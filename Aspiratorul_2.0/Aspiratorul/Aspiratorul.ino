#include "TimerOne.h"
#define relay4 12 // releu 4
// Speed Control Interrupts
const byte MOTOR_A = 2;
const byte MOTOR_B = 3;

// Constants for going forward
const float forwardTime = 1000;  // miliseconds
const int forwardSpeed = 85;  // 0-70? - 255

// Constants for turning
const float turnTime = 1000; // miliseconds
const int turnSpeed = 70;  // 0-70? - 255

// Motor A
int enA = 10;
int in1 = 9;
int in2 = 8;
 
// Motor B
int enB = 5;
int in3 = 7;
int in4 = 6;

// Fan
int fanPin = 11;

// Speed Control
int counterA = 0;
int counterB = 0;
const float stepcount = 20.00;
const float stepLag = 1;
const float wheeldiameter = 66.10;
const float moveSpeed = 230;
const float lagSpeed = 0;
const float unitLength = 10; // cm
const float turnLength = 10; // cm ??
const int moveDelay = 1000;

#include "movement.h"
#include "improvedMovement.h"
#include "demos.h"
#include "fan.h"
#include "irReceiver.h"

void setup() 
{
  Serial.begin(9600);
  irReceiver();
  movement();
  fan();
  fanHigh();
  delay(3000);
  //improvedMovement();
  //Forward();
  //Back();
 
}
void loop()
{
  irLoop();
  //verifyContinious();
}
