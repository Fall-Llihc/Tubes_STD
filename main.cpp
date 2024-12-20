#include <windows.h>
#include "MainHeader.h"

int main(void)
{
    HANDLE hStdout;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    ShowConsoleCursor(false);

    int inp;
    createLine();

    while(true){
        cls(hStdout);
        Print("Insert");
        inp = get_code();
        if (inp == 13){ // Enter
            createLine();
        } else if (inp == 8){ //Backspace
            backspace();
        } else if (inp == 339) { //Delete
            delete_elem();
        } else if (inp == KEY_LEFT) { //Delete
            left();
        } else if (inp == KEY_RIGHT) { //Delete
            right();
        } else {
            cout<<endl;
            add(char(inp));
        }
    }

    return 0;
}
