#include "cprocessing.h"
#include "quiz.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include <mainmenu.h>
#include "utils.h"
#include <stdbool.h>
#include<level.h>

char TrueFalse_x1[4] = { 1 };
char TrueFalse_y1[10] = { 2 };
char TrueFalseans1[10] = { 3 };

char TrueFalse_x2[4] = { 1 };
char TrueFalse_y2[10] = { 2 };
char TrueFalseans2[10] = { 3 };


char TrueFalse_x3[4] = { 1 };
char TrueFalse_y3[10] = { 2 };
char TrueFalseans3[10] = { 3 };


char TrueFalse_x4[4] = { 1 };
char TrueFalse_y4[10] = { 2 };
char TrueFalseans4[10] = { 3 };


char TrueFalse_x5[4] = { 1 };
char TrueFalse_y5[10] = { 2 };
char TrueFalseans5[10] = { 3 };



void Quiz_Init()
{
	 int quiz_score = 0;
	 
	//Setting up the window size
	CP_Settings_TextSize(70);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	int random_x1 = CP_Random_RangeInt(0, 10);
	sprintf_s(TrueFalse_x1, _countof(TrueFalse_x1), "%d", random_x1);
	int random_y1 = CP_Random_RangeInt(0, 10);
	sprintf_s(TrueFalse_y1, _countof(TrueFalse_y1), "%d", random_y1);
	sprintf_s(TrueFalseans1, _countof(TrueFalseans1), "%d", random_y1 + random_x1);

	int random_x2 = CP_Random_RangeInt(0, 10);
	sprintf_s(TrueFalse_x2, _countof(TrueFalse_x2), "%d", random_x2);
	int random_y2 = CP_Random_RangeInt(0, 10);
	sprintf_s(TrueFalse_y2, _countof(TrueFalse_y2), "%d", random_y2);
	sprintf_s(TrueFalseans2, _countof(TrueFalseans2), "%d",  random_y2*random_x2 + 3);

	int random_x3 = CP_Random_RangeInt(0, 5);
	sprintf_s(TrueFalse_x3, _countof(TrueFalse_x3), "%d", random_x3);
	int random_y3 = CP_Random_RangeInt(0, 5);
	sprintf_s(TrueFalse_y3, _countof(TrueFalse_y3), "%d", random_y3);
	sprintf_s(TrueFalseans3, _countof(TrueFalseans3), "%d", random_y3 * random_x3 + 2);

	int random_x4 = CP_Random_RangeInt(0, 5);
	sprintf_s(TrueFalse_x4, _countof(TrueFalse_x4), "%d", random_x4);
	int random_y4 = CP_Random_RangeInt(0, 5);
	sprintf_s(TrueFalse_y4, _countof(TrueFalse_y4), "%d", random_y4);
	sprintf_s(TrueFalseans4, _countof(TrueFalseans4), "%d", random_y4 * random_x4 + 3);

	int random_x5 = CP_Random_RangeInt(0, 5);
	sprintf_s(TrueFalse_x5, _countof(TrueFalse_x5), "%d", random_x5);
	int random_y5 = CP_Random_RangeInt(0, 5);
	sprintf_s(TrueFalse_y5, _countof(TrueFalse_y5), "%d", random_y5);
	sprintf_s(TrueFalseans5, _countof(TrueFalseans5), "%d", random_y5 * random_x5 + 3);
	
}
	bool timesuppage = false;
	bool timercounter = true;
	
	bool clicked_q1	   = false;
	bool question_1ans = false;
	bool question_1	   = true;

	bool question_2	   = false;
	bool clicked_q2    = false;
	bool question_2ans = false;

	bool question_3	   = false;
	bool clicked_q3    = false;
	bool question_3ans = false;

	bool question_4    = false;
	bool clicked_q4    = false;
	bool question_4ans = false;

	bool question_5    = false;
	bool clicked_q5    = false;
	bool question_5ans = false;

