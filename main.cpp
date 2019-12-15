#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include "board.h"
void draw_pointer(int coord){
    gotoXY(35,coord);
    cout << ">";
    gotoXY(72,coord);
    cout << "<";
}
void end_game(board b){
    system("cls");
    b.ShowBoard(50);
    b.ShowValues(52,57,62);
    gotoXY(53,12);
    if(b.win() == 1){
        SetColor(Green,Black);
        cout << "X is WIN!";
    }
    else{
        SetColor(Red,Black);
        cout << "0 is WIN!";
    }
}
void game_with_ai(){
    system("cls");
    SetColor(White,Black);
    cout << "Select you character (x,z)";
    char key = _getch();
    if(key == 'x') key = 'X';
    else key = '0';
    char ai_char;
    if(key == 'X') ai_char = '0';
    else ai_char = 'X';
    board ai_board;
    ai_board.init();
    while(true){
        if(ai_board.board_is_full()) ai_board.init();
       if(!ai_board.win()) ai_board.input(key); else break;
       if(!ai_board.win()){
           if(ai_board.is_empty_position(1,1)) ai_board.setChar(1,1,ai_char);
            else if(ai_board.is_empty_position(0,0)) ai_board.setChar(0,0,ai_char);
            else if(ai_board.is_empty_position(2,2)) ai_board.setChar(2,2,ai_char);
            else if(ai_board.is_empty_position(0,2)) ai_board.setChar(0,2,ai_char);
            else if(ai_board.is_empty_position(2,0)) ai_board.setChar(2,0,ai_char);
            else if(ai_board.is_empty_position(1,0)) ai_board.setChar(1,0,ai_char);
            else if(ai_board.is_empty_position(1,2)) ai_board.setChar(1,2,ai_char);
            else if(ai_board.is_empty_position(0,1)) ai_board.setChar(0,1,ai_char);
            else if(ai_board.is_empty_position(2,0)) ai_board.setChar(2,0,ai_char);
        }
        else break;
}
end_game(ai_board);
_getch();
}
void game_with_second_player(){
    board Board;
    Board.init();
    while(true){
        if(!Board.win()){
        if(Board.board_is_full()) Board.init();
         Board.input('X');   
        }
        else break;
        if(!Board.win()){
        if(Board.board_is_full()) Board.init();
         Board.input('0');   
        }
        else break;
    }
    end_game(Board);
    getch();
}
void ShowMenu(){
    gotoXY(0,0);
    cout << "========================================================================================================================";
    gotoXY(0,5);
    cout << "========================================================================================================================";
    gotoXY(40,6);
    gotoXY(45,2);
    cout << "xzGame v1.1 FINAL";
    gotoXY(40,3);
    cout << "Copyright KALANDAR Software (C)";
    gotoXY(90,4);
    cout << "Author:Ilyosiddin Kalandar";
    gotoXY(5,4);
    cout << "Date:2019.09.08";
    gotoXY(40,10);
    cout << "Start Game with second Player";
    gotoXY(40,12);
    cout << "Start game with xzAI";
    gotoXY(40,14);
    cout << "About xzGame v1.1 Final";
    gotoXY(40,16);
    cout << "End game";
}
int main(){
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitle("xzGame v1.1 final by Ilyosiddin Kalandar copyright KALANDAR Software (C)");
    ShowMenu();
    KeyValue key;
    int n = 1;
    SetColor(LightGreen,Black);
    while(true){        
        switch(n){
            case 1:
                draw_pointer(10);
                break;
            case 2:
                draw_pointer(12);
                break;
            case 3:
                draw_pointer(14);
                break;
            case 4:
                draw_pointer(16);
                break;
        }
        int(key) = _getch();
        if(key == LEFT){
            if(n == 1) n = 4;
            else n--;
        } 
        if(key == DOWN){
            if(n == 4) n = 1;
            else n++;
        }
        if(key == UP){
            if(n == 1) n = 4;
            else n--;
        }
        if(key == ENTER){
            switch(n){
                case 4:
                return 0;
                case 1:
                    game_with_second_player();
                    break;
                    case 3:
                        SetColor(Yellow,Black);
                        system("cls");
                        gotoXY(45,2);
                        cout << "xzGame v1.1";
                         gotoXY(35,4);
                        cout << "Copyright KALANDAR Software(C)";
                        cout << endl << "==========================================================================================";
                        cout << endl << "In version 1.1 some bugs fixed\nAdded Graphical Interface\nAdded moving information\nAdded Instructions\nAdded panels \nOptimization\nAnd More\n\nNew version coming soon!\n\n";
                        cout << endl << "==========================================================================================";
                        cout << endl << endl << "Press any key!";
                        _getch();
                        break;
                        case 2:
                            game_with_ai();
                            break;
            }
            system("cls");
            SetColor(White,Black);
            ShowMenu();
            SetColor(Green,Black);
        }
        for(int i = 10; i <=16;i+=2){
            gotoXY(35,i);
            cout << " "; 
            gotoXY(72,i);
            cout << " ";
        }
    }
}