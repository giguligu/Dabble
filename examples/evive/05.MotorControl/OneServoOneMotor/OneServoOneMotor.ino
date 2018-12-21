/*
 * MotorControl Module is used to control actuators like DC motors and Servos.
 * This is a code for running one motor in motor channel M1 and one Servo in 
 * servo channel S2 on evive. 
 * 
 * Explore more: https://thestempedia.com/docs/dabble/motor-control-module/
 */
#define CUSTOM_SETTINGS
#define INCLUDE_MOTORCONTROL_MODULE
#include <evive.h>
#include <Dabble.h>
motorControls Control;
Servo servo;

void setup() {
  Serial.begin(250000);
  Dabble.begin(115200);              //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.
  servo.attach(SERVO2_ATTACH);
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.              //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile. 
  Control.runMotor1(Control.getpwm_Motor1());         //Connect motor to motor channel M1 on evive.
  servo.write(Control.getangle_Servo2());             //Connect servo to servo channel S2 on evive. 
}
