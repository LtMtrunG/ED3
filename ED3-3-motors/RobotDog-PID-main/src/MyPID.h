//---------------------------------MyPID.h-----------------------------//
#include <Arduino.h>
#include <PID_v1.h>

extern double th1_ref, th2_ref, th3_ref; 
// double kp = 15, ki = 0.01, kd = 0.01; //official configuration for PID constants
double kp = 15, ki = 0.02, kd = 0.01;
// double kptwo = 15, kitwo = 0.02, kdtwo = 0.01;
// double kpthree = 15, kithree = 0.02, kdthree = 0.01;
// Input, output, reference
PID MOT1_PID(&th1, &MOT1_cmd, &th1_ref, kp, ki, kd, DIRECT);
PID MOT2_PID(&th2, &MOT2_cmd, &th2_ref, kp, ki, kd, DIRECT);
PID MOT3_PID(&th3, &MOT3_cmd, &th3_ref, kp, ki, kd, DIRECT);

// ================================================================
// Function Definition
// ================================================================
void Init_PID()
{
  MOT1_PID.SetMode(AUTOMATIC);
  MOT1_PID.SetOutputLimits(-255, 255);
  MOT1_PID.SetSampleTime(10);

  MOT2_PID.SetMode(AUTOMATIC);
  MOT2_PID.SetOutputLimits(-255, 255);
  MOT2_PID.SetSampleTime(10);

  MOT3_PID.SetMode(AUTOMATIC);
  MOT3_PID.SetOutputLimits(-255, 255);
  MOT3_PID.SetSampleTime(10);
}

// ================================================================
void Compute_PID()
{
  MOT1_PID.SetTunings(kp, ki, kd);
  MOT1_PID.Compute();

  MOT2_PID.SetTunings(kp, ki, kd);
  MOT2_PID.Compute();

  MOT3_PID.SetTunings(kp, ki, kd);
  MOT3_PID.Compute();

  // Add a tolerance to avoid oscillations
}
// ================================================================
