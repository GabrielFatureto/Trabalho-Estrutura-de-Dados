#ifndef DISPARADOR_H
#define DISPARADOR_H

#include "carregador.h"

/*
 Arquivo que vai representar os Disparadores de formas que vão desenhar as formas geométricas no SVG.
 Um Disparador vai atuar como uma pilha, estrutura LIFO (Last In, First Out), colocando e retirando elementos do topo
*/

typedef void* DISPARADOR;

/** 
 /// @brief Cria um Disparador vazio.
 /// @param i Identificador do Disparador
 /// @param x Coordenada x do Disparador
 /// @param y Coordenada y do Disparador
 /// @return Retorna um ponteiro para o Disparador criado
 */
DISPARADOR criar_Disparador(int i, double x, double y);

/** 
 /// @brief Recebe o identificador do Disparador
 /// @param d Ponteiro para o Disparador analisado
 /// @return Retorna o identificador do Disparador
 */
int get_id_disparador(DISPARADOR d);

/** 
 /// @brief Recebe a coordenada x do Disparador
 /// @param d Ponteiro para o Disparador analisado
 /// @return Retorna a coordenada x do Disparador
 */
double get_x_disparador(DISPARADOR d);

/** 
 /// @brief Recebe a coordenada y do Disparador
 /// @param d Ponteiro para o Disparador analisado
 /// @return Retorna a coordenada y do Disparador
 */
double get_y_disparador(DISPARADOR d);

/** 
 /// @brief Recebe o Carregador associado ao Disparador
 /// @param d Ponteiro para o Disparador analisado
 /// @return Retorna o ponteiro para o Carregador associado ao Disparador
 */
CARREGADOR get_carregador(DISPARADOR d);

/**
 /// @brief Recebe a forma que está armada no Disparador
 /// @param d Ponteiro para o Disparador analisado
 /// @return Retorna o ponteiro para a forma que está armada no Disparador
 */
void* get_forma_armada_disparador(DISPARADOR d);

/** 
 /// @brief Prepara a forma que está no topo do Disparador para ser "atirada"
 /// @param d Ponteiro para o Disparador analisado
 /// @return Retorna o ponteiro para a forma na posição de disparo
 */
void* armar_disparador(DISPARADOR d);

/**
 /// @brief Move o Disparador para uma nova posição (novo_x, novo_y)
 /// @param d Ponteiro para o Disparador analisado
 /// @param novo_x Novo valor do x do Disparador
 /// @param novo_y Novo valor do y do Disparador
 */
void mover_disparador(DISPARADOR d, double novo_x, double novo_y);


