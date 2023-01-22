// Includes
#include "Variables.h"
/*
#include "DirectionEnum.h"
#include "DirectionChange.h"
#include "JoystickControl.h"
#include "MotorSetup.h"*/
#include "SensorControl.h"/*
#include "StateEnum.h"
#include "ActionsEnum.h"
#include "SoundControl.h"
#include "BehaviouralControl.h"
#include "ControllerReceiver.h"
*/
#include "Screen.h"
//#include "SoundDetection.h"
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
  lcd.print("Energi: " + String(energy));
  lcd.setCursor(0, 2);
  lcd.print("Social: " + String(social));
  lcd.setCursor(0,3);
  lcd.print("(^-^)");


  //SoundDetectionLoop(false);
  //RFIDLoop();
  /*
  if (joystickControlOn) {
    JoystickLoop();
  }*/

  SensorLoop();
  //BehavioralLoop();
  //ReceiverLoop();
}
