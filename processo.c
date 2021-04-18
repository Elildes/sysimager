#include <stdlib.h>
#include <string.h>
#include "db_imagem.h"
#include "menu.h"
#include "processo.h"
#include "alocarmemoria.h"

/*
    Função que aplica a escala de cinza na imagem escolhida pelo usuário.
*/
void filtro_cinza(Imagem *imagem) {
    int i, j;
    for (i = 0; i < imagem->lin; i++) {
        for (j = 0; j < imagem->col; j++) {
            imagem->matriz[i][j].r = (int) (((imagem->matriz[i][j].r) + (imagem->matriz[i][j].g) + (imagem->matriz[i][j].b))/3); //calcula o valor para conversão
            imagem->matriz[i][j].g = imagem->matriz[i][j].r; //copia o valor para
            imagem->matriz[i][j].b = imagem->matriz[i][j].r; //todos membros r, g, b
        }
    }
}

/*
    Função que amplia a imagem em 'num' vezes. O número inteiro num (digitado pelo usuário)
    é a quantidade de vezes que a imagem será ampliada.
*/
void filtro_ampliar(Imagem *imagem, int num, Imagem *aux){

    strcpy(aux->code, imagem->code);    //copia o código (string) da imagem de origem para a matriz ampliada/auxiliar
    aux->col = imagem->col*num;     //qtde. de colunas da imagem ampliada:
    aux->lin = imagem->lin*num;     //qtde. de linhas da imagem lida x num (escala a ser ampliada)
    aux->ton = imagem->ton;     //atribui tonalidade máxima a imagem ampliada: mesma quantidade da imagem lida (origem)

    alocar_memoria(aux);     //aloca memória dinamicamente para a nova imagem

    /* AMPLIA A IMAGEM 'num' VEZES */
	//leitura da imagem de origem
    for (int lin = 0; lin < imagem->lin; lin++){        //para cada elemento lin de imagem->matriz
        for (int col = 0; col < imagem->col; col++){    //fazer col vezes
            //atribui valores a matriz da nova imagem
            for (int l = lin*num; l < (lin*num + num); l++){     //atribui valores as linhas da nova imagem
                for (int c = col*num; c < (col*num + num); c++){     //atribui valores as colunas da nova imagem
                    //imagem de destino (ampliada)
                    aux->matriz[l][c].r = imagem->matriz[lin][col].r;
                    aux->matriz[l][c].g = imagem->matriz[lin][col].g;
                    aux->matriz[l][c].b = imagem->matriz[lin][col].b;
                }
            }
        }
    }
}

/*
    Função que reduz a imagem em 'num' vezes. O número inteiro num (digitado pelo usuário)
    é a quantidade de vezes que a imagem será reduzida.
*/
void filtro_reduzir(Imagem *imagem, int num, Imagem *aux){
    int l, c, lin, col, somaRed=0, somaGreen=0, somaBlue=0;
    strcpy(aux->code, imagem->code);    //copia o código (string) da imagem de origem para a matriz reduzida/auxiliar
    aux->col = imagem->col/num;     //qtde. de colunas da imagem reduzida:
    aux->lin = imagem->lin/num;     //qtde. de linhas da imagem lida / num (escala a ser reduzida)
    aux->ton = imagem->ton;     //atribui tonalidade máxima a imagem reduzida: mesma quantidade da imagem lida (origem)

    alocar_memoria(aux);     //aloca memória dinamicamente para a nova imagem

    /* REDUZ A IMAGEM 'num' VEZES */
	//atribui valores a matriz da nova imagem
    for (l = 0; l < (imagem->lin/num); l++){        //atribui valores as linhas da nova imagem
        for (c = 0; c < (imagem->col/num); c++){    //atribui valores as colunas da nova imagem
            somaRed = 0;
            somaGreen = 0;
            somaBlue = 0;
            //leitura da imagem de origem
            for (lin = l*num; lin < (l*num + num); lin++){     //para cada elemento lin de imagem->matriz
                for (col = c*num; col < (c*num + num); col++){     //fazer col vezes
                    somaRed += imagem->matriz[lin][col].r;
                    somaGreen += imagem->matriz[lin][col].g;
                    somaBlue += imagem->matriz[lin][col].b;
                }
            }
            //imagem de destino (reduzida)
            aux->matriz[l][c].r = somaRed/(num*num);
            aux->matriz[l][c].g = somaGreen/(num*num);
            aux->matriz[l][c].b = somaBlue/(num*num);
        }
    }
}

