//
//  main.cpp
//  TicTacToe
//
//  Created by rob on 5/6/14.
//  Copyright (c) 2014 rob. All rights reserved.
//

#include <iostream>

using namespace std;

// setup game board
char gameBoard[10] = {'o','1','2','3','4','5','6','7','8','9'};

// prototype game class
class ticTacToe {
    int player, choice;
    char mark;
    public:
    // user game walk
    void gameWalk();
    // set player number
    void setPlayerNum();
    // set player mark
    void setPlayerMark();
    // check game board entries
    void playerEntry();
    // print user board
    void printBoard();
    // check for winner
    int checkWinner();
};

int main(int argc, const char * argv[])
{
    // init game class
    ticTacToe game;
    
    // start game walk
    game.gameWalk();
    
	return 0;
}

// user game walk
void ticTacToe::gameWalk(){
    
    int i;
    
    player = 1;
    
    // loop until
	do
	{
		// print current game board
        printBoard();
        
        // gather active player number
        setPlayerNum();
        
        // gather and filter player entry
        playerEntry();
        
        // check for winner
		i=checkWinner();
        
        // increment player number
		player++;
	}while(i == -1);
    
    // reprint game board
	printBoard();
    
    // determine game status
	if(i == 1){
		cout << "PLAYER " << --player <<" WINS! ";
	} else {
		cout << "DRAW!";
    }
    
    // clean user input
	cin.ignore();
	cin.get();
    
}
// set player number
void ticTacToe::setPlayerNum(){
    if(player % 2){
        player = 1;
    } else {
        player = 2;
    }
}
// set player mark
void ticTacToe::setPlayerMark(){
    if(player == 1){
        mark = 'X';
    } else {
        mark = 'O';
    }
}
// check game board entries
void ticTacToe::playerEntry(){
    
    // request user enter a number
    cout << "Player " << player << ", enter a number:  ";
    cin >> choice;
    
    // assign mark
    setPlayerMark();
    
    // check for usable board entries
    if (choice == 1 && gameBoard[1] == '1')
        gameBoard[1] = mark;
    else if (choice == 2 && gameBoard[2] == '2')
        
        gameBoard[2] = mark;
    else if (choice == 3 && gameBoard[3] == '3')
        
        gameBoard[3] = mark;
    else if (choice == 4 && gameBoard[4] == '4')
        
        gameBoard[4] = mark;
    else if (choice == 5 && gameBoard[5] == '5')
        
        gameBoard[5] = mark;
    else if (choice == 6 && gameBoard[6] == '6')
        
        gameBoard[6] = mark;
    else if (choice == 7 && gameBoard[7] == '7')
        
        gameBoard[7] = mark;
    else if (choice == 8 && gameBoard[8] == '8')
        
        gameBoard[8] = mark;
    else if (choice == 9 && gameBoard[9] == '9')
        
        gameBoard[9] = mark;
    // not valid move
    else
    {
        cout << "Invalid move, please make another selection.";
        
        player--;
        cin.ignore();
        cin.get();
    }
    
}
// print game board
void ticTacToe::printBoard(){
    
    system("cls");
    
    // print game title
	cout << "n\tTic Tac Toe\n\n";
    
    // print user guide
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    
    // print first line dividers
	cout << "     |     |     " << endl;
    
    // print first row of user entries
	cout << "  " << gameBoard[1] << "  |  " << gameBoard[2] << "  |  " << gameBoard[3] << endl;
    
    // first and second row divider
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
    
    // print second row of user entries
	cout << "  " << gameBoard[4] << "  |  " << gameBoard[5] << "  |  " << gameBoard[6] << endl;
    
    // second and third row divider
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
    
    // print third row of user entries
	cout << "  " << gameBoard[7] << "  |  " << gameBoard[8] << "  |  " << gameBoard[9] << endl;
    
    // print final line dividers
	cout << "     |     |     " << endl << endl;

}

// check for winner
int ticTacToe::checkWinner(){
    
    // check for winner
    if (gameBoard[1] == gameBoard[2] && gameBoard[2] == gameBoard[3])
		return 1;
	else if (gameBoard[4] == gameBoard[5] && gameBoard[5] == gameBoard[6])
		return 1;
	else if (gameBoard[7] == gameBoard[8] && gameBoard[8] == gameBoard[9])
		return 1;
	else if (gameBoard[1] == gameBoard[4] && gameBoard[4] == gameBoard[7])
		return 1;
	else if (gameBoard[2] == gameBoard[5] && gameBoard[5] == gameBoard[8])
		return 1;
	else if (gameBoard[3] == gameBoard[6] && gameBoard[6] == gameBoard[9])
		return 1;
	else if (gameBoard[1] == gameBoard[5] && gameBoard[5] == gameBoard[9])
		return 1;
	else if (gameBoard[3] == gameBoard[5] && gameBoard[5] == gameBoard[7])
		return 1;
	else if (gameBoard[1] != '1' && gameBoard[2] != '2' && gameBoard[3] != '3'
             && gameBoard[4] != '4' && gameBoard[5] != '5' && gameBoard[6] != '6'
             && gameBoard[7] != '7' && gameBoard[8] != '8' && gameBoard[9] != '9')
		return 0;
    // no win found
	else
		return -1;
}