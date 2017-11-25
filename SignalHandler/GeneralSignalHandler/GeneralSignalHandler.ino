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
}

void loop() {

  // check for serial command
  if (Serial.available() > 0) {
    /* 
     *  Command format = xx_yy 
     *  xx = motor number (00 - 18)
     *  yy = angle (0-180)
     *  eg : 00_180, 18_0
     */
    String command = Serial.readString();
    int motor = command.substring(0,2).toInt();
    int new_angle = command.substring(3).toInt();
    angle[motor] = new_angle;
  }

  // update angles for all motor
  updateAngles();

  // get the feedback values for all motor
  getFeedbackValues();

  // send the feedback values via serial
  sendFeedbackValues();

  // for debug send angle values
  sendAngleValues();
}
// END OF LOOP


/******************************************
 * Function definitions
 ******************************************
*/


/* 
 *  This function sends the feedback value data on serial
 */
void sendFeedbackValues() {
  String data;
  for (byte i=0;i<=15; i++) {
    data.concat(String(fb_value[i]));
    data.concat(",");
  }
  
  Serial.println(data);
}

/* 
 *  This function sends the current angle data on serial
 */
void sendAngleValues() {
  String data;
  for (byte i=0;i<=15; i++) {
    data.concat(String(angle[i]));
    data.concat(",");
  }
  
  Serial.println(data);
}

/* 
 * This function loops through 0-15 for all motors and 
 * updates their angles according to the values from the array
 * array index corresponds to the motor selected
 * 
 */
void updateAngles() {
  // set mux selector
  for (byte i = 0; i <= 15; i++) {
    PORTB = i;
    sendAngle(angle[i]);
  }
}

/* 
 *  This function loops through 0-15 for all motor feedback signals and
 *  updates the feedback values in the array
 *  array index corresponds to the motor selected
 * 
 */
void getFeedbackValues() {
  // set mux selector
  for (byte i = 0; i <= 15; i++) {
    PORTB = i;
    int currentVal = analogRead(A1);
    fb_value[i] = currentVal;
  }
}

/* 
 * This function briefly starts pwm signal for the angle sent as arguement 
 * Attach and Detach are required because of 
 * switching between different motors sequentially
 * Also minimum delay to reflect the angle is required 
 * after writing the angle and before detaching the signal.
 * This will allow shaft to come to its expected position
 * This minimum time is calculated from step response for 180 degrees.
 * 
 */
void sendAngle(int angle) {
  s.attach(SERVO_PIN);
  s.write(angle);
  delay(300);
  s.detach();
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

