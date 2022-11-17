#include "cprocessing.h"
#include "quiz.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include <mainmenu.h>
#include "utils.h"
#include <stdbool.h>
#include<level.h>

bool timesuppage;
bool timercounter;

bool clicked_q1;
bool question_1ans;
bool question_1;

bool question_2;
bool clicked_q2;
bool question_2ans;

bool question_3;
bool clicked_q3;
bool question_3ans;

bool question_4;
bool clicked_q4;
bool question_4ans;

bool question_5;
bool clicked_q5;
bool question_5ans;

bool question_6;
bool clicked_q6;
bool question_6ans;

bool question_7;
bool clicked_q7;
bool question_7ans;

bool question_8;
bool clicked_q8;
bool question_8ans;

bool question_9;
bool clicked_q9;
bool question_9ans;

bool question_10;
bool clicked_q10; 
bool question_10ans;

bool question_11;
bool clicked_q11;
bool question_11ans;

bool question_12;
bool clicked_q12;
bool question_12ans;

bool question_13;
bool clicked_q13;
bool question_13ans;

bool question_14;
bool clicked_q14;
bool question_14ans;

bool question_15;
bool clicked_q15;
bool question_15ans;

bool fail_page;
bool fail_page1;
bool fail_page2;

char TrueFalse_x1[10] = { 10 };
char TrueFalse_y1[10] = { 10 };
char TrueFalseans1[10] = { 10 };

char TrueFalse_x2[10] = { 10 };
char TrueFalse_y2[10] = { 10 };
char TrueFalseans2[10] = { 10 };


char TrueFalse_x3[10] = { 10 };
char TrueFalse_y3[10] = { 10 };
char TrueFalseans3[10] = { 10 };


char TrueFalse_x4[10] = { 10 };
char TrueFalse_y4[10] = { 10 };
char TrueFalseans4[10] = { 10 };


char TrueFalse_x5[10] = { 10 };
char TrueFalse_y5[10] = { 10 };
char TrueFalseans5[10] = { 10 };


char multiplechoice1_xvalue[10] = { 10 };
char multiplechoice1_xconstant[10] = { 10 };
char multiplechoice1_yvalue[10] = { 10 };
char multiplechoice1_yconstant[10] = { 10 };
char multiplechoice1_1[10] = { 10 };
char multiplechoice1_2[10] = { 10 };
char multiplechoice1_3[10] = { 10 };
char multiplechoice1_ans[10] = { 10 };


char multiplechoice2_xvalue[10] = { 10 };
char multiplechoice2_xconstant[10] = { 10 };
char multiplechoice2_yvalue[10] = { 10 };
char multiplechoice2_yconstant[10] = { 10 };
char multiplechoice2_1[10] = { 10 };
char multiplechoice2_2[10] = { 10 };
char multiplechoice2_3[10] = { 10 };
char multiplechoice2_ans[10] = { 10 };

char multiplechoice3_xvalue[10] = { 10 };
char multiplechoice3_xconstant[10] = { 10 };
char multiplechoice3_yvalue[10] = { 10 };
char multiplechoice3_yconstant[10] = { 10 };
char multiplechoice3_1[10] = { 10 };
char multiplechoice3_2[10] = { 10 };
char multiplechoice3_3[10] = { 10 };
char multiplechoice3_ans[10] = { 10 };

char multiplechoice4_xvalue[10] = { 10 };
char multiplechoice4_xconstant[10] = { 10 };
char multiplechoice4_yvalue[10] = { 10 };
char multiplechoice4_yconstant[10] = { 10 };
char multiplechoice4_1[10] = { 10 };
char multiplechoice4_2[10] = { 10 };
char multiplechoice4_3[10] = { 10 };
char multiplechoice4_ans[10] = { 10 };

char multiplechoice5_xvalue[10] = { 10 };
char multiplechoice5_yvalue[10] = { 10 };
char multiplechoice5_1[10] = { 10 };
char multiplechoice5_2[10] = { 10 };
char multiplechoice5_3[10] = { 10 };
char multiplechoice5_ans[10] = { 10 };

char multiplechoice6_xvalue[10] = { 10 };
char multiplechoice6_xconstant[10] = { 10 };
char multiplechoice6_yconstant[10] = { 10 };
char multiplechoice6_1[10] = { 10 };
char multiplechoice6_2[10] = { 10 };
char multiplechoice6_3[10] = { 10 };
char multiplechoice6_ans[10] = { 10 };

char multiplechoice7_xvalue[10] = { 10 };
char multiplechoice7_xconstant[10] = { 10 };
char multiplechoice7_yconstant[10] = { 10 };
char multiplechoice7_1[10] = { 10 };
char multiplechoice7_2[10] = { 10 };
char multiplechoice7_3[10] = { 10 };
char multiplechoice7_ans[10] = { 10 };

char multiplechoice8_xvalue[10] = { 10 };
char multiplechoice8_xconstant[10] = { 10 };
char multiplechoice8_yvalue[10] = { 10 };
char multiplechoice8_yconstant[10] = { 10 };
char multiplechoice8_1[10] = { 10 };
char multiplechoice8_2[10] = { 10 };
char multiplechoice8_3[10] = { 10 };
char multiplechoice8_ans[10] = { 10 };

char multiplechoice9_xvalue[10] = { 10 };
char multiplechoice9_xconstant[10] = { 10 };
char multiplechoice9_yconstant[10] = { 10 };
char multiplechoice9_1[10] = { 10 };
char multiplechoice9_2[10] = { 10 };
char multiplechoice9_3[10] = { 10 };
char multiplechoice9_ans[10] = { 10 };

char multiplechoice10_xvalue[10] = { 10 };
char multiplechoice10_yvalue[10] = { 10 };
char multiplechoice10_1[10] = { 10 };
char multiplechoice10_2[10] = { 10 };
char multiplechoice10_3[10] = { 10 };
char multiplechoice10_ans[10] = { 10 };

char OperatorRandom[10] = { 3 };
char totalscore[10] = { 3 };

 int counter ;
 int counter1 ;
 int counter2 ;

 static float totalElapsedTime;

