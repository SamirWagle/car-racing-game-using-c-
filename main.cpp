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
