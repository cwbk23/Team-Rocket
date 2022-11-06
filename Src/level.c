#include "cprocessing.h"
#include "mainmenu.h"
#include "utils.h"
#include <stdbool.h>


#define MOVING_ENEMY_SIZE 3 // NUMBER OF MOVING ENEMIES IN THE LEVEL
#define SIZE_STAT 9 // NUMBER OF STATIONARY PLATFORMS IN THE LEVEL
#define SIZE_MOVE 4 // NUMBER OF MOVING PLATFORMS IN THE LEVEL
#define SIZE_SPIKES 48 // NUMBER OF SPIKES IN THE LEVEL
#define PLAT_SPEED 50.f // GENERAL MOVING SPEED OF THE PLATFORM (FOR TESTING)


///////////////////	YEE LEI	/////////////////////////////

//Game boundary collision points
//float boundary_posY = 1080.0f;

struct PLAYER 
{
	float posX, posY;
	float width, height;
	float moveSpeed, fallSpeed;
	float jumpHeight, jumpSpeed;
	float jumpEnd_posX, jumpEnd_posY;
	bool isJumping, isColliding;
	bool blockLeft, blockRight;
};

struct PLAYER player;


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

struct Enemy enemies[MOVING_ENEMY_SIZE];


//////////////////// KENNY ///////////////////////////

struct platform
{
	float pos_x, pos_y, width, height, rotation, distance, limit, speed;
	char *direction, movement;
}; struct platform stat_plat[SIZE_STAT];
struct platform move_plat[SIZE_MOVE];

struct spike
{
	float x1, y1, x2, y2, x3, y3, deg;
}; struct spike spikes[SIZE_SPIKES];

