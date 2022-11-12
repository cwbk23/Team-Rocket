#include "cprocessing.h"
#include "utils.h"
#include "mainmenu.h"
#include "level.h"
#include <stdbool.h>
#include <stdio.h>

bool new_highscore;

struct BOXES {
	float pos_x, pos_y, width, height;
}; 
	
//int *highscore;
//int *game_score;
//int highscore;

FILE* highscore_file;

void Win_Init() {
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	// Reset checkpoint number to 0
	checkpoint_no = -1;

	new_highscore = FALSE;

}

void Win_Update() {

	// Emerald green background colour
	//CP_Graphics_ClearBackground(CP_Color_Create(80, 200, 120, 255));
	CP_Graphics_ClearBackground(CP_Color_Create(0, 153, 51, 255));
	CP_Color color_white = (CP_Color_Create(255, 255, 255, 255));
	CP_Color color_blue = (CP_Color_Create(0, 102, 255, 255));
	CP_Color color_lightgrey = (CP_Color_Create(199, 198, 193, 255));
	CP_Color color_darkgrey = (CP_Color_Create(119, 123, 126, 255));
	CP_Color color_test = (CP_Color_Create(30, 144, 255, 255));

	// Score breakdown box
	CP_Settings_Fill(color_darkgrey);
	CP_Graphics_DrawRectAdvanced(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 1.675f, 450.0f, 250.0f, 0.f, 5.0f);

	// Return to main menu button
	CP_Settings_Fill(color_blue);
	CP_Graphics_DrawRectAdvanced((CP_System_GetWindowWidth() / 2.0f) - 200.f, CP_System_GetWindowHeight() / 1.20f, 200.f, 100.f, 0.f, 10.f);

	// Play again button
	CP_Graphics_DrawRectAdvanced((CP_System_GetWindowWidth() / 2.0f) + 200.f, CP_System_GetWindowHeight() / 1.20f, 200.f, 100.f, 0.f, 10.f);


	// Calculate and compare current game score with previous highscore
		/* game_score = quiz_score + players lives left*/
	int game_score = 500;

	// Retrieve previous highscore from highscore text file
	//FILE* highscore_file;
	//fopen_s(highscore_file, "Highscore.txt", "w+");
	//if (highscore_file == NULL) {
	//	return 0;
	//}

	int highscore = 1000;
	//fgets(highscore, 10, highscore_file);
	
	//fscanf(highscore_file, "%d", highscore);

	// Compare scores
	CP_Settings_Fill(color_white);

	if (game_score > highscore) {
		/* Write current game score into highscore text file */
		//fputs(*game_score, highscore_file);
		//fclose(highscore_file);
		new_highscore = TRUE;
	}
	
	// Draw and display score boxes
	if (new_highscore == TRUE) {
	
		CP_Settings_TextSize(50.0f);
		new_highscore = FALSE;

		// Display new highscore
		CP_Font_DrawText("NEW HIGH SCORE: 1000", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 3.3f);
	
	} else {
		
		CP_Settings_TextSize(50.0f);

		// Display final game score
		CP_Font_DrawText("Total Score: 500", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 3.0f);
	
		// Display previous highscore
		CP_Font_DrawText("High Score: 1000", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.5f);
	}

	// Text for Victory message
	CP_Settings_TextSize(150.0f);

	CP_Font_DrawText("VICTORY", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 5.0f);

	// Text for Game Score breakdown
	CP_Settings_TextSize(40.0f);

	CP_Font_DrawText("Quiz Score: 300", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 1.875f);
	CP_Font_DrawText("Bonus Score: 200", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 1.67f);
	CP_Font_DrawText("(3 Lives Left)", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 1.55f);

	// Text for Return to Main Menu & Play Again buttons
	CP_Settings_TextSize(35.0f);
	
	CP_Font_DrawText("PLAY AGAIN", (CP_System_GetWindowWidth() / 2.0f) - 200.f, CP_System_GetWindowHeight() / 1.20f);
	CP_Font_DrawText("MAIN MENU", (CP_System_GetWindowWidth() / 2.0f) + 200.f, CP_System_GetWindowHeight() / 1.20f);

	// Check for mouse left click
	if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)) {

		// Play again action
		if (IsAreaClicked((CP_System_GetWindowWidth() / 2.0f - 200.f), CP_System_GetWindowHeight() / 1.20f, 200.f, 100.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {
			CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);
		}
		// Return to main menu action
		else if (IsAreaClicked((CP_System_GetWindowWidth() / 2.0f + 200.f), CP_System_GetWindowHeight() / 1.20f, 200.f, 100.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {
			CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
		}
	}
}

void Win_Exit() {

}
