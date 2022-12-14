/*---------------------------------------------------------------
Math Run by Team Rocket
Class: CSD1401A Fall 2022
File: level.c
Authors: Low Yee Lei, yeelei.low@digipen.edu
		 Chua Wen Bin Kenny, c.wenbinkenny@digipen.edu
		 Tan Wei Jie Clement, weijieclement.tan@digipen.edu

Description:
Yee Lei - Player creation, movement controls, normal and charged jump, 
falling, collision blocking with boundary and platforms, death and respawning, 
lives HUD, score HUD, lose logic, player sound effects.

Kenny - Drawing of stationary, moving platforms, and blockers. Moving 
platform logic, drawing of spikes, checkpoints, and endpoint. Checkpoint 
collision and logic, endpoint collision and win logic.

Clement - Bomb enemy creation, Moving enemy creation, Shooting enemy and bullet creation,
Enemy movement logic, Bullet movement logic, Collision checking between player and enemy entities,
Sound effects for all enemies.


Copyright: 2022, Digipen Institute of Technology, Singapore
----------------------------------------------------------------*/

#include "cprocessing.h"
#include "mainmenu.h"
#include "utils.h"
#include "quiz.h"
#include "level.h"
#include "lose.h"
#include "win.h"
#include <stdbool.h>
#include <stdio.h>


#define MOVING_ENEMY_SIZE 3 // NUMBER OF MOVING ENEMIES IN THE LEVEL
#define BOMB_ENEMY_SIZE 3 // NUMBER OF BOMB ENEMIES IN THE LEVEL
#define SHOOTING_ENEMY_SIZE 2 // NUMBER OF SHOOTING ENEMIES IN THE LEVEL
#define BULLET_SIZE 10 // NUMBER OF BULLETS FOR EACH ENEMY
#define SIZE_STAT 18 // NUMBER OF STATIONARY PLATFORMS IN THE LEVEL
#define SIZE_MOVE 7 // NUMBER OF MOVING PLATFORMS IN THE LEVEL
#define SIZE_BLOCKER 3 // NUMBER OF BLOCKER PLATFORMS IN THE LEVEL
#define SIZE_SPIKES 132 // NUMBER OF SPIKES IN THE LEVEL
#define SIZE_CHECKPOINTS 3 // NUMBER OF CHECKPOINTS IN THE LEVEL
#define PLAT_SPEED 50.f // GENERAL MOVING SPEED OF THE PLATFORM (FOR TESTING)


///////////////////	YEE LEI	/////////////////////////////

// Player sounds
CP_Sound sound_jump;
CP_Sound sound_death;

// Player character models
CP_Image player_stand_right;
CP_Image player_stand_left;
CP_Image player_jump_right;
CP_Image player_jump_left;
CP_Image player_down_left;
CP_Image player_down_right;

// Player lives heart icons
CP_Image heart_full;
CP_Image heart_empty;

// Mouse left click icon
CP_Image mouse_left;

// Default no. of player lives
int totalLives = 5;
playerLives = 5;	// EXTERN INT

// Jump charge settings
const float jumpChargeMax = 1.5f;
float jumpCharge = 1.0f;

// Initialize starting checkpoint (-1 means new game)
int current_checkpoint = -1;

// Initialize quiz score
quiz_score = 0;		// EXTERN INT


struct PLAYER 
{
	float posX, posY;
	float width, height;
	float moveSpeed, fallSpeed;
	float jumpHeight, jumpSpeed;
	float jumpEnd_posX, jumpEnd_posY;
	bool alive;
	bool isJumping, isColliding;
	bool blockLeft, blockRight, blockJump;
};

struct PLAYER player;


/////////////////// CLEMENT //////////////////////////////

CP_Image BombEnemy;
CP_Image MovingEnemyLeft, MovingEnemyRight;
CP_Image ExplosionSmall, ExplosionMedium, ExplosionLarge;
CP_Image TurretLeft, TurretRight;
CP_Image BulletLeft, BulletRight;

CP_Sound BulletSound = NULL;
CP_Sound ExplosionSound = NULL;

enum {MOVE_RIGHT, MOVE_LEFT};

struct Enemy
{
	float x_position, y_position;
	float width, height;
	float enemy_distance, enemy_speed, max_x, min_x;
	int enemy_direction;
	bool enemy_draw, explosion_draw;
	float bullet_totalElapsedTime, explosion_totalElapsedTime;
};

struct Bullet
{
	float bullet_startX, bullet_startY;
	float bullet_x, bullet_y;

	float bullet_width, bullet_height;
	float bullet_speed, bullet_timeBetween;

	bool bullet_move;
	char bullet_direction;
};

struct Enemy mov_enemies[MOVING_ENEMY_SIZE];

struct Enemy bomb_enemies[BOMB_ENEMY_SIZE];

struct Enemy shooting_enemies[SHOOTING_ENEMY_SIZE];

struct Bullet bullet[SHOOTING_ENEMY_SIZE][BULLET_SIZE];


//////////////////// KENNY ///////////////////////////

enum {
	RIGHT_LEFT, LEFT_RIGHT, DOWN_UP, UP_DOWN, // Types of directions 
	LEFT, RIGHT, DOWN, UP // Movement directions
};

struct PLATFORMS
{
	float pos_x, pos_y;
	float width, height;
	float rotation, distance, limit, speed;
	int direction, movement;
}; struct PLATFORMS stat_plat[SIZE_STAT], move_plat[SIZE_MOVE], blocker_plat[SIZE_BLOCKER];

struct SPIKES
{
	float x1, y1, x2, y2, x3, y3, deg;
}; struct SPIKES spikes[SIZE_SPIKES];

struct CHECKPOINTS {
	float pos_x, pos_y;
	float width, height;
}; struct CHECKPOINTS checkpoint[SIZE_CHECKPOINTS], checkpoint_hitbox[SIZE_CHECKPOINTS];
struct CHECKPOINTS endpoint, endpoint_hitbox;

// Initialize checkpoint number to 0
checkpoint_no = 0;

// Declaration of images and sounds
CP_Image CPoint, EPoint;
CP_Sound levelMusic, checkpointSound;

// Initialize playing level music to 0
playlevelmusic = 0;


