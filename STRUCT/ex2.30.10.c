#include <stdio.h>
#include <stdlib.h>

typedef struct { 

	int codigo;
	char nome[40];
	int estoque;
	float preco_uni;
	
} Produto;

int main () {
	
	Produto produtos[5] = {
		
	{110, "monitor", 10, 549.90},
	{112, "teclado", 50, 149.90},
	{113, "notebook", 10, 3999.90},
	{114, "mousepad", 25, 49.90},
	{115, "headset", 30, 249.50}
	
	};
	

	return 0;
}
