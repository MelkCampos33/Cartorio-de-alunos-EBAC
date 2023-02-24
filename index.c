#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // alocação de espaço na memória
#include <locale.h> // alocação de texto por região

int main() 
{
	setlocale(LC_ALL, "Portuguese");
	printf("### Cartório da EBAC ###\n\n\n");
	printf("\tEscolha a opção desejada no menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n\n");
	
	printf("\tEsse Software é de livre uso\n\tCriado por: Melquisedeque F. Campos");
}	
