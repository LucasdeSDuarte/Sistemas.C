#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <iostream>

using namespace std;
void cadastroProdutos();
void menuConsultas();


bool procura(char nome[50],int &quant, float &valor){
    char nome_lida[50];
    int quant_lida;
    float valor_lido;



    FILE *arquivo;

    arquivo = fopen("estoque.txt","r");
    while(!feof(arquivo)){
        setbuf(stdin,NULL);
        fscanf(arquivo,"%d %s %f",&quant_lida,&nome_lida,&valor_lido);
        if(strcmp(nome_lida,nome)==0){
            quant=quant_lida;
            valor=valor_lido;
            fclose(arquivo);
            return true;
        }
    }
    fclose(arquivo);
    return false;
}

void consultaProdutos(){
	
    char nome[50];
    int quant, op;
    float valor;
    
	fflush(stdin);
    while(1){
        system("cls");
        printf("Bem vindo ao Consulta Estoque");
        printf("Informe a descricao do produto: ");
        gets(nome);
    

        if(procura(nome,quant,valor)){
            printf("\nProduto: %s",nome);
            printf("\nQuant. em estoque: %d",quant);
            printf("\nValor: %3.f\n",valor);
            system("pause");
            break;
        }else{
            printf("\n\nProduto nao encontrado!\n\n");
            system("pause");
        }
        
    }  
    menuConsultas();
}

