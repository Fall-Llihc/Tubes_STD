#include "MainHeader.h"

int LineNum = 0;
LineList Line; //Universal variable
Cursor cursor = {
    NULL,
    NULL
}; //Universal variable

//Function

adrTxt createTxtElem(infotype x){
    adrTxt P = new ElemenTxt;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void createLine(){
    adrLine line_new = new ElemenLine;
    line_new->TxtLen = 0;
    line_new->next = NULL;
    line_new->prev = NULL;
    line_new->TxtFirst = NULL;
    line_new->TxtLast = NULL;
    line_new->LineNumber = ++LineNum;

    if (Line.First == NULL){
        Line.First = line_new;
        Line.Last = line_new;
    } else {
        Line.Last->next = line_new;
        line_new->prev = Line.Last;
        Line.Last = line_new;
    }

    cursor.line_info = line_new;
    cursor.txt_info = NULL;
}

void add(infotype x){
    adrTxt elem = createTxtElem(x);
    if (cursor.line_info->TxtFirst == NULL){
        cursor.line_info->TxtFirst = elem;
    }
     else {
        cursor.txt_info->next = elem;
        elem->prev = cursor.txt_info;
    }

    cursor.txt_info = elem;
    cursor.line_info->TxtLen++;
    cursor.line_info->TxtLast = elem;
}




























