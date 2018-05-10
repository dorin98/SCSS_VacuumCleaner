#include <IRremote.h>

#define UP 16718055
#define DOWN 16730805
#define RIGHT 16734885
#define LEFT 16716015
#define STOP 16726215
#define MAX_INT 4294967295

long lastValue;

// Senzor IR
int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;

void stopMotors() 
{
    // Set Motor A forward
//  digitalWrite(in1, LOW);
//  digitalWrite(in2, LOW);
// 
//  // Set Motor B forward
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, LOW);
  
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void irReceiver()
{
	irrecv.enableIRIn();
	Serial.print("! Started !\n");
}

void irLoop()
{
  if (irrecv.decode(&results)) {
    if (results.value == UP) {
      stopMotors();
      Serial.println("UP");
      MoveForward();
    }
    else if (results.value == DOWN) {
      stopMotors();
      Serial.println("DOWN");
      MoveReverse();
    }
    else if (results.value == RIGHT) {
      stopMotors();
      Serial.println("RIGHT");
      TurnRight();
    }
    else if (results.value == LEFT) {
      stopMotors();
      Serial.println("LEFT");
      TurnLeft();
    }
    else if (results.value == STOP) {
      stopMotors();
      Serial.println("STOP");
    }
    Serial.print(results.value);
    Serial.print("\n");
    irrecv.resume(); // Receive the next value
  }
}
	
