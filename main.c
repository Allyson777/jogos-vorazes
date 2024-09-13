#include "maze.h"

int main()
{
    Labirinto labirinto; // Estrutura para armazenar o labirinto

    int altura, largura;

    scanf("%d %d", &altura, &largura); // Leitura das dimensões do labirinto

    carregarLabirinto(&labirinto, altura, largura); // Carrega o labirinto com as dimensões especificadas

    imprimeLabirinto(&labirinto); // Imprime a configuração inicial do labirinto

    printf("Buscando o menor caminho...\n");

    resolverLabirinto(&labirinto); // Resolve o labirinto e imprime o resultado

    return 0;
}