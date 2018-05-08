#include <IRremote.h>

#define UP 16718055
#define DOWN 16730805
#define RIGHT 16734885
#define LEFT 16716015
#define STOP 16726215
#define MAX_INT 4294967295

long lastValue;

// Senzor IR
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

// Constants for going forward
const float forwardTime = 500;  // miliseconds
const int forwardSpeed = 250;  // 0-70? - 255

// Constants for turning
const float turnTime = 300; // miliseconds
const int turnSpeed = 150;  // 0-70? - 255

// Motor A
int enA = 10;
int in1 = 9;
int in2 = 8;
 
// Motor B
int enB = 5;
int in3 = 7;
int in4 = 6;

void MoveForward()
{
  // Set Motor A forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  // Set Motor B forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  // Engage motors
  analogWrite(enA, forwardSpeed);
  analogWrite(enB, forwardSpeed);
  delay(forwardTime);
   
  // Stop motors
//  analogWrite(enA, 0);
//  analogWrite(enB, 0);
}
void MoveReverse()
{
  // Set Motor A reverse
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  // Set Motor B reverse
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  // Engage motors
  analogWrite(enA, forwardSpeed);
  analogWrite(enB, forwardSpeed);
  delay(forwardTime);
   
  // Stop motors
//  analogWrite(enA, 0);
//  analogWrite(enB, 0);
}
void TurnRight() 
{ 
  // Set Motor A reverse
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  // Set Motor B forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  // Engage motors
  analogWrite(enA, turnSpeed);
  analogWrite(enB, turnSpeed);
  delay(turnTime);
   
  // Stop motors
//  analogWrite(enA, 0);
//  analogWrite(enB, 0);
}
void TurnLeft()
{
  // Set Motor A forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
 
  // Set Motor B reverse
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   
  // Engage motors
  analogWrite(enA, turnSpeed);
  analogWrite(enB, turnSpeed);
  delay(turnTime);
   
  // Stop motors
//  analogWrite(enA, 0);
//  analogWrite(enB, 0);
}

void stopMotors() 
{
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
 
void setup() 
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
//  delay(5000);
//  MoveForward();
//  delay(1000);
//  MoveReverse();
//  delay(1000);
//  TurnLeft();
//  delay(1000);
//  TurnRight();
//  TurnRight();
//  delay(1000);
//  TurnRight();
  Serial.print("Starting\n");
}
void loop()
{
  if (irrecv.decode(&results)) {
    if (results.value == MAX_INT) {
      results.value = lastValue;
    }
    if (results.value == UP) {
      Serial.print("UP");
      if (lastValue != UP)
        stopMotors();
      MoveReverse();
      lastValue = UP;
    }
    else if (results.value == DOWN) {
      Serial.print("DOWN");
      if (lastValue != DOWN)
        stopMotors();
      MoveForward();
      lastValue = DOWN;
    }
    else if (results.value == RIGHT) {
      Serial.print("RIGHT");
      if (lastValue != RIGHT)
        stopMotors();
      TurnRight();
      lastValue = RIGHT;
    }
    else if (results.value == LEFT) {
      Serial.print("LEFT");
      if (lastValue != LEFT)
        stopMotors();
      TurnLeft();
      lastValue = LEFT;
    }
    Serial.print(results.value);
    Serial.print("\n");
    irrecv.resume(); // Receive the next value
  }
  else {
    stopMotors();
  }
}

