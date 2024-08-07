//---------------------------------MySerial.h-----------------------------//
#include <Arduino.h>
#include "MyFile.h"
unsigned long Serial_time = 0; // time in us
double th1_ref;
double lastAngle = 100;
double cnt = 0;
bool write2File = false;
// ====================================================================================
void Init_Serial()
{
  Serial.begin(115200);
  while (!Serial)
    ;
}
// ====================================================================================
void SerialDataPrint()
{
  if (micros() - Serial_time >= 100)
  {
    cnt++;
    Serial_time = micros();
    // For MATLAB
    Serial.print(Serial_time / 10000);
    Serial.print(",");
    Serial.print(MOT1_cmd);
    Serial.print(",");
    Serial.print(th1_ref);
    Serial.print(",");
    Serial.print(th1);
    Serial.print(",");
    Serial.print(cnt);
    Serial.print(",");
    Serial.print(write2File);
    Serial.println();

    if (lastAngle == th1)
    {
      cnt++;
      if (cnt > 100 && !write2File && th1 != 0)
      {
        createFile(th1, 10, 10);
        write2File = true;
      }
    }
    else
    {
      lastAngle = th1;
      cnt = 0;
    }

    // For Teleplot
    // Serial.println(Serial_time / 10000);
    // Serial.print(">MOT1_cmd:");
    // Serial.println(MOT1_cmd);
    // Serial.print(">th1:");
    // Serial.println(th1);
    // Serial.print(">th1_ref:");
    // Serial.println(th1_ref);
    // Serial.print(">kp:");
    // Serial.println(kp);
    // Serial.print(">ki:");
    // Serial.println(ki);
    // Serial.print(">kd:");
    // Serial.println(kd);
  }
}
// ====================================================================================
void SerialDataWrite()
{
  static String received_chars;
  while (Serial.available())
  {
    char inChar = (char)Serial.read();
    received_chars += inChar;
    if (inChar == '\n')
    {
      switch (received_chars[0])
      {
      case 'a':
        received_chars.remove(0, 1);
        MOT1_cmd = 30;
        th1_ref = 90;
        break;
      case 'q':
        received_chars.remove(0, 1);
        kp = received_chars.toFloat();
        break;
      case 'w':
        received_chars.remove(0, 1);
        ki = received_chars.toFloat();
        break;
      case 'e':
        received_chars.remove(0, 1);
        kd = received_chars.toFloat();
        break;
      case 'r':
        readFile();
        break;

      default:
        break;
      }
      received_chars = "";
    }
  }
}
