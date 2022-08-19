#include "class.h"
using namespace std;


/**defining function
*@brief function to change the color of the text
* @return void
*/
void parent::color(int i){
	SetConsoleTextAttribute(console, i);    }

/**defining function
*@brief function to set the text in the center of the main screen
* @return space
*/
int parent::center(string s){
	int spaces = ( WIDTH- s.size() ) / 2;	//variable to store the center of width of the terminal
	return spaces;
}

/**defining function
*@brief function to change the color of the text
*@param tt variable to save local time 
* @return local time in character data type 
*/

char* parent::timme()
{	
	time_t t;
	struct tm * tt; 		// decalring variable for localtime()
	time (&t); 				//passing argument to time()
	tt = localtime(&t);				
	return asctime(tt);			
}
	

/**defining function
*@brief function to print main menu1 at the start
*@param text_1 string to save certain texts as required
* @return void 
*/
void parent::menu1()
{
	system("Color 0A");				//changes the text color to green
	system("cls");					//clearing the whole screen
	
	//printing the text in the center of the main screen
	string text_1="-----------------------------";
	position(center(text_1),4);		//calling the position() function
		cout<<text_1;
	text_1="|        Car Race Game        |";
	position(center(text_1),5);
		cout<<text_1;
	text_1="-----------------------------";
	position(center(text_1),6);
		cout<<text_1;
	text_1="ENTER THE PLAYER'S NAME:";
	position(center(text_1),10);
		cout<<text_1;
		getline(cin,Name);			//storing the user’s name 
	
}
	
/**defining function
*@brief function to print menu 2
*@param text_1 string to save certain texts as required
* @return void 
*/

void parent::menu2()
{		
		system("Color 0A");			//changes the text color to green
		system("cls");				//clearing the whole screen
		
		//printing the text in the center of the main screen
		string text_1="-----------------------------";
		position(center(text_1),4);
			cout<<text_1;
		text_1="|        Car Race Game        |";
		position(center(text_1),5);
			cout<<text_1;
		text_1="-----------------------------";
		position(center(text_1),6);
			cout<<text_1;
		text_1="1. Start Game";
		position(center(text_1),10);
			cout<<text_1;
		text_1="2. Instructions";
		position(center(text_1),12);
			cout<<text_1;
		text_1= "3. Leaderboard";
		position(center(text_1),14);
			cout<<text_1;
		text_1= "4. Quit";
		position(center(text_1),16);
			cout<<text_1;
		text_1= "Select option:";
		position(center(text_1),18);
			cout<<text_1;
			cin>>option;			//stores the user’s option 
		system("cls");				//clearing the whole screen
}	
	
	/**defining function
*@brief function to print Game Over page
*@param text_2 string to save certain texts as required
*@param text_3 string to save certain texts as required
*@param text_2_length int data type to save the size of the text entered
*@param text_3_length int data type to save the size of the text entered
*@param end variable to save the game over time
*@return void 
*/

void parent::game_Over()
{
	
	time_t end=time(0);		
	string text_2, text_3;
	
	color(12);			//calling the color function to change the color to red
	
	//printing the text in the center of the main screen
	text_2="-----------------------";
		position(center(text_2),4);
			cout<<text_2;
	text_2="|        GAME OVER        |";
	position(center(text_2),5);
		cout<<text_2;
	text_2="-----------------------";
		position(center(text_2),6);
			cout<<text_2;
	
	color(10);			//calling the color function

	
	text_2="PLAYER'S NAME: ";
	text_3=Name;
	
	//defining the variable to save the length of text_2 and name
	int text_2_length=text_2.size();
	int text_3_length=Name.size();

	//to align the text at the center
	int text_length= ( WIDTH-(text_2_length +text_3_length)) / 2;
	position(text_length,10);

	//printing the text
	cout<<text_2;
	cout<<text_3;
	
	text_2="SCORE ==> ";
	position(center(text_2),12);
		cout<<text_2<<score;
	text_2="PLAYED TIME ==> ";
	position(center(text_2),14);
		cout<<text_2;
		cout<<diff<<" sec";
		
	text_2="PRESS ENTER KEY TO CONTINUE";
	position(center(text_2),17);
		cout<<text_2;
	fflush(stdin); getchar();		
}
	
