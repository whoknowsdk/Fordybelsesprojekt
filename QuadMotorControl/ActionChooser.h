int ran;
int caseCount;
int LastTime = millis();

void efterforsk(){
  //Afspil lyd
    MotionDirection();
  }
void sang(){

  // Lyd
  }
void lur(){
    FindWall(true);
    int TStart = millis();
  while (millis()-TStart > 60000){}  
  }
void snurreRundt(){
  // SPiiinnnnnn
  int ran = random(1, 4);
  int LvsR = random(1, 3);
  int wait = ran * 1000;
    
  if (LvsR = 1){ChangeDirection(RotateLeft, 255);}
  else {ChangeDirection(RotateRight, 255);}
  int TStart = millis();
  while (millis()-TStart > wait){}  
  }
void opmearksomhed(){
  // Lyd
    MotionDirection();
  }
void selvhad(){
    FindWall(false);
  }
void vrede(){
    // Lyd
    DetectSound(2000, 128);
    int TStart = millis();
  while (millis()-TStart > 5000){}  
  }

void nysgerrig(){
    DetectSound(2000, 128);
    int TStart = millis();
  while (millis()-TStart > 3000){}  
  }

// ActiveAction
// ChangeDirection(dir, speed);

void ActionPicker (){
  ran = random(0, happiness);

  if (happiness > 85) {caseCount = 0;}
  else if (happiness > 70) {caseCount = 1;}
  else if (happiness > 45) {caseCount = 2;}
  else if (happiness > 15) {caseCount = 3;}
  else if (happiness > 0) {caseCount = 4;}

  switch (caseCount){
    case (0):
      if (ran > 75) {efterforsk();}
      else if (ran > 60) {sang();}
      else if (ran > 55) {lur();}
      else if (ran > 40) {snurreRundt();}
      else if (ran > 30) {opmearksomhed();}
      else if (ran > 0)  {nysgerrig();}
    case (1):
      if (ran > 90) {efterforsk();}
      else if (ran > 85) {lur();}
      else if (ran > 65) {snurreRundt();}
      else if (ran > 45) {opmearksomhed();}
      else if (ran > 0)  {nysgerrig();}
            
    case (2):
      if (ran > 85) {efterforsk();}
      else if (ran > 75) {lur();}
      else if (ran > 45) {opmearksomhed();}
      else if (ran > 0)  {nysgerrig();}
    case (3):
      if (ran > 60) {efterforsk();}
      else if (ran > 45) {lur();}
      else if (ran > 25) {opmearksomhed();}
      else if (ran > 0)  {selvhad();}
    case (4):
      if (ran > 50) {efterforsk();}
      else if (ran > 25) {selvhad();}
      else if (ran > 0)  {vrede();}
    }
  }
