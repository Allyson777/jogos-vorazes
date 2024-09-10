#include "maze.h"

int main()
{
    Labirinto labirinto;
    Pilha caminho;
    
    int n, m;
    inicializarPilha(&caminho, 1000); 
    printf("Digite a largura do labirinto: ");
    scanf("%d", &m);
    printf("Digite a altura do labirinto: ");
    scanf("%d", &n);
    carregarLabirinto(&labirinto, n, m);
    printf("\n");
    imprimeLabirinto(&labirinto);

    printf("Buscando caminho...\n");
    if (encontrarCaminho(&labirinto, labirinto.posicaoInicial, &caminho))
    {
        printf("Caminho encontrado:\n");
        imprimirResultado(&caminho);
    }
    else
    {
        printf("Nenhum caminho encontrado.\n");
    }

    desalocarPilha(&caminho);
    return 0;
}