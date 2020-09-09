#include<stdio.h>
#include<stdlib.h>

#include"svg.h"

void iniciaSvg(char svg[])
{

    FILE *arqSvg;
    arqSvg = fopen(svg, "w");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser aberto\n");
        exit(1);
    }

    fprintf(arqSvg, "<svg>\n");

    fclose(arqSvg);
}

void desenhaCirculo(double raio, double x, double y, char cor_b[], char cor_p[], char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, cor_p);

    fclose(arqSvg);

}


void desenhaRetangulo(double w, double h, double x, double y, char cor_b[], char cor_p[], char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width =\"1\"/>\n",x,y,w,h,cor_p,cor_b);

    fclose(arqSvg);
}

void desenhaRetanguloTracejado(double w, double h, double x, double y, char cor_b[], char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-width =\"1\" stroke-dasharray=\"1\" />\n",x,y,w,h,cor_b);

    fclose(arqSvg);
}

void escreveTexto(double x, double y, char cor_b[], char cor_p[], char text[], char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">%s</text>\n",x,y,cor_b,cor_p,text);

    fclose(arqSvg);
}

void desenhaQuadra(double w, double h, double x, double y, char cor_b[], char cor_p[], char cep[], char svg[], char quaExpessura[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg,"\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\"/>\n",x, y, w, h, cor_p, cor_b, quaExpessura);
    fprintf(arqSvg, "\t<text x=\"%lf\" y=\"%lf\" fill=\"black\">%s</text>\n", x+w/2, y+h/2, cep);

    fclose(arqSvg);

}

void desenhaHidrante(double raio, double x, double y, char cor_b[], char cor_p[], char svg[], char hidraExpessura[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, hidraExpessura,cor_p);

    fclose(arqSvg);
}

void desenhaSemaforo(double raio, double x, double y, char cor_b[], char cor_p[], char svg[], char semaExpessura[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, semaExpessura, cor_p);

    fclose(arqSvg);
}

void desenhaRadioBase(double raio, double x, double y, char cor_b[], char cor_p[], char svg[], char radioExpessura[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser editado");
        exit(1);
    }

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, radioExpessura, cor_p);


    fclose(arqSvg);

}

void finalizaSvg(char svg[])
{
    FILE *arqSvg;
    arqSvg = fopen(svg, "a");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser finalizado");
        exit(1);
    }

    fprintf(arqSvg, "</svg>");

    fclose(arqSvg);
}

void gerarSvgQry(Lista listasObjetos[], char saidaSvg[])
{
    int i=0;

    if(i==0)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info c = getInfo(node);
            desenhaCirculo(getCirculoR(c), getCirculoX(c), getCirculoY(c), getCirculoCorb(c), getCirculoCorp(c), saidaSvg);
        } 
        i++;
    }

    if(i==1)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info r = getInfo(node);
            desenhaRetangulo(getRetanguloW(r), getRetanguloH(r), getRetanguloX(r), getRetanguloY(r), getRetanguloCorb(r), getRetanguloCorp(r), saidaSvg);           
        } 
        i++;
    }

    if(i==2)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info t = getInfo(node);
            escreveTexto(getTextoX(t), getTextoY(t), getTextoCorb(t), getTextoCorp(t), getTextoTxto(t), saidaSvg);
        } 
        i++;
    }

    if(i==3)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info q = getInfo(node);
            desenhaQuadra(getQuadraW(q), getQuadraH(q), getQuadraX(q), getQuadraY(q), getRadiobaseCstrk(q), getQuadraCfill(q), getQuadraCep(q), saidaSvg, getQuadraSw(q));           
        } 
        i++;
    }

    if(i==4)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info h = getInfo(node);
            desenhaHidrante(5, getHidranteX(h), getHidranteY(h), getHidranteCstrk(h), getHidranteCfill(h), saidaSvg, getHidranteSw(h));            
        } 
        i++;
    }

    if(i==5)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info s = getInfo(node);
            desenhaSemaforo(5, getSemaforoX(s), getSemaforoY(s), getSemaforoCstrk(s), getSemaforoCfill(s), saidaSvg, getSemaforoSw(s));
        } 
        i++;
    }

    if(i==6)
    {
        No node;
        for(node = getFirst(listasObjetos[i]); node != NULL; node = getNext(node))
        {
            Info rb = getInfo(node);
            desenhaRadioBase(5, getRadiobaseX(rb), getRadiobaseY(rb), getRadiobaseCstrk(rb), getRadiobaseCfill(rb), saidaSvg, getRadiobaseSw(rb));            
        } 
        i++;
    }
}