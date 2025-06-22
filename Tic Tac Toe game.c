#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char PLAYER = 'X';    // Player's mark
const char COMPUTER = 'O';  // Computer's mark


void resetBoard();       //function to reset board.Our board is 2D character array.
void printBoard();      //function to print board.
int checkFreeSpace();    //function to check if there is any free space left on the board.
void playerMove();      //function to get the player's move.
void computerMove();    //function to get the computer's move.
char checkWinner();    //function to check if there is a winner.
void printWinner(char winner); //function to print the winner.

int main(){
    char winner= ' ';
    char response;
    do{
        winner = ' ';      // Reset winner for each new game
        resetBoard();      //Reset the board to initialize the characters in 2D board.
        
        while(winner == ' ' && checkFreeSpace() != 0)
        {
            printBoard();
            playerMove();  //Get the player's move.
    
            winner = checkWinner(); // After player moves check if there is a winner.
            if(winner != ' ' || checkFreeSpace() == 0 ){
                break; // If there is a winner or no free space, exit the loop
                }
                computerMove();  //Get the computers move.
                winner = checkWinner();
                if(winner != ' ' || checkFreeSpace() == 0 ) {
                    break; // If there is a winner or no free space, exit the loop
                    }
                }
                printBoard();
                printWinner(winner); 
                
                printf("Do you want to play again? (y/n): ");             // Read the response character    
                scanf(" %c", &response); 
                
                response = tolower(response); // Convert response to lowercase for consistency
                }while(response == 'y');

                printf("Thanks for playing!\n");
                
                return 0;
            }

void resetBoard(){
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){

            board[i][j]= ' '; //Initialize the board with empty spaces.
        }
    }


}
void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n---|---|---\n");
    printf("\n");


}  
int checkFreeSpace(){

    int freeSpaces = 9;          // Start with 9 free spaces

    // Count the number of free spaces in the board
    
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(board[i][j] !=' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;


}  
void playerMove(){
    int x, y;

    do{
        printf("Select row #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Select column #(1-3): ");
        scanf("%d", &y);
        y--;
        if(board[x][y] != ' ')
        {
            printf("Invalid move! Try again.\n");
        } 
        else
        {
            board[x][y] = PLAYER; // Place player's mark on the board
            break ;
        }
        
    }
    while (board[x][y] != ' ');


}
void computerMove(){
    /*
    Computers move will be randomly generated.
    For that we create a seed based on current time.
    */

    srand(time(0));
    int x, y ;

    if(checkFreeSpace() > 0){
        do{
            x = rand() %3;
            y = rand() %3;
        }while(board[x][y] != ' '); // Keep generating random coordinates until we find a free space


        board[x][y] = COMPUTER; // Place computer's mark on the board
    }
    else {
        printWinner(' '); // If no free space, print a message indicating the game is a draw
        printf("It's a draw! No free spaces left.\n");
    }



}
char checkWinner(){

    // Check all the winning conditions
    
    for(int i = 0; i<3 ; i++){

        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0 != ' '])
        {
            return board[i][0];  //Return the winner if a row is complete
        }
    }
    for(int i = 0; i<3 ; i++){

        if(board[0][i] == board[1][i] && board[0][i] == board[i][2] && board[0][i] != ' ')
        {
            return board[0][i];  //Return the winner if a column is complete
        }
    }

    // Checking diagonals( two cases for it)
    if(board[0][0] == board[1][1] && board[0][0] ==  board[2][2] && board[0][0] != ' '){

        return board[0][0];
    }

    if(board[0][2] == board[1][1] && board[0][2] ==  board[2][0]){

        return board[0][2];
    }
    // If still no winner, return space character
    
    return ' ';


}
void printWinner(char winner){

    if(winner == PLAYER){
        printf("You win!\n");
    }
    else if(winner == COMPUTER){
        printf("Computer wins!\n");
    }
    else{
        printf("It's a draw!\n");
    }

}