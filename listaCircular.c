#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoDados {
  char nome[30];
  int id;
} tipoDados;


typedef struct tipoNo {
  tipoDados dado;
  struct tipoNo *prox;
} tipoNo;

typedef struct tipoListaCircular {
  tipoNo *atual;
} tipoListaCircular;


void mostraDado(tipoDados d) {
  printf("%s\n",d.nome);
  printf("%d\n",d.id);
}

void mostraListaCircular(tipoListaCircular *pLista) {
  tipoNo *aux;

  if( pLista->atual) {
    aux = pLista->atual;   
    do {
      mostraDado( aux->dado );
      aux = aux -> prox;
    } while(aux != pLista->atual);
  }
}

int removeDaListaCircular(tipoListaCircular *pLista, char *nome) {
  tipoNo *aux, *seguinte;
  if( pLista->atual) {
    aux = pLista->atual;
    seguinte = aux->prox;
    while(seguinte != pLista->atual) {
      if(!strcmp(seguinte->dado.nome, nome)) {
	aux->prox = seguinte->prox;
	free(seguinte);
	return 1;
      }
      aux = seguinte; 
      seguinte = seguinte -> prox;
    }
    if(!strcmp(seguinte->dado.nome, nome)) {
      if(aux == seguinte) {
	pLista->atual = NULL;
      }
      else {
	aux->prox = seguinte->prox;
	pLista->atual = seguinte->prox;
      }
	free(seguinte);
	return 1;
    }
  }
  return 0;
}





void proximoDaVez(tipoListaCircular *pLista) {
  if(pLista->atual) {
    pLista->atual = pLista->atual->prox;
  }
}

void insereNaListaCircular(tipoListaCircular *pLista, tipoDados *d) {

  tipoNo *aux;
  aux = (tipoNo *) malloc (sizeof(tipoNo) );
  aux->dado = *d;
  if(pLista->atual) {
    aux->prox = pLista->atual->prox;
    pLista->atual->prox = aux;
  }
  else {
    pLista->atual = aux;
    aux->prox = aux;
  }
}



void criaListaCircular(tipoListaCircular *pLista) {
  pLista->atual = NULL;
}



/// FACA SUA FUNCAO AQUI
// NAO ALTERE NADA ANTES DESTE TRECHO
int contaK(tipoListaCircular *pLista, int k) {
    tipoNo *aux;
    int count = 0;
    if( pLista->atual) {
        aux = pLista->atual;   
        do {
        if(aux->dado.id == k){
            count++;
        }
        aux = aux -> prox;
        } while(aux != pLista->atual);
    }
    return count;
}

// FIM DA SUA FUNCAO
// NAO ALETERE NADA A SEGUIR!


int main() {
  tipoDados d;
  tipoListaCircular l1;
  tipoDados *p;
  int k;
  criaListaCircular(&l1);
  
  for(int x = 0; x< 10; x++) {
    scanf("%[^\n]%*c",d.nome);
    scanf("%d%*c",&d.id);
    insereNaListaCircular(&l1,&d);
  }

   scanf("%d%*c",&k);
   printf("%d\n", contaK(&l1,k) );
}
