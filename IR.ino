#include <IRremote.h>

#define UP 16718055
#define DOWN 16730805
#define RIGHT 16734885
#define LEFT 16716015

int pin = 4;
IRrecv irrecv(pin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.print("Welcome");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    Serial.print("Value: ");
    Serial.print(results.value, DEC);
    Serial.print("\n");
    irrecv.resume(); // Receive the next value
  }
}
