#include "cprocessing.h"
#include "quiz.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include <mainmenu.h>
#include "utils.h"
#include <stdbool.h>

char TrueFalse_x1[4] = { 1 };
char TrueFalse_y1[10] = { 2 };
char TrueFalseans1[10] = { 3 };
char TrueFalse_x2[4] = { 1 };
char TrueFalse_y2[10] = { 2 };
char TrueFalseans2[10] = { 3 };



void Quiz_Init()
{
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
	sprintf_s(TrueFalseans2, _countof(TrueFalseans2), "%d", random_y2 + random_x2);

	
}
	
	bool clicked = false;
	bool question_1 = true;
	bool question_1ans = false;
	bool question_2 = false;
void Quiz_Update()
{
	int questionnum = 1;

	float height = (float)CP_System_GetWindowHeight();
	float width =  (float)CP_System_GetWindowWidth();

	//Setting the background colour
	CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));

	if (question_1 == TRUE)
	{

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
		if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
		{
			if (IsAreaClicked(width / 2.4f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				 clicked = TRUE;
			}
			else if (IsAreaClicked(width / 1.7f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				 question_1ans = TRUE;
			}
		

		}
			if (clicked == TRUE)
			{
				CP_Font_DrawText(" Correct ", width / 2, height / 1.8);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 2, height / 2.4, 200, 100, 0, 5); // false button
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 2, height / 2.4);
				//CP_Graphics_ClearBackground(CP_Color_Create(135, 206, 250, 255));
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width /2.0f, height / 2.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						CP_Graphics_ClearBackground(CP_Color_Create(135, 206, 250, 255));
						question_1 = FALSE;
						question_2 = TRUE;
					}
				}
			}
			if((question_1ans == TRUE) && (clicked == FALSE))
			{
				CP_Font_DrawText(" Wrong ", width / 2, height / 1.8);
			}
	}

	if (question_2 == TRUE )
	{

		//Drawing and setting the start rectangle position
		CP_Font_DrawText("If y =      and x =  ", width / 2, height / 2);
		CP_Font_DrawText(TrueFalse_x2, width / 2.15, height / 2);
		CP_Font_DrawText(TrueFalse_y2, width / 1.65, height / 2);
		CP_Font_DrawText(" Does x and y equals to       ?", width / 2, height / 1.6);
		CP_Font_DrawText(TrueFalseans2, width / 1.55, height / 1.6);

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
		CP_Graphics_DrawRectAdvanced(width / 1.7, height / 1.4, 200, 100, 0, 5); // false button
		CP_Graphics_DrawRectAdvanced(width / 2.4, height / 1.4, 200, 100, 0, 5); // true button

		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
		CP_Font_DrawText(" True ", width / 2.4, height / 1.4);
		CP_Font_DrawText(" False ", width / 1.7, height / 1.4);

		//If mouse click is within a certain area
		if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
		{
			if (IsAreaClicked(width / 2.4f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				CP_Font_DrawText(" Correct ", width / 2, height / 1.8);
			}
			else if (IsAreaClicked(width / 1.7f, height / 1.4f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
			{
				CP_Font_DrawText(" Wrong ", width / 2, height / 1.8);
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