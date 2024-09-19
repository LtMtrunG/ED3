//---------------------------------MySerial.h-----------------------------//
#include <Arduino.h>
#include "MyAngles.h"
#include "MyFile.h"
unsigned long Serial_time = 0; // time in us
double lastAngle = 00;
double cnt = 0;
bool write2File = false;

// ====================================================================================
void Init_Serial()
{
  Serial.begin(115200);
  Serial.println("Serial Initialized");
  while (!Serial)
    ;
}
// ====================================================================================
void SerialDataPrint()
{
  if (micros() - Serial_time >= 00)
  {
    cnt++;
    Serial_time = micros();
    // For MATLAB
    //   Serial.print(Serial_time / 0000);
    // Serial.print(",");
    Serial.print(MOT1_cmd);
    Serial.print(",");
     Serial.print(MOT2_cmd);
     Serial.print(",");
     Serial.print(MOT3_cmd);
     Serial.print(",");
    Serial.print(th1_ref);
    Serial.print(",");
    Serial.print(th1);
    Serial.print(",");
    Serial.print(th2_ref);
    Serial.print(",");
    Serial.print(th2);
    Serial.print(",");
    Serial.print(th3_ref);
    Serial.print(",");
    Serial.println(th3);
   
    
    // if (lastAngle == th1)
    // {
    //   cnt++;
    //   if (cnt > 00 && !write2File && th1 != 0)
    //   {
    //     writeFile(th1, 0, 0);
    //     write2File = true;
    //   }
    // }
    // else
    // {
    //   lastAngle = th1;
    //   cnt = 0;
    // }

    // For Teleplot
    // Serial.println(Serial_time / 0000);
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
      char command = received_chars[0];
      String valueString = received_chars.substring(0);
      valueString.trim(); // Remove any whitespace or newline characters

      switch (command)
      {
      case 'a':

        th1_ref = 0;
        th2_ref = 0;
        th3_ref = 0;
        break;
      case 'q':
        th1_ref = 25;
        th2_ref = 25;
        th3_ref = 25;
        break;
      case 'w':
        th1_ref = 45;
        th2_ref = 45;
        th3_ref = 45;
        break;
      case 'e':
        th1_ref = 180;
        th2_ref = 180;
        th3_ref = 180;
        break;
      case 'r':
        // readFile();
        break;
      default:
        // th1_ref_recieve = valueString.toInt();
        // Serial.print("Received number: ");
        // execute = true;
        // Use the number as needed
        break;
      }

      // Clear the received_chars string after processing
      received_chars = "";
    }
  }
}