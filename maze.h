#ifndef __MAZE_H__
#define __MAZE_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAMANHO_MAX 1000

/*
    Estrutura: Posicao
    Atributos:
        x: (Inteiro que representa a coordenada x da posição no labirinto)
        y: (Inteiro que representa a coordenada y da posição no labirinto)
    Objetivo: Representar uma posição no labirinto, com coordenadas x e y.
*/
typedef struct
{
    int x, y;
} Posicao;

/*
    Estrutura: Labirinto
    Atributos:
        mapa: (Matriz de caracteres representando o labirinto)
        altura: (Inteiro que representa a altura do labirinto)
        largura: (Inteiro que representa a largura do labirinto)
        posicaoInicial: (Estrutura Posicao que guarda a posição inicial do tributo no labirinto)
    Objetivo: Armazenar as informações do labirinto.
*/
typedef struct
{
    char mapa[TAMANHO_MAX][TAMANHO_MAX];
    int altura, largura;
    Posicao posicaoInicial;
} Labirinto;

/*
    Estrutura: Pilha
    Atributos:
        pilha: (Ponteiro para uma lista dinâmica de posições, representando o caminho percorrido)
        topo: (Índice do topo da pilha, indicando a última posição inserida)
        tamanho_maximo: (Tamanho máximo da pilha)
        movimentos: (Ponteiro para uma string que armazena a sequência de movimentos realizados)
    Objetivo: Armazenar o caminho percorrido no labirinto, com as posições e os movimentos.
*/
typedef struct
{
    Posicao *pilha;
    int topo;
    int tamanho_maximo;
    char *movimentos;
} Pilha;

/*
    Nome da função: carregarLabirinto
    Parâmetros:
        labirinto: (Ponteiro para uma estrutura Labirinto)
        linhas: (Número de linhas do labirinto)
        colunas: (Número de colunas do labirinto)
    Objetivo: Inicializa o labirinto com as entradas e preenche o mapa com caracteres aleatórios.

*/
void carregarLabirinto(Labirinto *labirinto, int linhas, int colunas);

/*
    Nome da função: carregaLabirintoAleatorio
    Parâmetros:
        labirinto: (Ponteiro para uma estrutura Labirinto)
    Objetivo: Preencher o labirinto aleatoriamente para testes.
*/
void carregaLabirintoAleatorio(Labirinto *labirinto);

/*
    Nome da função: imprimeLabirinto
    Parâmetros:
        labirinto: (Ponteiro para uma estrutura Labirinto)
    Objetivo: Imprimir o labirinto.
*/
void imprimeLabirinto(Labirinto *labirinto);

/*
    Nome da função: inicializarPilha
    Parâmetros:
        pilha: (Ponteiro para uma estrutura Pilha)
        tamanho_maximo: (Tamanho máximo da pilha)
    Objetivo: Inicializar a estrutura pilha, alocando memória para armazenar as posições e movimentos.
*/
void inicializarPilha(Pilha *pilha, int tamanho_maximo);


/*
    Nome da função: empilhar
    Parâmetros:
        pilha: (Ponteiro para uma estrutura Pilha)
        pos: (Estrutura Posicao a ser empilhada)
        movimento: (Caractere representando o movimento associado)
    Objetivo: Adicionar uma posição e o movimento correspondente à pilha.
*/
void empilhar(Pilha *pilha, Posicao pos, char movimento);

/*
    Nome da função: desempilhar
    Parâmetros:
        pilha: (Ponteiro para uma estrutura Pilha)
    Objetivo: Remover e retornar a posição no topo da pilha.
    Retorno: A posição removida do topo da pilha.
*/
Posicao desempilhar(Pilha *pilha);

/*
    Nome da função: imprimirResultado
    Parâmetros:
        pilha: (Ponteiro para uma estrutura Pilha)
    Objetivo: Imprimir as posições e a sequência de movimentos armazenados na pilha.
*/
void imprimirResultado(Pilha *pilha);

/*
    Nome da função: desalocarPilha
    Parâmetros:
        pilha: (Ponteiro para uma estrutura Pilha)
    Objetivo: Liberar a memória alocada para a pilha e os movimentos, evitando vazamentos de memória.
*/
void desalocarPilha(Pilha *pilha);

/*
    Nome da função: encontrarCaminho
    Parâmetros:
        labirinto: (Ponteiro para uma estrutura Labirinto)
        posicaoAtual: (Estrutura Posicao indicando a posição atual no labirinto)
        caminho: (Ponteiro para uma estrutura Pilha onde o caminho encontrado será armazenado)
    Objetivo: Encontrar um caminho do início do labirinto até a borda usando busca em profundidade.
    Retorno: Retorna 1 se um caminho for encontrado, caso contrário retorna 0.
*/
int encontrarCaminho(Labirinto *labirinto, Posicao posicaoAtual, Pilha *caminho);

#endif
