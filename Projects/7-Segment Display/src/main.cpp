#include <Arduino.h>

// SSD = Seven-Segment Display
// Note - the schematics refer to 2 SSDs.
// For this project, only connect the right one, but exactly the same as in the picture (use the same pins). 

void setup()
{
  for (int i = 7; i <= 13; i++)
  {
    // Set all pins from 7 to 13 as OUTPUT
    pinMode(i, OUTPUT);
  }
}

// The line below is the array containing all the binary numbers for the digits on a SSD from 0 to 9
const int number[11] = {0b0111111,
                        0b0000110,
                        0b1011011,
                        0b1001111,
                        0b1100110,
                        0b1101101,
                        0b1111101,
                        0b0000111,
                        0b1111111,
                        0b1101111};

void loop()
{
  for (int digit = 0; digit <= 9; digit++)
  {
    display_digit(digit);
    delay(1000);
  }
}

void display_digit(const int digit)
{
  int pin, b;

  // Pin is used to deal with pins of the 7SD

  for (pin = 7, b = 0; pin <= 13; pin++, b++)
  {
    digitalWrite(pin, bitRead(number[digit], b));
  }
}
