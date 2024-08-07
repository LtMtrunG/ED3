//---------------------------------Main.cpp-----------------------------//
#include <Arduino.h>
#include "MyMotor.h"
#include "MyEncoder.h"
#include "MyPID.h"
#include "MySerial.h"

void setup()
{
  Init_Motor();
  Init_Encoder();
  Init_PID();
  Init_Serial();
  initSPIFFS();
}

void loop()
{
  Get_Angle();
  SerialDataPrint();
  Run_Motor();
  SerialDataWrite();
  Compute_PID();
}
