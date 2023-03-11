// Includes

#include "Variables.h"
#include "DirectionEnum.h"
#include "DirectionChange.h"
#include "MotorSetup.h"
#include "SensorControl.h"
#include "SoundControl.h"
#include "AvoidanceSystem.h"
#include "SoundDetection.h"

#include "TouchSensor.h"
#include "DistanceMeasure.h"

#include "Screen.h"
#include "ActionChooser.h"

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
  MotorSetup();
  SensorSetup();
  SoundPlayerSetup();
  showSensorInfo = false;
  delay(5000);
}

void loop(){
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
  SensorLoop();
  TouchLoop();
}
