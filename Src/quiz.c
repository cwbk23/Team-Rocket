#include "cprocessing.h"
#include"quiz.h"
#include"math.h"
#include<stdio.h>
#include<stdlib.h>

//#include"utils.h"
char TrueFalse_x[4] = { 1 };
char TrueFalse_y[10] = { 2 };
char TrueFalseans[10] = { 3 };

void Quiz_Init()
{
	//Setting up the window size
	CP_System_SetWindowSize(700, 700);
	CP_Settings_TextSize(30);

	int random_x = CP_Random_RangeInt(0, 10);
	sprintf_s(TrueFalse_x, _countof(TrueFalse_x), "%d", random_x);
	int random_y = CP_Random_RangeInt(0, 10);
	sprintf_s(TrueFalse_y, _countof(TrueFalse_y), "%d", random_y);
	sprintf_s(TrueFalseans, _countof(TrueFalseans), "%d", random_y + random_x);
	
}
	
void Quiz_Update()
{

	//Setting the background colour
	CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));

	//Drawing and setting the start rectangle position
	CP_Font_DrawText(" x =      and y =  ", 200, 200);
	CP_Font_DrawText(TrueFalse_x, 250, 200);
	CP_Font_DrawText(TrueFalse_y, 380, 200);
	CP_Font_DrawText(" Does x and y equals to       ?", 180, 230);
	CP_Font_DrawText(TrueFalseans, 450, 230);

	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
	CP_Graphics_DrawRectAdvanced(180, 250, 100, 50, 0, 5);
	CP_Graphics_DrawRectAdvanced(350, 250, 100, 50, 0, 5);

	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText(" True ", 200, 280);
	CP_Font_DrawText(" False ", 360 , 280);

	//If mouse click is within a certain area
	//if (CP_Input_MouseClicked())
	//{
	//	IsAreaClicked(200.0f, 280.0f, 100.0f, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY());
	//}
	

	
	// Pressing Q to exit the program
	if (CP_Input_KeyTriggered(KEY_Q))
	{
		CP_Engine_Terminate();
	}
		          
}
void Quiz_Exit()
{

}