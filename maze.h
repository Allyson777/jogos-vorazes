#ifndef MAZE_H
#define MAZE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
    Estrutura: Monstro
    Atributos:
        posicao: (Estrutura Posicao que guarda a posição atual do monstro)
    Objetivo: Representar um monstro no labirinto.
*/
typedef struct monstros
{
    Posicao posicao;
} Monstro;

/*
    Estrutura: Labirinto
    Atributos:
        mapa: (Matriz de caracteres que representa o layout do labirinto, com paredes, caminhos, o ponto inicial de 'A' e monstros)
        altura: (Inteiro que representa a altura do labirinto)
        largura: (Inteiro que representa a largura do labirinto)
        posicaoInicial: (Estrutura Posicao que guarda a posição inicial de 'A')
        monstros: (Array de estruturas Monstro que contém os monstros do labirinto)
        numMonstros: (Inteiro que indica o número de monstros no labirinto)
    Objetivo: Armazenar as informações do labirinto, como o layout, as dimensões e a posição dos monstros.
*/
typedef struct
{
    char mapa[TAMANHO_MAX][TAMANHO_MAX];
    int altura, largura;
    Posicao posicaoInicial;
    Monstro monstros[TAMANHO_MAX];
    int numMonstros;
} Labirinto;

/*
    Estrutura: Pilha
    Atributos:
        pilha: (Array de posições que representa a pilha de posições percorridas por 'A')
        topo: (Índice do topo da pilha)
        tamanho_maximo: (Tamanho máximo que a pilha pode ter)
        movimentos: (Array de caracteres que armazena os movimentos realizados por 'A')
    Objetivo: Armazenar as posições e os movimentos realizados por 'A' durante a exploração do labirinto.
*/
typedef struct
{
    Posicao *pilha;
    int topo;
    int tamanho_maximo;
    char *movimentos;
} Pilha;

/*
    Estrutura: Fila
    Atributos:
        itens: (Array para armazenar as posições da fila)
        primeiro: (Índice do primeiro elemento da fila)
        ultimo: (Índice do último elemento da fila)
        tamanho: (Tamanho máximo da fila)
    Objetivo: Armazenar as posições enquanto o labirinto é explorado em largura.
*/
typedef struct
{
    Posicao *itens;
    int primeiro;
    int ultimo;
    int tamanho;
} Fila;

/*
    Estrutura: ItemFila
    Atributos:
        x: (Coordenada x da posição)
        y: (Coordenada y da posição)
        distancia: (Distância da posição inicial até esta posição)
    Objetivo: Representar um item da fila usado durante a busca em largura.
*/
typedef struct
{
    int x, y;
    int distancia;
} ItemFila;

/*
    Nome da função: carregarLabirinto
    Parâmetros:
        labirinto: (Ponteiro para uma estrutura Labirinto)
        linhas: (Número de linhas do labirinto)
        colunas: (Número de colunas do labirinto)
    Objetivo: Carregar o layout do labirinto a partir de uma entrada externa.
*/
void carregarLabirinto(Labirinto *labirinto, int linhas, int colunas);

/*
    Nome da função: imprimeLabirinto
    Parâmetros:
        labirinto: (Ponteiro para uma estrutura Labirinto)
    Objetivo: Exibir o layout do labirinto no terminal.
*/
void imprimeLabirinto(Labirinto *labirinto);

/*
    Nome da função: inicializarPilha
    Parâmetros:
        pilha: (Ponteiro para uma estrutura Pilha)
        tamanho_maximo: (Tamanho máximo que a pilha pode ter)
    Objetivo: Inicializar uma pilha para armazenar as posições e movimentos de 'A'.
*/
void inicializarPilha(Pilha *pilha, int tamanho_maximo);

/*
    Nome da função: pilhaVazia
    Parâmetros:
        pilha: (Ponteiro para uma estrutura Pilha)
    Retorno: (Inteiro, retorna 1 se a pilha está vazia, 0 caso contrário)
    Objetivo: Verificar se a pilha está vazia.
*/
int pilhaVazia(Pilha *pilha);

/*
    Nome da função: empilhar
    Parâmetros:
        pilha: (Ponteiro para uma estrutura Pilha)
        pos: (Estrutura Posicao que será empilhada)
        movimento: (Caractere que representa o movimento realizado)
    Objetivo: Inserir uma nova posição e movimento na pilha.
*/
void empilhar(Pilha *pilha, Posicao pos, char movimento);

/*
    Nome da função: desempilhar
    Parâmetros:
        pilha: (Ponteiro para uma estrutura Pilha)
    Retorno: (Estrutura Posicao que foi desempilhada)
    Objetivo: Remover a última posição da pilha e retornar essa posição.
*/
Posicao desempilhar(Pilha *pilha);

/*
    Nome da função: imprimirPilha
    Parâmetros:
        pilha: (Ponteiro para uma estrutura Pilha)
    Objetivo: Imprimir os movimentos e posições armazenados na pilha.
*/
void imprimirPilha(Pilha *pilha);

/*
    Nome da função: desalocarPilha
    Parâmetros:
        pilha: (Ponteiro para uma estrutura Pilha)
    Objetivo: Liberar a memória alocada para a pilha.
*/
void desalocarPilha(Pilha *pilha);

/*
    Nome da função: inicializarFila
    Parâmetros:
        q: (Ponteiro para uma estrutura Fila)
        tamanhoMaximo: (Tamanho máximo que a fila pode ter)
    Objetivo: Inicializar uma fila com um tamanho máximo definido.
*/
void inicializarFila(Fila *f, int tamanhoMaximo);

/*
    Nome da função: filaVazia
    Parâmetros:
        q: (Ponteiro para uma estrutura Fila)
    Retorno: (Inteiro, retorna 1 se a fila está vazia, 0 caso contrário)
    Objetivo: Verificar se a fila está vazia.
*/
int filaVazia(Fila *f);

/*
    Nome da função: enfileirar
    Parâmetros:
        q: (Ponteiro para uma estrutura Fila)
        valor: (Estrutura Posicao que será adicionada à fila)
    Objetivo: Inserir uma nova posição no final da fila.
*/
void enfileirar(Fila *f, Posicao valor);

/*
    Nome da função: desenfileirar
    Parâmetros:
        q: (Ponteiro para uma estrutura Fila)
    Retorno: (Estrutura Posicao que foi removida do início da fila)
    Objetivo: Remover e retornar a primeira posição da fila.
*/
Posicao desenfileirar(Fila *f);

/*
    Nome da função: inicializarMonstros
    Parâmetros:
        labirinto: (Ponteiro para uma estrutura Labirinto)
    Objetivo: Inicializar as posições dos monstros no labirinto.
*/
void inicializarMonstros(Labirinto *labirinto);

/*
    Nome da função: resolverLabirintoComMonstros
    Parâmetros:
        labirinto: (Ponteiro para uma estrutura Labirinto)
        movimentosA: (inteiro armazenando a quantidade de movimentos que A fez até a saída (se houve))
    Retorno: (Inteiro que indica o sucesso ou falha da solução)
    Objetivo: Resolver o labirinto levando em consideração a presença de monstros.
*/
int resolverLabirintoComMonstros(Labirinto *labirinto, int *movimentosA);

/*
    Nome da função: resolverLabirinto
    Parâmetros:
        labirinto: (Ponteiro para uma estrutura Labirinto)
    Objetivo: Resolver o labirinto sem considerar os monstros.
*/
void resolverLabirinto(Labirinto *labirinto);

#endif