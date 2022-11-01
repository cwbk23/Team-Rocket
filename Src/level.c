#include "cprocessing.h"
#include "mainmenu.h"
#include "utils.h"
#include <stdbool.h>


#define ENEMY_SIZE 3 // NUMBER OF ENEMIES IN THE LEVEL
#define SIZE_STAT 9 // NUMBER OF STATIONARY PLATFORMS IN THE LEVEL
#define SIZE_SPIKES 48 // NUMBER OF SPIKES IN THE LEVEL


///////////////////	YEE LEI	/////////////////////////////

float playerPosX, playerPosY, playerWidth, playerHeight;
float playerMoveSpeed, playerJumpHeight, playerFallSpeed;
bool playerIsJumping = FALSE, playerCollidingY = TRUE;
float playerJumpEndPointY;
float boundaryFloorY;


/////////////////// CLEMENT //////////////////////////////

int _toleft = 1;
int _toright = 2;

float bomb_size = 100.f;
float bomb_resize = 100.f;

struct Enemy
{
	float x_position, y_position;
	float width, height;
	float enemy_distance, enemy_speed, max_x, min_x;
	int enemy_direction;
};

struct Enemy enemies[ENEMY_SIZE];


//////////////////// KENNY ///////////////////////////

struct platform
{
	float pos_x, pos_y, width, height, rotation, distance, limit;
	int direction, speed;
}; struct platform stat_plat[SIZE_STAT];

struct spike
{
	float x1, y1, x2, y2, x3, y3, deg;
}; struct spike spikes[SIZE_SPIKES];


void Level_Init()
{
	///////////////	YEE LEI	/////////////////
	
	// Player spawn point
	playerPosX = 10.0f;
	playerPosY = 1000.0f;

	// Initialize player stats
	playerWidth = 30.0f;
	playerHeight = 60.0f;
	playerMoveSpeed = 300.0f;	// Point movement per sec
	playerJumpHeight = 200.0f;
	playerFallSpeed = 750.0f;

	// Initialize collision boundary points
	boundaryFloorY = 1080.0f;
	
	
	/////////////  CLEMENT  /////////////////
	
	// INITIALIZE ENEMY VARIABLES
	enemies[0].x_position = 500.f; enemies[1].x_position = 600.f; enemies[2].x_position = 700.f;
	enemies[0].y_position = 500.f; enemies[1].y_position = 700.f; enemies[2].y_position = 800.f;
	enemies[0].width = 40.f; enemies[1].width = 40.f; enemies[2].width = 40.f;
	enemies[0].height = 40.f; enemies[1].height = 40.f; enemies[2].height = 40.f;
	enemies[0].enemy_distance = 500.f; enemies[1].enemy_distance = 300.f; enemies[2].enemy_distance = 400.f;
	enemies[0].enemy_speed = 100.f; enemies[1].enemy_speed = 150.f; enemies[2].enemy_speed = 50.f;
	enemies[0].enemy_direction = _toleft; enemies[1].enemy_direction = _toright; enemies[2].enemy_direction = _toleft;
	for (int i = 0; i < ENEMY_SIZE; ++i)
	{
		enemies[i].max_x = enemies[i].enemy_distance + enemies[i].x_position;
		enemies[i].min_x = enemies[i].x_position - enemies[i].enemy_distance;
	}

	

	///////////////  KENNY  //////////////////
	
	// Initialize stationary platforms variables
	stat_plat[0].pos_x = 0.f;
	stat_plat[0].pos_y = 900.f;
	stat_plat[0].width = 100.f;
	stat_plat[0].height = 30.f;
	stat_plat[0].rotation = 0.f;

	stat_plat[1].pos_x = 200.f;
	stat_plat[1].pos_y = 900.f;
	stat_plat[1].width = 150.f;
	stat_plat[1].height = 30.f;
	stat_plat[1].rotation = 0.f;

	stat_plat[2].pos_x = 400.f;
	stat_plat[2].pos_y = 750.f;
	stat_plat[2].width = 100.f;
	stat_plat[2].height = 30.f;
	stat_plat[2].rotation = 0.f;

	stat_plat[3].pos_x = 550.f;
	stat_plat[3].pos_y = 900.f;
	stat_plat[3].width = 200.f;
	stat_plat[3].height = 30.f;
	stat_plat[3].rotation = 0.f;

	stat_plat[4].pos_x = 850.f;
	stat_plat[4].pos_y = 950.f;
	stat_plat[4].width = 100.f;
	stat_plat[4].height = 30.f;
	stat_plat[4].rotation = 0.f;

	stat_plat[5].pos_x = 1000.f;
	stat_plat[5].pos_y = 850.f;
	stat_plat[5].width = 200.f;
	stat_plat[5].height = 30.f;
	stat_plat[5].rotation = 0.f;

	stat_plat[6].pos_x = 1400.f;
	stat_plat[6].pos_y = 950.f;
	stat_plat[6].width = 100.f;
	stat_plat[6].height = 30.f;
	stat_plat[6].rotation = 0.f;

	stat_plat[7].pos_x = 1550.f;
	stat_plat[7].pos_y = 850.f;
	stat_plat[7].width = 100.f;
	stat_plat[7].height = 30.f;
	stat_plat[7].rotation = 0.f;

	stat_plat[8].pos_x = 1700.f;
	stat_plat[8].pos_y = 750.f;
	stat_plat[8].width = 100.f;
	stat_plat[8].height = 30.f;
	stat_plat[8].rotation = 0.f;

	// Initialize the spikes variables
	spikes[0].x1 = 20.f;
	spikes[0].y1 = 1030.f;
	spikes[0].x2 = 0.f;
	spikes[0].y2 = 1080.f;
	spikes[0].x3 = 40.f;
	spikes[0].y3 = 1080.f;
	spikes[0].deg = 0.f;


}

