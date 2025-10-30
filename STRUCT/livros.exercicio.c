#include <stdio.h>
#include <stdlib.h>

typedef struct { 

	char titulo[50];
	char autor[50];
	int ano_pub;
	float preco;
	
} Livro;

int main () {
	
	Livro livro1;
	float desconto;
	
	printf("==================================");
	printf("\n\nBEM VINDO AO SISTEMA DE LIVROS\n");
	printf("\n===================================\n\n\n");
	
	printf("Digite o titulo do livro:\n");
	scanf(" %s", &livro1.titulo);
	
	printf("\nDigite o nome do autor:\n");
	scanf(" %s", &livro1.autor);
	
	printf("\nDigite o ano de publicacao do livro:\n");
	scanf("%d", &livro1.ano_pub);
	
	printf("\nDigite o preco do livro:\n");
	scanf("%f", &livro1.preco);
	
	desconto = livro1.preco * 0.85;
	
	printf("\n\nDADOS DO LIVRO");
	
	printf("\n\nTitulo: %s", livro1.titulo);
	printf("\nNome do autor: %s", livro1.autor);
	printf("\nAno de publicacao do livro: %d", livro1.ano_pub);
	printf("\nPreco do livro: %.2f", livro1.preco);
	
	printf("\n\nO PRECO COM DESCONTO E: %.2f", desconto);
	
	return 0;
}
