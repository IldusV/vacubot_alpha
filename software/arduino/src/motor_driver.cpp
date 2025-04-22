/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/
#include "main.h"

#ifdef USE_BASE
   
#ifdef POLOLU_VNH5019
  /* Include the Pololu library */
  #include "DualVNH5019MotorShield.h"

  /* Create the motor driver object */
  DualVNH5019MotorShield drive;
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    drive.init();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT) drive.setM1Speed(spd);
    else drive.setM2Speed(spd);
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#elif defined POLOLU_MC33926
  /* Include the Pololu library */
  #include "DualMC33926MotorShield.h"

  /* Create the motor driver object */
  DualMC33926MotorShield drive;
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    drive.init();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT) drive.setM1Speed(spd);
    else drive.setM2Speed(spd);
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#elif defined L298_MOTOR_DRIVER
  void initMotorController() {
    digitalWrite(RIGHT_MOTOR_ENABLE, HIGH);
    digitalWrite(LEFT_MOTOR_ENABLE, HIGH);
  }
  
  void setMotorSpeed(int i, int spd) {
    unsigned char reverse = 0;
  
    if (spd < 0)
    {
      spd = -spd;
      reverse = 1;
    }
    if (spd > 255)
      spd = 255;
    
    if (i == LEFT) { 
      if      (reverse == 0) { analogWrite(LEFT_MOTOR_FORWARD, spd); analogWrite(LEFT_MOTOR_BACKWARD, 0); }
      else if (reverse == 1) { analogWrite(LEFT_MOTOR_BACKWARD, spd); analogWrite(LEFT_MOTOR_FORWARD, 0); }
    }
    else /*if (i == RIGHT) //no need for condition*/ {
      if      (reverse == 0) { analogWrite(RIGHT_MOTOR_FORWARD, spd); analogWrite(RIGHT_MOTOR_BACKWARD, 0); }
      else if (reverse == 1) { analogWrite(RIGHT_MOTOR_BACKWARD, spd); analogWrite(RIGHT_MOTOR_FORWARD, 0); }
    }
  }
  
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#elif defined ILDUS_MOTOR_DRIVER
  #include <Wire.h>
  #include "motor_driver.h"
  #include "commands.h"
// const uint8_t MS_LEFT  = 0;
// const uint8_t MS_RIGHT = 1;

  void initMotorController() {
    digitalWrite(A_LEFT, LOW);
    digitalWrite(B_LEFT, LOW);
    digitalWrite(A_RIGHT, LOW);
    digitalWrite(B_RIGHT, LOW);

    // stop the motors
    setMotorSpeeds(0, 0);
  }
  
  void setMotorSpeed(int i, int spd) {
    unsigned char reverse = 0;
  
    if (spd < 0)
    {
      spd = -spd;
      reverse = 1;
    }
    if (spd > 255)
      spd = 255;

    if(i == LEFT) {
      if(spd == 0){
        // LEFT wheel break
        digitalWrite(A_LEFT, HIGH);
        digitalWrite(B_LEFT, HIGH);
        // digitalWrite(A_RIGHT, HIGH);
        // digitalWrite(B_RIGHT, HIGH);
        // digitalWrite(BREAK_RIGHT, HIGH);
        //digitalWrite(BREAK_LEFT, HIGH);
        //delay(80);
        //digitalWrite(BREAK_LEFT, LOW);
        // digitalWrite(BREAK_RIGHT, LOW);
      }
      else {
        if (reverse == 0) {
          //  LEFT wheel forward
          digitalWrite(A_LEFT, LOW);
          analogWrite(B_LEFT, spd);
        }
        else {
          // LEFT wheel reverse
          analogWrite(A_LEFT, spd);
          digitalWrite(B_LEFT, LOW);
        }
      }
    }
    
    if(i == RIGHT)
    {
      if (spd == 0) {
        // digitalWrite(A_LEFT, HIGH);
        // digitalWrite(B_LEFT, HIGH);
        digitalWrite(A_RIGHT, HIGH);
        digitalWrite(B_RIGHT, HIGH);
        //digitalWrite(BREAK_RIGHT, HIGH);
        // digitalWrite(BREAK_LEFT, HIGH);
        //delay(80);
        // digitalWrite(BREAK_LEFT, LOW);
        //digitalWrite(BREAK_RIGHT, LOW);
      }
      else {
        if (reverse == 0) {
          // RIGHT wheel forward
          digitalWrite(A_RIGHT, LOW);
          analogWrite(B_RIGHT, spd);
        }
        else {
          // RIGHT wheel reverse
          analogWrite(A_RIGHT, spd);
          digitalWrite(B_RIGHT, LOW);
        }
      }
    }

  }
  
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }

#else
  #error A motor driver must be selected!
#endif

#endif
