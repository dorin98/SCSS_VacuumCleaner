const int trigPin1 = A4;
const int echoPin1 = A5;
const int trigPin2 = A0;
const int echoPin2 = A1;

long duration;
long distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600); // Starts the serial communication
}

int getDist(int trigPin, int echoPin) {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  return distance;
}

void loop() {
  Serial.print("Distance1: ");
  Serial.println(getDist(trigPin1, echoPin1));
  Serial.print("Distance2: ");
  Serial.println(getDist(trigPin2, echoPin2));
  Serial.print("\n");
  delay(1000);
}
