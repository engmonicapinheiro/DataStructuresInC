#include <stdlib.h>
#include "tabuleiro.h"

/* escreve o tabuleiro */
void Tabuleiro(char b[][10])
{
    putchar('\n');
    printf("     A   B   C   D   E   F   G   H   I   J  \n");
    printf("   -----------------------------------------\n");
    printf(" 1 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", b[0][0], b[0][1], b[0][2], b[0][3], b[0][4], b[0][5], b[0][6], b[0][7], b[0][8], b[0][9]);
    printf("   -----------------------------------------\n");
    printf(" 2 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", b[1][0], b[1][1], b[1][2], b[1][3], b[1][4], b[1][5], b[1][6], b[1][7], b[1][8], b[1][9]);
    printf("   -----------------------------------------\n");
    printf(" 3 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", b[2][0], b[2][1], b[2][2], b[2][3], b[2][4], b[2][5], b[2][6], b[2][7], b[2][8], b[2][9]);
    printf("   -----------------------------------------\n");
    printf(" 4 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", b[3][0], b[3][1], b[3][2], b[3][3], b[3][4], b[3][5], b[3][6], b[3][7], b[3][8], b[3][9]);
    printf("   -----------------------------------------\n");
    printf(" 5 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", b[4][0], b[4][1], b[4][2], b[4][3], b[4][4], b[4][5], b[4][6], b[4][7], b[4][8], b[4][9]);
    printf("   -----------------------------------------\n");
    printf(" 6 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", b[5][0], b[5][1], b[5][2], b[5][3], b[5][4], b[5][5], b[5][6], b[5][7], b[5][8], b[5][9]);
    printf("   -----------------------------------------\n");
    printf(" 7 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", b[6][0], b[6][1], b[6][2], b[6][3], b[6][4], b[6][5], b[6][6], b[6][7], b[6][8], b[6][9]);
    printf("   -----------------------------------------\n");
    printf(" 8 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", b[7][0], b[7][1], b[7][2], b[7][3], b[7][4], b[7][5], b[7][6], b[7][7], b[7][8], b[7][9]);
    printf("   -----------------------------------------\n");
    putchar('\n');

}

/* insere inimigos e espacos
 * em branco no tabuleiro */
void InsertElementsInBoard(char board[8][10])
{
    unsigned int numbers;       //armazena numeros aleatorios
    register int i, j;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 10; j++)
        {
            //numbers recebe um número aleatório entre 1 e 100
            numbers = rand() % 100 + 1;

            if(numbers % 2)
            {
                board[i][j] = ' '; //se o nr for par, insere um espaco em branco
            }
            else
            {
                board[i][j] = '@';  //se o nr for par, insere um "inimigo"
            }
        }
    }
}

/* escreve o menu */
char Menu()
{
    char option;

    printf("(s) sortear novamente\n");
    printf("(j) jogar\n>>>");
    scanf("%c", &option);

    return option;
}


/* gera números aleatórios para distribuir
 * as minas no tabuleiro */
void NewSeed()
{
    unsigned long capture;
    time(&capture);
    srand((unsigned)capture);
}

unsigned int mappingColumns(char column)
{
    switch(column)
    {
        case 'a':
        case 'A':
            return 0;
            break;
        case 'b':
        case 'B':
            return 1;
            break;
        case 'c':
        case 'C':
            return 2;
            break;
        case 'd':
        case 'D':
            return 3;
            break;
        case 'e':
        case 'E':
            return 4;
            break;
        case 'f':
        case 'F':
            return 5;
            break;
        case 'g':
        case'G':
            return 6;
            break;
        case 'h':
        case 'H':
            return 7;
            break;
        case 'i':
        case 'I':
            return 8;
            break;
        case 'j':
        case 'J':
            return 9;
            break;
    }
}

