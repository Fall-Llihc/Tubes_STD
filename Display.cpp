#include "MainHeader.h"

void DefaultDisplay(bool &typing){
    int input;
    string mode_input;
    bool first = true;

    IntroText("Command");
    typing = true;
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

void ShowConsoleCursor(bool showFlag){
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void printLine(adrLine P){
    adrTxt temp = P->TxtFirst;
    while (temp){
        cout << temp->info;
        temp = temp->next;
    }
    cout << endl;
}

void Print(){
    int numline = 0;
    adrLine Line_tmp = Line.First;
    while(Line_tmp != NULL){
        printf("Line %d :", ++numline);
        printLine(Line_tmp);
        Line_tmp = Line_tmp->next;
    }
}




















