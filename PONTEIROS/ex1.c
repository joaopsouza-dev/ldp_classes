#include <stdio.h>
#include <stdlib.h>

void incrementa (int *ponteiro) { //ex 4
	*ponteiro += 1;
}

void troca (char *a, char *b) { //ex 5
	
	char trocar;
	
	trocar = *a;
	*a = *b;
	*b = trocar;
	
}

void dobrar(float *ptr) { // ex 6
	*ptr += *ptr;
}

void MaiorMenor(int *a, int *b, int *maior, int *menor) { //ex 7
	
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

int soma(int *vetor, int *somar) { //ex 8
		
		int i;
		
		for(i=0;i<5;i++) {
			*somar += *(vetor + i);
		}
		
		return *somar;
}

void copiar(int *orig, int *dest, int n) { //ex 10
	
	int i;
		
		for(i=0;i<n;i++) {
			*(dest + i) =  *(orig + i);
		}
}

int contaCaracteres(const char *s) { //ex 11
	
	int ntotal = 0 ;
	
	 
	while (*s != '\0'){
		
		ntotal++;
		s++;
	} 

	return ntotal;
}

void ex12(char *s) { //ex 12
	
	int i;
		
		for(i=0;i<34;i++) {
			printf("o caractere %c esta na posicao %d\n", *(s + i),i);
		}
}

int comparar(const char *a, const char *b) { //ex 13
	
	
	
}

int main () { ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// EXERCICIO 1
	
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
	
	// EXERCICIO 2
	
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
	int *ptr_soma = vetor_soma;
	
	soma(ptr_soma, &total);
	printf("o valor total da soma e: %d", total);
	
	// EXERCICIO 9
	
	printf("\n\n\nEXERCICIO 9 PODEMOS PULAR\n\n");
	
	// EXERCICIO 10
	
	printf("\n\n\nEXERCICIO 10\n\n");
	
	char origem[9] = "Guilherme";
	char destino[9];
	
	copiar(origem, destino, 9);
	printf("o resultado e: ");
	
	for(i=0;i<9;i++) {
			printf("%c", destino[i]);
	}
		
	// EXERCICIO 11
	
	printf("\n\n\nEXERCICIO 11\n\n");
	
	char frase[] = "To com muita fome mlk";

	contaCaracteres(&frase);
	
	printf("resultado: %d", contaCaracteres(frase));
	
	// EXERCICIO 12
	
	printf("\n\n\nEXERCICIO 12\n\n");
	
	char frase2[100] = "nao_consigo_criar_nome_de_variavel";
	
	ex12(&frase2);
	
	// EXERCICIO 13
	
	printf("\n\n\nEXERCICIO 13\n\n");
	
	char acabapfv[4] = "amor";
	char insuportavel[4] = "anom";
	
	
	
	return 0;
}