/*
    Função que rotaciona a imagem escolhida pelo usuário a 90º.
    Caso queira ratacionar a imagem a 180º, a função deverá ser chamada
    duas vezes, e para rotacionar a imagem a 270º, a função deverá ser
    chamada três vezes.
*/
void rotacionar_img(Imagem *imagem, Imagem *aux){

    int i, j , l, c;
    aux->lin = imagem->col;   //a qtde. de linhas da imagem de destino serão iguais a qtde. de colunas da imagem de origem
    aux->col = imagem->lin;   //a qtde. de colunas da imagem de destino serão iguais a qtde. de linhas da imagem de origem
    aux->ton = imagem->ton;   //a qtde. da tonalidade máxima serão iguais

    alocar_memoria(aux);     //aloca memória dinamicamente para a nova imagem
    
    /* ROTACIONA A IMAGEM A 90º */
    for (i = 0; i < imagem->lin; i++) {     //acessa as linhas da matriz da imagem de origem
        for (j = 0; j < imagem->col; j++) { //acessa as colunas da matriz da imagem de origem
            l = j;
            c = aux -> col - 1 - i;
            aux->matriz[l][c].r = (int) (imagem->matriz[i][j].r); //faz a mudança de posição dos pixel
            aux->matriz[l][c].g = (int) (imagem->matriz[i][j].g); //
            aux->matriz[l][c].b = (int) (imagem->matriz[i][j].b); //
        }        
    }
}

/*
    Função que aplica o filtro de sharpening (nitidez) na imagem escolhida pelo usuário.
*/
void filtro_sharpening(Imagem *imagem, Imagem *aux) {
    strcpy(aux->code, imagem->code);    //copia o código (string) da imagem de origem para a matriz filtrada/auxiliar
    aux->col = imagem->col;     //qtde. de colunas da imagem filtrada:
    aux->lin = imagem->lin;     //qtde. de linhas da imagem lida x num (escala a ser filtrada)
    aux->ton = imagem->ton;     //atribui tonalidade máxima da imagem filtrada: mesma quantidade da imagem lida (origem)

    alocar_memoria(aux);     //aloca memória dinamicamente para a nova imagem
    //máscara que percorrerá toda imagem realizando as operações de filtro sobre os pixels
    int mask[3][3] = { { 0, -1,  0},
                       {-1,  5, -1},
                       { 0, -1,  0} };
    /* laço que percorrerá a imagem de origem */
    int i, j, l, c, somaRed=0, somaGreen=0, somaBlue=0;
    for (i = 1; i < imagem->lin - 1; i++) {
        for (j = 1; j < imagem->col - 1; j++) {
            somaRed=0;     //variável que receberá os valores do canal Red (r)
            somaGreen=0;   //variável que receberá os valores do canal Green (g)
            somaBlue=0;    //variável que receberá os valores do canal Blue (b)
            //calcula o valor para conversão do canal Red
            somaRed += (int) (imagem->matriz[i-1][j-1].r * 0 +
                              imagem->matriz[i-1][j].r * -1 +
                              imagem->matriz[i-1][j+1].r * 0 +
                              imagem->matriz[i][j-1].r * -1 +
                              imagem->matriz[i][j].r * 5 +
                              imagem->matriz[i][j+1].r * -1 +
                              imagem->matriz[i+1][j-1].r * 0 +
                              imagem->matriz[i+1][j].r * -1 +
                              imagem->matriz[i+1][j+1].r * 0);
            //calcula o valor para conversão do canal Green
            somaGreen += (int) (imagem->matriz[i-1][j-1].g * 0 +
                                imagem->matriz[i-1][j].g * -1 +
                                imagem->matriz[i-1][j+1].g * 0 +
                                imagem->matriz[i][j-1].g * -1 +
                                imagem->matriz[i][j].g * 5 +
                                imagem->matriz[i][j+1].g * -1 +
                                imagem->matriz[i+1][j-1].g * 0 +
                                imagem->matriz[i+1][j].g * -1 +
                                imagem->matriz[i+1][j+1].g * 0);
            //calcula o valor para conversão do canal Blue
            somaBlue += (int) (imagem->matriz[i-1][j-1].b * 0 +
                               imagem->matriz[i-1][j].b * -1 +
                               imagem->matriz[i-1][j+1].b * 0 +
                               imagem->matriz[i][j-1].b * -1 +
                               imagem->matriz[i][j].b * 5 +
                               imagem->matriz[i][j+1].b * -1 +
                               imagem->matriz[i+1][j-1].b * 0 +
                               imagem->matriz[i+1][j].b * -1 +
                               imagem->matriz[i+1][j+1].b * 0);
            //Verifica se algum canal vai ficar com valores abaixo de zero
            if(somaRed < 0) somaRed = 0;
            if(somaGreen < 0) somaGreen = 0;
            if(somaBlue < 0) somaBlue = 0;
            //Verifica se algum canal vai ficar com valores acima de 255
            if(somaRed > 255) somaRed = 255;
            if(somaGreen > 255) somaGreen = 255;
            if(somaBlue > 255) somaBlue = 255;
            //Atribui novos valores aos pixels da nova imagem
            aux->matriz[i][j].r = somaRed;    //copia o valor para
            aux->matriz[i][j].g = somaGreen;  //todos membros
            aux->matriz[i][j].b = somaBlue;   //r, g, b
        }
    }
}

