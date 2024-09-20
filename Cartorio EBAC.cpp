#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoria 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
			
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
			
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
			
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria arquivo
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
			
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
			
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
		
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
			
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
			
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
		
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
			
}	

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
	{
	int opcao=0; //Definindo Variaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		system ("cls");
		for(laco=1;laco=1;)
		{
	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cartótio EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n\n");
			printf("\t4 - Sair do Sistema\n\n");
			printf("Opção: "); //Fim do menu
		
			scanf("%d", &opcao); //armazenando a escolha do usúario
	
			system("cls");
		
			switch(opcao)
			{
				case 1:
				registro();
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa opcao não esta disponivel!\n");
				system("pause");
				break;
			}	
		}
	}
	
	else
		printf("Senha incorreta!");
	
}
