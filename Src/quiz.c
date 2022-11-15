#include "cprocessing.h"
#include "quiz.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include <mainmenu.h>
#include "utils.h"
#include <stdbool.h>
#include<level.h>

char TrueFalse_x1[10] = { 10 };
char TrueFalse_y1[10] = { 10 };
char TrueFalseans1[10] = { 10 };

char TrueFalse_x2[10] = { 10 };
char TrueFalse_y2[10] = { 10 };
char TrueFalseans2[10] = { 10 };


char TrueFalse_x3[10] = { 10 };
char TrueFalse_y3[10] = { 10 };
char TrueFalseans3[10] = { 10 };


char TrueFalse_x4[10] = { 10 };
char TrueFalse_y4[10] = { 10 };
char TrueFalseans4[10] = { 10 };


char TrueFalse_x5[10] = { 10 };
char TrueFalse_y5[10] = { 10 };
char TrueFalseans5[10] = { 10 };

char multiplechoice1_1[10] = { 10 };
char multiplechoice1_2[10] = { 10 };
char multiplechoice1_3[10] = { 10 };
char multiplechoice1_ans[10] = { 10 };

char OperatorRandom[10] = { 3 };
char totalscore[10] = { 3 };

int counter = 0;

void Quiz_Init()
{
int quiz_score = 0;
	quiz_score = 0;
	  
	 
	//Setting up the window size
	CP_Settings_TextSize(70);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	int random_x1 = CP_Random_RangeInt(1, 10);
	sprintf_s(TrueFalse_x1, _countof(TrueFalse_x1), "%d", random_x1);
	int random_y1 = CP_Random_RangeInt(1, 10);
	sprintf_s(TrueFalse_y1, _countof(TrueFalse_y1), "%d", random_y1);
	sprintf_s(TrueFalseans1, _countof(TrueFalseans1), "%d", random_y1 + random_x1);

	int random_x2 = CP_Random_RangeInt(1, 10);
	sprintf_s(TrueFalse_x2, _countof(TrueFalse_x2), "%d", random_x2);
	int random_y2 = CP_Random_RangeInt(1, 10);
	sprintf_s(TrueFalse_y2, _countof(TrueFalse_y2), "%d", random_y2);
	sprintf_s(TrueFalseans2, _countof(TrueFalseans2), "%d",  random_y2*random_x2 + 3);

	int random_x3 = CP_Random_RangeInt(1, 5);
	sprintf_s(TrueFalse_x3, _countof(TrueFalse_x3), "%d", random_x3);
	int random_y3 = CP_Random_RangeInt(1, 5);
	sprintf_s(TrueFalse_y3, _countof(TrueFalse_y3), "%d", random_y3);
	sprintf_s(TrueFalseans3, _countof(TrueFalseans3), "%d", random_y3 * random_x3 + 2);

	int random_x4 = CP_Random_RangeInt(1, 5);
	sprintf_s(TrueFalse_x4, _countof(TrueFalse_x4), "%d", random_x4);
	int random_y4 = CP_Random_RangeInt(1, 5);
	sprintf_s(TrueFalse_y4, _countof(TrueFalse_y4), "%d", random_y4);
	sprintf_s(TrueFalseans4, _countof(TrueFalseans4), "%d", random_x4 * random_y4 );

	int random_x5 = CP_Random_RangeInt(1, 5);
	sprintf_s(TrueFalse_x5, _countof(TrueFalse_x5), "%d", random_x5);
	int random_y5 = CP_Random_RangeInt(1, 5);
	sprintf_s(TrueFalse_y5, _countof(TrueFalse_y5), "%d", random_y5);
	sprintf_s(TrueFalseans5, _countof(TrueFalseans5), "%d", random_y5 * random_x5 - 5);

	int randomoperator = CP_Random_RangeInt(1,4);
	sprintf_s(OperatorRandom, _countof(OperatorRandom), "%d", randomoperator);

	
	
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

	bool fail_page = false;




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
		CP_Font_DrawText("Timer:     :", width /1.2, height / 8);
		float currentElapsedTime = CP_System_GetDt();
		static float totalElapsedTime = 300;
		totalElapsedTime -= currentElapsedTime;
		char minute[16] = { 0 };
		char second[16] = { 0 };
		sprintf_s(minute, _countof(minute), "%d",(int) totalElapsedTime/60);
		sprintf_s(second, _countof(second), "%.d", ((int)totalElapsedTime%60));
		CP_Font_DrawText(minute, width/1.14, height/8 );
		CP_Font_DrawText(second, width/1.08, height / 8);

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

			 fail_page = false;
		}
	}
		if (timesuppage == true) 
		{
			CP_Settings_TextSize(100);
			CP_Font_DrawText("Times up !", width / 2, height / 2);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5); // false button
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Settings_TextSize(70);
			CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.2f, height / 1.1f, 500.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);

					}
				}
			}
		
	if (question_1 == TRUE)
	{
		CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
		CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
		int total_score = counter * 10;
		sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

		CP_Settings_TextSize(50);
		CP_Font_DrawText("Current score :", width / 9, height / 8);
		CP_Font_DrawText(totalscore , width / 5, height / 8);

		//Drawing and setting the start rectangle position
		CP_Settings_TextSize(70);
		CP_Font_DrawText("q1)", width / 3, height / 4);
		CP_Font_DrawText("If x =      and y =  ", width / 2, height / 4);
		CP_Font_DrawText(TrueFalse_x1, width / 2.1, height / 4);
		CP_Font_DrawText(TrueFalse_y1, width / 1.6, height / 4);
		CP_Font_DrawText(" Does x and y equals to       ?", width / 1.9, height / 3);
		CP_Font_DrawText(TrueFalseans1, width / 1.49, height / 3);
		CP_Font_DrawText(OperatorRandom, width / 4, height / 4);

		if (OperatorRandom == 1)
		{
			CP_Font_DrawText("+", width / 4, height / 4);
		}
		else if (OperatorRandom == 2)
		{
			CP_Font_DrawText("-", width / 4, height / 4);
		}
		else if (OperatorRandom == 3)
		{
			CP_Font_DrawText("x", width / 4, height / 4);
		}
		else if (OperatorRandom == 4)
		{
			CP_Font_DrawText("/", width / 4, height / 4);
		}

		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
		CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5); // false button
		CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
		CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5); // true button

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
		CP_Font_DrawText(" True ", width / 2.6, height / 2);
		CP_Font_DrawText(" False ", width / 1.5, height / 2);

		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
		CP_Settings_TextSize(50);
		CP_Font_DrawText("10 marks ", width /9, height / 1.1);
		CP_Settings_TextSize(70);
		
		//If mouse click is within a certain area
		if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)&&(clicked_q1 == FALSE) && (question_1ans == FALSE))
		{
			if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				clicked_q1 = TRUE;
				counter = counter + 1;
			}
			else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				 question_1ans = TRUE;
			}
		

		}
			if ((clicked_q1 == TRUE))
			{
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
				CP_Font_DrawText(" Correct ", width / 2, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5); 
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width /1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						
						question_1 = FALSE;
						question_2 = TRUE;
					}
				}
			} if((question_1ans == TRUE)&&(clicked_q1 == FALSE))
			{
				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
				CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5); 
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 1.1,height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{

						question_1 = FALSE;
						question_2 = TRUE;
					}
				}
			}
	}

	if (question_2 == TRUE )
	{
		int total_score = counter * 10;
		sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

		CP_Settings_TextSize(50);
		CP_Font_DrawText("Current score :", width / 9, height / 8);
		CP_Font_DrawText(totalscore, width / 5, height / 8);

		CP_Settings_TextSize(70);
		//Drawing and setting the start rectangle position
		CP_Font_DrawText("q2)", width / 3, height / 4);
		CP_Font_DrawText("If x =      ", width / 2, height / 4);
		CP_Font_DrawText(TrueFalse_x2, width / 1.9, height / 4);
		CP_Font_DrawText(" Does      x + 3 equals to       ?", width / 2, height / 3);
		CP_Font_DrawText(TrueFalse_y2, width / 2.4, height / 3);
		//CP_Font_DrawText(TrueFalse_x2, width / 2.15, height / 1.6);
		CP_Font_DrawText(TrueFalseans2, width / 1.55, height / 3);

		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
		CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5); // false button
		CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
		CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5); // true button

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
		CP_Font_DrawText(" True ", width / 2.6, height / 2);
		CP_Font_DrawText(" False ", width / 1.5, height / 2);

		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
		CP_Settings_TextSize(50);
		CP_Font_DrawText("10 marks ", width / 9, height / 1.1);
		CP_Settings_TextSize(70);

		//If mouse click is within a certain area
		if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q2 == FALSE) && (question_2ans == FALSE))
		{
			if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				clicked_q2 = TRUE;
				counter = counter + 1;
			}
			else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				question_2ans = TRUE;
			}


		}
		if ((clicked_q2 == TRUE))
		{
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
			CP_Font_DrawText(" Correct ", width / 2, height / 1.5);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{

					question_2 = FALSE;
					question_3 = TRUE;
				}
			}
		} if ((question_2ans == TRUE) && (clicked_q2 == FALSE))
		{
			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
			CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{

					question_2 = FALSE;
					question_3 = TRUE;
				}
			}
		}
	}


	if (question_3 == TRUE)
	{
		int total_score = counter * 10;
		sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

		CP_Settings_TextSize(50);
		CP_Font_DrawText("Current score :", width / 9, height / 8);
		CP_Font_DrawText(totalscore, width / 5, height / 8);

		CP_Settings_TextSize(70);
		CP_Font_DrawText("q3)", width / 3, height / 4);
		CP_Font_DrawText("If x =      ", width / 2, height / 4);
		CP_Font_DrawText(TrueFalse_x3, width / 1.9, height / 4);
		CP_Font_DrawText(" Does      x + 3 equals to       ?", width / 2, height / 3);
		CP_Font_DrawText(TrueFalse_y3, width / 2.4, height / 3);
		CP_Font_DrawText(TrueFalseans3, width / 1.55, height / 3);

		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
		CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5); // false button
		CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
		CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5); // true button

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
		CP_Font_DrawText(" True ", width / 2.6, height / 2);
		CP_Font_DrawText(" False ", width / 1.5, height / 2);

		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
		CP_Settings_TextSize(50);
		CP_Font_DrawText("10 marks ", width / 9, height / 1.1);
		CP_Settings_TextSize(70);

		//If mouse click is within a certain area
		if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q3 == FALSE) && (question_3ans == FALSE))
		{
			if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				clicked_q3 = TRUE;
			}
			else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				question_3ans = TRUE;
				counter = counter + 1;
			}


		}
		if ((question_3ans == TRUE))
		{
			
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
			CP_Font_DrawText(" Correct ", width / 2, height / 1.5);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{

					question_3 = FALSE;
					question_4 = TRUE;
				}
			}
		} if ((clicked_q3 == TRUE) )
		{
			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
			CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{

					question_3 = FALSE;
					question_4 = TRUE;
				}
			}
		}
	}



	if (question_4 == TRUE)
	{
		int total_score = counter * 10;
		sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

		CP_Settings_TextSize(50);
		CP_Font_DrawText("Current score :", width / 9, height / 8);
		CP_Font_DrawText(totalscore, width / 5, height / 8);

		CP_Settings_TextSize(70);
		//Drawing and setting the start rectangle position
		CP_Font_DrawText("q4)", width / 3, height / 4);
		CP_Font_DrawText("If x =      and y =  ", width / 2, height / 4);
		CP_Font_DrawText(TrueFalse_x4, width / 2.1, height / 4);
		CP_Font_DrawText(TrueFalse_y4, width / 1.6, height / 4);
		CP_Font_DrawText(" Does x times y equals to       ?", width / 1.9, height / 3);
		CP_Font_DrawText(TrueFalseans4, width / 1.48, height / 3);

		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
		CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5); // false button
		CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
		CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5); // true button

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
		CP_Font_DrawText(" True ", width / 2.6, height / 2);
		CP_Font_DrawText(" False ", width / 1.5, height / 2);

		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
		CP_Settings_TextSize(50);
		CP_Font_DrawText("10 marks ", width / 9, height / 1.1);
		CP_Settings_TextSize(70);

		//If mouse click is within a certain area
		if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q4 == FALSE) && (question_4ans == FALSE))
		{
			if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				clicked_q4 = TRUE;
				counter = counter + 1;
			}
			else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				question_4ans = TRUE;
			}


		}
		if ((clicked_q4 == TRUE))
		{
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
			CP_Font_DrawText(" Correct ", width / 2, height / 1.5);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{

					question_4 = FALSE;
					question_5 = TRUE;
				}
			}
		} if ((question_4ans == TRUE) && (clicked_q4 == FALSE))
		{
			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
			CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{

					question_4 = FALSE;
					question_5 = TRUE;
				}
			}
		}
	}


	if (question_5 == TRUE)
	{
		int total_score = counter * 10;
		sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

		CP_Settings_TextSize(50);
		CP_Font_DrawText("Current score :", width / 9, height / 8);
		CP_Font_DrawText(totalscore, width / 5, height / 8);

		CP_Settings_TextSize(70);
		//Drawing and setting the start rectangle position
		CP_Font_DrawText("q5)", width / 3, height / 4);
		CP_Font_DrawText("If x =      ", width / 2, height / 4);
		CP_Font_DrawText(TrueFalse_x5, width / 1.9, height / 4);
		CP_Font_DrawText(" Does      x - 5 equals to       ?", width / 2, height / 3);
		CP_Font_DrawText(TrueFalse_y5, width / 2.4, height / 3);
		CP_Font_DrawText(TrueFalseans5, width / 1.55, height / 3);

		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
		CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5); // false button
		CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
		CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5); // true button

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
		CP_Font_DrawText(" True ", width / 2.6, height / 2);
		CP_Font_DrawText(" False ", width / 1.5, height / 2);

		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
		CP_Settings_TextSize(50);
		CP_Font_DrawText("10 marks ", width / 9, height / 1.1);
		CP_Settings_TextSize(70);

		//If mouse click is within a certain area
		if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q5 == FALSE) && (question_5ans == FALSE))
		{
			if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				clicked_q5 = TRUE;
				counter = counter + 1;

			}
			else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				question_5ans = TRUE;
			}
		}

	
		if (clicked_q5 == TRUE)
		{
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
			CP_Font_DrawText(" Correct ", width / 2, height / 1.5);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.2	, height / 1.1, 500, 100, 0, 5); // false button
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.1);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				question_5 = false;
				fail_page = true;
			}
			}
		}
		if (question_5ans == TRUE)
		{
			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
			CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.1);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				question_5 = false;
				fail_page = true;
			}
		}

		int total_score = counter * 10;
		sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

		if (fail_page == true)
		{

			if (counter <=2)
			{
				CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
				CP_Font_DrawText("U HAVE FAIL THE REQUIREMENT", width / 2, height / 4);
				CP_Font_DrawText("You have scored a total of:", width / 2, height / 3);
				CP_Font_DrawText(totalscore, width / 1.4, height / 3);
				CP_Font_DrawText(" Retry quiz ", width / 3, height / 1.1);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 3, height / 1.1, 500, 100, 0, 5);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 3, height / 1.1f, 500.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						CP_Engine_SetNextGameState(Quiz_Init, Quiz_Update, Quiz_Exit);

					}
				}
			}
			else if (counter > 2)
			{
				CP_Font_DrawText("U HAVE PASS THE REQUIREMENT", width / 2, height / 4);
				CP_Font_DrawText("You have scored a total of:", width / 2, height / 3);
				CP_Font_DrawText(totalscore, width /1.4, height / 3);
			}

			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.1);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.2f, height / 1.1f, 500.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);

				}
			}

		}

		quiz_score = counter;

	
	// Pressing Q to exit the program
	if (CP_Input_KeyTriggered(KEY_ESCAPE))
	{
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit); 
	}			
	
		          
}
void Quiz_Exit()
{

}