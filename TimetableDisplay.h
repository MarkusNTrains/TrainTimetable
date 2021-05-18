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


#ifndef _TIMETABLE_DISPLAY_H
#define _TIMETABLE_DISPLAY_H


//----------------------------------------------------------------------------
// include
#include "Arduino.h"
#include <TFT.h>  // Arduino LCD library


//----------------------------------------------------------------------------
// enum




//----------------------------------------------------------------------------
// class
class TimetableDisplay
{
	public:
		typedef enum 
		{
			EC = 0,
			IC,
			ICE,
			ICN,
			IR,
			R,
			RE,
			S1,
			S2,
			S3,
			S4,
			S5,
			S6,
			S7,
			S8,
			S9,
			S10,
			S11,
		} train_type_t;

		TimetableDisplay(uint8_t CS_PIN, uint8_t DC_PIN, uint8_t RST_PIN);
		~TimetableDisplay();
        void Clear(void);
        void SetHeader();
        void SetLine(train_type_t type, const char* time, const char* target, const char* platform, uint8_t line);
        void SetLine(const char* txt, uint8_t line);
		
	private:
		const uint8_t VIEWING_AREA_WIDTH = 160;
		const uint8_t VIEWING_AREA_HEIGHT = 80;
		const uint8_t CHAR_WIDTH = 5;
		const uint8_t CHAR_SPACE_WIDTH = 1;
		
		const uint8_t X_POS_START =		 1;
		const uint8_t X_POS_TYPE = 	   	 3;
		const uint8_t X_POS_TIME =	  	27;
		const uint8_t X_POS_TARGET =  	65;
		const uint8_t X_POS_PLATFORM = 154;
		const uint8_t Y_POS_START =     27;
		const uint8_t LINE_HEIGHT = 10;
		const uint8_t TYPE_BG_WIDTH = (3 * (CHAR_WIDTH + CHAR_SPACE_WIDTH)) + 2;
		const uint8_t TYPE_BG_HEIGHT = 9;

		
		TFT* m_screen;
		uint16_t m_txt_color;

		void DrawTrainType(train_type_t type, uint8_t x, uint8_t y);
};

#endif
