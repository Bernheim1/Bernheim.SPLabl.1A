#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "paises.h"
#include "parser.h"
#include "informes.h"


int pais_setId(ePais* this,int id)
{
    int todoOk = 1;
    if(this != NULL && id>0)
    {
        this->id = id;
        todoOk=0;
    }
    return todoOk;
}

int pais_getId(ePais* this,int* id)
{
    int todoOk = 1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 0;
    }
    return todoOk;
}

int pais_setNombre(ePais* this,char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL && strlen(nombre) <= 50)
    {
        strcpy(this->nombre,nombre);
        todoOk = 0;
    }
    return todoOk;
}

int pais_getNombre(ePais* this,char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 0;
    }
    return todoOk;
}

int pais_setRecuperados(ePais* this,int recuperados)
{
    int todoOk = 1;

    if(this != NULL && recuperados >= 0)
    {
        this->recuperados = recuperados;
        todoOk = 0;
    }
    return todoOk;
}

int pais_getRecuperados(ePais* this,int* recuperados)
{
    int todoOk = 1;

    if(this != NULL && recuperados != NULL)
    {
        *recuperados = this->recuperados;
        todoOk = 0;
    }
    return todoOk;
}

int pais_setInfectados(ePais* this,int infectados)
{
    int todoOk = 1;

    if(this != NULL && infectados >= 0)
    {
        this->infectados = infectados;
        todoOk = 0;
    }
    return todoOk;
}

int pais_getInfectados(ePais* this,int* infectados)
{
    int todoOk = 1;

    if(this != NULL && infectados != NULL)
    {
        *infectados = this->infectados;
        todoOk = 0;
    }
    return todoOk;
}

int pais_setMuertos(ePais* this,int muertos)
{
    int todoOk = 1;

    if(this != NULL && muertos >= 0)
    {
        this->muertos = muertos;
        todoOk = 0;
    }
    return todoOk;
}

int pais_getMuertos(ePais* this,int* muertos)
{
    int todoOk = 1;

    if(this != NULL && muertos != NULL)
    {
        *muertos = this->muertos;
        todoOk = 0;
    }
    return todoOk;
}

ePais* pais_new()
{
    ePais* newPais = (ePais*) malloc(sizeof(ePais));

    return newPais;
}

ePais* pais_newParamS(char* idStr, char* nombreStr, char* recuperadosStr,char* infectadosStr,char* muertosStr)
{
    return pais_newParametros(atoi(idStr),nombreStr,atoi(recuperadosStr),atoi(infectadosStr),atoi(muertosStr));
}

ePais* pais_newParametros(int id,char* nombre,int recuperados,int infectados,int muertos)
{
    ePais* newPais = pais_new();

    if(newPais != NULL)
    {
        pais_setId(newPais,id);
        pais_setNombre(newPais,nombre);
        pais_setRecuperados(newPais,recuperados);
        pais_setInfectados(newPais,infectados);
        pais_setMuertos(newPais,muertos);
    }
    else
    {
        free(newPais);
        newPais = NULL;
    }
    return newPais;
}

int getRandomMuertos()
{
    int muertos;

    muertos = rand()% (50000) + 1001;

    return muertos;
}

int getRandomInfectados()
{
    int infectados;

    infectados = rand()% (2000000) + 40001 ;

    return infectados;
}

int getRandomRecuperados()
{
    int recuperados;

    recuperados = rand()% (100000) + 50001;

    return recuperados;
}

void* asignarCamposPiases(void* pElement)
{
    ePais* auxPais;
    auxPais = (ePais*) pElement;

    settearRecuperados(auxPais);
    settearInfectados(auxPais);
    settearMuertos(auxPais);

    return auxPais;
}

int pais_setCampos(LinkedList* lista)
{
    int todoOk = 1;
    LinkedList* listaAsignada;

    if(lista != NULL)
    {
        listaAsignada = ll_map(lista,asignarCamposPiases);
        if(listaAsignada != NULL)
        {
            todoOk = 0;
            printf("Se asignaron los campos a los paises\n");
        }
        else
        {
            printf("No se pudieron asignar los campos a los paises\n");
        }
    }
    return todoOk;
}

void settearMuertos(void* element)
{
    ePais* muertos = NULL;

    if(element!=NULL)
    {
        muertos = (ePais*) element;
        pais_setMuertos(muertos, getRandomMuertos());

    }

}

void settearInfectados(void* element)
{
    ePais* infectado = NULL;

    if(element!=NULL)
    {
        infectado = (ePais*)element;
        pais_setInfectados(infectado, getRandomInfectados());

    }

}

void settearRecuperados(void* element)
{
    ePais* recuperados = NULL;

    if(element!=NULL)
    {
        recuperados = (ePais*) element;
        pais_setRecuperados(recuperados, getRandomRecuperados());

    }
}

