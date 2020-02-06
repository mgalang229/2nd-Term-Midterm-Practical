#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
void storeRandom(int sRandom[4][4]);
void printGame();
void getRowColumn(int &row, int &column, int &row2, int &column2);
void playGame(int sRandom[4][4], int &row, int &column, int &row2, int &column2);
void returnMenu(int newChoice);
int main(){
    int randomNum[4][4];
    int r,c,r2,c2,choice;
    while(1){
        storeRandom(randomNum);
        printGame();
        getRowColumn(r,c,r2,c2);
        cout << setw(3);
        for(int i = 0; i < 4; i++){
            cout << i+1 << " ";
        }
        cout << endl;
        for(int i = 0 ; i < 10; i++){
            cout << "-";
        }
        cout << endl;
        playGame(randomNum,r,c,r2,c2);
        returnMenu(choice);
    }
    return 0;
}
void storeRandom(int sRandom[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            sRandom[i][j] = rand() % 9 + 1;
        }
    }
}
void printGame(){
    cout << setw(3);
    for(int i = 0; i < 4; i++){
        cout << i+1 << " ";
    }
    cout << endl;
    for(int i = 0 ; i < 10; i++){
        cout << "-";
    }
    cout << endl;
    for(int i = 0; i < 4; i++){
        cout << i+1 << "|";
        for(int j = 0; j < 4; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void getRowColumn(int &row, int &column, int &row2, int &column2){
    int *newRow = &row;
    int *newColumn = &column;
    int *newRow2 = &row2;
    int *newColumn2 = &column2;
    cout << "Please insert the row\n";
    cin >> *newRow;
    cout << "Please insert the column\n";
    cin >> *newColumn;
    cout << "Please insert the row\n";
    cin >> *newRow2;
    cout << "Please insert the column\n";
    cin >> *newColumn2;
}
void playGame(int sRandom[4][4], int &row, int &column, int &row2, int &column2){
    int *newRow = &row;
    int *newColumn = &column;
    int *newRow2 = &row2;
    int *newColumn2 = &column2;
    for(int i = 0; i < 4; i++){
        cout << i+1 << "|";
        for(int j = 0; j < 4; j++){
            if((i == *newRow-1) && (j == *newColumn-1)){
                cout << sRandom[i][j] << " ";
            } else if((i == *newRow2-1) && (j == *newColumn2-1)){
                cout << sRandom[i][j] << " ";
            } else{
                cout << "* ";
            }
        }
        cout << endl;
    }
}
void returnMenu(int newChoice){
    cout << "\nEnter 1 to play again.";
    cout << "Enter 0 to quit: ";
    cin >> newChoice;
    if(newChoice == 1){
        system("cls");
    } else if(newChoice == 0){
        cout << "\nGame Exiting...\n";
        exit(1);
    } else{
        cout << "\nInvalid Choice. Game Exiting...\n";
    }
}
