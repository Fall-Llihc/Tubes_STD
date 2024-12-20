#include "MainHeader.h"

void right(){
    if (!cursor.txt_info){
        cursor.txt_info = cursor.line_info->TxtFirst;
    } else if (cursor.txt_info != cursor.line_info->TxtLast){
        cursor.txt_info = cursor.txt_info->next;
    }
}

void left(){
    if (cursor.txt_info){
        cursor.txt_info = cursor.txt_info->prev;
    }
}
