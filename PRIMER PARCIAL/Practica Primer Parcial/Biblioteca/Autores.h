#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct
{
    int idAutores;
    char apellido[31];
    char nombre[31];
    int isEmpty;
}Autores;

int autores_init(Autores* pAutores,int len);

int autores_add(Autores* pAutores,int len,int pIndex,char* msgE,int tries);

int autores_alter(Autores* pAutores, int len,char* msgE,int tries);
int autores_remove(Autores* pAutores, int len,char* msgE,int tries);

int autores_print(Autores* pAutores,int len);


int autores_findFree(Autores* pAutores, int len);
int autores_findAutorById(Autores* pAutores, int len, int idFind);
int autores_getID(Autores* pAutores,int len,char* msgE,int tries, char* msg);



#endif // AUTORES_H_INCLUDED
