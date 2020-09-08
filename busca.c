#include <stdio.h>
#include <stdlib.h>
#include "busca.h"

No buscarCirculo(Lista listasObjetos[], int i)
{
    No node;
    for(node = getFirst(listasObjetos[0]); node != NULL; node = getNext(node))
    {
        Info c = getInfo(node);
        if(getCirculoI(c)== i)
        {
            return node;
        }    
    }
    return node=NULL; 
}

No buscarRetangulo(Lista listasObjetos[], int i)
{
    No node;
    for(node = getFirst(listasObjetos[1]); node != NULL; node = getNext(node))
    {
        Info r = getInfo(node);
        if(getRetanguloI(r)== i)
        {
            return node;
        }    
    }
    return node=NULL; 
}

No buscarTexto(Lista listasObjetos[], int i)
{
    No node;
    for(node = getFirst(listasObjetos[2]); node != NULL; node = getNext(node))
    {
        Info t = getInfo(node);
        if(getTextoI(t)== i)
        {
            return node;
        }    
    }
    return node=NULL; 
}

No buscarQuadra(Lista listasObjetos[], char cep[])
{
    No node;
    for(node = getFirst(listasObjetos[3]); node != NULL; node = getNext(node))
    {
        Info q = getInfo(node);
        if(strcmp(getQuadraCep(q), cep)==0)
        {
            return node;
        }    
    }
    return node=NULL; 
}

No buscarHidrante(Lista listasObjetos[], char id[])
{
    No node;
    for(node = getFirst(listasObjetos[4]); node != NULL; node = getNext(node))
    {
        Info h = getInfo(node);
        if(strcmp(getHidranteId(h), id)==0)
        {
            return node;
        }    
    }
    return node=NULL; 
}

No buscarSemaforo(Lista listasObjetos[], char id[])
{
    No node;
    for(node = getFirst(listasObjetos[5]); node != NULL; node = getNext(node))
    {
        Info s = getInfo(node);
        if(strcmp(getSemaforoId(s), id)==0)
        {
            return node;
        }    
    }
    return node=NULL; 
}

No buscarRadioBase(Lista listasObjetos[], char id[])
{
    No node;
    for(node = getFirst(listasObjetos[6]); node != NULL; node = getNext(node))
    {
        Info rb = getInfo(node);
        if(strcmp(getRadiobaseId(rb), id)==0)
        {
            return node;
        }    
    }
    return node=NULL; 
}