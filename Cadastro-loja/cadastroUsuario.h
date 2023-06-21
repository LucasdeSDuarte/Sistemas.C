#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <iostream>
#include <time.h>
#include <conio.h>


#define MAX_SENHA 15
#define MAX_LOGIN 50
#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)

void menuCadastros(); 
char* CriaSenha();

//Função cadastro de usuarios
void cadastroUsuario(){
		FILE* fpIN;

	int option = 0;

	char *user  = (char*)malloc(sizeof *user * MAX_LOGIN);
	char *senha,
		 *confirmaSenha;
		 
		 printf("Usuarios: ");
		 fflush(stdin);
				gets(user);

				do
				{	//cadastra senha e pede confirmação da senha
					printf("Senha: ");
					fflush(stdin);
					senha = CriaSenha();
					printf("\nConfirmacao de senha: ");
					confirmaSenha = CriaSenha();
					printf("\n");

					if( !strcmp(senha, confirmaSenha) )
						break;
					else
						printf("As senhas não são iguais. Tente novamente.\n\n\n");
					
						
				}while(1);

				fpIN = fopen("usuarios.db", "a+");
				fprintf(fpIN, "%s %s\n", user, senha);
				fclose(fpIN);

				free(senha);
				free(confirmaSenha);
			
			menuCadastros(); 
	}

