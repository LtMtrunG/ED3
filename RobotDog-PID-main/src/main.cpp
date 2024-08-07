//---------------------------------Main.cpp-----------------------------//
#include <Arduino.h>
#include "MyMotor.h"
#include "MyEncoder.h"
#include "MyPID.h"
#include "MySerial.h"
bool flag = true;
int count = 0;
void setup()
{
  Init_Motor();
  Init_Encoder();
  Init_PID();
  Init_Serial();
}

void loop()
{
  Get_Angle();
  SerialDataPrint();
  Run_Motor();
  SerialDataWrite();
  Compute_PID();
}
