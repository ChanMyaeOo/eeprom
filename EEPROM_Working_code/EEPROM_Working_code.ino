#include <EEPROM.h>
int buttonPin = 6;
int buttonState;
int relayPin = 12;
int address = 0; // or int address;
int isOnOrOff;
int count;
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(relayPin, OUTPUT);
  isOnOrOff = EEPROM.read(address);
  if (isOnOrOff == 1) {
    digitalWrite(relayPin, HIGH);
    count = 1;
  }
  else if (isOnOrOff == 0) {
    digitalWrite(relayPin, LOW);
    count = 2;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    if (count % 2 == 0) {
      digitalWrite(relayPin, HIGH);
      EEPROM.write(address, 1);
    }
    else {
      digitalWrite(relayPin, LOW);
      EEPROM.write(address, 0);
    }
    count++;
    delay(1000);
  }

}
