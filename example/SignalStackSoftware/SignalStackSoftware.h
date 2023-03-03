#pragma once

//////  RoveComm Initialization ////////////////////////////////////////////////////////////////////////////////////////////////////
#include "RoveComm.h"

RoveCommEthernet RoveComm;
rovecomm_packet packet;

EthernetServer TCPServer(RC_ROVECOMM_SIGNALSTACKBOARD_PORT);

IntervalTimer telemetry;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





////// Pin Definitions /////////////////////////////////////////////////////////////////////////////////////////////////////////////
// motor pins
#define COIL1_FWD       A0
#define COIL1_RVS       A1
#define COIL2_FWD       A10
#define COIL2_RVS       A11

// compass I2C pins
#define COMPASS_SDA     A4
#define COMPASS_SCL     A5

// GPS serial pins
#define GPS_RX          0
#define GPS_TX          1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





////// Variable Definitions ////////////////////////////////////////////////////////////////////////////////////////////////////////
double signalStackPosition;             // latitude and longitude
float signalStackDirection;             // Compass angle in degrees
#define COMPASS_ADDRESS         0x0D    // I2C address for Matek M8Q-5883
#define COMPASS_DATA_LENGTH     4       // number of bytes required to hold compass data
uint8_t compassBytes[4];
uint8_t compassByte;

#define STEP_ANGLE 0.12;                // degrees per step according to motor
uint8_t motorPWM = 230;                 // approximately 90% duty cycle to not kill H bridges
uint8_t stepCount = 0;                  // tracks what step the motor is on
int16_t stepNumber;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





////// Function Definitions ////////////////////////////////////////////////////////////////////////////////////////////////////////
void Telemetry();
void stackRotate(int16_t numSteps);
void motorStep(uint8_t PWM);
void updateCompass();
void updateGPS();
void goToAngle(uint16_t degrees);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
