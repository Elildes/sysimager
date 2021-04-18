#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db_imagem.h"
#include "menu.h"
#include "lerescrever.h"
#include "alocarmemoria.h"
#include "processo.h"

/* Implementação da função menu(): esta função faz com que o programa fica rodando até escolher a opção 0 (sair: opção zero) */
void menu(){
    Imagem imagem;  //declara variável que irá armazenar a imagem de origem (a ser lida)
    Imagem aux, aux2, aux3;     //declara variável que irá armazenar a imagem de destino (a ser manipulada)
    int op, num;    //inteiros a serem lidos como opção de escolhas
    char nomeImg[50];    //string a ser digitada pelo usuário (nome da imagem a ser lida ou a salva)
    do{
        system("clear");    //limpa a tela do terminal
        //Escolher a opção desejada
        printf("*** SISTEMA DE PROCESSAMENTO E MANIPULAÇÃO DE IMAGENS ***\n");
        printf("\nDigite a opção desejada:\n");
        printf("1 - Para aplicar Escala de Cinza na imagem.\n");
        printf("2 - Para Ampliar uma imagem.\n");
        printf("3 - Para Reduzir uma imagem.\n");
        printf("4 - Para Rotacionar uma imagem.\n");
        printf("5 - Para aplicar filtro de blurring.\n");
        printf("6 - Para aplicar filtro de Sharpening.\n");
        printf("7 - Para aplicar filtro de Detecção de Bordas.\n");
        printf("8 - Para aplicar filtro de Negativo.\n");
        printf("0 - Para sair.\n");
        scanf("%i", &op);    /*Escolher as opções de filtros*/
        switch (op){
            case 1:     //Para aplicar escala de cinza na imagem
                /* Ler da entrada padrão o nome do arquivo de imagem a ser alterada */
                printf("\nDigite o nome do arquivo de imagem: ");
                scanf("%s", nomeImg);
                ler_imagem(&imagem, nomeImg);    //função que irá fazer a leitura da imagem
                /* aplicar o filtro de tom de cinzas */
                filtro_cinza(&imagem);
                /* Ler da entrada padrão o nome do arquivo de imagem a ser salvo */
                printf("\nDigite o nome da imagem que deseja salvar: ");
                scanf("%s", nomeImg);
                salvar_imagem(&imagem, nomeImg);
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                system("clear");    //limpa a tela do terminal     
                printf("\nArquivo de imagem salvo com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                /* libera o espaço de memória alocado dinamicamente */
                liberar_memoria(&imagem);
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                printf("\nFiltro de cinza aplicado na imagem com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                break;
            case 2:     //Para ampliar uma imagem
                system("clear");    //limpa a tela do terminal
                printf("*** SISTEMA DE PROCESSAMENTO E MANIPULAÇÃO DE IMAGENS ***\n");
                printf("** Ampliar uma imagem **\n");
                /* Ler da entrada padrão o nome do arquivo de imagem de origem */
                printf("\nDigite o nome do arquivo de imagem: ");
                scanf("%s", nomeImg);
                ler_imagem(&imagem, nomeImg);    //função que irá fazer a leitura da imagem
                /* aplicar a ampliação na imagem */
                printf("\nDigite a escala (zoom): ");
                scanf("%i", &num);
                filtro_ampliar(&imagem, num, &aux);
                printf("\nDigite o nome da imagem que deseja salvar: ");
                scanf("%s", nomeImg);
                salvar_imagem(&aux, nomeImg);
               /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                system("clear");    //limpa a tela do terminal     
                printf("\nArquivo de imagem salvo com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                /* libera o espaço de memórialibera o espaço de memória alocado dinamicamente */
                liberar_memoria(&imagem);
                liberar_memoria(&aux);
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                printf("\nAmpliação aplicado na imagem com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                break;
            case 3:     //Para reduzir uma imagem
                system("clear");    //limpa a tela do terminal
                printf("*** SISTEMA DE PROCESSAMENTO E MANIPULAÇÃO DE IMAGENS ***\n");
                printf("** Reduzir uma imagem **\n");
                /* Ler da entrada padrão o nome do arquivo de imagem de origem */
                printf("\nDigite o nome do arquivo de imagem: ");
                scanf("%s", nomeImg);
                ler_imagem(&imagem, nomeImg);    //função que irá fazer a leitura da imagem
                /* aplicar a redução na imagem */
                printf("\nDigite a escala (zoom): ");
                scanf("%i", &num);
                filtro_reduzir(&imagem, num, &aux);
                printf("\nDigite o nome da imagem que deseja salvar: ");
                scanf("%s", nomeImg);
                salvar_imagem(&aux, nomeImg);
               /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                system("clear");    //limpa a tela do terminal     
                printf("\nArquivo de imagem salvo com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                /* libera o espaço de memórialibera o espaço de memória alocado dinamicamente */
                liberar_memoria(&imagem);
                liberar_memoria(&aux);
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                printf("\nRedução aplicado na imagem com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                break;
            case 4:     //Para rotacionar uma imagem
                system("clear");    //limpa a tela do terminal
                printf("*** SISTEMA DE PROCESSAMENTO E MANIPULAÇÃO DE IMAGENS ***\n");
                printf("** Rotacionar uma imagem **\n");
                /* Ler da entrada padrão o nome do arquivo de imagem de origem */
                printf("\nDigite o nome do arquivo de imagem: ");
                scanf("%s", nomeImg);
                ler_imagem(&imagem, nomeImg);    //função que irá fazer a leitura da imagem
                /* rotacionar uma imagem */
                voltar:    //label: a execução do programa volta para esta linha se o usuário digitar uma opção inválida
                system("clear");    //limpa a tela do terminal
                printf("*** SISTEMA DE PROCESSAMENTO E MANIPULAÇÃO DE IMAGENS ***\n");
                printf("** Rotacionar uma imagem **\n");
                printf("\nDigite a opção desejada:\n");
                printf("1 - Rotacionar 90º.\n");    //apresenta na tela
                printf("2 - Rotacionar 180º.\n");   //para o usuário
                printf("3 - Rotacionar 270º.\n");   //as opções de rotação: 90º, 180º e 270º
                scanf("%i", &op);                   //ler um inteiro ref.a opção escolhida pelo usuário
                rotacionar_img(&imagem, &aux);      //chama a função que rotacionar a imagem a 90º
                if(op==1){     //Rotaciona a imagem em 90º
                    printf("\nDigite o nome da imagem que deseja salvar: ");
                    scanf("%s", nomeImg);
                    salvar_imagem(&aux, nomeImg);
                    //libera o espaço de memória alocado dinamicamente
                    liberar_memoria(&aux);
                }
                else if(op==2){     //Rotaciona a imagem em 180º
                    rotacionar_img(&aux, &aux2);      //chama a função novamente para rotacionar a imagem a 180º
                    printf("\nDigite o nome da imagem que deseja salvar: ");
                    scanf("%s", nomeImg);
                    salvar_imagem(&aux2, nomeImg);
                    //libera o espaço de memória alocado dinamicamente
                    liberar_memoria(&aux);
                    liberar_memoria(&aux2);
                }
                else if(op==3){     //Rotaciona a imagem em 270º
                    rotacionar_img(&aux, &aux2);      //chama a função novamente para rotacionar a imagem a 180º
                    rotacionar_img(&aux2, &aux3);      //chama a função novamente para rotacionar a imagem a 270º
                    printf("\nDigite o nome da imagem que deseja salvar: ");
                    scanf("%s", nomeImg);
                    salvar_imagem(&aux3, nomeImg);
                    //libera o espaço de memória alocado dinamicamente
                    liberar_memoria(&aux);
                    liberar_memoria(&aux2);
                    liberar_memoria(&aux3);
                }
                else if(op!=1 || op!=2 || op!=3){
                    printf("\nOpção inválida!!!\n");
                    getchar();    //mantém a tela aberta até apertar ENTER
                    getchar();    //mantém a tela aberta até apertar ENTER
                    goto voltar;  //retorna a execução do programa para a linha onde o label 'voltar' se encontra
                }
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                system("clear");    //limpa a tela do terminal     
                printf("\nArquivo de imagem salvo com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                /* libera o espaço de memória alocado dinamicamente */
                liberar_memoria(&imagem);
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                printf("\nRotação aplicado na imagem com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                break;
            case 5:  //Para aplicar filtro de blurring
                system("clear");    //limpa a tela do terminal
                printf("*** SISTEMA DE PROCESSAMENTO E MANIPULAÇÃO DE IMAGENS ***\n");
                printf("** Filtro de blurring na imagem **\n");
                /* Ler da entrada padrão o nome do arquivo de imagem de origem */
                printf("\nDigite o nome do arquivo de imagem: ");
                scanf("%s", nomeImg);
                ler_imagem(&imagem, nomeImg);    //função que irá fazer a leitura da imagem de origem
                /* aplicar filtro de blurring na imagem */
                filtro_blurring(&imagem, &aux);
                /* Ler da entrada padrão o nome do arquivo de imagem a ser salvo */
                printf("\nDigite o nome da imagem que deseja salvar: ");
                scanf("%s", nomeImg);
                salvar_imagem(&aux, nomeImg);
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                system("clear");    //limpa a tela do terminal     
                printf("\nArquivo de imagem salvo com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                /* libera o espaço de memória alocado dinamicamente */
                liberar_memoria(&imagem);
                liberar_memoria(&aux);
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                printf("\nFiltro de blurring aplicado na imagem com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                break;
            case 6:     //Para aplicar filtro de sharpening
                system("clear");    //limpa a tela do terminal
                printf("*** SISTEMA DE PROCESSAMENTO E MANIPULAÇÃO DE IMAGENS ***\n");
                printf("** Filtro de Sharpening na imagem **\n");
                /* Ler da entrada padrão o nome do arquivo de imagem de origem */
                printf("\nDigite o nome do arquivo de imagem: ");
                scanf("%s", nomeImg);
                ler_imagem(&imagem, nomeImg);    //função que irá fazer a leitura da imagem de origem
                /* aplicar filtro de sharpening na imagem */
                filtro_sharpening(&imagem, &aux);
                /* Ler da entrada padrão o nome do arquivo de imagem a ser salvo */
                printf("\nDigite o nome da imagem que deseja salvar: ");
                scanf("%s", nomeImg);
                salvar_imagem(&aux, nomeImg);
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                system("clear");    //limpa a tela do terminal     
                printf("\nArquivo de imagem salvo com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                /* libera o espaço de memória alocado dinamicamente */
                liberar_memoria(&imagem);
                liberar_memoria(&aux);
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                printf("\nFiltro de sharpening aplicado na imagem com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                break;
            case 7:     //Para aplicar filtro de detecção de bordas
                system("clear");    //limpa a tela do terminal
                printf("*** SISTEMA DE PROCESSAMENTO E MANIPULAÇÃO DE IMAGENS ***\n");
                printf("** Filtro de Detecção de Bordas na imagem **\n");
                /* Ler da entrada padrão o nome do arquivo de imagem de origem */
                printf("\nDigite o nome do arquivo de imagem: ");
                scanf("%s", nomeImg);
                ler_imagem(&imagem, nomeImg);    //função que irá fazer a leitura da imagem de origem
                /* aplicar filtro de detecção de bordas na imagem */
                filtro_bordas(&imagem, &aux);
                /* Ler da entrada padrão o nome do arquivo de imagem a ser salvo */
                printf("\nDigite o nome da imagem que deseja salvar: ");
                scanf("%s", nomeImg);
                salvar_imagem(&aux, nomeImg);
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                system("clear");    //limpa a tela do terminal     
                printf("\nArquivo de imagem salvo com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                /* libera o espaço de memória alocado dinamicamente */
                liberar_memoria(&imagem);
                liberar_memoria(&aux);
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                printf("\nFiltro de detecção de bordas aplicado na imagem com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                break;
            case 8:  //Para aplicar filtro negativo
                system("clear");    //limpa a tela do terminal
                printf("* SISTEMA DE PROCESSAMENTO E MANIPULAÇÃO DE IMAGENS *\n");
                printf("* Filtro de negativo na imagem *\n");
                /* Ler da entrada padrão o nome do arquivo de imagem de origem */
                printf("\nDigite o nome do arquivo de imagem: ");
                scanf("%s", nomeImg);
                ler_imagem(&imagem, nomeImg);    //função que irá fazer a leitura da imagem de origem
                /* aplicar filtro de negativo na imagem */
                filtro_negativo(&imagem, &aux);
                /* Ler da entrada padrão o nome do arquivo de imagem a ser salvo */
                printf("\nDigite o nome da imagem que deseja salvar: ");
                scanf("%s", nomeImg);
                salvar_imagem(&aux, nomeImg);
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                system("clear");    //limpa a tela do terminal     
                printf("\nArquivo de imagem salvo com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                /* libera o espaço de memória alocado dinamicamente */
                liberar_memoria(&imagem);
                liberar_memoria(&aux);
                /* MENSAGEM DE EXECUÇÃO COM SUCESSO */
                printf("\nFiltro de negativo aplicado na imagem com sucesso!!!\n");
                getchar();  //mantém a tela aberta até apertar ENTER
                break;
            case 0:     //Para sair do sistema
                break;
            default:    //Caso o usuário digite alguma opção que não esteja na lista case
                printf("\nOpção inválida!!!");
                getchar();  //mantém a tela aberta até apertar ENTER
                break;
        }
    }while (op != 0);
}