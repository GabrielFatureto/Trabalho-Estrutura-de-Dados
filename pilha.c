#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


typedef struct No {
    void* dado;       
    struct No* proximo;
} No;


typedef struct Pilha {
    No* topo;         
    int tamanho;
} Pilha;

PILHA pilha_criar() {
    PILHA p = (PILHA) malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
        p->tamanho = 0;
    }
    return p;
}

// void pilha_destruir(PILHA p_ptr, void (*liberar_dado)(void*)) {
//     if (p_ptr == NULL || *p_ptr == NULL) return;

//     PILHA p = *p_ptr;
//     No* atual = p->topo;
//     while (atual != NULL) {
//         No* proximo_no = atual->proximo;
//         if (liberar_dado != NULL) {
//             liberar_dado(atual->dado); // Libera o dado do usuário, se a função for fornecida
//         }
//         free(atual); // Libera o nó da pilha
//         atual = proximo_no;
//     }
//     free(p); // Libera a estrutura da pilha
//     *p_ptr = NULL; // Define o ponteiro original do usuário como NULL para segurança
// }

bool pilha_empilhar(PILHA p, void* dado) {
    if (p == NULL) return false;

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        return false; // Falha na alocação de memória
    }

    novo_no->dado = dado;
    novo_no->proximo = p->topo; // O novo nó aponta para o antigo topo
    p->topo = novo_no;          // O topo da pilha agora é o novo nó
    p->tamanho++;

    return true;
}

void* pilha_desempilhar(PILHA p) {
    if (p == NULL || pilha_esta_vazia(p)) {
        return NULL;
    }

    No* no_removido = p->topo;
    void* dado_retornado = no_removido->dado;

    p->topo = p->topo->proximo; // O topo agora é o próximo elemento

    free(no_removido); // Libera a memória do nó
    p->tamanho--;

    return dado_retornado;
}

void* pilha_topo(PILHA p) {
    if (p == NULL || pilha_esta_vazia(p)) {
        return NULL;
    }
    return p->topo->dado;
}

int pilha_tamanho(PILHA p) {
    if (p == NULL) return 0;
    return p->tamanho;
}

bool pilha_esta_vazia(PILHA p) {
    if (p == NULL) return true;
    return p->tamanho == 0;
}