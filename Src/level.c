#include "cprocessing.h"
#include "mainmenu.h"
#include "utils.h"
#define ENEMY_SIZE 3 // NUMBER OF ENEMIES IN THE LEVEL

/////////////////// CLEMENT //////////////////////////////

int _toleft = 1;
int _toright = 2;

float circle_size = 100.f;
float circle_resize = 100.f;
float speed_adjust = 10.f; // ENEMY SPEED VARIABLE

struct Enemy
{
	float x_position, y_position;
	float width, height;
	float max_x, min_x;
};

struct Enemy enemies[ENEMY_SIZE];
int enemy_direction[ENEMY_SIZE];// DIRECTION VARIABLE FOR EACH ENEMY

/////////////////////////////////////////////////////////

void Level_Init()
{
	/////////////CLEMENT/////////////////
	// INITIALIZE ENEMY VARIABLES
	enemies[0].x_position = 500.f; enemies[1].x_position = 300.f; enemies[2].x_position = 200.f;
	enemies[0].y_position = 500.f; enemies[1].y_position = 700.f; enemies[2].y_position = 800.f;
	enemies[0].width = 50.f; enemies[1].width = 50.f; enemies[2].width = 50.f;
	enemies[0].height = 50.f; enemies[1].height = 50.f; enemies[2].height = 50.f;
	enemies[0].min_x = 500.f; enemies[1].min_x = 300.f; enemies[2].min_x = 400.f;
	enemies[0].max_x = 1000.f; enemies[1].max_x = 1200.f; enemies[2].max_x = 800.f;
	/////////////////////////////////////
	
}

void Level_Update()
{
	// Sky blue background colour
	CP_Graphics_ClearBackground(CP_Color_Create(135, 206, 250, 255));

	// Test
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Graphics_DrawRect(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 25.0f, 25.0f);
	
	// Kenny
	// Set starting point of rectangles
	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Graphics_DrawRectAdvanced(CP_System_GetWindowWidth() / 12.8f, CP_System_GetWindowHeight() / 7.2f, 50.f, 20.f, 90.f, 0.f);
	


	//////////////////////////// CLEMENT /////////////////////////////////

	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Color color_white = CP_Color_Create(255, 255, 255, 255); // black color
	CP_Color color_black = CP_Color_Create(0, 0, 0, 255); // white color

	float currentElapsedTime = CP_System_GetDt();
	static float totalElapsedTime = 0;
	totalElapsedTime += currentElapsedTime;

	CP_Settings_Fill(color_black);
	CP_Graphics_DrawCircle(200.f, 200.f, circle_size); //DRAWING OF BOMB ENEMY

	for (int i = 0; i < ENEMY_SIZE; ++i) // DRAWING OF THE 3 ENEMIES INITIALIZED
	{
		CP_Settings_Fill(color_black);
		CP_Graphics_DrawRect(enemies[i].x_position, enemies[i].y_position, enemies[i].width, enemies[i].height);
	}

	if (totalElapsedTime >= 1.f) // CIRCLE EXPANDING (SIMULATE EXPLOSION)
	{
		circle_size += circle_resize * currentElapsedTime;
	}
	if (circle_size >= 200.f) // CIRCLE DISAPPEARS AFTER EXPLODING
	{
		circle_size = 0;
		circle_resize = 0;
	}

	// LOGIC FOR MOVING ENEMIES TO MOVE LEFT AND RIGHT
	for (int index = 0; index < ENEMY_SIZE; ++index)
	{
		if (enemies[index].x_position <= enemies[index].min_x) // WHEN ENEMY REACHES MINIMUM X POSITION
		{
			enemy_direction[index] = _toright;
		}

		if (enemies[index].x_position >= enemies[index].max_x) // WHEN ENEMY REACHES THE MAXIMUN X POSITION
		{
			enemy_direction[index] = _toleft;
		}


		if (enemy_direction[index] == _toright) // ENEMY MOVES TO THE RIGHT
		{
			enemies[index].x_position += (speed_adjust * 10) * currentElapsedTime;
		}
		if (enemy_direction[index] == _toleft)// ENEMY MOVES TO THE LEFT
		{
			enemies[index].x_position -= (speed_adjust * 10) * currentElapsedTime;
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	

	// Exit game if press ESC key
	if (CP_Input_KeyTriggered(KEY_ESCAPE)) {
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void Level_Exit()
{
	
}
