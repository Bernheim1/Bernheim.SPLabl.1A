#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "paises.h"
#include "parser.h"
#include "informes.h"




int menuPrincipal();




//COUNT
void contarArticulos(LinkedList* lista);
int menuContadores();
int contarArtCuidado(void* pElement);
int contarArtLimpieza(void* pElement);
int contarArtPersonal(void* pElement);
int contarArtAutomotor(void* pElement);


int main()
{
    LinkedList* lista = ll_newLinkedList();
    char seguir = 's';
    char confirma;
    int flagCarga = 0;
    srand (time(NULL));


    do
    {
        switch(menuPrincipal())
        {
       case 1:
           //CARGAR LOS DATOS
            if(controller_loadFromText(lista)==0)
            {
                flagCarga = 1;
            }
        break;
       case 2:
           //LISTAR
            if(flagCarga)
            {
                system("cls");
                mostrarPaises(lista);
            }
            else
            {
                printf("Debe cargar los paises para poder listarlos\n");
            }
        break;
       case 3:
           //ASIGNAR ESTADISTICAS
            if(flagCarga)
            {
               pais_setCampos(lista);
            }
            else
            {
                printf("Debe cargar los paises para poder asignarle estadisticas\n");
            }
        break;
       case 4:
           //FILTRAR POR EXITOSOS
            if(flagCarga)
            {
                filtrar_PaisesExitosos(lista);
            }
            else
            {
                printf("Debe cargar los paises para poder filtrarlos\n");
            }
        break;
       case 5:
           //FILTRAR POR EN EL HORNO
            if(flagCarga)
            {
                filtrar_PaisesHorno(lista);
            }
            else
            {
                printf("Debe cargar los paises para poder filtrarlos\n");
            }
        break;
       case 6:
           //ORDENAR POR NIVEL DE INFECCION
            if(flagCarga)
            {
                ordenarPises(lista);
            }
            else
            {
                printf("Debe cargar los paises para poder ordenarlos\n");
            }
        break;
       case 7:
           //MOSTRAR MAS CASTIGADO
            if(flagCarga)
            {
                mostrarMasCastigados(lista);
            }
            else
            {
                printf("Debe cargar los paises para poder listar los mas castigados\n");
            }
        break;
       case 8:
           //SALIR
            printf("Confirma salida: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
        break;
       default:
        printf("Ingrese una opcion valida\n");
        }
        system("pause");
    }while(seguir=='s');

    ll_deleteLinkedList(lista);
    return 0;
}



int menuPrincipal()
{
    int opcion;
    system("cls");
    printf("\t**** MENU DE OPCIONES ****\n\n");
    printf("1- Cargar archivo (Modo texto)\n");
    printf("2- Imprimir lista\n");
    printf("3- Asignar estadisticas\n");
    printf("4- Filtrar por paises exitosos\n");
    printf("5- Filtrar por paises en el horno\n");
    printf("6- Ordenar por nivel de infeccion\n");
    printf("7- Mostrar pais mas castigado\n");
    printf("8- Salir\n\n");

    printf("Indique la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);


    return opcion;
}


