#include<Servo.h>
int motor_pin = 5;
int fb_motor_pin = 1;

Servo s1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  s1.attach(motor_pin);
  pinMode(fb_motor_pin, INPUT);
}

int DELAY = 10;
void loop() {
  for (int i = 0 ; i < 180; i++) {
    s1.write(i);
    delay(DELAY);
    Serial.println(analogRead(fb_motor_pin));
  }
  for (int i=180; i > 0; i--) {
    s1.write(i);
    delay(DELAY);
    Serial.println(analogRead(fb_motor_pin));
  }
}
