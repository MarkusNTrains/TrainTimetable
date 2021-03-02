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
// create an instance of the library
TimetableDisplay* s_time_table;



//*****************************************************************************
// description:
//   start up befor inifinity loop
//*****************************************************************************
void setup() 
{
  s_time_table = new TimetableDisplay(TFT_CS_PIN, TFT_DC_PIN, TFT_RST_PIN);
  
  /*s_time_table->SetLine(TimetableDisplay::S2,  "13:48", "Glarus",     13, 1);
  s_time_table->SetLine(TimetableDisplay::ICE, "13:57", "Frankfurt",  11, 2);
  s_time_table->SetLine(TimetableDisplay::EC,  "14:04", "Paris",      54, 3);
  s_time_table->SetLine(TimetableDisplay::RE,  "14:19", "Chur",       21, 4);
  s_time_table->SetLine(TimetableDisplay::S10, "14:21", "Linthal",    7,  5);
  s_time_table->SetLine(TimetableDisplay::S8,  "14:32", "Rapperswil", 8,  6);
  s_time_table->SetLine(TimetableDisplay::R,   "14:41", "Bilten",     1,  7);

  delay(1000);*/
}


//*****************************************************************************
// description:
//   infinity loop
//*****************************************************************************
void loop() 
{
  // update display with new time table information
  s_time_table->Clear();
  s_time_table->SetLine(TimetableDisplay::S2,  "13:48", "Glarus",     13, 1);
  s_time_table->SetLine(TimetableDisplay::ICE, "13:57", "Frankfurt",  11, 2);
  s_time_table->SetLine(TimetableDisplay::EC,  "14:04", "Paris",      54, 3);
  s_time_table->SetLine(TimetableDisplay::RE,  "14:19", "Chur",       21, 4);
  s_time_table->SetLine(TimetableDisplay::S10, "14:21", "Linthal",    7,  5);
  s_time_table->SetLine(TimetableDisplay::S8,  "14:32", "Rapperswil", 8,  6);
  s_time_table->SetLine(TimetableDisplay::R,   "14:41", "Bilten",     1,  7);
  delay(2000);

  s_time_table->Clear();
  s_time_table->SetLine(TimetableDisplay::S2,  "13:48", "London",     13, 1);
  s_time_table->SetLine(TimetableDisplay::ICE, "13:57", "Mannheim",   11, 2);
  s_time_table->SetLine(TimetableDisplay::EC,  "14:04", "Rastatt",    54, 3);
  s_time_table->SetLine(TimetableDisplay::RE,  "14:19", "Hamburg",    21, 4);
  s_time_table->SetLine(TimetableDisplay::S10, "14:21", "Rust",       7,  5);
  s_time_table->SetLine(TimetableDisplay::S8,  "14:32", "Rom",        8,  6);
  s_time_table->SetLine(TimetableDisplay::R,   "14:41", "Prag",       1,  7);
  delay(2000);
}
