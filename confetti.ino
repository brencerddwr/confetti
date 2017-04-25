#include "FastLED.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Confetti
//
//////////////////////////////////////////////////

#define NUM_LEDS 24

// Data pin that led data will be written out over
#define DATA_PIN 6
// Clock pin only needed for SPI based chipsets when not using hardware SPI
//#define CLOCK_PIN 8

CRGB leds[NUM_LEDS];

void setup() {
	// sanity check delay - allows reprogramming if accidentally blowing power w/leds
	delay(2000);


	FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
	
	// set master brightness to enable FastLED dithering
	FastLED.setBrightness(96);

}

void loop() {
	fadeToBlackBy( leds, NUM_LEDS, 33);
	int x = random16(NUM_LEDS);
	if (!leds[x])
	{
		leds[ x ] += CHSV( random8(), 255, 255);
	}
	FastLED.show();
	FastLED.delay(60);
	

}

