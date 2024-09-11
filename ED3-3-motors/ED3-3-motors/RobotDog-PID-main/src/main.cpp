//---------------------------------Main.cpp-----------------------------//
#include <Arduino.h>
#include "MyMotor.h"
#include "MyEncoder.h"
#include "MyPID.h"
#include "MySerial.h"
#include "MyMATLAB.h"
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

void setup()
{
  Init_Motor();
  Init_Encoder();
  Init_PID();
  Init_Serial();
 // init_connection();
}

void loop()
{
  Get_Angle();
  SerialDataPrint();
  Run_Motor();
  SerialDataWrite();
  Compute_PID();
 //s serverAPI.handleClient();
  // calculate();
}
