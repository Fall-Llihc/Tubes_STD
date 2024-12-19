#ifndef STRUCT_AND_TYPEDEF_H_INCLUDED
#define STRUCT_AND_TYPEDEF_H_INCLUDED

typedef char infotype;
typedef struct ElemenLine* adrLine;
typedef struct ElemenTxt* adrTxt;

struct ElemenLine{
    int LineNumber;
    int TxtLen;
    adrTxt TxtFirst;
    adrTxt TxtLast;
    adrLine prev;
    adrLine next;
};

struct ElemenTxt{
    infotype info;
    adrTxt prev;
    adrTxt next;
};

struct LineList{
    adrLine First;
    adrLine Last;
};

struct Cursor{
    adrLine line_info;
    adrTxt txt_info;
};

#endif // STRUCT_AND_TYPEDEF_H_INCLUDED