/*
    Função que aplica o filtro de blurring (borrado) na imagem escolhida pelo usuário.
*/
void filtro_blurring(Imagem *imagem, Imagem *aux) {
    strcpy(aux->code, imagem->code);    //copia o código (string) da imagem de origem para a matriz filtrada/auxiliar
    aux->col = imagem->col;     //qtde. de colunas da imagem filtrada:
    aux->lin = imagem->lin;     //qtde. de linhas da imagem lida x num (escala a ser filtrada)
    aux->ton = imagem->ton;     //atribui tonalidade máxima da imagem filtrada: mesma quantidade da imagem lida (origem)

    alocar_memoria(aux);     //aloca memória dinamicamente para a mova imagem
    //máscara que percorrerá toda imagem realizando as operações de filtro sobre os pixels
    int mask[3][3] = { {1, 1, 1},
                       {1, 1, 1},
                       {1, 1, 1} };
    /* laço que percorrerá a imagem de origem */
    
    int i, j, l, c, somaRed=0, somaGreen=0, somaBlue=0;
    for (i = 1; i < imagem->lin - 1; i++) {
        for (j = 1; j < imagem->col - 1; j++) {
            somaRed=0;     //variável que receberá os valores do canal Red (r)
            somaGreen=0;   //variável que receberá os valores do canal Green (g)
            somaBlue=0;    //variável que receberá os valores do canal Blue (b)
            //calcula o valor para conversão do canal Red
            somaRed += (int) ((imagem->matriz[i-1][j-1].r * 1 +
                              imagem->matriz[i-1][j].r * 1 +
                              imagem->matriz[i-1][j+1].r * 1 +
                              imagem->matriz[i][j-1].r * 1 +
                              imagem->matriz[i][j].r * 1 +
                              imagem->matriz[i][j+1].r * 1 +
                              imagem->matriz[i+1][j-1].r * 1 +
                              imagem->matriz[i+1][j].r * 1 +
                              imagem->matriz[i+1][j+1].r * 1) * 1/9);
            //calcula o valor para conversão do canal Green
            somaGreen += (int) ((imagem->matriz[i-1][j-1].g * 1 +
                                imagem->matriz[i-1][j].g * 1 +
                                imagem->matriz[i-1][j+1].g * 1 +
                                imagem->matriz[i][j-1].g * 1 +
                                imagem->matriz[i][j].g * 1 +
                                imagem->matriz[i][j+1].g * 1 +
                                imagem->matriz[i+1][j-1].g * 1 +
                                imagem->matriz[i+1][j].g * 1 +
                                imagem->matriz[i+1][j+1].g * 1) * 1/9);
            //calcula o valor para conversão do canal Blue
            somaBlue += (int) ((imagem->matriz[i-1][j-1].b * 1 +
                               imagem->matriz[i-1][j].b * 1 +
                               imagem->matriz[i-1][j+1].b * 1 +
                               imagem->matriz[i][j-1].b * 1 +
                               imagem->matriz[i][j].b * 1 +
                               imagem->matriz[i][j+1].b * 1 +
                               imagem->matriz[i+1][j-1].b * 1 +
                               imagem->matriz[i+1][j].b * 1 +
                               imagem->matriz[i+1][j+1].b * 1) * 1/9);
            //Verifica se algum canal vai ficar com valores abaixo de zero
            if(somaRed < 0) somaRed = 0;
            if(somaGreen < 0) somaGreen = 0;
            if(somaBlue < 0) somaBlue = 0;
            //Verifica se algum canal vai ficar com valores acima de 255
            if(somaRed > 255) somaRed = 255;
            if(somaGreen > 255) somaGreen = 255;
            if(somaBlue > 255) somaBlue = 255;
            //Atribui novos valores aos pixels da nova imagem
            aux->matriz[i][j].r = somaRed;    //copia o valor para
            aux->matriz[i][j].g = somaGreen;  //todos membros
            aux->matriz[i][j].b = somaBlue;   //r, g, b
        }
    }
}

