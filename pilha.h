#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h> // Para usar o tipo 'bool' e os valores 'true'/'false'
#include <stddef.h>  // Para usar o tipo 'size_t' e NULL




typedef void* PILHA;


/**
 * @brief Cria e inicializa uma nova pilha vazia.
 *
 * @return Um ponteiro para a nova Pilha alocada, ou NULL se a alocação falhar.
 */
PILHA pilha_criar();

// /**
//  * @brief Libera toda a memória associada à pilha e seus nós.
//  *
//  * @param p_ptr Ponteiro para um ponteiro da Pilha a ser destruída. O ponteiro da pilha
//  * original será definido como NULL após a destruição para evitar uso indevido.
//  * @param liberar_dado Ponteiro de função para liberar a memória de cada dado.
//  * Se for NULL, os dados em si não serão liberados por esta função.
//  */
// void pilha_destruir(PILHA* p_ptr, void (*liberar_dado)(void*));

/**
 * @brief Adiciona um elemento no topo da pilha (push).
 *
 * @param p Ponteiro para a Pilha.
 * @param dado Ponteiro para o dado a ser inserido.
 * @return 'true' se a inserção for bem-sucedida, 'false' em caso de falha na alocação.
 */
bool pilha_empilhar(PILHA p, void* dado);

/**
 * @brief Remove e retorna o elemento do topo da pilha (pop).
 *
 * @param p Ponteiro para a Pilha.
 * @return O ponteiro para o dado removido, ou NULL se a pilha estiver vazia.
 */
void* pilha_desempilhar(PILHA p);

/**
 * @brief Retorna o elemento no topo da pilha sem removê-lo (peek/top).
 *
 * @param p Ponteiro para a Pilha (const, pois não a modifica).
 * @return O ponteiro para o dado no topo, ou NULL se a pilha estiver vazia.
 */
void* pilha_topo(PILHA p);

/**
 * @brief Retorna o número de elementos na pilha.
 *
 * @param p Ponteiro para a Pilha (const).
 * @return O tamanho da pilha.
 */
int pilha_tamanho(PILHA p);

/**
 * @brief Verifica se a pilha está vazia.
 *
 * @param p Ponteiro para a Pilha (const).
 * @return 'true' se a pilha estiver vazia, 'false' caso contrário.
 */
bool pilha_esta_vazia(PILHA p);

#endif // PILHA_H