int ran;
int minimumDistance = 25;

void efterforsk(){
    //player.play(/*Track number*/);
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("Efterforsk");
    MotionDirection();
  }
  
void sang(){
    //player.play(/*Track number*/);
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("Singing");
    ActionTime = 2000;
  }
  
void lur(){
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("Lur");
    ActionTime = 10000;
  //  FindWall(true);
    //player.play(/*Track number*/);
    
}

void snurreRundt(){
  // SPiiinnnnnn
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print("Spinning");
  int ran = random(1, 4);
  int LvsR = random(1, 3);
  int wait = ran * 1000;
  ActionTime = wait;
  if (LvsR = 1){ChangeDirection(RotateLeft, 255);}
  else {ChangeDirection(RotateRight, 255);}
}

void opmearksomhed(){
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("Wanting attention");
    //player.play(/*Track number*/);
    ActionTime = 7000;
    MotionDirection();
  }
  
void selvhad(){
    //player.play(/*Track number*/);
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("Hating myself");
    ActionTime = 10000;
    //FindWall(false);
  }
  
void vrede(){
    //player.play(/*Track number*/);
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("Angryyy");
    ActionTime = 7000;
    MotionDirection();
}

void nysgerrig(){
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("Curious");
    ActionTime = 7000;
    //DetectSound(2000, 128);
    //player.play(/*Track number*/);
}

// ActiveAction
// ChangeDirection(dir, speed);

void ActionPicker (){

  if (mood >= 45 && avoiding == false && distance_N <= minimumDistance || distance_E <= minimumDistance ||  distance_S <= minimumDistance || distance_W <= minimumDistance){
    ChangeDirection(Stop);
    Avoidance(minimumDistance);
  }

  if (mood > 85) {
    ran = random(0, 90);
    if (ran > 75) {efterforsk();}
    else if (ran > 60) {sang();}
    else if (ran > 55) {lur();}
    else if (ran > 40) {snurreRundt();}
    else if (ran > 30) {opmearksomhed();}
    else if (ran > 0)  {nysgerrig();}
    }
  else if (mood > 70) {
    ran = random(0, 120);
    if (ran > 90) {efterforsk();}
      else if (ran > 85) {lur();}
      else if (ran > 65) {snurreRundt();}
      else if (ran > 45) {opmearksomhed();}
      else if (ran > 0)  {nysgerrig();}
    }
  else if (mood > 45) {
    ran = random(0, 130);
    if (ran > 85) {efterforsk();}
      else if (ran > 75) {lur();}
      else if (ran > 45) {opmearksomhed();}
      else if (ran > 0)  {nysgerrig();}
    }
  else if (mood > 15) {
    ran = random(0, 120);
    if (ran > 60) {efterforsk();}
      else if (ran > 45) {lur();}
      else if (ran > 25) {opmearksomhed();}
      else if (ran > 0)  {selvhad();}
    }
  else if (mood > 0) {
    ran = random(0, 100);
    if (ran > 50) {efterforsk();}
      else if (ran > 25) {selvhad();}
      else if (ran > 0)  {vrede();}
    }
}
