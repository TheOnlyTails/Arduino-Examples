/* Basic example code for MAX7219 LED dot matrix display with Arduino. More info: https://www.makerguides.com */

// Include the required Arduino libraries:
#include <Arduino.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define hardware type, size, and output pins:
#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
#define MAX_DEVICES 1
#define CS_PIN 3

// Create a new instance of the MD_Parola class with hardware SPI connection:
// MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// Setup for software SPI:
#define DATA_PIN 11
#define CLK_PIN 13
MD_Parola display = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

// The message that should be printed:
#define MESSAGE "MESSAGE"

void setup()
{
  // Intialize the object:
  display.begin();
  // Set the intensity (brightness) of the display (0-15):
  display.setIntensity(0);
  // Clear the display:
  display.displayClear();

  display.displayText(MESSAGE, PA_CENTER, 125, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}

void loop()
{
  if (display.displayAnimate())
  {
    display.displayReset();
  }
}