void Level_Update()
{
	// Sky blue background colour
	CP_Graphics_ClearBackground(CP_Color_Create(135, 206, 250, 255));

	// COMMONLY USED VARIABLES
	// Elapsed time from the last frame
	float currentElapsedTime = CP_System_GetDt();
	static float totalElapsedTime = 0;
	totalElapsedTime += currentElapsedTime;


	///////////////////////	YEE LEI	/////////////////////////////////////////
	
	// Draw player model
	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Settings_Fill(CP_Color_Create(0, 0, 255, 255));
	CP_Graphics_DrawRect(playerPosX, playerPosY, playerWidth, playerHeight);

	// TEST PLATFORMS
	float plat1X = 100.0f, plat1Y = 950.0f;
	float plat1Width = 200.0f, plat1Height = 30.0f;
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Graphics_DrawRect(plat1X, plat1Y, plat1Width, plat1Height);

	// Player left/right controls
	if (CP_Input_KeyDown(KEY_A)) {
		playerPosX -= playerMoveSpeed * currentElapsedTime;
	}
	if (CP_Input_KeyDown(KEY_D)) {
		playerPosX += playerMoveSpeed * currentElapsedTime;
	}

	// Player jump control
	if (CP_Input_KeyTriggered(KEY_SPACE)) {
		if (!playerIsJumping && playerCollidingY) {
			playerJumpEndPointY = playerPosY - playerJumpHeight;
			playerIsJumping = TRUE;
			playerCollidingY = FALSE;
		}
	}

	// Jumping mechanic
	if (playerIsJumping) {
		if (playerPosY > playerJumpEndPointY) {
			playerPosY -= playerJumpHeight * (currentElapsedTime * 5.0f);

			if (playerPosY < playerJumpEndPointY) playerPosY = playerJumpEndPointY;
		}
		else {
			playerIsJumping = FALSE;
		}
	}
	else {
		// Player collision checking
		float playerPosX_left = playerPosX, playerPosX_right = playerPosX + playerWidth;
		float playerPosY_top = playerPosY, playerPosY_bottom = playerPosY + playerHeight;
		playerCollidingY = FALSE;

		// Window boundary checking
		if (playerPosY_bottom >= boundaryFloorY) {
			playerCollidingY = TRUE;

			if (playerPosY_bottom > boundaryFloorY) playerPosY = boundaryFloorY - playerHeight;
		}
		// Platform boundary checking
		else {
			float xLeft = plat1X, xRight = plat1X + plat1Width;
			float yTop = plat1Y, yBottom = plat1Y + plat1Height;

			if (playerPosX_right >= xLeft && playerPosX_left <= xRight && playerPosY_bottom >= yTop && playerPosY_bottom <= yBottom) {
				playerCollidingY = TRUE;

				if (playerPosY_bottom > yTop) playerPosY = yTop - playerHeight;
			}
		}

		// Make player fall downwards if not colliding with any object
		if (!playerCollidingY) {
			playerPosY += playerFallSpeed * currentElapsedTime;
		}
	}

	
	////////////////////// KENNY /////////////////////////
	
	// Draw platforms and spikes settings
	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Color color_brown = (CP_Color_Create(181, 101, 29, 255));
	CP_Color color_grey = (CP_Color_Create(211, 211, 211, 255));

	// Drawing of all stationary platforms
	CP_Settings_Fill(color_brown);
	for (int i = 0; i < SIZE_STAT; ++i) {
		CP_Graphics_DrawRectAdvanced(stat_plat[i].pos_x, stat_plat[i].pos_y, stat_plat[i].width, stat_plat[i].height, stat_plat[i].rotation, 0.f);
	}

	// Draw 48 spikes at the bottom of the map
	CP_Settings_Fill(color_grey);
	int current = 0;
	int spikesWanted = 48;
	int size = current + spikesWanted;

	for (int i = 0; current < size; ++current, ++i) {
		spikes[current].x1 = spikes[0].x1 + (i * 40.f);
		spikes[current].y1 = spikes[0].y1;
		spikes[current].x2 = spikes[0].x2 + (i * 40.f);
		spikes[current].y2 = spikes[0].y2;
		spikes[current].x3 = spikes[0].x3 + (i * 40.f);
		spikes[current].y3 = spikes[0].y3;
		CP_Graphics_DrawTriangleAdvanced(spikes[current].x1, spikes[current].y1, spikes[current].x2, spikes[current].y2, spikes[current].x3, spikes[current].y3, spikes[current].deg);
	}
	//////////////////////////// CLEMENT /////////////////////////////////

	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Color color_white = CP_Color_Create(255, 255, 255, 255); // black color
	CP_Color color_black = CP_Color_Create(0, 0, 0, 255); // white color

	CP_Settings_Fill(color_black);
	CP_Graphics_DrawCircle(200.f, 200.f, bomb_size); //DRAWING OF BOMB ENEMY


	for (int i = 0; i < ENEMY_SIZE; ++i) // DRAWING OF THE 3 ENEMIES INITIALIZED
	{
		CP_Settings_Fill(color_black);
		CP_Graphics_DrawRect(enemies[i].x_position, enemies[i].y_position, enemies[i].width, enemies[i].height);
	}

	if (totalElapsedTime >= 1.f) // CIRCLE EXPANDING (SIMULATE EXPLOSION)
	{
		bomb_size += bomb_resize * currentElapsedTime;
	}
	if (bomb_size >= 200.f) // CIRCLE DISAPPEARS AFTER EXPLODING
	{
		bomb_size = 0;
		bomb_resize = 0;
	}

	// LOGIC FOR MOVING ENEMIES TO MOVE LEFT AND RIGHT
	for (int index = 0; index < ENEMY_SIZE; ++index)
	{
		if (enemies[index].enemy_direction == _toright) // ENEMY MOVES TO THE RIGHT
		{
			enemies[index].x_position += enemies[index].enemy_speed * currentElapsedTime;
		}
		if (enemies[index].enemy_direction == _toleft)// ENEMY MOVES TO THE LEFT
		{
			enemies[index].x_position -= enemies[index].enemy_speed * currentElapsedTime;
		}


		if (enemies[index].x_position <= enemies[index].min_x) // WHEN ENEMY REACHES MINIMUM X POSITION
		{
			enemies[index].enemy_direction = _toright;
		}

		if (enemies[index].x_position >= enemies[index].max_x) // WHEN ENEMY REACHES THE MAXIMUN X POSITION
		{
			enemies[index].enemy_direction = _toleft;
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	

	// Exit to main menu if ESC key pressed
	if (CP_Input_KeyTriggered(KEY_ESCAPE)) {
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void Level_Exit()
{
	
}
