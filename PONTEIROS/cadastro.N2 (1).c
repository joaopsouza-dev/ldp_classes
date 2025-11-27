#include <stdio.h>

#define MAX_ALUNOS 30

// STRUCTS //////// STRUCTS /////////////// STRUCTS /////////// STRUCTS /////// STRUCTS ////// STRUCTS ///////// STRUCTS ///////// STRUCTS //////// STRUCTS //////// STRUCTS //////// STRUCTS ///


typedef struct { // struct para definir os parametros dos alunos

    int matricula;
    char nome[50]; 
    float notas[3];
    float media;

} Alunos;


// FUNCOES //////// FUNCOES /////////////// FUNCOES /////////// FUNCOES /////// FUNCOES ////// FUNCOES///////// FUNCOES ///////// FUNCOES ////// FUNCOES ///////// FUNCOES //// FUNCOES ////////


void inicio() { // funcao so para exibir as mensagens iniciais e nao ocupar o main

    printf("====================================\n");
    printf("| BEM VINDO AO CADASTRO DE ALUNOS  |\n");
    printf("====================================\n\n");

}

void menu(int *opcoes) { // funcao para exibir o menu do sistema

    printf("\n\nFuncoes disponiveis:\n\n");
    printf("1. Cadastramento de alunos\n");
    printf("2. Listar alunos da sala\n");
    printf("3. Estatisticas da turma\n");
    printf("4. Buscar aluno por matricula\n");
    printf("5. Atualizar notas de um aluno\n");
    printf("6. Ordem decrescente de alunos\n");
    printf("7. Enderecos de memoria\n");
    printf("8. Sair do Sistema\n");

    printf("\nEscolha uma das opcoes disponiveis (1-8)\n");
    scanf("%d", opcoes);

}

void despedida () { // opcao 8
    printf("\n\nVoce esta saindo do nosso sistema! Ate mais e muito obrigado.\n\n");
}

void invalido () { // default
    printf("\n\nopcao invalida, escolha outra.\n\n");

}

void case1(Alunos *ptr_aluno, int *qtd_alunos, int *ptr_cad) {
    
    int i, j;
    

    printf("\nQuantos alunos voce deseja cadastrar?\n");
    scanf("%d", ptr_cad);

    for(i = *qtd_alunos; i < *ptr_cad + *qtd_alunos; i++) {
    	
    	float soma = 0;

        printf("\n\ndigite a matricula do aluno %d\n", i + 1);
        scanf("%d", &ptr_aluno[i].matricula);

        printf("\ndigite o nome do aluno %d\n", i + 1);
        scanf("%s", ptr_aluno[i].nome);

        printf("\ndigite a nota 1 do aluno %d\n", i + 1);
        scanf("%f", &ptr_aluno[i].notas[0]);

        printf("\ndigite a nota 2 do aluno %d\n", i + 1);
        scanf("%f", &ptr_aluno[i].notas[1]);

        printf("\ndigite a nota 3 do aluno %d\n", i + 1);
        scanf("%f", &ptr_aluno[i].notas[2]);

        for(j = 0; j < 3; j++) {
            soma += ptr_aluno[i].notas[j];
        }
        ptr_aluno[i].media = soma / 3.0;
    }
    
    *qtd_alunos += *ptr_cad;
}

void case2(Alunos *ptr_aluno, int *qtd_alunos) {

    int i;
    
    for(i=0;i<*qtd_alunos;i++) {
    	
        printf("\nAluno %d:\n", i+1);
        printf("Matricula: %d \n", ptr_aluno[i].matricula);
        printf("Nome: %s \n", ptr_aluno[i].nome);
        printf("Nota 1: %.1f \n", ptr_aluno[i].notas[0]);
        printf("Nota 2: %.1f \n", ptr_aluno[i].notas[1]);
        printf("Nota 3: %.1f \n", ptr_aluno[i].notas[2]);
        printf("Media do aluno: %.1f \n\n", ptr_aluno[i].media);
        
    }
}

void case3 (Alunos *ptr_aluno, int *qtd_alunos) {

    float media_turma = 0.0;
    int i;
	float aprovados = 0;
	int reprovados = 0;
	float acuracia;

    for(i = 0; i < *qtd_alunos; i++) {
    	
        media_turma += ptr_aluno[i].media;

        if(ptr_aluno[i].media >= 7.0) {
            aprovados++;
        } else {
            reprovados++;
        }
    }

    media_turma = media_turma / *qtd_alunos;
    acuracia = (aprovados / *qtd_alunos) * 100.0; 

    printf("\n///// estatisticas da sala /////\n\n");
    printf("Media geral da sala: %.2f\n", media_turma);
    printf("Total de alunos: %d\n", *qtd_alunos);
    printf("Total de alnos que foram aprovados: %.0f\n", aprovados);
    printf("Total de alunos reprovados: %d\n", reprovados);
    printf("Acuracia da turma: %.1f%%\n", acuracia);
}



