//---------------------------------Main.cpp-----------------------------//
#include <Arduino.h>
#include "MyMotor.h"
#include "MyEncoder.h"
#include "MyPID.h"
#include "MySerial.h"
#include "MyMATLAB.h"

double th1_receive, th2_receive, th3_receive;

void setup()
{
  Init_Motor();
  Init_Encoder();
  Init_PID();
  Init_Serial();
  initSPIFFS();
  init_connection();
}

void loop()
{
  Get_Angle();
  // SerialDataPrint();
  Run_Motor();
  SerialDataWrite();
  Compute_PID();
  serverAPI.handleClient();
  Angles1 recive_angles = handleUpdate();
  if (recive_angles.th1 != 1000) {
    th1_ref = recive_angles.th1;
  }
}
