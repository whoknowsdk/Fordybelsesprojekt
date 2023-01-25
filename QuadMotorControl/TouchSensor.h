int Left;
int Middle;
int Right;

const int pressureSensitivity = 200;

bool touchedLeft = false;
bool touchedRight = false;
bool touchedMiddle = false;

int timer = 1000;
long delayStart = 0;
bool delayRunning = false;

void CheckTime()
{
  if (delayRunning && ((millis() - delayStart) >= timer)) 
  {
    delayRunning = false; 
    touchedLeft = false;
    touchedMiddle = false;
    touchedRight = false;
  }
}

void TouchSetup(void) {
  Serial.begin(9600);   
}
 
void TouchLoop(void) {
  CheckTime();
  Left = analogRead(A4);
  Middle = analogRead(A5);
  Right = analogRead(A6);

  if(Left > pressureSensitivity)
  {
    //touchedLeft = true;
     if(touchedMiddle == true)
    {
      if(touchedRight == true)
      {
        Serial.println("Sennep has been touched"); 
        mood = mood + 10; 
        touchedLeft = false;
        touchedMiddle = false;
        touchedRight = false;
      } 
      if (touchedRight == false)
      {
        touchedMiddle = false;  
      } 
    }
    if(touchedMiddle == false)
    {
      touchedLeft = true;
      delayRunning = true;
      delayStart = millis();
    } 
    if (touchedRight == true)
    {
       if(touchedMiddle == false)
       {
          touchedRight = false; 
       }
    }
  }
  if(Middle > pressureSensitivity)
  {
    //touchedMiddle = true;
    if(touchedRight == true)
    {
      touchedMiddle = true;
      delayStart = millis();
      
    }
    if(touchedLeft == true)
    {
      touchedMiddle = true; 
      delayStart = millis(); 
    }
  }
  if(Right > pressureSensitivity)
  {
      if(touchedMiddle == true)
    {
      if(touchedLeft == true)
      {
        Serial.println("Sennep has been touched"); 
        touchedLeft = false;
        touchedMiddle = false;
        touchedRight = false;
      } 
      if (touchedLeft == false)
      {
        touchedMiddle = false;  
      }
    }
    if(touchedMiddle == false)
    {
      touchedRight = true;
      delayStart = millis();
    }
    if (touchedLeft == true)
    {
       if(touchedMiddle == false)
       {
          touchedLeft = false; 
       }
    }
  }
}

String GetPressureLevel(int pressure){
  String level;
  if (pressure < 10) {
    level = " - No pressure";
  } else if (pressure < 200) {
    level = " - Light touch";
  } else if (pressure < 500) {
    level = " - Light squeeze";
  } else if (pressure < 800) {
    level = " - Medium squeeze";
  } else {
    level = " - Big squeeze";
  }

  return level;
}
