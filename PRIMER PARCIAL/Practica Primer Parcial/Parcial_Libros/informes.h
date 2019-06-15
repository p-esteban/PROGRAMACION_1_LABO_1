#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

typedef struct
{

    int isEmpty;
    //-----------------
    int contadorDias;
    int dia;
    int mes;
    int anio;

}EAux;

#endif // INFORMES_H_INCLUDED
int Informes_maxContadorAcumulado(Prestamos arrayPrestamos[], EAux arrayEAux[], int sizeI);
int informes_buscarEmpty(EAux array[], int size, int* posicion);
int informes_Inicializar(EAux array[], int size);
int informes_listar(EAux array[], int size) ;
int informes_buscarAnio(EAux array[], int size, int valorBuscado, int* posicion);
