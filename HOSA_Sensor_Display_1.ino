 #include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()
{
  lcd.begin(16,2);
  lcd.clear();
}

void loop() {
  unsigned int analogValue;
  


  analogValue = analogRead(A0);
  String displayVal = String(16);

   String S_Danger = String(16);
    String S_Precaution = String(16);
     String S_Normal = String(16);
     String S_EmergencyCare = String(16);
     String S_PrecautionCare = String(16);
 S_Normal = "Normal: "; 
 S_Precaution = "Precaution: ";
 S_Danger = "Danger: ";
 S_EmergencyCare = "Dialing 911...";
 S_PrecautionCare = "Consult Doctor";

  if ( analogValue < 35){
    displayVal = S_Normal +analogValue ;//+ " " + "Normal";
  }else if (analogValue < 240 ){
    displayVal = S_Precaution + analogValue;// + " " + "Precaution";
  }else {
    displayVal = S_Danger +analogValue ;// + " " + "Danger";
  }
  lcd.print(displayVal);
  if ( analogValue >= 240 ) {
    lcd.setCursor(1 , 2);
    lcd.print(S_EmergencyCare);
  }
  if (( analogValue >= 35 ) && (analogValue <= 240)) {
    lcd.setCursor(1 , 2);
    lcd.print(S_PrecautionCare);
  }
  delay (1000);
  lcd.clear();
  
}
