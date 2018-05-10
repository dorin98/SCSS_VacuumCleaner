void movement() {
  // Motor Setup
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
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
}
void TurnRight() 
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
}
void TurnLeft()
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
}

