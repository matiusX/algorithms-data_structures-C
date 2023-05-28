#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// SO pra manter o costume de colocar os dados da pilha com tipoDados
// aqui tipoDados vai ser mesma coisa que int

typedef int tipoDados;


typedef struct tipoNo {
  tipoDados d;
  struct tipoNo *prox;
} tipoNo;

typedef struct tipoPilha {
  tipoNo *topo;
} tipoPilha;



void mostraPilha(tipoPilha *pPilha) {
  tipoNo *aux;

  aux = pPilha->topo;

  while(aux) {
    printf("%d\n",aux->d);
    aux = aux->prox;
  }
}




void criaPilha(tipoPilha *pPilha) {
  pPilha->topo = NULL;
}


/*  Remove 1o elemento da lista

assume que há pelo menos 1 elemento e dá erro se lista estiver vazia */

void removeDaPilha(tipoPilha *pPilha, tipoDados *res) {
  tipoNo *tmp;
  tmp = pPilha->topo;
  pPilha->topo = tmp->prox;
  *res = tmp->d;
  free(tmp);
}


void lerValores(int v[], int tam) {
  
  for(int x =0; x< tam; x++) {
    scanf("%d%*c",&v[x]);
  }
}


// AQUI SUA FUNCAO QUE TRANSFERE. NAO ALTERE OUTRAS PARTES DO CODIGO!!!!
void transfere(int vetor[], int tamanho, tipoPilha *pilha){
    tipoNo *aux;

    for(int i=0; i<tamanho; i++){
        aux = (tipoNo *) malloc (sizeof(tipoNo));
        aux->d = vetor[i];
        aux->prox = pilha->topo;
        pilha->topo = aux;
    }

}

// FIM

int main() {
  tipoPilha l1;
  int *v;
  int tam;

  criaPilha(&l1);
  scanf("%d%*c",&tam);
  v = (int*)malloc (sizeof(int)*tam);
  lerValores(v,tam);
  transfere(v, tam, &l1); // CHAMADA PARA A SUA FUNCAO
  free(v);
  mostraPilha(&l1);
}