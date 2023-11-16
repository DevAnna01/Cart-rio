#include <stdio.h> // biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria 
#include <locale.h> // biblioteca de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()//fun��o de cadastro do usuario
{ //inicio da cria��o de variaveis
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado\n\n\n"); //coletando informa��es do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf);//responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose (file); //fechar arquivo
	
	file = fopen(arquivo,"a"); //acessar arquivo
	fprintf(file,",");
	fclose(file); //fechar arquivo
	
	printf("Digite o nome a ser cadastrado\n\n\n"); //coletando informa��es do usuario
	scanf("%s",nome);//%s refere-se a string
	
		
	file = fopen(arquivo,"a"); //acessar arquivo
	fprintf(file,nome);
	fclose(file);//fechar arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado\n\n\n");//coletando informa��es do usuario
	scanf("%s",sobrenome); //refere-se a string
	

	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo:\n\n\n"); //coletando informa��es do usuario
	scanf("%s",cargo); //%s refere-se a string
	

	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
}


int consulta()
{
	setlocale(LC_ALL, "PORTUGUESE"); //Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:\n\n");
	scanf("%s",cpf);
	
	FILE *file;
	file =fopen(cpf,"r");
	
	
	if(file == NULL)
	{ printf("*ERRO*\n\n CPF n�o encontrado, tente novamente\n\n");
	system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas s�o as informa��es do usuario:\n");
		printf("%s",conteudo);
		printf("\n");
		system("pause");
	}
}



int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado:\n\n");
	printf("CPF:"); // espa�o de intera��o
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("CPF N�O CADASTRADO!\n");
		system("pause");
}
}

int main()
{
	int opcao=0; //Definindo variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	system("cls"); //responsavel por limpar a tela
	
	setlocale(LC_ALL,"PORTUGUESE"); //Definindo idioma
	
	printf("### CART�RIO ###\n\n"); // inicio do menu
	printf("Escolha a op��o desejada:\n\n");
	printf("\t 1- Registrar nomes\n");
	printf("\t 2- Consultar nomes\n");
	printf("\t 3- Excluir nomes\n\n\n\n"); 
	printf("op��o:"); //fim do menu

	scanf("%d",&opcao); // armazenando a escolha do usuario
	
	system("cls"); //responsavel por limpar a tela
	
	switch(opcao) //inicio de sele��o do menu
{
			case 1:
			registro();// chamada de fun��o
			break;
			
		case 2:
			consulta(); //chamada de fun��o
			break;
		
		case 3:
			deletar(); //chamada de fun��o
			break;
			
			default:
				printf("Op��o invalida\n");
				system("pause");
				break;
			} //fim da sele��o
		}
	}
	
		
		
			
	

