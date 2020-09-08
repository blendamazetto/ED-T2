#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circulo.h"

typedef struct c{

    int i;
    double r;
    double x;
    double y;
    char expessura[20];
    char corb[20];
    char corp[20];

}CirculoStruct;

Circulo criaCirculo(int i, double r, double x, double y, char expessura[], char corb[], char corp[])
{
    CirculoStruct* circulo = (CirculoStruct*) malloc(sizeof(CirculoStruct));

    circulo->i = i;
    circulo->x = x;
    circulo->y = y;
    circulo->r = r;
    strcpy(circulo->expessura, expessura);
    strcpy(circulo->corb, corb);
    strcpy(circulo->corp, corp);

    return circulo;
}

int getCirculoI(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->i;
}

double getCirculoR(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->r;
}

double getCirculoX(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->x;
}

double getCirculoY(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->y;
}

char* getCirculoSw(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->expessura;
}

char* getCirculoCorb(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->corb;
}

char* getCirculoCorp(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->corp;
}

void setCirculoI(Circulo circulo, int i)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->i = i;
}

void setCirculoR(Circulo circulo, double r)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->r = r;
}

void setCirculoX(Circulo circulo, double x)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->x = x;
}

void setCirculoY(Circulo circulo, double y)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->y = y;
}

void setCirculoSw(Circulo circulo, char sw[])
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    strcpy(circ->expessura, sw);
}

void setCirculoCorb(Circulo circulo, char corb[])
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    strcpy(circ->corb, corb);
}

void setCirculoCorp(Circulo circulo, char corp[])
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    strcpy(circ->corp, corp);
}
