//Dette er en form for "Statemachine", som ændre retning og hastighed af robotten, ud fra dens parametre

//Denne funktion bruger princippet "Overloading", eftersom der allerede er en funktion der hedder "ChangeDirection",
//men denne funtion behøver ikke en hastigheds variable som parametre, eftersom det er ligemeget, i det at den stopper robotten.

//Alle variablerne ift. pins bliver sat i et andet script (Som jeg ikke har lavet 100% selv. Derfor er det ikke inkluderet).
//Alle "Direction" variablerne er lavet fra en enum (Her refererer jeg til "DirectionEnum" scriptet.
void ChangeDirection(Direction newDirection){
  if (newDirection == Stop){

    //Eftersom alle case'ne indeholder det samme, men med forskellige "HIGH" / "LOW" værdier, beskrives det kun her, og ikke resten af scriptet.

    //Her sættes den foreste (T for top) venste (L for left) motor (M for motor) til at stå stille.
    //_1 er den positive (røde) indang til mortoren
    //_2 er den negative (sorte) indgang til mortoren
    //Eftersom det er en DC motor, kan retningen af motoren skiftest ud fra om der sættes strøm til den positive eller den negative indgang.
    //Derfor, når begge indgange sættes til LOW, får den ikke størm, ergo. den stopper. Hvis _1 bliver sat til HIGH, når _2 er LOW, vil motoren
    //dreje fremad. Hvis det er omvendt, altså _1 er LOW og _2 er HIGH, vil motoren dreje baglæns.
    digitalWrite(TLM_1, LOW);
    digitalWrite(TLM_2, LOW);

    //Det samme sker her for (Top Right Motor)
    digitalWrite(TRM_1, LOW);
    digitalWrite(TRM_2, LOW);

    //Igen for (Back Left Motor
    digitalWrite(BLM_1, LOW);
    digitalWrite(BLM_2, LOW);

    //Og til sidst for (Back Right Motor)
    digitalWrite(BRM_1, LOW);
    digitalWrite(BRM_2, LOW);

    //Til aller sidst, bliver hastigheden sat, ved at sætte hastigheden til motor kontrol pins'ne. (Dette sker selvfølgelig med en varierende variable i den
    //følgende funktion.
    analogWrite(TLEN, 0);
    analogWrite(TREN, 0);
    analogWrite(BLEN, 0);
    analogWrite(BREN, 0);
  }
}

//Her sker det samme, bortset fra at der modtages en hastighed med retningen.
void ChangeDirection(Direction newDirection, int speedValue){
  //Staten bliver ændret ift. en switch statement (Hvilket er muligt, eftersom der bliver gjort brug af en enum,
  //som jo egentligt er et tal fra 0 til 10 (I dette tilfælde)
  //Dette switch statement ændre motornes output til at være overensstemmende med den retning den skal bevæge sig.
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
