#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED



typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    int idSocio;
    int idLibro;
    int dia;
    int mes;
    int anio;


}Prestamos;


#endif // PRESTAMOS_H_INCLUDED

int prestamos_Inicializar(Prestamos array[], int size);                                    //cambiar prestamos
int prestamos_buscarEmpty(Prestamos array[], int size, int* posicion);                    //cambiar prestamos
int prestamos_buscarID(Prestamos array[], int size, int valorBuscado, int* posicion);                    //cambiar prestamos
int prestamos_buscarInt(Prestamos array[], int size, int valorBuscado, int* posicion);                    //cambiar prestamos
int prestamos_buscarString(Prestamos array[], int size, char* valorBuscado, int* indice);                    //cambiar prestamos
int prestamos_alta(Prestamos array[],Socios arraySocios[],Libros arrayLibros[], int size,int sizeSocios, int sizeLibros, int* contadorID);                          //cambiar prestamos
int prestamos_baja(Prestamos array[], int sizeArray);                                      //cambiar prestamos
int prestamos_bajaValorRepetidoInt(Prestamos array[], int sizeArray, int valorBuscado);
int prestamos_modificar(Prestamos array[], int sizeArray);                                //cambiar prestamos
int prestamos_ordenarPorDobleCriterio(Prestamos array[],int size, int orderFirst, int orderSecond);                                  //cambiar prestamos
int prestamos_listar(Prestamos array[], int size);                      //cambiar prestamos



void prestamos_mock(Prestamos arrayPrestamos[], int size,int *contadorId);
