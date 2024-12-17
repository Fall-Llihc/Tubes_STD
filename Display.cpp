#include "MainHeader.h"

void DefaultDisplay(){
    int input;
    string mode_input;
    bool first = true;

    IntroText("Command");
    while(true){
        input = getch();
        if (input == 58){
            cout << char(input);
            cin >> mode_input;
            if (mode_input == "q!"){
                system("CLS");
                return;
            } else {
                system("CLS");
                IntroText("Command");
                continue;
            }
        } else {
            if (input == 27 && first){
                system("CLS");
                IntroText("Command");
                continue;
            } else if (first){
                system("CLS");
                IntroText("Insert");
                first = false;
            }else {
                system("CLS");
            }
            while(true){
                input = getch();
                if (input == 27){
                    break;
                } else{
                    system("CLS");
                    cout <<  cout << input << char(input) << endl; //Dingati list text nanti
                }
            }
        }
    }
}

void IntroText(string mode){
    printf("Mode: %s", mode.c_str());
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tGTC Code Editor v0.1\n\n");
    printf("\t\t\t\t    Here are some command lists in command mode.\n\n");
    printf("\033[38;5;87m\t\t\t\t    type :help\033[m\t for new player.\n");
    printf("\033[38;5;87m\t\t\t\t    type :q!\033[m\t to rage quit if you stress out!\n");
    printf("\033[38;5;87m\t\t\t\t    type :id!\033[m\t to become nasionalist.\n\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}






















