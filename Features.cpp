#include "MainHeader.h"

ListHistory HistoryList = {
    NULL,
    NULL,
};
adrHistory CurrentHistory = NULL;


string commandCheck(){
    string hasil = "";
    printf("\n\n\n\n\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    int inp = get_code();
    if (inp == 58){
        cout << char(inp);
        while(true){
            inp = get_code();
            if (inp == 27){
                return "ESC";
                break;
            } else if (inp == 13){
                return hasil;
            }else {
                cout << char(inp);
                hasil += char(inp);
            }
        }
    } else if (char(inp)== 'u'){
        undo();
    } else if (char(inp)== 'r'){
        redo();
    }
}

adrHistory createElemHistory(string tipe){
    adrHistory P = new history;
    P->linehis = cursor.line_info;
    P->txthis = cursor.txt_info;
    P->tipe_inputan = tipe;
    return P;
}

void addHistory(adrHistory P){
    if (!HistoryList.First){
        HistoryList.First = P;
        HistoryList.Last = P;
    } else {
        HistoryList.Last->next = P;
        P->prev = HistoryList.Last;
        HistoryList.Last = P;
    }
    CurrentHistory = P;
}

void undo(){
    if (CurrentHistory){
        if (CurrentHistory->tipe_inputan == "add"){
            cursor.txt_info = CurrentHistory->txthis;
            cursor.line_info = CurrentHistory->linehis;
            while(cursor.txt_info->info != ' ' && cursor.txt_info != NULL){
                backspace();
                CurrentHistory = CurrentHistory->prev;
            }
            backspace();
            CurrentHistory = CurrentHistory->prev;
        }
        cursor.txt_info = CurrentHistory->txthis;
        cursor.line_info = CurrentHistory->linehis;

    }
}

void redo(){
    if (CurrentHistory){
        if (CurrentHistory->tipe_inputan == "add"){
            cursor.txt_info = CurrentHistory->txthis;
            cursor.line_info = CurrentHistory->linehis;
             while(CurrentHistory->next != NULL){
                add(CurrentHistory->txthis->info);
                CurrentHistory = CurrentHistory->next;
            }
            add(CurrentHistory->txthis->info);
        }

    }
}
