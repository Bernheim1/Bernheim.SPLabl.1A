#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

//LISTAR

int mostrarPaises( LinkedList* lista);
void mostrarPais( LinkedList* lista,int indice);

//FILTRAR
int filtrar_PaisesExitosos(LinkedList* lista);
int comparaMuertos(void* pais);

int filtrar_PaisesHorno(LinkedList* lista);
int comparaPaisesHorno(void* pais);

//ORDENAR
int ordenarPises(LinkedList* lista);
int pais_comparaIfectados(void* a, void* b);

//MOSTRAR MAS CASTIGADO
void mostrarMasCastigados(LinkedList* lista);
