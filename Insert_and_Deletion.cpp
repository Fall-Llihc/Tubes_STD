#include "MainHeader.h"

int LineNum = 0;
LineList Line; //Universal variable
Cursor cursor = {
    NULL,
    NULL,
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
    LineNum++;

    if (Line.First == NULL){
        Line.First = line_new;
        Line.Last = line_new;
    } else if (cursor.line_info == Line.Last){
        Line.Last->next = line_new;
        line_new->prev = Line.Last;
        Line.Last = line_new;
    } else {
        line_new->next = cursor.line_info->next;
        cursor.line_info->next = line_new;
        line_new->prev = cursor.line_info;
        line_new->next->prev = line_new;
    }

    if (cursor.line_info && (cursor.txt_info != cursor.line_info->TxtLast)){
        if (!cursor.txt_info){
            line_new->TxtFirst = cursor.line_info->TxtFirst;
            line_new->TxtLast = cursor.line_info->TxtLast;
            cursor.line_info->TxtFirst = NULL;
            cursor.line_info->TxtLast = NULL;
        } else {
            line_new->TxtFirst = cursor.txt_info->next;
            if (line_new->TxtFirst){
                line_new->TxtLast = cursor.line_info->TxtLast;
                cursor.txt_info->next->prev = NULL;
                cursor.txt_info->next = NULL;
            }
            cursor.line_info->TxtLast = cursor.txt_info;
        }
    }
    cursor.line_info = line_new;
    cursor.txt_info = NULL;
}

void add(infotype x){
    adrTxt elem = createTxtElem(x);
    if (!cursor.txt_info && cursor.line_info->TxtFirst){
        elem->next = cursor.line_info->TxtFirst;
        cursor.line_info->TxtFirst->prev = elem;
        cursor.line_info->TxtFirst = elem;

    }else if (cursor.line_info->TxtFirst == NULL){
        cursor.line_info->TxtFirst = elem;
        cursor.line_info->TxtLast = elem;
    }else if (cursor.txt_info == cursor.line_info->TxtLast) {
        cursor.txt_info->next = elem;
        elem->prev = cursor.txt_info;
        cursor.line_info->TxtLast = elem;
    }else {
        elem->next = cursor.txt_info->next;
        elem->next->prev = elem;
        cursor.txt_info->next = elem;
        elem->prev = cursor.txt_info;
    }

    cursor.txt_info = elem;
    cursor.line_info->TxtLen++;
}

//Deletion

void backspace(){
    if (cursor.txt_info){
        cursor.line_info->TxtLen--;
        if (cursor.txt_info == cursor.line_info->TxtFirst){
            cursor.txt_info = NULL;
            cursor.line_info->TxtFirst = cursor.line_info->TxtFirst->next;
            if (cursor.line_info->TxtFirst == NULL){
                cursor.line_info->TxtLast = NULL;
            }
        } else if (cursor.txt_info == cursor.line_info->TxtLast) {
            cursor.txt_info = cursor.txt_info->prev;
            cursor.txt_info->next->prev = NULL;
            cursor.txt_info->next = NULL;
            cursor.line_info->TxtLast = cursor.txt_info;
        } else {
            adrTxt tmp = cursor.txt_info->prev;
            cursor.txt_info->prev->next = cursor.txt_info->next;
            cursor.txt_info->next->prev = cursor.txt_info->prev;
            cursor.txt_info->next = NULL;
            cursor.txt_info->prev = NULL;
            cursor.txt_info = tmp;
        }
    } else if (cursor.line_info->LineNumber != 1) {  //Hapus line
        adrTxt tmpTxt = cursor.line_info->prev->TxtLast;

        if (!tmpTxt){
            cursor.line_info->prev->TxtFirst = cursor.line_info->TxtFirst;
            cursor.line_info->prev->TxtLast  = cursor.line_info->TxtLast;
        } else {
            tmpTxt->next = cursor.line_info->TxtFirst;
            if (tmpTxt->next){
               cursor.line_info->prev->TxtLast = cursor.line_info->TxtLast;
               tmpTxt->next->prev = tmpTxt;
            }
        }
        cursor.txt_info = tmpTxt;
        adrLine tmpLine = cursor.line_info->prev;
        tmpLine->next = cursor.line_info->next;
        if (cursor.line_info->next != NULL){
            cursor.line_info->next->prev = tmpLine;
        }

        if (cursor.line_info == Line.Last){
            Line.Last = tmpLine;
        }
        cursor.line_info->next = NULL;
        cursor.line_info->prev = NULL;
        cursor.line_info = tmpLine;
        LineNum--;
    }
}

void delete_elem(){
    if (cursor.txt_info != cursor.line_info->TxtLast){
        cursor.line_info->TxtLen--;
        if (!cursor.txt_info && cursor.line_info->TxtFirst){
            cursor.line_info->TxtFirst = cursor.line_info->TxtFirst->next;
            if (!cursor.line_info->TxtFirst){
                cursor.line_info->TxtLast = NULL;
            } else {
                 cursor.line_info->TxtFirst->prev->next = NULL;
                 cursor.line_info->TxtFirst->prev = NULL;
            }
        } else if (cursor.txt_info->next == cursor.line_info->TxtLast){
            cursor.txt_info->next = NULL;
            cursor.line_info->TxtLast->prev = NULL;
            cursor.line_info->TxtLast = cursor.txt_info;
        } else {
             adrTxt tmp = cursor.txt_info->next->next;
             cursor.txt_info->next = tmp;
             tmp->prev->prev = NULL;
             tmp->prev->next = NULL;
             tmp->prev = cursor.txt_info;
        }
    }
}

int get_code(){
  int ch = getch();

  if ( ch == 0 || ch == 224 )
    ch = 256 + getch();

  return ch;
}

void updateLineNumber(){
    int num = 1;
    adrLine tmp = Line.First;
    while(tmp){
        tmp->LineNumber = num++;
        tmp = tmp->next;
    }
}
