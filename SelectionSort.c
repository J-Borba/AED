#include <stdio.h>
#define n 10

void preencher(int vet[n]){
    for(int i=0; i<n; i++){
        printf("Digite vet[%d]: ", i); scanf("%d", &vet[i]);
    }
}

int buscar(int vet[n], int x){
    for(int i=0; i<n; i++){
        if(vet[i] == x){
            return i;
        }
    }
    return -1;
}

void selectionSort(int vet[n]){
    for(int i=0; i<n; i++){
        int posMin = i;
        for(int j=i+1; j<n; j++){              
            if(vet[posMin] > vet[j])
                posMin = j;                
        }
        int temp = vet[i];
        vet[i] = vet[posMin];
        vet[posMin] = temp;       
    }
}
int main(){
    int vet[10], ans;
    do{
        printf("\n\nDigite a operacao desejada: \n[1]Preencher vetor [2]Buscar por um valor [3]Ordenar o vetor [4]Sair\n");
        scanf("%d", &ans);
        if(ans == 1){
            preencher(vet);
        }
        else if(ans == 2){
            int valor;
            printf("\nDigite o valor a ser procurado: "); scanf("%d", &valor);
            if(buscar(vet, valor) == -1){
                printf("\nNúmero não está no vetor!\n");
            }
            else{
                printf("\nNumero está na posição %d\n", buscar(vet, valor));
            }
        }
        else if(ans == 3){
            selectionSort(vet);
        }
        else if(ans < 1 || ans > 4){
            printf("Favor digitar uma opção válida!");
        }
    } while(ans != 4);
    printf("Programa terminado!");
    return 0;
}
