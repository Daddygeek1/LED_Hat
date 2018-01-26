#include <FastLED.h>

#include <LEDMatrix.h>
#include <LEDText.h>
#include <FontRobotron.h>

// Change the next 6 defines to match your matrix type and size

#define DATA_PIN 11
//#define CLOCK_PIN 12
#define LED_PIN        11
#define COLOR_ORDER    GRB
#define CHIPSET        APA102
#define CLOCK_PIN       12
//#define CLK_PIN         12

#define MATRIX_WIDTH   32
#define MATRIX_HEIGHT  -8
#define MATRIX_TYPE    -VERTICAL_ZIGZAG_MATRIX
//#define LED_PIN        2
//#define COLOR_ORDER    GRB
//#define CHIPSET        WS2812B

//#define MATRIX_WIDTH   68
//#define MATRIX_HEIGHT  7
//#define MATRIX_TYPE    HORIZONTAL_ZIGZAG_MATRIX

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;

cLEDText ScrollingMsg;

const unsigned char TxtDemo[] = { EFFECT_SCROLL_LEFT "         LEFT SCROLL"
                                  EFFECT_SCROLL_RIGHT "         LLORCS THGIR"
                                  EFFECT_SCROLL_DOWN "         SCR-DOWN          SCR-DOWN         " EFFECT_FRAME_RATE "\x04" " SCR-DOWN         " EFFECT_FRAME_RATE "\x00" " "
                                  EFFECT_SCROLL_UP "         SCROL-UP          SCROL-UP         " EFFECT_FRAME_RATE "\x04" " SCROL-UP         " EFFECT_FRAME_RATE "\x00" " "
                                  EFFECT_CHAR_UP EFFECT_SCROLL_LEFT "         UP"
                                  EFFECT_CHAR_RIGHT "  RIGHT"
                                  EFFECT_CHAR_DOWN "  DOWN"
                                  EFFECT_CHAR_LEFT "  LEFT"
                                  EFFECT_HSV_CV "\x00\xff\xff\x40\xff\xff" EFFECT_CHAR_UP "   HSV_CV 00-40"
                                  EFFECT_HSV_CH "\x00\xff\xff\x40\xff\xff" "   HSV_CH 00-40"
                                  EFFECT_HSV_AV "\x00\xff\xff\x40\xff\xff" "   HSV_AV 00-40"
                                  EFFECT_HSV_AH "\x00\xff\xff\xff\xff\xff" "   HSV_AH 00-FF"
                                  "         " EFFECT_HSV "\x00\xff\xff" "R" EFFECT_HSV "\x20\xff\xff" "A" EFFECT_HSV "\x40\xff\xff" "I" EFFECT_HSV "\x60\xff\xff" "N" EFFECT_HSV "\xe0\xff\xff" "B" EFFECT_HSV "\xc0\xff\xff" "O"
                                  EFFECT_HSV "\xa0\xff\xff" "W" EFFECT_HSV "\x80\xff\xff" "S" EFFECT_DELAY_FRAMES "\x00\x96" EFFECT_RGB "\xff\xff\xff" };

void setup()
{
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds[0], leds.Size());
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

  ScrollingMsg.SetFont(RobotronFontData);
  ScrollingMsg.Init(&leds, leds.Width(), ScrollingMsg.FontHeight() + 1, 0, 0);
  ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);
  ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0xff, 0x00, 0xff);
}


void loop()
{
  if (ScrollingMsg.UpdateText() == -1)
    ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);
  else
    FastLED.show();
  delay(10);
}
