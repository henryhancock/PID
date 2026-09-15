#include "object.hpp"
#include <iostream>

using namespace std;

void Object::applyForce(double fx, double fy, double dt) {
    state.ax = fx / mass;
    state.ay = fy / mass;

    state.vx += state.ax * dt;
    state.vy += state.ay * dt;

    state.x += state.vx * dt;  // uses updated velocity ✓
    state.y += state.vy * dt;
   // cout<<"Force of "<< fx <<"x and " << fy << 'y' << " has been applied"<<endl;
    //cout<<"New state is..."<<endl;
    //printState(state);
}

State Object::getState() const {
    return state;
}
void Object::printState(const State& s){
    cout<<"x = " << s.x << ", y = " << s.y<<endl;
    cout<<"vx = " << s.vx << ", y = " << s.vy<<endl;
    cout<<"ax = " << s.ax << ", y = " << s.ay<<endl;
    return;
}