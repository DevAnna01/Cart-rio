#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria 
#include <locale.h> // biblioteca de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()//função de cadastro do usuario
{ //inicio da criação de variaveis
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variaveis
	
	printf("Digite o CPF a ser cadastrado\n\n\n"); //coletando informações do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf);//responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose (file); //fechar arquivo
	
	file = fopen(arquivo,"a"); //acessar arquivo
	fprintf(file,",");
	fclose(file); //fechar arquivo
	
	printf("Digite o nome a ser cadastrado\n\n\n"); //coletando informações do usuario
	scanf("%s",nome);//%s refere-se a string
	
		
	file = fopen(arquivo,"a"); //acessar arquivo
	fprintf(file,nome);
	fclose(file);//fechar arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado\n\n\n");//coletando informações do usuario
	scanf("%s",sobrenome); //refere-se a string
	

	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo:\n\n\n"); //coletando informações do usuario
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
	{ printf("*ERRO*\n\n CPF não encontrado, tente novamente\n\n");
	system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuario:\n");
		printf("%s",conteudo);
		printf("\n");
		system("pause");
	}
}



int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado:\n\n");
	printf("CPF:"); // espaço de interação
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("CPF NÃO CADASTRADO!\n");
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
	
	printf("### CARTÓRIO ###\n\n"); // inicio do menu
	printf("Escolha a opção desejada:\n\n");
	printf("\t 1- Registrar nomes\n");
	printf("\t 2- Consultar nomes\n");
	printf("\t 3- Excluir nomes\n\n\n\n"); 
	printf("opção:"); //fim do menu

	scanf("%d",&opcao); // armazenando a escolha do usuario
	
	system("cls"); //responsavel por limpar a tela
	
	switch(opcao) //inicio de seleção do menu
{
			case 1:
			registro();// chamada de função
			break;
			
		case 2:
			consulta(); //chamada de função
			break;
		
		case 3:
			deletar(); //chamada de função
			break;
			
			default:
				printf("Opção invalida\n");
				system("pause");
				break;
			} //fim da seleção
		}
	}
	
		
		
			
	