/**defining function
*@brief function to print Instruction page
*@param text_1 string to save certain texts as required
*@return void 
*/

	
void parent:: instruction()
{
	system("Color 0A");			//change the text color to green
	string text1="----------------------------";
		position(center(text1),4);
			cout<<text1;
	text1="|        Instructions        |";
		position(center(text1),5);
			cout<<text1;
	text1="----------------------------";
		position(center(text1),6);
			cout<<text1;
	text1="Avoid Cars by moving left or right ";
		position(center(text1),9);
			cout<<text1;
	text1="Press 'A' or '<==' to move left";
		position(center(text1),11);
			cout<<text1;
	text1="Press 'D' or '==>' to move right";
		position(center(text1),13);
			cout<<text1;
	text1="Press 'Esc' to exit";
		position(center(text1),15);
			cout<<text1;
	text1="Press any key to go back to menu";
		position(center(text1),19);
			cout<<text1;
			
}

	/**defining function
*@brief function to print the clock 
*@param seconds[a] array to save seconds
*@param minutes[a] array to save minutes
*@param hours[a] array to save hour
*@param str string to save ‘AM’ or ‘PM’
*@return void 
*/
	
void parent:: print_Clock(int a)
{
  
    int seconds[a], minutes[a], hours[a];
    string str;
  
    //storing total seconds passed
    time_t total_seconds=time(0);
  
    //getting values of seconds, minutes and hours
    struct tm* ct=localtime(&total_seconds);
  
    seconds[a]=ct->tm_sec;
    minutes[a]=ct->tm_min;
    hours[a]=ct->tm_hour;
    
    //converting it into 12 hour format
    if(hours[a]>=12)
      str="PM";
    else
      str="AM";
    hours[a]=hours[a]>12?hours[a]-12:hours[a];  
    
    
    //printing the result
    color(10);
    if(seconds[a]==sec_prev+1 || (sec_prev==59 && seconds[a]==0))
    {
		position(MAIN_SCREEN + 6, 19);
      cout<< (hours[a]<10?"0":"") << hours[a] <<":" << (minutes[a]<10?"0":"") << minutes[a] << ":" << (seconds[a]<10?"0":"") << seconds[a] << " " << str;
    }
    
    sec_prev=seconds[a];
    
  }
  

	
/**defining function
*@brief function to print the border in the main scren
*@return void 
*/
void parent::draw_Border()
{
	system("Color 0A");

	//using for loop to print the border
	for(int j=0;j<HEIGHT;j++)
	{	
		position(16,j);
		cout<<line2;
		position(54,j);
		cout<<line2;
		for(int i=0;i<16;i++)
		{
			position(i,j);	
				cout<<block1;
			position(MAIN_SCREEN-i,j);
				cout<<block1;	
		}
		
		for(int j=0;j<HEIGHT;j++)
		{
			position(WIDTH,j);
					cout<<block<<block2<<block1;
		}
		
	}
	for(int i=0;i<WIDTH;i++)
		{
			position(i,HEIGHT+1);
			cout<<line;
		}	
}
	
	
/**defining function
*@brief function to print score 
*@return void 
*/

void parent:: updateScore()
{

	position(MAIN_SCREEN + 7, 5);
	color(10);
	cout<<"Score: "<<score<<endl;		// printing the score
}    
	
	/**defining function
*@brief function to print instruction at the side of the main screen
*@return void 
*/

