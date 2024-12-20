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

            printf("\n\n\n\n\n\n");
            string mode;
            inp = get_code();
            if (inp == 58){
                cout << char(inp);
                cin >> mode;
                if (mode == "q!"){
                    cls(hStdout);
                    cout << "!Thank You!" << endl;
                    break;
                } else {
                    continue;
                }
            }

        } else if (inp == 13){ // Enter
            createLine();
        } else if (inp == 8){ //Backspace
            backspace();
        } else if (inp == 339) { //Delete
            delete_elem();
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
        }
        updateLineNumber();
    }

    return 0;
}
