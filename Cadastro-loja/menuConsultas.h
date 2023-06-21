#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<string.h>

void menuCadastrosRelatorios();
void consultaProdutos();

//Menu para telas cadástros
void menuConsultas(){
	int op;
	//repetição principal de todo o menu
	do{
		// operação que usuario ira escolher entre 1 para consulta produtos 2 voltar menuprincipal 3 sair.
		system("cls");
		printf("###################################################");
		printf("\n Bem Vindo!\n Tela de Consultas...\n");
		printf("###################################################\n\n");
		printf("\n DIGITE \n [1] Consulta de Produtos.");
		printf("\n [2] Menu Principal.");
		printf("\n [3] Sair.");
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
    		printf("\n DIGITE \n [1] Consulta de Produtos.");
			printf("\n [2] Menu Principal.");
			printf("\n [3] Sair.");
			printf("\n E Precione Enter para Continuar. ");
			printf("  \n ");
	     
    }	//Menu de escolha entre 1 2 3 ou da erro caso digite algo diferrente
		switch(op){
					
			case 1:
				printf("\n");
				system("cls");
				printf("######################################");
				printf("\n Bem Vindo!\n Tela de Consulta de Produtos...\n");
				printf("######################################\n\n");
				consultaProdutos();
				break;
				
			case 2:
				printf("\n");
				system("cls");
				printf("######################################");
				printf("\n Menu Inicial...\n");
				printf("######################################\n\n");
				menuCadastrosRelatorios(); // volta para o menu inicial
				break;			
				
			case 3:
				system("cls");
				printf("#####################################");
				printf("\a\n Fim do programa.\n");
				printf("#####################################\n\n");
				exit(0);  // Finaliza o Programa caso entre aqui no case 5
				break;	
				
			// Caso o usuario digite outro numero que nãoo seja 1, 2, 3, 4 ou 5  aparece esse erro.	
			default:
				system("cls");
				printf("####################################");
				printf("\a\n !OPCAO INVALIDA\n TENTE NOVAMENTE!");
				printf("\n#################################\n\n");
				
				getchar();
		}
	}while(op != 1 && op != 2);	
}
