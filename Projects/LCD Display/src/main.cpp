#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Comment
// GND => GND
// VCC => 5V
// SDA => A4
// SCL => A5

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

#define MESSAGE "A generic message"

void setup()
{
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(MESSAGE);
}
void loop()
{
  lcd.setCursor(16, 1);
  lcd.autoscroll(); // Set diplay to scroll automatically
  lcd.print(" ");   // set characters
  delay(500);
}
