// Includes
#include "Variables.h"
#include "DirectionEnum.h"
#include "DirectionChange.h"
#include "JoystickControl.h"
#include "MotorSetup.h"
#include "SensorControl.h"
#include "StateEnum.h"
#include "ActionsEnum.h"
#include "SoundControl.h"
#include "BehaviouralControl.h"
#include "ControllerReceiver.h"

// CODE

void setup() {
  Serial.begin(9600);
  MotorSetup();
  //SensorSetup();
  ReceiverSetup();
  showSensorInfo = false;
  joystickControlOn = false;
  ChangeDirection(North, 255);
}

void loop() {/*
  if (joystickControlOn) {
    JoystickLoop();
  }*/

  //SensorLoop();
  //BehavioralLoop();
  //ReceiverLoop();
}
