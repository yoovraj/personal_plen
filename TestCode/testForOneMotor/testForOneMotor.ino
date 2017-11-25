#include<Servo.h>

// servo for pwm signal
Servo s;

// current position of motor
int angle[16];

// current feedback value of motor
int fb_value[16];

// pwm signal pin
const short int SERVO_PIN = 6;

void setup() {
  // put your setup code here, to run once:
  // configure the arduino pins for control signals to mux
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  // configure the signal pin
  pinMode(A1, INPUT);

  // PWM output pin
  pinMode(5, OUTPUT);
  
  Serial.begin(9600);
  initializeVariables();
  s.attach(6);

}

void loop() {
  // put your main code here, to run repeatedly:
  byte i = 0;
  PORTB = i;
  sendAngle(90);

}

void sendAngle(int angle) {
  s.write(angle);
  delay(300);
}

/* 
 *  Initialize all the variables
 */
void initializeVariables() {
  for (byte i = 0; i <= 15; i++) {
    // all angles initialize to 90
    angle[i] = 90;
    
    // initial feedback values not known, so initialize to 0
    fb_value[i] = 0;
  }
}

