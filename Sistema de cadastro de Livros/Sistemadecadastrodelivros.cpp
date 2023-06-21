#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
bool sair = false;
FILE *p;
FILE *aux;
struct livros{
	int codigo, ano;
	char titulo[50],assunto[50],editora[50],autor[50];
}livro;
void abrir_arq(){
	p = fopen("t.txt","a+b");
	aux = fopen("auxiliar.txt","wb");
	if(p == NULL){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}
}
void cadastro(){
	system("cls");
	abrir_arq();
	printf("Informe o codigo: ");
	scanf("%d", &livro.codigo);
	printf("Informe titulo: ");
	fflush(stdin);
	gets(livro.titulo);
	printf("Informe Assunto: ");
	fflush(stdin);
	gets(livro.assunto);
	printf("Informe Autor: ");
	fflush(stdin);
	gets(livro.autor);
	printf("Informe Editora: ");
	fflush(stdin);
	gets(livro.editora);
	printf("Informe Ano: ");
	fflush(stdin);
	scanf("%d", &livro.ano);
	fseek(p,SEEK_END,1);
	fwrite(&livro,sizeof(livro),1,p);
	fclose(p);
	fclose(aux);
	system("pause");	
}
void consulta(){
	system("cls");
	abrir_arq();
	int codigo,a=0;
	printf("Informe codigo a ser pesquisado: ");
	scanf("%d", &codigo);
	fseek(p,SEEK_SET,1);
	fread(&livro,sizeof(livro),1,p); 
	while(!feof(p)){
		if(livro.codigo==codigo){
			a++;
			printf("Livro encontrado\n");
			printf("Titulo: %s\n", livro.titulo);
			printf("Titulo: %s\n", livro.assunto);
			printf("Titulo: %s\n", livro.autor);
			printf("Titulo: %s\n", livro.editora);
			printf("Ano: %d\n\n", livro.ano);
		}
		fread(&livro,sizeof(livro),1,p);	
	}
	if(a==0)printf("Livro não encontrado\n");
	fclose(p);
	fclose(aux);
	system("pause");
}
void exclusao(){
	system("cls");
	abrir_arq();
	int codigo,a=0;
	printf("Informe codigo a ser pesquisado: ");
	scanf("%d", &codigo);
	fseek(p,SEEK_SET,1);
	fread(&livro,sizeof(livro),1,p); 
	while(!feof(p)){
		if(livro.codigo==codigo)a++;
		else fwrite(&livro,sizeof(livro),1,aux);
		fread(&livro,sizeof(livro),1,p); 
	}
	if(a==0)printf("Livro nao encontrado\n");
	else printf("Livro excluido\n");
	fclose(p);
	remove("t.txt");
	fclose(aux);
	rename("auxiliar.txt","t.txt");
	remove("auxiliar.txt");
	system("pause");
}
void alteracao(){
	system("cls");
	abrir_arq();
	int codigo,a=0;
	printf("Informe codigo a ser pesquisado: ");
	scanf("%d", &codigo);
	fseek(p,SEEK_SET,1);
	fread(&livro,sizeof(livro),1,p); 
	while(!feof(p)){
		if(livro.codigo==codigo){
			a++;
			printf("Informe novo codigo: ");
			scanf("%d", &livro.codigo);
			printf("Informe novo titulo: ");
			fflush(stdin);
			gets(livro.titulo);
			printf("Informe novo Assunto: ");
			fflush(stdin);
			gets(livro.assunto);
			printf("Informe novo Autor: ");
			fflush(stdin);
			gets(livro.autor);
			printf("Informe nova Editora: ");
			fflush(stdin);
			gets(livro.editora);
			printf("Informe novo Ano: ");
			fflush(stdin);
			scanf("%d", &livro.ano);
			
		}
		fwrite(&livro,sizeof(livro),1,aux);
		fread(&livro,sizeof(livro),1,p); 
	}
	if(a==0)printf("Livro nao encontrado\n");
	else printf("Livro alterado\n");
	fclose(p);
	remove("t.txt");
	fclose(aux);
	rename("auxiliar.txt","t.txt");
	remove("auxiliar.txt");
	system("pause");
}
void menu(){
	system("cls");
	int op;
	printf("1 = Cadastro\n");
	printf("2 = Consulta\n");
	printf("3 = Exclusão\n");
	printf("4 = Alteração\n");
	printf("0 = Sair\n");
	printf("Escolha uma opção: ");
	scanf("%d", &op);
	switch(op){
		case 1:cadastro();break;
		case 2:consulta();break;
		case 3:exclusao();break;
		case 4:alteracao();break;
		case 0:sair = true;break;
		default:printf("Opção Invalida\n");break;
	
		
	}
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	p = fopen("t.txt", "w+b");
	if(p == NULL){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}
	fclose(p);
	while(!sair){
		menu();
	}
	return 0;
}
