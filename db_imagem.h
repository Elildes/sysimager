#ifndef DB_IMAGEM_H
#define DB_IMAGEM_H

/*
    Registro que servirá para identificar os canais
    r (red), g (green) e b (blue)
*/
typedef struct {
    int r, g, b;
} Pixel;

/* Registro que servirá para guardar os valores das imagens */
typedef struct {
    char code[3];
    int col;
    int lin;
    int ton;
    Pixel **matriz;
} Imagem;

#endif