/*
    Função que aplica o filtro de detecção de bordas na imagem escolhida pelo usuário.
*/
void filtro_bordas(Imagem *imagem, Imagem *aux){
    strcpy(aux->code, imagem->code);    //copia o código (string) da imagem de origem para a matriz filtrada/auxiliar
    aux->col = imagem->col;     //qtde. de colunas da imagem filtrada:
    aux->lin = imagem->lin;     //qtde. de linhas da imagem lida x num (escala a ser filtrada)
    aux->ton = imagem->ton;     //atribui tonalidade máxima da imagem filtrada: mesma quantidade da imagem lida (origem)

    alocar_memoria(aux);     //aloca memória dinamicamente para a nova imagem
    //máscara que percorrerá toda imagem realizando as operações de filtro sobre os pixels
    int mask[3][3] = { { -1, -1,  -1},
                       { -1,  8, -1},
                       { -1, -1, -1} };
    /* laço que percorrerá a imagem de origem */
    int i, j, l, c, somaRed=0, somaGreen=0, somaBlue=0;
    for (i = 1; i < imagem->lin - 1; i++) {
        for (j = 1; j < imagem->col - 1; j++) {
            somaRed=0;     //variável que receberá os valores do canal Red (r)
            somaGreen=0;   //variável que receberá os valores do canal Green (g)
            somaBlue=0;    //variável que receberá os valores do canal Blue (b)
            //calcula o valor para conversão do canal Red
            somaRed += (int) (imagem->matriz[i-1][j-1].r * -1 +
                              imagem->matriz[i-1][j].r * -1 +
                              imagem->matriz[i-1][j+1].r * -1 +
                              imagem->matriz[i][j-1].r * -1 +
                              imagem->matriz[i][j].r * 8 +
                              imagem->matriz[i][j+1].r * -1 +
                              imagem->matriz[i+1][j-1].r * -1 +
                              imagem->matriz[i+1][j].r * -1 +
                              imagem->matriz[i+1][j+1].r * -1);
            //calcula o valor para conversão do canal Green
            somaGreen += (int) (imagem->matriz[i-1][j-1].g * -1 +
                                imagem->matriz[i-1][j].g * -1 +
                                imagem->matriz[i-1][j+1].g * -1 +
                                imagem->matriz[i][j-1].g * -1 +
                                imagem->matriz[i][j].g * 8 +
                                imagem->matriz[i][j+1].g * -1 +
                                imagem->matriz[i+1][j-1].g * -1 +
                                imagem->matriz[i+1][j].g * -1 +
                                imagem->matriz[i+1][j+1].g * -1);
            //calcula o valor para conversão do canal Blue
            somaBlue += (int) (imagem->matriz[i-1][j-1].b * -1 +
                               imagem->matriz[i-1][j].b * -1 +
                               imagem->matriz[i-1][j+1].b * -1 +
                               imagem->matriz[i][j-1].b * -1 +
                               imagem->matriz[i][j].b * 8 +
                               imagem->matriz[i][j+1].b * -1 +
                               imagem->matriz[i+1][j-1].b * -1 +
                               imagem->matriz[i+1][j].b * -1 +
                               imagem->matriz[i+1][j+1].b * -1);
            //Verifica se algum canal vai ficar com valores abaixo de zero
            if(somaRed < 0) somaRed = 0;
            if(somaGreen < 0) somaGreen = 0;
            if(somaBlue < 0) somaBlue = 0;
            //Verifica se algum canal vai ficar com valores acima de 255
            if(somaRed > 255) somaRed = 255;
            if(somaGreen > 255) somaGreen = 255;
            if(somaBlue > 255) somaBlue = 255;
            //Atribui novos valores aos pixels da nova imagem
            aux->matriz[i][j].r = somaRed;    //copia o valor para
            aux->matriz[i][j].g = somaGreen;  //todos membros
            aux->matriz[i][j].b = somaBlue;   //r, g, b
        }
    }
}

/*
    Função que aplica o filtro de negativo na imagem escolhida pelo usuário.
*/
void filtro_negativo(Imagem *imagem, Imagem *aux) {

    aux->lin = imagem->lin;   //a qtde. de linhas da imagem de destino serão iguais a qtde. de colunas da imagem de origem
    aux->col = imagem->col;   //a qtde. de colunas da imagem de destino serão iguais a qtde. de linhas da imagem de origem
    aux->ton = imagem->ton;   //a qtde. da tonalidade máxima serão iguais

    alocar_memoria(aux);    //alocar memória dinâmica

    /* laço que percorrerá a imagem de origem */
    for (int i = 0; i < imagem->lin; i++) {
        for (int j = 0; j < imagem->col; j++) {
            aux->matriz[i][j].r = 255 -  imagem -> matriz [i][j].r;  // os valores dos pixels da nova
            aux->matriz[i][j].g = 255 -  imagem -> matriz [i][j].g;  // imagem será a diferença dos valores
            aux->matriz[i][j].b = 255 -  imagem -> matriz [i][j].b;  // dos pixels da imagem de origem com 255
         }
    }
}