#pragma once
#include <vector>

using namespace std;

struct PIDcontroller {
    double Kp = 1.0;
    double Ki = 1.0;
    double Kd = 1.0;
    
    double intX = 0, intY = 0;
    double prevErrX = 0, prevErrY = 0;

    vector<double> update(vector<double> error, double dt) {
        intX += error[0] * dt;
        intY += error[1] * dt;
        
        double dX = (error[0] - prevErrX) / dt;
        double dY = (error[1] - prevErrY) / dt;
        
        prevErrX = error[0];
        prevErrY = error[1];
        
        return vector<double>{
            Kp * error[0] + Ki * intX + Kd * dX,
            Kp * error[1] + Ki * intY + Kd * dY
        };
    }
};