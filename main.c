/* Projeto original do Wagner Rambo
 * Curso Linguagem C Hotmart
 * 29/dez/2021
 *
 * requerimentos:
 * 1 - gerar a tabela
 * 2 - gerar nrs aleatorios
 * 3 - pegar o caractere da coluna e converter para um nr inteiro
 * pra passar como dimensao da matriz (da coluna)
 * 4 - criar o menu para o usuario
 * 5- jogar: atingir as @ (que sao os alvos)
 * 6 - se um @ for atingido, incrementa acertos
 * 7 - se um espaco vazio for atingido, incrementa erros
 * 8 - em caso de mais de 5 erros, o jogo acaba.
 * */

#include <stdio.h>
#include "tabuleiro.h"

#define LINES 8
#define COLUMNS 10

int main()
{
    char boats[LINES][COLUMNS] = {0};    //guarda as posicoes dos inimigos
    char option = 'j';          //opcao do usuario iniciada em 'j'
    char sortedFlag = 1;        //flag para novos sorteios
    char column = 0;            //caracteres das colunas

    unsigned int row = 0;       //numero das linhas
    unsigned int acertos = 0;   //numero de alvos atingidos
    unsigned int erros = 0;     //numero de erros cometidos

    do
    {
        if(sortedFlag)
        {
            system("cls");   //limpa a tela
            NewSeed();
            InsertElementsInBoard(boats);

            Tabuleiro(boats);   //atualiza matriz da batalha
        }

        option = Menu();
        putchar('\n');

    }while(option != 'j' && option != 'J'); //encerra o loop quando digitado j para jogar

    system("cls");   //limpa a tela
    Tabuleiro(boats);
    printf("ALVOS ATINGIDOS: %3d | ERROS: %3d\n", acertos, erros);

    while(1)
    {
        printf("Digite a posicao para o disparo ");
        scanf("%c%d", &column, &row);

        system("cls");

        if(boats[row-1][mappingColumns(column)] == '@')  //se a posicao indicada coincidir com um alvo...
        {
            boats[row-1][mappingColumns(column)] = '*'; //atualiza posicao com um '*' para indicar o alvo abatido
            acertos++;      //incrementa acertos
            putchar('\a');  //sinal sonoro
        }
        else if(boats[row-1][mappingColumns(column)] == ' ')
        {
            erros++;
            putchar('\a');  //sinal sonoro

            if(erros > 5)
            {
                printf("FOMOS DERROTADOS!\n");
                for(int i = 0; i < 5; i++)
                {
                    putchar('\a');   //sinal sonoro
                    system("PAUSE");
                    exit(0);   //interrompe o programa
                }
            }
        }

        Tabuleiro(boats);
        printf("ALVOS ATINGIDOS: %3d | ERROS: %3d\n", acertos, erros);
    }

    system("PAUSE");
    return 0;
}


