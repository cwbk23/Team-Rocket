#include "cprocessing.h"
#include "level.h"
#include "utils.h"
#include "quiz.h"
#include "credits.h"


void Main_Menu_Init()
{	
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	checkpoint_no = -1;
	quiz_score = 0;
}

void Main_Menu_Update()
{
	// Sky blue background colour
	CP_Graphics_ClearBackground(CP_Color_Create(0, 191, 255, 255));

	// Play button
	CP_Settings_Fill(CP_Color_Create(0, 102, 255, 255));
	CP_Graphics_DrawRect(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, 150.0f, 50.0f);

	// Credits button
	CP_Settings_Fill(CP_Color_Create(0, 153, 51, 255));
	CP_Graphics_DrawRect(CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 100.0f, 150.0f, 50.0f);

	// Exit button
	CP_Settings_Fill(CP_Color_Create(128, 128, 128, 255));
	CP_Graphics_DrawRect(CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 200.0f, 150.0f, 50.0f);

	// Buttons text
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(25.0f);
	CP_Font_DrawText("PLAY", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f);
	CP_Font_DrawText("CREDITS", CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 100.0f);
	CP_Font_DrawText("EXIT", CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 200.0f);

	// Game title
	CP_Settings_TextSize(150.0f);
	CP_Font_DrawText("MATH RUN", CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) - 250.0f);

	// Check for mouse left click
	if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)) {

		// Play game
		if (IsAreaClicked(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, 150.0f, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

			CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);
		}
		// Credits screen
		else if (IsAreaClicked(CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 100.0f, 150.0f, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

			CP_Engine_SetNextGameState(Credits_Init, Credits_Update, Credits_Exit);
		}
		// Exit game
		else if (IsAreaClicked(CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 200.0f, 150.0f, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

			CP_Engine_Terminate();
		}
	}
}

void Main_Menu_Exit()
{
	
}
