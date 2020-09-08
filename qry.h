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

void crd (Lista listasObjetos[], char id[], FILE* saida);

float max(float n1, float n2);

float min(float n1, float n2);

void retanguloxCirculo(Info circ, Info ret, FILE* saida, char saidaSvg[]);

void circuloInt(Info c1, Info c2, FILE* saida, char saidaSvg[]);

void retanguloInt(Info r1, Info r2, FILE* saida, char saidaSvg[]);

void o(int j, int k, FILE* saida, char saidaSvg[], Lista listasObjetos[]);

void dq(Lista listaObjetos[], FILE* txt, char svg_qry[], char id[], double r, int ident);


#endif