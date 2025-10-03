#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circulo.h"

#define pi 3.1415926535897

typedef struct {
    int i;
    double x, y, r;
    char *corb, *corp;
} Circle;

CIRCULO cria_circulo(int i, double x, double y, double r, char* corb, char* corp){
    Circle* c = (Circle*)malloc(sizeof(Circle));
    if(c == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    c->i = i;
    c->x = x;
    c->y = y;
    c->r = r;

    c->corb = (char*)malloc(strlen(corb)+1);
    if(c->corb == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(c->corb, corb);

    c->corp = (char*)malloc(strlen(corp)+1);
    if(c->corp == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(c->corp, corp);

    return c;
}

int get_i(CIRCULO c){
    return ((Circ*)c)->i;
}

double get_x_circulo(CIRCULO c){
    return ((Circ*)c)->x;
}

double get_y_circulo(CIRCULO c){
    return ((Circ*)c)->y;
}

double get_r(CIRCULO c){
    return ((Circ*)c)->r;
}

double get_area(CIRCULO c){
    return pi * ((Circ*)c)->r * ((Circ*)c)->r;
}

char* get_corb(CIRCULO c){
    return ((Circ*)c)->corb;
}

char* get_corp(CIRCULO c){
    return ((Circ*)c)->corp;
}

void set_i (CIRCULO c, int i){
    ((Circ*)c)->i = i;
}

void set_x_circulo(CIRCULO c, double x){
    ((Circ*)c)->x = x;
}

void set_y_circulo(CIRCULO c, double y){
    ((Circ*)c)->y = y;
}

void set_corb(CIRCULO c, char* corb){
    strcpy(((Circ*)c)->corb, corb);
}

void set_corp(CIRCULO c, char* corp){
    strcpy(((Circ*)c)->corp, corp);
}

void excluir_circulo(CIRCULO c){
    free(((Circ*)c)->corb);
    free(((Circ*)c)->corp);
    free(c);
}