/*
blink
*/
// include the library code:
#include <LiquidCrystal_I2C.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
// set up the LCD's number of columns and rows and:
//lcd.begin(0, 1);
lcd.init();
lcd.backlight();
lcd.clear();
// Print a message to the LCD.
lcd.print("hello, world!");
}
void loop()
{
lcd.setCursor(0, 1);
lcd.print("cursor blink");
lcd.blink();
delay(2000);
lcd.noBlink();
lcd.print(" noBlink");
delay(2000);
lcd.clear();
lcd.print("Display off ...");
delay(1000);
lcd.noDisplay();
delay(2000);
lcd.display(); // turn the display back on
lcd.setCursor(0, 0);
lcd.print(" display flash !");
displayBlink(2, 250); // blink twice
displayBlink(2, 500); // and again for twice as long
lcd.clear();
}
void displayBlink(int blinks, int duration)
{
while(blinks--)
{
lcd.noDisplay();
delay(duration);
lcd.display();
delay(duration);
}
}
