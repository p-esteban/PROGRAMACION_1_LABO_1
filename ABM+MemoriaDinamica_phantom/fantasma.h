#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#define SIZE_STRING 51

typedef struct
{
    int varId;
    char varChar;
    char varString[SIZE_STRING];
    char varLongString[SIZE_STRING];
    int varInt;
    int varIntDos;
    float varFloat;
    float varFloatDos;
}Fantasma;


#endif // FANTASMA_H_INCLUDED

Fantasma* fantasma_new();
Fantasma* fantasma_newParametros(char* varId,char* varChar,char* varString, char* varLongString,char* varInt,char* varIntDos, char* varFloat,char* varFloatDos);

void fantasma_delete(Fantasma* this);

int fantasma_searchById(LinkedList* pArrayListFantasma, int valorBuscado, int* index);
int fantasma_maxId(LinkedList* pArrayListFantasma, int* maxID);
int fantasma_searchByVarInt(LinkedList* pArrayListFantasma, int valorBuscado, int* index);
int fantasma_searchByVarString(LinkedList* pArrayListFantasma, char* valorBuscado, int* index);
int fantasma_searchByVarFloat(LinkedList* pArrayListFantasma, float valorBuscado, int* index);

int fantasma_criterioSortId(void* this1, void* this2);
int fantasma_criterioSortVarString(void* this1, void* this2);
int fantasma_criterioSortVarFloat(void* this1, void* this2);
int fantasma_criterioSortVarInt(void* this1, void* this2);

int fantasma_criterioFilterVarInt(Fantasma* fantasma);
int fantasma_criterioFilterVarString(Fantasma* fantasma);
int fantasma_criterioFilterVarFloat(Fantasma* fantasma);
int fantasma_print(Fantasma* fantasma);


int fantasma_setIdStr(Fantasma* this, char* varId);
int fantasma_setId(Fantasma* this, int varId);
int fantasma_getIdStr(Fantasma* this, char* result);
int fantasma_getId(Fantasma* this, int* result);

int fantasma_setVarChar(Fantasma* this, char* varChar);
int fantasma_getVarChar(Fantasma* this, char* result);

int fantasma_setVarString(Fantasma* this, char* varString);
int fantasma_getVarString(Fantasma* this, char* result);

int fantasma_setVarLongString(Fantasma* this, char* varLongString);
int fantasma_getVarLongString(Fantasma* this, char* result);

int fantasma_setVarIntStr(Fantasma* this, char* varInt);
int fantasma_setVarInt(Fantasma* this, int varInt);
int fantasma_getVarIntStr(Fantasma* this, char* result);
int fantasma_getVarInt(Fantasma* this, int* result);

int fantasma_setVarIntDosStr(Fantasma* this, char* varIntDos);
int fantasma_setVarIntDos(Fantasma* this, int varIntDos);
int fantasma_getVarIntDosStr(Fantasma* this, char* result);
int fantasma_getVarIntDos(Fantasma* this, int* result);

int fantasma_setVarFloatStr(Fantasma* this, char* varFloat);
int fantasma_setVarFloat(Fantasma* this, float varFloat);
int fantasma_getVarFloatStr(Fantasma* this, char* result);
int fantasma_getVarFloat(Fantasma* this, float* result);

int fantasma_setVarFloatDosStr(Fantasma* this, char* varFloatDos);
int fantasma_setVarFloatDos(Fantasma* this, float varFloatDos);
int fantasma_getVarFloatDosStr(Fantasma* this, char* result);
int fantasma_getVarFloatDos(Fantasma* this, float* result);





