#define Mic1 A1
#define Mic2 A0
#define Mic3 A3
#define Mic4 A2

int ListL = 128;
int Arr1[128];
int Arr2[128];
int Arr3[128];
int Arr4[128];
int Delay = 8;


int Forth;
int Left;
int Back;
int Right;
int DirFinal;

int xComp;
int yComp;
int x;
int y;

void SoundDetectionSetup() {
  pinMode(Mic1, INPUT);
  pinMode(Mic2, INPUT);
  pinMode(Mic3, INPUT);
  pinMode(Mic4, INPUT);
  Serial.begin(9600);// initialize serial communications at 9600 bps: 
}

void SoundDetectionLoop(bool Log) {
  
  int Min1 = 1000;
  int Min2 = 1000;
  int Min3 = 1000;
  int Min4 = 1000;

  int Max1 = 0;
  int Max2 = 0;
  int Max3 = 0;
  int Max4 = 0;
    
  for(int i = 0; i < ListL; i++) {
   Arr1[i] = analogRead(Mic1);
   Arr2[i] = analogRead(Mic2);
   Arr3[i] = analogRead(Mic3);
   Arr4[i] = analogRead(Mic4);
  delay(Delay);
  }
  for (int i = 0; i < ListL; i++) {
      
      Max1 = max(Arr1[i],Max1);
      Min1 = min(Arr1[i],Min1);

      Max2 = max(Arr2[i],Max2);
      Min2 = min(Arr2[i],Min2);

      Max3 = max(Arr3[i],Max3);
      Min3 = min(Arr3[i],Min3);
      
      Max4 = max(Arr4[i],Max4);
      Min4 = min(Arr4[i],Min4);
  }

  Forth = Max1 - Min1;
  Left = Max2 - Min2;
  Back = Max3 - Min3;
  Right = Max4 - Min4;

   if (Forth > Back) {
      yComp = Forth;
      y = 1;
    }
   else {
      yComp = Back;
      y = -1;
    }
   if (Left > Right) {
      xComp = Left;
      x = -1;
    }
  else {
      xComp = Right;
      x = 1;
    }


if (yComp > xComp +2 ) {
      if (y == 1) { DirFinal = 1;}
      if (y == -1) { DirFinal = 2;}
  }
  
else if (xComp > yComp + 2) {
      if (x == 1) {DirFinal = 3;}
      if (x == -1) {DirFinal = 4;}
  }

else {
  if (y == 1 && x == 1){ DirFinal = 5;}
  if (y == 1 && x == -1) {DirFinal = 6;}
  if (y == -1 && x == 1) {DirFinal = 7;}
  if (y == -1 && x == -1) {DirFinal = 8;}
  }

  if(!Log){
    return;
  }

// Debug
 if (xComp > yComp + 2) {
    Serial.print("x-dir = "); Serial.print(x); Serial.print(" , y-dir = "); Serial.println(0);
  }
 else if (yComp > xComp + 2){
    Serial.print("x-dir = "); Serial.print(0); Serial.print(" , y-dir = "); Serial.println(y);
  }
 else {
    Serial.print("x-dir = "); Serial.print(x); Serial.print(" , y-dir = "); Serial.println(y);
  }

  

  Serial.print("1,"); Serial.print(" Min: "); Serial.print(Min1); Serial.print(" Max: "); Serial.print(Max1); Serial.print(" Diff: "); Serial.println(Forth);   
  Serial.print("2,"); Serial.print(" Min: "); Serial.print(Min2); Serial.print(" Max: "); Serial.print(Max2); Serial.print(" Diff: "); Serial.println(Left);
  Serial.print("3,"); Serial.print(" Min: "); Serial.print(Min3); Serial.print(" Max: "); Serial.print(Max3); Serial.print(" Diff: "); Serial.println(Back);
  Serial.print("4,"); Serial.print(" Min: "); Serial.print(Min4); Serial.print(" Max: "); Serial.print(Max4); Serial.print(" Diff: "); Serial.println(Right);
  Serial.println("___________________________________");      

  
  delay(500);
}
