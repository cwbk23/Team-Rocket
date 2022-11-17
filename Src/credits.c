#include "cprocessing.h"
#include "mainmenu.h"

CP_Image TeamName;
CP_Image KennyName, WeiFongName, ClementName, YeeLeiName;
CP_Image DigipenExec;
int transparencyTeam, transparency;
float totalElapsedTime, totalElapsedTime_sec;

void Credits_Init(void)
{
	CP_Settings_ImageMode(CP_POSITION_CENTER);
	TeamName = CP_Image_Load("./Assets/team_name.png");
	KennyName = CP_Image_Load("./Assets/kenny_name.png");
	WeiFongName = CP_Image_Load("./Assets/weifong_name.png");
	ClementName = CP_Image_Load("./Assets/clement_name.png");
	YeeLeiName = CP_Image_Load("./Assets/yeelei_name.png");
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
	if (totalElapsedTime < 4.0f)
	{
		CP_Image_Draw(TeamName, CP_System_GetWindowWidth() / 2.0, (CP_System_GetWindowHeight() / 2.0) - 200.f, CP_Image_GetWidth(TeamName) + 200.f, CP_Image_GetHeight(TeamName), transparencyTeam);
		if (transparencyTeam < 255)
		{
			transparencyTeam = (totalElapsedTime_sec / 4) * 255;
		}
	}

	if (totalElapsedTime >= 4.0f && totalElapsedTime < 6.0f)
	{
		CP_Image_Draw(TeamName, CP_System_GetWindowWidth() / 2.0, (CP_System_GetWindowHeight() / 2.0) - 200.f, CP_Image_GetWidth(TeamName) + 200.f, CP_Image_GetHeight(TeamName), transparencyTeam);
		CP_Image_Draw(KennyName, CP_System_GetWindowWidth() / 2.0, (CP_System_GetWindowHeight() / 2.0) - 100.f, CP_Image_GetWidth(TeamName), CP_Image_GetHeight(TeamName), transparencyTeam);
		CP_Image_Draw(WeiFongName, CP_System_GetWindowWidth() / 2.0, CP_System_GetWindowHeight() / 2.0, CP_Image_GetWidth(TeamName), CP_Image_GetHeight(TeamName), transparencyTeam);
		CP_Image_Draw(ClementName, CP_System_GetWindowWidth() / 2.0, (CP_System_GetWindowHeight() / 2.0) + 100.f, CP_Image_GetWidth(TeamName), CP_Image_GetHeight(TeamName), transparencyTeam);
		CP_Image_Draw(YeeLeiName, CP_System_GetWindowWidth() / 2.0, (CP_System_GetWindowHeight() / 2.0) + 200.f, CP_Image_GetWidth(TeamName), CP_Image_GetHeight(TeamName), transparencyTeam);
		totalElapsedTime_sec = 0.0f;
	}

	if (totalElapsedTime >= 6.0f)
	{
		CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
		CP_Image_Draw(DigipenExec, CP_System_GetWindowWidth() / 2.0, CP_System_GetWindowHeight() / 2.0, CP_Image_GetWidth(DigipenExec), CP_Image_GetHeight(DigipenExec), transparency);
		if (transparency < 255)
		{
			transparency = (totalElapsedTime_sec / 4) * 255;
		}
	}

	if (totalElapsedTime >= 10.0f)
	{
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void Credits_Exit(void)
{
	CP_Image_Free(&TeamName);
}