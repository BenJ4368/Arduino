#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
#define PSTR
#endif

#define PIN 4

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
											   NEO_MATRIX_BOTTOM + NEO_MATRIX_RIGHT +
												   NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
											   NEO_GRB + NEO_KHZ800);
int x = matrix.width();
int y = 0;

// Texte à afficher. Eviter les accents, séparer les phrases par 3 tabs
const char *textToPrint = "Texte";
const int scrollSpeed = 30;	// Vitesse d'actualisation du texte (plus petit = défile plus vite)
int textWidth;

const unsigned long executionDuration = 6 * 60 * 60000; // Affiche pendant 6h
const unsigned long pauseDuration = 500; // puis fait une pause de 500ms
unsigned long startTime;
unsigned long currentTime;

void setup()
{
	matrix.begin();
	matrix.setTextWrap(false);
	matrix.setBrightness(100);
	matrix.setTextColor(matrix.Color(204, 0, 204)); // Couleur du texte (prefer. contraste élever)
	startTime = millis();
}

void loop()
{
	currentTime = millis();

	if (currentTime - startTime <= executionDuration)
	{
		if (x >= -textWidth)
		{
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
	else
	{
		matrix.fillScreen(0);
		matrix.show();
		delay(pauseDuration);
		startTime = millis();
	}
}
