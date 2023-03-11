#define Mic1 A1
#define Mic2 A0
#define Mic3 A3
#define Mic4 A2

void SoundDetectionSetup() {
  pinMode(Mic1, INPUT);
  pinMode(Mic2, INPUT);
  pinMode(Mic3, INPUT);
  pinMode(Mic4, INPUT);
  Serial.begin(9600);// initialize serial communications at 9600 bps: 
}

//Sound detection function. Takes total time measuring in milliseconds, and how many measurements per mic. Be aware of limited memory in arduino.

void DetectSound(int totalTime, int arrL){
    
    int TNow = millis();
    
    int Arr1[arrL];
    int Arr2[arrL];
    int Arr3[arrL];
    int Arr4[arrL];
    int Delay = totalTime/arrL;

    int AvgN = 0;
    int AvgW = 0;
    int AvgS = 0;
    int AvgE = 0; 


    for(int i = 0; i < arrL; i++) {
      Arr1[i] = analogRead(Mic1);
      Arr2[i] = analogRead(Mic2);
      Arr3[i] = analogRead(Mic3);
      Arr4[i] = analogRead(Mic4);
//       while (millis() - TNow > Delay) {TNow = millis();}
    }

    // Filters (hopefully) all arrays at the same time.
    for (int i = 0; i < 9; i++) {
      for (int j = i + 1; j < 10; j++) {
        if (Arr1[i] > Arr1[j]) {
          float swap = Arr1[i];
          Arr1[i] = Arr1[j];
          Arr1[j] = swap;
        }
        if (Arr2[i] > Arr2[j]) {
          float swap = Arr2[i];
          Arr2[i] = Arr2[j];
          Arr2[j] = swap;
        }
        if (Arr3[i] > Arr3[j]) {
          float swap = Arr1[i];
          Arr3[i] = Arr3[j];
          Arr3[j] = swap;
        }
        if (Arr4[i] > Arr4[j]) {
          float swap = Arr4[i];
          Arr4[i] = Arr4[j];
          Arr4[j] = swap;
        }
      }
    }

    // Designate middle avgs

    double sum1 = 0;
    double sum2 = 0;
    double sum3 = 0;
    double sum4 = 0;
    
    for (int sample = arrL/2 - 2; sample < arrL/2 + 2; sample++) {
      sum1 += Arr1[sample];
      sum2 += Arr2[sample];
      sum3 += Arr3[sample];
      sum4 += Arr4[sample];
    }
  
    AvgN = sum1 / 4;
    AvgW = sum2 / 4;
    AvgS = sum3 / 4;
    AvgE = sum4 / 4;

    int yComp;
    int xComp;

    int y;
    int x; 

    // Comparison of averages to choose final direction

    if (AvgN > AvgS) {yComp = AvgN; y = 1;}
    else {yComp = AvgN; y = -1;}
    
    if (AvgW > AvgS) {xComp = AvgW;x = -1;}
    else {xComp = AvgE ;x = 1;}

    if (yComp > xComp +2 ) {
      if (y == 1) { ChangeDirection(North, 255);}
      if (y == -1) { ChangeDirection(South, 255);}
    }
  
    else if (xComp > yComp + 2) {
      if (x == 1) {ChangeDirection(East, 255);}
      if (x == -1) {ChangeDirection(West, 255);}
    }

    else {
      if (y == 1 && x == 1){ ChangeDirection(NorthEast, 255);}
      if (y == 1 && x == -1) {ChangeDirection(NorthWest, 255);}
      if (y == -1 && x == 1) {ChangeDirection(SouthEast, 255);}
      if (y == -1 && x == -1) {ChangeDirection(SouthWest, 255);}
    }
}