int locale_aluno(Alunos *ptr_aluno, int *qtd_alunos) {

    int matricula, i;
    
    printf("\nDigite o numero da matricula:\n");
	scanf("%d", &matricula);

    for(i=0;i<*qtd_alunos;i++) {

        if(matricula == ptr_aluno[i].matricula) {

            printf("\nDados do aluno:\n");
            printf("Matricula: %d \n", ptr_aluno[i].matricula);
            printf("Nome: %s \n", ptr_aluno[i].nome);
            printf("Nota 1: %.1f \n", ptr_aluno[i].notas[0]);
            printf("Nota 2: %.1f \n", ptr_aluno[i].notas[1]);
            printf("Nota 3: %.1f \n", ptr_aluno[i].notas[2]);
            return i;
        } 
    }
    return -1;
}


void case4(Alunos *ptr_aluno, int *qtd_alunos) {

    int index_resultado = locale_aluno(ptr_aluno, qtd_alunos);
    if (index_resultado == -1){
    	printf("Nao existe aluno com essa matricula");    	
	}
}

void case5(Alunos *ptr_aluno, int *qtd_alunos) {

    int matricula, i, nota;

    printf("\nDigite a matricula do aluno que voce deseja atualizar a nota:\n");
    scanf("%d", &matricula);

    for(i = 0; i < *qtd_alunos; i++) {

        if(matricula == ptr_aluno[i].matricula) {

            printf("\nQual nota voce deseja alterar? (1, 2 ou 3)\n");
            scanf("%d", &nota);

            switch(nota) {

                case 1:
                    printf("atualize a nota 1 do aluno:\n");
                    scanf("%f", &ptr_aluno[i].notas[0]);
                    break;

                case 2:
                    printf("atualize a nota 2 do aluno:\n");
                    scanf("%f", &ptr_aluno[i].notas[1]);
                    break;

                case 3:
                    printf("atualize a nota 3 do aluno:\n");
                    scanf("%f", &ptr_aluno[i].notas[2]);
                    break;

                default:
                    printf("opcao invalida! digite novamente.\n");
                    break;
            }

            ptr_aluno[i].media = (ptr_aluno[i].notas[0] + ptr_aluno[i].notas[1] + ptr_aluno[i].notas[2]) / 3.0; 

            printf("\nMedia atualizada com sucesso!\n");
            printf("Nova media: %.2f\n", ptr_aluno[i].media);

            return;
        }
    }

    printf("\nMatricula nao encontrada.\n");
}

void case6 (Alunos *ptr_aluno, int *qtd_alunos) {

    int i, j;
    Alunos temporario;

    for(i=0;i<*qtd_alunos;i++) {
        for(j=i+1;j<*qtd_alunos;j++) {
            if(ptr_aluno[i].media < ptr_aluno[j].media) {
                temporario = ptr_aluno[i];
                ptr_aluno[i] = ptr_aluno[j];
                ptr_aluno[j] = temporario;
            }
        }
    }
    printf("\nordem dos alunos pela media (decrescente): \n\n");
    
    for(i = 0; i < *qtd_alunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Matricula: %d\n", ptr_aluno[i].matricula);
        printf("Nome: %s\n", ptr_aluno[i].nome);
        printf("Media: %.2f\n", ptr_aluno[i].media);
    }
}

void case7 (Alunos *ptr_aluno, int *qtd_alunos) {

    int i;
    
        printf("\nendereco da primeira matricula: %p\n", &ptr_aluno[0].matricula);
        printf("endereco do primeiro nome: %p\n", &ptr_aluno[0].nome);
        printf("endereco da primeira nota: %p\n", &ptr_aluno[0].notas[0]);
        printf("endereco da primeira media: %p\n\n", &ptr_aluno[0].media);

}



// MAIN //////// MAIN /////////////// MAIN /////////// MAIN /////// MAIN ////// MAIN///////// MAIN ///////// MAIN//////// MAIN //////// MAIN //////// MAIN ////// MAIN ////// MAIN /// MAIN ///


int main () {

	
    int opcoes, qtd_alunos = 0, cadastro, i, j, matricula, nota;
    int *ptr_cad = &cadastro;
    char resposta;

    Alunos aluno[MAX_ALUNOS];
    Alunos *ptr_aluno = aluno;


    inicio();


        do {

            menu(&opcoes);
            
            switch(opcoes) {

                case 1:
                case1(ptr_aluno, &qtd_alunos, ptr_cad);
                break;

                        case 2:
                        case2(ptr_aluno, &qtd_alunos);
                        break;

                case 3:
                case3(ptr_aluno, &qtd_alunos); 
                break;

                        case 4:
                        case4(ptr_aluno, &qtd_alunos);
                        break;

                case 5:
                	
                case5(ptr_aluno, &qtd_alunos);
                break;

                        case 6:
                        case6(ptr_aluno, &qtd_alunos);
                        break;
                        

                case 7:
            	case7(ptr_aluno, &qtd_alunos); 
				break;
                
                
                        case 8:
                        despedida();
                        break;

                default:
                invalido();
                break;

            }

        } while (opcoes != 8);

    
    return 0;
}
