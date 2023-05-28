#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct tipoAluno{
    char nome[30];
    char curso[30];
    char pibic; //verdadeiro ou falso
    float coeficienteRendimento;
}tipoAluno;

typedef struct tipoNo{
    tipoAluno dado; // informacao
    struct tipoNo *prox; //ponteiro pro proximo 
} tipoNo;

typedef struct tipoLista{
    tipoNo *prim; //ponteiro pro primeiro
}tipoLista;

void mostraAluno(tipoAluno *aluno){
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

void criaLista(tipoLista *lista){
    lista->prim = NULL; //aloca espaco p lista
}

void insereNoTopo(tipoLista *lista, tipoAluno *aluno){
    tipoNo *aux;
    aux = (tipoNo*) malloc (sizeof(tipoNo));
    aux->dado = *aluno;
    aux->prox = lista->prim;   
    lista->prim = aux;
}

int buscaElemento(tipoLista *lista, char *chave){
    tipoNo *aux;
    aux = lista->prim;
    while(aux != NULL){
        if(!strcmp(chave, aux->dado.nome)){//(*aux).dado.nome, [(strcmp(a,b) == 0)  == !strcmp(a,b)]
        return 1; 
        }
        aux = aux->prox;
    }
    return 0;
}
void mostraLista(tipoLista *lista){
    tipoNo *aux;
    aux = lista->prim;
    while(aux != NULL){
        //mostraAluno(aux->dado);
        aux = aux->prox;
    }
}

int main(){
    tipoLista l1;
    criaLista(&l1);

    tipoAluno pessoa;

    strcpy(pessoa.nome, "Matheus");
    strcpy(pessoa.curso, "Ciencia da Computacao");
    pessoa.pibic = 1;
    pessoa.coeficienteRendimento = 8.0;
    insereNoTopo(&l1, &pessoa);

    strcpy(pessoa.nome, "Ana");
    strcpy(pessoa.curso, "Engenharia da Computacao");
    pessoa.pibic = 0;
    pessoa.coeficienteRendimento = 9.45;
    insereNoTopo(&l1, &pessoa);

    strcpy(pessoa.nome, "Lina");
    strcpy(pessoa.curso, "Sistema de Informacao");
    pessoa.pibic = 1;
    pessoa.coeficienteRendimento = 7.48;
    insereNoTopo(&l1, &pessoa);


    mostraLista(&l1);

    



}