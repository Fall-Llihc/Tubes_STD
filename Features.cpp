#include "MainHeader.h"


adrHistory createHistoryElem(string tipe){
    adrHistory P = new history;
    P->tipe = tipe;
    P->line = cursor.line_info;
    P->txtelem = cursor.txt_info;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

