#include <stdio.h>
#include <time.h>  
#include <stdlib.h>

// bom para vetores quase ordenados (faz poucas trocas)
// bom para organizar crescentemente
// ruim para transformar vetores quase crescentes para decrescentes e vice-versa

void mostraVet(int vetor[], int tamanhoVetor){
    int penultimo = tamanhoVetor-1;
    int i;
    printf("{");
    for(i=0; i < penultimo; i++){
        printf("%d; ", vetor[i]);
    }
    printf("%d}\n", vetor[penultimo]);

}

void insertionSort(int vetor[], unsigned tamanhoVetor){
    unsigned i = 1;
    int pivot;
    int j;
    while(i < tamanhoVetor){
        pivot = vetor[i];
        j = i -1;
        while((j>=0) && vetor[j] > pivot){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = pivot; 
        i++;  
    }
}

void randomizaVetor(int vetor[], unsigned tamanhoVetor, int limiteSuperior){
    //necessario incluir biblioteca <time.h> e <stdlib.h>
    srand(time(NULL));
    for(int x=0; x<tamanhoVetor; x++){
        vetor[x] =rand() % limiteSuperior;
    }
}

int main(){
    unsigned lenVet = 50;
    int vet[lenVet];

    randomizaVetor(vet, lenVet, 100);

    printf("Antes da ordenacao: ");
    mostraVet(vet, lenVet);

    insertionSort(vet, lenVet);
    printf("\nDepois da ordenacao: ");
    mostraVet(vet, lenVet);
}