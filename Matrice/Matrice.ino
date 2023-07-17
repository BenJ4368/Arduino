#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
  #define PSTR
#endif

#define PIN 4

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
  NEO_MATRIX_BOTTOM     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);
int x = matrix.width();
int y = 0;

const char *textToPrint = "Info: Reunion studs mercredi 14h14 en cantina          Minecraft: Choix du modpack via sondage sur Discord          Je sais pas quoi ecrire d'autre mdr";
const int scrollSpeed = 50;
int textWidth;

const unsigned long executionDuration = 6 * 60 *60000; // 8hours
const unsigned long pauseDuration = 18 * 60 * 60000; // 16 hours
unsigned long startTime;
unsigned long currentTime;

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(100);
  matrix.setTextColor(matrix.Color(75, 190, 255));
  startTime = millis();
}

void loop() {
    currentTime = millis();

    if (currentTime - startTime <= executionDuration) {
      if (x >= -textWidth) {
        matrix.fillScreen(0);
        matrix.setCursor(x, y);
        matrix.print(textToPrint);
        if (textWidth == 0)
          textWidth = matrix.getCursorX();
        x--;
        matrix.show();
        delay(scrollSpeed);
      }
      else
        x = matrix.width();
    }
    else {
      matrix.fillScreen(0);
      matrix.show();
      delay(pauseDuration);
      startTime = millis();
    }
}
