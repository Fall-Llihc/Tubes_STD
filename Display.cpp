#include "MainHeader.h"

void DefaultDisplay(bool &typing){
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
                cout << "!Thank You!" << endl;
                break;
            } else if(mode_input == "help"){
                system("CLS");
                showHelp();
                getch();
                system("CLS");
                IntroText("Command");
                continue;
            } else {
                system("CLS");
                IntroText("Command");
                continue;
            }
        } else if (input == 27){
            system("CLS");
            IntroText("Command");
            continue;
        } else {
            system("CLS");
            IntroText("Insert");
            input = getch();
            if (input == 27){
                system("CLS");
                IntroText("Command");
                continue;
            } else if (input == 13){
                createLine();
                typing = true;
                break;
            } else {
                createLine();
                add(char(input));
                typing = true;
                break;
            }
        }
    }
}

void IntroText(string mode){
    printf("Mode: %s", mode.c_str());
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tGTC Code Editor v0.1\n\n");
    printf("\t\t\t\t    Here are some command lists in command mode.\n\n");
    printf("\033[38;5;87m\t\t\t\t    type :help\033[m\t for new player.\n");
    printf("\033[38;5;87m\t\t\t\t    type :q!\033[m\t to rage quit if you stress out!\n\n\n\n\n\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void showHelp(){
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tGTC Code Editor v0.1\n\n");
    printf("\t\t\t\t    Here are some command lists maybe you can use for\n\n");
    printf("\033[38;5;87m\t\t\t\t    type :u\033[m\t\t\t undo.\n");
    printf("\033[38;5;87m\t\t\t\t    type :r\033[m\t\t\t redo.\n");
    printf("\033[38;5;87m\t\t\t\t    type :s\033[m\t\t\t save.\n");
    printf("\033[38;5;87m\t\t\t\t    type :sq!\033[m\t\t\t save and force quit.\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void ShowConsoleCursor(bool showFlag){
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void printLine(adrLine P, int linenum){
    adrTxt temp = P->TxtFirst;
    if ((!cursor.txt_info || !temp) && (linenum == cursor.line_info->LineNumber)){
        printf("\033[38;5;87m|\033[m");
    }
    while (temp){
        cout << temp->info;
        if(temp == cursor.txt_info){
            printf("\033[38;5;87m|\033[m");
        }
        temp = temp->next;
    }
    cout << endl;
}


void Print(string mode){
    int line = 1;
    printf("Mode: %s\n\n\n", mode.c_str());
    int numline = 0;
    adrLine Line_tmp = Line.First;
    while(Line_tmp != NULL){
        printf("Line %d :", ++numline);
        printLine(Line_tmp, line++);
        Line_tmp = Line_tmp->next;
    }
}

void seeCursor(){
    cout << cursor.line_info->LineNumber << ", ";
    if (cursor.txt_info){
        cout << cursor.txt_info->info << endl;
    }
}

void cls(HANDLE hConsole){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SMALL_RECT scrollRect;
    COORD scrollTarget;
    CHAR_INFO fill;

    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    // Scroll the rectangle of the entire buffer.
    scrollRect.Left = 0;
    scrollRect.Top = 0;
    scrollRect.Right = csbi.dwSize.X;
    scrollRect.Bottom = csbi.dwSize.Y;

    // Scroll it upwards off the top of the buffer with a magnitude of the entire height.
    scrollTarget.X = 0;
    scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

    // Fill with empty spaces with the buffer's default text attribute.
    fill.Char.UnicodeChar = TEXT(' ');
    fill.Attributes = csbi.wAttributes;

    // Do the scroll
    ScrollConsoleScreenBuffer(hConsole, &scrollRect, NULL, scrollTarget, &fill);

    // Move the cursor to the top left corner too.
    csbi.dwCursorPosition.X = 0;
    csbi.dwCursorPosition.Y = 0;

    SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
}

















