#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

//#define TEXT_SIZE 20
#include "instrumento.h"
#include "orquesta.h"

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int edad;
    int idOrquesta;
    int idInstrumento;


}Musico;


#endif // MUSICO_H_INCLUDED

int musico_Inicializar(Musico array[], int size);
int musico_buscarEmpty(Musico array[], int size, int* posicion);
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);
int musico_alta(Musico array[], int size, Orquesta arrayOrquesta[], int sizeOrquesta, Instrumento arrayInstrumento[],int sizeInstrumento, int* contadorID) ;
int musico_baja(Musico array[], int sizeArray);
int musico_buscarByIdOrquesta(Musico array[], int size, int valorBuscado, int* posicion);
int musico_bajaByIdOrquesta(Musico array[], int sizeArray, int idOrquestaBuscado);
int musico_modificar(Musico array[], int sizeArray);
int musico_ordenarPorApellido(Musico array[],int size, int orderFirst);
int musico_listarConInstrumento(Musico array[], int size,Instrumento arrayInstrumento[], int sizeInstrumento);
int musico_listar(Musico array[], int size);

void musico_mock(Musico arrayMusico[], int size);

int musico_ordenar(Musico array[],int size)  ;