void Quiz_Update()
{
	int questionnum = 1;
	float height = (float)CP_System_GetWindowHeight();
	float width =  (float)CP_System_GetWindowWidth();

	//Setting the background colour
	CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));

	if (timercounter == true)
	{
		CP_Font_DrawText("Timer:", width / 15, height / 5.5);
		CP_Font_DrawText(" :    ", width / 5.6, height / 5.5);
		float currentElapsedTime = CP_System_GetDt();
		static float totalElapsedTime = 300;
		totalElapsedTime -= currentElapsedTime;
		char minute[16] = { 0 };
		char second[16] = { 0 };
		sprintf_s(minute, _countof(minute), "%d",(int) totalElapsedTime/60);
		sprintf_s(second, _countof(second), "%.d", ((int)totalElapsedTime%60));
		CP_Font_DrawText(minute, width/8, height/5.5 );
		CP_Font_DrawText(second, width/4.8, height / 5.5);

		if (totalElapsedTime <= 0)
		{
			timercounter = false;
			timesuppage = true;

			clicked_q1    = false;
			question_1ans = false;
			question_1    = false;

			question_2    = false;
			clicked_q2    = false;
			question_2ans = false;

			question_3    = false;
			clicked_q3    = false;
			question_3ans = false;

			question_4    = false;
			clicked_q4    = false;
			question_4ans = false;

			question_5    = false;
			clicked_q5    = false;
			question_5ans = false;
		}
	}
		if (timesuppage == true) 
		{
			CP_Settings_TextSize(70);
			CP_Font_DrawText("Times up ", width / 2, height / 2);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.3, 500, 100, 0, 5); // false button
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.3);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.2f, height / 1.3f, 500.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);

					}
				}
			}
		
	if (question_1 == TRUE)
	{
		CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
		CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));

		//Drawing and setting the start rectangle position
		CP_Font_DrawText("If x =      and y =  ", width / 2, height / 2);
		CP_Font_DrawText(TrueFalse_x1, width / 2.15, height / 2);
		CP_Font_DrawText(TrueFalse_y1, width / 1.65, height / 2);
		CP_Font_DrawText(" Does x and y equals to       ?", width / 2, height / 1.6);
		CP_Font_DrawText(TrueFalseans1, width / 1.55, height / 1.6);

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
		CP_Graphics_DrawRectAdvanced(width / 1.7, height / 1.4, 200, 100, 0, 5); // false button
		CP_Graphics_DrawRectAdvanced(width / 2.4, height / 1.4, 200, 100, 0, 5); // true button

		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
		CP_Font_DrawText(" True ", width / 2.4, height / 1.4);
		CP_Font_DrawText(" False ", width / 1.7, height / 1.4);
		
		//If mouse click is within a certain area
		if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)&&(clicked_q1 == FALSE) && (question_1ans == FALSE))
		{
			if (IsAreaClicked(width / 2.4f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				clicked_q1 = TRUE;
			}
			else if (IsAreaClicked(width / 1.7f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				 question_1ans = TRUE;
			}
		

		}
			if ((clicked_q1 == TRUE))
			{
				CP_Font_DrawText(" Correct ", width / 2, height / 1.8);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.3, height / 1.3, 200, 100, 0, 5); 
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 1.3, height / 1.3);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width /1.3f, height / 1.3f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						
						question_1 = FALSE;
						question_2 = TRUE;
					}
				}
			} if((question_1ans == TRUE)&&(clicked_q1 == FALSE))
			{
				CP_Font_DrawText(" Wrong ", width / 2, height / 1.8);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.3, height / 1.3, 200, 100, 0, 5); 
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 1.3, height / 1.3);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.3f, height / 1.3f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{

						question_1 = FALSE;
						question_2 = TRUE;
					}
				}
			}
	}

	if (question_2 == TRUE )
	{

		//Drawing and setting the start rectangle position
		CP_Font_DrawText("If x =      ", width / 2, height / 2);
		CP_Font_DrawText(TrueFalse_x2, width / 1.9, height / 2);
		CP_Font_DrawText(" Does      x + 3 equals to       ?", width / 2, height / 1.6);
		CP_Font_DrawText(TrueFalse_y2, width / 2.4, height / 1.6);
		//CP_Font_DrawText(TrueFalse_x2, width / 2.15, height / 1.6);
		CP_Font_DrawText(TrueFalseans2, width / 1.55, height / 1.6);

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
		CP_Graphics_DrawRectAdvanced(width / 1.7, height / 1.4, 200, 100, 0, 5); // false button
		CP_Graphics_DrawRectAdvanced(width / 2.4, height / 1.4, 200, 100, 0, 5); // true button

		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
		CP_Font_DrawText(" True ", width / 2.4, height / 1.4);
		CP_Font_DrawText(" False ", width / 1.7, height / 1.4);

		//If mouse click is within a certain area
		if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT) && (clicked_q2 == FALSE) && (question_2ans == FALSE))
		{
			if (IsAreaClicked(width / 2.4f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				clicked_q2 = TRUE;
			}
			else if (IsAreaClicked(width / 1.7f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				question_2ans = TRUE;
			}
		}
		if (clicked_q2 == TRUE)
		{
			CP_Font_DrawText(" Correct ", width / 2, height / 1.8);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.3, height / 1.3, 200, 100, 0, 5); // false button
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Next ", width / 1.3, height / 1.3);
			//CP_Graphics_ClearBackground(CP_Color_Create(135, 206, 250, 255));
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.3f, height / 1.3f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					
					question_3 = TRUE;
					question_2 = FALSE;
				}
			}
		}
		if ((clicked_q2 == FALSE) && (question_2ans == TRUE))
		{
			CP_Font_DrawText(" Wrong ", width / 2, height / 1.8);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.3, height / 1.3, 200, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Next ", width / 1.3, height / 1.3);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.3f, height / 1.3f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{

					question_2 = FALSE;
					question_3 = TRUE;
				}
			}
		}
	}


	if (question_3 == TRUE)
	{

		CP_Font_DrawText("If x =      ", width / 2, height / 2);
		CP_Font_DrawText(TrueFalse_x3, width / 1.9, height / 2);
		CP_Font_DrawText(" Does      x + 3 equals to       ?", width / 2, height / 1.6);
		CP_Font_DrawText(TrueFalse_y3, width / 2.4, height / 1.6);
		CP_Font_DrawText(TrueFalseans3, width / 1.55, height / 1.6);

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
		CP_Graphics_DrawRectAdvanced(width / 1.7, height / 1.4, 200, 100, 0, 5); // false button
		CP_Graphics_DrawRectAdvanced(width / 2.4, height / 1.4, 200, 100, 0, 5); // true button

		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
		CP_Font_DrawText(" True ", width / 2.4, height / 1.4);
		CP_Font_DrawText(" False ", width / 1.7, height / 1.4);

		//If mouse click is within a certain area
		if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT) && (clicked_q3 == FALSE) && (question_3ans == FALSE))
		{
			if (IsAreaClicked(width / 2.4f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				question_3ans = TRUE;
			}
			else if (IsAreaClicked(width / 1.7f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				clicked_q3 = TRUE;
			}
		}
		if (clicked_q3 == TRUE)
		{
			CP_Font_DrawText(" Correct ", width / 2, height / 1.8);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.3, height / 1.3, 200, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Next ", width / 1.3, height / 1.3);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.3f, height / 1.3f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{

					question_4 = TRUE;
					question_3 = FALSE;
				}
			}
		}
		if ((clicked_q3 == FALSE) && (question_3ans == TRUE))
		{
			CP_Font_DrawText(" Wrong ", width / 2, height / 1.8);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.3, height / 1.3, 200, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Next ", width / 1.3, height / 1.3);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.3f, height / 1.3f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{

					question_3 = FALSE;
					question_4 = TRUE;
				}
			}
		}
	}





	if (question_4 == TRUE)
	{
		//Drawing and setting the start rectangle position
		CP_Font_DrawText("If x =      ", width / 2, height / 2);
		CP_Font_DrawText(TrueFalse_x4, width / 1.9, height / 2);
		CP_Font_DrawText(" Does      x + 3 equals to       ?", width / 2, height / 1.6);
		CP_Font_DrawText(TrueFalse_y4, width / 2.4, height / 1.6);
		CP_Font_DrawText(TrueFalseans4, width / 1.55, height / 1.6);

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
		CP_Graphics_DrawRectAdvanced(width / 1.7, height / 1.4, 200, 100, 0, 5); // false button
		CP_Graphics_DrawRectAdvanced(width / 2.4, height / 1.4, 200, 100, 0, 5); // true button

		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
		CP_Font_DrawText(" True ", width / 2.4, height / 1.4);
		CP_Font_DrawText(" False ", width / 1.7, height / 1.4);

		//If mouse click is within a certain area
		if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT) && (clicked_q4 == FALSE) && (question_4ans == FALSE))
		{
			if (IsAreaClicked(width / 2.4f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				clicked_q4 = TRUE;
			}
			else if (IsAreaClicked(width / 1.7f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				question_4ans = TRUE;
			}
		}
		if (clicked_q4 == TRUE)
		{
			CP_Font_DrawText(" Correct ", width / 2, height / 1.8);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.3, height / 1.3, 200, 100, 0, 5); // false button
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Next ", width / 1.3, height / 1.3);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.3f, height / 1.3f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{

					question_5 = TRUE;
					question_4 = FALSE;
				}
			}
		}
		if ((clicked_q4 == FALSE) && (question_4ans == TRUE))
		{
			CP_Font_DrawText(" Wrong ", width / 2, height / 1.8);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.3, height / 1.3, 200, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Next ", width / 1.3, height / 1.3);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.3f, height / 1.3f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{

					question_4 = FALSE;
					question_5 = TRUE;
				}
			}
		}
	}


	if (question_5 == TRUE)
	{
		//Drawing and setting the start rectangle position
		CP_Font_DrawText("If x =      ", width / 2, height / 2);
		CP_Font_DrawText(TrueFalse_x5, width / 1.9, height / 2);
		CP_Font_DrawText(" Does      x + 3 equals to       ?", width / 2, height / 1.6);
		CP_Font_DrawText(TrueFalse_y5, width / 2.4, height / 1.6);
		CP_Font_DrawText(TrueFalseans5, width / 1.55, height / 1.6);

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
		CP_Graphics_DrawRectAdvanced(width / 1.7, height / 1.4, 200, 100, 0, 5); // false button
		CP_Graphics_DrawRectAdvanced(width / 2.4, height / 1.4, 200, 100, 0, 5); // true button

		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
		CP_Font_DrawText(" True ", width / 2.4, height / 1.4);
		CP_Font_DrawText(" False ", width / 1.7, height / 1.4);

		//If mouse click is within a certain area
		if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT) && (clicked_q5 == FALSE) && (question_5ans == FALSE))
		{
			if (IsAreaClicked(width / 2.4f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				clicked_q5 = TRUE;
			}
			else if (IsAreaClicked(width / 1.7f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				question_5ans = TRUE;
			}
		}
		if (clicked_q5 == TRUE)
		{
			CP_Font_DrawText(" Correct ", width / 2, height / 1.8);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.3, 500, 100, 0, 5); // false button
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.3);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.2f, height / 1.3f, 500.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);

				}
			}
			}
		}
		if ((clicked_q5 == FALSE) && (question_5ans == TRUE))
		{
			CP_Font_DrawText(" Wrong ", width / 2, height / 1.8);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.3, 500, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.3);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.2f, height / 1.3f, 500.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);

				}
			}

		}
	











	// Pressing Q to exit the program
	if (CP_Input_KeyTriggered(KEY_Q))
	{
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit); 
	}			
	
		          
}
void Quiz_Exit()
{

}