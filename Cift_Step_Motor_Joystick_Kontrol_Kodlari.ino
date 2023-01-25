#include <Stepper.h>

const int stepsPerRevolution = 64;  // change this to fit the number of steps per revolution
// for your motor

                                         
// initialize the stepper library for both steppers:
Stepper small_stepper(stepsPerRevolution, 8, 9, 10, 11);  
Stepper small_stepper2(stepsPerRevolution, 2, 3, 4, 5); 

void setup() {

  // set the speed of the motors 
  small_stepper.setSpeed(500);    // set first stepper speed
  small_stepper2.setSpeed(500);   // set second stepper speed
}


void loop() {
 
  int sensorReading = analogRead(A5); // read value from joystick X-axis

  if (sensorReading < 350) { small_stepper.step(1); }   // step left
  if (sensorReading > 575) { small_stepper.step(-1); }  // step right
 
  int sensorReading2 = analogRead(A4); // read value from joystick Y-axis

  if (sensorReading2 < 350) { small_stepper2.step(1); } // step forward
  if (sensorReading2 > 575) { small_stepper2.step(-1); } // step backward
  
  
 }