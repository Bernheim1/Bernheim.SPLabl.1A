#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    int recuperados;
    int infectados;
    int muertos;
}ePais;

#endif // PAISES_H_INCLUDED

//SETTER Y GETTER
int pais_setId(ePais* this,int id);
int pais_getId(ePais* this,int* id);
int pais_setNombre(ePais* this,char* nombre);
int pais_getNombre(ePais* this,char* nombre);
int pais_setRecuperados(ePais* this,int recuperados);
int pais_getRecuperados(ePais* this,int* recuperados);
int pais_setInfectados(ePais* this,int infectados);
int pais_getInfectados(ePais* this,int* infectados);
int pais_setMuertos(ePais* this,int muertos);
int pais_getMuertos(ePais* this,int* muertos);

//CONSTRUCTORES
ePais* pais_new();
ePais* pais_newParamS(char* idStr, char* nombreStr, char* recuperadosStr,char* infectadosStr,char* muertosStr);
ePais* pais_newParametros(int id,char* nombre,int recuperados,int infectados,int muertos);

//ASIGNAR
int getRandomMuertos();
int getRandomInfectados();
int getRandomRecuperados();
void* asignarCamposPiases(void* pElement);
int pais_setCampos(LinkedList* lista);
void settearMuertos(void* element);
void settearInfectados(void* element);
void settearRecuperados(void* element);





