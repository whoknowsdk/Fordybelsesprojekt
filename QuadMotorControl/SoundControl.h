#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial softwareSerial(10, 11);
DFRobotDFPlayerMini player;

void SoundPlayerSetup() {
  softwareSerial.begin(9600);
  
  if (player.begin(softwareSerial)) {
    player.volume(volumeLevel);  
    player.play(1);
  } else {
    Serial.println("Connecting   to DFPlayer Mini failed!");
  }
}

enum SoundTrack {
  Nysgerrig1,
  Passiv1,
  Passiv2,
  Passiv3,
  Snork1,
  Sur1,
  Sur2,
  Sur3,
  Sang1
};

#define IDNAME(name) #name
const char* soundTrackNames[] = {
  IDNAME(Nysgerrig1),
  IDNAME(Passiv1),
  IDNAME(Passiv2),
  IDNAME(Passiv3),
  IDNAME(Snork1),
  IDNAME(Sur1),
  IDNAME(Sur2),
  IDNAME(Sur3),
  IDNAME(Sang1)
};

void PlaySound(SoundTrack track){
  if (digitalRead(7) == 1){
    player.play(track + 1); 
  }
}

void PlayRandomSound(SoundTrack tracks[]){
  if (digitalRead(7) == 1){
    int rnd = random(0, sizeof(tracks) / sizeof(int));
    player.play(tracks[rnd] + 1);
  }
}
