#ifndef MAIN_H
#define MAIN_H

#define USE_BASE      // Enable the base controller code
//#undef USE_BASE     // Disable the base controller code

/* Define the motor controller and encoder library you are using */
#ifdef USE_BASE
   /* The Pololu VNH5019 dual motor driver shield */
   //#define POLOLU_VNH5019

   /* The Pololu MC33926 dual motor driver shield */
   //#define POLOLU_MC33926

   /* The RoboGaia encoder shield */
   //#define ROBOGAIA
   
   /* Encoders directly attached to Arduino board */
   //#define ARDUINO_ENC_COUNTER

   /* L298 Motor driver*/
   //#define L298_MOTOR_DRIVER

   #define ILDUS_ENC_COUNTER

   #define ILDUS_MOTOR_DRIVER
#endif

#endif