/*---------------------------------------------------------------
Math Run by Team Rocket
Class: CSD1401A Fall 2022
File: mainmenu.c
Authors: Low Yee Lei, yeelei.low@digipen.edu

Description:
Game Main Menu with title and buttons to start game, how to play, credits 
and exit game.


Copyright: 2022, Digipen Institute of Technology, Singapore
----------------------------------------------------------------*/

#include "cprocessing.h"
#include "level.h"
#include "utils.h"
#include "quiz.h"
#include "credits.h"
#include "howtoplay.h"


// Menu music
CP_Sound menuMusic;

// Menu images
CP_Image img_plus_black;
CP_Image img_minus_black;
CP_Image img_times_black;
CP_Image img_equal_black;

CP_Font titleFont;


void Main_Menu_Init()
{	
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	// Images
	img_plus_black = CP_Image_Load("Assets/plus_black.png");
	img_minus_black = CP_Image_Load("Assets/minus_black.png");
	img_times_black = CP_Image_Load("Assets/cross_black.png");
	img_equal_black = CP_Image_Load("Assets/equal_black.png");
	
	CP_Settings_ImageMode(CP_POSITION_CENTER);
	CP_Settings_ImageWrapMode(CP_IMAGE_WRAP_CLAMP);

	// Menu Title font
	titleFont = CP_Font_Load("Assets/Kenney_Future_Narrow.ttf");

	// Reset checkpoint and score
	checkpoint_no = -1;
	quiz_score = 0;

	// Stop level music
	playlevelmusic = 0;
	CP_Sound_Free(&levelMusic);

	// Play menu music
	menuMusic = CP_Sound_LoadMusic("Assets/menu_music.wav");
	CP_Sound_PlayMusic(menuMusic);
}

void Main_Menu_Update()
{
	// Sky blue background colour
	CP_Graphics_ClearBackground(CP_Color_Create(135, 206, 235, 255));

	// Icon images
	CP_Image_DrawAdvanced(img_plus_black, (CP_System_GetWindowWidth() / 2.0f) - 700.0f, (CP_System_GetWindowHeight() / 2.0f) - 350.0f, 200.0f, 200.0f, 255, -10.0f);
	CP_Image_DrawAdvanced(img_minus_black, (CP_System_GetWindowWidth() / 2.0f) - 650.0f, (CP_System_GetWindowHeight() / 2.0f) - 100.0f, 200.0f, 200.0f, 255, -10.0f);
	CP_Image_DrawAdvanced(img_times_black, (CP_System_GetWindowWidth() / 2.0f) + 700.0f, (CP_System_GetWindowHeight() / 2.0f) - 350.0f, 170.0f, 170.0f, 255, 10.0f);
	CP_Image_DrawAdvanced(img_equal_black, (CP_System_GetWindowWidth() / 2.0f) + 650.0f, (CP_System_GetWindowHeight() / 2.0f) - 100.0f, 170.0f, 170.0f, 255, 10.0f);

	// Game title
	CP_Font_Set(titleFont);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(200.0f);
	CP_Font_DrawText("MATH RUN", CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) - 250.0f);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(210.0f);
	CP_Font_DrawText("MATH RUN", CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) - 260.0f);

	// Reset font
	CP_Font_Set(CP_Font_GetDefault());

	// Play button
	CP_Settings_Fill(CP_Color_Create(0, 102, 255, 255));
	CP_Graphics_DrawRectAdvanced(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, 160.0f, 55.0f, 0.0f, 5.0f);

	// How To Play button
	CP_Settings_Fill(CP_Color_Create(255, 69, 0, 255));
	CP_Graphics_DrawRectAdvanced(CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 100.0f, 160.0f, 55.0f, 0.0f, 5.0f);

	// Credits button
	CP_Settings_Fill(CP_Color_Create(0, 153, 51, 255));
	CP_Graphics_DrawRectAdvanced(CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 200.0f, 160.0f, 55.0f, 0.0f, 5.0f);

	// Exit button
	CP_Settings_Fill(CP_Color_Create(128, 128, 128, 255));
	CP_Graphics_DrawRectAdvanced(CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 300.0f, 160.0f, 55.0f, 0.0f, 5.0f);
	

	// Buttons text
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(25.0f);
	CP_Font_DrawText("START GAME", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f);
	CP_Font_DrawText("HOW TO PLAY", CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 100.0f);
	CP_Font_DrawText("CREDITS", CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 200.0f);
	CP_Font_DrawText("EXIT GAME", CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 300.0f);


	// Check for mouse left click
	if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)) {

		// Start game
		if (IsAreaClicked(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, 160.0f, 55.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

			CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);
		}
		// How to play screen
		else if (IsAreaClicked(CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 100.0f, 160.0f, 55.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

			CP_Engine_SetNextGameState(HowToPlay_Init, HowToPlay_Update, HowToPlay_Exit);
		}
		// Credits screen
		else if (IsAreaClicked(CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 200.0f, 160.0f, 55.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

			CP_Engine_SetNextGameState(Credits_Init, Credits_Update, Credits_Exit);
		}
		// Exit game
		else if (IsAreaClicked(CP_System_GetWindowWidth() / 2.0f, (CP_System_GetWindowHeight() / 2.0f) + 300.0f, 160.0f, 55.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

			CP_Engine_Terminate();
		}
	}
}

void Main_Menu_Exit()
{
	CP_Sound_Free(&menuMusic);

	CP_Image_Free(&img_plus_black);
	CP_Image_Free(&img_minus_black);
	CP_Image_Free(&img_times_black);
	CP_Image_Free(&img_equal_black);
}
