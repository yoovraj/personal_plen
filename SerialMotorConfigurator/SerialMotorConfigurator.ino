#include<Servo.h> 
// 0,1
int motor_pin[]    = {3,5, 6, 11};
// analog inputs
int fb_motor_pin[] = {0, 1, 2, 3};
Servo s1;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   for (int i = 0 ; i < 2; i++) {
    pinMode(fb_motor_pin[i], INPUT);
   }
}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available() > 0) {
      // Command format = xx_yy 
      // xx = motor number (00 - 18)
      // yy = angle (0-180)
      // eg : 00_180, 18_0
      String command = Serial.readString();
      int motor = command.substring(0,2).toInt();
      int angle = command.substring(3).toInt();
      s1.attach(motor_pin[motor]);
      s1.write(angle);
      delay(500);
      s1.detach();
      Serial.println(analogRead(fb_motor_pin[motor]));
    }

}
