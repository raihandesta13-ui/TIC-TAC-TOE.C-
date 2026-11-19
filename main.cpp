/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int pilihan;
string player = "X";
string playername1 = " ";
string playername2 = " ";
bool hasil;

string arr[3][3] = {{"1","2","3"},{"4","5","6"},{"7","8","9"}};

bool cekPemenang() {
    
    for (int i = 0; i < 3; i++) {
    // horizintal
    if (arr[i][0] == "X" && arr[i][1] == "X" && arr[i][2] == "X")   {
        return true;
    }   
    if (arr[i][0] == "O" && arr[i][1] == "O" && arr[i][2] == "O")   {
        return true;
        
    }
    
    }
    
    //Diagonal
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
    //
    
    //vertikal
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

void tampilkanboard () {
    
    cout<< " |---|---|---|" << endl;
    for (int i = 0; i < 3; i++) {

         for (int j = 0; j < 3; j++) {
             
             cout<< " | " << arr [i][j];
             if (j == 2) {
                 cout<< " | ";
             }
         }
         cout<< endl;
         cout<< " |---|---|---|" << endl;
    }
}

int main()
{
    int token = 0;
    cout<< "--------------------" << endl;
    cout<< "TIC-TAC TOE " << endl;
    cout<< "--------------------" << endl;
    tampilkanboard();
    
    cout<< "enter player 1 name[X] :";
    cin>> playername1;
    cout<< "enter player 2 name[O] :";
    cin>> playername2;
    cout<< endl;
    
    string nama = playername1;
    
    do
    {
        
    if (token != 0) {
        tampilkanboard();
        token = token - 1;
    }
    
    cout<< "pilih anka 1-9 untuk mengisi (giliran " << nama << "[" << player << "])" << endl;
    cin>> pilihan;
    
    if (nama == playername1) {
        nama = playername2;
    }
    
    else if (nama == playername2) {
        nama = playername1;
    }
    
    pilihan = pilihan - 1;
    
    if (pilihan == 0 || pilihan == 1 || pilihan == 2) {
        
        if (arr[0][pilihan] == "X" || arr[0][pilihan] == "O") {
            pilihan = pilihan + 1;
            cout<< "[!] kotak ke " << pilihan << " sudah terisi [!], pilih kotak lain!" << endl;
            token = token + 1;
            continue;
        }
        
        arr[0][pilihan] = player;
        tampilkanboard();
        
        
        if (player == "X") {
            player = "O";
        }
        
        else if (player == "O") {
            player =  "X";
        }
        
         hasil = cekPemenang();
    }
    
    else if (pilihan == 3 || pilihan == 4 || pilihan == 5) {
            pilihan = pilihan - 3;
            
            if (arr[1][pilihan] == "X" || arr[1][pilihan] == "O") {
            pilihan = pilihan + 1;
            cout<< "[!] kotak ke " << pilihan << " sudah terisi [!], pilih kotak lain!" << endl;
            token = token + 1;
            continue;
            }
            
            arr[1][pilihan] = player;
            tampilkanboard();
            
        if (player == "X") {
         player = "O";
        }
        
        else if (player == "O") {
            player = "X";
        }
        
        hasil = cekPemenang();
    }
    
    else if (pilihan == 6 || pilihan == 7 || pilihan == 8) {
        pilihan = pilihan - 6;
        
        if (arr[2][pilihan] == "X" || arr[2][pilihan] == "O") {
            pilihan = pilihan + 1;
            cout<< "[!] kotak ke " << pilihan << " sudah terisi [!], pilih kotak lain!" << endl;
            token = token + 1;
            continue;
        }
        
        arr[2][pilihan] = player;
        tampilkanboard();
        
        if (player == "X") {
            player = "O";
        }
        
        else if (player == "O") {
            player = "X";
        }
        
        hasil = cekPemenang();
    }
    
    } while (!hasil);
    
    if (nama == playername1) {
        nama = playername2;
    }
    
    else if (nama == playername2) {
        nama = playername1;
    }
    cout<< "*---------------------------------------------------*" << endl;
    cout<< "| 👑 👑 👑 👑  {SELAMAT!! " << nama << "[" << player << "]" << " MENANG!!} 👑 👑 👑 👑    |" << endl;
     cout<< "*--------------------------------------------------*" << endl;
    return 0;
}