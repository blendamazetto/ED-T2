#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerGeo.h"

void lerGeo(char arqGeo[], char nomeSvgGeo[], Lista listasObjetos[])
{

    FILE *geo;
    int id1;
    double raio;
    int max[5] = {1000, 1000, 1000, 1000, 1000};
    char id2[20];
    char *txt=NULL;
    int n = 0;
    char tipo[10];
    char cep[20];
    double x, y, h, w;
    char expessura[2];
    char hidraExpessura[2];
    char semaExpessura[2];
    char quaExpessura[2];
    char radioExpessura[2];
    char circleExpessura[2];
    char rectExpessura[2];
    char borda[22]; 
    char preenchimento[22];
    char Qborda[22] = "black", Qpreenchimento[22] = "red";
    char RBborda[22] = "black", RBpreenchimento[22] = "green";
    char Sborda[22] = "black", Spreenchimento[22] = "blue";
    char Hborda[22] = "black", Hpreenchimento[22] = "yellow";

    hidraExpessura[0] = '0';
    semaExpessura[0] = '0';
    quaExpessura[0] = '0';
    radioExpessura[0] = '0';
    circleExpessura[0] = '0';
    rectExpessura[0] = '0';

    geo = fopen(arqGeo,"r");

    if(geo == NULL)
    {
        printf("\nERRO\nArquivo .geo nao pode ser aberto\n");
        exit(1);
    }
    
    iniciaSvg(nomeSvgGeo);
    printf("\nArquivo .svg aberto com sucesso\n");
    
    while(!feof(geo))
    {
        fscanf(geo, "%s", tipo);

        if(strcmp(tipo, "nx")==0)
        {
            fscanf(geo,"%d\n", &max[0]);
        }
        else if(strcmp(tipo, "c")==0)
        {
            fscanf(geo,"%d %lf %lf %lf %s %s\n", &id1, &raio, &x, &y, borda, preenchimento);
            Circulo circulo = criaCirculo(id1, raio, x, y, circleExpessura, borda, preenchimento);
            desenhaCirculo(raio, x, y, borda, preenchimento, nomeSvgGeo);
            insert(listasObjetos[0], circulo);
            
            
            n++;
        }
        else if(strcmp(tipo, "r")==0)
        {
            fscanf(geo,"%d %lf %lf %lf %lf %s %s\n", &id1, &x, &y, &h, &w, borda, preenchimento);
            Retangulo retangulo = criaRetangulo(id1, h, w, x, y, rectExpessura, borda, preenchimento);
            desenhaRetangulo(w, h, x, y, borda, preenchimento, nomeSvgGeo);
            insert(listasObjetos[1], retangulo);
            
            n++;
        }
        else if(strcmp(tipo, "t")==0)
        {   
            fscanf(geo,"%d %lf %lf %s %s", &id1, &x, &y, borda, preenchimento);
            fgets(txt, 255, geo);
            Texto texto = criaTexto(id1, x, y, borda, preenchimento, txt);
            escreveTexto(x, y, borda, preenchimento, strtok(txt,"\n"), nomeSvgGeo);
            insert(listasObjetos[2], texto);

            free(txt);
        }
        else if(strcmp(tipo, "q")==0)
        {
            fscanf(geo,"%s %lf %lf %lf %lf\n", cep, &x, &y, &h, &w);
            Quadra quadra = criaQuadra(cep, x, y, w, h, quaExpessura, Qpreenchimento, Qborda);
            desenhaQuadra(w, h, x, y, borda, preenchimento, cep, nomeSvgGeo);
            insert(listasObjetos[3], quadra);
            
            n++;
        }
        else if(strcmp(tipo, "h")==0)
        {
            fscanf(geo,"%s %lf %lf\n", id2, &x, &y);
            Hidrante hidrante = criaHidrante(id2, x, y, hidraExpessura, Hpreenchimento, Hborda);
            desenhaHidrante(5, x, y, Qborda, Qpreenchimento, nomeSvgGeo);
            insert(listasObjetos[4], hidrante);

            n++;
        }
        else if(strcmp(tipo, "s")==0)
        {
            fscanf(geo,"%s %lf %lf\n", id2, &x, &y);
            Semaforo semaforo = criaSemaforo(id2, x, y, semaExpessura, Spreenchimento, Sborda);
            desenhaSemaforo(5, x, y, Sborda, Spreenchimento, nomeSvgGeo);
            insert(listasObjetos[5], semaforo);
            
            n++;
        }
        else if(strcmp(tipo, "rb")==0)
        {
            fscanf(geo,"%s %lf %lf\n", id2, &x, &y);
            Radiobase radioBase = criaRadiobase(id2, x, y, radioExpessura, RBpreenchimento, RBborda);
            desenhaRadioBase(5, x, y, RBborda, RBpreenchimento, nomeSvgGeo);
            insert(listasObjetos[6], radioBase);
            
            n++;
        }
        else if(strcmp(tipo, "cq")==0)
        {
            fscanf(geo,"%s %s %s\n", expessura, preenchimento, borda);

            strcpy(quaExpessura, expessura);
            strcpy(Qpreenchimento, preenchimento);
            strcpy(Qborda, borda);            
            
            n++;
        }
        else if(strcmp(tipo, "ch")==0)
        {
            fscanf(geo,"%s %s %s\n", expessura, preenchimento, borda);

            strcpy(hidraExpessura, expessura);
            strcpy(Hpreenchimento, preenchimento);
            strcpy(Hborda, borda);            
            
            n++;
        }
        else if(strcmp(tipo, "cr")==0)
        {
            fscanf(geo,"%s %s %s\n", expessura, preenchimento, borda);

            strcpy(radioExpessura, expessura);
            strcpy(RBpreenchimento, preenchimento);
            strcpy(RBborda, borda);  

            n++;
        }
        else if(strcmp(tipo, "cs")==0)
        {
            fscanf(geo,"%s %s %s\n", expessura, preenchimento, borda);
            
            strcpy(semaExpessura, expessura);
            strcpy(Spreenchimento, preenchimento);
            strcpy(Sborda, borda); 

            n++;
        }
        else if(strcmp(tipo, "sw")==0)
        {
            fscanf(geo,"%s %s\n", circleExpessura, rectExpessura);          

            n++;
        }
    }
    
    finalizaSvg(nomeSvgGeo);
    printf("\nArquivo .svg finalizado com sucesso");
    fclose(geo);

}

