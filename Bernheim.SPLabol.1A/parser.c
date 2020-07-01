#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "paises.h"
#include "parser.h"


int controller_loadFromText(LinkedList* pArrayListPaises)
{
    int todoOk = 1;
    char path[128];

    printf("Ingrese el nombre del archivo a cargar: ");
    fflush(stdin);
    scanf("%s",path);

    strcat(path,".csv");


    FILE* f = fopen(path,"r");

    if(f != NULL)
    {
        if(parser_PaisesFromTxt(f,pArrayListPaises))
        {
            todoOk = 0;
            printf("Se cargaron los datos\n");
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f);

    return todoOk;
}

int parser_PaisesFromTxt(FILE* pFile, LinkedList* pArrayListPaises)
{
    int todoOk = 0;
    int cant;
    ePais* auxPais;
    if (pFile == NULL || pArrayListPaises == NULL)
    {
        return todoOk;
    }
    else
    {
        ll_clear(pArrayListPaises);

        char buffer[5][128];

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]",buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

        while(!feof(pFile))
        {


            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);
            if (cant == 5)
            {
                auxPais = pais_newParamS(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

                if (auxPais != NULL)
                {
                    ll_add(pArrayListPaises, auxPais);
                    todoOk = 1;
                }
            }

        }

    }



    return todoOk;

}

int controller_saveAsText(char* path , LinkedList* pArrayListPaises)
{
	int todoOk = 1;

	FILE* pFile;
	int auxId;
	char auxNombre[51];
	int auxRecuperados;
	int auxInfectados;
	int auxMuertos;
	ePais* auxPais;

	if(pArrayListPaises != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			todoOk = 0;
			fprintf(pFile, "id,nombre,recuperados,infectados,muertos\n");
			for(int i = 0; i < ll_len(pArrayListPaises); i++)
			{
				auxPais = (ePais*) ll_get(pArrayListPaises, i);
				if(!pais_getId(auxPais, &auxId) &&
				   !pais_getNombre(auxPais, auxNombre) &&
                   !pais_getRecuperados(auxPais,&auxRecuperados) &&
				   !pais_getInfectados(auxPais, &auxInfectados) &&
                   !pais_getMuertos(auxPais,&auxMuertos))
				{
					fprintf(pFile, "%d,%s,%d,%d,%d\n", auxId, auxNombre,auxRecuperados,auxInfectados,auxMuertos);
				}
			}
			fclose(pFile);
			printf("Se guardaron los datos en el archivo\n");
		}
	}

    return todoOk;
}