void parent:: side_Instruction()
{
	position(MAIN_SCREEN + 5, 4);
		cout<<"-----------";
	position(MAIN_SCREEN + 5, 6);
		cout<<"------------";
	position(MAIN_SCREEN + 5, 10);
		cout<<"---------------";
	position(MAIN_SCREEN + 7, 11);
		cout<<"INSTRUCTION";
	position(MAIN_SCREEN + 5, 12);
		cout<<"---------------";
	position(MAIN_SCREEN + 5, 13);
		cout<<"PRESS:";
	position(MAIN_SCREEN + 5, 14);
		cout<<"A or <-- for left";
	position(MAIN_SCREEN + 5, 15);
		cout<<"D or --> for right";	
	position(MAIN_SCREEN + 5, 16);
		cout<<"------------------";
	position(MAIN_SCREEN + 5, 18);
		cout<<"-------------";
	position(MAIN_SCREEN + 5, 20);
		cout<<"-------------";
		
	
		
} 
	
	/**defining function
*@brief function to print the main car
*@return void 
*/
void parent:: print_Car()
{
	color(10);

	// using for loop to print the appearance of the car
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++)
		{
			position(carposition+i,j+startcarY);
			cout<<car[i][j];
		}
	}
}
	
	/**defining function
*@brief function to erase the printed car
*@return void 
*/
void parent:: erase_Car()
{
	//using for loop to erase the printed car
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++)
		{
			position(carposition+i,j+startcarY);
			cout<<" ";
		}
	}	
}
	
	/**defining function
*@brief function to give the x coordinate for generating the enemy car
*@return void 
*/
void parent:: gen_Enemy(int ind)
{
	int s=rand();
		enemyX[ind] = 17 + s%(33);	    //setting random position on the main field
}

	/**defining function
*@brief function to print the enemy car
*@param flag[ind] variable to check whether to print the next enemy car or not
*@return void 
*/
void parent:: print_Enemy(int ind)
{
		color(12);
		// if the condition is fulfilled then print the enemy
		if(flag[ind]==1)
		{
			position(enemyX[ind], enemyY[ind]);   cout<<block3<<"**"<<block3;   
			position(enemyX[ind], enemyY[ind]+1); cout<<" ** "; 
			position(enemyX[ind], enemyY[ind]+2); cout<<block3<<"**"<<block3; 
			position(enemyX[ind], enemyY[ind]+3); cout<<" "<<block2<<block2<<" ";
		}
		
}

	/**defining function
*@brief function to erase the printed enemy
*@return void 
*/

void parent::erase_Enemy(int ind)
{
	if( flag[ind] == true ){
		position(enemyX[ind], enemyY[ind]); cout<<"    ";  //x,1
		position(enemyX[ind], enemyY[ind]+1); cout<<"    "; //x,2
		position(enemyX[ind], enemyY[ind]+2); cout<<"    "; //x,3
		position(enemyX[ind], enemyY[ind]+3); cout<<"    "; //x,4
	} 
}
	
	/**defining function
*@brief function to check whether the cars collide or not
*@param x integer data type containing value of 1 or 0
*@return true if collision happens, otherwise return false 
*/

int parent::collision(int ind)
{
	int x;
	if( enemyY[ind]+4 >= HEIGHT-2){
		if( enemyX[ind]+ 4 - carposition >= 0 && enemyX[ind] + 4 -carposition < 9  ){
			x= 1;
		}
	}
	return x;
} 
	
	/**defining function
*@brief function to erase the enemy and set the coordinate for new enemy
*@return 0
*/

void parent::reset(int ind)
{
	erase_Enemy(ind);			//erases the enemy
	enemyY[ind] = 1;  // coordinate of new enemy of y axis
	gen_Enemy(ind);			//generates the enemy coordinate
}

	/**defining function
*@brief function to move the enemy car downwards
*@param sleep integer data type to set the speed of enemy car
*@param q integer data type to increase the score according to the level
*@return void
*/
	
void parent::downward(int ind,int sleep,int q)
{

	print_Enemy(ind);			//print the first enemy
	print_Enemy(ind+1);			//print the second enemy
	Sleep(sleep);				//sets the speed for the enemy
	erase_Enemy(ind);			//erase the first enemy
	erase_Enemy(ind+1);			//erase the second enemy

	//checking the condition for appearance of second enemy
	if(enemyY[1]==13)	
	{
		if(flag[2]==0)
		{
			flag[2]=1;
		}
	}
	
	//moving the enemy downwards 
	if(flag[ind] == 1 )
			{enemyY[ind] += 1;}
	if(flag[ind+1] == 1 )
			{enemyY[ind+1] += 1;}

	//moving the car left or right as the user wants
	if(kbhit()==1)
	{
		//taking the input from the user
		char ch=getch();
		//Moving the car towards the left 
		if( ch=='a' || ch=='A'||ch==75 )		
		{
			if( carposition > 19 )
			{
				erase_Car();
				carposition -= 4;
				print_Car();
			}
				
		}
		//Moving the car towards the right
		if( ch=='d' || ch=='D'|| ch==77  )
		{
			if( carposition < 50 )
			{
				erase_Car();
				carposition += 4;
				print_Car();
			}
		}
	}
	
	//checking the condition if the enemy has reached the bottom or not
	if( enemyY[ind] > HEIGHT-4 ){
			reset(ind);			//calling reset() function
			score=score+q;		//increasing the score
			//Beep(1000,10);
			updateScore();		//calling
	}		

	if( enemyY[ind+1] > HEIGHT-4 ){
			reset(ind+1);	
			score=score+q;
			//Beep(1000,10);
			updateScore();}	
}

	/**defining function
*@brief function to print highest score using file handling in excel
*@param testname string to name 
*@param testtime string to store the played time 
*@return void
*/

