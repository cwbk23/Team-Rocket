#include "cprocessing.h"
#include "level.h"
#include "utils.h"


void Main_Menu_Init()
{
	/*CP_System_Fullscreen();*/
	/*CP_System_SetWindowSize(CP_System_GetDisplayWidth(), CP_System_GetDisplayHeight());*/
	CP_System_SetWindowSize(1920, 1080);
	CP_System_SetFrameRate(60.0f);
	
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
}

void Main_Menu_Update()
{
	CP_Graphics_ClearBackground(CP_Color_Create(135, 206, 250, 255));

	CP_Settings_Fill(CP_Color_Create(0, 102, 255, 255));
	CP_Graphics_DrawRect(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.3f, 150.0f, 50.0f);

	CP_Settings_Fill(CP_Color_Create(0, 153, 51, 255));
	CP_Graphics_DrawRect(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 1.7f, 150.0f, 50.0f);

	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(150.0f);
	CP_Font_DrawText("MATH RUN", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 4.5f);

	CP_Settings_TextSize(25.0f);
	CP_Font_DrawText("PLAY", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.3f);
	CP_Font_DrawText("EXIT", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 1.7f);

	if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)) {

		if (IsAreaClicked(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.3f, 150.0f, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

			CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);
		} 
		else if (IsAreaClicked(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 1.7f, 150.0f, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

			CP_Engine_Terminate();
		}
	}
}

void Main_Menu_Exit()
{
	
}
