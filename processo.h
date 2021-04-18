/*********************************************************
 * Biblioteca de funções que que faz a manipulação nas
 * imagens através de filtros escolhidos pelo usuário.
*********************************************************/

#ifndef PROCESSO_H
#define PROCESSO_H

/*
    Esta função aplica escala de cinza na imagem lida. A função substitui
    os valores dos pixels da imagem lida com a média dos valores das
    cores r, g, b.
*/
void filtro_cinza(Imagem *imagem);

/*
    Esta função amplia a imagem em uma escala digitada pelo usuário.
    A função faz com que cada pixel da nova imagem tenha 2^num (dois elevado a 'num' inteiros),
    ou seja, em uma escala de 2x cada pixel da imagem ampliada terá 2^2 (num=2) = 4 pixels.
    Obs.: a função 'img_preencher()' é uma função auxiliar que atribui os elementos à imagem de destino.
*/
void filtro_ampliar(Imagem *imagem, int num, Imagem *aux);

/*
    Esta função reduz a imagem em uma escala digitada pelo usuário.
    A função faz com que cada pixel da nova imagem tenha seja igual a média da soma dos pixels
    da matriz de tamanho num*num (num é o zoom de redução).
*/
void filtro_reduzir(Imagem *imagem, int num, Imagem *aux);

/*
    Esta função aplica a rotação de 90º imagem escolhida pelo usuário.
    A função faz com que os pixels da altura da imagem lida seja atribuída aos
    pixels da largura da nova imagem, e vice e versa, ou seja, os pixels das colunas
    da matriz da nova imagem terá os valores dos pixels das linhas da imagem lida, e
    os pixels das linhas da matriz da nova imagem será os pixels das colunas da matriz
    lida.
    Obs.: para aplicar a rotação de 180º a função deverá ser chamada duas vezes, caso
    queira rotacionar a imagem a 270º, deverá chamar a função três vezes, 
*/
void rotacionar_img(Imagem *imagem, Imagem *aux);

/*
    Esta função aplica o filtro de sharpening (nitidez) em uma imagem escolhida pelo usuário.
    A função faz com que cada pixel da nova imagem tenha novos valores, de acordo com operações
    de soma e multiplicação realizada sobre os pixels da imagem de origem e a máscara
    (matriz 3x3), obtendo melhor nitidez na nova imagem.
*/
void filtro_sharpening(Imagem *imagem, Imagem *aux);

/*
    Esta função aplica o filtro de blurring (borrado) em uma imagem escolhida pelo usuário.
    A função faz com que cada pixel da nova imagem tenha novos valores, de acordo com operações
    de soma e multiplicação realizada sobre os pixels da imagem de origem e a máscara
    (matriz 3x3), obtendo efeito de borrado na nova imagem.
*/
void filtro_blurring(Imagem *imagem, Imagem *aux);

/*
    Esta função aplica o filtro de detecção de bordas  em uma imagem escolhida pelo usuário.
    A função faz com que cada pixel da nova imagem tenha novos valores, de acordo com operações
    de soma e multiplicação realizada sobre os pixels da imagem de origem e a máscara
    (matriz 3x3), obtendo efeito de borrado na nova imagem.
*/
void filtro_bordas(Imagem *imagem, Imagem *aux);

/*
    Esta função aplica o filtro de negativo na imagem escolhida pelo usuário.
    A função faz com que cada pixel da nova imagem seja igual a diferença do valor
    do pixel da imagem de origem com 255.
*/
void filtro_negativo(Imagem *imagem, Imagem *aux);

#endif