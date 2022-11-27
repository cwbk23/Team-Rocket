/*---------------------------------------------------------------
Math Run by Team Rocket
Class: CSD1401A Fall 2022
File: main.c
Authors: Low Yee Lei, yeelei.low@digipen.edu
		 Chua Wen Bin Kenny, c.wenbinkenny@digipen.edu
		 Tan Wei Jie Clement, weijieclement.tan@digipen.edu
		 Tan Wei Fong, weifong.tan@digipen.edu

Description:
Run CProcessing engine and start splash screen state


Copyright: 2022, Digipen Institute of Technology, Singapore
----------------------------------------------------------------*/

#include "cprocessing.h"
#include "splashscreen.h"


int main(void)
{
	// Initialize splash screen state
	CP_Engine_SetNextGameState(splash_screen_init, splash_screen_update, splash_screen_exit);
	CP_Engine_Run();
	return 0;
}
