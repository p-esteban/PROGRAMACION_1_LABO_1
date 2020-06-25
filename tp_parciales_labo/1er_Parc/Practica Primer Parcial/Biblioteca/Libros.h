#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct
{
    int idLibro;
    char titulo[51];
    int idAutor;
    int isEmpty;
}Libro;

int libro_init(Libro* pLibro,int len);

int libro_add(Libro* pLibro,Autores* pAutores,int len,int pIndex,char* msgE,int tries);

int libro_alter(Libro* pLibro,Autores* pAutores, int len,char* msgE,int tries);
int libro_remove(Libro* pLibro, int len,char* msgE,int tries);

int libro_print(Libro* pLibro,int len);


int libro_findFree(Libro* pLibro, int len);
int libro_findLibroById(Libro* pLibro, int len, int idFind);
int libro_getID (Libro* pLibro,int len,char* msgE,int tries, char* msg);




#endif // LIBROS_H_INCLUDED
