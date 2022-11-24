#include "cprocessing.h"
#include "mainmenu.h"
#include "level.h"
#include "utils.h"

CP_Image Howtopage;

void HowToPlay_Init() {

	CP_Settings_ImageMode(CP_POSITION_CENTER);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	// Load How to Play page
	Howtopage = CP_Image_Load("Assets/howtopage.png");
}

void HowToPlay_Update() {

	// Sky blue background colour
	CP_Graphics_ClearBackground(CP_Color_Create(135, 206, 235, 255));
	CP_Color color_darkgrey = (CP_Color_Create(128, 128, 128, 255));
	CP_Color color_white = (CP_Color_Create(255, 255, 255, 255));

	// Draw How to Play page
	CP_Image_Draw(Howtopage, (CP_System_GetWindowWidth() / 2.0f), (CP_System_GetWindowHeight() / 2.0f - 50.f), 1720.0f, 900.0f, 255);

	// Start Game button
	CP_Settings_Fill(color_darkgrey);
	CP_Graphics_DrawRectAdvanced((CP_System_GetWindowWidth() / 2.0f) - 200.0f, (CP_System_GetWindowHeight() / 2.0f) + 425.0f, 300.f, 80.f, 0.f, 10.f);
	
	// Exit to Main Menu button
	CP_Graphics_DrawRectAdvanced((CP_System_GetWindowWidth() / 2.0f) + 200.0f, (CP_System_GetWindowHeight() / 2.0f) + 425.0f, 300.f, 80.f, 0.f, 10.f);

	// Text buttons
	CP_Settings_Fill(color_white);
	CP_Settings_TextSize(35.0f);
	
	CP_Font_DrawText("START GAME", (CP_System_GetWindowWidth() / 2.0f) - 200.0f, (CP_System_GetWindowHeight() / 2.0f) + 425.0f);
	CP_Font_DrawText("EXIT TO MAIN MENU", (CP_System_GetWindowWidth() / 2.0f) + 200.0f, (CP_System_GetWindowHeight() / 2.0f) + 425.0f);

	// Check for mouse left click
	if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)) {
	
		// Exit to Main Menu action
		if (IsAreaClicked((CP_System_GetWindowWidth() / 2.0f) - 200.0f, (CP_System_GetWindowHeight() / 2.0f) + 425.0f, 300.f, 80.f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {
			CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);
		}
		// Start Game action
		else if (IsAreaClicked((CP_System_GetWindowWidth() / 2.0f) + 200.0f, (CP_System_GetWindowHeight() / 2.0f) + 425.0f, 300.f, 80.f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {
			CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
		}
	
	}

	// Exit to main menu if ESC key pressed
	if (CP_Input_KeyTriggered(KEY_ESCAPE)) {
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void HowToPlay_Exit() {
	CP_Image_Free(&Howtopage);
}