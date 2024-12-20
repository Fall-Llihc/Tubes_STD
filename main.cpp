#include <windows.h>
#include "MainHeader.h"

int main(void)
{

    HANDLE hStdout;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    ShowConsoleCursor(false);

    int inp;
    bool typing = false;
    DefaultDisplay(typing);

    while(typing){
        cls(hStdout);
        Print("Insert");
        inp = get_code();
        if (inp == 27){ // Enter
            cls(hStdout);
            Print("Command");
            string input_mode = commandCheck();

            if(input_mode == "q!"){
                cls(hStdout);
                cout << "THANKS";
                break;
            } else{
                continue;
            }

        } else if (inp == 13){ // Enter
            createLine();
            addHistory(createElemHistory("createLine"));
        } else if (inp == 8){ //Backspace
            backspace();
            addHistory(createElemHistory("backspace"));
        } else if (inp == 339) { //Delete
            delete_elem();
            addHistory(createElemHistory("delete"));
        } else if (inp == KEY_LEFT) { //Kursor kiri
            left();
        } else if (inp == KEY_RIGHT) { //Kursor kanan
            right();
        } else if (inp == KEY_UP) { //Kursor atas
            up();
        } else if (inp == KEY_DOWN) { //Kursor bawah
            down();
        } else if (inp == HOME) { //Kursor bawah
            Home();
        } else if (inp == END) { //Kursor bawah
            End();
        } else {
            cout<<endl;
            add(char(inp));
            addHistory(createElemHistory("add"));
        }
        updateLineNumber();
    }

    return 0;
}
