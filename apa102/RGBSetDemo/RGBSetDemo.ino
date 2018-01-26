#include<FastLED.h>

// How many leds are in the strip?
#define NUM_LEDS 257

// Data pin that led data will be written out over
#define DATA_PIN 11

// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define CLOCK_PIN 12

CRGBArray<NUM_LEDS> leds;

void setup() { FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS); }

void loop(){ 
  static uint8_t hue;
  for(int i = 0; i < NUM_LEDS/2; i++) {   
    // fade everything out
    leds.fadeToBlackBy(40);

    // let's set an led value
    leds[i] = CHSV(hue++,255,255);

    // now, let's first 20 leds to the top 20 leds, 
    leds(NUM_LEDS/2,NUM_LEDS-1) = leds(NUM_LEDS/2 - 1 ,0);
    FastLED.delay(1);
  }
}

