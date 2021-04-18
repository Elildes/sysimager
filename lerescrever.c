#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "lerescrever.h"
#include "alocarmemoria.h"
#include "db_imagem.h"

/*
    Função que ler os dados dos pixels da imagem esolhida pelo usuário
    e escreveos dados lidos para uma matriz/ponteiro.
*/
void ler_imagem(Imagem *imagem, char nome_arq[50]) {
    int i, j;

    FILE *arquivo;

    if ((arquivo = fopen(nome_arq, "r")) == NULL) {
        printf("\n\nErro ao abrir o arquivo %s!!!\n\n", nome_arq);
        exit(1);       //sistema termina com falha
    }

    fscanf(arquivo, "%s", imagem->code);
    fscanf(arquivo, "%d", &imagem->col);
    fscanf(arquivo, "%d", &imagem->lin);
    fscanf(arquivo, "%d", &imagem->ton);

    alocar_memoria(imagem);
    
    //ler o conteúdo da imagem (pixel r,g,b)
    for (i = 0; i < imagem->lin; i++) {
        for (j = 0; j < imagem->col; j++) {
            fscanf(arquivo, "%d", &imagem->matriz[i][j].r);
            fscanf(arquivo, "%d", &imagem->matriz[i][j].g);
            fscanf(arquivo, "%d", &imagem->matriz[i][j].b);
        } 
    }
    fclose(arquivo);
}
/*
    Função que salva os dados dos pixels da imagem que foi escolhida
    pelo usuário após ser aplicado um tipo de filtro ou alguma 
    manipulação de imagem.
*/
void salvar_imagem(Imagem *img, char nome_arq[50]) {
    int i, j;
    FILE *arquivo;

    arquivo = fopen(nome_arq, "w");

    fprintf(arquivo, "P3\n");
    fprintf(arquivo, "%d ", img->col);
    fprintf(arquivo, "%d\n", img->lin);
    fprintf(arquivo, "%d\n", img->ton);

    for (i = 0; i < img->lin; i++) {
        for (j = 0; j < img->col; j++) {
            fprintf(arquivo, "%d ", img->matriz[i][j].r);
            fprintf(arquivo, "%d ", img->matriz[i][j].g);
            fprintf(arquivo, "%d\n", img->matriz[i][j].b);
        }
    }
    fclose(arquivo);
}