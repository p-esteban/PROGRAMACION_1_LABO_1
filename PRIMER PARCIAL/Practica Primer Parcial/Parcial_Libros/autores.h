#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

#define TEXT_SIZE 31

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];

}Autores;


#endif // FANTASMA_H_INCLUDED

int autores_Inicializar(Autores array[], int size);                                    //cambiar autores
int autores_buscarEmpty(Autores array[], int size, int* posicion);                    //cambiar autores
int autores_buscarID(Autores array[], int size, int valorBuscado, int* posicion);                    //cambiar autores
int autores_buscarInt(Autores array[], int size, int valorBuscado, int* posicion);                    //cambiar autores
int autores_buscarString(Autores array[], int size, char* valorBuscado, int* indice);                    //cambiar autores
int autores_alta(Autores array[], int size, int* contadorID);                          //cambiar autores
int autores_baja(Autores array[], int sizeArray);                                      //cambiar autores
int autores_bajaValorRepetidoInt(Autores array[], int sizeArray, int valorBuscado);
int autores_modificar(Autores array[], int sizeArray);                                //cambiar autores
int autores_ordenarPorDobleCriterio(Autores array[],int size, int orderFirst, int orderSecond);                                  //cambiar autores
int autores_listar(Autores array[], int size);                      //cambiar autores

void autores_mock(Autores arrayAutores[], int size,int *contadorIdautores);



