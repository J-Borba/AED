#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 10

void printFormatado(char palavra[]){
    printf("\n");
    for(int i=0; i<strlen(palavra); i++){
        printf("-");
        fflush(stdout);
    }
    printf("\n%s\n", palavra);
    for(int i=0; i<strlen(palavra); i++){
        printf("-");
        fflush(stdout);
    }
}

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
    char str[50];
    do{
        printf("\n\nDigite a operacao desejada: \n[1]Preencher vetor [2]Buscar por um valor [3]Ordenar o vetor [4]Sair\n");
        scanf("%d", &ans);
        if(ans == 1){
            preencher(vet);
        }
        else if(ans == 2){
            int valor;
            printf("Digite o valor a ser procurado: "); scanf("%d", &valor);
            if(buscar(vet, valor) == -1){
                printFormatado("Numero nao esta no vetor!");
            }
            else{
                snprintf(str, 50, "O numero esta na posicao: %d", buscar(vet, valor));
                printFormatado(str);
            }
        }
        else if(ans == 3){
            selectionSort(vet);
            printFormatado("Vetor Ordenado!");
        }
        else if(ans < 1 || ans > 4){
            printFormatado("Favor digitar uma opcao valida!");
        }
    } while(ans != 4);
    printFormatado("Programa terminado!");
    return 0;
}
