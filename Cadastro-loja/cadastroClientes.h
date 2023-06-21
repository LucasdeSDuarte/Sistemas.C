#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <iostream>
#include <unistd.h>

void menuCadastros();
//Cadastro de clientes
void cadastroClientes(){
	char nome[50];
	char cpf[11];
	char tel[20];
	int tam, op; 

	FILE *fptr;
	fptr= fopen("cliente.txt", "a+");
	
	do{
		system("cls");

			fflush(stdin);
			printf(" Informe Nome / Razão Social: ");
			fflush(fptr);
			gets(nome);
			
			fflush(stdin);
			printf(" Informe CPF segindo esse padrão 85835598731:  ");  
			gets(cpf);
			
			fflush(stdin);
			printf(" Informe Telefone segindo esse padrão 11981983232: ");
			gets(tel);
			
			tam = strlen(cpf); //validar tamanho de digitos pega a a quantidade e passa pra tam
			tam = strlen(tel); //validar tamanho de digitos pega a a quantidade e passa pra tam
			
			//Validação de da quantidade de digitos do cpf e do telefone
			if(tam == 11){
				//printf(" \nCPF VALIDADO..\n\n");
			} else{
				printf(" \nCPF INVALIDADO.\n");
				sleep(2);
			}	
			
			if(tam == 11){
				
			} else{
				printf("TELEFONE INVALIDADO.\n\n");
				sleep(2);
			}	
				
				
				}while(tam != 11 && tam != 11);
				
			// Armazena tudo em txt dessa forma descrita
			fflush(fptr);
			fprintf(fptr, "\nNOME:%s\nCPF:%s\nTEL:%s\n", nome, cpf, tel);
			printf("\n");
			printf("\n Dados Gravados com sucesso!\n\n");
			fclose (fptr);
			
			printf("\n");	
			system("pause");
			fflush(stdin);
			menuCadastros();
			
	}


