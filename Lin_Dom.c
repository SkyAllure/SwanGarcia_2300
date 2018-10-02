#ifdef _WIN32
#define _CRT_SECURE_NO_DEPRECATE
#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAXROWS 300
#define MAXCOLS 300

int gameArray[MAXROWS][MAXCOLS];
//declarations for drawBoard
int  rows, columns, sizex, sizey;
//declaration for turnCounter
int startRow, startCol, endRow, endCol, maxTurns, numTurns;
//general declarations
int currentTurn;
//declarations for drawLine
int ydifference, xdifference, startPoint, x, y, slope, slopeError;
//declarations for scoreBoard
int score1, score2;
//declarations for validMove
int p1Slope, p2Slope;
bool validMove();
//declarations for winCheck
int recordLoss;

//main method
int main(void)
{
	//enter number of rows
	printf("Choose how many rows and columns you want the game board to have.\n\nRows:");
	scanf_s("%d", &sizex);

	//enter number of columns
	printf("\n\nColumns:");
	scanf_s("%d", &sizey);

	//draw a blank game board
	printf("\nThe size of your game board is %d rows and %d columns.\n\n", sizex, sizey);
	drawBoard();
	
	//toggle all prompts for the current players turn
	turnCounter();
	
	getchar();
	getchar();
	return 0;
}

//this method draws the empty game board
int drawBoard(void)
{
	//draw the game board
	for (rows = 0; rows < sizex; rows++)
	{
		for (columns = 0; columns < sizey; columns++)
		{
			gameArray[rows][columns] = '.';
			printf("%c ", gameArray[rows][columns]);
		}
		printf("\n");
	}
	return 0;
}

//this method creates a turn counter and prompts each player for their input of starting and ending points of their line
//turnCounter also draws the line of the current player and increments score
//this is essentially the "brain" of the program
int turnCounter(void)
{
	maxTurns = 100;
	{
		for (numTurns = 0; numTurns < maxTurns; numTurns++)
		{
			for (currentTurn = 0; currentTurn < 2;)
			{
				//display turn number, current player, and score
				printf("\nTurn #%d\nPlayer: %d\n\n", (numTurns + 1), (currentTurn + 1));
				scoreBoard();

				//player picks starting point
				printf("Player %d, please pick a starting point (row,column):\n\n", (currentTurn + 1));
				printf("Start Row:\n");
				scanf_s("%d", &startRow);
				//make sure row selection is in bounds of game board
				if (startRow > sizex)
				{
					printf("That Row does not exist!\nPlease try again!\nStart Row:\n");
					scanf_s("%d", &startRow);
				}
				printf("\nStart Column:\n");
				scanf_s("%d", &startCol);
				//make sure the column selection is in bounds of the game board
				if (startCol > sizey)
				{
					printf("That Column does not exist!\nPlease try again!\nStart Column:\n");
					scanf_s("%d", &startCol);
				}
	
				//player picks end point
				printf("\nPlayer %d, please pick an ending point (row,column):\n\n", (currentTurn + 1));
				printf("End Row:\n");
				scanf_s("%d", &endRow);
				//make sure move is in bounds
				if (endRow > sizex)
				{
					printf("That Row does not exist!\nPlease try again!\nEnd Row:\n");
					scanf_s("%d", &endRow);
				}
				printf("\nEnd Column:\n");
				scanf_s("%d", &endCol);
				//make sure its in bounds
				if (endCol > sizey)
				{
					printf("That Column does not exist!\nPlease try again!\nEnd Column:\n");
					scanf_s("%d", &endCol);
				}
				printf("Drawing Line...\n\n");
				//make sure the start and end spots are valid
				if (currentTurn == 0 && (gameArray[startRow][startCol] != 'O') && (gameArray[endRow][endCol] != 'O'))
				{
					//set slope of player 1's line
					p1Slope = ((endCol - startCol) / (endRow - startRow));

					//if turn is valid draw the line and increment the score
					if (validMove() == true)
					{
						//draw the line virtually
						drawLine(startRow, startCol, endRow, endCol);
						//display the board with line drawn
						flipCell();
						//increment player 1s score
						score1++;
						//check for a win condition
						winCheck();
						//increment to next players turn
						currentTurn++;
					}

					//if turn is not valid, go to next persons turn
					else if (validMove() == false)
					{
						//check for win loss
						winCheck();
						//reprint previous board
						flipCell();
						//increment turn
						currentTurn++;
					}
				}

				//make sure the start and end spots are valid
				else if (currentTurn == 1 && (gameArray[startRow][startCol] != 'X') && (gameArray[endRow][endCol] != 'X'))
				{	 
					//set player 2's slope
					p2Slope = ((endCol - startCol) / (endRow - startRow));

					//if move is valid:
					if ((validMove()) == true)
					{
						//draw the line virtually
						drawLine(startRow, startCol, endRow, endCol);
						//display the board with line drawn
						flipCell();
						//increment player 2s score
						score2++;
						//check for winner
						winCheck();
						//increment to next players turn
						currentTurn++;
					}

					//if move is not valid:
					else if ((validMove()) == false)
					{
						//check for win or loss
						winCheck();
						//display last board
						flipCell();
						//increment turn
						currentTurn++;
					}
				}
				else
					printf("That space was already the beginning/end of another line. Try again\n");
			}
		}
	}
	return 0;
}

