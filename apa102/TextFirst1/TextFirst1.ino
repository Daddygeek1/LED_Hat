#include <FastLED.h>

#include <LEDMatrix.h>
#include <LEDText.h>
#include <FontMatrise.h>
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

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;

cLEDText ScrollingMsg;

const unsigned char TxtDemo[] = { 
          EFFECT_FRAME_RATE "\x00\xff\xff\xff\xff"
          "       "
          EFFECT_SCROLL_DOWN EFFECT_HSV "\x80\xff\xff" "STEVE" EFFECT_DELAY_FRAMES "\x00\x80"
          "               "                                 
          EFFECT_SCROLL_LEFT EFFECT_HSV "\x00\xff\xff" " A robot may not injure a human being or through inaction allow a human being to come to harm "
          "    "
          EFFECT_HSV_AV "\x00\xff\xff\x80\xff\xff" " Keep calm and let Steve handle it "
          "    "
          EFFECT_HSV_CH "\x00\xff\xff\x40\xff\xff" " First Robotics "
          "    "
          EFFECT_HSV "\x00\xff\xff" "-"                       
             EFFECT_HSV "\x20\xff\xff" "S" 
             EFFECT_HSV "\x50\xff\xff" "T" 
             EFFECT_HSV "\x90\xff\xff" "E" 
             EFFECT_HSV "\x50\xff\xff" "V"
             EFFECT_HSV "\x20\xff\xff" "E" 
             EFFECT_DELAY_FRAMES "\x00\x80"
             EFFECT_HSV "\x00\xff\xff" "-"                                 
                                 
          "     "                        
          EFFECT_HSV "\xa0\xff\xff" " Get excited and build a " EFFECT_HSV_AH "\x00\xff\xff\xff\xff\xff " "robot " 
          "   "
          EFFECT_SCROLL_LEFT EFFECT_HSV "\x80\xff\xff" " A robot must obey the orders given it by human beings except where such orders would conflict with the First Law "
          "   "
          EFFECT_SCROLL_UP EFFECT_HSV_AH "\x00\xff\xff\xff\xff\xff" "STEVE" EFFECT_DELAY_FRAMES "\x00\x80"
          "      "
          EFFECT_SCROLL_LEFT EFFECT_RGB "\xcf\xff\xff"  " Wear your Safety Glasses "
          "     "
          EFFECT_HSV_AV "\x00\xff\xff\x80\xff\xff" " Gracious Professionalism "
          "     "
          EFFECT_HSV "\x60\xff\xff" " NEVER" EFFECT_DELAY_FRAMES "\x00\x50" EFFECT_HSV "\x00\xff\xff" " NEVER" EFFECT_DELAY_FRAMES "\x00\x50" EFFECT_HSV "\x40\xff\xff" " NEVER" EFFECT_DELAY_FRAMES "\x00\x50" EFFECT_HSV_CV "\x00\xff\xff\x40\xff\xff" " GIVE UP"
          "     "
          EFFECT_SCROLL_LEFT EFFECT_HSV "\x40\xff\xff" " A robot must protect its own existence as long as such protection does not conflict with the First or Second Laws "
          "   "
          EFFECT_HSV_AH "\x00\xff\xff\xff\xff\xff" " The hardest fun you’ll ever have "
          "     "
          EFFECT_HSV_CH "\x00\xff\xff\x80\xff\xff" " Never Fear STEVE is here "
          "     "
          EFFECT_HSV "\x00\xff\xff\x80\xff\xff" " NOT FOREHEAD PROTECTORS "
          "     "
          EFFECT_HSV_AH "\x00\xff\xff\xff\xff\xff" " FIRST is More Than Robots              "


                                 // EFFECT_SCROLL_LEFT " a "
                                 // EFFECT_SCROLL_RIGHT " a "
                                 // EFFECT_SCROLL_DOWN             EFFECT_HSV "\x00\xff\xff" "  a  "    EFFECT_FRAME_RATE "\x08" " a   " EFFECT_FRAME_RATE "\x00" " "
                                 // EFFECT_SCROLL_UP               EFFECT_HSV "\x60\xff\xff" "  a  "    EFFECT_FRAME_RATE "\x08" "  a  " EFFECT_FRAME_RATE "\x00" " "
                                 // EFFECT_CHAR_UP   " a  "
                                 // EFFECT_CHAR_RIGHT " a "
                                 // EFFECT_CHAR_DOWN " a "
                                 // EFFECT_CHAR_LEFT " a "
                                 // EFFECT_HSV_CV "\x00\xff\xff\x40\xff\xff"   a "          Never fear STEVE is here"
                                 // EFFECT_HSV_CH "\x00\xff\xff\x40\xff\xff" "    Never fear STEVE is here"
                                 // EFFECT_HSV_AV "\x00\xff\xff\x80\xff\xff" "    Never fear STEVE is here"
                                 // EFFECT_HSV_AH "\x00\xff\xff\xff\xff\xff" "    Never fear STEVE is here"
                                 // "                 " 
                                 // EFFECT_HSV "\x00\xff\xff" " a "                       
                                 // EFFECT_HSV "\x20\xff\xff" " a " 
                                 // EFFECT_HSV "\x40\xff\xff" " a " 
                                 // EFFECT_HSV "\x60\xff\xff" " a " 
                                 // EFFECT_HSV "\x40\xff\xff" " a "
                                 // EFFECT_HSV "\x20\xff\xff" " a " 
                                 // EFFECT_DELAY_FRAMES "\x00\x80"
                                 // EFFECT_HSV "\x00\xff\xff" " a "                                 
                                 // EFFECT_RGB "\xff\xff\xff" 
                                 };

void setup()
{
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds[0], leds.Size());
  FastLED.setBrightness(5);
  FastLED.clear(true);
  delay(500);
  FastLED.showColor(CRGB::Red);   // x
  delay(1000);
  FastLED.showColor(CRGB::Lime);   // x
  delay(1000);
  FastLED.showColor(CRGB::Blue);    // x
  delay(1000);
  FastLED.showColor(CRGB::White);    // x
  delay(1000);
  FastLED.show();

  ScrollingMsg.SetFont(MatriseFontData);
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
