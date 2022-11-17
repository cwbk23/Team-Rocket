#include "cprocessing.h"
#include "utils.h"
#include "mainmenu.h"
#include "level.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


struct BOXES {
	float pos_x, pos_y, width, height;
}; 
	
bool NEW_HIGHSCORE;

//errno_t err_HS;
//FILE *highscore_file;

// Text to be printed on Win screen
char new_highscore_text[50];
char highscore_text[50];
char gamescore_text[50];
char quizscore_text[50];
char bonusscore_text[30];
char lives_left_text[30];

//char highscore_string[20]; // String to hold the highscore from text file
//char *HS_string = 0;

int game_score, bonus_score;
//int highscore_num;
highscore = 0;

void Win_Init() {

	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	NEW_HIGHSCORE = FALSE;
	
	//HS_string = &highscore_string;
	//err_HS = fopen_s(&highscore_file, "Assets/Highscore.txt", "w+"); // Open file
	//
	//if (err_HS == 0) {
	//	//HS_string = fgets(highscore_string, 20, highscore_file);
	//	//highscore_num = atoi(HS_string);
	//	//
	//	//if (highscore_num == NULL) {
	//	//	highscore_num = 69;
	//	//}
	//
	//	highscore_num = 69;
	//}
	//else {
	//	highscore_num = 500;
	//}
}

void Win_Update() {

	// Emerald green background colour
	CP_Graphics_ClearBackground(CP_Color_Create(0, 153, 51, 255));
	CP_Color color_white = (CP_Color_Create(255, 255, 255, 255));
	CP_Color color_blue = (CP_Color_Create(0, 102, 255, 255));
	CP_Color color_darkgrey = (CP_Color_Create(128, 128, 128, 255));
	CP_Color color_gold = (CP_Color_Create(255, 215, 0, 255));

	// Return to main menu button
	CP_Settings_Fill(color_darkgrey);
	CP_Graphics_DrawRectAdvanced((CP_System_GetWindowWidth() / 2.0f) - 200.f, CP_System_GetWindowHeight() / 1.20f, 200.f, 100.f, 0.f, 10.f);

	// Play again button
	CP_Graphics_DrawRectAdvanced((CP_System_GetWindowWidth() / 2.0f) + 200.f, CP_System_GetWindowHeight() / 1.20f, 200.f, 100.f, 0.f, 10.f);


	// Calculate and compare current game score with previous highscore
	bonus_score = (playerLives - 1) * 10;
	game_score = quiz_score + bonus_score;
	//highscore_num = 0;
	// Retrieve previous highscore from highscore text file


	// Compare scores

	if (game_score > highscore) {
		
		NEW_HIGHSCORE = TRUE;

		//if (err_HS == 0) {
		//	rewind(highscore_file); // Set pointer to beginning of file
		//	//fseek(highscore_file, 0L, SEEK_SET);
		//	sprintf_s(highscore_string, 20, "%d", game_score);
		//	fprintf_s(highscore_file, "%s", highscore_string);
		//
		//	//fprintf_s(highscore_file, "%d", game_score); // Write data to file
		//}

		highscore = game_score;

	}
	
	// Texts to be drawn 
	sprintf_s(new_highscore_text, 50, "NEW HIGH SCORE: %ld", game_score);
	sprintf_s(gamescore_text, 50, "Total Score: %ld", game_score);
	sprintf_s(highscore_text, 50, "High Score: %ld", highscore);
	sprintf_s(quizscore_text, 50, "Quiz Score: %d", quiz_score);
	sprintf_s(bonusscore_text, 30, "Bonus Score: %ld", bonus_score);
	sprintf_s(lives_left_text, 30, "(%d Lives Left)", playerLives);

	// Draw and display score boxes
	CP_Settings_TextSize(70.0f);
	if (NEW_HIGHSCORE == TRUE) {

		CP_Settings_Fill(color_gold);

		// Display new highscore
		CP_Font_DrawText(new_highscore_text, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.45f);
		
		//NEW_HIGHSCORE = FALSE;
	
	} else {

		CP_Settings_Fill(color_gold);

		// Display final game score
		CP_Font_DrawText(gamescore_text, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.75f);
		
		CP_Settings_Fill(color_white);

		// Display previous highscore
		CP_Font_DrawText(highscore_text, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.25f);
	}
		
	CP_Settings_Fill(color_white);

	// Text for Victory message
	CP_Settings_TextSize(150.0f);

	CP_Font_DrawText("VICTORY", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 5.0f);

	// Text for Game Score breakdown
	CP_Settings_TextSize(50.0f);

	CP_Font_DrawText(quizscore_text, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 1.825f);
	CP_Font_DrawText(bonusscore_text, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 1.625f);
	CP_Font_DrawText(lives_left_text, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 1.475f);

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

	//fclose(highscore_file); // Close Highscore.txt
	quiz_score = 0;
	checkpoint_no = -1;
}