//this method checks prints out the board to the screen and to the text file
int flipCell(void)
{
	FILE *fp1 = fopen("Linear_Domination.txt", "w");
	//iterate through rows
	for (rows = 0; rows < sizex; rows++)
	{
		//iterate through columns
		for (columns = 0; columns < sizey; columns++)
		{
			printf("%c ", gameArray[rows][columns]);
			fprintf(fp1, "%c ", gameArray[rows][columns]);
		}
		printf("\n");
		fprintf(fp1, "\n");
	}
	fclose(fp1);
	return 0;
}

//this method will literally draw the line onto the screen of the current player. It is an offshoot of the Bresenham Line algorithm. Player 1 is X and player 2 is O
int drawLine(xstart, ystart, xend, yend)
{
	ydifference = (yend - ystart);
	xdifference = (xend - xstart);
	slope = (2 * ydifference);
	//slopeError corrects for the floating point values that may arrise in the calculation
	slopeError = (slope - xdifference);
	x = xstart;
	y = ystart;

	for (x = xstart, y = ystart; x <= xend; x++)
	{
		slopeError += slope;
		//draw X
		if ((currentTurn == 0 && gameArray[(x - 1)][(y - 1)] == '.') || (currentTurn == 1 && gameArray[(x - 1)][(y - 1)] == 'O'))
		{
			gameArray[(x - 1)][(y - 1)] = 'X';
		}
		//draw O
		if ((currentTurn == 1 && gameArray[(x - 1)][(y - 1)] == '.') || (currentTurn == 1 && gameArray[(x - 1)][(y - 1)] == 'X'))
		{
			gameArray[(x - 1)][(y - 1)] = 'O';
		}
		//if slope is positive, increment y, adjust the slope error
		if (slopeError >= 0)
		{
			y++;
			slopeError -= (2 * xdifference);
		}
		//if slope is negative, decrement y, adjust the slope error
		if (slope < 0)
		{
			y--;
			slopeError += (2 * xdifference);
		}
	}
	return 0;
}

//this method checks to see if the players move is valid
bool validMove(void)
{
	if (p1Slope == p2Slope)
	{
		printf("There is already a Line with that slope on the game board. You lose your turn.\n\n");
		return false;
	}
	else
	return true;
}

//this method implements the scoreboard of the program
int scoreBoard(void)
{
	printf("Score:\nPlayer 1: %d\nPlayer2: %d\n\n", score1, score2);
	return 0;
}

//this method will decide if there is a winner after every round
int winCheck(void)
{
	//if both players draw a line parallel to another, game over
	//make a false move and the loss gets recorded
	if (currentTurn == 0 && validMove() == false)
	{
		recordLoss++;
	}
	//make the right move and the loss counter is reset
	if (currentTurn == 0 && validMove() == true)
	{
		recordLoss =0;
	}
	//false move
	if (currentTurn == 1 && validMove() == false)
	{
		recordLoss++;
	}
	//right move
	if (currentTurn == 1 && validMove() == true)
	{
		recordLoss = 0;
	}
	//if both players make an incorrect move right after one another, the game ends.
	if (recordLoss == 2)
	{
		printf("Both players have forfeited their turns. The game is over.\n\n");
		if (score1 > score2)
		{
			printf("Player 1 is the winner with %d line(s).\n\n", score1);
		}
		if (score1 < score2)
		{
			printf("Player 2 is the winner with %d line(s).\n\n", score2);
		}
		if (score1 == score2)
		{
			printf("The game is a tie. Final score is %d to %d\n\n", score1, score2);
		}
		//redraw a blank board
		for (rows = 0; rows < sizex; rows++)
		{
			for (columns = 0; columns < sizey; columns++)
			{
				gameArray[rows][columns] = '.';
			}
		}
	}

	//win condition if all spots are taken on the game board
	for(rows = 0; rows < sizex; rows++)
	{
		for (columns = 0; columns < sizey; columns++)
		{
			if (gameArray[rows][sizey] == 'X' || gameArray[rows][sizey] == 'O' && gameArray[rows][sizey] != '.')
			{
				printf("Congratulations to Player 1. You are the Winner!\n");
			}
		}
	}
}
