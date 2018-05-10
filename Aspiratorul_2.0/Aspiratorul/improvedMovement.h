void ISR_countA() {
  counterA++;  // increment Motor A counter value
  //Serial.println("DA1");
}
void ISR_countB() {
  counterB++;  // increment Motor B counter value
  //Serial.println("DA2");
}
void improvedMovement() {
  attachInterrupt(digitalPinToInterrupt (MOTOR_A), ISR_countA, RISING);  // Increase counter A when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt (MOTOR_B), ISR_countB, RISING);  // Increase counter B when speed sensor pin goes High
  // Motor Setup
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
int cmToSteps(float cm) {

  float circumference = (wheeldiameter * 3.14) / 10; // Calculate wheel circumference in cm
  float cm_step = circumference / stepcount;  // CM per Step
  
  float f_result = cm / cm_step;  // Calculate result as a float
  return (int) f_result; // Convert to an integer (note this is NOT rounded) 
}
void verifyMovement(int steps) {
  Serial.println(steps);
  counterA = 0;  //  reset counter A to zero
  counterB = 0;  //  reset counter B to zero
  int ahead;
  int behind;
  analogWrite(enA, moveSpeed);
  analogWrite(enB, moveSpeed);
  while (steps > counterA || steps > counterB) {

    if(abs(counterA - counterB) > stepLag && counterA != counterB) {
      if(counterA > counterB) {
        ahead = enA;
        behind = enB;
      }
      else {
        ahead = enB;
        behind = enA;
      }
      analogWrite(ahead, moveSpeed - lagSpeed);
      analogWrite(behind, moveSpeed);
      Serial.println("SugPula");
    }
    else {
      analogWrite(enA, moveSpeed);
      analogWrite(enB, moveSpeed);
      
    }
  }
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  counterA = 0;
  counterB = 0;
  delay(moveDelay);
}
void verifyContinious() {
  //Serial.println(steps);
  int ahead;
  int behind;
  analogWrite(enA, moveSpeed);
  analogWrite(enB, moveSpeed);

    if(abs(counterA - counterB) > stepLag && counterA != counterB) {
      if(counterA > counterB) {
        ahead = enA;
        behind = enB;
      }
      else {
        ahead = enB;
        behind = enA;
      }
      analogWrite(ahead, moveSpeed - lagSpeed);
      analogWrite(behind, moveSpeed);
      Serial.println("SugPula");
    }
    else {
      analogWrite(enA, moveSpeed);
      analogWrite(enB, moveSpeed);
    }
}
void Forward() 
{
  int steps = cmToSteps(unitLength);
   
  // Set Motor A forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
 
  // Set Motor B forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  verifyMovement(steps); 
}
void Back() 
{
  int steps = cmToSteps(unitLength);
  counterA = 0;  //  reset counter A to zero
  counterB = 0;  //  reset counter B to zero
   
  // Set Motor A reverse
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
 
  // Set Motor B reverse
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  verifyMovement(steps); 
}
void ForwardContinous() 
{
  int steps = cmToSteps(unitLength);
   
  // Set Motor A forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
 
  // Set Motor B forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  counterA = 0;  //  reset counter A to zero
  counterB = 0;  //  reset counter B to zero
}
void BackContinous() 
{
  int steps = cmToSteps(unitLength);
  counterA = 0;  //  reset counter A to zero
  counterB = 0;  //  reset counter B to zero
   
  // Set Motor A reverse
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
 
  // Set Motor B reverse
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  counterA = 0;  //  reset counter A to zero
  counterB = 0;  //  reset counter B to zero
}
void Right() 
{
  int steps = cmToSteps(turnLength);
  counterA = 0;  //  reset counter A to zero
  counterB = 0;  //  reset counter B to zero
  
   // Set Motor A reverse
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
 
  // Set Motor B forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  verifyMovement(steps); 
}
 
// Function to Spin Left
void Left() 
{
  int steps = cmToSteps(turnLength);
  counterA = 0;  //  reset counter A to zero
  counterB = 0;  //  reset counter B to zero
   
   // Set Motor A forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
 
  // Set Motor B reverse
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  verifyMovement(steps);
}


