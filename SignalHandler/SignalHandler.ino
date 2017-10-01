#include<Servo.h>

Servo right_shoulder_pitch, right_shoulder_roll;
int fb_right_shoulder_pitch, fb_right_shoulder_roll;

int angle[2], fb_angle[2]; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.write("Start handling signals");
  right_shoulder_pitch.attach(3);
  fb_right_shoulder_pitch = 0; // A0
  pinMode(fb_right_shoulder_pitch, INPUT);
  
  right_shoulder_roll.attach(5);
  fb_right_shoulder_roll = 1; // A1
  pinMode(fb_right_shoulder_roll, INPUT);
  
  // all angles initialize to 90
  angle[0] = 90;
  angle[1] = 90;

  fb_angle[0] = 90;
  fb_angle[1] = 90;
}

void loop() {
  // put your main code here, to run repeatedly:
  // write current angle
  right_shoulder_pitch.write(angle[0]);
  right_shoulder_roll.write(angle[1]);

  // read the current angle
  fb_angle[0] = analogRead(fb_right_shoulder_pitch);
  fb_angle[1] = analogRead(fb_right_shoulder_roll);
  Serial.write(fb_angle[0]);
  Serial.write(",");
  Serial.println(fb_angle[1]);
}
