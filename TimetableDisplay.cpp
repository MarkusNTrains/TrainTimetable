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


//-----------------------------------------------------------------------------
// includes
#include "TimetableDisplay.h"
#include <SPI.h>


//-----------------------------------------------------------------------------
// defines


//*****************************************************************************
// description:
//   constructor
//*****************************************************************************
TimetableDisplay::TimetableDisplay(uint8_t CS_PIN, uint8_t DC_PIN, uint8_t RST_PIN)
{
	m_screen = new TFT(CS_PIN, DC_PIN, RST_PIN);

	// Put this line at the beginning of every sketch that uses the GLCD:
	m_screen->begin();

	m_screen->setAddrWindow(2, 27, 20, 47);
	m_screen->invertDisplay(true);
	m_screen->setRotation(3);

	// clear the screen with a blue background
	m_screen->background(0, 0, 255);

	// write the static text to the screen
	// set the font color to white
	m_txt_color = m_screen->newColor(255, 255, 255);
	m_screen->stroke(m_txt_color);
	// set the font size
	m_screen->setTextSize(1);
	
	this->SetHeader();
}


//*****************************************************************************
// description:
//   destructor
//*****************************************************************************
TimetableDisplay::~TimetableDisplay()
{
	free(m_screen);
}


//*****************************************************************************
// description:
//   set default header
//*****************************************************************************
void TimetableDisplay::SetHeader()
{
    // draw header line
    m_screen->text("Zeit", X_POS_TIME, Y_POS_START);
    m_screen->text("Nach", X_POS_TARGET, Y_POS_START);
    m_screen->text("Gleis", X_POS_PLATFORM - ((3 * (CHAR_WIDTH + CHAR_SPACE_WIDTH)) + CHAR_WIDTH), Y_POS_START);    
}


//*****************************************************************************
// description:
//   show one line on time table
//*****************************************************************************
void TimetableDisplay::SetLine(train_type_t type, const char* time, const char* target, const char* platform, uint8_t line)
{
	char txt[5] = { 0 };
	uint16_t bg_color = 0x0000;
	uint8_t y = (line * LINE_HEIGHT) + Y_POS_START;

	
	if (line != 0)
	{
		// draw line 
		m_screen->drawLine(X_POS_START, y - 2, X_POS_START + (VIEWING_AREA_WIDTH - 1), y - 2, m_screen->newColor(0xE0, 0xE0, 0xE0));  
		
		// draw train type
		this->DrawTrainType(type, X_POS_TYPE, y);
		
		// draw time
		m_screen->text(time, X_POS_TIME, y);
		
		// draw target
		m_screen->text(target, X_POS_TARGET, y);
		
		// draw platform
		itoa(platform, txt, 10);
		if (platform >= 10)
		{
			m_screen->text(txt, X_POS_PLATFORM - (CHAR_WIDTH + CHAR_SPACE_WIDTH), y);
		}
		else
		{
			m_screen->text(txt, X_POS_PLATFORM, y);
		}
	}
}


//*****************************************************************************
// description:
//   set line
//*****************************************************************************
void TimetableDisplay::SetLine(const char* txt, uint8_t line)
{
    uint8_t y = (line * LINE_HEIGHT) + Y_POS_START;
    m_screen->text(txt, X_POS_START, y);
}


//*****************************************************************************
// description:
//   get text of train type
//*****************************************************************************
void TimetableDisplay::Clear(void)
{
    m_screen->fillScreen(m_screen->newColor(0, 0, 0xFF));
}


//*****************************************************************************
// description:
//   get text of train type
//*****************************************************************************
void TimetableDisplay::DrawTrainType(train_type_t type, uint8_t x, uint8_t y)
{
	uint16_t white = m_screen->newColor(255, 255, 255);
	uint16_t yellow = m_screen->newColor(255, 255, 0);
	uint16_t red = m_screen->newColor(255, 0, 0);
	uint16_t black = m_screen->newColor(0, 0, 0);
	
	char txt[5] = { 0 };
	uint16_t txt_color = 0;
	uint16_t bg_color = 0;
	
	switch (type)
	{
		case EC:
			strcpy(txt, "EC");
			txt_color = white;
			bg_color = red;
			break;
		case IC:
			strcpy(txt, "IC");
			txt_color = white;
			bg_color = red;
			break;
		case ICE:
			strcpy(txt, "ICE");
			txt_color = white;
			bg_color = red;
			break;
		case ICN:
			strcpy(txt, "ICN");
			txt_color = white;
			bg_color = red;
			break;
		case IR:
			strcpy(txt, "IR");
			txt_color = white;
			bg_color = red;
			break;		
		case R:
			strcpy(txt, "R");
			txt_color = black;
			bg_color = white;
			break;
		case RE:
			strcpy(txt, "RE");
			txt_color = red;
			bg_color = white;
			break;
		case S1:
			strcpy(txt, "S1");
			txt_color = black;
			bg_color = white;
			break;
		case S2:
			strcpy(txt, "S2");
			txt_color = black;
			bg_color = white;
			break;
		case S3:
			strcpy(txt, "S3");
			txt_color = black;
			bg_color = white;
			break;
		case S4:
			strcpy(txt, "S4");
			txt_color = black;
			bg_color = white;
			break;
		case S5:
			strcpy(txt, "S5");
			txt_color = black;
			bg_color = white;
			break;
		case S6:
			strcpy(txt, "S6");
			txt_color = black;
			bg_color = white;
			break;
		case S7:
			strcpy(txt, "S7");
			txt_color = black;
			bg_color = white;
			break;
		case S8:
			strcpy(txt, "S8");
			txt_color = black;
			bg_color = white;
			break;
		case S9:
			strcpy(txt, "S9");
			txt_color = black;
			bg_color = white;
			break;
		case S10:
			strcpy(txt, "S10");
			txt_color = black;
			bg_color = white;
			break;
			
		default:
			strcpy(txt, "???");
			txt_color = black;
			bg_color = yellow;
			break;
	}
	
	m_screen->stroke(txt_color);
	m_screen->fillRect(x-1, y-1, TYPE_BG_WIDTH, TYPE_BG_HEIGHT, bg_color);  // Background train type
	m_screen->text(txt, x, y);				// Text train type
		
	m_screen->stroke(m_txt_color);
}