void Quiz_Init()
{
 //quiz_score ;  
 //counter = 0;
 //counter1 = 0;
 //counter2 = 0;

	 
	//Setting up the window size
	CP_Settings_TextSize(70);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);


	int randomoperator = CP_Random_RangeInt(2, 5);
	sprintf_s(OperatorRandom, _countof(OperatorRandom), "%d", randomoperator);

	int random_x1 = CP_Random_RangeInt(1, 10);
	sprintf_s(TrueFalse_x1, _countof(TrueFalse_x1), "%d", random_x1);
	int random_y1 = CP_Random_RangeInt(1, 10);
	sprintf_s(TrueFalse_y1, _countof(TrueFalse_y1), "%d", random_y1);
	sprintf_s(TrueFalseans1, _countof(TrueFalseans1), "%d", random_y1 + random_x1);

	int random_x2 = CP_Random_RangeInt(1, 10);
	sprintf_s(TrueFalse_x2, _countof(TrueFalse_x2), "%d", random_x2);
	int random_y2 = CP_Random_RangeInt(1, 10);
	sprintf_s(TrueFalse_y2, _countof(TrueFalse_y2), "%d", random_y2);
	sprintf_s(TrueFalseans2, _countof(TrueFalseans2), "%d",  random_y2*random_x2 + 3);

	int random_x3 = CP_Random_RangeInt(1, 5);
	sprintf_s(TrueFalse_x3, _countof(TrueFalse_x3), "%d", random_x3);
	int random_y3 = CP_Random_RangeInt(1, 5);
	sprintf_s(TrueFalse_y3, _countof(TrueFalse_y3), "%d", random_y3);
	sprintf_s(TrueFalseans3, _countof(TrueFalseans3), "%d", random_y3 * random_x3 + 2);

	int random_x4 = CP_Random_RangeInt(1, 5);
	sprintf_s(TrueFalse_x4, _countof(TrueFalse_x4), "%d", random_x4);
	int random_y4 = CP_Random_RangeInt(1, 5);
	sprintf_s(TrueFalse_y4, _countof(TrueFalse_y4), "%d", random_y4);
	sprintf_s(TrueFalseans4, _countof(TrueFalseans4), "%d", random_x4 * random_y4 );

	int random_x5 = CP_Random_RangeInt(1, 5);
	sprintf_s(TrueFalse_x5, _countof(TrueFalse_x5), "%d", random_x5);
	int random_y5 = CP_Random_RangeInt(1, 5);
	sprintf_s(TrueFalse_y5, _countof(TrueFalse_y5), "%d", random_y5);
	sprintf_s(TrueFalseans5, _countof(TrueFalseans5), "%d", random_y5 * random_x5 - 5);

	int randommultiple1_xvalue = CP_Random_RangeInt(2, 4);
	sprintf_s(multiplechoice1_xvalue, _countof(multiplechoice1_xvalue), "%d", randommultiple1_xvalue);
	int randommultiple1_xconstant = CP_Random_RangeInt(1, 3);
	sprintf_s(multiplechoice1_xconstant, _countof(multiplechoice1_xconstant), "%d", randommultiple1_xconstant);
	int randommultiple1_yvalue = CP_Random_RangeInt(2, 4);
	sprintf_s(multiplechoice1_yvalue, _countof(multiplechoice1_yvalue), "%d", randommultiple1_yvalue);
	int randommultiple1_yconstant = CP_Random_RangeInt(6, 8);
	sprintf_s(multiplechoice1_yconstant, _countof(multiplechoice1_yconstant), "%d", randommultiple1_yconstant);
	sprintf_s(multiplechoice1_ans, _countof(multiplechoice1_ans), "%d", (randommultiple1_xconstant * randommultiple1_xvalue) + (randommultiple1_yconstant * randommultiple1_yvalue));
	sprintf_s(multiplechoice1_1, _countof(multiplechoice1_1), "%d", (randommultiple1_xconstant * randommultiple1_xvalue) + (randommultiple1_yconstant * randommultiple1_yvalue) + randomoperator);
	sprintf_s(multiplechoice1_2, _countof(multiplechoice1_2), "%d", (randommultiple1_xconstant * randommultiple1_xvalue) + (randommultiple1_yconstant * randommultiple1_yvalue) * randomoperator);
	sprintf_s(multiplechoice1_3, _countof(multiplechoice1_3), "%d", (randommultiple1_xvalue + randommultiple1_yvalue));

	int randommultiple2_xvalue = CP_Random_RangeInt(2, 4);
	sprintf_s(multiplechoice2_xvalue, _countof(multiplechoice2_xvalue), "%d", randommultiple2_xvalue);
	int randommultiple2_xconstant = CP_Random_RangeInt(4, 6);
	sprintf_s(multiplechoice2_xconstant, _countof(multiplechoice2_xconstant), "%d", randommultiple2_xconstant);
	int randommultiple2_yvalue = CP_Random_RangeInt(1, 3);
	sprintf_s(multiplechoice2_yvalue, _countof(multiplechoice2_yvalue), "%d", randommultiple2_yvalue);
	int randommultiple2_yconstant = CP_Random_RangeInt(4, 5);
	sprintf_s(multiplechoice2_yconstant, _countof(multiplechoice2_yconstant), "%d", randommultiple2_yconstant);
	sprintf_s(multiplechoice2_ans, _countof(multiplechoice2_ans), "%d", (randommultiple2_xconstant * randommultiple2_xvalue) + (randommultiple2_yconstant * randommultiple2_yvalue));
	sprintf_s(multiplechoice2_1, _countof(multiplechoice2_1), "%d", (randommultiple2_xconstant * randommultiple2_xvalue) * randomoperator);
	sprintf_s(multiplechoice2_2, _countof(multiplechoice2_2), "%d", (randommultiple2_xconstant * randommultiple2_xvalue) + randomoperator);
	sprintf_s(multiplechoice2_3, _countof(multiplechoice2_3), "%d", (randommultiple2_xvalue + randommultiple2_yvalue));

	int randommultiple3_xvalue = CP_Random_RangeInt(2, 3);
	sprintf_s(multiplechoice3_xvalue, _countof(multiplechoice3_xvalue), "%d", randommultiple3_xvalue);
	int randommultiple3_xconstant = CP_Random_RangeInt(4, 5);
	sprintf_s(multiplechoice3_xconstant, _countof(multiplechoice3_xconstant), "%d", randommultiple3_xconstant);
	int randommultiple3_yvalue = CP_Random_RangeInt(3, 4);
	sprintf_s(multiplechoice3_yvalue, _countof(multiplechoice3_yvalue), "%d", randommultiple3_yvalue);
	int randommultiple3_yconstant = CP_Random_RangeInt(6, 9);
	sprintf_s(multiplechoice3_yconstant, _countof(multiplechoice3_yconstant), "%d", randommultiple3_yconstant);
	sprintf_s(multiplechoice3_ans, _countof(multiplechoice3_ans), "%d", (randommultiple3_xconstant * randommultiple3_xvalue) - (randommultiple3_yconstant * randommultiple3_yvalue));
	sprintf_s(multiplechoice3_1, _countof(multiplechoice3_1), "%d", (randommultiple3_xconstant * randommultiple3_xvalue) + (randommultiple3_yconstant * randommultiple3_yvalue) + randomoperator);
	sprintf_s(multiplechoice3_2, _countof(multiplechoice3_2), "%d", (randommultiple3_xconstant * randommultiple3_xvalue) + (randommultiple3_yconstant ) - randomoperator);
	sprintf_s(multiplechoice3_3, _countof(multiplechoice3_3), "%d", (randommultiple3_xvalue - randommultiple3_yvalue));


	int randommultiple4_xvalue = CP_Random_RangeInt(1, 5);
	sprintf_s(multiplechoice4_xvalue, _countof(multiplechoice4_xvalue), "%d", randommultiple4_xvalue);
	int randommultiple4_xconstant = CP_Random_RangeInt(4, 5);
	sprintf_s(multiplechoice4_xconstant, _countof(multiplechoice4_xconstant), "%d", randommultiple4_xconstant);
	int randommultiple4_yvalue = CP_Random_RangeInt(2, 3);
	sprintf_s(multiplechoice4_yvalue, _countof(multiplechoice4_yvalue), "%d", randommultiple4_yvalue);
	int randommultiple4_yconstant = CP_Random_RangeInt(3, 7);
	sprintf_s(multiplechoice4_yconstant, _countof(multiplechoice4_yconstant), "%d", randommultiple4_yconstant);
	sprintf_s(multiplechoice4_ans, _countof(multiplechoice4_ans), "%d", (randommultiple4_xconstant * randommultiple4_xvalue) - (randommultiple4_yconstant * randommultiple4_yvalue));
	sprintf_s(multiplechoice4_1, _countof(multiplechoice4_1), "%d", (randommultiple4_xconstant * randommultiple4_xvalue) - (randommultiple4_xconstant * randommultiple4_yvalue) + randomoperator);
	sprintf_s(multiplechoice4_2, _countof(multiplechoice4_2), "%d", (randommultiple4_xconstant * randommultiple4_xvalue) + (randommultiple4_yconstant * randommultiple4_yconstant));
	sprintf_s(multiplechoice4_3, _countof(multiplechoice4_3), "%d", (randommultiple4_xvalue - randommultiple4_yvalue));


	int randommultiple5_xvalue = CP_Random_RangeInt(1, 5);
	sprintf_s(multiplechoice5_xvalue, _countof(multiplechoice5_xvalue), "%d", randommultiple5_xvalue);
	int randommultiple5_yvalue = CP_Random_RangeInt(6, 9);
	sprintf_s(multiplechoice5_yvalue, _countof(multiplechoice5_yvalue), "%d", randommultiple5_yvalue);
	sprintf_s(multiplechoice5_ans, _countof(multiplechoice5_ans), "%d", (randommultiple5_xvalue * randommultiple5_yvalue));
	sprintf_s(multiplechoice5_1, _countof(multiplechoice5_1), "%d", (randommultiple5_xvalue * randommultiple5_xvalue));
	sprintf_s(multiplechoice5_2, _countof(multiplechoice5_2), "%d", (randommultiple5_yvalue * randommultiple5_yvalue));
	sprintf_s(multiplechoice5_3, _countof(multiplechoice5_3), "%d", (randommultiple5_xvalue * randommultiple5_xvalue)-randomoperator);


	int randommultiple6_xvalue = CP_Random_RangeInt(3, 7);
	sprintf_s(multiplechoice6_xvalue, _countof(multiplechoice6_xvalue), "%d", randommultiple6_xvalue);
	int randommultiple6_xconstant = CP_Random_RangeInt(2, 3);
	sprintf_s(multiplechoice6_xconstant, _countof(multiplechoice6_xconstant), "%d", randommultiple6_xconstant);
	int randommultiple6_yconstant = CP_Random_RangeInt(4, 5);
	sprintf_s(multiplechoice6_yconstant, _countof(multiplechoice6_yconstant), "%d", randommultiple6_yconstant);
	sprintf_s(multiplechoice6_ans, _countof(multiplechoice6_ans), "%d", (randommultiple6_xconstant* randommultiple6_xvalue) + (randommultiple6_yconstant ));
	sprintf_s(multiplechoice6_1, _countof(multiplechoice6_1), "%d", (randommultiple6_xconstant* randommultiple6_xvalue) + (randommultiple6_yconstant ) + randomoperator);
	sprintf_s(multiplechoice6_2, _countof(multiplechoice6_2), "%d", (randommultiple6_xconstant* randommultiple6_xvalue) + (randommultiple6_yconstant ) - randomoperator);
	sprintf_s(multiplechoice6_3, _countof(multiplechoice6_3), "%d", (randommultiple6_xvalue ));

	int randommultiple7_xvalue = CP_Random_RangeInt(3, 7);
	sprintf_s(multiplechoice7_xvalue, _countof(multiplechoice7_xvalue), "%d", randommultiple7_xvalue);
	int randommultiple7_xconstant = CP_Random_RangeInt(2, 3);
	sprintf_s(multiplechoice7_xconstant, _countof(multiplechoice7_xconstant), "%d", randommultiple7_xconstant);
	int randommultiple7_yconstant = CP_Random_RangeInt(4, 5);
	sprintf_s(multiplechoice7_yconstant, _countof(multiplechoice7_yconstant), "%d", randommultiple7_yconstant);
	sprintf_s(multiplechoice7_ans, _countof(multiplechoice7_ans), "%d", (randommultiple7_xconstant * randommultiple7_xvalue) - (randommultiple7_yconstant));
	sprintf_s(multiplechoice7_1, _countof(multiplechoice7_1), "%d", (randommultiple7_xvalue* randommultiple7_xvalue) + (randommultiple7_yconstant)+randomoperator);
	sprintf_s(multiplechoice7_2, _countof(multiplechoice7_2), "%d", (randommultiple7_xconstant* randommultiple7_xconstant) - randomoperator);
	sprintf_s(multiplechoice7_3, _countof(multiplechoice7_3), "%d", (randommultiple7_xvalue * randomoperator));


	int randommultiple8_xvalue = CP_Random_RangeInt(3, 7);
	sprintf_s(multiplechoice8_xvalue, _countof(multiplechoice8_xvalue), "%d", randommultiple8_xvalue);
	int randommultiple8_xconstant = CP_Random_RangeInt(2, 3);
	sprintf_s(multiplechoice8_xconstant, _countof(multiplechoice8_xconstant), "%d", randommultiple8_xconstant);
	int randommultiple8_yconstant = CP_Random_RangeInt(4, 5);
	sprintf_s(multiplechoice8_yconstant, _countof(multiplechoice8_yconstant), "%d", randommultiple8_yconstant);
	sprintf_s(multiplechoice8_ans, _countof(multiplechoice8_ans), "%d", (randommultiple8_xconstant* randommultiple8_xvalue) + (randommultiple8_yconstant));
	sprintf_s(multiplechoice8_1, _countof(multiplechoice8_1), "%d", (randommultiple8_xconstant* randommultiple8_xvalue) + (randommultiple8_yconstant)+randomoperator);
	sprintf_s(multiplechoice8_2, _countof(multiplechoice8_2), "%d", (randommultiple8_xconstant* randommultiple8_xvalue) + (randommultiple8_yconstant)-randomoperator);
	sprintf_s(multiplechoice8_3, _countof(multiplechoice8_3), "%d", (randommultiple8_xvalue - randomoperator));



	int randommultiple9_xvalue = CP_Random_RangeInt(3, 7);
	sprintf_s(multiplechoice9_xvalue, _countof(multiplechoice9_xvalue), "%d", randommultiple9_xvalue);
	int randommultiple9_xconstant = CP_Random_RangeInt(2, 3);
	sprintf_s(multiplechoice9_xconstant, _countof(multiplechoice9_xconstant), "%d", randommultiple9_xconstant);
	int randommultiple9_yconstant = CP_Random_RangeInt(4, 5);
	sprintf_s(multiplechoice9_yconstant, _countof(multiplechoice9_yconstant), "%d", randommultiple9_yconstant);
	sprintf_s(multiplechoice9_ans, _countof(multiplechoice9_ans), "%d", randommultiple9_xconstant * randommultiple9_xvalue * randommultiple9_yconstant) ;
	sprintf_s(multiplechoice9_1, _countof(multiplechoice9_1), "%d", randommultiple9_xconstant * randommultiple9_xconstant);
	sprintf_s(multiplechoice9_2, _countof(multiplechoice9_2), "%d", (randommultiple9_yconstant * randommultiple9_xvalue) - (randommultiple9_yconstant));
	sprintf_s(multiplechoice9_3, _countof(multiplechoice9_3), "%d", (randommultiple9_xvalue* randommultiple9_xconstant + randommultiple9_xvalue));

	int randommultiple10_xvalue = CP_Random_RangeInt(1, 5);
	sprintf_s(multiplechoice10_xvalue, _countof(multiplechoice10_xvalue), "%d", randommultiple10_xvalue);
	int randommultiple10_yvalue = CP_Random_RangeInt(6, 9);
	sprintf_s(multiplechoice10_yvalue, _countof(multiplechoice10_yvalue), "%d", randommultiple10_yvalue);
	sprintf_s(multiplechoice10_ans, _countof(multiplechoice10_ans), "%d", (randommultiple10_xvalue* randommultiple10_yvalue));
	sprintf_s(multiplechoice10_1, _countof(multiplechoice10_1), "%d", (randommultiple10_xvalue* randommultiple10_xvalue));
	sprintf_s(multiplechoice10_2, _countof(multiplechoice10_2), "%d", (randommultiple10_yvalue* randommultiple10_yvalue));
	sprintf_s(multiplechoice10_3, _countof(multiplechoice10_3), "%d", (randommultiple10_xvalue* randommultiple10_xvalue) - randomoperator);


	timercounter = TRUE;
	timesuppage = FALSE;

	clicked_q1 = false;
	question_1ans = false;
	question_1 = false;

	question_2 = false;
	clicked_q2 = false;
	question_2ans = false;

	question_3 = false;
	clicked_q3 = false;
	question_3ans = false;

	question_4 = false;
	clicked_q4 = false;
	question_4ans = false;

	question_5 = false;
	clicked_q5 = false;
	question_5ans = false;

	 question_6 = false;
	 clicked_q6 = false;
	 question_6ans = false;

	 question_7 = false;
	 clicked_q7 = false;
	 question_7ans = false;

	 question_8 = false;
	 clicked_q8 = false;
	 question_8ans = false;

	 question_9 = false;
	 clicked_q9 = false;
	 question_9ans = false;

	 question_10 = false;
	 clicked_q10 = false;
	 question_10ans = false;

	 question_11 = false;
	 clicked_q11 = false;
	 question_11ans = false;

	 question_12 = false;
	 clicked_q12 = false;
	 question_12ans = false;

	 question_13 = false;
	 clicked_q13 = false;
	 question_13ans = false;

	 question_14 = false;
	 clicked_q14 = false;
	 question_14ans = false;

	 question_15 = false;
	 clicked_q15 = false;
	 question_15ans = false;


	fail_page = false;
	fail_page1 = false;
	fail_page2 = false;

	 if (checkpoint_no == 1)
	 {
		 question_1 = TRUE;
		 counter = 0;
	 }

	 if (checkpoint_no == 2)
	 {
		 question_6 = TRUE;
		 counter1 = 0;
	 }

	 if (checkpoint_no == 3)
	 {	
		 question_11 = TRUE;
	 }
	totalElapsedTime = 180;
}



