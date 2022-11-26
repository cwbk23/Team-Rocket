#pragma once

int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y);

int CollisionCheck(float player_x, float player_y, float player_width, float player_height, float object_x, float object_y,
	float object_width, float object_height);
