#include "PID.h"
#include <algorithm>

using namespace std;

/*
 * TODO: Complete the PID class.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  _Kp = Kp;
  _Ki = Ki;
  _Kd = Kd;
}

void PID::UpdateError(double cte) {
  _p_error = cte;
  _i_error = cte - _prev_cte;
  _d_error += cte;
  _prev_cte = cte;
  
}

double PID::ControlSteering() {
  
  _steer = -_Kp * _p_error - _Ki * _i_error - _Kd * _d_error;
  _steer = std::min(_steer, 1.0);
  _steer = std::max(-1.0, _steer);
  
  return _steer;
}

double PID::TotalError(double actual_steering) {
  _control_error = _steer - actual_steering;
  
  return _control_error;
}
