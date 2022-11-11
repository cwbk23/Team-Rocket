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
	CP_Settings_TextSize(150.0f);
	CP_Font_DrawText("GAME OVER", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 5.0f);

	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("YOU LOSE", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 3.0f);

	// Display total score and checkpoints completed
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(50.0f);
	char checkpointStr[50] = { 0 };
	sprintf_s(checkpointStr, 50, "Completed %d Checkpoints", checkpoint_no);
	CP_Font_DrawText(checkpointStr, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f);
	char totalScoreStr[50] = { 0 };
	sprintf_s(totalScoreStr, 50, "Total Score: %d", quiz_score);
	CP_Font_DrawText(totalScoreStr, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 1.7f);

	// Play button
	CP_Settings_Fill(CP_Color_Create(0, 102, 255, 255));
	CP_Graphics_DrawRectAdvanced((CP_System_GetWindowWidth() / 2.0f - 200.0f), CP_System_GetWindowHeight() / 1.2f, 200.0f, 100.0f, 0.0f, 10.0f);

	// Main menu button
	CP_Settings_Fill(CP_Color_Create(0, 102, 255, 255));
	CP_Graphics_DrawRectAdvanced((CP_System_GetWindowWidth() / 2.0f + 200.0f), CP_System_GetWindowHeight() / 1.2f, 200.0f, 100.0f, 0.0f, 10.0f);

	// Play / Menu button text
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(35.0f);
	CP_Font_DrawText("PlAY AGAIN", (CP_System_GetWindowWidth() / 2.0f - 200.0f), CP_System_GetWindowHeight() / 1.2f);
	CP_Font_DrawText("MAIN MENU", (CP_System_GetWindowWidth() / 2.0f + 200.0f), CP_System_GetWindowHeight() / 1.2f);

	// Check for mouse left click
	if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)) {

		// Play button action
		if (IsAreaClicked((CP_System_GetWindowWidth() / 2.0f - 200.0f), CP_System_GetWindowHeight() / 1.2f, 200.0f, 100.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

			CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);
		}
		// Menu button action
		else if (IsAreaClicked((CP_System_GetWindowWidth() / 2.0f + 200.0f), CP_System_GetWindowHeight() / 1.2f, 200.0f, 100.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

			CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
		}
	}
}

void Lose_Screen_Exit()
{
	
}
