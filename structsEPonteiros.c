#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct tipoAluno{
    char nome[30];
    char pibic; //verdadeiro ou falso
    char curso[30];
    float coeficienteRendimento;
}tipoAluno; //50 bits

void mostraStruct(tipoAluno *aluno){
    printf("---------------------\n");
    printf("Nome: %s\n", aluno->nome); // aluno->nome eh a msm coisa que (*aluno).nome
    printf("curso: %s\n", aluno->curso);
    printf("Coeficiente: %2.f\n", aluno->coeficienteRendimento);
    
    if(aluno->pibic == 1){
        printf("Eh aluno de pibic\n");
    }else{
        printf("Nao eh aluno de pibic\n");
    }
}

void mostrandoPonteiros(int x){
    printf("valor de x: %d", x);
}


int main(){
    tipoAluno aluno;
    


    tipoAluno *p = (tipoAluno*) malloc ( sizeof (tipoAluno));

    strcpy(aluno.nome, "Fernando");
    strcpy(aluno.curso, "Ciencia da computacao");
    aluno.coeficienteRendimento = 8.0;
    aluno.pibic = 1;


    strcpy(p->nome, "Carlos");
    strcpy(p->curso, "Engenharia de software");
    p->coeficienteRendimento = 7.15;
    p->pibic = 0; //(*p).pibic

    mostraStruct(&aluno);
    mostraStruct(p);
}