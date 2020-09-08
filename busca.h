#ifndef __BUSCA__
#define __BUSCA__
#include <string.h>
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "lista.h"

No buscarCirculo(Lista listasObjetos[], int i);

No buscarRetangulo(Lista listasObjetos[], int i);

No buscarTexto(Lista listasObjetos[], int i);

No buscarQuadra(Lista listasObjetos[], char cep[]);

No buscarHidrante(Lista listasObjetos[], char id[]);

No buscarSemaforo(Lista listasObjetos[], char id[]);

No buscarRadioBase(Lista listasObjetos[], char id[]);

void removerNo(Lista lista, No no);


#endif