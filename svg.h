#ifndef __SVG_H
#define __SVG_H
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "lista.h"
#include "svg.h"
#include "qry.h"

void iniciaSvg(char svg[]);

void desenhaCirculo(double raio, double x, double y, char cor_b[], char cor_p[], char svg[]);

void desenhaRetangulo(double w, double h, double x, double y, char cor_b[], char cor_p[], char svg[]);

void escreveTexto(double x, double y, char cor_b[], char cor_p[], char text[], char svg[]);

void desenhaQuadra(double w, double h, double x, double y, char cor_b[], char cor_p[], char cep[], char svg[]);

void desenhaHidrante(double raio, double x, double y, char cor_b[], char cor_p[], char svg[]);

void desenhaSemaforo(double raio, double x, double y, char cor_b[], char cor_p[], char svg[]);

void desenhaRadioBase(double raio, double x, double y, char cor_b[], char cor_p[], char svg[]);

void finalizaSvg(char svg[]);

void gerarSvgQry(Lista listasObjetos[], char saidaSvg[]);


#endif