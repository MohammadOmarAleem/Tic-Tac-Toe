#include <iostream>
using namespace std;


char  table[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displaytable() {



    cout << "     |     |     " << endl;
    cout << " " << table[0][0] << "   |" << " " << table[0][1] << "   |" << " " << table[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << " " << table[1][0] << "   |" << " " << table[1][1] << "   |" << " " << table[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << " " << table[2][0] << "   |" << " " << table[2][1] << "   |" << " " << table[2][2] << endl;
    cout << "     |     |     " << endl;
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (table[i][0] == table[i][1] && table[i][1] == table[i][2] ||
            table[0][i] == table[1][i] && table[1][i] == table[2][i]) {
            return true;
        }
    }
    // Check diagonals
    if (table[0][0] == table[1][1] && table[1][1] == table[2][2] ||
        table[0][2] == table[1][1] && table[1][1] == table[2][0]) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (table[i][j] != 'X' && table[i][j] != 'O') {
                return false; // Found an empty cell, so it's not a draw
            }
        }
    }
    return true; // All cells are occupied, it's a draw
}

void makeMove(char sym, string playerName) {
    int move;
    cin >> move;
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (table[row][col] != 'X' && table[row][col] != 'O') {
        table[row][col] = sym;
        displaytable();
        if (checkWin()) {
            cout << playerName << " wins!" << endl;
            exit(0); // End the game
        }
        else if (checkDraw()) {
            cout << "It's a draw!" << endl;
            exit(0); // End the game
        }
    }
    else {
        cout << "Cell already occupied. Try again." << endl;
        makeMove(sym, playerName);
    }
}

int main()
{

    string name1;   //name of the first player
    string name2;   //name of the 2nd player
    char sym1;      //character to be used by Player 2
    char sym2;      //symbol to be used by Player 2

    cout << "Enter the name of Player 1" << endl;
    cin >> name1;
    cout << "What symbol do you want to use" << endl;
    cin >> sym1;

    cout << "Enter the name of Player 2" << endl;
    cin >> name2;
    cout << "What symbol do you want to use" << endl;
    cin >> sym2;

    displaytable();

    while (true) { //  game loop
        cout << "What move do you want to make " << name1 << "?" << endl;
        makeMove(sym1, name1);
        // Check for win or draw

        cout << "What move do you want to make " << name2 << "?" << endl;
        makeMove(sym2, name2);
        // Check for win or draw
    }

    return 0;
}
