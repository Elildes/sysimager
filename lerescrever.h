/*********************************************************
 * Biblioteca de funções que faz a leitura e escrita das
 * imagens.
*********************************************************/
#include "db_imagem.h"

#ifndef LERESCREVER_H
#define LERESCREVER_H
/*
    Esta função ler o arquivo de imagem pixel a pixel e escreve
    os dados lidos em um arquivo. Os nomes do arquivo lido e escrito
    são definidos pelo usuário e se caso o nome do arquivo lido não
    existir a função escreve uma mensagem de erro.
*/

void ler_imagem(Imagem *imagem, char nomeImg[50]);
/*
    Esta função salva os dados dos pixels da imagem lida que foram trasformados
    através da opção do usuário.
*/
void salvar_imagem(Imagem *imagem, char nomeImg[50]);

#endif