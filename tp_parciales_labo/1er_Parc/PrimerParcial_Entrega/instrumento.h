#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED


#define TEXT_SIZE 50

typedef struct
{
    int idUnico;
    int isEmpty;//1 vacio - 0 ocupado
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo;// 1- cuerdas  2-viento-madera 3-viento metal 4-percusion



}Instrumento;


#endif // INSTRUMENTO_H_INCLUDED

int instrumento_Inicializar(Instrumento array[], int size);
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion);
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion);
int instrumento_alta(Instrumento array[], int size, int* contadorID);
int instrumento_baja(Instrumento array[], int sizeArray);
int instrumento_listar(Instrumento array[], int size);


void instrumento_mock(Instrumento arrayInstrumento[], int size);


void instrumento_tipoStr(Instrumento array[],int posicion, char* tipoInstrumento);