void Level_Init()
{
	///////////////	YEE LEI	/////////////////
	
	// Initialize player stats
	player.width = 60.0f;
	player.height = 60.0f;
	player.moveSpeed = 200.0f;
	player.jumpHeight = 160.0f;
	player.jumpSpeed = 15.0f;
	player.alive = TRUE;
	player.isColliding = FALSE;
	player.isJumping = FALSE;
	player.blockLeft = FALSE;
	player.blockRight = FALSE;
	player.blockJump = FALSE;

	player_stand_left = CP_Image_Load("Assets/player_stand_left.png");
	player_stand_right = CP_Image_Load("Assets/player_stand_right.png");
	player_jump_left = CP_Image_Load("Assets/player_jump_left.png");
	player_jump_right = CP_Image_Load("Assets/player_jump_right.png");
	player_down_left = CP_Image_Load("Assets/player_down_left.png");
	player_down_right = CP_Image_Load("Assets/player_down_right.png");

	heart_full = CP_Image_Load("Assets/hudHeart_full.png");
	heart_empty = CP_Image_Load("Assets/hudHeart_empty.png");
	mouse_left = CP_Image_Load("Assets/mouseLeft.png");

	sound_jump = CP_Sound_LoadMusic("Assets/jump.ogg");
	sound_death = CP_Sound_LoadMusic("Assets/death.ogg");
	

	///////////////  KENNY  //////////////////

	// Load images for checkpoint and endpoint
	CPoint = CP_Image_Load("Assets/Checkpoint.png");
	EPoint = CP_Image_Load("Assets/Endpoint.png");

	// Load music/sound
	levelMusic = CP_Sound_LoadMusic("Assets/level_music.wav");
	checkpointSound = CP_Sound_LoadMusic("Assets/checkpoint_sound.ogg");

	if (playlevelmusic == 0) {
		playlevelmusic = 1;
		CP_Sound_PlayMusic(levelMusic);
	}
	
	// Initialize stationary platforms variablesw
	stat_plat[0].pos_x = 0.f;
	stat_plat[0].pos_y = 1000.f;
	stat_plat[0].width = 150.f;
	stat_plat[0].height = 30.f;
	stat_plat[0].rotation = 0.f;

	stat_plat[1].pos_x = 500.f;
	stat_plat[1].pos_y = 1000.f;
	stat_plat[1].width = 300.f;
	stat_plat[1].height = 30.f;
	stat_plat[1].rotation = 0.f;

	stat_plat[2].pos_x = 1100.f;
	stat_plat[2].pos_y = 900.f;
	stat_plat[2].width = 150.f;
	stat_plat[2].height = 30.f;
	stat_plat[2].rotation = 0.f;

	stat_plat[3].pos_x = 1350.f;
	stat_plat[3].pos_y = 1000.f;
	stat_plat[3].width = 300.f;
	stat_plat[3].height = 30.f;
	stat_plat[3].rotation = 0.f;

	stat_plat[4].pos_x = 1650.f;
	stat_plat[4].pos_y = 910.f;
	stat_plat[4].width = 120.f;
	stat_plat[4].height = 30.f;
	stat_plat[4].rotation = 0.f;
	
	stat_plat[5].pos_x = 1770.f;
	stat_plat[5].pos_y = 815.f;
	stat_plat[5].width = 150.f;
	stat_plat[5].height = 30.f;
	stat_plat[5].rotation = 0.f;
	
	stat_plat[6].pos_x = 0.f; // Platform for 2nd floor
	stat_plat[6].pos_y = 710.f;
	stat_plat[6].width = 1720.f;
	stat_plat[6].height = 20.f;
	stat_plat[6].rotation = 0.f;
	
	stat_plat[7].pos_x = 1570.f;
	stat_plat[7].pos_y = 630.f;
	stat_plat[7].width = 150.f;
	stat_plat[7].height = 30.f;
	stat_plat[7].rotation = 0.f;
	
	stat_plat[8].pos_x = 770.f;
	stat_plat[8].pos_y = 580.f;
	stat_plat[8].width = 300.f;
	stat_plat[8].height = 30.f;
	stat_plat[8].rotation = 0.f;

	stat_plat[9].pos_x = 370.f;
	stat_plat[9].pos_y = 630.f;
	stat_plat[9].width = 300.f;
	stat_plat[9].height = 30.f;
	stat_plat[9].rotation = 0.f;

	stat_plat[10].pos_x = 210.f;
	stat_plat[10].pos_y = 530.f;
	stat_plat[10].width = 100.f;
	stat_plat[10].height = 30.f;
	stat_plat[10].rotation = 0.f;

	stat_plat[11].pos_x = 0.f;
	stat_plat[11].pos_y = 445.f;
	stat_plat[11].width = 150.f;
	stat_plat[11].height = 30.f;
	stat_plat[11].rotation = 0.f;

	stat_plat[12].pos_x = 200.f; // Platform for 3rd floor
	stat_plat[12].pos_y = 340.f;
	stat_plat[12].width = 1720.f;
	stat_plat[12].height = 20.f;
	stat_plat[12].rotation = 0.f;

	stat_plat[13].pos_x = 500.f;
	stat_plat[13].pos_y = 260.f;
	stat_plat[13].width = 300.f;
	stat_plat[13].height = 30.f;
	stat_plat[13].rotation = 0.f;

	stat_plat[14].pos_x = 1050.f;
	stat_plat[14].pos_y = 210.f;
	stat_plat[14].width = 150.f;
	stat_plat[14].height = 30.f;
	stat_plat[14].rotation = 0.f;

	stat_plat[15].pos_x = 1500.f; // Victory platform
	stat_plat[15].pos_y = 260.f;
	stat_plat[15].width = 420.f;
	stat_plat[15].height = 30.f;
	stat_plat[15].rotation = 0.f;

	stat_plat[16].pos_x = 1680.f; // 2nd floor platform connector
	stat_plat[16].pos_y = 660.f;
	stat_plat[16].width = 40.f;
	stat_plat[16].height = 50.f;
	stat_plat[16].rotation = 0.f;

	stat_plat[17].pos_x = 200.f; // 3rd floor platform connector
	stat_plat[17].pos_y = 290.f;
	stat_plat[17].width = 40.f;
	stat_plat[17].height = 50.f;
	stat_plat[17].rotation = 0.f;

	// Initialize variables for blocker platforms

	blocker_plat[0].pos_x = 1720.f; // 2nd level blocker
	blocker_plat[0].pos_y = 710.f;
	blocker_plat[0].width = 200.f;
	blocker_plat[0].height = 20.f;
	blocker_plat[0].rotation = 0.f;

	blocker_plat[1].pos_x = 0.f; // 3rd level blocker
	blocker_plat[1].pos_y = 340.f;
	blocker_plat[1].width = 200.f;
	blocker_plat[1].height = 20.f;
	blocker_plat[1].rotation = 0.f;

	blocker_plat[2].pos_x = 1520.f; // Victory platform blocker
	blocker_plat[2].pos_y = 0.f;
	blocker_plat[2].width = 260.f;
	blocker_plat[2].height = 20.f;
	blocker_plat[2].rotation = 90.f;

	// Initialize variables for moving platform
	move_plat[0].pos_x = 250.f;
	move_plat[0].pos_y = 1000.f;
	move_plat[0].width = 100.f;
	move_plat[0].height = 30.f;
	move_plat[0].rotation = 0.f;
	move_plat[0].direction = RIGHT_LEFT;
	move_plat[0].movement = RIGHT;
	move_plat[0].speed = PLAT_SPEED;
	move_plat[0].distance = 50.f;
	move_plat[0].limit = 250.f; // Follows value from pos_x for left/right and pos_y for up/down

	move_plat[1].pos_x = 900.f;
	move_plat[1].pos_y = 1000.f;
	move_plat[1].width = 100.f;
	move_plat[1].height = 30.f;
	move_plat[1].rotation = 0.f;
	move_plat[1].direction = UP_DOWN;
	move_plat[1].movement = UP;
	move_plat[1].speed = PLAT_SPEED;
	move_plat[1].distance = 100.f;
	move_plat[1].limit = 1000.f;

	move_plat[2].pos_x = 1420.f;
	move_plat[2].pos_y = 530.f;
	move_plat[2].width = 100.f;
	move_plat[2].height = 30.f;
	move_plat[2].rotation = 0.f;
	move_plat[2].direction = LEFT_RIGHT;
	move_plat[2].movement = LEFT;
	move_plat[2].speed = PLAT_SPEED;
	move_plat[2].distance = 100.f;
	move_plat[2].limit = 1420.f;
	
	move_plat[3].pos_x = 1170.f;
	move_plat[3].pos_y = 630.f;
	move_plat[3].width = 100.f;
	move_plat[3].height = 30.f;
	move_plat[3].rotation = 0.f;
	move_plat[3].direction = UP_DOWN;
	move_plat[3].movement = UP;
	move_plat[3].speed = PLAT_SPEED;
	move_plat[3].distance = 100.f;
	move_plat[3].limit = 630.f;

	move_plat[4].pos_x = 200.f;
	move_plat[4].pos_y = 260.f;
	move_plat[4].width = 100.f;
	move_plat[4].height = 30.f;
	move_plat[4].rotation = 0.f;
	move_plat[4].direction = RIGHT_LEFT;
	move_plat[4].movement = RIGHT;
	move_plat[4].speed = PLAT_SPEED;
	move_plat[4].distance = 100.f;
	move_plat[4].limit = 200.f;

	move_plat[5].pos_x = 850.f;
	move_plat[5].pos_y = 260.f;
	move_plat[5].width = 100.f;
	move_plat[5].height = 30.f;
	move_plat[5].rotation = 0.f;
	move_plat[5].direction = UP_DOWN;
	move_plat[5].movement = UP;
	move_plat[5].speed = PLAT_SPEED;
	move_plat[5].distance = 150.f;
	move_plat[5].limit = 260.f; 

	move_plat[6].pos_x = 1300.f;
	move_plat[6].pos_y = 110.f;
	move_plat[6].width = 100.f;
	move_plat[6].height = 30.f;
	move_plat[6].rotation = 0.f;
	move_plat[6].direction = DOWN_UP;
	move_plat[6].movement = DOWN;
	move_plat[6].speed = PLAT_SPEED;
	move_plat[6].distance = 150.f;
	move_plat[6].limit = 110.f; 

	// Initialize the spikes variables
	spikes[0].x1 = 20.f;
	spikes[0].y1 = 1050.f;
	spikes[0].x2 = 0.f;
	spikes[0].y2 = 1080.f;
	spikes[0].x3 = 40.f;
	spikes[0].y3 = 1080.f;
	spikes[0].deg = 0.f;

	spikes[48].x1 = 20.f;
	spikes[48].y1 = 680.f;
	spikes[48].x2 = 0.f;
	spikes[48].y2 = 710.f;
	spikes[48].x3 = 40.f;
	spikes[48].y3 = 710.f;
	spikes[48].deg = 0.f;

	spikes[90].x1 = 260.f;
	spikes[90].y1 = 310.f;
	spikes[90].x2 = 240.f;
	spikes[90].y2 = 340.f;
	spikes[90].x3 = 280.f;
	spikes[90].y3 = 340.f;
	spikes[90].deg = 0.f;

	// Initialize the checkpoints and its corresponding hitbox variables
	checkpoint[0].width = 50.f;
	checkpoint[0].height = 50.f;
	checkpoint[0].pos_x = stat_plat[5].pos_x + (stat_plat[5].width / 2); // Takes the x-coordinates relative to the platform with adjustments
	checkpoint[0].pos_y = stat_plat[5].pos_y - (checkpoint[0].height / 2 + 5.f); // Takes the y-coordinates relative to the platform with adjustments

	checkpoint_hitbox[0].width = checkpoint[0].width;
	checkpoint_hitbox[0].height = checkpoint[0].height;
	checkpoint_hitbox[0].pos_x = checkpoint[0].pos_x - (checkpoint[0].width / 2);
	checkpoint_hitbox[0].pos_y = checkpoint[0].pos_y - (checkpoint[0].height / 2);

	checkpoint[1].width = 50.f;
	checkpoint[1].height = 50.f;
	checkpoint[1].pos_x = stat_plat[11].pos_x + (stat_plat[11].width / 2);
	checkpoint[1].pos_y = stat_plat[11].pos_y - (checkpoint[1].height / 2 + 5.f);
	 
	checkpoint_hitbox[1].width = checkpoint[1].width;
	checkpoint_hitbox[1].height = checkpoint[1].height;
	checkpoint_hitbox[1].pos_x = checkpoint[1].pos_x - (checkpoint[1].width / 2);
	checkpoint_hitbox[1].pos_y = checkpoint[1].pos_y - (checkpoint[1].height / 2);
	
	checkpoint[2].width = 50.f;
	checkpoint[2].height = 50.f;
	checkpoint[2].pos_x = stat_plat[14].pos_x + (stat_plat[14].width / 2);
	checkpoint[2].pos_y = stat_plat[14].pos_y - (checkpoint[2].height / 2 + 5.f);
	
	checkpoint_hitbox[2].width = checkpoint[2].width;
	checkpoint_hitbox[2].height = checkpoint[2].height;
	checkpoint_hitbox[2].pos_x = checkpoint[2].pos_x - (checkpoint[2].width / 2);
	checkpoint_hitbox[2].pos_y = checkpoint[2].pos_y - (checkpoint[2].height / 2);

	// Initialize the endpoint and its corresponding hitbox variables

	endpoint.width = 60.f;
	endpoint.height = 80.f;
	endpoint.pos_x = stat_plat[15].pos_x + stat_plat[15].width - endpoint.width; // Takes the x-coordinates relative to the platform
	endpoint.pos_y = stat_plat[15].pos_y - (endpoint.height / 2); // Takes the y-coordinates relative to the platform

	endpoint_hitbox.width = endpoint.width;
	endpoint_hitbox.height = endpoint.height;
	endpoint_hitbox.pos_x = endpoint.pos_x - (endpoint.width / 2);
	endpoint_hitbox.pos_y = endpoint.pos_y - (endpoint.height / 2);
	

	//////////////////// CLEMENT ///////////////////////

	// IMAGES USED
	BombEnemy = CP_Image_Load("./Assets/bomb_enemy.png");
	MovingEnemyLeft = CP_Image_Load("./Assets/moving_enemy_left.png");
	MovingEnemyRight = CP_Image_Load("./Assets/moving_enemy_right.png");

	ExplosionSmall = CP_Image_Load("./Assets/explosion_small.png");
	ExplosionMedium = CP_Image_Load("./Assets/explosion_medium.png");
	ExplosionLarge = CP_Image_Load("./Assets/explosion_large.png");

	TurretLeft = CP_Image_Load("./Assets/turret_left.png");
	TurretRight = CP_Image_Load("./Assets/turret_right.png");
	BulletLeft = CP_Image_Load("./Assets/bullet_left.png");
	BulletRight = CP_Image_Load("./Assets/bullet_right.png");

	// SOUNDS USED
	BulletSound = CP_Sound_Load("./Assets/bullet_sound.ogg");
	ExplosionSound = CP_Sound_Load("./Assets/explosion_sound.wav");


	// INITIALIZE MOVING ENEMY VARIABLES
	mov_enemies[0].width = 45.f; mov_enemies[1].width = 45.f; mov_enemies[2].width = 45.f;
	mov_enemies[0].height = 45.f; mov_enemies[1].height = 45.f; mov_enemies[2].height = 45.f;

	mov_enemies[0].enemy_distance = stat_plat[3].width / 2;
	mov_enemies[1].enemy_distance = stat_plat[8].width / 2;
	mov_enemies[2].enemy_distance = stat_plat[15].width / 2;

	mov_enemies[0].enemy_speed = 150.f; mov_enemies[1].enemy_speed = 100.f; mov_enemies[2].enemy_speed = 100.f;

	mov_enemies[0].x_position = stat_plat[3].pos_x + (stat_plat[3].width / 2);
	mov_enemies[1].x_position = stat_plat[8].pos_x + (stat_plat[8].width / 2);
	mov_enemies[2].x_position = stat_plat[15].pos_x + (stat_plat[15].width / 2);

	mov_enemies[0].y_position = stat_plat[3].pos_y - mov_enemies[0].height;
	mov_enemies[1].y_position = stat_plat[8].pos_y - mov_enemies[1].height;
	mov_enemies[2].y_position = stat_plat[15].pos_y - mov_enemies[2].height;

	mov_enemies[0].enemy_direction = MOVE_RIGHT; 
	mov_enemies[1].enemy_direction = MOVE_LEFT;
	mov_enemies[2].enemy_direction = MOVE_LEFT;
	
	for (int i = 0; i < MOVING_ENEMY_SIZE; ++i)
	{
		mov_enemies[i].max_x = (mov_enemies[i].enemy_distance + mov_enemies[i].x_position) - mov_enemies[i].width;
		mov_enemies[i].min_x = mov_enemies[i].x_position - mov_enemies[i].enemy_distance;
	}
	mov_enemies[2].min_x += blocker_plat[2].height;

	// INITIALIZE BOMB ENEMY VARIABLES
	bomb_enemies[0].width = 45.f; bomb_enemies[1].width = 45.f; bomb_enemies[2].width = 45.f;
	bomb_enemies[0].height = 45.f; bomb_enemies[1].height = 45.f; bomb_enemies[2].height = 45.f;

	bomb_enemies[0].x_position = stat_plat[1].pos_x + (stat_plat[1].width / 2) - (bomb_enemies[0].width / 2);
	bomb_enemies[1].x_position = stat_plat[9].pos_x + (stat_plat[9].width / 2) - (bomb_enemies[1].width / 2);
	bomb_enemies[2].x_position = stat_plat[13].pos_x + (stat_plat[13].width / 2) - (bomb_enemies[2].width / 2);

	bomb_enemies[0].y_position = stat_plat[1].pos_y - bomb_enemies[0].height;
	bomb_enemies[1].y_position = stat_plat[9].pos_y - bomb_enemies[1].height;
	bomb_enemies[2].y_position = stat_plat[13].pos_y - bomb_enemies[2].height;

	bomb_enemies[0].enemy_draw = TRUE;
	bomb_enemies[1].enemy_draw = TRUE;
	bomb_enemies[2].enemy_draw = TRUE;

	for (int i = 0; i < BOMB_ENEMY_SIZE; ++i)
	{
		bomb_enemies[i].explosion_draw = FALSE;
		bomb_enemies[i].explosion_totalElapsedTime = 0.0f;
	}

	//INITIALIZE SHOOTING ENEMY VARIABLES

	shooting_enemies[0].width = 50.f; shooting_enemies[1].width = 50.f;
	shooting_enemies[0].height = 50.f; shooting_enemies[1].height = 50.f;

	shooting_enemies[0].x_position = CP_System_GetWindowWidth() - shooting_enemies[0].width;
	shooting_enemies[1].x_position = 0.0f;

	shooting_enemies[0].y_position = 435.f; shooting_enemies[1].y_position = 200.f;
	shooting_enemies[0].enemy_direction = MOVE_LEFT; shooting_enemies[1].enemy_direction = MOVE_RIGHT;

	for (int i = 0; i < SHOOTING_ENEMY_SIZE; ++i)
	{
		shooting_enemies[i].bullet_totalElapsedTime = 0.0f;
	}
	
	for (int i = 0; i < SHOOTING_ENEMY_SIZE; ++i)
	{
		for (int j = 0; j < BULLET_SIZE; ++j)
		{
			bullet[i][j].bullet_startX = shooting_enemies[i].x_position + (shooting_enemies[i].width / 2.4f);
			bullet[i][j].bullet_startY = shooting_enemies[i].y_position + (shooting_enemies[i].height / 2.4f);

			bullet[i][j].bullet_x = bullet[i][j].bullet_startX;
			bullet[i][j].bullet_y = bullet[i][j].bullet_startY;

			bullet[i][j].bullet_width = 30.f;
			bullet[i][j].bullet_height = 10.f;
			bullet[i][j].bullet_speed = 200.f;
			bullet[i][j].bullet_timeBetween = 2.0f;

			bullet[i][j].bullet_move = FALSE;
			bullet[0][j].bullet_direction = 'L';
			bullet[1][j].bullet_direction = 'R';
		}
	}
}

