#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int itens[MAX];
    int inicio;
    int fim;
}Fila;

void inicializarFila(Fila *f){
    f->inicio = 0;
    f->fim = 0;
}

int filaVazia(Fila *f){
    return f->inicio == f->fim; // Verifica se o inicio e igual ao fim
}

int filaCheia(Fila *f){
    return f->fim == MAX; // Verifica se o fim e igual a MAX
}

int adicionarFila(Fila *f, int valor){

    if(filaCheia(f)){
        return 0;
    }

    f->itens[f->fim] = valor; // Adiciona o valor no lugar que o fim esta 
    f->fim++; // Anda com o final para o proximo lugar 

    return 1;
}

int removerFila(Fila *f){

    if(filaVazia(f)){
        return 0;
    }
    f->inicio++; // Anda com o inicio 
    return 1;
}

void mostrarFila(Fila *f){

    int i;

    for(i = f->inicio; i < f->fim; i++){
        printf("%d ", f->itens[i]);
    }

    printf("\n");
}

int main(){
 Fila f;
    inicializarFila(&f);

    printf("Inicializando fila\n");
    printf("Fila vazia? %s\n", filaVazia(&f) ? "Sim" : "Nao");
    printf("Adicionando valores: 10, 20, 30\n");
    adicionarFila(&f, 10);
    adicionarFila(&f, 20);
    adicionarFila(&f, 30);
    printf("Conteudo da fila: ");
    mostrarFila(&f);
    printf("Removendo um elemento...\n");
    removerFila(&f);
    printf("Conteudo da fila apos remocao: ");
    mostrarFila(&f);
    printf("Adicionando mais valores ate a fila ficar cheia\n");
    while(!filaCheia(&f)){
        adicionarFila(&f, f.itens[f.fim - 1] + 10);
    }
    printf("Fila cheia? %s\n", filaCheia(&f) ? "Sim" : "Nao");
    printf("Conteudo da fila cheia: ");
    mostrarFila(&f);
    printf("Removendo todos os elementos\n");
    while(!filaVazia(&f)){
        removerFila(&f);
    }
    printf("Fila vazia apos remover tudo? %s\n", filaVazia(&f) ? "Sim" : "Nao");
    return 0;  
      
}
