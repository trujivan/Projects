/*Vanessa Trujillo
Feb 27 th 2017; 
 The purose of this project is to create a game
 where there are 3 players with the objective of 
 creating an "L" with the same character symbol*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//function shows the current grid moves
void PrintCurrentGrid(int height, int width, char Grid[height][width]){
	int i;
	int j;
	const int numCount=9;
	int printNum[]={1,2,3,4,5,6,7,8,9}; 
	
	for(i=0;i<numCount;i++){
	printf("%d  ", printNum[i] );//prints the numbers corresponding to columns
	}printf("\n");
	//generating grid for game
		for(i=0; i<height;i++)
		{
			for(j=0;j<width;j++)
			{
			
			printf("%c  ", Grid[i][j]);	
			}
			printf("\n");
		}
	return;
}
//function creates a nice neat clean grid
void NewGrid(int height, int width, char Grid[height][width]){
	int i;
	int j;
//wipes out memory from previous game
	for(i=0; i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			Grid[i][j]='-';
		}
	
	}
	return;
}
//function updates grid with current players move
void PlayerMove(int height, int width, char Grid[height][width], int playerInput, char currentPlayer){
int maxHeight=height-1;
	playerInput=playerInput-1;
	//saves the players input in "PrintCurrentGrid" when stated in main.
	while(1) {
		if(Grid[maxHeight][playerInput]=='-'){
	
		Grid[maxHeight][playerInput] = currentPlayer;
			break;
		}
		else if(maxHeight==0){//limits input choices
		printf("invalid column chosen, please enter a valid column");
			scanf("%d", &playerInput);
			maxHeight=height-1;
			playerInput=playerInput-1;
	
		}
		else if (Grid[maxHeight][playerInput]!='-'){
		maxHeight=maxHeight-1;
		}
	}
	return;
}
//checks for a win/match horizontally
int check4WinH(int height, int width, char Grid[height][width], char currentPlayer){
	int ThreeContin=0;
	int i,j;
	int win=0;
	for(i=height-1;i>=0;i--){
		for(j=0;j<width;j++){
			if(Grid[i][j]==currentPlayer){
				ThreeContin++;
			}
			else if (Grid[i][j]!=currentPlayer){
				ThreeContin=0;
			}
			if(ThreeContin>=3){
				if(i==0){
					if(Grid[i+1][j]==currentPlayer){
					win=1;
					}
					else if(Grid[i+1][j-2]==currentPlayer){
					return 1;	
					}
				}
				if (i==height-1){
					if(Grid[i-1][j]==currentPlayer){
					win=1;				
					}
					if(Grid[i-1][j-2]==currentPlayer){
						win=1;
					}
					}
					else {
						if(Grid[i+1][j]==currentPlayer){
						win=1;
						}
			
						if(Grid[i+1][j-2]==currentPlayer){
						win=1;
						}
						if(Grid[i-1][j]==currentPlayer){
							win=1;	
						}
						if(Grid[i-1][j-2]==currentPlayer){
							win=1;
						}
					}
				
			}
		}
	}


return win;

}
//checks for win/match vertically (Same idea as horizontal check, i and j switched)
int check4WinV(int height, int width, char Grid[height][width], char currentPlayer){
	int win=0;
	int ThreeContin =0;
	int i,j;
	for(i=0;i<width;i++){
		for(j=height-1;j>=0;j--){
			if(Grid[j][i]==currentPlayer){
				ThreeContin = ThreeContin +1;
			}
			else if (Grid[j][i]!=currentPlayer){
				ThreeContin=0;
			}
			if(ThreeContin>=3){
				if(i==0){
					if(Grid[j][i+1]==currentPlayer){
					win = 1;
					}
					if(Grid[j+2][i+1]==currentPlayer){
					win=1;	
					}
				}
				else if (i==width-1){
					if(Grid[j][i-1]==currentPlayer){
						win=1;				
					}
					if(Grid[j+2][i-1]==currentPlayer){
						win=1;
					}
				}
				else {
						if(Grid[j][i+1]==currentPlayer){
								win=1;
						}
						if(Grid[j+2][i+1]==currentPlayer){
							win=1;	
						}
						if(Grid[j][i-1]==currentPlayer){
							win=1;				
						}
						if(Grid[j+2][i-1]==currentPlayer){
							win=1;
						}
					}
				
			}
		}
	}


return win;

}



// beginning of main funtion
int main(void) {
int Height=8;
char currentPlayer=' ';
int Width=9;
char Grid[Height][Width];
char ply1='O';
char ply2='X';
char ply3='B';
int i;
int j;
int w=1;
int playerInput;
char playerInputStr[10];
char contin[2];
bool ok; //bool allows users to only enter 2 possible inputs.

// while loop using bool so that Y and N can be the only options.
ok = false;
while (ok == false){
printf("\nWelcome to connect four\n");
printf("Object is to be the first person to get 4 of their tokens\n");
printf("in the shape of an L contiguous in a column or row, in the game board\n");
printf("no wrapping is allowed\n\n");

NewGrid(Height, Width, Grid);
PrintCurrentGrid(Height, Width, Grid);
//allowing the characters to alternate each turn
while(1){

	if (w%3==1){
		currentPlayer=ply1;
	
	}
	else if (w%3==2){
		currentPlayer=ply2;	

	}
	else if (w%3==0){
		currentPlayer=ply3;	
	}
		w++;

	while(1){

	printf("Player %c  pick a column: ", currentPlayer);
	scanf("%s", playerInputStr);
	playerInput = atoi(playerInputStr);//accepts numbers

		if(playerInput<=0 || playerInput > 9){
			printf("invalid column chosen, please enter a valid column\n");
		}
		else{
			break;
		}
	}
	int won=0;
	PlayerMove(Height, Width, Grid, playerInput, currentPlayer);
	PrintCurrentGrid(Height, Width, Grid);
	won = check4WinH(Height, Width, Grid, currentPlayer);
		if(won==1){
			break;
		}
	won = check4WinV(Height, Width, Grid, currentPlayer);
		if(won==1){
			break;
		}
}	
	// winning output
	printf("player %c wins", currentPlayer);
	printf("\n\n");
	//asking for new game
	printf("Would you like to play again (Y/N)? \n\n");
	scanf("%s", contin);
		if (strcmp(contin, "N")==0) {
			ok = true;
		}
		else if (strcmp(contin, "Y")==0) {
			ok = false;
		}

}
	return 0;

}

