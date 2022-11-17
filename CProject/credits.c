#include "cprocessing.h"
#include "mainmenu.h"

CP_Image TeamName;
int transparency;

void Credits_Init(void)
{
	CP_Settings_ImageMode(CP_POSITION_CENTER);
	TeamName = CP_Image_Load("./Assets/team_name.png");
	transparency = 0;
}

void Credits_Update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(0, 191, 255, 255));
	float currentElapsedTime = CP_System_GetDt();
	static float totalElapsedTime = 0;
	totalElapsedTime += currentElapsedTime;

	CP_Image_Draw(TeamName, CP_System_GetWindowWidth() / 2.0, CP_System_GetWindowHeight() / 2.0, CP_Image_GetWidth(TeamName), CP_Image_GetHeight(TeamName), transparency);
	if (transparency < 255)
	{
		transparency = (totalElapsedTime / 4) * 255;
	}
	else
	{
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void Credits_Exit(void)
{
	CP_Image_Free(&TeamName);
}