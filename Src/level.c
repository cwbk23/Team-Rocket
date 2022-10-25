#include "cprocessing.h"
#include "mainmenu.h"
#include "utils.h"


void Level_Init()
{
	
}

void Level_Update()
{
	CP_Graphics_ClearBackground(CP_Color_Create(135, 206, 250, 255));

	CP_Graphics_DrawRect(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 25.0f, 25.0f);

	if (CP_Input_KeyTriggered(KEY_ESCAPE)) {
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void Level_Exit()
{
	
}
