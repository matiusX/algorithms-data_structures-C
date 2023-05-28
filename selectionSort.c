#include <stdio.h>
void mostraVet(float vetor[], int tamanhoVetor){
    int penultimo = tamanhoVetor-1;
    int i;
    printf("{");
    for(i=0; i < penultimo; i++){
        printf("%f; ", vetor[i]);
    }
    printf("%f}\n", vetor[penultimo]);

}

void selectionSort(float vetor[], unsigned tamanhoVetor){
    int penultimo = tamanhoVetor-1;
    float tmp;
    unsigned i, cont;

    for(i = 0; i < penultimo; i++){
        int menorPosicao = i;
        for(cont = i+1; cont<tamanhoVetor; cont++){
            if(vetor[cont] < vetor[menorPosicao]){
                menorPosicao = cont;
            }
        }
        tmp = vetor[i];
        vetor[i] = vetor[menorPosicao];
        vetor[menorPosicao] = tmp;
    }   
}

int main(){
    int tamanhoVetor = 3;
    float vetor[3] = {17,45,13};    
    
    printf("Antes da ordenacao: ");
    mostraVet(vetor, 3);

    selectionSort(vetor, 3);
    printf("Depois da ordenacao: ");
    mostraVet(vetor, 3);
}