#include <iostream>
using namespace std;

int choice;
string player = "X";
string playername1 = " ";
string playername2 = " ";
bool result;

string arr[3][3] = {{"1","2","3"},{"4","5","6"},{"7","8","9"}};

bool checkWinner() {
    
    for (int i = 0; i < 3; i++) {
        // Horizontal
        if (arr[i][0] == "X" && arr[i][1] == "X" && arr[i][2] == "X") {
            return true;
        }   
        if (arr[i][0] == "O" && arr[i][1] == "O" && arr[i][2] == "O") {
            return true;
        }
    }
    
    // Diagonal
    if (arr[0][0] == "X" && arr[1][1] == "X" && arr[2][2] == "X") {
        return true;
    }
    
    if (arr[0][0] == "O" && arr[1][1] == "O" && arr[2][2] == "O") {
        return true;
    }
    
    if (arr[0][2] == "X" && arr[1][1] == "X" && arr[2][0] == "X") {
        return true;
    }
    
    if (arr[0][2] == "O" && arr[1][1] == "O" && arr[2][0] == "O") {
        return true;        
    }
    
    // Vertical
    if (arr[0][0] == "X" && arr[1][0] == "X" && arr[2][0] == "X") {
        return true;
    }
    
    if (arr[0][1] == "X" && arr[1][1] == "X" && arr[2][1] == "X") {
        return true;
    }
    
    if (arr[0][2] == "X" && arr[1][2] == "X" && arr[2][2] == "X") {
        return true;
    }
    
    if (arr[0][0] == "O" && arr[1][0] == "O" && arr[2][0] == "O") {
        return true;
    }
    
    if (arr[0][1] == "O" && arr[1][1] == "O" && arr[2][1] == "O") {
        return true;
    }
    
    if (arr[0][2] == "O" && arr[1][2] == "O" && arr[2][2] == "O") {
        return true;
    }
    
    return false;
}

void displayBoard() {
    
    cout << " |---|---|---|" << endl;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            
            cout << " | " << arr[i][j];
            if (j == 2) {
                cout << " | ";
            }
        }
        cout << endl;
        cout << " |---|---|---|" << endl;
    }
}

int main()
{
    int token = 0;
    cout << "--------------------" << endl;
    cout << "TIC-TAC TOE " << endl;
    cout << "--------------------" << endl;
    displayBoard();
    
    cout << "enter player 1 name[X] :";
    cin >> playername1;
    cout << "enter player 2 name[O] :";
    cin >> playername2;
    cout << endl;
    
    string name = playername1;
    
    do
    {
        if (token != 0) {
            displayBoard();
            token = token - 1;
        }
        
        cout << "choose a number 1-9 to fill (" << name << "[" << player << "]'s turn)" << endl;
        cin >> choice;
        
        if (name == playername1) {
            name = playername2;
        }
        else if (name == playername2) {
            name = playername1;
        }
        
        choice = choice - 1;
        
        if (choice == 0 || choice == 1 || choice == 2) {
            
            if (arr[0][choice] == "X" || arr[0][choice] == "O") {
                choice = choice + 1;
                cout << "[!] box number " << choice << " is already taken [!], choose another box!" << endl;
                token = token + 1;
                continue;
            }
            
            arr[0][choice] = player;
            displayBoard();
            
            if (player == "X") {
                player = "O";
            }
            else if (player == "O") {
                player = "X";
            }
            
            result = checkWinner();
        }
        
        else if (choice == 3 || choice == 4 || choice == 5) {
            choice = choice - 3;
            
            if (arr[1][choice] == "X" || arr[1][choice] == "O") {
                choice = choice + 1;
                cout << "[!] box number " << choice << " is already taken [!], choose another box!" << endl;
                token = token + 1;
                continue;
            }
            
            arr[1][choice] = player;
            displayBoard();
            
            if (player == "X") {
                player = "O";
            }
            else if (player == "O") {
                player = "X";
            }
            
            result = checkWinner();
        }
        
        else if (choice == 6 || choice == 7 || choice == 8) {
            choice = choice - 6;
            
            if (arr[2][choice] == "X" || arr[2][choice] == "O") {
                choice = choice + 1;
                cout << "[!] box number " << choice << " is already taken [!], choose another box!" << endl;
                token = token + 1;
                continue;
            }
            
            arr[2][choice] = player;
            displayBoard();
            
            if (player == "X") {
                player = "O";
            }
            else if (player == "O") {
                player = "X";
            }
            
            result = checkWinner();
        }
        
    } while (!result);
    
    if (name == playername1) {
        name = playername2;
    }
    else if (name == playername2) {
        name = playername1;
    }
    
    cout << "*---------------------------------------------------*" << endl;
    cout << "| 👑 👑 👑 👑  {CONGRATS!! " << name << "[" << player << "]" << " WINS!!} 👑 👑 👑 👑    |" << endl;
    cout << "*--------------------------------------------------*" << endl;
    return 0;
}

