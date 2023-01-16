void SensorSetup(){
  pinMode(TRN, OUTPUT);
  pinMode(TRE, OUTPUT);
  pinMode(TRS, OUTPUT);
  pinMode(TRW, OUTPUT);
  pinMode(ECN, INPUT);
  pinMode(ECE, INPUT);
  pinMode(ECS, INPUT);
  pinMode(ECW, INPUT);
}

float GetDistance(int TriggerPin, int EchoPin){
  digitalWrite(TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  float duration = pulseIn(EchoPin, HIGH);
  float distance = (duration * 0.0343) / 2;
  distance = constrain(distance, minDistance, maxDistance);
  return distance;
}

void SensorLoop(){
  distance_N = GetDistance(TRN, ECN);
  distance_E = GetDistance(TRE, ECE);
  distance_S = GetDistance(TRS, ECS);
  distance_W = GetDistance(TRW, ECW);
  
  if (showSensorInfo) {
    Serial.print("N: ");
    Serial.print(distance_N);
    Serial.print(" - E: ");
    Serial.print(distance_E);
    Serial.print(" - S:");
    Serial.print(distance_S);
    Serial.print(" - W:");
    Serial.println(distance_W);
  }
}
