# sysimager
System that manipulates images.

# Projeto final de ITP - Introdução às Técnicas de Programação

Prof. Orientador: Dr. André Maurício Cunha Campos
Descrição do Projeto: Processamento de Imagem
Autor: Elildes Fortaleza Santos

*** TAREFAS ***
1) Criar pastas para separar arquivos com funcionalidades parecidas:
    Foi criado os seguintes arquivos para organização dos códigos e modularização do programa:
> main.c: função principal que dá início e fim do programa.
> menu.c: serve para chamar as funções e oferecer as opções aos usuários. Faz a interação com o usuário.
> alocarmemoria.c: onde estão implementadas as funções de alocação dinâmica de memória.
> db_imagem.c: serve para chamar/incluir os campos das estruturas registradas em db_imagem.h
> lerescrever.c: onde estão implementadas as funções de leitura e escrita das imagens.
> processo.c: onde estão implementadas as funções de filtros.
> Makefile: estão os códigos que servirá para compilar e criar a biblioteca estática do programa.

Obs.: cada arquivo .c tem um arquivo .h de mesmo nome, que servem para escrever as interfaces/assinaturas
das funções que estão implementadas nos arquivos .c.

2) O que foi feito:

> Escala de Cinza:

    Função: void filtro_cinza(Imagem *imagem).
    
    Esta função aplica escala de cinza na imagem lida. A função substitui
    os valores dos pixels da imagem lida com a média dos valores das
    cores r, g, b.

    Obs.: a função recebe como parãmetro um ponteiro tipo estrutura (Imagem *imagem) e servirá para
    passar a função os valores da imagem lida. A função é do tipo void, não retorna nenhum valor.

> Ampliar uma imagem:

    Função: void filtro_ampliar(Imagem *imagem, int num, Imagem *aux).

    Esta função amplia uma imagem em 'num' vezes.
    O número inteiro 'num' (digitado pelo usuário) é a quantidade de vezes que a imagem será ampliada.
    
    Obs.: a função recebe como parãmetros dois ponteiros tipo estrutura (Imagem *imagem, Imagem *aux),
    sendo que o ponteiro *imagem é o ponteiro que está armazenando os valores da imagem lida, e o
    ponteiro *aux servirá para receber os valores da nova imagem ampliada. A função também recebe como
    parãmetro um inteiro (int num) que indica a quantidade de vezes que a imagem será ampliada.
    A função é do tipo void, não retorna nenhum valor.
    
> Reduzir uma imagem:

    Função: void filtro_reduzir(Imagem *imagem, int num, Imagem *aux).

    Esta função reduz uma imagem em 'num' vezes.
    O número inteiro 'num' (digitado pelo usuário) é a quantidade de vezes que a imagem será reduzida.
    
    Obs.: a função recebe como parãmetros dois ponteiros tipo estrutura (Imagem *imagem, Imagem *aux),
    sendo que o ponteiro *imagem é o ponteiro que está armazenando os valores da imagem lida, e o
    ponteiro *aux servirá para receber os valores da nova imagem reduzida. A função também recebe como
    parãmetro um inteiro (int num) que indica a quantidade de vezes que a imagem será reduzida. A função
    é do tipo void, não retorna nenhum valor.

> Rotacionar uma imagem:

    Função: void rotacionar_img(Imagem *imagem, Imagem *aux).

    Esta função rotaciona a imagem escolhida pelo usuário a 90º.
    Caso o usuário queira ratacionar a imagem a 180º, a função deverá ser chamada
    duas vezes, e para rotacionar a imagem a 270º, a função deverá ser
    chamada três vezes.

    Obs.: a função recebe como parãmetros dois ponteiros do tipo estrutura (Imagem *imagem e Imagem *aux).
    O ponteiro *imagem servirá para passar para a função os valores da imagem lida e o ponteiro *aux
    servirá para receber os valores da nova imagem rotacionada. A função é do tipo void, não retorna nenhum valor.
    
> Aplicar filtro de sharpening:

    Função: void filtro_sharpening(Imagem *imagem, Imagem *aux).

    Esta função aplica o filtro de sharpening (nitidez) na imagem escolhida pelo usuário.

    Obs.: a função recebe como parãmetros dois ponteiros do tipo estrutura (Imagem *imagem e Imagem *aux).
    O ponteiro *imagem servirá para passar para a função os valores da imagem lida e o ponteiro *aux
    servirá para receber os valores da nova imagem filtrada com sharpening.
    A função é do tipo void, não retorna nenhum valor.
    
