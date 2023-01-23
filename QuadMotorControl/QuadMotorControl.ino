// Includes
#include "Variables.h"
#include "DirectionEnum.h"
#include "DirectionChange.h"
#include "JoystickControl.h"
#include "MotorSetup.h"
#include "SensorControl.h"
#include "StateEnum.h"
#include "SoundControl.h"
#include "BehaviouralControl.h"
#include "SoundDetection.h"
#include "DistanceMeasure.h"
//#include "ControllerReceiver.h"

#include "Screen.h"
//#include "RFID.h"

// CODE

void setup() {
  Serial.begin(9600);
  ScreenSetup();
  //SoundDetectionSetup();
  //RFIDSetup();
  //MotorSetup();
  SensorSetup();
  //ReceiverSetup();
  showSensorInfo = true;
  //joystickControlOn = false;
  //ChangeDirection(North, 255);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Mood: " + String(mood));
  lcd.setCursor(0, 1);
  lcd.print("(^-^)");


  //SoundDetectionLoop(false);
  //RFIDLoop();
  /*
  if (joystickControlOn) {
    JoystickLoop();
  }*/

  SensorLoop();
  if (DirCur ==  0){
    ActionPicker();
    }
  //BehavioralLoop();
  //ReceiverLoop();
}
