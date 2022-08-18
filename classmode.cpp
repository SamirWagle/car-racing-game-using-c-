#include"class.h"										//including header file
using namespace std;

void modee::mode()
	{
	system("Color 0A");
		system("cls");
		string text_1="-----------------------------";
		position(center(text_1),4);						//calling the position() function to align at the center
			cout<<text_1;
		text_1="|        Car Race Game        |";
		position(center(text_1),5);
			cout<<text_1;
		text_1="-----------------------------";
		position(center(text_1),6);
			cout<<text_1;
		text_1="1.EASY  MODE";
		position(center(text_1),10);
			cout<<text_1;
		text_1="2. MEDIUM MODE";
		position(center(text_1),12);
			cout<<text_1;
		text_1= "3.HARD MODE";
		position(center(text_1),14);
			cout<<text_1;
		text_1= "Select option:";
		position(center(text_1),16);
			cout<<text_1;
			cin>>level;											//take the user input option to set the level
		system("cls");	
	}
	
	
	/**
	*@define function for the coutdown before the game starts
	
	
	*@return void
	*/
	void modee::countdown()
	{
		//using two for loops; one for the appearance of the number and another to erase for each of the three numbers
		for(int j=0;j<6;j++){
			for(int i=0;i<6;i++){
				position(MAIN_SCREEN/2+i-3,HEIGHT/2+j-3);		//calling the position() function
				cout<<one[j][i];								//prints '1'
			}
		}
	sleep(1);
		for(int j=0;j<6;j++){
			for(int i=0;i<6;i++){
				position(MAIN_SCREEN/2+i-3,HEIGHT/2+j-3);
				cout<<" ";										//erases '1'
		}
	}
		
		for(int j=0;j<6;j++){
			for(int i=0;i<6;i++){
				position(MAIN_SCREEN/2+i-3,HEIGHT/2+j-3);		//calling the position() function
				cout<<two[j][i];								//prints '2'
		}	
	}
	sleep(1);
		for(int j=0;j<6;j++){
			for(int i=0;i<6;i++){
				position(MAIN_SCREEN/2+i-3,HEIGHT/2+j-3);
				cout<<" ";										//erases '2'
		}
	}
	
	for(int j=0;j<7;j++){
			for(int i=0;i<7;i++){
				position(MAIN_SCREEN/2+i-3,HEIGHT/2+j-3);
				cout<<three[j][i];								//prints '3'
		}	
	}
	sleep(1);
		for(int j=0;j<7;j++){
			for(int i=0;i<7;i++){
				position(MAIN_SCREEN/2+i-3,HEIGHT/2+j-3);
				cout<<" ";										//erses '3'
		}
	}
	
	}
	
	/**
	*@define function to play the actual game
	*@param x integer to set the speed as required
	*@param s integer for the added scores in different levels
	*@param z integer 
	*/
	void modee::play(int x ,int s,int z)
	{
		draw_Border();			//calling function to draw border
		updateScore();			//calling function to update score
		side_Instruction();		//calling function to print side instruction
		enemyY[1]=enemyY[2]=0;	//initializing the y coordinate of two enemy
		print_Car();			//calling function to print car
		flag[1]=1;
		flag[2]=0;
		gen_Enemy(1);			//calling function to generate first enemy
		gen_Enemy(2);			//calling function to generate second enemy
		time_t start=time(0);	//variable for saving starting time
		start_time = timme();
		
		static int a=x;
		Sleep(1);
		countdown();			//calling function to start countdown
		while(1)
		{
			print_Clock(A);		//calling function to  print the digital clock
			
			speed=x;
			
			//using for loop for the condition to speed up
			//execute if score is less than 5
			if(score<=10){
					downward(1,speed,s);	//calling function to move enemy downwards
			}
			//execute if score is greater than 10, less than 50
			if(score>10&&score<=50){
					downward(1,speed-(20/z),s);
			}
			//execute if score is greater than 50, less than 100
			if(score>50&&score<=100){
					downward(1,speed-(40/z),s);
			}
			A++;
			int c=collision(1);				//assigning the value to check the collision
			if(collision(1)==1||collision(2)==1)
			{
				system("cls");				//clears the whole window
					time_t end=time(0);
					diff=end-start;			//calculating the total played time
					testscore=score;
					
				//opening the file named ‘sample14’
				fout.open("sample14.csv",ios::app);
				fout <<Name<<",";					//saving the name in a cell of excel
				fout<<score <<endl;					//saves start time and end time in two corresponding cells
				fout.close();						//closes the opened file
				game_Over();						//calling the function game_Over
				parent::highest();					//calling highest() function from parent class
				score=0;							//re-initializing the value of ‘score’ as 0
				break;
			}
						
		}   
	} 
