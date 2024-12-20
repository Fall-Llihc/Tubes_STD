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

void up(){
    if (cursor.line_info->LineNumber > 1){
        int pos = 0;
        int i = 0;
        while(cursor.txt_info){
            pos++;
            cursor.txt_info = cursor.txt_info->prev;
        }
        cursor.line_info = cursor.line_info->prev;

        if (i < pos && cursor.txt_info == NULL){
            cursor.txt_info = cursor.line_info->TxtFirst;
            i++;
        }

        while(i < pos && cursor.txt_info != cursor.line_info->TxtLast){
            cursor.txt_info = cursor.txt_info->next;
            i++;
        }
    }
}

void down(){
    if (cursor.line_info->LineNumber < LineNum){
        int pos = 0;
        int i = 0;
        while(cursor.txt_info){
            pos++;
            cursor.txt_info = cursor.txt_info->prev;
        }
        cursor.line_info = cursor.line_info->next;

        if (i < pos && cursor.txt_info == NULL){
            cursor.txt_info = cursor.line_info->TxtFirst;
            i++;
        }

        while(i < pos && cursor.txt_info != cursor.line_info->TxtLast){
            cursor.txt_info = cursor.txt_info->next;
            i++;
        }
    }
}
