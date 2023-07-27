#include <stdio.h>    //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>	  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>   //biblioteca para aloca��o de texto por regi�o
#include <string.h>   //biblioteca responsavel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os clientes no sistema
{
setlocale(LC_ALL,"portuguese");

	//inicio da cria��o das vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis
	
	printf("Digite o cpf a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s",cpf);			 //"%s"refere-se a string
	strcpy(arquivo, cpf);		 //respons�vel por copiar dados de uma v�ri�vel para outra. 

	FILE *file;					// cria aquivo
	file = fopen(arquivo,"w");	//cria arquivo "(W)rite the data"
	fprintf(file,cpf);			//salva valor da vari�vel
	fclose(file); 				//fecha arquivo	
	
	file = fopen(arquivo,"a"); //cria arquivo ("A"ppends the data")
	fprintf(file,",");		   //insere a informa��o 
	fclose(file);              //encerra a cria��o de arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}
int consulta() //func��o respons�vel por consultar os clientes cadastrados no sistema
{
setlocale(LC_ALL,"portuguese");

	char cpf[40];//in�cio das vari�veis 
	char conteudo[200];//final das vari�veis
	
	printf("Digite o o CPF a ser consultado: ");//coleta informa��o do usu�rio
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o CPF.\n");
		system("pause");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
		system("pause");
	}
}

int deletar() //fun��o respons�vel por deletar clientes do sistema
{
	char cpf[40]; //cira��o da vari�vel
	
	printf("Qual CPF a ser deletado: ");//coleta de dados do usu�rio
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//abre o aquivo ("R"ead the data)
	fclose(file);
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado no sistema.\n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	 system("cls");//responsavel por limpar a tela
		
		
	setlocale(LC_ALL,"portuguese");//definindo linguagem
	
	
	printf("\t### CART�RIO DA EBAC ###\n\n");//inicio menu
	printf("Escolha a op��o desejada no menu: \n\n");
	
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Op��o: ");
	scanf("%d",&opcao);//final menu
	
	system("cls");
	
	switch(opcao)//inicio da sele��o do menu
	{
		case 1:
		registro();//chamada de fun��es 
		break;
		
		case 2:
		consulta();//chamada de fun��es 
		break;
		
		case 3: 
		deletar();//chamada de fun��es 
		break;
		
		default:
		printf("Essa op��o n�o est� dispon�vel\n");
		system("pause");
		break;
	}
}
}
	

