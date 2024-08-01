#include <Arduino.h>
#include "MyMotor.h"
#include "MyEncoder.h"
#include "MyPID.h"
#include "MySerial.h"
bool flag = true;

double input = 360; //INPUT ANGLE HERE
void setup()
{
  Init_Motor();
  Init_Encoder();
  Init_PID();
  Init_Serial();
  th1_ref =  input;
}

void loop()
{
  Get_Angle(); 
  Compute_PID();

  if (abs(th1) >= th1_ref)
  {
    if (flag)
    {
      Serial.print("Larger");
      flag = false;
        pinMode(MOT1_A, LOW);
    pinMode(MOT1_B, LOW);
    }
    
  }
  else
  {
    Run_Motor();
    SerialDataPrint();
  }

  // SerialDataWrite();
}
