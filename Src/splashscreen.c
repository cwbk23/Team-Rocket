#include "cprocessing.h"
#include "mainmenu.h"


CP_Image logo;

void splash_screen_init(void)
{
	CP_System_Fullscreen();
	//CP_System_SetWindowSize(CP_System_GetDisplayWidth(), CP_System_GetDisplayHeight());
	//CP_System_SetWindowSize(1920, 1080);
	CP_System_SetFrameRate(60.0f);

	logo = CP_Image_Load("Assets/DigiPen_BLACK.png");
	CP_Settings_ImageMode(CP_POSITION_CENTER);
	CP_Settings_ImageWrapMode(CP_IMAGE_WRAP_CLAMP);
}

void splash_screen_update(void)
{
	// Display splashscreen for a few seconds before initializing main menu state
	float currentElapsedTime = CP_System_GetDt();
	static float totalElapsedTime = 0;
	totalElapsedTime += currentElapsedTime;
	int transparency = totalElapsedTime * (255 / 2.0f);

	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	CP_Image_Draw(logo, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, CP_Image_GetWidth(logo), CP_Image_GetHeight(logo), transparency);

	// Call main menu state after 2.5 sec
	if (totalElapsedTime >= 2.5) {
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void splash_screen_exit(void)
{
	CP_Image_Free(&logo);
}
