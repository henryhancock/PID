#pragma once

struct State { 
    double x, y, vx, vy, ax, ay;
 };

class Object {
    State state;


public:
    double mass;
    double COD;
    Object() {
        mass = 1.0;
        COD = .0001;
        state = {0,0,0,0,0,0};
    }
    void setState(const State& s) { state = s; }
    void applyForce(double fx, double fy, double dt);
    void printState(const State& s);
    State getState() const;
};