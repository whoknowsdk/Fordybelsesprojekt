

float ultraMeasure(int TRIG_PIN, int ECHO_PIN) {
  distance_cm = GetDistance(TRIG_PIN, ECHO_PIN);
  return distance_cm;
}

float filter(int TRIG_PIN, int ECHO_PIN, float filterArray[]) {
    for (int sample = 0; sample < 10; sample++) {
    filterArray[sample] = ultraMeasure(TRIG_PIN, ECHO_PIN);
    int TStart = millis();
    while (millis()-TStart > 30){}   // to avoid untrasonic interfering
  }

  // 2. SORTING THE ARRAY IN ASCENDING ORDER
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (filterArray[i] > filterArray[j]) {
        float swap = filterArray[i];
        filterArray[i] = filterArray[j];
        filterArray[j] = swap;
      }
    }
  }

  double sum = 0;
  for (int sample = 3; sample < 7; sample++) {
    sum += filterArray[sample];
  }
  
  return sum / 4;
}

void FindWall(bool Sleep) {
    distN = filter (TRN, ECN, filterArrayN);
    distS = filter (TRS, ECS, filterArrayS);
    distE = filter (TRE, ECE, filterArrayE);
    distW = filter (TRW, ECW, filterArrayW);

    int Dir;
    int Dist;

    if (distN > distS && distN > distE && distN > distW ) {
      ChangeDirection(North, 255);
      Dir = 1;
    }
    else if (distS > distN && distS > distE && distS > distW ) {
      ChangeDirection(South, 255);
      Dir = -1;
    }
    else if (distE > distS && distE > distN && distE > distW ) {
      ChangeDirection(East, 255);
      Dir = 2;
    }
    else if (distW > distS && distW > distN && distW > distE ) {
      ChangeDirection(South, 255);
      Dir = -2;
    }
    
    while (Dist > 8){
        int TStart = millis();
        while (millis()-TStart > 500){}
        switch(Dir){
          case(1):
            Dist = distN;
            break;
          case(-1):
            Dist = distS;
            break; 
          case(2):
            Dist = distE;
            break;
          case(-2):
            Dist = distW;
            break;
          }      
      }
    Dir = Dir *(-1);
    if (Sleep == false) {
      switch(Dir){
        case(1):
          ChangeDirection(South, 255);
          int TStart = millis();
          while (millis()-TStart > 500){}
          ChangeDirection(North, 255);
          TStart = millis();
          while (millis()-TStart > 500){}
          break;
        case(-1):
          ChangeDirection(North, 255);
          TStart = millis();
          while (millis()-TStart > 500){}
          ChangeDirection(South, 255);
          TStart = millis();
          while (millis()-TStart > 500){}
          break;
        case(2):
          ChangeDirection(West, 255);
          TStart = millis();
          while (millis()-TStart > 500){}
          ChangeDirection(East, 255);
          TStart = millis();
          while (millis()-TStart > 500){}
          break;
        case(-2):
          ChangeDirection(East, 255);
          TStart = millis();
          while (millis()-TStart > 500){}
          ChangeDirection(West, 255);
          TStart = millis();
          while (millis()-TStart > 500){}
          break;
        }
      }   
}   

void MotionDirection() {
  distN = filter (TRN, ECN, filterArrayN);
  distCompN = filter (TRN, ECN, filterArrayCompN);
  distS = filter (TRS, ECS, filterArrayS);
  distCompS = filter (TRS, ECS, filterArrayCompS);
  distE = filter (TRE, ECE, filterArrayE);
  distCompE = filter (TRE, ECE, filterArrayCompE);
  distW = filter (TRW, ECW, filterArrayW);
  distCompW = filter (TRW, ECW, filterArrayCompW);

  distDiffN = abs(distN - distCompN);
  distDiffS = abs(distS - distCompS);
  distDiffE = abs(distE - distCompE);
  distDiffW = abs(distW - distCompW);
    
  Serial.print("DistN: "); Serial.print(distDiffN);
  Serial.print(", DistS: "); Serial.print(distDiffS);
  Serial.print(", DistE: "); Serial.print(distDiffE);
  Serial.print(", DistW: "); Serial.println(distDiffW);

  if (distDiffN > 5) {ChangeDirection(North, 255);}
  if (distDiffS > 5) {ChangeDirection(South, 255);}
  if (distDiffE > 5) {ChangeDirection(East, 255);}
  if (distDiffW > 5) {ChangeDirection(West, 255);}
}
