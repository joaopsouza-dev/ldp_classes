#include <stdio.h>
#include <stdlib.h>

void incrementa (int *ponteiro) {
	*ponteiro += 1;
}

void troca (char *a, char *b) {
	
	char trocar;
	
	trocar = *a;
	*a = *b;
	*b = trocar;
	
}

void dobrar(float *ptr) {
	*ptr += *ptr;
}

void MaiorMenor(int *a, int *b, int *maior, int *menor) {
	
	if(*a > *b) {
		*maior = *a;
		*menor = *b;
	}
	
	else {
		*maior = *b;
		*menor = *a;
	}

	
	printf("maior: %d", *maior);
	printf("\nmenor: %d", *menor);
	
	
}

int soma(int *vetor[], int tamanho) {
		
		int i;
		int somar = 0;
		
		for(i=0;i<tamanho;i++) {
			somar += *vetor++;
		}
		
		return somar;
	}
	
int *maiorElemento(int *v, int n) {
	
}


int main () {
	
	// EXERCÍCIO 1
	
	int idade = 18;
	char letra = 'j';
	float nota = 7.65;
	
	int *ptr1 = &idade;
	char *ptr2 = &letra;
	float *ptr3 = &nota;
	
	printf("EXERCICIO 1\n\n");
	printf("variavel int: %p\n\n", ptr1);
	printf("variavel char: %p\n\n", ptr2);
	printf("variavel float: %p", ptr3);
	
	// EXERCÍCIO 2
	
	printf("\n\n\nEXERCICIO 2\n\n");
	
	int random = 10;
	int *ptr = &random;
	
	printf("antes: %d", random);
	
	*ptr = 20;
	
	printf("\ndepois: %d", random);
	
	// EXERCICIO 3
	
	printf("\n\n\nEXERCICIO 3\n\n");
	
	int mds = 25;
	int *ptr_mds = &mds;
	
	incrementa(ptr_mds);
	printf("Valor depois do incremento: %d", *ptr_mds);
	
	// EXERCICIO 4
	
	printf("\n\n\nEXERCICIO 4\n\n");
	
	char trocar1 = 'a';
	char trocar2 = 'z';
	
	char *ptr_trocar1 = &trocar1;
	char *ptr_trocar2 = &trocar2;
	
	printf("antes: %c e %c", *ptr_trocar1, *ptr_trocar2);
	
	troca(ptr_trocar1, ptr_trocar2);
	printf("\ndepois: %c e %c", *ptr_trocar1, *ptr_trocar2);
	
	// EXERCICIO 5
	
	printf("\n\n\nEXERCICIO 5\n\n");
	
	float num = 3.5;
	
	dobrar(&num);
	printf("valor dobrado: %.2f", num);
	
	// EXERCICIO 6
	
	printf("\n\n\nEXERCICIO 6\n\n");
	
	int num1 = 10, num2 = 15;
	int maior, menor;
	
	MaiorMenor(&num1, &num2, &maior, &menor);
	
	// EXERCICIO 7
	
	printf("\n\n\nEXERCICIO 7\n\n");
	
	int vetor[5] = {1,2,3,4,5};
	int *ptr_vetor = vetor;
	int i;
	
	for(i=0;i<5;i++) {
		printf("posicao %d: %d\n", i, *ptr_vetor++);
	}
	
	// EXERCICIO 8
	
	printf("\n\n\nEXERCICIO 8\n\n");
	
	int vetor_soma[5] = {10, 20, 30, 40, 50};
	int total;
	
	total = soma(vetor_soma, 5);
	printf("o valor total da soma e: %d", total);
	
	// EXERCICIO 9
	
	printf("\n\n\nEXERCICIO 9\n\n");
	
	
	
	
	
	
	return 0;
}


