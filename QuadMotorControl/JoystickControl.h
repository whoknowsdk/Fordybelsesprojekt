void JoystickLoop(){
  int Y_Value = analogRead(A0);
  int X_Value = analogRead(A2);
  int Rot_Value = analogRead(A1);
  int currentSpeedValue = 0;
  Direction dir = Stop;
  if (Rot_Value >= 525){
    currentSpeedValue = map(Rot_Value, 525, 1023, minMotorSpeed, maxMotorSpeed);
    ChangeDirection(RotateRight, currentSpeedValue);
    dir = RotateRight;
  }
  else if (Rot_Value <= 475){
    currentSpeedValue = map(Rot_Value, 475, 0, minMotorSpeed, maxMotorSpeed);
    ChangeDirection(RotateLeft, currentSpeedValue);
    dir = RotateLeft;
  }
  else if (Y_Value >= 550 && X_Value >= 550){
    currentSpeedValue = map((Y_Value + X_Value) / 2, 550, 1023, minMotorSpeed, maxMotorSpeed);
    ChangeDirection(NorthEast, currentSpeedValue);
    dir = NorthEast;
  }
  else if (Y_Value <= 500 && X_Value <= 500){
    currentSpeedValue = map((Y_Value + X_Value) / 2, 500, 0, minMotorSpeed, maxMotorSpeed);
    ChangeDirection(SouthWest, currentSpeedValue);
    dir = SouthWest;
  }
  else if (Y_Value >= 550 && X_Value <= 500){
    currentSpeedValue = map(abs(Y_Value - X_Value), 550, 1023, minMotorSpeed, maxMotorSpeed);
    ChangeDirection(NorthWest, currentSpeedValue);
    dir = NorthWest;
  }
  else if (Y_Value <= 500 && X_Value >= 550){
    currentSpeedValue = map(abs(Y_Value - X_Value), 550, 1023, minMotorSpeed, maxMotorSpeed);
    ChangeDirection(SouthEast, currentSpeedValue);
    dir = SouthEast;
  }
  else if (Y_Value >= 550){
    currentSpeedValue = map(Y_Value, 550, 1023, minMotorSpeed, maxMotorSpeed);
    ChangeDirection(North, currentSpeedValue);
    dir = North;
  }
  else if (Y_Value <= 500){
    currentSpeedValue = map(Y_Value, 500, 0, minMotorSpeed, maxMotorSpeed);
    ChangeDirection(South, currentSpeedValue);
    dir = South;
  }
  else if (X_Value >= 550){
    currentSpeedValue = map(X_Value, 550, 1023, minMotorSpeed, maxMotorSpeed);
    ChangeDirection(East, currentSpeedValue);
    dir = East;
  }
  else if (X_Value <= 500){
    currentSpeedValue = map(X_Value, 500, 0, minMotorSpeed, maxMotorSpeed);
    ChangeDirection(West, currentSpeedValue);
    dir = West;
  }
  else {
    ChangeDirection(Stop);
    dir = Stop;
  }

  if (showDirectionInfo) {
    Serial.print("Direction: ");
    Serial.print(directionNames[dir]);
    Serial.print(" - Speed: ");
    Serial.println(currentSpeedValue);
  }

  if (showJoystickInfo) {
    Serial.print("X: ");
    Serial.print(X_Value);
    Serial.print(" - Y: ");
    Serial.print(Y_Value);
    Serial.print(" - Rot: ");
    Serial.println(Rot_Value);
  }
}
