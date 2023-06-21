#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<string.h>
#define SIZE 200

//


void menuCadastrosRelatorios();
void relatorioClientes();
void relatorioProdutos();
void relatorioUsuario();

//Menu para telas cadastros
void menuRelatorios(){
	int op;
	//repetição principal de todo o menu
	do{
		// operação que usuario ira escolher entre 1 para Relatório de Usuarios 2 para reltório clientes 3 reltório produtos 4 para menu anterior5 sair.
		system("cls");
		printf("###################################################");
		printf("\n Bem Vindo!\n Tela de Relatórios...\n");
		printf("###################################################\n\n");
		printf("\n DIGITE \n [1] Relatório de Usuários.");
		printf("\n [2] Relatório de Clientes.");
		printf("\n [3] Relatório de Produtos.");
		printf("\n [4] Menu Principal.");
		printf("\n [5] Sair.");
		printf("\n E Precione Enter para Continuar. ");
		printf("  \n ");

		// faz verificaçãoo caso o usuario digite letras ou caracteres ou tudo que seja diferente de 1  e 2
		while (scanf("%d", &op) != 1 && scanf("%d", &op) != 2){ //enquanto não ler 1 inteiro
	    	static char temp[256];
    		fgets(temp, sizeof(temp), stdin); //limpa tudo o que ficou na entrada lendo como string
    		system("cls");
    		printf("###########################################");
			printf("\a\n !OPCAO INVALIDA\n TENTE NOVAMENTE!");
    		printf("\n###########################################\n\n");
    		printf("\n DIGITE \n [1] Relatório de Usuários.");
			printf("\n [2] Relatorio de Clientes.");
			printf("\n [4] Relatório de Produtos.");
			printf("\n [3] Menu Principal.");
			printf("\n [5] Sair.");
			printf("\n E Precione Enter para Continuar. ");
			printf("  \n ");
	     
    }	//Menu de escolha entre 1 2 ou da erro caso digite algo diferrente
		switch(op){
			case 1:
				printf("\n");
				system("cls");
				printf("#######################################");
				printf("\n Bem Vindo!\n Tela de Relatório de Usuários...\n");
				printf("#######################################\n\n");
				printf("| USUARIO  |   SENHA    |\n\n");
				printf("#######################################\n\n");
				relatorioUsuario();
				break;
				
			case 2:
				printf("\n");
				system("cls");
				printf("######################################");
				printf("\n Bem Vindo!\n Tela de Relatório de Clientes...\n");
				printf("######################################\n\n");
				relatorioClientes();
				break;
				
			case 3:
				printf("\n");
				system("cls");
				printf("######################################");
				printf("\n Bem Vindo!\n Tela de Relatório de Produtos...\n");
				printf("######################################\n\n");
				printf("QNT| PRODUTO| PREÇO |\n\n");
				relatorioProdutos();
				break;
				
			case 4:
				printf("\n");
				system("cls");
				printf("######################################");
				printf("\n Menu Inicial...\n");
				printf("######################################\n\n");
				menuCadastrosRelatorios();
				break;			
				
			case 5:
				system("cls");
				printf("#####################################");
				printf("\a\n Fim do programa.\n");
				printf("#####################################\n\n");
				exit(0);  // Finaliza o Programa caso entre aqui no case 3
				break;	
				
			// Caso o usuario digite outro numero que nãoo seja 1, 2 ou 3  aparece esse erro	
			default:
				system("cls");
				printf("####################################");
				printf("\a\n !OPCAO INVALIDA\n TENTE NOVAMENTE!");
				printf("\n#################################\n\n");
				
				getchar();
		}
	}while(op != 1 && op != 2);	
}
