#ifndef __QRY_h
#define __QRY_h
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "lista.h"
#include "svg.h"
#include "lerQry.h"
#include "busca.h"
#include <math.h>

void car(Lista listasObjetos[], double x, double y, double w, double h, char saidaSvg[], FILE* saida);

double distancia(double x1, double y1, double x2, double y2);

void cbq(Lista listasObjetos[], double x, double y, double r, char corb[], FILE* saida);

void i(Lista listasObjetos[], int i,  double x, double y, char saidaSvg[], FILE* saida);

void pnt (Lista listasObjetos[], int j, char corb[], char corp[], FILE* saida);

void delf(Lista listasObjetos[], int j, FILE* saida);

void del (Lista listasObjetos[], char id[], FILE* saida, char saidaSvg[]);


#endif