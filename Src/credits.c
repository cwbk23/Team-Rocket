#include "cprocessing.h"
#include "mainmenu.h"

CP_Image TeamName;
CP_Image DigipenExec;
int transparencyTeam, transparency;
float totalElapsedTime, totalElapsedTime_sec;

void Credits_Init(void)
{
	CP_Settings_ImageMode(CP_POSITION_CENTER);
	TeamName = CP_Image_Load("./Assets/team_name.png");
	DigipenExec = CP_Image_Load("./Assets/digipenexec.png");

	totalElapsedTime = 0.0f;
	totalElapsedTime_sec = 0.0f;
	transparencyTeam = 0;
	transparency = 0;
}

void Credits_Update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
	float currentElapsedTime = CP_System_GetDt();
	totalElapsedTime += currentElapsedTime;
	totalElapsedTime_sec += currentElapsedTime;

	if (totalElapsedTime < 8.0f)
	{
		CP_Image_Draw(TeamName, CP_System_GetWindowWidth() / 2.0, CP_System_GetWindowHeight() / 2.0, CP_Image_GetWidth(TeamName), CP_Image_GetHeight(TeamName), transparencyTeam);
		if (transparencyTeam < 255)
		{
			transparencyTeam = (totalElapsedTime_sec / 4) * 255;
		}
	}

	if (totalElapsedTime >= 8.0f)
	{
		if (transparencyTeam >= 255)
		{
			totalElapsedTime_sec = 0.0f;
			transparencyTeam = 0;
		}
		CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
		CP_Image_Draw(DigipenExec, CP_System_GetWindowWidth() / 2.0, CP_System_GetWindowHeight() / 2.0, CP_Image_GetWidth(DigipenExec), CP_Image_GetHeight(DigipenExec), transparency);
		if (transparency < 255)
		{
			transparency = (totalElapsedTime_sec / 4) * 255;
		}
	}

	if (totalElapsedTime >= 14.0f)
	{
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void Credits_Exit(void)
{
	CP_Image_Free(&TeamName);
}