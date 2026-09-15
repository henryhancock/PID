#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "object.hpp"
#include "trajectories.hpp"
#include "PID.hpp"
using namespace std;

int main() {
    int duration = 90000;
    Object o;
    Trajectory traj(duration, 1000, 10);
    
    PIDcontroller PID;
    PID.Kp = 5.0;
    PID.Ki = 0.1;
    PID.Kd = 5.0;
    
    vector<double> times, error_x, error_y, dx, dy, vx, vy;
    State initial = o.getState();
    initial.vy = 10000;
    initial.x = 0.0;
    o.setState(initial);
    
    for (int i = 0; i < duration; i++) {
        double t = i * 0.01;
        times.push_back(t);
        
        vector<double> err = {traj.x[i] - o.getState().x, traj.y[i] - o.getState().y};
        vector<double> f = PID.update(err, .01);
        
        o.applyForce(f[0], f[1], 0.01);
        
        error_x.push_back(err[0]);
        error_y.push_back(err[1]);
        dx.push_back(o.getState().x);
        dy.push_back(o.getState().y);
        vx.push_back(o.getState().vx);
        vy.push_back(o.getState().vy);
    }
    
    ofstream file("sim_data.json");
    file << "{\"time\":[";
    for (size_t i = 0; i < times.size(); i++) {
        file << times[i];
        if (i < times.size() - 1) file << ",";
    }
    file << "],\"error_x\":[";
    for (size_t i = 0; i < error_x.size(); i++) {
        file << error_x[i];
        if (i < error_x.size() - 1) file << ",";
    }
    file << "],\"error_y\":[";
    for (size_t i = 0; i < error_y.size(); i++) {
        file << error_y[i];
        if (i < error_y.size() - 1) file << ",";
    }
    file << "],\"dx\":[";
    for (size_t i = 0; i < dx.size(); i++) {
        file << dx[i];
        if (i < dx.size() - 1) file << ",";
    }
    file << "],\"dy\":[";
    for (size_t i = 0; i < dy.size(); i++) {
        file << dy[i];
        if (i < dy.size() - 1) file << ",";
    }
    file << "],\"vx\":[";
    for (size_t i = 0; i < vx.size(); i++) {
        file << vx[i];
        if (i < vx.size() - 1) file << ",";
    }
    file << "],\"vy\":[";
    for (size_t i = 0; i < vy.size(); i++) {
        file << vy[i];
        if (i < vy.size() - 1) file << ",";
    }
    file << "]}";
    file.close();
    
    return 0;
}