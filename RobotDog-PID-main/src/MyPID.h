//---------------------------------MyPID.h-----------------------------//
#include <Arduino.h>
#include <PID_v1.h>

extern double th1_ref; 
double kp = 5, ki = 0.01, kd = 0.01; //official configuration for PID constants

// Input, output, reference
PID MOT1_PID(&th1, &MOT1_cmd, &th1_ref, kp, ki, kd, DIRECT);

// ================================================================
// Function Definition
// ================================================================
void Init_PID()
{
  MOT1_PID.SetMode(AUTOMATIC);
  MOT1_PID.SetOutputLimits(-30, 30);
  MOT1_PID.SetSampleTime(10);
}

// ================================================================
void Compute_PID()
{
  MOT1_PID.SetTunings(kp, ki, kd);
  MOT1_PID.Compute();

  // Add a tolerance to avoid oscillations
}
// ================================================================
