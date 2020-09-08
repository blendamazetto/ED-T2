#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerGeo.h"
#include "lista.h"
#include "lerQry.h"


char *concatenacao(char dir_entrada[])
{	
	char* arqGeoConcatenado = NULL;
    char* aux = strrchr(dir_entrada,'/');
    if(aux == NULL)
	{
		arqGeoConcatenado=strtok(dir_entrada,".");
        return(arqGeoConcatenado);
    }
	arqGeoConcatenado=strtok(&aux[1],".");
	return(arqGeoConcatenado);

}

int main (int argc, char *argv[])
{
    Lista listasObjetos[7];

    for (int i = 0; i < 7; i++)
    {
        listasObjetos[i] = create();
    }
    
    char *dir_entrada = NULL;
    char *arq_geoNome = NULL;
    char *arq_consulta = NULL;
    char *dir_saida = NULL;
    char *arqGeo = NULL;
    char *arqQry = NULL;
    char *nomeSvgGeo = NULL;
    char *nomeGeo = NULL;
    char *nomeQry = NULL;
    char *saidaQry = NULL;   
    char *saida = NULL;


    int i;
    for(i=1;i<argc;i++)
    {
        if(strcmp("-e", argv[i]) == 0 )
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nDiretorio de entrada nao encontrado\n");
                exit(1);
            }
            dir_entrada = (char*) malloc(strlen((argv[i]) + 1)*sizeof (char));
            strcpy(dir_entrada,argv[i]);
        }

        else if(strcmp("-f", argv[i]) == 0)
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nParametro nao foi encontrado em -f\n");
                exit(1);
            }
            arq_geoNome = (char*) malloc( strlen((argv[i]) + 1)*sizeof (char));
            strcpy(arq_geoNome,argv[i]);
        
        }
        else if(strcmp("-q", argv[i]) == 0)
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nParametro nao foi econtrado em -q\n");
                exit(1);
            }

            arq_consulta = (char*) malloc( strlen((argv[i]) + 1)*sizeof (char));
            strcpy(arq_consulta,argv[i]);

        }

        else if(strcmp("-o", argv[i]) == 0)
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nDiretorio de saida nao foi econtrado\n");
                exit(1);
            }
            dir_saida = (char*) malloc( strlen((argv[i]) + 1)*sizeof (char));
            strcpy(dir_saida,argv[i]);      
        }
    }
    if(arq_geoNome == NULL || dir_saida == NULL)
    {
        printf("\nERRO\nArgumento essencial nao inserido\n");
        exit(1);
    }
    else if (dir_entrada != NULL) 
    {
        if(dir_entrada[strlen(dir_entrada) - 1] != '/')
        {
            arqGeo = (char *)malloc((strlen(arq_geoNome)+strlen(dir_entrada)+2)*sizeof(char));
    	    sprintf(arqGeo,"%s/%s",dir_entrada,arq_geoNome);
        }
		else
        {
            arqGeo = (char *)malloc((strlen(arq_geoNome)+strlen(dir_entrada)+1)*sizeof(char));
    	    sprintf(arqGeo,"%s%s",dir_entrada,arq_geoNome);
        }
        if (arq_consulta!= NULL)
        {
            arqQry = (char *)malloc((strlen(arq_consulta)+strlen(dir_entrada)+2)*sizeof(char));
            sprintf(arqQry,"%s/%s",dir_entrada,arq_consulta);
        }
	} 
    else 
    {
		arqGeo = (char *)malloc((strlen(arqGeo)+1)*sizeof(char));
    	strcpy(arqGeo, arq_geoNome);

        if(arq_consulta!= NULL)
        {
            arqQry = (char *)malloc((strlen(arq_consulta)+1)*sizeof(char));
            strcpy(arqQry, arq_consulta);
        }
	}
    nomeGeo = concatenacao(arq_geoNome);
    if (dir_saida[strlen(dir_saida) - 1] == '/')
    {
        saida = (char*)malloc((strlen(nomeGeo) + strlen(dir_saida) + 1)*sizeof(char));
        sprintf(saida,"%s%s",dir_saida,nomeGeo);
    }
    else
    {
        saida = (char*)malloc((strlen(nomeGeo) + strlen(dir_saida) + 2)*sizeof(char));
        sprintf(saida,"%s/%s",dir_saida,nomeGeo);
    }
    nomeSvgGeo = (char*)malloc((strlen(saida) + 5)*sizeof(char));
    sprintf(nomeSvgGeo,"%s.svg",saida);

    lerGeo(arqGeo,nomeSvgGeo, listasObjetos);

    if (arq_consulta!= NULL)
    {
        nomeQry = concatenacao(arq_consulta);
        saidaQry = (char*)malloc((strlen(dir_saida) + strlen(saida) + 2)*sizeof(char));
        sprintf(saidaQry,"%s-%s",saida,nomeQry);

        lerQry (saidaQry,listasObjetos,arqQry);
    }

   free(dir_entrada);
   free(arq_geoNome);
   free(arq_consulta);
   free(dir_saida);
   free(arqGeo);
   free(arqQry);
   free(nomeSvgGeo);
   free(nomeGeo);
   free(nomeQry);
   free(saidaQry);   
   free(saida);

   for (int i = 0; i < 7; i++)
    {
        removeList(listasObjetos[i]);
    }  

}