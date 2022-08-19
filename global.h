#ifndef _GLOBAL_H_
#define _GLOBAL_H_
#include <string.h>
using namespace std;
#define WIDTH 100 			 //main screen width (to the sidemost)
#define HEIGHT 30 		 	  //total height
#define MAIN_SCREEN 70		 //width of the playing field


int testscore;				//declaring variable
int highest[3]={0,0,0};			//initializing array for highest value and assigning initial //value 0
int level;				//initializing variable for choosing levels
int speed;				//initializing variable for choosing speed
string Name;				//initializing variable for saving player’s name

//array for storing coordinates of the enemy car	
int enemyX[3]; 			
int enemyY[3];


int flag[3];				// array for checking whether to generate enemy or not
int startcarY=HEIGHT-4;		//initial y coordinate for the generated car
int carposition=(MAIN_SCREEN/2)-1;	///initial x coordinate for the generated car
int score=0;				//initializing variable for score
int option;				//initializing variable for storing user’s input option
int sec_prev=0;			//initializing variable for starting time (seconds)
int A=0;				//initializing variable
int diff;					//initializing variable for saving the total played time
char *start_time;		//initializing variable for starting time

//ascii values of needed symbols
char full = 219; 			//dark full block
char top = 223;			
char bottom = 220;			
char block =219;			//dark full block
char block1=176;			
char block2=177;
char block3=178;
char line=205;
char line2=186;
char O=233;
char S=48;

//assigning appearance of the car
char car[4][4]={' ',block3,' ',block3,		
				'*','*','*','*',
				'*','*','*','*',
				' ',block3,' ',block3};
				
//assigning appearance of the number ‘1’			
char one[6][6]={' ',' ',' ',' ','#',' ',
				' ',' ',' ','#','#',' ',
				' ',' ','#',' ','#',' ',
				' ','#',' ',' ','#',' ',
				' ',' ',' ',' ','#',' ',
				' ',' ',' ',' ','#',' '};
//assigning appearance of the number ‘2’
char two[6][6]={' ',' ','#',' ',' ',' ',
				' ','#',' ','#',' ',' ',
				' ',' ',' ',' ','#',' ',
				' ',' ',' ','#',' ',' ',
				' ',' ','#',' ',' ',' ',
				' ','#','#','#','#','#'};

//assigning appearance of the number ‘3’			
char three[7][7]={  ' ','#','#',' ',' ',' ',' ',
			    	'#',' ',' ','#',' ',' ',' ',
				    ' ',' ',' ','#',' ',' ',' ',
				    ' ','#','#','#',' ',' ',' ',
					' ',' ',' ','#',' ',' ',' ',
					'#',' ',' ','#',' ',' ',' ',
					' ','#','#',' ',' ',' ',' ',};

//defining structure to store player info
struct contacts {
    string name;		
    int score;
    string time;
};

contacts a[10],b[10];					//assigning initial values

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursor;			


//function to point to the coordinates passed to the function	
void position(int x,int y)
{
	cursor.X=x;
	cursor.Y=y;
	SetConsoleCursorPosition(console, cursor);
}


#endif