void Level_Init()
{
	///////////////	YEE LEI	/////////////////
	
	// Player spawn point
	player.posX = 10.0f;
	player.posY = 1000.0f;

	// Initialize player stats
	player.width = 30.0f;
	player.height = 60.0f;
	player.moveSpeed = 250.0f;	// X movement per sec
	player.fallSpeed = 700.0f;
	player.jumpHeight = 200.0f;
	player.jumpSpeed = 800.0f;
	player.blockLeft = FALSE;
	player.blockRight = FALSE;


	
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

	// Initialize variables for moving platform
	move_plat[0].pos_x = 1000.f;
	move_plat[0].pos_y = 200.f;
	move_plat[0].width = 50.f;
	move_plat[0].height = 25.f;
	move_plat[0].rotation = 0.f;
	move_plat[0].direction = "R_L";
	move_plat[0].movement = 'R';
	move_plat[0].speed = PLAT_SPEED;
	move_plat[0].distance = 50.f;
	move_plat[0].limit = 1000.f; // Follows pos_x for left/right and pos_y for up/down

	move_plat[1].pos_x = 1200.f;
	move_plat[1].pos_y = 200.f;
	move_plat[1].width = 50.f;
	move_plat[1].height = 25.f;
	move_plat[1].rotation = 0.f;
	move_plat[1].direction = "D_U";
	move_plat[1].movement = 'D';
	move_plat[1].speed = PLAT_SPEED;
	move_plat[1].distance = 50.f;
	move_plat[1].limit = 200.f; // Follows pos_x for left/right and pos_y for up/down

	move_plat[2].pos_x = 1400.f;
	move_plat[2].pos_y = 200.f;
	move_plat[2].width = 50.f;
	move_plat[2].height = 25.f;
	move_plat[2].rotation = 0.f;
	move_plat[2].direction = "L_R";
	move_plat[2].movement = 'L';
	move_plat[2].speed = PLAT_SPEED;
	move_plat[2].distance = 50.f;
	move_plat[2].limit = 1400.f; // Follows pos_x for left/right and pos_y for up/down

	move_plat[3].pos_x = 1600.f;
	move_plat[3].pos_y = 200.f;
	move_plat[3].width = 50.f;
	move_plat[3].height = 25.f;
	move_plat[3].rotation = 0.f;
	move_plat[3].direction = "U_D";
	move_plat[3].movement = 'U';
	move_plat[3].speed = PLAT_SPEED;
	move_plat[3].distance = 50.f;
	move_plat[3].limit = 200.f; // Follows pos_x for left/right and pos_y for up/down

	// Initialize the spikes variables
	spikes[0].x1 = 20.f;
	spikes[0].y1 = 1030.f;
	spikes[0].x2 = 0.f;
	spikes[0].y2 = 1080.f;
	spikes[0].x3 = 40.f;
	spikes[0].y3 = 1080.f;
	spikes[0].deg = 0.f;



	//////////////////// CLEMENT ///////////////////////

	// INITIALIZE ENEMY VARIABLES
	enemies[0].width = 40.f; enemies[1].width = 40.f; enemies[2].width = 40.f;
	enemies[0].height = 40.f; enemies[1].height = 40.f; enemies[2].height = 40.f;

	enemies[0].enemy_distance = stat_plat[0].width / 2;
	enemies[1].enemy_distance = stat_plat[3].width / 2;
	enemies[2].enemy_distance = stat_plat[5].width / 2;

	enemies[0].enemy_speed = 100.f; enemies[1].enemy_speed = 150.f; enemies[2].enemy_speed = 50.f;

	enemies[0].x_position = stat_plat[0].pos_x + (stat_plat[0].width / 2);
	enemies[1].x_position = stat_plat[3].pos_x + (stat_plat[3].width / 2);
	enemies[2].x_position = stat_plat[5].pos_x + (stat_plat[5].width / 2);

	enemies[0].y_position = stat_plat[0].pos_y - enemies[0].height;
	enemies[1].y_position = stat_plat[3].pos_y - enemies[1].height;
	enemies[2].y_position = stat_plat[5].pos_y - enemies[2].height;

	enemies[0].enemy_direction = _toleft; enemies[1].enemy_direction = _toright; enemies[2].enemy_direction = _toleft;
	
	for (int i = 0; i < MOVING_ENEMY_SIZE; ++i)
	{
		enemies[i].max_x = (enemies[i].enemy_distance + enemies[i].x_position) - enemies[i].width;
		enemies[i].min_x = enemies[i].x_position - enemies[i].enemy_distance;
	}

	
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
	CP_Graphics_DrawRect(player.posX, player.posY, player.width, player.height);

	// TEST PLATFORMS
	/*float plat1X = 100.0f, plat1Y = 950.0f;
	float plat1Width = 200.0f, plat1Height = 50.0f;
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Graphics_DrawRect(plat1X, plat1Y, plat1Width, plat1Height);*/

	// Player left/right controls
	if (CP_Input_KeyDown(KEY_A) && !player.blockLeft) {
		player.posX -= player.moveSpeed * currentElapsedTime;
	}
	if (CP_Input_KeyDown(KEY_D) && !player.blockRight) {
		player.posX += player.moveSpeed * currentElapsedTime;
	}

	// Player jump control
	if (CP_Input_KeyTriggered(KEY_SPACE)) {
		if (!player.isJumping && player.isColliding) {
			player.jumpEnd_posY = player.posY - player.jumpHeight;
			player.isJumping = TRUE;
			player.isColliding = FALSE;
		}
	}

	// Jumping mechanic
	if (player.isJumping) {
		if (player.posY > player.jumpEnd_posY) {
			player.posY -= player.jumpSpeed * currentElapsedTime;

			if (CP_Input_KeyDown(KEY_A) && !player.blockLeft) {
				player.posX -= 50.0f * currentElapsedTime;
			}
			if (CP_Input_KeyDown(KEY_D) && !player.blockRight) {
				player.posX += 50.0f * currentElapsedTime;
			}

			if (player.posY < player.jumpEnd_posY) {
				player.posY = player.jumpEnd_posY;
				player.isJumping = FALSE;
			}
		}
		else {
			player.isJumping = FALSE;
		}
	}

	// Player hit box position
	float playerPosX_left = player.posX, playerPosX_right = player.posX + player.width;
	float playerPosY_top = player.posY, playerPosY_bottom = player.posY + player.height;

	// Reset collision booleans
	player.isColliding = FALSE;
	player.blockLeft = FALSE;
	player.blockRight = FALSE;

	// Window boundary collision checking
	if (playerPosY_bottom >= CP_System_GetWindowHeight()) {
		player.isColliding = TRUE;
		/*if (playerPosY_bottom > boundary_posY) */player.posY = CP_System_GetWindowHeight() - player.height;
		playerPosY_top = player.posY;
		playerPosY_bottom = player.posY + player.height;
	}
	else if (playerPosY_top < 0) {
		player.isJumping = FALSE;
		player.posY = 0;
		playerPosY_top = player.posY;
		playerPosY_bottom = player.posY + player.height;
	}

	if (playerPosX_left < 0) {
		player.posX = 0;
		playerPosX_left = player.posX;
		playerPosX_right = player.posX + player.width;
		player.blockLeft = TRUE;
	}
	else if (playerPosX_right > CP_System_GetWindowWidth()) {
		player.posX = CP_System_GetWindowWidth() - player.width;
		playerPosX_left = player.posX;
		playerPosX_right = player.posX + player.width;
		player.blockRight = TRUE;
	}

	// Store coordinate values of all platforms in an array for processing
	struct platform all_platforms[SIZE_STAT + SIZE_MOVE];
	int platCount = 0;

	for (int i = 0; i < SIZE_STAT; i++, platCount++) {
		all_platforms[platCount].pos_x = stat_plat[i].pos_x;
		all_platforms[platCount].pos_y = stat_plat[i].pos_y;
		all_platforms[platCount].width = stat_plat[i].width;
		all_platforms[platCount].height = stat_plat[i].height;
	}

	for (int i = 0; i < SIZE_MOVE; i++, platCount++) {
		all_platforms[platCount].pos_x = move_plat[i].pos_x;
		all_platforms[platCount].pos_y = move_plat[i].pos_y;
		all_platforms[platCount].width = move_plat[i].width;
		all_platforms[platCount].height = move_plat[i].height;
	}

	// Platform collision checking
	for (int i = 0; i < platCount; i++) {
		float xLeft = all_platforms[i].pos_x, xRight = xLeft + all_platforms[i].width;
		float yTop = all_platforms[i].pos_y, yBottom = yTop + all_platforms[i].height;

		// Block left or right side
		if (playerPosY_bottom > yTop && playerPosY_top < yBottom) {
			if (playerPosX_right > xLeft && playerPosX_left < xLeft && CP_Input_KeyDown(KEY_D)) {
				player.posX = xLeft - player.width;
				playerPosX_left = player.posX;
				playerPosX_right = player.posX + player.width;
				player.blockRight = TRUE;
			}
			else if (playerPosX_left < xRight && playerPosX_right > xRight && CP_Input_KeyDown(KEY_A)) {
				player.posX = xRight;
				playerPosX_left = player.posX;
				playerPosX_right = player.posX + player.width;
				player.blockLeft = TRUE;
			}
		}

		// Block top or bottom
		if (playerPosX_right > xLeft && playerPosX_left < xRight) {
			if (playerPosY_bottom >= yTop && playerPosY_bottom <= yBottom) {

				player.isColliding = TRUE;
				/*if (playerPosY_bottom > yTop) */player.posY = yTop - player.height;
				playerPosY_top = player.posY;
				playerPosY_bottom = player.posY + player.height;
			}
			else if (playerPosY_top < yBottom && playerPosY_top >= yTop && !player.isColliding) {

				player.isJumping = FALSE;
				player.posY = yBottom;
				playerPosY_top = player.posY;
				playerPosY_bottom = player.posY + player.height;
			}
		}
	}

	// Make player fall downwards if not colliding with any platform
	if (!player.isColliding && !player.isJumping) {
		player.posY += player.fallSpeed * currentElapsedTime;
		playerPosY_top = player.posY;
		playerPosY_bottom = player.posY + player.height;
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
	
	// Drawing of all moving platforms
	for (int i = 0; i < SIZE_MOVE; ++i) {
		CP_Graphics_DrawRectAdvanced(move_plat[i].pos_x, move_plat[i].pos_y, move_plat[i].width, move_plat[i].height, move_plat[i].rotation, 0.f);

		// Logic for moving platform right then left
		if (move_plat[i].direction == "R_L") {
			float right_limit = move_plat[i].limit + move_plat[i].distance;

			if (move_plat[i].pos_x <= move_plat[i].limit) { // Check if platform exceeds left limit
				move_plat[i].movement = 'R';
			}
			if (move_plat[i].pos_x >= right_limit) { // Check if platform exceeds right limit
				move_plat[i].movement = 'L';
			}
		}

		// Logic for moving platform left then right
		if (move_plat[i].direction == "L_R") {
			float left_limit = move_plat[i].limit - move_plat[i].distance;

			if (move_plat[i].pos_x >= move_plat[i].limit) { // Check if platform exceeds right limit
				move_plat[i].movement = 'L';
			}
			if (move_plat[i].pos_x <= left_limit) { // Check if platform exceeds left limit
				move_plat[i].movement = 'R';
			}
		}

		// Logic for moving platform down then up
		if (move_plat[i].direction == "D_U") {
			float lower_limit = move_plat[i].limit + move_plat[i].distance;

			if (move_plat[i].pos_y <= move_plat[i].limit) { // Check if platform exceeds upper limit
				move_plat[i].movement = 'D';
			}
			if (move_plat[i].pos_y >= lower_limit) { // Check if platform exceeds lower limit
				move_plat[i].movement = 'U';
			}
		}

		// Logic for moving platform up then down
		if (move_plat[i].direction == "U_D") {
			float upper_limit = move_plat[i].limit - move_plat[i].distance;

			if (move_plat[i].pos_y >= move_plat[i].limit) { // Check if platform exceeds lower limit
				move_plat[i].movement = 'U';
			}
			if (move_plat[i].pos_y <= upper_limit) { // Check if platform exceeds upper limit
				move_plat[i].movement = 'D';
			}
		}

		// Check the direction of the movement and move platform accordingly
		if (move_plat[i].movement == 'L') { // Move left
			move_plat[i].pos_x -= move_plat[i].speed * currentElapsedTime;
		}
		if (move_plat[i].movement == 'R') { // Move right
			move_plat[i].pos_x += move_plat[i].speed * currentElapsedTime;
		}
		if (move_plat[i].movement == 'U') { // Move up
			move_plat[i].pos_y -= move_plat[i].speed * currentElapsedTime;
		}
		if (move_plat[i].movement == 'D') { // Move down
			move_plat[i].pos_y += move_plat[i].speed * currentElapsedTime;
		}
	}

	// Draw 48 spikes at the bottom of the map
	CP_Settings_Fill(color_grey);
	int currentSpike = 0;
	int spikesWanted = 48;
	int size = currentSpike + spikesWanted;

	for (int i = 0; currentSpike < size; ++currentSpike, ++i) {
		spikes[currentSpike].x1 = spikes[0].x1 + (i * 40.f);
		spikes[currentSpike].y1 = spikes[0].y1;
		spikes[currentSpike].x2 = spikes[0].x2 + (i * 40.f);
		spikes[currentSpike].y2 = spikes[0].y2;
		spikes[currentSpike].x3 = spikes[0].x3 + (i * 40.f);
		spikes[currentSpike].y3 = spikes[0].y3;
		CP_Graphics_DrawTriangleAdvanced(spikes[currentSpike].x1, spikes[currentSpike].y1, spikes[currentSpike].x2, spikes[currentSpike].y2, spikes[currentSpike].x3, spikes[currentSpike].y3, spikes[currentSpike].deg);
	}

	//////////////////////////// CLEMENT /////////////////////////////////

	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Color color_white = CP_Color_Create(255, 255, 255, 255); // black color
	CP_Color color_black = CP_Color_Create(0, 0, 0, 255); // white color

	CP_Settings_Fill(color_black);
	CP_Graphics_DrawCircle(200.f, 200.f, bomb_size); //DRAWING OF BOMB ENEMY


	for (int i = 0; i < MOVING_ENEMY_SIZE; ++i) // DRAWING OF THE 3 ENEMIES INITIALIZED
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
	for (int index = 0; index < MOVING_ENEMY_SIZE; ++index)
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

	// COLLISION CHECKING BETWEEN MOVING ENEMIES PLAYERS
	for (int index = 0; index < MOVING_ENEMY_SIZE; ++index)
	{
		if (CollisionCheck(player.posX, player.posY, player.width, player.height, enemies[index].x_position, enemies[index].y_position,
			enemies[index].width, enemies[index].height))
		{
			player.posX = 10.f;
			player.posY = 1000.f;
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
