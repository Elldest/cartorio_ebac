#include <stdio.h>    //biblioteca de comunicação com o usuário
#include <stdlib.h>	  //biblioteca de alocação de espaço em memória
#include <locale.h>   //biblioteca para alocação de texto por região
#include <string.h>   //biblioteca responsavel por cuidar das strings

int registro() //função responsável por cadastrar os clientes no sistema
{
setlocale(LC_ALL,"portuguese");

	//inicio da criação das variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis
	
	printf("Digite o cpf a ser cadastrado: ");//coletando informações do usuário
	scanf("%s",cpf);			 //"%s"refere-se a string
	strcpy(arquivo, cpf);		 //responsável por copiar dados de uma váriável para outra. 

	FILE *file;					// cria aquivo
	file = fopen(arquivo,"w");	//cria arquivo "(W)rite the data"
	fprintf(file,cpf);			//salva valor da variável
	fclose(file); 				//fecha arquivo	
	
	file = fopen(arquivo,"a"); //cria arquivo ("A"ppends the data")
	fprintf(file,",");		   //insere a informação 
	fclose(file);              //encerra a criação de arquivo
	
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
int consulta() //funcção responsável por consultar os clientes cadastrados no sistema
{
setlocale(LC_ALL,"portuguese");

	char cpf[40];//início das variáveis 
	char conteudo[200];//final das variáveis
	
	printf("Digite o o CPF a ser consultado: ");//coleta informação do usuário
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível localizar o CPF.\n");
		system("pause");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
		system("pause");
	}
}

int deletar() //função responsável por deletar clientes do sistema
{
	char cpf[40]; //ciração da variável
	
	printf("Qual CPF a ser deletado: ");//coleta de dados do usuário
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//abre o aquivo ("R"ead the data)
	fclose(file);
	
	if(file == NULL)
	{
		printf("Usuário não encontrado no sistema.\n");
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
	
	
	printf("\t### CARTÓRIO DA EBAC ###\n\n");//inicio menu
	printf("Escolha a opção desejada no menu: \n\n");
	
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Opção: ");
	scanf("%d",&opcao);//final menu
	
	system("cls");
	
	switch(opcao)//inicio da seleção do menu
	{
		case 1:
		registro();//chamada de funções 
		break;
		
		case 2:
		consulta();//chamada de funções 
		break;
		
		case 3: 
		deletar();//chamada de funções 
		break;
		
		default:
		printf("Essa opção não está disponível\n");
		system("pause");
		break;
	}
}
}
	

