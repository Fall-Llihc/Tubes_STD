#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

void ShowConsoleCursor(bool showFlag);
void DefaultDisplay(bool &typing);
void IntroText(string mode);
string commandCheck();
void show_help();
void cls(HANDLE hConsole);

void printLine(adrLine P, int linenum);
void Print(string mode);
void seeCursor();

#endif // DISPLAY_H_INCLUDED
