#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <iostream>

void menuCadastros(); 


void cadastroProdutos(){
	char nome[50];
	int quant, op;
	float valor;
	
	FILE *fptr;
	fptr = fopen("estoque.txt", "a+");
	
	
			fflush(stdin);
			printf(" Informe o Nome do Produto: ");
			fflush(fptr);
			gets(nome);
			
			fflush(stdin);
			printf(" Informe a quantidade: ");
			scanf("%d", &quant);
			
			fflush(stdin);
			printf(" Informe preço: ");
			scanf("%f",&valor);
			
			fflush(fptr);
			fprintf(fptr, "%d %s %.2f \n", quant, nome, valor);
			printf("\n");
			printf("\n Dados Gravados com sucesso!\n\n");
			fclose (fptr);
			
			printf("\n");	
			system("pause");
			fflush(stdin);
			
			menuCadastros(); 
	}

