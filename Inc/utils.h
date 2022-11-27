/*---------------------------------------------------------------
Math Run by Team Rocket
Class: CSD1401A Fall 2022
File: utils.h
Authors: Low Yee Lei, yeelei.low@digipen.edu
		 Tan Wei Jie Clement, weijieclement.tan@digipen.edu

Description:
Yee Lei - IsAreaClicked function for button clicking
Clement - CollisionCheck function for collision checking between player and object


Copyright: 2022, Digipen Institute of Technology, Singapore
----------------------------------------------------------------*/

#pragma once

int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y);

int CollisionCheck(float player_x, float player_y, float player_width, float player_height, float object_x, float object_y,
	float object_width, float object_height);
