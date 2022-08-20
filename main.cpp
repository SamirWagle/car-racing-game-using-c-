//including required header files
#include<iostream>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<sstream>
#include <fstream>
#include<cmath>

//including self-made header files
#include "classparent.cpp"
#include"classmode.cpp"
#include "global.h"

using namespace std;

int main()
{
	
	
	parent p;					//creating object to class ‘parent’
	p.menu1();					//calling the function ‘menu1’ from ‘parent’ class
	modee e;					//creating object to the class ‘modee’
	
	system("cls");					//clearing the whole window
//	fout.open("sample14.csv",ios::app);
//		fout <<Name<<",";

//creating do-while loop for starting the game
		do{
		
		p.menu2();				//calling the function ‘menu2’ from’parent’ class
		
//using switch() according to the passed value
	switch(option)
	{
//executing if option is ‘1’
		case 1:
			e.mode();			//calling a function ‘play’’ from class ‘modee‘
			
//using switch() according to the passed value
switch(level)
			{
				//executing if option is ‘1’
				case 1:
					e.play(80,1,1);	//calling a function ‘play’ from class ‘modee’
					break;		
				//executing if option is ‘2’
				case 2:
					e.play(40,2,2);	//calling a function ‘play’ from class ‘modee’
					break;
				//executing if option is ‘3’
				case 3:
					e.play(20,3,4);	//calling a function ‘play’ from class ‘modee’

					break;	
			}
			break;
		
//executing if option is ‘2’
		case 2:
			p.instruction();	//calling the function ‘instruction’ from ’parent’ class
			getch();		
			break;
		
//executing if option is ‘3’
		case 3:
			p.leaderboard();		//calling the function ‘leaderboard’’ from ’parent’ class
			break;
		
//executing if option is ‘4’
		case 4:
			exit(1);		//exiting the program
			break;
			
		}
	}while(1);			
			
			
	return 0;

}			



