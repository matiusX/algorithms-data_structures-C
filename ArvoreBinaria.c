#include <stdio.h>

struct tipoNo{
    int dado;
    tipoNo* noEsquerda;
    tipoNo* noDireita;
    tipoNo* noPai;
}typedef tipoNo;

struct tipoArvore{
    tipoNo* raiz;
    int tamanho;
}typedef tipoArvore;

void criaArvore(tipoArvore* arvore){
    arvore->tamanho = 0;
    arvore->raiz = NULL; 
}

void criaNo(tipoNo* no){
    no->dado = NULL;
    no->noDireita = NULL;
    no->noEsquerda = NULL;
    no->noPai = NULL;
}


int main(){
    tipoArvore a1;
    criaArvore(&a1);
    return 0;
}