//Avoidance systemet er med til at sørge for at robotten ikke kører ind i forhindringer, når vi ikke specifikt vil have det.
//Derfor er programmet programmeret til at starte dette recursive blocking loop, som forhindre robotten i at kører ind i forhindringer.
//Det tidligere nævnte program er kun delvist lavet af mig, derfor er det ikke med i afleveringen.
//Systemet modtager en minimums distance som parametre, som den bruger til at tjekke distancerne til hver side af robotten.
void Avoidance(float minDistance){
  Serial.print("Avoiding - ");

  //Eftersom det er et blocking loop, bliver sensorværdieren ikke opdateret af det normale main loop, derfor tilføjes denne linje,
  //for at sikre at kun de mest nødvendige sensorværdier bliver brugt. Så robotten går i "fight or flight" mode, og benytter kun dens
  //mest bersale funktioner.
  SensorLoop();

  //Herefter hardcodes alle blokeringsmulighederne i en række if-else statements. Dette gøres for at sikre at rækkefølgen bliver overholdt,
  //så den ikke begynder at reagere på en blokeringsmulighede fra øst (Og dermed går vest), hvis den både bliver blokeret fra øst og vest.
  //Derfor er de placeret så det mest relevante (4 retnings blokering) er først, derefter (3 retnings blokering), så (2 retningsblokering),
  //og til sidst (1 regningsblokering).
  //distance_N, distance_S, distance_E, og distance_W er forkortelser for den nuværende distance der er fra sensoren. _N = Nord, _S = Syd, _E = Øst, _W = Vest.
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

  //Hvis så det viser sig at robotten ikke længere er i faresone, bliver loopet stoppet igen, og robotten går tilbage til normal
  if (distance_N >= minDistance && distance_E >= minDistance && distance_S >= minDistance && distance_W >= minDistance){
    ChangeDirection(Stop);
    avoiding = false;
    return;
  }

  //Derfor er denne linje sat til sidst, så loopet kan stoppes inden det gentager sig selv.
  Avoidance(minDistance);
}
