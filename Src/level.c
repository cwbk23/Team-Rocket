#include "cprocessing.h"
#include "mainmenu.h"
#include "utils.h"


void Level_Init()
{
	
}

void Level_Update()
{
	// Sky blue background colour
	CP_Graphics_ClearBackground(CP_Color_Create(135, 206, 250, 255));

	// Test
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Graphics_DrawRect(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 25.0f, 25.0f);
	
	// Kenny
	// Set starting point of rectangles
	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Graphics_DrawRectAdvanced(CP_System_GetWindowWidth() / 12.8f, CP_System_GetWindowHeight() / 7.2f, 50.f, 20.f, 90.f, 0.f);
	
	// Exit game if press ESC key
	if (CP_Input_KeyTriggered(KEY_ESCAPE)) {
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}


	// Clement 1

}

void Level_Exit()
{
	
}
