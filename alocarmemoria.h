/*********************************************************
 * Biblioteca de funções que que aloca memória dinamicamente
 * e libera o espaço alocado para as matrizes. Nas matrizes
 * são guardados os dados de leitura e escrita das imagens.
*********************************************************/
#include "db_imagem.h"

#ifndef ALOCARMEMORIA_H
#define ALOCARMEMORIA_H

/*
    Esta função faz a alocação dinâmica de memória da matriz/ponteiros, a
    qual recebeu os dados dos pixels alterados atraveś de uma função de manipilação
    de imagem que o usuário escolheu.
*/
void alocar_memoria(Imagem *imagem);

/*
    Esta função faz a liberação de memória que foi alocada para a matriz/ponteiros, a
    qual recebeu os dados dos pixels alterados atraveś de uma função de manipilação
    de imagem que o usuário escolheu.
*/
void liberar_memoria(Imagem *imagem);

#endif