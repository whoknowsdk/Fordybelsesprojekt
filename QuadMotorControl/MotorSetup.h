//Dette script er til for at rydde op i main scriptet, for at sikre at det ikke bare bliver et langt script.
//Derfor tilføjes der funktioner som "FunktionNavn + Setup" eller "FunktionsNavn + Loop", som derefter kan aktiveres
//i main setup'et eller main loop'et. Derfor er det også vigtigt at der ikke tilføjes delays i nogen af scriptsene,
//eftesom dert ville sænke hele programmet.
void MotorSetup(){
  pinMode(TLEN, OUTPUT);
  pinMode(BLEN, OUTPUT);

  pinMode(TREN, OUTPUT);
  pinMode(BREN, OUTPUT);
  
  pinMode(TLM_1, OUTPUT);
  pinMode(TLM_2, OUTPUT);
  pinMode(TRM_1, OUTPUT);
  pinMode(TRM_2, OUTPUT);
  
  pinMode(BLM_1, OUTPUT);
  pinMode(BLM_2, OUTPUT);
  pinMode(BRM_1, OUTPUT);
  pinMode(BRM_2, OUTPUT);
}
