#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[COLS][ROWS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {6,7,8,9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2,3,4,5}; //connect to the column pinouts of the keypad
String customKey("");
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), colPins, rowPins, COLS, ROWS); 

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Enter password: ");
}
  
void loop(){
  char k = customKeypad.getKey();
  
  
  if(k){
    if(k == '#'){
      lcd.clear();
      customKey = ""; 
      lcd.setCursor(1, 0);
      lcd.print("Enter password: ");
      }
  else{ 
      customKey = customKey + String(k);   
      if(k == '*') 
      {
        customKey.remove(customKey.length()-2);
        customKey = " " + customKey; 
      }

      lcd.setCursor(16-customKey.length(),1);
      lcd.print(customKey);
      if (k == 'D')
      {
        customKey.remove(customKey.length()-1);
        lcd.clear();
        lcd.setCursor(1,0);
        if (customKey == String("1234")) lcd.print("$10000 is yours!!");
        else lcd.print("Wrong Password");
        customKey = "";
      }
    }
  } 
}
