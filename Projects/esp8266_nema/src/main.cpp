#include <Arduino.h>
#include <BasicStepperDriver.h>

#define MOTOR_STEP 200
#define RPM 120

#define MICROSTEPS 1

#define DIR D4
#define STEP D3

BasicStepperDriver stepper(MOTOR_STEP, DIR, STEP);

void setup() {
  Serial.begin(115200);
  stepper.begin(RPM, MICROSTEPS);
}

void loop() {  
  if (Serial.available() && stepper.getCurrentState() == BasicStepperDriver::STOPPED) {
    int degree = Serial.parseInt();
    stepper.rotate(degree);
  }
}
