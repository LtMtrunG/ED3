//---------------------------------Main.cpp-----------------------------//
#include <Arduino.h>
#include "MyMotor.h"
#include "MyEncoder.h"
#include "MyPID.h"
#include "MySerial.h"
#include "MyMATLAB.h"
// #include "soc/soc.h"
// #include "soc/rtc_cntl_reg.h"
// bool flag = false;
unsigned long Serial_time_main = 0; // time in us
// double cnt_main = 0;
void setup()
{
  Init_Motor();
  Init_Encoder();
  Init_PID();
  Init_Serial();
  init_connection();
}

void loop()
{
  Get_Angle();
  if (micros() - Serial_time_main >= 1000)
  {
    Serial_time_main = micros();
    Compute_PID();
    Run_Motor();
  }

 // SerialDataPrint();
  SerialDataWrite();

  serverAPI.handleClient();
  // calculate();
}
