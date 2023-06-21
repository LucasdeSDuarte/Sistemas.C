#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

void menuRelatorios();
//Função relatório de usuarios
void relatorioUsuario(){

  	FILE *fptr;
	short int ch;
	
	fptr = fopen("usuarios.db","r");

	while((ch=fgetc(fptr)) != EOF)
	printf("%c", ch);
	fclose(fptr);
	getchar();
	printf("\n\n\n");
	
	system("pause");
	for (;;) menuRelatorios();
}
