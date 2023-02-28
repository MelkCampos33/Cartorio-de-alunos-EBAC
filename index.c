#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // aloca��o de espa�o na mem�ria
#include <locale.h> // aloca��o de texto por regi�o
#include <string.h> // Responsavel pelas Strings

int registerUser() 
{
	char archive[40];
	char cpf[40];
	char name[40];
	char surname[40];
	char position [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	// Copiar o valor de "CPF" para a variavel "FILE"
	strcpy(archive, cpf);
	
	// Criando "FILE" bunscando dentro da biblioteca
	FILE *file;
	
	file = fopen(archive, "w"); // w = write 
	fprintf(file, cpf); // Salvando o valor de CPF em FILE
	fclose(file);
	
	// separando cada char quando for mostrado ao usu�rio na frase
	file = fopen(archive, "a"); // "a" = atualiza��o
	fprintf(file, ",");
	fclose(file);
	
	
	// nome
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", name);
	
	file = fopen(archive, "a");
	fprintf(file, name);
	fclose(file);
	
	file = fopen(archive, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	// sobrenome
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", surname);
	
	file = fopen(archive, "a");
	fprintf(file, surname);
	fclose(file);
	
	
	file = fopen(archive, "a");
	fprintf(file, ",");
	fclose(file);
	
	// cargo
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", position);
	
	file = fopen(archive, "a");
	fprintf(file, position);
	fclose(file);

	system("pause");
}


int consultUser() 
{
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char userContent[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" = read

	
	// Validando se o CPF existe
	if(file == NULL) {
		
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(userContent, 200, file) != NULL) // conteudo diferente de nulo
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", userContent);

		printf("\n\n");
	}
	
	system("pause");
}

int deleteUser() 
{
	char cpf[40];
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // lendo o cpf
	
	if(file == NULL)
	{
		printf("Usu�rio excluido com sucesso!\n");
		printf("O usu�rio n�o se encontra mais no sistema!\n");
		system("pause");
	}
	
}

int main() 
{
	int option = 0;
	int updateMenu = 1;
	
	for(updateMenu = 1; updateMenu = 1;){
		
		system("cls");
		setlocale(LC_ALL, "Portuguese");
		
		// Inicio do MENU
		printf("### Cart�rio da EBAC ###\n\n\n");
		printf("\tEscolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n");
		printf("\t4 - Sair do Sistema\n\n\n");
		printf("Digite sua op��o: ");
		// printf("\tEsse Software � de livre uso\n\tCriado por: Melquisedeque F. Campos");
		
		scanf("%d", &option); // scanf armazena a resposta do usu�rio
		
		
		system("cls"); // limpar tela
		
		
		switch(option)
		{
			// Registro
			case 1:
				registerUser();
				break;
			
			// Consulta
			case 2:
				consultUser();
				break;
			
			// Deletar
			case 3:
				deleteUser();
				break;
			
			case 4:
				printf("Obrigado por ultilizar nosso sistema!");
				return 0; // quebrando o sistema
				break;
			
			// Verificando op��es do Menu
			default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;
		}
	}
}	
