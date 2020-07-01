#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED



#endif // ARCHIVOS_H_INCLUDED


int controller_saveAsText(char* path , LinkedList* pArrayListPaises);
int controller_loadFromText(LinkedList* pArrayListPaises);
int parser_PaisesFromTxt(FILE* pFile, LinkedList* pArrayListPaises);
