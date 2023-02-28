#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // alocação de espaço na memória
#include <locale.h> // alocação de texto por região
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
	
	// separando cada char quando for mostrado ao usuário na frase
	file = fopen(archive, "a"); // "a" = atualização
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
		
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(userContent, 200, file) != NULL) // conteudo diferente de nulo
	{
		printf("\n Essas são as informações do usuário: ");
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
		printf("Usuário excluido com sucesso!\n");
		printf("O usuário não se encontra mais no sistema!\n");
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
		printf("### Cartório da EBAC ###\n\n\n");
		printf("\tEscolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n");
		printf("\t4 - Sair do Sistema\n\n\n");
		printf("Digite sua opção: ");
		// printf("\tEsse Software é de livre uso\n\tCriado por: Melquisedeque F. Campos");
		
		scanf("%d", &option); // scanf armazena a resposta do usuário
		
		
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
			
			// Verificando opções do Menu
			default:
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
		}
	}
}	
