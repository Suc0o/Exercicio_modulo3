#include <stdio.h>
#include <string.h>

typedef struct DadosAluno{
	char nome[50];
	int matricula;
	float nota1, nota2;
	float media;
}DadosAluno;

void limp(){
	
	char c;
	
	while((c = getchar()) != '\n' && c != EOF);
}

float media(float n1, float n2){
	
	return (n1 + n2) / 2;
}

int main(){
	
	int qntd;
	
	printf("Digite a quantidade de alunos: ");
	scanf("%d", &qntd);
	 limp();

	
	DadosAluno aluno[qntd], alfa[qntd], num[qntd], aux;

	
	for(int i = 0; i < qntd; i++){
		
		printf("\nDigite o nome do %d aluno: ", i+1);
		fgets(aluno[i].nome, 50, stdin);

		limp();
		
		printf("Digite a matricula do %d aluno: ", i+1);
		scanf("%d", &aluno[i].matricula);
		
		limp();
		
		printf("Digite a primeira nota do %d aluno: ", i+1);
		scanf("%f", &aluno[i].nota1);
		
		limp();
		
		printf("Digite a segunda nota do %d aluno: ", i+1);
		scanf("%f", &aluno[i].nota2);
		
		limp();
		
		aluno[i].media	= media(aluno[i].nota1, aluno[i].nota2);
	}	
	
	printf("------Lista de alunos inserida------\n\n");
	
	for(int i = 0; i < qntd; i++){
		printf("\nAluno: %s\n", aluno[i].nome);
		printf("Matricula: %d\n", aluno[i].matricula);
		printf("Nota 1: %.2f\n", aluno[i].nota1);
		printf("Nota 2: %.2f\n", aluno[i].nota2);
		printf("Media: %.2f\n", aluno[i].media);
	}
	
	for(int i = 0; i < qntd; i++){
	
	alfa[i] = aluno[i];   
	
    }
	
	for(int i = 0; i < qntd; i++){
		for(int j = i + 1; j < qntd; j++){
			if(strcmp(alfa[i].nome, alfa[j].nome) > 0){
				aux = alfa[j];
				alfa[j] = alfa[i];
				alfa[i] = aux;
			}
		}
	}
	
		for(int i = 0; i < qntd; i++){
	
	num[i] = aluno[i];   
	
    }
	
	for(int i = 1; i < qntd; i++){
		
		DadosAluno p = num[i];
		int c = i - 1;
		
		while(i >= 0 && num[c].media > p.media){
			num[c + 1] = num[c];
			c -= 1;
			num[c + 1] = p;
		}
	}
	
	
	printf("------Lista de alunos em ordem alfabetica------\n\n");
	
for(int i = 0; i < qntd; i++){
		printf("\nAluno: %s\n", alfa[i].nome);
		printf("Matricula: %d\n", alfa[i].matricula);
		printf("Nota 1: %.2f\n", alfa[i].nota1);
		printf("Nota 2: %.2f\n", alfa[i].nota2);
		printf("Media: %.2f\n", alfa[i].media);
	}
	
		printf("------Lista de alunos em ordem de media------\n\n");
	
	for(int i = 0; i < qntd; i++){
		printf("\nAluno: %s\n", num[i].nome);
		printf("Matricula: %d\n", num[i].matricula);
		printf("Nota 1: %.2f\n", num[i].nota1);
		printf("Nota 2: %.2f\n", num[i].nota2);
		printf("Media: %.2f\n", num[i].media);
	}
	
	
	

	
	return 0;
	
}
