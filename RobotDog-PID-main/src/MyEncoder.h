//---------------------------------MyEncoder.h-----------------------------//
#include <Arduino.h>
#define ENC1_A 32    // MOT 1A   
#define ENC1_B 33   // MOT 1B
#define ENC2_A 19    // MOT 2A   
#define ENC2_B 21   // MOT 2B
#define ENC3_A 4    // MOT 3A   
#define ENC3_B 16   // MOT 3B
#define ENC_RES 330 // Encoder resolution*Gearbox ratio: 11*30

volatile long int cnt1 = 0; // Volatile as it changed during interrupt
double th1 = 0;             // Position angle in degrees

volatile long int cnt2 = 0; // Volatile as it changed during interrupt
double th2 = 0;             // Position angle in degrees

volatile long int cnt3 = 0; // Volatile as it changed during interrupt
double th3 = 0;             // Position angle in degrees

//================================================================================
void readEncoder1()
{
    int b = digitalRead(ENC1_B);
    cnt1 = (b > 0) ? (cnt1 + 1) : (cnt1 - 1);
}

void readEncoder2()
{
    int b = digitalRead(ENC2_B);
    cnt2 = (b > 0) ? (cnt2 + 1) : (cnt2 - 1);
}

void readEncoder3()
{
    int b = digitalRead(ENC3_B);
    cnt3 = (b > 0) ? (cnt3 + 1) : (cnt3 - 1);
}

void Init_Encoder()
{
    pinMode(ENC1_A, INPUT_PULLUP);
    pinMode(ENC1_B, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENC1_A), readEncoder1, RISING);

    pinMode(ENC2_A, INPUT_PULLUP);
    pinMode(ENC2_B, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENC2_A), readEncoder2, RISING);

    pinMode(ENC3_A, INPUT_PULLUP);
    pinMode(ENC3_B, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENC3_A), readEncoder3, RISING);
}

void Get_Angle()
{
    th1 = cnt1 * 360 / ENC_RES; // Conversion between encoder count and degree
    th2 = cnt2 * 360 / ENC_RES; // Conversion between encoder count and degree
    th3 = cnt3 * 360 / ENC_RES; // Conversion between encoder count and degree
}