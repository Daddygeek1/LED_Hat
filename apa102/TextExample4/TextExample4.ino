// This example shows the use of INSTANT_OPTIONS_MODE
// When set it stops the text routine from having to scroll all
// of the existing text off the display before changing the scroll
// direction.

#include <FastLED.h>

#include <LEDMatrix.h>
#include <LEDText.h>
#include <Font32x8.h>

// Change the next 6 defines to match your matrix type and size

#define DATA_PIN 11
#define CLOCK_PIN 12
#define LED_PIN        11
#define COLOR_ORDER    GRB
#define CHIPSET        APA102

#define MATRIX_WIDTH   32
#define MATRIX_HEIGHT  -8
#define MATRIX_TYPE    -VERTICAL_ZIGZAG_MATRIX

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;

cLEDText ScrollingMsg;

const unsigned char TxtDemo[] = { EFFECT_FRAME_RATE "\x3"
                                  EFFECT_HSV_AH "\x00\xff\xff\xff\xff\xff"
                                  EFFECT_SCROLL_LEFT "  Steve "
                                  EFFECT_SCROLL_UP "can "
                                  EFFECT_SCROLL_LEFT "handle "
                                  EFFECT_SCROLL_DOWN "that"
                                  EFFECT_SCROLL_LEFT "EEE "
                                  EFFECT_SCROLL_UP "FFF "
                                  EFFECT_SCROLL_LEFT "GGG "
                                  EFFECT_SCROLL_DOWN "HHH  "
                                  EFFECT_SCROLL_LEFT "III " };
uint16_t Options;

void setup()
{
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds[0], leds.Size());
  // FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
  FastLED.setBrightness(1);
  FastLED.clear(true);
  delay(500);
  FastLED.showColor(CRGB::Red);
  delay(1000);
  FastLED.showColor(CRGB::Lime);
  delay(1000);
  FastLED.showColor(CRGB::Blue);
  delay(1000);
  FastLED.showColor(CRGB::White);
  delay(1000);
  FastLED.show();

  ScrollingMsg.SetFont(Font32x8Data);
  ScrollingMsg.Init(&leds, leds.Width(), ScrollingMsg.FontHeight() + 1, 0, 0);
  ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);
  ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0xff, 0x00, 0xff);
  Options = INSTANT_OPTIONS_MODE;
  ScrollingMsg.SetOptionsChangeMode(Options);
}


void loop()
{
  if (ScrollingMsg.UpdateText() == -1)
  {
    ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);
    Options ^= INSTANT_OPTIONS_MODE;
    ScrollingMsg.SetOptionsChangeMode(Options);
  }
  else
    FastLED.show();
  delay(10);
}

