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