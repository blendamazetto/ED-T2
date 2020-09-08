#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerQry.h"

void lerQry (char saidaQry[], Lista listasObjetos, char arqQry[])
{
    char* saidaTxt = malloc((5 + strlen(saidaQry))*sizeof(char));
    char* saidaSvg = malloc((5 + strlen(saidaQry))*sizeof(char));
    sprintf(saidaTxt,"%s.txt",saidaQry);
    sprintf(saidaSvg,"%s.svg",saidaQry);

    FILE* qry = fopen(arqQry,"r");
    FILE* saida = fopen(saidaTxt,"w");

    iniciaSvg(saidaSvg);

    if(saida == NULL || qry == NULL)
    {
        printf("Erro ao abrir o QRY ou ao gerar o TXT\n");
        exit(1);
    }

    int j;
    int k;
    int ident;
    double x;
    double y;
    char tipo[5];
    char corb[20];
    char corp[20];
    char identificacao[20];
    double r;
    char parametroOpcional[1];
    double w, h;


    while(fscanf(qry,"%s",tipo) != EOF)
    {
        if(strcmp(tipo,"o?") == 0)
        {
            fscanf(qry,"%d %d",&j,&k);
            fprintf(saida,"%s %d %d\n",tipo,j,k);
            o(j, k, saida, saidaSvg, listasObjetos);
        }
        else if(strcmp(tipo,"i?") == 0)
        {
            fscanf(qry,"%d %lf %lf",&j,&x,&y);
            fprintf(saida,"%s %d %lf %lf\n",tipo,j,x,y);
            i(listasObjetos, j, x, y, saidaSvg, saida);
        }
        else if(strcmp(tipo,"pnt") == 0)
        {
            fscanf(qry,"%d %s %s",&j,corb,corp);
            fprintf(saida,"%s %d %s %s\n",tipo,j,corb,corp);
            pnt (listasObjetos, j, corb, corp, saida);

        }
        else if(strcmp(tipo,"pnt*") == 0)
        {
            fscanf(qry,"%d %d %s %s",&j,&k,corb,corp);
            fprintf(saida,"%s %d %d %s %s\n",tipo,j,k,corb,corp);
            pnt (listasObjetos, j, corb, corp, saida);
            pnt (listasObjetos, k, corb, corp, saida);
        }
        else if(strcmp(tipo,"delf") == 0)
        {
            fscanf(qry,"%d",&j);
            fprintf(saida,"%s %d\n",tipo,j);
            delf(listasObjetos, j, saida);
        }
        else if(strcmp(tipo,"delf*") == 0)
        {
            fscanf(qry,"%d %d",&j,&k);
            fprintf(saida,"%s %d %d\n",tipo,j,k);
            delf(listasObjetos, j, saida);
            delf(listasObjetos, k, saida);
        }
       else if(strcmp(tipo, "dq") == 0) 
        {
            
            fscanf(qry,"%s", parametroOpcional);

             if(strcmp(parametroOpcional,"#")==0)
            {
                ident=1;
                fscanf(qry,"%s %lf",identificacao, &r);
                fprintf(saida,"%s %s %lf\n",tipo, identificacao, r);
            }
            else
            {
                ident=0;
                fscanf(qry,"%lf", &r);
                strcpy(identificacao, parametroOpcional);
                fprintf(saida,"dq %s %lf\n",identificacao, r);
            }
            dq(listasObjetos, saida, saidaSvg, identificacao, r, ident);
        }
        else if(strcmp(tipo, "del")==0)
        {
            fscanf(qry,"%s",identificacao);
            fprintf(saida,"%s %s\n",tipo, identificacao);
            del(listasObjetos, identificacao, saida, saidaSvg);
        }
        else if(strcmp(tipo, "cbq")==0)
        {
            fscanf(qry,"%lf %lf %lf %s",&x, &y, &r, corb);
            fprintf(saida,"%s %lf %lf %lf %s\n",tipo,x, y, r, corb);
            cbq(listasObjetos, x, y, r, corb, saida);
        }
        else if(strcmp(tipo, "crd?")==0)
        {
            fscanf(qry,"%s",identificacao);
            fprintf(saida,"%s %s\n",tipo, identificacao);
            crd(listasObjetos, identificacao, saida);
        }
        else if(strcmp(tipo, "car")==0)
        {
            fscanf(qry,"%lf %lf %lf %lf",&x, &y, &w, &h);
            fprintf(saida,"%s %lf %lf %lf %lf\n",tipo, x, y, w, h);
            car(listasObjetos, x, y, w, h, saidaSvg, saida);
        }
    }

    gerarSvgQry(listasObjetos, saidaSvg);

    finalizaSvg(saidaSvg);

    fclose(saida);
    fclose(qry);
    free(saidaSvg);
    free(saidaTxt);
}