#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { 
    char nome[20];
    char endereco[40];
    int id;
} tipoDado;

void mergeSort(tipoDado vetor[], tipoDado auxiliar[], unsigned inicio, unsigned fim){
    unsigned meio;
    unsigned i,j,k;
    if(inicio < fim){
        meio = (inicio +fim)/2;
        mergeSort(vetor, auxiliar, inicio, meio);
        mergeSort(vetor, auxiliar, meio+1, fim);

        i=inicio;
        k = inicio;
        j=meio+1;

        while((i <= meio) && (j <= fim)){
            if(strcmp(vetor[i].nome, vetor[j].nome) > 0){auxiliar[k] = vetor[i]; i++;}
            else                   {auxiliar[k] = vetor[j]; j++;}
            k++;
        }
        while(i<=meio){auxiliar[k] = vetor[i]; i++; k++;}
        while(j<=fim ){auxiliar[k] = vetor[j]; j++; k++;}
        for(k = inicio; k <= fim; k++){
            vetor[k] = auxiliar[k];
        }
    }
}

void leDados(tipoDado vetor[], int tamanho){
    for(int i=0; i<tamanho; i++){
        scanf("%[^\n]%*c", vetor[i].nome);
        scanf("%[^\n]%*c", vetor[i].endereco);
        scanf("%d%*c", &vetor[i].id);
    }
}

void mostraVetor(tipoDado vetor[], int tamanho){
    for(int i=0; i<tamanho; i++){
        printf("%s\n",vetor[i].nome);
        printf("%s\n",vetor[i].endereco);
        printf("%d\n",vetor[i].id);
    }
}


int main(){
    int tamanho;
    scanf("%d%*c", &tamanho);
    tipoDado vetor[tamanho];
    tipoDado vetorAuxiliar[tamanho];

    leDados(vetor, tamanho);
    mergeSort(vetor, vetorAuxiliar, 0, tamanho-1);
    mostraVetor(vetor, tamanho);
}