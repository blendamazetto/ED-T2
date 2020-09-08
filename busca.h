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

/*
    *Faz uma busca dentro da lista de circulos
    *Precisa da lista circulos e o id do item a ser procurado
    *Retorna o lemento achado ou null
    
*/
No buscarCirculo(Lista listasObjetos[], int i);

/*
    *Faz uma busca dentro da lista de retangulos
    *Precisa da lista retangulos e o id do item a ser procurado
    *Retorna o lemento achado ou null
    
*/
No buscarRetangulo(Lista listasObjetos[], int i);

/*
    *Faz uma busca dentro da lista de textos
    *Precisa da lista texto e o id do item a ser procurado
    *Retorna o lemento achado ou null
    
*/
No buscarTexto(Lista listasObjetos[], int i);

/*
    *Faz uma busca dentro da lista de quadras
    *Precisa da lista quadra e o id do item a ser procurado
    *Retorna o lemento achado ou null
    
*/
No buscarQuadra(Lista listasObjetos[], char cep[]);

/*
    *Faz uma busca dentro da lista de hidrande
    *Precisa da lista hidrante e o id do item a ser procurado
    *Retorna o lemento achado ou null
    
*/
No buscarHidrante(Lista listasObjetos[], char id[]);

/*
    *Faz uma busca dentro da lista de semaforo
    *Precisa da lista semaforo e o id do item a ser procurado
    *Retorna o lemento achado ou null
    
*/
No buscarSemaforo(Lista listasObjetos[], char id[]);

/*
    *Faz uma busca dentro da lista de Radio Base
    *Precisa da lista Radio Base e o id do item a ser procurado
    *Retorna o lemento achado ou null
    
*/
No buscarRadioBase(Lista listasObjetos[], char id[]);

/*
    *Remove um no
    *Precisa da lista escolhida e o no a ser removido
    *Retorna nada
    
*/
void removerNo(Lista lista, No no);


#endif