#ifndef __leitura_h
#define __leitura_h
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
#include "busca.h"

//le o arquivo qry e executa suas funcoes
void lerQry (char saidaQry[], Lista listasObjetos, char arqQry[]);

#endif