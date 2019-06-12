/*******************************************************************************
Project   Train TimeTable

  This is an OpenSource Project.
  You can use, share or improve this project. If you improve this source code
  please share with the comunity or at least with the author of the original 
  source code
  
  Created 09. May 2019 by MarkusNTrains
================================================================================
$HeadURL:  $
$Id:  $
*******************************************************************************/



//!!!!!! change in Adafruit_ST7735.h #define ST7735_TFTHEIGHT to 161 !!!!!!!!!!!!!!!!!!!!



//-----------------------------------------------------------------------------
// includes
#include "TimetableDisplay.h"


//----------------------------------------------------------------------------
// pin definition for the Uno / Nano
#define TFT_CS_PIN   10
#define TFT_DC_PIN   9
#define TFT_RST_PIN  8
#define TFT_SCL_PIN  13
#define TFT_MOSI_PIN 11


//----------------------------------------------------------------------------
// enum



//----------------------------------------------------------------------------
// create an instance of the library
//TFT TFTscreen = TFT(TFT_CS_PIN, TFT_DC_PIN, TFT_RST_PIN);
TimetableDisplay* s_time_table;

// char array to print to the screen
//char sensorPrintout[4];


//*****************************************************************************
// description:
//   show one line on time table
//*****************************************************************************
/*void show_train(const char* text, int16_t row)
{
  uint16_t red = TFTscreen.newColor(255, 0, 0);
  uint8_t x = 3;
  uint8_t y = (row * 10) + 27;

  if (row != 0)
  {
    if (row == 2)
    {
      TFTscreen.fillRect(x-1, y-1, 18, 9, 0x0600);  // Background Zug art      
    }
    else
    {
      TFTscreen.fillRect(x-1, y-1, 18, 9, red);  // Background Zug art
    }
  }
  
  TFTscreen.text(text, x, y);

  if (row < 7)
  {
    TFTscreen.drawLine(2, y + 8, 159, y + 8, 0xFFFF);  
  }
}*/


//*****************************************************************************
// description:
//   start up befor inifinity loop
//*****************************************************************************
void setup() 
{
  s_time_table = new TimetableDisplay(TFT_CS_PIN, TFT_DC_PIN, TFT_RST_PIN);
  
  /*show_train("    Zeit   Nach      Gleis", 0);
  show_train("S2  13:48  Domat/Ems    13", 1);
  show_train("ICE 13:57  Glarus       11", 2);
  show_train("EC  14:04  Schwanden    54", 3);
  show_train("RE  14:19  Luchsingen   21", 4);
  show_train("S41 14:21  Linthal       7", 5);
  show_train("S8  14:32  Chur          8", 6);
  //show_train("R   14:41  Zurich        1", 7);
  char a[10];
  sprintf(a, "%d  %d", TFTscreen.width(), TFTscreen.height());
  show_train(a, 7);*/
  s_time_table->SetLine(TimetableDisplay::S2,  "13:48", "Glarus",     13, 1);
  s_time_table->SetLine(TimetableDisplay::ICE, "13:57", "Frankfurt",  11, 2);
  s_time_table->SetLine(TimetableDisplay::EC,  "14:04", "Paris",      54, 3);
  s_time_table->SetLine(TimetableDisplay::RE,  "14:19", "Chur",       21, 4);
  s_time_table->SetLine(TimetableDisplay::S10, "14:21", "Linthal",    7,  5);
  s_time_table->SetLine(TimetableDisplay::S8,  "14:32", "Rapperswil", 8,  6);
  s_time_table->SetLine(TimetableDisplay::R,   "14:41", "Bilten",     1,  7);

  delay(1000);
}


//*****************************************************************************
// description:
//   infinity loop
//*****************************************************************************
void loop() 
{
  // update display with new time table information
  delay(1000);
}