void Level_Update()
{
	// Sky blue background colour
	CP_Graphics_ClearBackground(CP_Color_Create(135, 206, 235, 255));

	// COMMONLY USED VARIABLES
	// Elapsed time from the last frame
	float currentElapsedTime = CP_System_GetDt();
	static float totalElapsedTime = 0;
	totalElapsedTime += currentElapsedTime;

	
	///////////////////////	YEE LEI	/////////////////////////////////////////

	// Initialize player model state
	static char player_model_state = 'R';

	// Initialize respawn effect timer
	static float spawn_totalElapsedTime = 0;

	// Set player spawn point based on checkpoint
	if (checkpoint_no == -1) {
		checkpoint_no = 0;
		current_checkpoint = 0;
		playerLives = totalLives;
		player.posX = stat_plat[0].pos_x + 30.0f;
		player.posY = stat_plat[0].pos_y - player.height - 50.0f;
	}
	else if (current_checkpoint != checkpoint_no) {
		current_checkpoint = checkpoint_no;
		
		player.posX = checkpoint[current_checkpoint - 1].pos_x;
		player.posY = checkpoint[current_checkpoint - 1].pos_y - player.height;
	}
	else if (player.alive == FALSE) {	// Respawn player if dead
		if (playerLives > 0) {
			playerLives--;

			CP_Sound_PlayAdvanced(sound_death, 0.3f, 1.0f, FALSE, CP_SOUND_GROUP_1);
		}

		if (playerLives == 0) {		// Go to Lose screen if 0 lives left
			CP_Engine_SetNextGameState(Lose_Init, Lose_Update, Lose_Exit);
		}
		else {
			if (current_checkpoint == 0) {
				player.posX = stat_plat[0].pos_x + 30.0f;
				player.posY = stat_plat[0].pos_y - player.height - 50.0f;
			}
			else {
				player.posX = checkpoint[current_checkpoint - 1].pos_x;
				player.posY = checkpoint[current_checkpoint - 1].pos_y - player.height;
			}

			player.alive = TRUE;
			player.isColliding = FALSE;
			player.isJumping = FALSE;

			// Respawn effect timer
			spawn_totalElapsedTime = 1.0f;
		}
	}

	// Respawn flashing visual effect
	CP_Settings_ImageMode(CP_POSITION_CORNER);
	int player_transparency = 255;

	if (spawn_totalElapsedTime > 0) {
		if (spawn_totalElapsedTime < 0.85 && spawn_totalElapsedTime > 0.8 || 
			spawn_totalElapsedTime < 0.65 && spawn_totalElapsedTime > 0.6 || 
			spawn_totalElapsedTime < 0.45 && spawn_totalElapsedTime > 0.4 || 
			spawn_totalElapsedTime < 0.25 && spawn_totalElapsedTime > 0.2 || 
			spawn_totalElapsedTime < 0.05 && spawn_totalElapsedTime > 0.0) 
		{
			player_transparency = 0;
		}
		
		// Draw player down model
		if (player_model_state == 'R') {
			CP_Image_Draw(player_down_right, player.posX, player.posY - 5.0f, player.width + 5.0f, player.height + 5.0f, player_transparency);
		}
		else if (player_model_state == 'L') {
			CP_Image_Draw(player_down_left, player.posX, player.posY - 5.0f, player.width + 5.0f, player.height + 5.0f, player_transparency);
		}

		player.blockLeft = TRUE;
		player.blockRight = TRUE;
		player.blockJump = TRUE;

		spawn_totalElapsedTime -= currentElapsedTime;
		if (spawn_totalElapsedTime < 0) spawn_totalElapsedTime = 0;
	}
	else {
		// Draw player standing model
		if (player.isColliding) {
			if (player_model_state == 'R') {
				CP_Image_Draw(player_stand_right, player.posX, player.posY, player.width, player.height, player_transparency);
			}
			else if (player_model_state == 'L') {
				CP_Image_Draw(player_stand_left, player.posX, player.posY, player.width, player.height, player_transparency);
			}
		}
		// Draw player jumping model
		else {
			if (player_model_state == 'R') {
				CP_Image_Draw(player_jump_right, player.posX, player.posY, player.width + 10.0f, player.height + 10.0f, player_transparency);
			}
			else if (player_model_state == 'L') {
				CP_Image_Draw(player_jump_left, player.posX, player.posY, player.width + 10.0f, player.height + 10.0f, player_transparency);
			}
		}

		player.blockLeft = FALSE;
		player.blockRight = FALSE;
		player.blockJump = FALSE;
	}

	// Player lives display
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(45.0f);
	CP_Font_DrawText("Lives:", 60.0f, 30.0f);
	CP_Settings_ImageMode(CP_POSITION_CENTER);
	
	for (int i = 0; i < playerLives; i++) {
		CP_Image_Draw(heart_full, 140.0f + (i * 50.0f), 30.f, 50.0f, 50.0f, 255);
	}

	for (int i = playerLives; i < totalLives; i++) {
		CP_Image_Draw(heart_empty, 140.0f + (i * 50.0f), 30.f, 50.0f, 50.0f, 255);
	}

	// Current score display
	CP_Settings_Fill(CP_Color_Create(255, 215, 0, 255));
	CP_Settings_TextSize(45.0f);
	char currentScoreStr[50] = { 0 };
	sprintf_s(currentScoreStr, 50, "Current Score: %d", quiz_score);
	CP_Font_DrawText(currentScoreStr, CP_System_GetWindowWidth() - 170.0f, 30.0f);

	// Player left/right controls
	if ((CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT)) && !player.blockLeft) {
		player.posX -= player.moveSpeed * currentElapsedTime;
		player_model_state = 'L';
	}

	if ((CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT)) && !player.blockRight) {
		player.posX += player.moveSpeed * currentElapsedTime;
		player_model_state = 'R';
	}

	// Jump speed deceleration based on time
	static float jump_totalElapsedTime = 1.0f;

	// Fall speed acceleration based on time
	static float fall_totalElapsedTime = 0.1f;
	
	// Player short jump control
	if (CP_Input_KeyTriggered(KEY_SPACE) && !player.blockJump) {
		if (!player.isJumping && player.isColliding) {
			player.jumpEnd_posY = player.posY - player.jumpHeight * jumpCharge;
			player.isJumping = TRUE;
			player.isColliding = FALSE;
			jump_totalElapsedTime = 1.0f;
			fall_totalElapsedTime = 0.1f;

			CP_Sound_PlayAdvanced(sound_jump, 0.3f, 1.0f, FALSE, CP_SOUND_GROUP_1);
		}

		jumpCharge = 1.0f;
	}

	// Jump charge indicator
	char jumpChargeStr[50] = { 0 };
	sprintf_s(jumpChargeStr, 50, "%.1fx", jumpCharge);
	CP_Settings_Fill(CP_Color_Create(0, 0, 128, 255));
	CP_Settings_TextSize(30.0f);
	CP_Font_DrawText(jumpChargeStr, player.posX + player.width / 2.0f, player.posY - 20.0f);

	// Chargeable vertical jump control
	if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT) && !player.blockJump) {
		if (!player.isJumping && player.isColliding && jumpCharge < jumpChargeMax) {
			jumpCharge += 1.0f * currentElapsedTime;

			if (jumpCharge > jumpChargeMax) jumpCharge = jumpChargeMax;
		}
	}
	else if (CP_Input_MouseReleased(MOUSE_BUTTON_LEFT)) {
		if (!player.isJumping && player.isColliding && !player.blockJump) {
			player.jumpEnd_posY = player.posY - player.jumpHeight * jumpCharge;
			player.isJumping = TRUE;
			player.isColliding = FALSE;
			jump_totalElapsedTime = 1.0f;
			fall_totalElapsedTime = 0.1f;

			CP_Sound_PlayAdvanced(sound_jump, 0.3f, 1.0f, FALSE, CP_SOUND_GROUP_1);
		}

		jumpCharge = 1.0f;
	}
	
	// Up vector scaled with jump speed
	CP_Vector jumpVec = CP_Vector_Set(0.0f, 1.0f);
	CP_Vector jumpVec_scaled = CP_Vector_Scale(jumpVec, player.jumpSpeed);
	
	// Apply jump movement
	if (player.isJumping) {
		if (player.posY > player.jumpEnd_posY) {
			if (jump_totalElapsedTime > 0.1) {
				jump_totalElapsedTime -= currentElapsedTime;
			}
			else {
				jump_totalElapsedTime = 0.1f;
			}
			
			if ((CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT)) && !player.blockLeft) {
				player.posX -= player.moveSpeed * currentElapsedTime;
			}
			if ((CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT)) && !player.blockRight) {
				player.posX += player.moveSpeed * currentElapsedTime;
			}
			
			player.posY -= jumpVec_scaled.y * jump_totalElapsedTime;
			if (player.posY < player.jumpEnd_posY) player.posY = player.jumpEnd_posY;
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

	// Window boundary collision blocking
	// Top and bottom boundaries
	if (playerPosY_bottom >= CP_System_GetWindowHeight()) {
		player.isColliding = TRUE;
		player.posY = CP_System_GetWindowHeight() - player.height;
		playerPosY_top = player.posY;
		playerPosY_bottom = player.posY + player.height;
	}
	else if (playerPosY_top < 0) {
		player.isJumping = FALSE;
		player.posY = 0;
		playerPosY_top = player.posY;
		playerPosY_bottom = player.posY + player.height;
	}

	// Left and right boundaries
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

	// Store coordinate values of all platforms into an array for collision checking
	struct PLATFORMS all_platforms[SIZE_STAT + SIZE_MOVE + SIZE_BLOCKER] = { 0 };
	int platCount = 0;

	// Add all stationary platforms to array
	for (int i = 0; i < SIZE_STAT; i++, platCount++) {
		all_platforms[platCount].pos_x = stat_plat[i].pos_x;
		all_platforms[platCount].pos_y = stat_plat[i].pos_y;
		all_platforms[platCount].width = stat_plat[i].width;
		all_platforms[platCount].height = stat_plat[i].height;
		all_platforms[platCount].movement = -1;
	}

	// Add all moving platforms to array
	for (int i = 0; i < SIZE_MOVE; i++, platCount++) {
		all_platforms[platCount].pos_x = move_plat[i].pos_x;
		all_platforms[platCount].pos_y = move_plat[i].pos_y;
		all_platforms[platCount].width = move_plat[i].width;
		all_platforms[platCount].height = move_plat[i].height;
		all_platforms[platCount].movement = move_plat[i].movement;
	}

	// Add blocker platforms to array based on checkpoint no.
	if (checkpoint_no < 1) {
		all_platforms[platCount].pos_x = blocker_plat[0].pos_x;
		all_platforms[platCount].pos_y = blocker_plat[0].pos_y;
		all_platforms[platCount].width = blocker_plat[0].width;
		all_platforms[platCount].height = blocker_plat[0].height;
		all_platforms[platCount].movement = -1;
		platCount++;
	}

	if (checkpoint_no < 2) {
		all_platforms[platCount].pos_x = blocker_plat[1].pos_x;
		all_platforms[platCount].pos_y = blocker_plat[1].pos_y;
		all_platforms[platCount].width = blocker_plat[1].width;
		all_platforms[platCount].height = blocker_plat[1].height;
		all_platforms[platCount].movement = -1;
		platCount++;
	}

	if (checkpoint_no < 3) {
		all_platforms[platCount].pos_x = blocker_plat[2].pos_x;
		all_platforms[platCount].pos_y = blocker_plat[2].pos_y;
		all_platforms[platCount].width = blocker_plat[2].width;
		all_platforms[platCount].height = blocker_plat[2].height;
		all_platforms[platCount].movement = -1;
		platCount++;
	}

	// Player position X offset when on side-moving platforms (-999 = NONE)
	static float player_Xoffset = -999.0f;

	// Index of down-moving platform that player is standing on (-1 = NONE)
	static int downPlatIndex = -1;

	// Platform collision checking
	for (int i = 0; i < platCount; i++) {
		float xLeft = all_platforms[i].pos_x, xRight = xLeft + all_platforms[i].width;
		float yTop = all_platforms[i].pos_y, yBottom = yTop + all_platforms[i].height;
		int movement = all_platforms[i].movement;

		// Reset index var if player no longer on the same moving platform
		if (downPlatIndex == i) {
			if (playerPosX_right < xLeft || playerPosX_left > xRight) downPlatIndex = -1;
		}

		// Block left and right side
		if (playerPosY_bottom > (yTop + jumpVec_scaled.y * 1.0)
			&& playerPosY_top < (yBottom - jumpVec_scaled.y * 1.0)) {

			if (playerPosX_right > xLeft && playerPosX_left < xLeft) {
				player.posX = xLeft - player.width;
				playerPosX_left = player.posX;
				playerPosX_right = player.posX + player.width;
				player.blockRight = TRUE;
			}
			else if (playerPosX_left < xRight && playerPosX_right > xRight) {
				player.posX = xRight;
				playerPosX_left = player.posX;
				playerPosX_right = player.posX + player.width;
				player.blockLeft = TRUE;
			}
		}
		
		// Block top and bottom
		if (playerPosX_right > xLeft && playerPosX_left < xRight) {
			if (playerPosY_bottom >= yTop && playerPosY_bottom <= yBottom) {

				player.isColliding = TRUE;

				// Save moving platform index if going down, else reset
				if (movement == DOWN) {
					downPlatIndex = i;
				}
				else {
					downPlatIndex = -1;
				}

				// Update player position X to follow side-moving platform when colliding
				if (movement == LEFT || movement == RIGHT) {
					if (player_Xoffset == -999.0f) {
						player_Xoffset = player.posX - xLeft;
					}

					if (CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_LEFT) || CP_Input_KeyDown(KEY_RIGHT)) {
						player_Xoffset = player.posX - xLeft;
					}

					player.posX = xLeft + player_Xoffset;
					playerPosX_left = player.posX;
					playerPosX_right = player.posX + player.width;
				}

				player.posY = yTop - player.height;
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
	
	// Update player position Y if standing on a down-moving platform
	if (downPlatIndex >= 0) {
		if (!player.isJumping) {
			player.isColliding = TRUE;
			player.posY = all_platforms[downPlatIndex].pos_y - player.height;
			playerPosY_top = player.posY;
			playerPosY_bottom = player.posY + player.height;
		}
		else {
			downPlatIndex = -1;
		}
	}
	
	// Make player fall downwards if not colliding with any platform
	if (!player.isColliding && !player.isJumping) {
		if (fall_totalElapsedTime < 1.0) {
			fall_totalElapsedTime += currentElapsedTime;
		}
		else {
			fall_totalElapsedTime = 1.0f;
		}
		
		player.posY += jumpVec_scaled.y * fall_totalElapsedTime;
		playerPosY_top = player.posY;
		playerPosY_bottom = player.posY + player.height;

		// Reset player position X offset for moving platforms (-999.0f = NONE)
		player_Xoffset = -999.0f;
	}

	// Reset fall speed back to default after falling
	if (player.isColliding) {
		fall_totalElapsedTime = 0.1f;
	}

	// Check for player collision with spikes and trigger death
	for (int i = 0; i < SIZE_SPIKES; i++) {
		float LeftX = spikes[i].x2;
		float topY = spikes[i].y1;

		if (CollisionCheck(player.posX, player.posY, player.width, player.height, LeftX, topY, 40.0f, 30.0f)) {
			player.alive = FALSE;
			break;
		}
	}

	// Hints for when to use charged jump
	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Settings_Fill(CP_Color_Create(105, 105, 105, 255));
	
	if (CollisionCheck(player.posX, player.posY, player.width, player.height, stat_plat[5].pos_x, stat_plat[5].pos_y - player.height, stat_plat[5].width, player.height) 
		&& current_checkpoint == 1) {
		CP_Settings_TextSize(30.0f);
		CP_Font_DrawText("Hold        to", stat_plat[5].pos_x + 40.0f, stat_plat[5].pos_y - player.height - 220.0f);
		CP_Font_DrawText("charge jump!", stat_plat[5].pos_x + 40.0f, stat_plat[5].pos_y - player.height - 185.0f);

		CP_Settings_ImageMode(CP_POSITION_CORNER);
		CP_Image_Draw(mouse_left, stat_plat[5].pos_x + 30.0f, stat_plat[5].pos_y - player.height - 245.0f, 50.0f, 50.0f, 255);
	} 
	else if (CollisionCheck(player.posX, player.posY, player.width, player.height, stat_plat[11].pos_x, stat_plat[11].pos_y - player.height, stat_plat[11].width, player.height) 
		&& current_checkpoint == 2) {

		CP_Settings_TextSize(30.0f);
		CP_Font_DrawText("Hold        to", stat_plat[11].pos_x + 90.0f, stat_plat[11].pos_y - player.height - 100.0f);
		CP_Font_DrawText("charge jump!", stat_plat[11].pos_x + 90.0f, stat_plat[11].pos_y - player.height - 65.0f);

		CP_Settings_ImageMode(CP_POSITION_CORNER);
		CP_Image_Draw(mouse_left, stat_plat[11].pos_x + 80.0f, stat_plat[11].pos_y - player.height - 125.0f, 50.0f, 50.0f, 255);
	}

	
	////////////////////// KENNY /////////////////////////
	
	// Draw platforms and spikes settings
	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Settings_ImageMode(CP_POSITION_CENTER);
	CP_Color color_brown = (CP_Color_Create(181, 101, 29, 255));
	CP_Color color_grey = (CP_Color_Create(211, 211, 211, 255));
	CP_Color color_lightgrey = (CP_Color_Create(220, 220, 220, 255));
	CP_Color color_darkgrey = (CP_Color_Create(128, 128, 128, 255));

	// Drawing of all stationary platforms
	CP_Settings_Fill(color_brown);
	for (int i = 0; i < SIZE_STAT; ++i) {
		CP_Graphics_DrawRectAdvanced(stat_plat[i].pos_x, stat_plat[i].pos_y, stat_plat[i].width, stat_plat[i].height, stat_plat[i].rotation, 0.f);
	}

	// Drawing of all blocker platforms
	
	CP_Settings_Fill(color_darkgrey);
	if (checkpoint_no < 1) {
		CP_Graphics_DrawRectAdvanced(blocker_plat[0].pos_x, blocker_plat[0].pos_y, blocker_plat[0].width, blocker_plat[0].height, blocker_plat[0].rotation, 0.f);
	}
	
	if (checkpoint_no < 2) {
		CP_Graphics_DrawRectAdvanced(blocker_plat[1].pos_x, blocker_plat[1].pos_y, blocker_plat[1].width, blocker_plat[1].height, blocker_plat[1].rotation, 0.f);
	}
	
	if (checkpoint_no < 3) {
		CP_Graphics_DrawRectAdvanced(blocker_plat[2].pos_x, blocker_plat[2].pos_y, blocker_plat[2].width, blocker_plat[2].height, blocker_plat[2].rotation, 0.f);
	}

	// Drawing of all moving platforms
	CP_Settings_Fill(color_brown);
	for (int i = 0; i < SIZE_MOVE; ++i) {
		CP_Graphics_DrawRectAdvanced(move_plat[i].pos_x, move_plat[i].pos_y, move_plat[i].width, move_plat[i].height, move_plat[i].rotation, 0.f);

		// Logic for moving platform right then left
		if (move_plat[i].direction == RIGHT_LEFT) {
			float right_limit = move_plat[i].limit + move_plat[i].distance;

			if (move_plat[i].pos_x <= move_plat[i].limit) { // Check if platform exceeds left limit
				move_plat[i].movement = RIGHT;
			}
			if (move_plat[i].pos_x >= right_limit) { // Check if platform exceeds right limit
				move_plat[i].movement = LEFT;
			}
		}

		// Logic for moving platform left then right
		if (move_plat[i].direction == LEFT_RIGHT) {
			float left_limit = move_plat[i].limit - move_plat[i].distance;

			if (move_plat[i].pos_x >= move_plat[i].limit) { // Check if platform exceeds right limit
				move_plat[i].movement = LEFT;
			}
			if (move_plat[i].pos_x <= left_limit) { // Check if platform exceeds left limit
				move_plat[i].movement = RIGHT;
			}
		}

		// Logic for moving platform down then up
		if (move_plat[i].direction == DOWN_UP) {
			float lower_limit = move_plat[i].limit + move_plat[i].distance;

			if (move_plat[i].pos_y <= move_plat[i].limit) { // Check if platform exceeds upper limit
				move_plat[i].movement = DOWN;
			}
			if (move_plat[i].pos_y >= lower_limit) { // Check if platform exceeds lower limit
				move_plat[i].movement = UP;
			}
		}

		// Logic for moving platform up then down
		if (move_plat[i].direction == UP_DOWN) {
			float upper_limit = move_plat[i].limit - move_plat[i].distance;

			if (move_plat[i].pos_y >= move_plat[i].limit) { // Check if platform exceeds lower limit
				move_plat[i].movement = UP;
			}
			if (move_plat[i].pos_y <= upper_limit) { // Check if platform exceeds upper limit
				move_plat[i].movement = DOWN;
			}
		}

		// Check the direction of the movement and move platform accordingly
		if (move_plat[i].movement == LEFT) { // Move left
			move_plat[i].pos_x -= move_plat[i].speed * currentElapsedTime;
		}
		if (move_plat[i].movement == RIGHT) { // Move right
			move_plat[i].pos_x += move_plat[i].speed * currentElapsedTime;
		}
		if (move_plat[i].movement == UP) { // Move up
			move_plat[i].pos_y -= move_plat[i].speed * currentElapsedTime;
		}
		if (move_plat[i].movement == DOWN) { // Move down
			move_plat[i].pos_y += move_plat[i].speed * currentElapsedTime;
		}
	}

	// Draw 48 spikes at the first floor of the map
	CP_Settings_Fill(color_lightgrey);
	int currentSpike = 0; // The number of the current selected spike
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

	// Draw 43 spikes at the 2nd floor of the map
	spikesWanted = 42;
	size = currentSpike + spikesWanted;

	for (int i = 0; currentSpike < size; ++currentSpike, ++i) {
		spikes[currentSpike].x1 = spikes[48].x1 + (i * 40.f);
		spikes[currentSpike].y1 = spikes[48].y1;
		spikes[currentSpike].x2 = spikes[48].x2 + (i * 40.f);
		spikes[currentSpike].y2 = spikes[48].y2;
		spikes[currentSpike].x3 = spikes[48].x3 + (i * 40.f);
		spikes[currentSpike].y3 = spikes[48].y3;
		CP_Graphics_DrawTriangleAdvanced(spikes[currentSpike].x1, spikes[currentSpike].y1, spikes[currentSpike].x2, spikes[currentSpike].y2, spikes[currentSpike].x3, spikes[currentSpike].y3, spikes[currentSpike].deg);
	}

	// Draw 42 spikes at the 3rd floor of the map
	spikesWanted = 42;
	size = currentSpike + spikesWanted;

	for (int i = 0; currentSpike < size; ++currentSpike, ++i) {
		spikes[currentSpike].x1 = spikes[90].x1 + (i * 40.f);
		spikes[currentSpike].y1 = spikes[90].y1;
		spikes[currentSpike].x2 = spikes[90].x2 + (i * 40.f);
		spikes[currentSpike].y2 = spikes[90].y2;
		spikes[currentSpike].x3 = spikes[90].x3 + (i * 40.f);
		spikes[currentSpike].y3 = spikes[90].y3;
		CP_Graphics_DrawTriangleAdvanced(spikes[currentSpike].x1, spikes[currentSpike].y1, spikes[currentSpike].x2, spikes[currentSpike].y2, spikes[currentSpike].x3, spikes[currentSpike].y3, spikes[currentSpike].deg);
	}


	// Draw checkpoints
	for (int i = checkpoint_no; i < SIZE_CHECKPOINTS; ++i) {
		
		//CP_Graphics_DrawRect(checkpoint_hitbox[i].pos_x, checkpoint_hitbox[i].pos_y, checkpoint_hitbox[i].width, checkpoint_hitbox[i].height); // Checkpoint hitbox boundary checking
		CP_Image_Draw(CPoint, checkpoint[i].pos_x, checkpoint[i].pos_y, checkpoint[i].width, checkpoint[i].height, 255);

		// Collision checking of checkpoints
		if (CollisionCheck(player.posX, player.posY, player.width, player.height, checkpoint_hitbox[i].pos_x, checkpoint_hitbox[i].pos_y, checkpoint_hitbox[i].width, checkpoint_hitbox[i].height)) {
			checkpoint_no = i + 1; // Saves the current checkpoint
			CP_Sound_Play(checkpointSound);
			CP_Engine_SetNextGameState(Quiz_Init, Quiz_Update, Quiz_Exit);
		}
	}

	// Draw endpoint
	CP_Image_Draw(EPoint, endpoint.pos_x, endpoint.pos_y, endpoint.width, endpoint.height, 255);

	// Collision checking of endpoint
	if (CollisionCheck(player.posX, player.posY, player.width, player.height, endpoint_hitbox.pos_x, endpoint_hitbox.pos_y, endpoint_hitbox.width, endpoint_hitbox.height)) {
		CP_Engine_SetNextGameState(Win_Init, Win_Update, Win_Exit);
	}


	//////////////////////////// CLEMENT /////////////////////////////////
	
	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Settings_ImageMode(CP_POSITION_CORNER);

	for (int i = 0; i < SHOOTING_ENEMY_SIZE; ++i)
	{
		shooting_enemies[i].bullet_totalElapsedTime += currentElapsedTime;
	}

	for (int i = 0; i < MOVING_ENEMY_SIZE; ++i) // DRAWING OF THE 3 MOVING ENEMIES INITIALIZED
	{
		CP_Settings_Fill(color_grey);
		//CP_Graphics_DrawRect(mov_enemies[i].x_position, mov_enemies[i].y_position, mov_enemies[i].width, mov_enemies[i].height);
		if (mov_enemies[i].enemy_direction == MOVE_LEFT)
		{
			CP_Image_Draw(MovingEnemyLeft, mov_enemies[i].x_position , mov_enemies[i].y_position, mov_enemies[i].width, mov_enemies[i].height, 255);
		}
		if (mov_enemies[i].enemy_direction == MOVE_RIGHT)
		{
			CP_Image_Draw(MovingEnemyRight, mov_enemies[i].x_position, mov_enemies[i].y_position, mov_enemies[i].width, mov_enemies[i].height, 255);
		}
	}

	for (int i = 0; i < BOMB_ENEMY_SIZE; ++i) // DRAWING OF THE 3 BOMB ENEMIES INITIALIZED
	{
		if (bomb_enemies[i].enemy_draw == TRUE) // DRAW BOMB ENEMY IF ITS STILL ALIVE
		{
			CP_Settings_Fill(color_grey);
			//CP_Graphics_DrawRect(bomb_enemies[i].x_position, bomb_enemies[i].y_position, bomb_enemies[i].width, bomb_enemies[i].height);
			CP_Image_Draw(BombEnemy, bomb_enemies[i].x_position, bomb_enemies[i].y_position, bomb_enemies[i].width, bomb_enemies[i].height, 255);
		}
		else
		{
			if (bomb_enemies[i].explosion_draw == TRUE) // DRAW EXPLOSION IF BOMB ENEMY HAS EXPLODED AND BEEN CLEARED
			{
				CP_Image_Draw(ExplosionSmall, bomb_enemies[i].x_position, bomb_enemies[i].y_position, bomb_enemies[i].width, bomb_enemies[i].height, 255);
				bomb_enemies[i].explosion_totalElapsedTime += currentElapsedTime;

				if (bomb_enemies[i].explosion_totalElapsedTime >= 0.1f)
				{
					CP_Image_Draw(ExplosionMedium, bomb_enemies[i].x_position - 10, bomb_enemies[i].y_position - 10, bomb_enemies[i].width + 20, bomb_enemies[i].height + 20, 255);
				}
				if (bomb_enemies[i].explosion_totalElapsedTime >= 0.15f)
				{
					CP_Image_Draw(ExplosionLarge, bomb_enemies[i].x_position - 20 , bomb_enemies[i].y_position - 20, bomb_enemies[i].width + 40, bomb_enemies[i].height + 40, 255);
				}
				if (bomb_enemies[i].explosion_totalElapsedTime >= 0.2f)
				{
					bomb_enemies[i].explosion_draw = FALSE;
					bomb_enemies[i].explosion_totalElapsedTime = 0.0f;

				}
			}
		}
	}

	// LOGIC FOR MOVING ENEMIES TO MOVE LEFT AND RIGHT
	for (int index = 0; index < MOVING_ENEMY_SIZE; ++index)
	{
		if (mov_enemies[index].enemy_direction == MOVE_RIGHT) // ENEMY MOVES TO THE RIGHT
		{
			mov_enemies[index].x_position += mov_enemies[index].enemy_speed * currentElapsedTime;
		}
		if (mov_enemies[index].enemy_direction == MOVE_LEFT)// ENEMY MOVES TO THE LEFT
		{
			mov_enemies[index].x_position -= mov_enemies[index].enemy_speed * currentElapsedTime;
		}


		if (mov_enemies[index].x_position <= mov_enemies[index].min_x) // WHEN ENEMY REACHES MINIMUM X POSITION
		{
			mov_enemies[index].enemy_direction = MOVE_RIGHT;
		}

		if (mov_enemies[index].x_position >= mov_enemies[index].max_x) // WHEN ENEMY REACHES THE MAXIMUN X POSITION
		{
			mov_enemies[index].enemy_direction = MOVE_LEFT;
		}
	}

	// COLLISION CHECKING BETWEEN MOVING ENEMIES & PLAYERS
	for (int index = 0; index < MOVING_ENEMY_SIZE; ++index)
	{
		if (CollisionCheck(player.posX, player.posY, player.width, player.height, mov_enemies[index].x_position, mov_enemies[index].y_position,
			mov_enemies[index].width, mov_enemies[index].height))
		{
			player.alive = FALSE;
		}
	}

	// COLLISION CHECKING BETWEEN BOMB ENEMIES & PLAYERS
	for (int index = 0; index < BOMB_ENEMY_SIZE; ++index)
	{
		if (bomb_enemies[index].enemy_draw == TRUE) // CHECK FOR COLLISION WITH PLAYER IF BOMB ENEMY IS STILL ALIVE
		{
			if (CollisionCheck(player.posX, player.posY, player.width, player.height, bomb_enemies[index].x_position, bomb_enemies[index].y_position,
				bomb_enemies[index].width, bomb_enemies[index].height))
			{
				player.alive = FALSE;
				CP_Sound_PlayAdvanced(ExplosionSound, 1.0f, 1.0f, FALSE, CP_SOUND_GROUP_0);
				bomb_enemies[index].explosion_draw = TRUE;
				bomb_enemies[index].enemy_draw = FALSE; // CLEAR THE BOMB ENEMY DRAWING IF ITS HAS COLLIDED WITH PLAYER
			}
		}
	}

	// DRAW BULLETS
	for (int i = 0; i < SHOOTING_ENEMY_SIZE; ++i)
	{
		for (int j = 0; j < BULLET_SIZE; ++j)
		{
			CP_Settings_Fill(color_grey);
			//CP_Graphics_DrawRect(bullet[i][j].bullet_x, bullet[i][j].bullet_y, bullet[i][j].bullet_width, bullet[i][j].bullet_height);

			if (bullet[i][j].bullet_direction == 'R')
			{
				CP_Image_Draw(BulletRight, bullet[i][j].bullet_x, bullet[i][j].bullet_y, bullet[i][j].bullet_width, bullet[i][j].bullet_height, 255);
			}
			if (bullet[i][j].bullet_direction == 'L')
			{
				CP_Image_Draw(BulletLeft, bullet[i][j].bullet_x, bullet[i][j].bullet_y, bullet[i][j].bullet_width, bullet[i][j].bullet_height, 255);
			}
		}
	}

	// LOGIC FOR BULLETS TO TRAVEL TO THE RIGHT / LEFT
	for (int i = 0; i < SHOOTING_ENEMY_SIZE; ++i)
	{
		for (int j = 0; j < BULLET_SIZE; ++j)
		{
			// BULLET TRAVELS TO THE RIGHT
			if (bullet[i][j].bullet_direction == 'R')
			{
				if (bullet[i][j].bullet_move == TRUE)
				{
					bullet[i][j].bullet_x += bullet[i][j].bullet_speed * currentElapsedTime;
					if (bullet[i][j].bullet_x >= bullet[i][j].bullet_startX && bullet[i][j].bullet_x <= bullet[i][j].bullet_startX + 5.0f)
					{
						CP_Sound_PlayAdvanced(BulletSound, 0.1f, 1.0f, FALSE, CP_SOUND_GROUP_0);
					}
					continue;
				}
				if (shooting_enemies[0].bullet_totalElapsedTime >= bullet[i][j].bullet_timeBetween && bullet[i][j].bullet_move == FALSE) // TIME BEFORE THE NEXT BULLET STARTS TRAVELLING
				{
					bullet[i][j].bullet_move = TRUE;
					shooting_enemies[0].bullet_totalElapsedTime = 0.0f;
				}
			}

			// BULLET TRAVELS TO THE LEFT
			if (bullet[i][j].bullet_direction == 'L')
			{
				if (bullet[i][j].bullet_move == TRUE)
				{
					bullet[i][j].bullet_x -= bullet[i][j].bullet_speed * currentElapsedTime;
					if (bullet[i][j].bullet_x <= bullet[i][j].bullet_startX && bullet[i][j].bullet_x >= bullet[i][j].bullet_startX - 5.0f)
					{
						CP_Sound_PlayAdvanced(BulletSound, 0.1f, 1.0f, FALSE, CP_SOUND_GROUP_0);
					}
					continue;
				}
				if (shooting_enemies[1].bullet_totalElapsedTime >= bullet[i][j].bullet_timeBetween && bullet[i][j].bullet_move == FALSE) // TIME BEFORE THE NEXT BULLET STARTS TRAVELLING
				{
					bullet[i][j].bullet_move = TRUE;
					shooting_enemies[1].bullet_totalElapsedTime = 0.0f;
				}

			}
		}
	}

	// LOGIC TO LOOP THE BULLET BACK TO THE STARTING POSITION CONTINUOUSLY
	for (int i = 0; i < SHOOTING_ENEMY_SIZE; ++i)
	{
		for (int j = 0; j < BULLET_SIZE; ++j)
		{
			// BULLETS TRAVELING TO THE RIGHT
			if (bullet[i][j].bullet_direction == 'R')
			{
				if (bullet[i][j].bullet_x + bullet[i][j].bullet_width >= CP_System_GetWindowWidth())
				{
					bullet[i][j].bullet_move = FALSE;
					bullet[i][j].bullet_x = bullet[i][j].bullet_startX;
				}
			}

			// BULLETS TRAVELING TO THE LEFT
			if (bullet[i][j].bullet_direction == 'L')
			{
				if (bullet[i][j].bullet_x <= 0.0f)
				{
					bullet[i][j].bullet_move = FALSE;
					bullet[i][j].bullet_x = bullet[i][j].bullet_startX;
				}
			}
		}
	}

	// COLLISION CHECK BETWEEN THE PLAYER AND BULLETS
	for (int i = 0; i < SHOOTING_ENEMY_SIZE; ++i)
	{
		for (int j = 0; j < BULLET_SIZE; ++j)
		{
			if (CollisionCheck(player.posX, player.posY, player.width, player.height, bullet[i][j].bullet_x, bullet[i][j].bullet_y,
				bullet[i][j].bullet_width, bullet[i][j].bullet_height))
			{
				player.alive = FALSE;
			}
		}
	}

	// COLLISION CHECK BETWEEN THE PLAYER AND SHOOTING ENEMIES
	for (int index = 0; index < SHOOTING_ENEMY_SIZE; ++index)
	{
		if (CollisionCheck(player.posX, player.posY, player.width, player.height, shooting_enemies[index].x_position, shooting_enemies[index].y_position,
			shooting_enemies[index].width, shooting_enemies[index].height))
		{
			player.alive = FALSE;
		}
	}

	// DRAWING OF THE SHOOTING ENEMIES
	for (int i = 0; i < SHOOTING_ENEMY_SIZE; ++i)
	{
		CP_Settings_Fill(color_grey);
		//CP_Graphics_DrawRect(shooting_enemies[i].x_position, shooting_enemies[i].y_position, shooting_enemies[i].width , shooting_enemies[i].height);
		if (shooting_enemies[i].enemy_direction == MOVE_LEFT)
		{
			CP_Image_Draw(TurretLeft, shooting_enemies[i].x_position - 10.f, shooting_enemies[i].y_position - 10.f, shooting_enemies[i].width + 20.f, shooting_enemies[i].height + 20.f, 255);
		}
		if (shooting_enemies[i].enemy_direction == MOVE_RIGHT)
		{
			CP_Image_Draw(TurretRight, shooting_enemies[i].x_position - 10.f, shooting_enemies[i].y_position - 10.f, shooting_enemies[i].width + 20.f, shooting_enemies[i].height + 20.f, 255);
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
	///////////////////// YEE LEI /////////////////////
	CP_Image_Free(&player_stand_right);
	CP_Image_Free(&player_stand_left);
	CP_Image_Free(&player_jump_right);
	CP_Image_Free(&player_jump_left);
	CP_Image_Free(&player_down_left);
	CP_Image_Free(&player_down_right);

	CP_Image_Free(&heart_full);
	CP_Image_Free(&heart_empty);
	CP_Image_Free(&mouse_left);

	CP_Sound_Free(&sound_jump);
	CP_Sound_Free(&sound_death);

	///////////////////// KENNY /////////////////////
	CP_Image_Free(&CPoint);
	CP_Image_Free(&EPoint);
	//CP_Sound_Free(&levelMusic);

	///////////////////// CLEMENT /////////////////////
	CP_Image_Free(&BombEnemy);
	CP_Image_Free(&MovingEnemyLeft);
	CP_Image_Free(&MovingEnemyRight);
	CP_Image_Free(&ExplosionSmall);
	CP_Image_Free(&ExplosionMedium);
	CP_Image_Free(&ExplosionLarge);
	CP_Image_Free(&TurretLeft);
	CP_Image_Free(&TurretRight);
	CP_Image_Free(&BulletLeft);
	CP_Image_Free(&BulletRight);

	CP_Sound_Free(&BulletSound);
	CP_Sound_Free(&ExplosionSound);
}
