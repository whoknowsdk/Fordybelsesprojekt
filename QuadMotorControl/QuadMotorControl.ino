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

#include "TouchSensor.h"
#include "AccelerometerControle.h"
#include "DistanceMeasure.h"

//#include "ControllerReceiver.h"
#include "Screen.h"
#include "ActionChooser.h"
//#include "RFID.h"
  long waitTmp = millis();
// CODE

void setup() {
  Serial.begin(9600);
  ScreenSetup();
  lcd.setCursor(0, 0);
  lcd.print("Mood: " + String(mood) + " ");
  lcd.setCursor(0, 1);
  lcd.print("(^-^)");
  //SoundDetectionSetup();
  //RFIDSetup();
  //MotorSetup();
  SensorSetup();
  //ReceiverSetup();
  showSensorInfo = true;
  //joystickControlOn = false;
  //ChangeDirection(North, 255);
  
}

void loop(){  
  /*if (millis() - waitTmp > 5000) {
     ChangeDirection(North, 255);
     waitTmp = millis();
    }*/

  //SensorLoop();
  // DirCur = Direction Currently - For Bloms' skyld findes denne kommentar. 



  if (millis() - ActionStart > ActionTime) {
      //lcd.print("Doing something");
      ActionStart = millis();
      ActionPicker();  
    }
  
  if (millis() - LastMsgT > 3000){
      MsgPicker();
      LastMsgT = millis();
    }

  if (millis() - LastDrop > 10000){
    LastDrop = millis();
    if (mood > 0){
        mood = mood - 1;
        lcd.setCursor(0, 0);
        lcd.print("Mood: " + String(mood) + " ");
      } 
    }
  TouchLoop();
}
