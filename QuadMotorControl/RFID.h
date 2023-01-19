#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 53
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

String activeCards[10] = {"33 26 17 0B", "99 5F 7E C2"};

int currentMode = 0; //0 == Read mode, 1 == Add mode, 2 == Delete mode
String lastAddedCard;
String lastRemovedCard;


void RFIDSetup() 
{

  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Read Mode Activated...");
  Serial.println("Waiting for Card");
  Serial.println();
}
void RFIDLoop() 
{

  if (currentMode != 0){
    currentMode = 0;
    Serial.println("Read Mode Activated...");
    Serial.println("Waiting for Card");
    Serial.println();
  }
  
  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.remove(0,1);
  content.toUpperCase();

  Serial.print("UID: ");
  Serial.println(content);
  
  if (currentMode == 0){
    Serial.print("Message : ");
    bool cardAllowed = false;
    for (int i = 0; i < sizeof(activeCards) / sizeof(String); i++){
      if (content == activeCards[i]) //change here the UID of the card/cards that you want to give access
      {
        cardAllowed = true;
        Serial.println("Authorized access");
        Serial.println();
      }
    }

    if (!cardAllowed){
      Serial.println("Access Denied");
      Serial.println();
    }
    
    delay(3000);
  }

}

