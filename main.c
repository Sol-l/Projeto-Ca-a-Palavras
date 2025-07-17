#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//fazer agora para a vertical, vamos fazer a soma tanto na horizontal quanto na vertical.

int main(void){

    int vetorzao[10][10];
    int i, j;
    int numeroBusca, somarValPosicao=0, salvarPosicaoi, salvarPosicaoj, parar;


    //inicializa o gerador de números
    srand(time(NULL));

    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            vetorzao[i][j] = (rand() % 100) + 1;
        }
    }

    printf("Informe um numero para buscar na tabela: \n");
    scanf("%d", &numeroBusca);

    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            printf("%d ", vetorzao[i][j]);
            if(j == 9){
                printf("\n");
            }
        }
    }

    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            //se o valor a ser buscado for igual ao valor armazenado na posição
            if(numeroBusca == vetorzao[i][j]){ 

                //salva as posições que o número foi encontrado
                salvarPosicaoi = i;
                salvarPosicaoj = j;

                //aqui o algortimo faz a soma do número com base no seu tamanho, 
                //se for 3 então ele soma [3]+[x]+[y] = somarValPosicao
                for(int k=0; k<numeroBusca; k++){
                    //faz a soma do numeroBusca com os número seguintes
                    somarValPosicao += vetorzao[i][j+k];
                }            
            }
        }
    }

    if(somarValPosicao == 0){
        printf("Numero nao encontrado na matriz");
    }else{
        printf("Busca por: %d, resultado = %d\n", numeroBusca, somarValPosicao);
        printf("Posicao na Matriz: %d%d", salvarPosicaoi, salvarPosicaoj);
    }

    return 0;
}