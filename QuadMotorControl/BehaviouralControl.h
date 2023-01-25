//Random movements her...
//Stop kontrol

// TEMP Variables:

bool actionRunning = false;
bool avoiding = false;
State currentState = Happy;
float actionWaitTime = 0;
float actionRunTime = 0;
int cooldownPeriod = 3000;

float minActionRunTime = 1000;
float maxActionRunTime = 7000;

// Happy state variables
int happyIntervalMin = 15000;
int happyIntervalMax = 30000;
int happyMinDistance = 25;

// Scared state variables
int scaredIntervalMin = 3000;
int scaredIntervalMax = 7000;
int scaredMinDistance = 100;

// Depressed state variables
int depressedIntervalMin = 60000;
int depressedIntervalMax = 120000;
int depressedMinDistance = 100;

//
// Variables
//

/*
char songs[] = {
  "sang1",
  "sang2"
};

void SingAction() {
  int songNr = random(sizeof(songs) / sizeof(String) - 1);
  PlaySound(songs[songNr])
}
*/
Direction GetRandomDirection(){
  int directionNr = random(0, 9);
  Serial.println(directionNames[directionNr]);
  return directionNr;
}

void RunRandomAction(){
  actionRunning = true;
  if (currentState == Happy){
    ChangeDirection(GetRandomDirection(), 255);
    actionWaitTime = millis() + random(happyIntervalMin, happyIntervalMax);
    actionRunTime = millis() + random(minActionRunTime, maxActionRunTime);
  }

  if (currentState == Scared){
    ChangeDirection(GetRandomDirection(), 255);
    actionWaitTime = millis() + random(scaredIntervalMin, scaredIntervalMax);
    actionRunTime = millis() + random(minActionRunTime, maxActionRunTime);
  }

  if (currentState == Depressed){
    ChangeDirection(GetRandomDirection(), 255);
    actionWaitTime = millis() + random(depressedIntervalMin, depressedIntervalMax);
    actionRunTime = millis() + random(minActionRunTime, maxActionRunTime);
  }
}

void Avoidance(float minDistance){
  Serial.print("Avoiding - ");
  
  SensorLoop();
  
  if (distance_N < minDistance && distance_E < minDistance && distance_S < minDistance && distance_W < minDistance){
    ChangeDirection(RotateLeft, 255);
    Serial.println("RotateLeft - 4");
  }
  else if (distance_N < minDistance && distance_E < minDistance && distance_W < minDistance){
    ChangeDirection(South, 255);
    Serial.println("South - 3");
  }
  else if (distance_N < minDistance && distance_E < minDistance && distance_S < minDistance){
    ChangeDirection(West, 255);
    Serial.println("West - 3");
  }
  else if (distance_N < minDistance && distance_S < minDistance && distance_W < minDistance){
    ChangeDirection(East, 255);
    Serial.println("East - 3");
  }
  else if (distance_E < minDistance && distance_S < minDistance && distance_W < minDistance){
    ChangeDirection(North, 255);
    Serial.println("North - 3");
  }
  else if (distance_N < minDistance && distance_E < minDistance){
    ChangeDirection(SouthWest, 255);
    Serial.println("SouthWest - 2");
  }
  else if (distance_N < minDistance && distance_W < minDistance){
    ChangeDirection(SouthEast, 255);
    Serial.println("SouthEast - 2");
  }
  else if (distance_S < minDistance && distance_W < minDistance){
    ChangeDirection(NorthEast, 255);
    Serial.println("NorthEast - 2");
  }
  else if (distance_E < minDistance && distance_S < minDistance){
    ChangeDirection(NorthWest, 255);
    Serial.println("NorthWest - 2");
  }
  else if (distance_N < minDistance && distance_S < minDistance){
    ChangeDirection(East, 255);
    Serial.println("East - 2");
  }
  else if (distance_E < minDistance && distance_W < minDistance){
    ChangeDirection(North, 255);
    Serial.println("North - 2");
  }
  else if (distance_N < minDistance){
    ChangeDirection(South, 255);
    Serial.println("South - 1");
  }
  else if (distance_E < minDistance){
    ChangeDirection(West, 255);
    Serial.println("West - 1");
  }
  else if (distance_S < minDistance){
    ChangeDirection(North, 255);
    Serial.println("North - 1");
  }
  else if (distance_W < minDistance){
    ChangeDirection(East, 255);
    Serial.println("East - 1");
  }
  
  if (distance_N >= minDistance && distance_E >= minDistance && distance_S >= minDistance && distance_W >= minDistance){
    ChangeDirection(Stop);
    avoiding = false;
    actionRunning = true;
    actionWaitTime = millis() + cooldownPeriod;
    return;
  }

  Avoidance(minDistance);
}

void BehavioralLoop(){
  if (avoiding == false && actionRunning == false){
    Serial.println("Running Action");
    RunRandomAction();
  }

  if (avoiding == false && currentState == Happy && distance_N <= happyMinDistance || distance_E <= happyMinDistance ||  distance_S <= happyMinDistance || distance_W <= happyMinDistance){
    ChangeDirection(Stop);
    actionRunning = false;
    Avoidance(happyMinDistance);
  }

  if (millis() >= actionRunTime){
    ChangeDirection(Stop);
  }

  if (millis() >= actionWaitTime){
    ChangeDirection(Stop);
    actionRunning = false;
  }
}
