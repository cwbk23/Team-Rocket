/*---------------------------------------------------------------
Math Run by Team Rocket
Class: CSD1401A Fall 2022
File: win.h
Authors: Chua Wen Bin Kenny, c.wenbinkenny@digipen.edu

Description:
Displayed the victory screen that calculate and show the high score
and score break down of the current game. Restart game and back to
main menu button for players to play again or go back to main menu.

Copyright: 2022, Digipen Institute of Technology, Singapore
----------------------------------------------------------------*/

#pragma once

extern int highscore;

void Win_Init(void);

void Win_Update(void);

void Win_Exit(void);
