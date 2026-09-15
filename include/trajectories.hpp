#pragma once
#include <vector>
#include <cmath>

using namespace std;

struct Trajectory {
    vector<double> x, y, vx, vy, ax, ay;

    Trajectory(int n,double r,double v_mag) {
        x.resize(n); y.resize(n);
        vx.resize(n); vy.resize(n);
        ax.resize(n); ay.resize(n);

        double omega = v_mag / r;
        for (int i = 0; i < n; i++) {
            double t = i * .01;
            double theta_rad = omega * t;
            x[i] = r * cos(omega*t); y[i] = r * sin(omega * t);
            vx[i] = -omega * r * sin(omega * t); vy[i] = omega * r * cos(omega*t);
            ax[i] = -1*pow(omega,2) * r * cos(omega * t); ay[i] = -1 * pow(omega, 2) * r * sin(omega * t);
        }
         
    }

};