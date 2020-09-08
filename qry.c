#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry.h"

void car(Lista listasObjetos[], double x, double y, double w, double h, char saidaSvg[], FILE* saida)
{
    FILE *svgQry = fopen(saidaSvg, "a");

    double areaTotal=0;
    No node;

    for(node = getFirst(listasObjetos[3]); node != NULL; node = getNext(node))
    {
        Info q = getInfo(node);
    
        if (getQuadraX(q) >= x && getQuadraY(q) >= y && getQuadraX(q) + getQuadraW(q) <= x + w && getQuadraY(q) + getQuadraH(q) <= y + h)
        {
            areaTotal=areaTotal+(getQuadraH(q)*getQuadraW(q));

            fprintf(saida, "%s %lf\n", getQuadraCep(q),(getQuadraH(q)*getQuadraW(q)));
            fprintf(svgQry,"\t<text x=\"%lf\" y=\"%lf\" >%lf</text>\n",((getQuadraX(q)+getQuadraW(q))/2),((getQuadraY(q)+getQuadraH(q))/2),(getQuadraW(q)*getQuadraH(q)));
        }
    }   

    fprintf(saida, "%lf\n",areaTotal);
    fprintf(svgQry, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"transparent\" stroke=\"black\"/>\n",x,y,w,h);
    fprintf(svgQry,"\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%d\" stroke=\"black\"/>\n",x,y,x,0);
    fprintf(svgQry,"\t<text x=\"%lf\" y=\"%d\">%lf</text>\n",x,0,areaTotal);

    fclose(svgQry);
}

double distancia(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
}

void cbq(Lista listasObjetos[], double x, double y, double r, char corb[], FILE* saida)
{
    No node;

    for(node = getFirst(listasObjetos[3]); node != NULL; node = getNext(node))
    {
        Info q = getInfo(node);
    
        if(distancia(getQuadraX(q),getQuadraY(q),x,y) <= r && distancia(getQuadraX(q) + getQuadraW(q) ,getQuadraY(q) + getQuadraH(q),x,y) <= r)
        {
            if(distancia(getQuadraX(q) + getQuadraW(q), getQuadraY(q),x,y) <= r && distancia(getQuadraX(q), getQuadraY(q) + getQuadraH(q),x,y) <= r)
            {
                setQuadraCstrk(q, corb);
                fprintf(saida, "%s\n", getQuadraCep(q));
            }
        }
    } 
}

void i(Lista listasObjetos[], int j,  double x, double y, char saidaSvg[], FILE* saida)
{
    FILE *svgQry = fopen(saidaSvg, "a");
    No node;

    for(node = getFirst(listasObjetos[0]); node != NULL; node = getNext(node))
    {
        Info c = getInfo(node);
        if(getCirculoI(c)==j)
        {
            float dist = sqrt(pow(x - getCirculoX(c),2) + pow(y - getCirculoY(c),2));

            if (getCirculoR(c) >= dist)
            {
                fprintf(saida,"circulo interno\n");
                desenhaCirculo(10, x, y, "blue", "blue", saidaSvg);
                fprintf(svgQry,"\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n",x ,y ,getCirculoX(c) ,getCirculoY(c) ,"blue");
            }
            else
            {
                fprintf(saida,"circulo nao interno\n");
                desenhaCirculo(10, x, y, "magenta", "magenta", saidaSvg);
                fprintf(svgQry,"\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n",x ,y ,getCirculoX(c) ,getCirculoY(c) ,"magenta");
            }
        }
    } 

    for(node = getFirst(listasObjetos[1]); node != NULL; node = getNext(node))
    {
        Info r = getInfo(node);
        if(getRetanguloI(r)==j)
        {
            float difx = x - getRetanguloX(r);
            float dify = y - getRetanguloY(r);

            if(difx >= 0 && difx <= getRetanguloW(r) && dify >= 0 && dify <= getRetanguloH(r))
            {
                fprintf(saida,"retangulo interno\n");
                desenhaCirculo(10, x, y, "blue", "blue", saidaSvg);
                fprintf(svgQry,"\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n",x ,y ,(getRetanguloX(r)+getRetanguloW(r))/2 ,(getRetanguloY(r)+getRetanguloH(r))/2 ,"blue");

            }
            else
            {
                fprintf(saida,"retangulo nao interno\n");
                desenhaCirculo(10, x, y ,"magenta", "magenta", saidaSvg);
                fprintf(svgQry,"\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n",x ,y ,(getRetanguloX(r)+getRetanguloW(r))/2 ,(getRetanguloY(r)+getRetanguloH(r))/2 ,"magenta");
            }
        }
    } 

    fclose(svgQry);
}

