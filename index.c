#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // aloca��o de espa�o na mem�ria
#include <locale.h> // aloca��o de texto por regi�o

int main() 
{
	setlocale(LC_ALL, "Portuguese");
	printf("### Cart�rio da EBAC ###\n\n\n");
	printf("\tEscolha a op��o desejada no menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n\n");
	
	printf("\tEsse Software � de livre uso\n\tCriado por: Melquisedeque F. Campos");
}	
