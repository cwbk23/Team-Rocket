#include "cprocessing.h"
#include "mainmenu.h"
#include "level.h"
#include "utils.h"


void Lose_Screen_Init()
{
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
}

void Lose_Screen_Update()
{
	// Red background colour
	CP_Graphics_ClearBackground(CP_Color_Create(255, 0, 0, 255));

	// Lose title
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(200.0f);
	CP_Font_DrawText("LOSE", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 4.5f);

	// Exit to main menu if ESC key pressed
	if (CP_Input_KeyTriggered(KEY_ESCAPE)) {
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void Lose_Screen_Exit()
{

}
