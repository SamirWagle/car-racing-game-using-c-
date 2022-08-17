#ifndef _CLASS_H_
#define _CLASS_H_

#include "global.h"			//including header file
ofstream fout1;
ofstream fout;
class parent{
	public:
	void color(int i);

	int center(string s);
	
	char* timme();
	
	void menu1();
	void menu2();
	void game_Over();	
	void instruction();
	void print_Clock(int a);
	  
	void draw_Border();
	
	void updateScore();
	void side_Instruction();
	void print_Car();
	void erase_Car();
	void gen_Enemy(int ind);
	void print_Enemy(int ind);
	void erase_Enemy(int ind);
	int collision(int ind);
	void reset(int ind);
	
	void downward(int ind,int sleep,int q);
	void highest(); 
	void leaderboard();
};

class modee:public parent{
	public:
		void mode();
	void countdown();
	void play(int x ,int s,int z);
	
};

#endif

