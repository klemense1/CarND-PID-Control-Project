#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double _p_error;
  double _i_error;
  double _d_error;
  double _prev_cte;

  /*
  * Coefficients
  */ 
  double _Kp;
  double _Ki;
  double _Kd;
  
  double _steer;
  double _control_error;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  double ControlSteering();
  
  /*
  * Calculate the total PID error.
  */
  double TotalError(double actual_steering);
  
};

#endif /* PID_H */
