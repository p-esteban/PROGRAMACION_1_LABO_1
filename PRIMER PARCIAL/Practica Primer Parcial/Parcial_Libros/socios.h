#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

#define TEXT_SIZE_SOCIO 31

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE_SOCIO];
    char sexo[2];
    char apellido[TEXT_SIZE_SOCIO];
    char telefono[16];
    char email[TEXT_SIZE_SOCIO];
    int dia;
    int mes;
    int anio;


}Socios;


#endif // FANTASMA_H_INCLUDED

int socios_Inicializar(Socios array[], int size);                                    //cambiar socios
int socios_buscarEmpty(Socios array[], int size, int* posicion);                    //cambiar socios
int socios_buscarID(Socios array[], int size, int valorBuscado, int* posicion);                    //cambiar socios
int socios_buscarInt(Socios array[], int size, int valorBuscado, int* posicion);                    //cambiar socios
int socios_buscarString(Socios array[], int size, char* valorBuscado, int* indice);                    //cambiar socios
int socios_alta(Socios array[], int size, int* contadorID);                          //cambiar socios
int socios_baja(Socios array[], int sizeArray);                                      //cambiar socios
int socios_bajaValorRepetidoInt(Socios array[], int sizeArray, int valorBuscado);
int socios_modificar(Socios array[], int sizeArray);                                //cambiar socios
int socios_ordenarPorDobleCriterio(Socios array[],int size, int orderFirst, int orderSecond);                                  //cambiar socios
int socios_listar(Socios array[], int size);                      //cambiar socios


void socios_mock(Socios arraySocios[], int size,int *contadorId);


