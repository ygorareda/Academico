#include <stdio.h>
#include <stdlib.h>

int main(){
    long int i,j,menor,aux,qtd;
    long int *vetor;

    printf("digite a quantidade:");
    scanf("%ld",&qtd);


    //aloca um vetor aleatório de acordo com o tamanho anterior
    vetor = (long int*)malloc(sizeof(long int) * qtd);
    srand(time(NULL));
    for(i=0;i<qtd;i++){
        do{
            vetor[i] = rand() % qtd;
            aux = 1;
            for(j=0;j<i;j++){
                if(vetor[j] == vetor[i]){
                    vetor[i] = rand()%qtd;
                    aux = 0;
                }
            }
        }while(aux!= 1);
        
    }

    //mostra o vetor desordenado
    for(i=0;i<qtd;i++){
        printf("%ld\t",vetor[i]);
    }

    //ordena o vetor com o algorítmo selection
    for(i=0;i<qtd;i++){
        menor = i;
        for(j=i+1;j<qtd;j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        aux = vetor[menor];
        vetor[menor] = vetor[i];
        vetor[i] = aux;
    }

    //mostra o vetor ordenado após a ordenação
    printf("\n **** \n");
    for(i=0;i<qtd;i++){
        printf("%ld \t",vetor[i]);
    }

}