#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int valor;
    struct Lista *proximo;
}Lista;

typedef Lista* tipoLista;

// Cria um novo nó
tipoLista criarItem(int valor){
    tipoLista novoItem = (tipoLista) malloc(sizeof(Lista));

    if(novoItem == NULL){
        return NULL;
    }

    novoItem->valor = valor;
    novoItem->proximo = NULL;

    return novoItem;
}

// Inserir no início
tipoLista inserirInicio(int valor, tipoLista lista){
    tipoLista novoNoh = criarItem(valor);

    if(novoNoh == NULL){
        return lista;
    }

    novoNoh->proximo = lista;
    return novoNoh;
}

// Inserir no final
tipoLista inserirFinal(int valor, tipoLista lista){
    tipoLista novoNoh = criarItem(valor);

    if(novoNoh == NULL){
        return lista;
    }

    if(lista == NULL){
        return novoNoh;
    }

    tipoLista aux = lista;

    while(aux->proximo != NULL){
        aux = aux->proximo;
    }

    aux->proximo = novoNoh;

    return lista;
}

// Inserir depois de um valor
tipoLista inserirMeio(int valor, tipoLista lista, int entre){

    if(lista == NULL){
        return inserirInicio(valor, lista);
    }

    tipoLista aux = lista;

    while(aux != NULL && aux->valor != entre){
        aux = aux->proximo;
    }

    if(aux == NULL){
        printf("Valor %d nao encontrado!\n", entre);
        return lista;
    }

    tipoLista novoNoh = criarItem(valor);

    novoNoh->proximo = aux->proximo;
    aux->proximo = novoNoh;

    return lista;
}

// Remover início
tipoLista removerInicio(tipoLista lista){

    if(lista == NULL){
        return NULL;
    }

    tipoLista aux = lista;

    lista = lista->proximo;

    free(aux);

    return lista;
}

// Remover final
tipoLista removerFinal(tipoLista lista){

    if(lista == NULL){
        return NULL;
    }

    if(lista->proximo == NULL){
        free(lista);
        return NULL;
    }

    tipoLista aux1 = lista->proximo;
    tipoLista aux2 = lista;

    while(aux1->proximo != NULL){
        aux1 = aux1->proximo;
        aux2 = aux2->proximo;
    }

    aux2->proximo = NULL;

    free(aux1);

    return lista;
}

// Remover valor específico
tipoLista removerMeio(tipoLista lista, int valor){

    if(lista == NULL){
        return NULL;
    }

    if(lista->valor == valor){
        return removerInicio(lista);
    }

    tipoLista aux1 = lista->proximo;
    tipoLista aux2 = lista;

    while(aux1 != NULL && aux1->valor != valor){
        aux1 = aux1->proximo;
        aux2 = aux2->proximo;
    }

    if(aux1 == NULL){
        printf("Valor %d nao encontrado!\n", valor);
        return lista;
    }

    aux2->proximo = aux1->proximo;

    free(aux1);

    return lista;
}

// Imprimir lista
void imprimirLista(tipoLista lista){

    if(lista == NULL){
        printf("Lista vazia!\n");
        return;
    }

    tipoLista aux = lista;

    while(aux != NULL){
        printf("%d -> ", aux->valor);
        aux = aux->proximo;
    }

    printf("NULL\n");
}

// Liberar memória
tipoLista liberarLista(tipoLista lista){

    while(lista != NULL){
        lista = removerInicio(lista);
    }

    return NULL;
}

int main(){

    tipoLista lista = NULL;

    lista = inserirInicio(10, lista);
    lista = inserirInicio(5, lista);
    lista = inserirInicio(1, lista);

    printf("Inserindo no inicio:\n");
    imprimirLista(lista);

    lista = inserirFinal(20, lista);
    lista = inserirFinal(30, lista);

    printf("\nInserindo no final:\n");
    imprimirLista(lista);

    lista = inserirMeio(15, lista, 10);

    printf("\nInserindo 15 depois de 10:\n");
    imprimirLista(lista);

    lista = removerInicio(lista);

    printf("\nRemovendo inicio:\n");
    imprimirLista(lista);

    lista = removerFinal(lista);

    printf("\nRemovendo final:\n");
    imprimirLista(lista);

    lista = removerMeio(lista, 15);

    printf("\nRemovendo valor 15:\n");
    imprimirLista(lista);

    lista = liberarLista(lista);

    return 0;
}