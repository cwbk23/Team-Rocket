#include "cprocessing.h"
#include "mainmenu.h"


CP_Image logo;


void splash_screen_init(void)
{
	// Run game in full screen at fixed 1920x1080
	CP_System_FullscreenAdvanced(1920, 1080);
	CP_System_SetFrameRate(60.0f);

	// Load Digipen logo image
	logo = CP_Image_Load("Assets/DigiPen_BLACK.png");
	CP_Settings_ImageMode(CP_POSITION_CENTER);
	CP_Settings_ImageWrapMode(CP_IMAGE_WRAP_CLAMP);
}

void splash_screen_update(void)
{
	// Fade in splashscreen for a few sec before initializing main menu state
	float currentElapsedTime = CP_System_GetDt();
	static float totalElapsedTime = 0;
	totalElapsedTime += currentElapsedTime;
	int transparency = (int)(totalElapsedTime * (255 / 3.0f));

	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	CP_Image_Draw(logo, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, (float)CP_Image_GetWidth(logo), (float)CP_Image_GetHeight(logo), transparency);

	// Call main menu state after 3.5 sec
	if (totalElapsedTime >= 3.5) {
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void splash_screen_exit(void)
{
	CP_Image_Free(&logo);
}