void pnt (Lista listasObjetos[], int j, char corb[], char corp[], FILE* saida)
{
    if(buscarCirculo(listasObjetos, j) != NULL)
{
        Info c = getInfo(buscarCirculo(listasObjetos, j));

        fprintf(saida,"%lf %lf\n", getCirculoX(c), getCirculoY(c));
        setCirculoCorb(c, corb);
        setCirculoCorp(c, corp);
    }

    No node;
    for(node = getFirst(listasObjetos[1]); node != NULL; node = getNext(node))
    {
        Info r = getInfo(node);

        if(getRetanguloI(r)== j)
        {
            fprintf(saida,"%lf %lf\n", getRetanguloX(r), getRetanguloY(r));
            setRetanguloCorb(r, corb);
            setRetanguloCorp(r, corp);
        }    
    } 

    for(node = getFirst(listasObjetos[2]); node != NULL; node = getNext(node))
    {
        Info t = getInfo(node);

        if(getTextoI(t)== j)
        {
            fprintf(saida,"%lf %lf\n", getTextoX(t), getTextoY(t));
            setTextoCorb(t, corb);
            setTextoCorp(t, corp);
        }    
    } 
}

void delf(Lista listasObjetos[], int j, FILE* saida)
{
    if(buscarCirculo(listasObjetos, j) != NULL)
    {
        Info c = getInfo(buscarCirculo(listasObjetos, j));
        fprintf(saida,"%d %lf %lf %lf %s %s \n", getCirculoI(c), getCirculoR(c), getCirculoX(c), getCirculoY(c), getCirculoCorb(c), getCirculoCorp(c));
        removerNo(listasObjetos[0], buscarCirculo(listasObjetos, j));
    }

    if(buscarRetangulo(listasObjetos, j) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listasObjetos, j));
        fprintf(saida,"%d %lf %lf %lf %lf %s %s \n", getCirculoI(r), getRetanguloW(r), getRetanguloH(r), getRetanguloX(r), getRetanguloY(r), getRetanguloCorb(r), getRetanguloCorp(r));
        removerNo(listasObjetos[1], buscarRetangulo(listasObjetos, j));
    }

    if(buscarTexto(listasObjetos, j) != NULL)
    {
        Info t = getInfo(buscarTexto(listasObjetos, j));
        fprintf(saida,"%d %lf %lf %s %s %s\n",getTextoI(t), getTextoX(t), getTextoY(t), getTextoCorb(t), getTextoCorp(t), getTextoTxto(t));
        removerNo(listasObjetos[2], buscarTexto(listasObjetos, j));
    }
}

void del (Lista listasObjetos[], char id[], FILE* saida, char saidaSvg[])
{

    FILE *svgQry = fopen(saidaSvg, "a");

    if(buscarQuadra(listasObjetos, id) != NULL)
    {
        Info q = getInfo(buscarQuadra(listasObjetos, id));
        fprintf(saida,"%s %lf %lf %lf %lf\n", getQuadraCep(q), getQuadraX(q), getQuadraY(q), getQuadraW(q), getQuadraH(q));
        fprintf(svgQry,"\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%d\" stroke=\"%s\"/>\n",(getQuadraX(q)+getQuadraW(q))/2,((getQuadraY(q)+getQuadraH(q))/2),(getQuadraX(q)+getQuadraW(q))/2,0,"black");
        fprintf(svgQry,"\t<text x=\"%lf\" y=\"%d\" >%s</text>\n",(getQuadraX(q)+getQuadraW(q))/2,0, getQuadraCep(q));
        removerNo(listasObjetos[3], buscarQuadra(listasObjetos, id));
    }

    if(buscarHidrante(listasObjetos, id) != NULL)
    {
        Info h = getInfo(buscarHidrante(listasObjetos, id));
        fprintf(saida,"%s %lf %lf \n", getHidranteId(h), getHidranteX(h), getHidranteY(h));
        fprintf(svgQry,"\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%d\" stroke=\"%s\"/>\n",getHidranteX(h), getHidranteY(h), getHidranteX(h), 0, "black");
        fprintf(svgQry,"\t<text x=\"%lf\" y=\"%d\" >%s</text>\n",getHidranteX(h), 0, getHidranteId(h));
        removerNo(listasObjetos[4], buscarHidrante(listasObjetos, id));
    }

    if(buscarSemaforo(listasObjetos, id) != NULL)
    {
        Info s = getInfo(buscarSemaforo(listasObjetos, id));
        fprintf(saida,"%s %lf %lf \n", getSemaforoId(s), getSemaforoX(s), getSemaforoY(s));
        fprintf(svgQry,"\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%d\" stroke=\"%s\"/>\n",getSemaforoX(s), getSemaforoY(s), getSemaforoX(s), 0, "black");
        fprintf(svgQry,"\t<text x=\"%lf\" y=\"%d\" >%s</text>\n",getSemaforoX(s), 0, getSemaforoId(s));
        removerNo(listasObjetos[5], buscarSemaforo(listasObjetos, id));
    }

    if(buscarRadioBase(listasObjetos, id) != NULL)
    {
        Info rb = getInfo(buscarRadioBase(listasObjetos, id));
        fprintf(saida,"%s %lf %lf \n", getRadiobaseId(rb), getRadiobaseX(rb), getRadiobaseY(rb));
        fprintf(svgQry,"\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%d\" stroke=\"%s\"/>\n",getRadiobaseX(rb), getRadiobaseY(rb), getRadiobaseX(rb), 0, "black");
        fprintf(svgQry,"\t<text x=\"%lf\" y=\"%d\" >%s</text>\n",getRadiobaseX(rb), 0, getRadiobaseId(rb));
        removerNo(listasObjetos[6], buscarRadioBase(listasObjetos, id));
    }

    fclose(svgQry);
}