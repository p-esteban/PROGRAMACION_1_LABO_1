#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    int idUsuario;
    char varString[TEXT_SIZE];//nombre
    int varInt;//stock
    float varFloat;// precio
    int cantVendidos;//cant vendido

}Producto;


#endif // PRODUCTOS_H_INCLUDED

int producto_Inicializar(Producto array[], int size);                                    //cambiar producto
int producto_buscarEmpty(Producto array[], int size, int* posicion);                    //cambiar producto
int producto_buscarID(Producto array[], int size, int valorBuscado, int* posicion);                    //cambiar producto
int producto_buscarInt(Producto array[], int size, int valorBuscado, int* posicion);                    //cambiar producto
int producto_buscarString(Producto array[], int size, char* valorBuscado, int* indice);                    //cambiar producto
int producto_alta(Producto array[],Usuario arrayUsuario[], int size, int sizeUsuario, int* contadorID);                          //cambiar producto
int producto_baja(Producto array[], int sizeArray);                                      //cambiar producto
int producto_bajaValorRepetidoInt(Producto array[], int sizeArray, int valorBuscado);
int producto_modificar(Producto array[], int sizeArray);                                //cambiar producto
int producto_ordenarPorDobleCriterio(Producto array[],int size, int orderFirst, int orderSecond);                                  //cambiar producto
int producto_listar(Producto array[], int size);                      //cambiar producto


int producto_comprar(Producto array[],Usuario arrayUsuario[],int sizeUsuario, int sizeArray) ;


