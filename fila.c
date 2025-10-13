#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


typedef struct {
    void* dado;      
    struct No* proximo;
} No;

typedef struct {
    No* frente;      
    No* tras;        
    int tamanho;
} Fila;


FILA fila_criar() {
    FILA f = (FILA) malloc(sizeof(Fila));
    if (f != NULL) {
        f->frente = NULL;
        f->tras = NULL;
        f->tamanho = 0;
    }
    return f;
}

// void fila_destruir(FILA f, void (*liberar_dado)(void*)) {
//     if (f == NULL) return;

//     No* atual = f->frente;
//     while (atual != NULL) {
//         No* proximo = atual->proximo;
//         if (liberar_dado != NULL) {
//             liberar_dado(atual->dado); // Libera o dado do usuário
//         }
//         free(atual); // Libera o nó da fila
//         atual = proximo;
//     }
//     free(f); // Libera a estrutura da fila
// }

bool fila_enfileirar(FILA f, void* dado) {
    if (f == NULL) return false;

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        return false; // Falha na alocação de memória
    }

    novo_no->dado = dado;
    novo_no->proximo = NULL;

    if (fila_esta_vazia(f)) {
        // Se a fila está vazia, o novo nó é tanto o início quanto o fim
        f->frente = novo_no;
        f->tras = novo_no;
    } else {
        // Adiciona o novo nó após o último e atualiza o ponteiro 'tras'
        f->tras->proximo = novo_no;
        f->tras = novo_no;
    }

    f->tamanho++;
    return true;
}

void* fila_desenfileirar(FILA f) {
    if (f == NULL || fila_esta_vazia(f)) {
        return NULL;
    }

    No* no_removido = f->frente;
    void* dado_retornado = no_removido->dado;

    // Avança o ponteiro 'frente' para o próximo nó
    f->frente = f->frente->proximo;

    // Se a fila ficou vazia, atualiza também o ponteiro 'tras'
    if (f->frente == NULL) {
        f->tras = NULL;
    }

    free(no_removido); // Libera a memória do nó
    f->tamanho--;

    return dado_retornado;
}

void* fila_frente(FILA f) {
    if (f == NULL || fila_esta_vazia(f)) {
        return NULL;
    }
    return f->frente->dado;
}

int fila_tamanho(FILA f) {
    if (f == NULL) return 0;
    return f->tamanho;
}

bool fila_esta_vazia(FILA f) {
    if (f == NULL) return true;
    return f->tamanho == 0;
}