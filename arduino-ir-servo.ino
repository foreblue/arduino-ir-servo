#include <IRremote.h>
#include <IRremoteInt.h>
#include <Servo.h>

int servoPin = 9;
int angle = 0;
Servo servo;

int irPin = 2;

int index = 0;

IRrecv irrecv(irPin);
decode_results signals;
 
void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();
    servo.attach(servoPin);
    servo.write(angle);
}
 
void loop() {
  if (irrecv.decode(&signals)) {
      index++;
      Serial.println(index);
      Serial.println(signals.bits, DEC);
      
      if (angle == 0) {
        angle = 45;
      } else {
        angle = 0;
      }
      servo.write(angle);

      delay(1000);
      irrecv.resume();
    }
}
