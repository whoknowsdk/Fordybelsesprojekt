void ChangeDirection(Direction newDirection){
  if (newDirection == Stop){
    digitalWrite(TLM_1, LOW);
    digitalWrite(TLM_2, LOW);
    
    digitalWrite(TRM_1, LOW);
    digitalWrite(TRM_2, LOW);
    
    digitalWrite(BLM_1, LOW);
    digitalWrite(BLM_2, LOW);
    
    digitalWrite(BRM_1, LOW);
    digitalWrite(BRM_2, LOW);
    
    analogWrite(TLEN, 0);
    analogWrite(TREN, 0);
    analogWrite(BLEN, 0);
    analogWrite(BREN, 0);
  }
}

void ChangeDirection(Direction newDirection, int speedValue){
  switch (newDirection){
    case Stop:
      digitalWrite(TLM_1, LOW);
      digitalWrite(TLM_2, LOW);
      
      digitalWrite(TRM_1, LOW);
      digitalWrite(TRM_2, LOW);
      
      digitalWrite(BLM_1, LOW);
      digitalWrite(BLM_2, LOW);
      
      digitalWrite(BRM_1, LOW);
      digitalWrite(BRM_2, LOW);
      
      analogWrite(TLEN, 0);
      analogWrite(TREN, 0);
      analogWrite(BLEN, 0);
      analogWrite(BREN, 0);
      break;
    case North:
      digitalWrite(TLM_1, HIGH);
      digitalWrite(TLM_2, LOW);
      
      digitalWrite(TRM_1, HIGH);
      digitalWrite(TRM_2, LOW);
      
      digitalWrite(BLM_1, HIGH);
      digitalWrite(BLM_2, LOW);
      
      digitalWrite(BRM_1, HIGH);
      digitalWrite(BRM_2, LOW);
      
      analogWrite(TLEN, speedValue);
      analogWrite(TREN, speedValue);
      analogWrite(BLEN, speedValue);
      analogWrite(BREN, speedValue);
      break;
    case South:
      digitalWrite(TLM_1, LOW);
      digitalWrite(TLM_2, HIGH);
      
      digitalWrite(TRM_1, LOW);
      digitalWrite(TRM_2, HIGH);
      
      digitalWrite(BLM_1, LOW);
      digitalWrite(BLM_2, HIGH);
      
      digitalWrite(BRM_1, LOW);
      digitalWrite(BRM_2, HIGH);
      
      analogWrite(TLEN, speedValue);
      analogWrite(TREN, speedValue);
      analogWrite(BLEN, speedValue);
      analogWrite(BREN, speedValue);
      break;
    case East:
      digitalWrite(TLM_1, HIGH);
      digitalWrite(TLM_2, LOW);
      
      digitalWrite(TRM_1, LOW);
      digitalWrite(TRM_2, HIGH);
      
      digitalWrite(BLM_1, LOW);
      digitalWrite(BLM_2, HIGH);
      
      digitalWrite(BRM_1, HIGH);
      digitalWrite(BRM_2, LOW);
      
      analogWrite(TLEN, speedValue);
      analogWrite(TREN, speedValue);
      analogWrite(BLEN, speedValue);
      analogWrite(BREN, speedValue);
      break;
    case West:
      digitalWrite(TLM_1, LOW);
      digitalWrite(TLM_2, HIGH);
      
      digitalWrite(TRM_1, HIGH);
      digitalWrite(TRM_2, LOW);
      
      digitalWrite(BLM_1, HIGH);
      digitalWrite(BLM_2, LOW);
      
      digitalWrite(BRM_1, LOW);
      digitalWrite(BRM_2, HIGH);
      
      analogWrite(TLEN, speedValue);
      analogWrite(TREN, speedValue);
      analogWrite(BLEN, speedValue);
      analogWrite(BREN, speedValue);
      break;
    case NorthEast:
      digitalWrite(TLM_1, HIGH);
      digitalWrite(TLM_2, LOW);
      
      digitalWrite(TRM_1, LOW);
      digitalWrite(TRM_2, LOW);
      
      digitalWrite(BLM_1, LOW);
      digitalWrite(BLM_2, LOW);
      
      digitalWrite(BRM_1, HIGH);
      digitalWrite(BRM_2, LOW);
      
      analogWrite(TLEN, speedValue);
      analogWrite(TREN, speedValue);
      analogWrite(BLEN, speedValue);
      analogWrite(BREN, speedValue);
      break;
    case NorthWest:
      digitalWrite(TLM_1, LOW);
      digitalWrite(TLM_2, LOW);
      
      digitalWrite(TRM_1, HIGH);
      digitalWrite(TRM_2, LOW);
      
      digitalWrite(BLM_1, HIGH);
      digitalWrite(BLM_2, LOW);
      
      digitalWrite(BRM_1, LOW);
      digitalWrite(BRM_2, LOW);
      
      analogWrite(TLEN, speedValue);
      analogWrite(TREN, speedValue);
      analogWrite(BLEN, speedValue);
      analogWrite(BREN, speedValue);
      break;
    case SouthEast:
      digitalWrite(TLM_1, LOW);
      digitalWrite(TLM_2, LOW);
      
      digitalWrite(TRM_1, LOW);
      digitalWrite(TRM_2, HIGH);
      
      digitalWrite(BLM_1, LOW);
      digitalWrite(BLM_2, HIGH);
      
      digitalWrite(BRM_1, LOW);
      digitalWrite(BRM_2, LOW);
      
      analogWrite(TLEN, speedValue);
      analogWrite(TREN, speedValue);
      analogWrite(BLEN, speedValue);
      analogWrite(BREN, speedValue);
      break;
    case SouthWest:
      digitalWrite(TLM_1, LOW);
      digitalWrite(TLM_2, HIGH);
      
      digitalWrite(TRM_1, LOW);
      digitalWrite(TRM_2, LOW);
      
      digitalWrite(BLM_1, LOW);
      digitalWrite(BLM_2, LOW);
      
      digitalWrite(BRM_1, LOW);
      digitalWrite(BRM_2, HIGH);
      
      analogWrite(TLEN, speedValue);
      analogWrite(TREN, speedValue);
      analogWrite(BLEN, speedValue);
      analogWrite(BREN, speedValue);
      break;
    case RotateLeft:
      digitalWrite(TLM_1, LOW);
      digitalWrite(TLM_2, HIGH);
      
      digitalWrite(TRM_1, HIGH);
      digitalWrite(TRM_2, LOW);
      
      digitalWrite(BLM_1, LOW);
      digitalWrite(BLM_2, HIGH);
      
      digitalWrite(BRM_1, HIGH);
      digitalWrite(BRM_2, LOW);
      
      analogWrite(TLEN, speedValue);
      analogWrite(TREN, speedValue);
      analogWrite(BLEN, speedValue);
      analogWrite(BREN, speedValue);
      break;
    case RotateRight:
      digitalWrite(TLM_1, HIGH);
      digitalWrite(TLM_2, LOW);
      
      digitalWrite(TRM_1, LOW);
      digitalWrite(TRM_2, HIGH);
      
      digitalWrite(BLM_1, HIGH);
      digitalWrite(BLM_2, LOW);
      
      digitalWrite(BRM_1, LOW);
      digitalWrite(BRM_2, HIGH);
      
      analogWrite(TLEN, speedValue);
      analogWrite(TREN, speedValue);
      analogWrite(BLEN, speedValue);
      analogWrite(BREN, speedValue);
      break;
    
  }
}
