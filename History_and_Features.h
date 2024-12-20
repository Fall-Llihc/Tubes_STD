#ifndef HISTORY_AND_FEATURES_H_INCLUDED
#define HISTORY_AND_FEATURES_H_INCLUDED
#include "MainHeader.h"

typedef struct history* adrHistory;

struct history{
    string tipe_inputan;
    adrLine linehis;
    adrTxt txthis;
    adrHistory next;
    adrHistory prev;
};

struct ListHistory{
    adrHistory First;
    adrHistory Last;
};

extern ListHistory HistoryList;
extern adrHistory CurrentHistory;

string commandCheck();
adrHistory createElemHistory(string tipe);
void addHistory(adrHistory P);
void undo();
void redo();

#endif // HISTORY_AND_FEATURES_H_INCLUDED
