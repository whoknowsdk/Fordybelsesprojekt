#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void SpeakerSetup(){
  tmrpcm.speakerPin = 9;
  
  if(!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    return;
  }

  tmrpcm.setVolume(6);
  tmrpcm.quality(2);
}

void PlaySound(char soundName){
  //String path = soundName + ".wav";
  //char test[path.length() + 1];
  //path.toCharArray(test.length(), path.length());
  //char arrayTest = path.toCharArray(arrayTest, path.length());
  //tmrpcm.play(path);
  Serial.println(soundName);
}
