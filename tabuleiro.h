#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Tabuleiro(char b[][10]);
void NewSeed(void);
char Menu(void);
unsigned int mappingColumns(char column);
void InsertElementsInBoard(char board[8][10]);


#endif //TABULEIRO_H
