
#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

#include "Socios.h"
#include "Libros.h"

typedef struct
{
    int idPrestamo;
    int idLibro;
    int idSocio;
    int dia;
    int mes;
    int ano;
    int isEmpty;
}Prestamo;

int prestamo_init(Prestamo* pPrestamo,int len);

int prestamo_add(Prestamo* pPrestamo,Libro* pLibro,Socio* pSocio, int len,int pIndex,char* msgE,int tries);

//int libro_alter(Prestamo* pPrestamo, int len,char* msgE,int tries);
//int libro_remove(Libro* pLibro, int len,char* msgE,int tries);

int prestamo_print(Prestamo* pPrestamo,int len);


int prestamo_findFree(Prestamo* pPrestamo, int len);
int prestamo_findPrestamoById(Prestamo* pPrestamo, int len, int idFind);
int prestamo_getID (Prestamo* pPrestamo,int len,char* msgE,int tries, char* msg);




#endif // PRESTAMOS_H_INCLUDED