void parent::highest()
{
	string testname=Name;
	string testtime=to_string(diff);		//to_string changes the integer to string type
	ifstream file;
	file.open("highest.csv",ios::app);		//opening the file
	string s;
	//checking if file is open or not
   if (file.is_open()) 
	{
	// getting the data from the excel
        for (int i = 0; i <= 3; i++) {		
            getline(file,a[i].name,',');
            getline(file,s,',');
            getline(file,a[i].time);
            stringstream qw(s);
            qw>>a[i].score;
        }   
    }
    
    else {
        cout << "Error";					//if not opened
    }
    int i=0;
  

//while loop to sort the leaderboard for the first three highest scorers in excel
   while(i<3){
    	if(a[i].score<testscore)
		{
			
			
			a[i+2].score=a[i+1].score;
			a[i+2].name=a[i+1].name;
			a[i+2].time=a[i+1].time;
			
			a[i+1].score=a[i].score;
			a[i+1].name=a[i].name;
			a[i+1].time=a[i].time;
			
			a[i].score=testscore;
			a[i].name=testname;
			a[i].time=testtime;
			
			cout<<i<<endl;;
			break;
		}
		else{i++;
		}	
	}

	//for (int i = 0; i < 3; i++) {
         //   cout << "Name :      " << a[i].name << endl;
	//	      
   	//cout<< "Nick :   " << a[i].score << endl;}
	
	//clearing the previous old file and opening a new file
   	 fout1.open("highest.csv",ios::trunc);
	//putting the data in excel
   	 for (int i = 0; i < 3; i++) {
       	fout1<< a[i].name <<",";
 		fout1<< a[i].score <<",";
	 	fout1<<a[i].time<< endl;  
		       
	}
	fout1.close();					//closes the file
} 
	
/**defining function
*@brief function to print the leaderboard page
*@return void
*/

     
void parent::leaderboard()
{
	system("Color 0A");				//changes the text color to green
	//printing the text in center if the terminal
	string text1="----------------------------";
		position(center(text1),4);
			cout<<text1;
	text1="|        Leaderboard        |";
		position(center(text1),5);
			cout<<text1;
	text1="----------------------------";
		position(center(text1),6);
			cout<<text1;
	ifstream file1;
    file1.open("highest.csv",ios::app);			//opening the file
	string s1;
	if (file1.is_open()) {
	//getting the data from the excel and saving it into the structure
        for (int i = 0; i <= 3; i++) {
            getline(file1,b[i].name,',');
            getline(file1,s1,',');
            getline(file1,b[i].time);
            stringstream qw1(s1);
            qw1>>b[i].score;
            
            position((MAIN_SCREEN/4),8);	
				cout<<"S.N.";
			position((2)*(MAIN_SCREEN/4),8);
				cout<<"NAME";
			position((3)*(MAIN_SCREEN/4),8);
				cout<<"SCORE";
			position((4)*(MAIN_SCREEN/4),8);
				cout<<"TIME";
	//printing the data from the structure			
            for(int i=0;i<3;i++)
			{
					int j=1;
					
					position((j)*(MAIN_SCREEN/4),10+(3*i));	
					cout<<i+1;
					position((j+1)*(MAIN_SCREEN/4),10+(3*i));
					cout<<b[i].name;
					position((j+2)*(MAIN_SCREEN/4),10+(3*i));
					cout<<b[i].score;
					position((j+3)*(MAIN_SCREEN/4),10+(3*i));
					cout<<b[i].time<<" sec.";
					

			}
        }   
    }
    //if file is not openedd
    else {
    	position (MAIN_SCREEN/2,7);
        cout << "Error";
    }
	
	
	getch();
}
	
	