> Aplicar filtro de blurring:

    Função: void filtro_blurring(Imagem *imagem, Imagem *aux).

    Esta função aplica o filtro de blurring (borrado) na imagem escolhida pelo usuário.

    Obs.: a função recebe como parãmetros dois ponteiros do tipo estrutura (Imagem *imagem e Imagem *aux).
    O ponteiro *imagem servirá para passar para a função os valores da imagem lida e o ponteiro *aux
    servirá para receber os valores da nova imagem filtrada com blurring.
    A função é do tipo void, não retorna nenhum valor.

> Aplicar filtro de Detecção de Bordas:

    Função: void filtro_bordas(Imagem *imagem, Imagem *aux).

    A função aplica o filtro de detecção de bordas na imagem escolhida pelo usuário.

    Obs.: a função recebe como parãmetros dois ponteiros do tipo estrutura (Imagem *imagem e Imagem *aux).
    O ponteiro *imagem servirá para passar para a função os valores da imagem lida e o ponteiro *aux
    servirá para receber os valores da nova imagem filtrada com detecção de bordas.
    A função é do tipo void, não retorna nenhum valor.

3) O que não foi feito:
    Apenas não foi feito uma função recurssiva.
    
4) O que seria feito diferentemente.

    Percebemos ao final do projeto que algumas alterações nos códigos seriam possíveis,
entretando devido ao tempo não foi possível fazer as mudanças conforme detalhamos a
seguir:

> Funções de filtro que usam máscara:
    As funções de filtro_sharpening(), filtro_blurring() e a função filtro_bordas() usam
praticamente o mesmo código, mudando apenas a matriz 3x3 que é usada como máscara para
fazer alterações nos valores da imagem. Com isso, após finalizarmos o projeto, foi percebido
que estas funções poderiam ser implementadas com apenas uma função, bastando para isso
retirar a máscara da função e adicionar um ponteiro ou matriz como argumento da função, a
qual deverá ser passado os lementos da máscara. Como a máscara sairia de dentro da função,
a máscara deveria ser declarada em outro lugar, sendo que para cada filtro deverá ser declarado
uma máscara com os valores correspondentes. Com essa mudança, o código ficaria bem reduzido.

> Função que rotaciona imagem com uso de função recurssiva:
    A função rotacionar_img() rotaciona uma imagem a 90º, para que a imagem seja rotacionada
a 180º, a função deverá ser chamada duas vezes, e se for chamada três vezes a imagem irá
rotacionar a 270º. Entretanto, percebemos que talvez fosse possível fazer alterações no código
da função para que fosse implementado uma função recursiva, tendo como condição de parada quando
a quantidade de vezes que a função fosse chamado chegasse a zero.

> Otimização nas funções de filtro_sharpening(), filtro_blurring() e a função filtro_bordas():
    Como os códigos destas funções são praticamente os mesmos, mudando basicamente a máscara,
poderíamos ter feito os calculos dos valores para conversão dos canais (reg, green e blue) com
dois laços 'for' de repetição dentro dos laços 'for' (laço que percorrerá a imagem de origem),
fazendo com que os códigos ficassem com menos linhas.

5) Como compilar o projeto, deixando explícito se foi utilizada alguma biblioteca externa que 
precise ser instalada, que versão e quais parâmetros extras são necessários para o
compilador:
    Para que o usuário compile o projeto de maneira mais fácil, foi feito como trabalho extra,
um arquivo 'Makefile' que está configurado para executar os comandos de compilação e criação
de uma biblioteca estática.
    Para compilar e criar uma biblioteca estática do projeto, basta que:
a) O usuário entre na pasta do projeto;
b) Digite no terminal o comando 'make' (sem aspas). Com isso os comandos configurados
    no arquivo 'Makefile' irá gerar os arquivos binários de cada arquico .c, em seguida com o programa
    'ar' os arquivos binário .o serão juntados em um arquivos .a (libimg.a) e depois com o arquivo .a
    (biblioteca estática) criado será gerado o arquivo executável (exec).
c) E por fim para executar o programa basta digitar: ./exec.
    Segue abaixo as linhas de comando para compilar, criar bilioteca e executar o programa:

> entrar na pasta do projeto
> make
> ./exec

