#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display
// Er det 4 fordi det er 4-line display? og med 20 char?

String VeryHappyMsg[] = {"(*´◡`*)",
  "q(>V<q)",
  "Hej Til Alle Mine Venner",
  "Jubii !!!",
  "Jeg Elsker Livet På Skolen",
  "Hejsa (*◡‿◡)",
  "Intet Kan Stoppe Mig!",
  "Jeg Er Uovervindelig!"};

String HappyMsg[] = {"Jeg Nyder At Udforske Skolen",
  "(^_^)",
  "Jeg Har Det Sjovt",
  "Hihi",
  "Mine Tandhjul Summer Af Glæde",
  "Skal Vi Til Fredagscafe",
  "Hvad Betyder Mucki Bar"};

String NeutralMsg[] = {"Hej Med Dig",
  "Vil Du Age Mig På Hovedet ?",
  "Jeg Keder Mig Lidt",
  "Hvad Er Dette Sted",
  "Hvad Er Meningen Med Livet?",
  "Hvornaar Er Der Mad",
  "Mit Navn Er Sennep … Hvad Er Dit ?"};

String SadMsg[] = {"Jeg Savner Min Far, Mikkel Blom",
  "Hvorfor Er Jeg Her",
  "...Bip",
  "(O_O;)",
  "Jeg Er Traet Af At Foele Mig Uforstaaet",
  "Doer Herovre LOL",
  "Det Her Sted Er Utrygt",
  "Definitionen Af Kedsomhed:",
  "Hhhhhhhhhhhhh"
};

String DepressedMsg[] = {"Jeg Hader Industrisamfundet.",
  "Jeg Foeler Mig Haabloes Og Ulykkelig.",
  "Jeg Kan Ikke Se En Positiv Fremtid.",
  "(X﹏X)",
  "(=╭╮=)",
  "Fodr Mig, Smaa Dyr",
  "...",
  "Kan Man Doe Af Det Her",
  "Frygt Mig, Menneske"
};

String RanMsg (String arr[], int arrL){
  int ran = random(0, arrL);
  return arr[ran];
  }

void MsgPicker(){
  String Msg = "";
  if (mood >85){Msg =  RanMsg(VeryHappyMsg, 8);}
  else if (mood  > 70) {Msg = RanMsg(HappyMsg, 7);}
  else if (mood  > 45) {Msg = RanMsg(NeutralMsg, 7);}
  else if (mood  > 15) {Msg = RanMsg(SadMsg, 9);}
  else if (mood  >= 0) {Msg = RanMsg(DepressedMsg, 9);}
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mood: " + String(mood) + " ");
  lcd.setCursor(0, 1);
  lcd.print(Msg);
  }

void ScreenSetup()
{
  lcd.init(); // initialize the lcd\
  // Print a message to the LCD.
  lcd.backlight();
}
