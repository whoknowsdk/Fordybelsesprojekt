// Includes
/*#include "Variables.h"
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
*/
#include "Screen.h"
#include "SoundDetection.h"

// CODE

void setup() {
  Serial.begin(9600);
  ScreenSetup();
  SoundDetectionSetup();
  //MotorSetup();
  //SensorSetup();
  //ReceiverSetup();
  //showSensorInfo = false;
  //joystickControlOn = false;
  //ChangeDirection(North, 255);
}

void loop() {
  SoundDetectionLoop(false);
  /*
  if (joystickControlOn) {
    JoystickLoop();
  }*/

  //SensorLoop();
  //BehavioralLoop();
  //ReceiverLoop();
}
