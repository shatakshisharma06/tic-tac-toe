#include<bits/stdc++.h>
using namespace std;

void drawBoard(char *spaces){
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}

void playerMove(char *spaces, char player){
    int number;
    do{
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> number;
        number--;
        if(spaces[number] == ' '){
           spaces[number] = player;
           break; 
        }
    }while(!number > 0 || !number < 8);
}

bool checkWinner(char *spaces, char player_1, char player_2, string playerOne, string playerTwo){

    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player_1 ? cout << playerOne << " WINS!" << endl : cout << playerTwo  << " WINS!" << endl;
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player_1 ? cout << playerOne  << " WINS!" << endl : cout << playerTwo  << " WINS!" << endl;
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player_1 ? cout << playerOne << " WINS!" << endl : cout << playerTwo  << " WINS!" << endl;
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player_1 ? cout << playerOne << " WINS!" << endl : cout << playerTwo  << " WINS!" << endl;
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player_1 ? cout << playerOne << " WINS!" << endl : cout << playerTwo  << " WINS!" << endl;
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player_1 ? cout << playerOne << " WINS!" << endl : cout << playerTwo  << " WINS!" << endl;
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player_1 ? cout << playerOne << " WINS!" << endl : cout << playerTwo  << " WINS!" << endl;
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player_1 ? cout << playerOne << " WINS!" << endl : cout << playerTwo  << " WINS!" << endl;
    }
    else{
        return false;
    }

    return true;
}

bool checkTie(char *spaces){

    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    cout << "IT'S A TIE!" << endl;
    return true;
}

int main() {

string playerOne, playerTwo;

cout << "Enter first player's name: " << endl;
cin >> playerOne;

cout << "Enter second player's name: " << endl;
cin >> playerTwo;

    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player_1 = 'X';
    char player_2 = 'O';
    bool running = true;

    drawBoard(spaces);

    while(running){
        playerMove(spaces, player_1);
        drawBoard(spaces);
        if(checkWinner(spaces, player_1, player_2, playerOne, playerTwo)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }

        playerMove(spaces, player_2);
        drawBoard(spaces);
        if(checkWinner(spaces, player_1, player_2, playerOne, playerTwo)) {
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
    }
    cout << "Thanks for playing!" << endl;
    return 0;
}