void Quiz_Update()
{
	float height = (float)CP_System_GetWindowHeight();
	float width =  (float)CP_System_GetWindowWidth();

	//Setting the background colour
	CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));

	if (timercounter == true)
	{
		CP_Font_DrawText("Timer:     :", width / 1.2, height / 8);
		float currentElapsedTime = CP_System_GetDt();
		totalElapsedTime -= currentElapsedTime;
		char minute[16] = { 0 };
		char second[16] = { 0 };
		sprintf_s(minute, _countof(minute), "%d", (int)totalElapsedTime / 60);
		sprintf_s(second, _countof(second), "%.d", ((int)totalElapsedTime % 60));
		CP_Font_DrawText(minute, width / 1.14, height / 8);
		CP_Font_DrawText(second, width / 1.08, height / 8);

	}

	if (checkpoint_no == 1)
	{
		if (totalElapsedTime <= 0)
		{
			clicked_q1 = false;
			question_1ans = false;
			question_1 = false;

			question_2 = false;
			clicked_q2 = false;
			question_2ans = false;

			question_3 = false;
			clicked_q3 = false;
			question_3ans = false;

			question_4 = false;
			clicked_q4 = false;
			question_4ans = false;

			question_5 = false;
			clicked_q5 = false;
			question_5ans = false;

			fail_page = true;
		}
		if (question_1 == TRUE)
		{	
			
			CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
			CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
			int total_score = counter * 10;
			sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

			CP_Settings_TextSize(50);
			CP_Font_DrawText("Current score :", width / 9, height / 8);
			CP_Font_DrawText(totalscore, width / 5, height / 8);

			//Drawing and setting the start rectangle position
			CP_Settings_TextSize(70);
			CP_Font_DrawText("q1)", width / 3, height / 4);
			CP_Font_DrawText("If x =      and y =  ", width / 2, height / 4);
			CP_Font_DrawText(TrueFalse_x1, width / 2.1, height / 4);
			CP_Font_DrawText(TrueFalse_y1, width / 1.6, height / 4);
			CP_Font_DrawText(" Does x and y equals to       ?", width / 1.9, height / 3);
			CP_Font_DrawText(TrueFalseans1, width / 1.49, height / 3);

			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5); // false button
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5); // true button

			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
			CP_Font_DrawText(" True ", width / 2.6, height / 2);
			CP_Font_DrawText(" False ", width / 1.5, height / 2);

			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Settings_TextSize(50);
			CP_Font_DrawText("10 marks ", width / 9, height / 1.1);
			CP_Settings_TextSize(70);

			//If mouse click is within a certain area
			if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q1 == FALSE) && (question_1ans == FALSE))
			{
				if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					clicked_q1 = TRUE;
					counter = counter + 1;
				}
				else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_1ans = TRUE;
				}


			}
			if ((clicked_q1 == TRUE))
			{
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
				CP_Font_DrawText(" Correct ", width / 2, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{

						question_1 = FALSE;
						question_2 = TRUE;
					}
				}
			} if ((question_1ans == TRUE) && (clicked_q1 == FALSE))
			{
				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
				CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{

						question_1 = FALSE;
						question_2 = TRUE;
					}
				}
			}
		}

		if (question_2 == TRUE)
		{
			int total_score = counter * 10;
			sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

			CP_Settings_TextSize(50);
			CP_Font_DrawText("Current score :", width / 9, height / 8);
			CP_Font_DrawText(totalscore, width / 5, height / 8);

			CP_Settings_TextSize(70);
			//Drawing and setting the start rectangle position
			CP_Font_DrawText("q2)", width / 3, height / 4);
			CP_Font_DrawText("If x =      ", width / 2, height / 4);
			CP_Font_DrawText(TrueFalse_x2, width / 1.9, height / 4);
			CP_Font_DrawText(" Does      x + 3 equals to       ?", width / 2, height / 3);
			CP_Font_DrawText(TrueFalse_y2, width / 2.4, height / 3);
			//CP_Font_DrawText(TrueFalse_x2, width / 2.15, height / 1.6);
			CP_Font_DrawText(TrueFalseans2, width / 1.55, height / 3);

			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5); // false button
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5); // true button

			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
			CP_Font_DrawText(" True ", width / 2.6, height / 2);
			CP_Font_DrawText(" False ", width / 1.5, height / 2);

			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Settings_TextSize(50);
			CP_Font_DrawText("10 marks ", width / 9, height / 1.1);
			CP_Settings_TextSize(70);

			//If mouse click is within a certain area
			if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q2 == FALSE) && (question_2ans == FALSE))
			{
				if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					clicked_q2 = TRUE;
					counter = counter + 1;
				}
				else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_2ans = TRUE;
				}


			}
			if ((clicked_q2 == TRUE))
			{
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
				CP_Font_DrawText(" Correct ", width / 2, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{

						question_2 = FALSE;
						question_3 = TRUE;
					}
				}
			} if ((question_2ans == TRUE) && (clicked_q2 == FALSE))
			{
				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
				CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{

						question_2 = FALSE;
						question_3 = TRUE;
					}
				}
			}
		}


		if (question_3 == TRUE)
		{
			int total_score = counter * 10;
			sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

			CP_Settings_TextSize(50);
			CP_Font_DrawText("Current score :", width / 9, height / 8);
			CP_Font_DrawText(totalscore, width / 5, height / 8);

			CP_Settings_TextSize(70);
			CP_Font_DrawText("q3)", width / 3, height / 4);
			CP_Font_DrawText("If x =      ", width / 2, height / 4);
			CP_Font_DrawText(TrueFalse_x3, width / 1.9, height / 4);
			CP_Font_DrawText(" Does      x + 3 equals to       ?", width / 2, height / 3);
			CP_Font_DrawText(TrueFalse_y3, width / 2.4, height / 3);
			CP_Font_DrawText(TrueFalseans3, width / 1.55, height / 3);

			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5); // false button
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5); // true button

			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
			CP_Font_DrawText(" True ", width / 2.6, height / 2);
			CP_Font_DrawText(" False ", width / 1.5, height / 2);

			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Settings_TextSize(50);
			CP_Font_DrawText("10 marks ", width / 9, height / 1.1);
			CP_Settings_TextSize(70);

			//If mouse click is within a certain area
			if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q3 == FALSE) && (question_3ans == FALSE))
			{
				if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					clicked_q3 = TRUE;
				}
				else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_3ans = TRUE;
					counter = counter + 1;
				}


			}
			if ((question_3ans == TRUE))
			{

				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
				CP_Font_DrawText(" Correct ", width / 2, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{

						question_3 = FALSE;
						question_4 = TRUE;
					}
				}
			} if ((clicked_q3 == TRUE))
			{
				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
				CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{

						question_3 = FALSE;
						question_4 = TRUE;
					}
				}
			}
		}



		if (question_4 == TRUE)
		{
			int total_score = counter * 10;
			sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

			CP_Settings_TextSize(50);
			CP_Font_DrawText("Current score :", width / 9, height / 8);
			CP_Font_DrawText(totalscore, width / 5, height / 8);

			CP_Settings_TextSize(70);
			//Drawing and setting the start rectangle position
			CP_Font_DrawText("q4)", width / 3, height / 4);
			CP_Font_DrawText("If x =      and y =  ", width / 2, height / 4);
			CP_Font_DrawText(TrueFalse_x4, width / 2.1, height / 4);
			CP_Font_DrawText(TrueFalse_y4, width / 1.6, height / 4);
			CP_Font_DrawText(" Does x times y equals to       ?", width / 1.9, height / 3);
			CP_Font_DrawText(TrueFalseans4, width / 1.48, height / 3);

			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5); // false button
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5); // true button

			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
			CP_Font_DrawText(" True ", width / 2.6, height / 2);
			CP_Font_DrawText(" False ", width / 1.5, height / 2);

			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Settings_TextSize(50);
			CP_Font_DrawText("10 marks ", width / 9, height / 1.1);
			CP_Settings_TextSize(70);

			//If mouse click is within a certain area
			if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q4 == FALSE) && (question_4ans == FALSE))
			{
				if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					clicked_q4 = TRUE;
					counter = counter + 1;
				}
				else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_4ans = TRUE;
				}


			}
			if ((clicked_q4 == TRUE))
			{
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
				CP_Font_DrawText(" Correct ", width / 2, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{

						question_4 = FALSE;
						question_5 = TRUE;
					}
				}
			} if ((question_4ans == TRUE) && (clicked_q4 == FALSE))
			{
				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
				CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{

						question_4 = FALSE;
						question_5 = TRUE;
					}
				}
			}
		}


		if (question_5 == TRUE)
		{
			int total_score = counter * 10;
			sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

			CP_Settings_TextSize(50);
			CP_Font_DrawText("Current score :", width / 9, height / 8);
			CP_Font_DrawText(totalscore, width / 5, height / 8);

			CP_Settings_TextSize(70);
			//Drawing and setting the start rectangle position
			CP_Font_DrawText("q5)", width / 3, height / 4);
			CP_Font_DrawText("If x =      ", width / 2, height / 4);
			CP_Font_DrawText(TrueFalse_x5, width / 1.9, height / 4);
			CP_Font_DrawText(" Does      x - 5 equals to       ?", width / 2, height / 3);
			CP_Font_DrawText(TrueFalse_y5, width / 2.4, height / 3);
			CP_Font_DrawText(TrueFalseans5, width / 1.55, height / 3);

			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5); // false button
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5); // true button

			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
			CP_Font_DrawText(" True ", width / 2.6, height / 2);
			CP_Font_DrawText(" False ", width / 1.5, height / 2);

			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Settings_TextSize(50);
			CP_Font_DrawText("10 marks ", width / 9, height / 1.1);
			CP_Settings_TextSize(70);

			//If mouse click is within a certain area
			if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q5 == FALSE) && (question_5ans == FALSE))
			{
				if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					clicked_q5 = TRUE;
					counter = counter + 1;

				}
				else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_5ans = TRUE;
				}
			}


			if (clicked_q5 == TRUE)
			{
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
				CP_Font_DrawText(" Correct ", width / 2, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5); // false button
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					question_5 = false;
					fail_page = true;
				}
			}
			if (question_5ans == TRUE)
			{
				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
				CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					question_5 = false;
					fail_page = true;
				}
			}

		}
		int total_score = counter * 10;
		sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

		if (fail_page == true)
		{
			timercounter = false;
			if (totalElapsedTime <= 0)
			{
				CP_Font_DrawText("TIMES UP !", width / 2, height / 5.5);
			}
			if (counter <= 2)
			{
				CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
				CP_Font_DrawText("U HAVE FAIL THE REQUIREMENT", width / 2, height / 4);
				CP_Font_DrawText("You have scored a total of:", width / 2, height / 3);
				CP_Font_DrawText(totalscore, width / 1.4, height / 3);
				CP_Font_DrawText(" Retry quiz ", width / 1.2, height / 1.1);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.2, height / 1.1f, 500.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						counter = 0;
						CP_Engine_SetNextGameStateForced(Quiz_Init, Quiz_Update, Quiz_Exit);

					}
				}
			}
			else if (counter > 2)
			{
				CP_Font_DrawText("U HAVE PASS THE REQUIREMENT", width / 2, height / 4);
				CP_Font_DrawText("You have scored a total of:", width / 2, height / 3);
				CP_Font_DrawText(totalscore, width / 1.4, height / 3);
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
			CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.1);
			if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
			{
				if (IsAreaClicked(width / 1.2f, height / 1.1f, 500.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);

				}
			}
			}


		}

		quiz_score =  counter*10;
		
	}


	if (checkpoint_no == 2)
	{
		if (totalElapsedTime <= 0)
		{
				question_6 = false;
				clicked_q6 = false;
				question_6ans = false;

				question_7 = false;
				clicked_q7 = false;
				question_7ans = false;

				question_8 = false;
				clicked_q8 = false;
				question_8ans = false;

				question_9 = false;
				clicked_q9 = false;
				question_9ans = false;

				question_10 = false;
				clicked_q10 = false;
				question_10ans = false;

				fail_page1 = true;
		}


		if (question_6 == TRUE)
		{
			int total_score = (counter1 * 20) ;
			sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

			CP_Settings_TextSize(50);
			CP_Font_DrawText("Current score :", width / 9, height / 8);
			CP_Font_DrawText(totalscore, width / 5, height / 8);

			CP_Settings_TextSize(70);
			CP_Font_DrawText("q6)", width / 3, height / 4);
			CP_Font_DrawText("If x =      and y = ", width / 2, height / 4);
			CP_Font_DrawText(multiplechoice1_xvalue, width / 2.1, height / 4);
			CP_Font_DrawText(multiplechoice1_yvalue, width / 1.63, height / 4);
			CP_Font_DrawText("What does    x +   y equals to  ?", width / 2, height / 3);
			CP_Font_DrawText(multiplechoice1_xconstant, width / 2.165, height / 3);
			CP_Font_DrawText(multiplechoice1_yconstant, width / 1.95, height / 3);


			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5);
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 1.5, 200, 100, 0, 5);// false button
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5);
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 1.5, 200, 100, 0, 5);// true button

			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
			CP_Font_DrawText(multiplechoice1_1, width / 2.6, height / 2);
			CP_Font_DrawText(multiplechoice1_2, width / 1.5, height / 2);
			CP_Font_DrawText(multiplechoice1_3, width / 1.5, height / 1.5);
			CP_Font_DrawText(multiplechoice1_ans, width / 2.6, height / 1.5);


			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Settings_TextSize(50);
			CP_Font_DrawText("20 marks ", width / 9, height / 1.1);
			CP_Settings_TextSize(70);


			if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q6 == FALSE) && (question_6ans == FALSE))
			{
				if (IsAreaClicked(width / 2.6f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					clicked_q6 = TRUE;
					counter1 = counter1 + 1;

				}
				else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_6ans = TRUE;
				}
				else if (IsAreaClicked(width / 1.5f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_6ans = TRUE;
				}
				else if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_6ans = TRUE;
				}
			}

			if (clicked_q6 == TRUE)
			{
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
				CP_Font_DrawText(" Correct ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5); // false button
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{

						question_6 = FALSE;
						question_7 = TRUE;
					}
				}
			}



			if (question_6ans == TRUE)
			{
				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
				CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_6 = FALSE;
						question_7 = TRUE;
					}
				}
			}
		}

		if (question_7 == TRUE)
		{
			int total_score = (counter1 * 20);
			sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

			CP_Settings_TextSize(50);
			CP_Font_DrawText("Current score :", width / 9, height / 8);
			CP_Font_DrawText(totalscore, width / 5, height / 8);

			CP_Settings_TextSize(70);
			CP_Font_DrawText("q7)", width / 3, height / 4);
			CP_Font_DrawText("If x =      and y = ", width / 2, height / 4);
			CP_Font_DrawText(multiplechoice2_xvalue, width / 2.1, height / 4);
			CP_Font_DrawText(multiplechoice2_yvalue, width / 1.63, height / 4);
			CP_Font_DrawText("What does    x +   y equals to  ?", width / 2, height / 3);
			CP_Font_DrawText(multiplechoice2_xconstant, width / 2.165, height / 3);
			CP_Font_DrawText(multiplechoice2_yconstant, width / 1.95, height / 3);


			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5);
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 1.5, 200, 100, 0, 5);// false button
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5);
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 1.5, 200, 100, 0, 5);// true button

			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
			CP_Font_DrawText(multiplechoice2_1, width / 2.6, height / 2);
			CP_Font_DrawText(multiplechoice2_2, width / 1.5, height / 2);
			CP_Font_DrawText(multiplechoice2_3, width / 1.5, height / 1.5);
			CP_Font_DrawText(multiplechoice2_ans, width / 2.6, height / 1.5);


			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Settings_TextSize(50);
			CP_Font_DrawText("20 marks ", width / 9, height / 1.1);
			CP_Settings_TextSize(70);


			if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q7 == FALSE) && (question_7ans == FALSE))
			{
				if (IsAreaClicked(width / 2.6f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					clicked_q7 = TRUE;
					counter1 = counter1 + 1;

				}
				else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_7ans = TRUE;
				}
				else if (IsAreaClicked(width / 1.5f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_7ans = TRUE;
				}
				else if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_7ans = TRUE;
				}
			}

			if (clicked_q7 == TRUE)
			{
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
				CP_Font_DrawText(" Correct ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5); // false button
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_7 = FALSE;
						question_8 = TRUE;
					}
				}
			}
			if (question_7ans == TRUE)
			{
				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
				CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_7 = FALSE;
						question_8 = TRUE;
					}
				}
			}

		}

		if (question_8 == TRUE)
		{

			int total_score = (counter1 * 20);
			sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

			CP_Settings_TextSize(50);
			CP_Font_DrawText("Current score :", width / 9, height / 8);
			CP_Font_DrawText(totalscore, width / 5, height / 8);

			CP_Settings_TextSize(70);
			CP_Font_DrawText("q8)", width / 3, height / 4);
			CP_Font_DrawText("If x =      and y = ", width / 2, height / 4);
			CP_Font_DrawText(multiplechoice3_xvalue, width / 2.1, height / 4);
			CP_Font_DrawText(multiplechoice3_yvalue, width / 1.63, height / 4);
			CP_Font_DrawText("What does    x -   y equals to  ?", width / 2, height / 3);
			CP_Font_DrawText(multiplechoice3_xconstant, width / 2.165, height / 3);
			CP_Font_DrawText(multiplechoice3_yconstant, width / 1.95, height / 3);


			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5);
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 1.5, 200, 100, 0, 5);// false button
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5);
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 1.5, 200, 100, 0, 5);// true button

			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
			CP_Font_DrawText(multiplechoice3_1, width / 2.6, height / 2);
			CP_Font_DrawText(multiplechoice3_ans, width / 1.5, height / 2);
			CP_Font_DrawText(multiplechoice3_3, width / 1.5, height / 1.5);
			CP_Font_DrawText(multiplechoice3_2, width / 2.6, height / 1.5);


			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Settings_TextSize(50);
			CP_Font_DrawText("20 marks ", width / 9, height / 1.1);
			CP_Settings_TextSize(70);


			if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q8 == FALSE) && (question_8ans == FALSE))
			{
				if (IsAreaClicked(width / 2.6f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_8ans = TRUE;

				}
				else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					clicked_q8 = TRUE;
					counter1 = counter1 + 1;
				}
				else if (IsAreaClicked(width / 1.5f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_8ans = TRUE;
				}
				else if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_8ans = TRUE;
				}
			}

			if (clicked_q8 == TRUE)
			{
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
				CP_Font_DrawText(" Correct ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5); // false button
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_8 = FALSE;
						question_9 = TRUE;
					}
				}
			}
			if (question_8ans == TRUE)
			{
				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
				CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5); // false button
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_8 = FALSE;
						question_9 = TRUE;
					}
				}
			}

		}


		if (question_9 == TRUE)
		{

			int total_score = (counter1 * 20);
			sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

			CP_Settings_TextSize(50);
			CP_Font_DrawText("Current score :", width / 9, height / 8);
			CP_Font_DrawText(totalscore, width / 5, height / 8);

			CP_Settings_TextSize(70);
			CP_Font_DrawText("q9)", width / 3, height / 4);
			CP_Font_DrawText("If x =      and y = ", width / 2, height / 4);
			CP_Font_DrawText(multiplechoice4_xvalue, width / 2.1, height / 4);
			CP_Font_DrawText(multiplechoice4_yvalue, width / 1.63, height / 4);
			CP_Font_DrawText("What does    x -   y equals to  ?", width / 2, height / 3);
			CP_Font_DrawText(multiplechoice4_xconstant, width / 2.165, height / 3);
			CP_Font_DrawText(multiplechoice4_yconstant, width / 1.95, height / 3);


			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5);
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 1.5, 200, 100, 0, 5);// false button
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5);
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 1.5, 200, 100, 0, 5);// true button

			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
			CP_Font_DrawText(multiplechoice4_ans, width / 2.6, height / 2);
			CP_Font_DrawText(multiplechoice4_1, width / 1.5, height / 2);
			CP_Font_DrawText(multiplechoice4_3, width / 1.5, height / 1.5);
			CP_Font_DrawText(multiplechoice4_2, width / 2.6, height / 1.5);


			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Settings_TextSize(50);
			CP_Font_DrawText("20 marks ", width / 9, height / 1.1);
			CP_Settings_TextSize(70);


			if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q9 == FALSE) && (question_9ans == FALSE))
			{
				if (IsAreaClicked(width / 2.6f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_9ans = TRUE;

				}
				else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_9ans = TRUE;
				}
				else if (IsAreaClicked(width / 1.5f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_9ans = TRUE;
				}
				else if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					clicked_q9 = TRUE;
					counter1 = counter1 + 1;
				}
			}

			if (clicked_q9 == TRUE)
			{
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
				CP_Font_DrawText(" Correct ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5); // false button
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_9 = FALSE;
						question_10 = TRUE;
					}
				}
			}
			if (question_9ans == TRUE)
			{
				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
				CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5); // false button
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_9 = FALSE;
						question_10 = TRUE;
					}
				}
			}

		}


		if (question_10 == TRUE)
		{

			int total_score = (counter1 * 20);
			sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

			CP_Settings_TextSize(50);
			CP_Font_DrawText("Current score :", width / 9, height / 8);
			CP_Font_DrawText(totalscore, width / 5, height / 8);

			CP_Settings_TextSize(70);
			CP_Font_DrawText("q10)", width / 3, height / 4);
			CP_Font_DrawText("If x =      and y = ", width / 2, height / 4);
			CP_Font_DrawText(multiplechoice5_xvalue, width / 2.1, height / 4);
			CP_Font_DrawText(multiplechoice5_yvalue, width / 1.63, height / 4);
			CP_Font_DrawText("What does x times y equals to  ?", width / 2, height / 3);

			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5);
			CP_Graphics_DrawRectAdvanced(width / 1.5, height / 1.5, 200, 100, 0, 5);// false button
			CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5);
			CP_Graphics_DrawRectAdvanced(width / 2.6, height / 1.5, 200, 100, 0, 5);// true button

			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
			CP_Font_DrawText(multiplechoice5_ans, width / 2.6, height / 2);
			CP_Font_DrawText(multiplechoice5_1, width / 1.5, height / 2);
			CP_Font_DrawText(multiplechoice5_3, width / 1.5, height / 1.5);
			CP_Font_DrawText(multiplechoice5_2, width / 2.6, height / 1.5);


			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
			CP_Settings_TextSize(50);
			CP_Font_DrawText("20 marks ", width / 9, height / 1.1);
			CP_Settings_TextSize(70);


			if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q10 == FALSE) && (question_10ans == FALSE))
			{
				if (IsAreaClicked(width / 2.6f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_10ans = TRUE;

				}
				else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_10ans = TRUE;
				}
				else if (IsAreaClicked(width / 1.5f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					question_10ans = TRUE;
				}
				else if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
				{
					clicked_q10 = TRUE;
					counter1 = counter1 + 1;
				}
			}

			if (clicked_q10 == TRUE)
			{
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
				CP_Font_DrawText(" Correct ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5); // false button
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{


					question_10 = FALSE;
					fail_page1 = TRUE;

				}
			}
			if (question_10ans == TRUE)
			{
				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
				CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{

					question_10 = FALSE;
					fail_page1 = TRUE;

				}
			}

		}




		if (fail_page1 == TRUE)
		{
			timercounter = false;
			int total_score = (counter1 * 20);
			sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

			if (totalElapsedTime <= 0)
			{
				CP_Font_DrawText("TIMES UP !", width / 2, height / 5.5);
			}


			if (counter1 < 3)
			{

				CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
				CP_Font_DrawText("U HAVE FAIL THE REQUIREMENT", width / 2, height / 4);
				CP_Font_DrawText("You have scored a total of:", width / 2, height / 3);
				CP_Font_DrawText(totalscore, width / 1.4, height / 3);
				CP_Font_DrawText(" Retry quiz ", width / 1.2, height / 1.1);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.2, height / 1.1f, 500.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						counter1 = 0;
						CP_Engine_SetNextGameStateForced(Quiz_Init, Quiz_Update, Quiz_Exit);

					}
				}
			}
			else if (counter1 >= 3)
			{
				CP_Font_DrawText("U HAVE PASS THE REQUIREMENT", width / 2, height / 4);
				CP_Font_DrawText("You have scored a total of:", width / 2, height / 3);
				CP_Font_DrawText(totalscore, width / 1.4, height / 3);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
				CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.1);
				if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
				{
					if (IsAreaClicked(width / 1.2f, height / 1.1f, 500.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);

					}
				}
			}


		}
		 quiz_score =counter*10+ counter1 * 20;

	}
		if (checkpoint_no == 3)
		{
			if (totalElapsedTime <= 0)
			{

				question_11 = false;
				clicked_q11 = false;
				question_11ans = false;

				question_12 = false;
				clicked_q12 = false;
				question_12ans = false;

				question_13 = false;
				clicked_q13 = false;
				question_13ans = false;

				question_14 = false;
				clicked_q14 = false;
				question_14ans = false;

				question_15 = false;
				clicked_q15 = false;
				question_15ans = false;

				fail_page2 = true;

			}
			if (question_11 == TRUE)
			{
				int total_score = (counter2 * 20);
				sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

				CP_Settings_TextSize(50);
				CP_Font_DrawText("Current score :", width / 9, height / 8);
				CP_Font_DrawText(totalscore, width / 5, height / 8);

				CP_Settings_TextSize(70);
				CP_Font_DrawText("q11)", width / 3, height / 4);
				CP_Font_DrawText("If x =      ", width / 2, height / 4);
				CP_Font_DrawText(multiplechoice6_xvalue, width / 1.9, height / 4);
				CP_Font_DrawText("What does    x +    equals to  ?", width / 2, height / 3);
				CP_Font_DrawText(multiplechoice6_xconstant, width / 2.165, height / 3);
				CP_Font_DrawText(multiplechoice6_yconstant, width / 1.9, height / 3);


				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
				CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5);
				CP_Graphics_DrawRectAdvanced(width / 1.5, height / 1.5, 200, 100, 0, 5);// false button
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
				CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5);
				CP_Graphics_DrawRectAdvanced(width / 2.6, height / 1.5, 200, 100, 0, 5);// true button

				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
				CP_Font_DrawText(multiplechoice6_1, width / 2.6, height / 2);
				CP_Font_DrawText(multiplechoice6_2, width / 1.5, height / 2);
				CP_Font_DrawText(multiplechoice6_3, width / 1.5, height / 1.5);
				CP_Font_DrawText(multiplechoice6_ans, width / 2.6, height / 1.5);


				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Settings_TextSize(50);
				CP_Font_DrawText("20 marks ", width / 9, height / 1.1);
				CP_Settings_TextSize(70);


				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q11 == FALSE) && (question_11ans == FALSE))
				{
					if (IsAreaClicked(width / 2.6f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						clicked_q11 = TRUE;
						counter2 = counter2 + 1;

					}
					else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_11ans = TRUE;
					}
					else if (IsAreaClicked(width / 1.5f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_11ans = TRUE;
					}
					else if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_11ans = TRUE;
					}
				}

				if (clicked_q11 == TRUE)
				{
					CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
					CP_Font_DrawText(" Correct ", width / 1.9, height / 1.5);
					CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
					CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5); // false button
					CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
					CP_Font_DrawText(" Next ", width / 1.1, height / 1.1);
					if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
					{
						if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
						{
							question_11 = FALSE;
							question_12 = TRUE;
						}
					}
				}
				if (question_11ans == TRUE)
				{
					CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
					CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
					CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
					CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
					CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
					CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
					if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
					{
						if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
						{
							question_11 = FALSE;
							question_12 = TRUE;
						}
					}
				}
			}
		
			if (question_12 == TRUE)
			{
				int total_score = (counter2 * 20);
				sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

				CP_Settings_TextSize(50);
				CP_Font_DrawText("Current score :", width / 9, height / 8);
				CP_Font_DrawText(totalscore, width / 5, height / 8);

				CP_Settings_TextSize(70);
				CP_Font_DrawText("q12)", width / 3, height / 4);
				CP_Font_DrawText("If x =      ", width / 2, height / 4);
				CP_Font_DrawText(multiplechoice7_xvalue, width / 1.9, height / 4);
				CP_Font_DrawText("What does    x -    equals to  ?", width / 2, height / 3);
				CP_Font_DrawText(multiplechoice7_xconstant, width / 2.165, height / 3);
				CP_Font_DrawText(multiplechoice7_yconstant, width / 1.9, height / 3);


				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
				CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5);
				CP_Graphics_DrawRectAdvanced(width / 1.5, height / 1.5, 200, 100, 0, 5);// false button
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
				CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5);
				CP_Graphics_DrawRectAdvanced(width / 2.6, height / 1.5, 200, 100, 0, 5);// true button

				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
				CP_Font_DrawText(multiplechoice7_ans, width / 2.6, height / 2);
				CP_Font_DrawText(multiplechoice7_2, width / 1.5, height / 2);
				CP_Font_DrawText(multiplechoice7_3, width / 1.5, height / 1.5);
				CP_Font_DrawText(multiplechoice7_1, width / 2.6, height / 1.5);


				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Settings_TextSize(50);
				CP_Font_DrawText("20 marks ", width / 9, height / 1.1);
				CP_Settings_TextSize(70);


				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q12 == FALSE) && (question_12ans == FALSE))
				{
					if (IsAreaClicked(width / 2.6f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_12ans = TRUE;

					}
					else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_12ans = TRUE;
					}
					else if (IsAreaClicked(width / 1.5f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_12ans = TRUE;
					}
					else if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						clicked_q12 = TRUE;
						counter2 = counter2 + 1;
					}
				}

				if (clicked_q12 == TRUE)
				{
					CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
					CP_Font_DrawText(" Correct ", width / 1.9, height / 1.5);
					CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
					CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5); // false button
					CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
					CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
					if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
					{
						if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
						{
							question_12 = FALSE;
							question_13 = TRUE;
						}
					}
				}
				if (question_12ans == TRUE)
				{
					CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
					CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
					CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
					CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
					CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
					CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
					if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
					{
						if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
						{
							question_12 = FALSE;
							question_13 = TRUE;
						}
					}
				}
			}



			if (question_13 == TRUE)
			{
				int total_score = (counter2 * 20);
				sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

				CP_Settings_TextSize(50);

				CP_Settings_TextSize(50);
				CP_Font_DrawText("Current score :", width / 9, height / 8);
				CP_Font_DrawText(totalscore, width / 5, height / 8);

				CP_Settings_TextSize(70);
				CP_Font_DrawText("q13)", width / 3, height / 4);
				CP_Font_DrawText("If x =      ", width / 2, height / 4);
				CP_Font_DrawText(multiplechoice8_xvalue, width / 1.9, height / 4);
				CP_Font_DrawText("What does    x +    equals to  ?", width / 2, height / 3);
				CP_Font_DrawText(multiplechoice8_xconstant, width / 2.165, height / 3);
				CP_Font_DrawText(multiplechoice8_yconstant, width / 1.9, height / 3);

				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
				CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5);
				CP_Graphics_DrawRectAdvanced(width / 1.5, height / 1.5, 200, 100, 0, 5);// false button
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
				CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5);
				CP_Graphics_DrawRectAdvanced(width / 2.6, height / 1.5, 200, 100, 0, 5);// true button

				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
				CP_Font_DrawText(multiplechoice8_ans, width / 2.6, height / 2);
				CP_Font_DrawText(multiplechoice8_1, width / 1.5, height / 2);
				CP_Font_DrawText(multiplechoice8_3, width / 1.5, height / 1.5);
				CP_Font_DrawText(multiplechoice8_2, width / 2.6, height / 1.5);


				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Settings_TextSize(50);
				CP_Font_DrawText("20 marks ", width / 9, height / 1.1);
				CP_Settings_TextSize(70);


				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q13 == FALSE) && (question_13ans == FALSE))
				{
					if (IsAreaClicked(width / 2.6f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_13ans = TRUE;

					}
					else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_13ans = TRUE;
					}
					else if (IsAreaClicked(width / 1.5f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_13ans = TRUE;
					}
					else if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						clicked_q13 = TRUE;
						counter2 = counter2 + 1;
					}
				}

				if (clicked_q13 == TRUE)
				{
					CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
					CP_Font_DrawText(" Correct ", width / 1.9, height / 1.5);
					CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
					CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5); // false button
					CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
					CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
					if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
					{
						if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
						{
							question_13 = FALSE;
							question_14 = TRUE;
						}
					}
				}
				if (question_13ans == TRUE)
				{
					CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
					CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
					CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
					CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
					CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
					CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
					if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
					{
						if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
						{
							question_13 = FALSE;
							question_14 = TRUE;
						}
					}
				}

			}

			if (question_14 == TRUE)
			{
				int total_score = (counter2 * 20);
				sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

				CP_Settings_TextSize(50);
				CP_Font_DrawText("Current score :", width / 9, height / 8);
				CP_Font_DrawText(totalscore, width / 5, height / 8);

				CP_Settings_TextSize(70);
				CP_Font_DrawText("q14)", width / 3, height / 4);
				CP_Font_DrawText("If x =      ", width / 2, height / 4);
				CP_Font_DrawText(multiplechoice9_xvalue, width / 1.9, height / 4);
				CP_Font_DrawText("What does    x times    equals to  ?", width / 2, height / 3);
				CP_Font_DrawText(multiplechoice9_xconstant, width / 2.3, height / 3);
				CP_Font_DrawText(multiplechoice9_yconstant, width / 1.8, height / 3);


				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
				CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5);
				CP_Graphics_DrawRectAdvanced(width / 1.5, height / 1.5, 200, 100, 0, 5);// false button
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
				CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5);
				CP_Graphics_DrawRectAdvanced(width / 2.6, height / 1.5, 200, 100, 0, 5);// true button

				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
				CP_Font_DrawText(multiplechoice9_1, width / 2.6, height / 2);
				CP_Font_DrawText(multiplechoice9_ans, width / 1.5, height / 2);
				CP_Font_DrawText(multiplechoice9_3, width / 1.5, height / 1.5);
				CP_Font_DrawText(multiplechoice9_2, width / 2.6, height / 1.5);


				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Settings_TextSize(50);
				CP_Font_DrawText("20 marks ", width / 9, height / 1.1);
				CP_Settings_TextSize(70);


				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q14 == FALSE) && (question_14ans == FALSE))
				{
					if (IsAreaClicked(width / 2.6f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_14ans = TRUE;

					}
					else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						clicked_q14 = TRUE;
						counter2 = counter2 + 1;
					}
					else if (IsAreaClicked(width / 1.5f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_14ans = TRUE;
					}
					else if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_14ans = TRUE;
					}
				}

				if (clicked_q14 == TRUE)
				{
					CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
					CP_Font_DrawText(" Correct ", width / 1.9, height / 1.5);
					CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
					CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5); // false button
					CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
					CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
					if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
					{
						if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
						{
							question_14 = FALSE;
							question_15 = TRUE;
						}
					}
				}
				if (question_14ans == TRUE)
				{
					CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
					CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
					CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
					CP_Graphics_DrawRectAdvanced(width / 1.1, height / 1.1, 200, 100, 0, 5);
					CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
					CP_Font_DrawText(" Next", width / 1.1, height / 1.1);
					if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
					{
						if (IsAreaClicked(width / 1.1f, height / 1.1f, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
						{
							question_14 = FALSE;
							question_15 = TRUE;
						}
					}
				}

			}


			if (question_15== TRUE)
			{
				int total_score = (counter2 * 20);
				sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

				CP_Settings_TextSize(50);
				CP_Font_DrawText("Current score :", width / 9, height / 8);
				CP_Font_DrawText(totalscore, width / 5, height / 8);

				CP_Settings_TextSize(70);
				CP_Font_DrawText("q15)", width / 3, height / 4);
				CP_Font_DrawText("If x =      and y = ", width / 2, height / 4);
				CP_Font_DrawText(multiplechoice10_xvalue, width / 2.1, height / 4);
				CP_Font_DrawText(multiplechoice10_yvalue, width / 1.63, height / 4);
				CP_Font_DrawText("What does x times y equals to  ?", width / 2, height / 3);

				CP_Settings_Fill(CP_Color_Create(255, 0, 0, 50));
				CP_Graphics_DrawRectAdvanced(width / 1.5, height / 2, 200, 100, 0, 5);
				CP_Graphics_DrawRectAdvanced(width / 1.5, height / 1.5, 200, 100, 0, 5);// false button
				CP_Settings_Fill(CP_Color_Create(0, 255, 0, 50));
				CP_Graphics_DrawRectAdvanced(width / 2.6, height / 2, 200, 100, 0, 5);
				CP_Graphics_DrawRectAdvanced(width / 2.6, height / 1.5, 200, 100, 0, 5);// true button

				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
				CP_Font_DrawText(multiplechoice10_3, width / 2.6, height / 2);
				CP_Font_DrawText(multiplechoice10_1, width / 1.5, height / 2);
				CP_Font_DrawText(multiplechoice10_ans, width / 1.5, height / 1.5);
				CP_Font_DrawText(multiplechoice10_2, width / 2.6, height / 1.5);


				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
				CP_Settings_TextSize(50);
				CP_Font_DrawText("20 marks ", width / 9, height / 1.1);
				CP_Settings_TextSize(70);


				if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT) && (clicked_q15 == FALSE) && (question_15ans == FALSE))
				{
					if (IsAreaClicked(width / 2.6f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_15ans = TRUE;

					}
					else if (IsAreaClicked(width / 1.5f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_15ans = TRUE;
					}
					else if (IsAreaClicked(width / 1.5f, height / 1.5, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						clicked_q15 = TRUE;
						counter2 = counter2 + 1;
					}
					else if (IsAreaClicked(width / 2.6f, height / 2, 200.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
					{
						question_15ans = TRUE;
					}
				}

				if (clicked_q15 == TRUE)
				{
					CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
					CP_Font_DrawText(" Correct ", width / 1.9, height / 1.5);
					CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
					CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5); // false button
					CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
					CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.1);
					if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
					{


						question_15 = FALSE;
						fail_page2= TRUE;

					}
				}
				if (question_15ans == TRUE)
				{
					CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
					CP_Font_DrawText(" Wrong ", width / 1.9, height / 1.5);
					CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
					CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5);
					CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
					CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.1);
					if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
					{

						question_15 = FALSE;
						fail_page2 = TRUE;

					}
				}

			}







			if (fail_page2 == TRUE)
			{
				timercounter = false;
				int total_score = (counter2 * 20);
				sprintf_s(totalscore, _countof(totalscore), "%d", total_score);

				if (totalElapsedTime <= 0)
				{
					CP_Font_DrawText("TIMES UP !", width / 2, height / 5.5);
				}

				if (counter2 < 3)
				{

					CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
					CP_Font_DrawText("U HAVE FAIL THE REQUIREMENT", width / 2, height / 4);
					CP_Font_DrawText("You have scored a total of:", width / 2, height / 3);
					CP_Font_DrawText(totalscore, width / 1.4, height / 3);
					CP_Font_DrawText(" Retry quiz ", width / 1.2, height / 1.1);
					CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
					CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5);
					if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
					{
						if (IsAreaClicked(width / 1.2, height / 1.1f, 500.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
						{
							counter2 = 0;
							CP_Engine_SetNextGameStateForced(Quiz_Init, Quiz_Update, Quiz_Exit);

						}
					}
				}
				else if (counter2 >= 3)
				{
					CP_Font_DrawText("U HAVE PASS THE REQUIREMENT", width / 2, height / 4);
					CP_Font_DrawText("You have scored a total of:", width / 2, height / 3);
					CP_Font_DrawText(totalscore, width / 1.4, height / 3);
					CP_Settings_Fill(CP_Color_Create(255, 255, 255, 0));
					CP_Graphics_DrawRectAdvanced(width / 1.2, height / 1.1, 500, 100, 0, 5);
					CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
					CP_Font_DrawText(" Continue game ", width / 1.2, height / 1.1);
					if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
					{
						if (IsAreaClicked(width / 1.2f, height / 1.1f, 500.f, 100.f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
						{
							CP_Engine_SetNextGameState(Level_Init, Level_Update, Level_Exit);

						}
					}
				}


			}


		quiz_score = counter * 10 + counter1*20 + counter2*20;
	}

	
	// Pressing Q to exit the program
	if (CP_Input_KeyTriggered(KEY_ESCAPE))
	{
		counter = 0;
		counter1 = 0;
		counter2 = 0;
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit); 
	}			
	
		          
}
void Quiz_Exit()
{

}