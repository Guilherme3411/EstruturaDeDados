#include <stdlib.h>
#include <stdio.h>

typedef struct Lista
{
    int valor;
    struct ITEM *proximo
}*tipoLista;

tipoLista criarItem(int valor){
    tipoLista novoItem = malloc(sizeof(tipoLista));
    if(novoItem == NULL){
        return NULL;
    }

    novoItem -> valor = valor;
    novoItem -> proximo = NULL;
    return novoItem;
}

tipoLista inserirInicio(int valor, tipoLista lista){
    tipoLista novoNoh = criarItem(valor);
    if(lista==NULL){
        return novoNoh;
    }else{
    novoNoh->proximo = lista;
        return novoNoh;
    }
}

tipoLista inserirFinal(int valor, tipoLista lista){
    tipoLista novoNoh = criarItem(valor);
    if(lista==NULL){
        return novoNoh;
    }else{
        tipoLista aux = lista;
        while (aux->proximo!=NULL)
        {
           aux = aux->proximo;
        }
        aux->proximo = novoNoh;
        return lista;
    }

}

tipoLista inserirMeio(int valor, tipoLista lista, int entre){
    tipoLista novoNoh = criarItem(valor);
    tipoLista aux = lista;
    if(lista==NULL){
        register novoNoh;
    }else if (aux->proximo == NULL)
    {
       inserirInicio(valor,lista);
    }else if(aux==NULL){
        return lista;
    }

    while (aux->valor != entre && aux != NULL )
    {
        aux = aux ->proximo;
    }

    novoNoh->proximo = aux->proximo;
    aux->proximo = novoNoh;
    return lista;
    
}

tipoLista removerInicio(tipoLista lista){
    if(lista==NULL){
        return lista;
    }else{
        tipoLista aux = lista;
        lista = lista->proximo;
        free(aux);
        aux = NULL;
        return lista;
    }
}

tipoLista removerFinal(tipoLista lista){
    if(lista==NULL){
        return 0;
    }else{
        if(lista -> proximo == NULL){
            free(lista);
            return NULL;
        }else{
            tipoLista aux1 = lista->proximo;
            tipoLista aux2 = lista;
            while(aux1->proximo != NULL){
                aux1 = aux1->proximo;
                aux2 = aux2->proximo;
            }
            aux2->proximo = aux1 ->proximo;
            free(aux1);
            return lista;
        }
    }
}

tipoLista removerMeio(tipoLista lista, int entre){
    if(lista==NULL){
        return 0;
    }else{
        if(lista->valor == entre){
            lista = removerInicio(lista);
            return lista;
        }else{
            tipoLista aux1 = lista->proximo;
            tipoLista aux2 = lista;
            while(aux1->valor == entre){
                aux1 = aux1->proximo;
                aux2 = aux2->proximo;
            }
            aux2->proximo = aux1 ->proximo;
            free(aux1);
            return lista;
        }
    }
}

int main(){
    return 0;
    
}