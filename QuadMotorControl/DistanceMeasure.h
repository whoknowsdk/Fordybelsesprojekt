float ultraMeasure(int TRIG_PIN, int ECHO_PIN) {
  distance_cm = GetDistance(TRIG_PIN, ECHO_PIN);
  return distance_cm;
}

float filter(float filterArray[], float rawArray[], bool comp) {
    // For normal
    if (!comp) {
        for (int i = 0; i < 10; i++){
        filterArray[i] = rawArray[i];
        }
      }
    else {
        for (int i = 10; i < 20; i++){
        filterArray[i - 10] = rawArray[i];
        }
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
  for (int i = 3; i < 7; i++) {
    sum += filterArray[i];
  }
  
  return sum / 4;
}

void FindWall(bool Sleep) {
    distN = filter (filterArrayN, distRawN, false);
    distS = filter (filterArrayS, distRawS, false);
    distE = filter (filterArrayE, distRawE, false);
    distW = filter (filterArrayW, distRawW, false);

    int Dir;
    int Dist;

    if (distN < distS && distN < distE && distN < distW ) {
      ChangeDirection(North, 255);
      Dir = 1;
    }
    else if (distS < distN && distS < distE && distS < distW ) {
      ChangeDirection(South, 255);
      Dir = -1;
    }
    else if (distE < distS && distE < distN && distE < distW ) {
      ChangeDirection(East, 255);
      Dir = 2;
    }
    else if (distW < distS && distW < distN && distW < distE ) {
      ChangeDirection(South, 255);
      Dir = -2;
    }
    
    while (Dist > 8){
        int TStart = millis();
        while (Dist < 15){}
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
          long TStart = millis();
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
  distN = filter (filterArrayN, distRawN, false);
  distCompN = filter (filterArrayCompN, distRawN, true);
  distS = filter (filterArrayS, distRawS, false);
  distCompS = filter (filterArrayCompS, distRawS, true);
  distE = filter (filterArrayE, distRawN, false);
  distCompE = filter (filterArrayCompE, distRawE, true);
  distW = filter (filterArrayW, distRawN, false);
  distCompW = filter (filterArrayCompW, distRawW, true);

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