Obs01.: basta digitar o comando make apenas uma vez, após isso basta executar o programa com o comando
        './exec'. Caso algum arquivo do programa seja alterado o comando make deverá ser digitado novamente.

d) Na execução do programa:
    Na primeira tela o programa apresentará as opções de filtros que o usuário deverá digitar uma das opções
ou digitar '0' (zero) para sair do sistema.
    Após a escolha da opção desejada o sistema irá apresentar outras opções ao usuário, conforme a opção escolhida.
até retornar a tela inicial.

*** PADRONIZAÇÕES ***
> Variavel simples:
Ex.: int valor.
É a variável que é escrita com apenas letras minúsculas, cujo nome seja relacionado
com a sua função no código.
> Variável composta:
Ex.: int valorMoeda.
É a variável que é escrita com duas ou mais palavras.
A primeira palavra é escrita com letras minúsculas concatenada com a segunda palavra, sendo que apenas
a primeira letra da segunda palavra é escrita com letra maiúscula.
> Funções:
Ex.: void filtro_sharpening(Imagem *imagem, Imagem *aux);
 Nome da função: se tiver nome composto será escrito em minpuscula e com um '_' entre as duas
 palavras.

*** EXTRA ***
    Como trabalho extra foi feito o seguinte:
1) Criação de bibliotecas (biblioteca estática) e arquivo Makefile:
    Para criação da bilioteca devemos apenas digitar o seguinte comando: make
Este comando irá fazer com que os comandos que estão no arquivo Makefile
sejam executados.

  Para que o usuário compile o projeto de maneira mais fácil, foi feito como trabalho extra,
um arquivo 'Makefile' que está configurado para executar os comandos de compilação e criação
de uma biblioteca estática.
    Para compilar e criar uma biblioteca estática do projeto, basta que:
a) O usuário entre na pasta do projeto;
b) Digite no terminal o comando 'make' (sem aspas). Com isso os comandos configurados
    no arquivo 'Makefile' irá gerar os arquivos binários de cada arquico .c, em seguida com o programa
    'ar' os arquivos binário .o serão juntados em um arquivos .a (libimg.a) e depois com o arquivo .a
    (biblioteca estática) criado será gerado o arquivo executável (exec).
c) E por fim para executar o programa basta digitar: ./exec.
    Segue abaixo as linhas de comando para compilar, criar bilioteca e executar o programa:

> entrar na pasta do projeto
> make
> ./exec

Obs01.: basta digitar o comando make apenas uma vez, após isso basta executar o programa com o comando
        './exec'. Caso algum arquivo do programa seja alterado o comando make deverá ser digitado.

Obs.02: abaixo estão listados os comandos implementados no arquivo Makefile:

        todos: main.o menu.o db_imagem.o lerescrever.o alocarmemoria.o processo.o
            ar rcs libimg.a menu.o db_imagem.o lerescrever.o alocarmemoria.o processo.o
            gcc main.o -limg -o exec -L.
            rm -r *.o

        main.o:
            gcc main.c -c -o main.o

        menu.o:
            gcc menu.c -c -o menu.o
            
        db_imagem.o:
            gcc db_imagem.c -c -o db_imagem.o

        lerescrever.o:
            gcc lerescrever.c -c -o lerescrever.o

        alocarmemoria.o:
            gcc alocarmemoria.c -c -o alocarmemoria.o

        processo.o:
            gcc processo.c -c -o processo.o

2) Implementação do filtro de negativo:
    Também como trabalho extra fizemos um filtro de negativo.

    Aplicar filtro de Negativo:

    Função: void filtro_negativo(Imagem *imagem, Imagem *aux).

    A função aplica o filtro de negativo na imagem escolhida pelo usuário.

    Obs.: a função recebe como parãmetros dois ponteiros do tipo estrutura (Imagem *imagem e Imagem *aux).
    O ponteiro *imagem servirá para passar para a função os valores da imagem lida e o ponteiro *aux
    servirá para receber os valores da nova imagem filtrada com Negativo.
    A função é do tipo void, não retorna nenhum valor.

3) Uso da ferramenta Git Hub:
    Na criação do projeto foi utilizado o programa Git Hub que serviu para manter todo o 
projeto em um repositório.
    O Git Hub foi de grande importância porque mantinha o projeto sempres atualizado com a versão mais recente, pois quando o trabalho era feito em sala de aula bastava baixar as atualizações do projeto que estavam no repositório.
