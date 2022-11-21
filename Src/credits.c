#include "cprocessing.h"
#include "mainmenu.h"

CP_Image TeamName;
CP_Image DigipenExec;
CP_Image CreditsThanks;
int transparency1, transparency2, transparency3;
float totalElapsedTime, totalElapsedTime_sec;

void Credits_Init(void)
{
	CP_Settings_ImageMode(CP_POSITION_CENTER);
	TeamName = CP_Image_Load("./Assets/team_name.png");
	DigipenExec = CP_Image_Load("./Assets/digipenexec.png");
	CreditsThanks = CP_Image_Load("./Assets/credits_thanks.png");

	totalElapsedTime = 0.0f;
	totalElapsedTime_sec = 0.0f;
	transparency1 = 0, transparency2 = 0, transparency3 = 0;
}

void Credits_Update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
	float currentElapsedTime = CP_System_GetDt();
	totalElapsedTime += currentElapsedTime;
	totalElapsedTime_sec += currentElapsedTime;

	if (totalElapsedTime < 6.0f)
	{
		CP_Image_Draw(TeamName, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, (float)CP_Image_GetWidth(TeamName), (float)CP_Image_GetHeight(TeamName), transparency1);
		if (transparency1 < 255)
		{
			transparency1 = (int)((totalElapsedTime_sec / 4) * 255);
		}
	}

	if (totalElapsedTime >= 6.0f && totalElapsedTime < 12.0f)
	{
		if (transparency1 >= 255)
		{
			totalElapsedTime_sec = 0.0f;
			transparency1 = 0;
		}

		CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
		CP_Image_Draw(CreditsThanks, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, (float)CP_Image_GetWidth(CreditsThanks), (float)CP_Image_GetHeight(CreditsThanks), transparency2);
		if (transparency2 < 255)
		{
			transparency2 = (int)((totalElapsedTime_sec / 4) * 255);
		}
	}

	if (totalElapsedTime >= 12.0f && totalElapsedTime < 18.0f)
	{
		if (transparency2 >= 255)
		{
			totalElapsedTime_sec = 0.0f;
			transparency2 = 0;
		}

		CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
		CP_Image_Draw(DigipenExec, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, (float)CP_Image_GetWidth(DigipenExec), (float)CP_Image_GetHeight(DigipenExec), transparency3);
		if (transparency3 < 255)
		{
			transparency3 = (int)((totalElapsedTime_sec / 4) * 255);
		}
	}

	if (totalElapsedTime >= 18.0f)
	{
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Exit to main menu if ESC key pressed
	if (CP_Input_KeyTriggered(KEY_ESCAPE)) {
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void Credits_Exit(void)
{
	CP_Image_Free(&TeamName);
	CP_Image_Free(&DigipenExec);
	CP_Image_Free(&CreditsThanks);
}