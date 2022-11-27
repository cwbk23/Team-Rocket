/*---------------------------------------------------------------
Math Run by Team Rocket
Class: CSD1401A Fall 2022
File: level.h
Authors: Low Yee Lei, yeelei.low@digipen.edu
		 Chua Wen Bin Kenny, c.wenbinkenny@digipen.edu
		 Tan Wei Jie Clement, weijieclement.tan@digipen.edu

Description:
Yee Lei - Player creation, movement controls, jumping and falling,
collision blocking with boundary and platforms, death and respawning,
lives HUD, score HUD, lose logic, player sound effects.

Kenny - Drawing of stationary, moving platforms, and blockers. Moving
platform logic, drawing of spikes, checkpoints, and endpoint. Checkpoint
collision and logic, endpoint collision and win logic.

Clement - Bomb enemy creation, Moving enemy creation, Shooting enemy and bullet creation,
Enemy movement logic, Bullet movement logic, Collision checking between player and enemy entities,
Sound effects for all enemies.


Copyright: 2022, Digipen Institute of Technology, Singapore
----------------------------------------------------------------*/

#pragma once

extern int checkpoint_no;

extern int quiz_score;

extern int playerLives;

extern CP_Sound levelMusic;

extern CP_Sound checkpointSound;

extern int playlevelmusic;

void Level_Init(void);

void Level_Update(void);

void Level_Exit(void);
