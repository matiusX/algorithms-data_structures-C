#include <stdio.h>
void mostraVet(int vetor[], int tamanhoVetor){
    int penultimo = tamanhoVetor-1;
    int i;
    printf("{");
    for(i=0; i < penultimo; i++){
        printf("%d; ", vetor[i]);
    }
    printf("%d}\n", vetor[penultimo]);

}

void quickSort(int vet[], int primeiraPosicao, int ultimaPosicao){
    int i, j;
    int pivot, temp;
    
    i = primeiraPosicao;
    j = ultimaPosicao;

    int elementoPivot = (primeiraPosicao + ultimaPosicao)/2;
    pivot = vet[elementoPivot];    

    while(i<=j){
        while(vet[i] < pivot) i++;
        while(vet[j] > pivot) j--;
        
        if(i<=j){
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
            i++;
            j--;
        }
    }
    quickSort(vet, primeiraPosicao, j);
    quickSort(vet, i, ultimaPosicao);
}



int main(){
    int len = 8;
    int vet[8] = {7,8,400,450,200,600,500,1000};
    
    printf("Antes da ordenacao: ");
    mostraVet(vet, len);

    quickSort(vet, 0, 8);

    printf("Depois da ordenacao: ");
    mostraVet(vet, len);
}