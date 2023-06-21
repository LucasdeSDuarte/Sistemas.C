#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
                                         
#include <time.h>
#define MAX_SENHA 15
#define MAX_LOGIN 50
#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)

#include "cadastroProdutos.h"
#include "cadastroUsuario.h"
#include "cadastroClientes.h"

#include "menuInicial.h"
#include "menuCadastrosRelatorios.h"
#include "menuCadastros.h"
#include "menuRelatorios.h"
#include "menuConsultas.h"

#include "consultaProdutos.h"

#include "relatorioClientes.h"
#include "relatorioProdutos.h"
#include "relatorioUsuario.h"

void cadastroProdutos();
void cadastroUsuario();
void cadastroClientes();
void menuInicial();

void menuCadastrosRelatorios();
void menuCadastros(); 
void menuRelatorios();
void menuConsultas();

void consultaProdutos();

void relatorioClientes();
void relatorioProdutos();
void relatorioUsuario();

int Usuario( FILE* file, char* user, char* senha ); //valida usuario
char* CriaSenha();

int main()
{	
	setlocale(LC_ALL, "Portuguese");
	int login_efetuado = 0;
	
	//4cadastroUsuario();
    menuInicial();
 
    int Usuario( FILE* file, char* user, char* senha );
    char* CriaSenha();
    
		FILE* fpIN;

	int option = 0;

	char *user  = (char*)malloc(sizeof *user * MAX_LOGIN);
	char *senha,
		 *confirmaSenha;
				int i=0;
				while(!login_efetuado){
				system("cls");
				printf("#####################################");
				printf("\n Bem Vindo!\n Tela de Login...\n");
				printf("#####################################\n\n");
				printf("Usuario: ");
				fflush(stdin);
				gets(user);
				printf("Senha: ");
				fflush(stdin);
				senha = CriaSenha();
				// Lendo dados salvos
				fpIN = fopen("usuarios.db", "r");
				if(Usuario(fpIN, user, senha)){
					//validação se usuario esta ou não registrado
                    printf("\nUsuario registrado.\n\n");
                    sleep(1);
                    menuCadastrosRelatorios();
                }else{
                	printf("\nUsuario nao registrado\n\n");	
                	sleep(1);
			
				}
            
				fclose(fpIN);
				free(senha);        
           }
  
    menuCadastrosRelatorios();
		
    return 0;
}

//------------------------------------------------------------------------------------------
// Valudação Usuario
int Usuario( FILE* file, char* user, char* senha ){
	char tmpLogin[MAX_LOGIN];
	char tmpSenha[MAX_SENHA];

	fscanf(file, "%s", tmpLogin);

	while( !feof(file) )
	{	//simples comparação entre o que foi salvo com o que esta digitando
		if( !strcmp(tmpLogin, user))
		{
			fscanf(file, "%s", tmpSenha);

			if( !strcmp(tmpSenha, senha))
				return 1;
		}
		else
		{
			fscanf(file, "%*s");
		}

		fscanf(file, "%s", tmpLogin);
	}

	return 0;
}
//------------------------------------------------------------------------------
char* CriaSenha() {
    register int i;
	
	char* senha = (char*)malloc(sizeof *senha * MAX_SENHA);

    for(i = 0; i < MAX_SENHA; i++)
	{
        senha[i] = getch();
        if(senha[i] == '\r')
            break;
        else
            printf("*"); //Camufla senha.
    }
	senha[i] = '\0';

	return senha;
	system("cls");
}

