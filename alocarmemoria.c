#include <stdlib.h>
#include "db_imagem.h"
#include "menu.h"
#include "alocarmemoria.h"

/* faz a alocação dinâmica de memória da imagem */
void alocar_memoria(Imagem *imagem){
    imagem->matriz = (Pixel**)calloc(imagem->lin, sizeof(Pixel*));
    for (int i = 0; i < imagem->lin; i++){
        imagem->matriz[i] = (Pixel*)calloc(imagem->col, sizeof(Pixel));
    }
}

/* faz a liberação de memória alocada da imagem  */
void liberar_memoria(Imagem *imagem){
    for (int i = 0; i < imagem->lin; i++){
        free(imagem->matriz[i]);
    }
    free(imagem->matriz);
}