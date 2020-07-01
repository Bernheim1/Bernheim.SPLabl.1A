#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "paises.h"
#include "parser.h"
#include "informes.h"

int mostrarPaises( LinkedList* lista)
{
    int todoOk = 1;
    int tam;

    if(lista != NULL)
    {
        todoOk = 0;
        printf("  ID      NOMBRE                RECUPERADOS           INFECTADOS              MUERTOS\n");
        tam = ll_len(lista);

        for (int i=0; i<tam; i++)
        {
            mostrarPais(lista, i);
        }
    }
    else
    {
        printf("No hay articulos que listar\n");
    }
    return todoOk;
}

void mostrarPais( LinkedList* lista,int indice)
{
    ePais* pais;

    pais = ll_get(lista, indice);

    printf("%4d     %-20s      %-10d           %-10d             %-10d\n", pais->id, pais->nombre,pais->recuperados, pais->infectados,pais->muertos);

}

int filtrar_PaisesExitosos(LinkedList* lista)
{
    int todoOk = 1;
    LinkedList* listaFiltrada;

    if(lista != NULL)
    {
        listaFiltrada = ll_filter(lista,comparaMuertos);
        if(listaFiltrada != NULL)
        {
            if(!controller_saveAsText("paisesExitosos.csv",listaFiltrada))
            {
                todoOk = 0;
                printf("Se creo el archivo paisesExitosos.csv\n");
            }
            else
            {
                printf("No se pudo crear el archivo con los paises filtrados\n");
            }

        }
        else
        {
            printf("No se pudo acceder a la lista\n");
        }
    }
    return todoOk;
}

int comparaMuertos(void* pais)
{
    int todoOk = 1;
    ePais* auxPais;
    int auxMuertos;

    if(pais != NULL)
    {
        auxPais = (ePais*) pais;
        pais_getMuertos(auxPais,&auxMuertos);
        if(auxMuertos < 5000)
        {
            todoOk = 0;
        }
    }
    return todoOk;
}

int filtrar_PaisesHorno(LinkedList* lista)
{
    int todoOk = 1;
    LinkedList* listaFiltrada;

    if(lista != NULL)
    {
        listaFiltrada = ll_filter(lista,comparaPaisesHorno);
        if(listaFiltrada != NULL)
        {
            if(!controller_saveAsText("paisesHorno.csv",listaFiltrada))
            {
                todoOk = 0;
                printf("Se creo el archivo paisesHorno.csv\n");
            }
            else
            {
                printf("No se pudo crear el archivo con los paises filtrados\n");
            }

        }
        else
        {
            printf("No se pudo acceder a la lista\n");
        }
    }
    return todoOk;
}

int comparaPaisesHorno(void* pais)
{
    int todoOk = 1;
    ePais* auxPais;
    int auxInfectados;
    int auxRecuperados;


    if(pais != NULL)
    {
        auxPais = (ePais*) pais;
        pais_getInfectados(auxPais,&auxInfectados);
        pais_getRecuperados(auxPais,&auxRecuperados);
        if(auxInfectados > auxRecuperados * 3)
        {
            todoOk = 0;
        }
    }
    return todoOk;
}

int ordenarPises(LinkedList* lista)
{
    int todoOk = 1;

    if(lista != NULL)
    {

        if(!ll_sort(lista,pais_comparaIfectados,0))
        {
            system("cls");
            mostrarPaises(lista);
            todoOk = 0;
        }
        else
        {
            printf("No se pudieron ordenar los paises\n");
        }
    }

    return todoOk;
}

int pais_comparaIfectados(void* a, void* b)
{
    int returnAux=0;
    ePais* e1;
    ePais* e2;

    if(a != NULL && b != NULL)
    {
        e1 = (ePais*)a;
        e2 = (ePais*)b;

        if(e1->infectados > e2->infectados)
        {
            returnAux=1;
        }
        else
        {
            if(e1->infectados < e2->infectados)
            {
                returnAux= -1;
            }
        }
    }
    return returnAux;
}

void mostrarMasCastigados(LinkedList* lista)
{
    ePais* auxPais;
    int auxMuertos;
    int maxMuertos = 0;
    int flag = 0;

    if(lista != NULL)
    {

        for(int i = 0; i < ll_len(lista); i++)
        {
            auxPais = (ePais*) ll_get(lista,i);
            pais_getMuertos(auxPais,&auxMuertos);
            if(auxMuertos > maxMuertos || !flag)
            {
                maxMuertos = auxMuertos;
                flag = 1;
            }
        }

        printf("MAYOR CANTIDAD DE MUERTOS: %d\n",maxMuertos);
        printf("  ID      NOMBRE                RECUPERADOS           INFECTADOS              MUERTOS\n");

        for(int i = 0; i < ll_len(lista); i++)
        {
            auxPais = (ePais*) ll_get(lista,i);
            pais_getMuertos(auxPais,&auxMuertos);

            if(auxMuertos >= maxMuertos)
            {
                mostrarPais(lista,i);
            }
        }

    }

}
