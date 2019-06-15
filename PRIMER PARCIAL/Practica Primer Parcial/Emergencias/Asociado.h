#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    int dni;
    int edad;
    int estado; ///1 habilitado - 0 inhabilitado - (-1) para vacio
    int idAsociado; ///clave unica de identidad univoca
}Asociado;

int asoc_initAsociado(Asociado* pAsociado,int len);

int asoc_add(Asociado* pAsociado,int len,int pIndex,char* msgE,int tries);
int asoc_alter(Asociado* pAsociado, int len,char* msgE,int tries);
int asoc_remove(Asociado* pAsociado, int len,char* msgE,int tries);

int asoc_print(Asociado* pAsociado,int len);


int asoc_findFree(Asociado* pAsociado, int len);
int asoc_findAsocById(Asociado* pAsociado, int len, int idFind);
int asoc_getID (Asociado* pAsociado,int len,char* msgE,int tries, char* msg);






#endif // ASOCIADO_H_INCLUDED
