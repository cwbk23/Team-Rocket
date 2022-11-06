#include "cprocessing.h"
#include <math.h>
#include "utils.h"


int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y)
{
	float x1, x2, y1, y2;

	x1 = area_center_x - area_width / 2.0f;
	x2 = area_center_x + area_width / 2.0f;
	y1 = area_center_y + area_height / 2.0f;
	y2 = area_center_y - area_height / 2.0f;

	if (click_x > x1 && click_x < x2) {
		if (click_y < y1 && click_y > y2) {
			return 1;
		}
	}

	return 0;
}

int IsCircleClicked(float circle_center_x, float circle_center_y, float diameter, float click_x, float click_y)
{
	float radius = diameter / 2.0f;
	float distance = CP_Math_Distance(circle_center_x, circle_center_y, click_x, click_y);

	if (distance < radius) {
		return 1;
	}

	return 0;
}

int CollisionCheck(float player_x, float player_y, float player_width, float player_height, float object_x, float object_y,
	float object_width, float object_height)
{
	float object_rightside = object_x + object_width;
	float player_rightside = player_x + player_width;
	float object_bottom = object_y + object_height;
	float player_bottom = player_y + player_height;

	if (player_x <= object_rightside && player_rightside >= object_x &&
		player_y <= object_bottom && player_bottom >= object_y)
	{
		return 1;
	}

	return 0;
}

CP_Vector AngleToVector(float radian_angle)
{
	float x = cos(radian_angle);
	float y = sin(radian_angle);
    CP_Vector ret = CP_Vector_Set(x, y);
    return ret;
}
