#ifndef HISTORY_AND_FEATURES_H_INCLUDED
#define HISTORY_AND_FEATURES_H_INCLUDED

typedef struct history* adrHistory;

struct history{
    string tipe;
    adrLine line;
    adrTxt txtelem;
    adrHistory next;
    adrHistory prev;
};

struct ListHistory{
    adrHistory First;
    adrHistory Last;
};


#endif // HISTORY_AND_FEATURES_H_INCLUDED
