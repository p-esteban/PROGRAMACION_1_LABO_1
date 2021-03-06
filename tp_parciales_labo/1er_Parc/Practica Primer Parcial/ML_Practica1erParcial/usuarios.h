#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];//nombre varString
    int calificacion;//calificacion
    char password[TEXT_SIZE];// pass

}Usuario;



#endif // USUARIOS_H_INCLUDED


int usuario_Inicializar(Usuario array[], int size);                                    //cambiar usuario
int usuario_buscarEmpty(Usuario array[], int size, int* posicion);                    //cambiar usuario
int usuario_buscarID(Usuario array[], int size, int valorBuscado, int* posicion);                    //cambiar usuario
int usuario_buscarInt(Usuario array[], int size, int valorBuscado, int* posicion);                    //cambiar usuario
int usuario_buscarString(Usuario array[], int size, char* valorBuscado, int* indice);                    //cambiar usuario
int usuario_alta(Usuario array[], int size, int* contadorID);                          //cambiar usuario
int usuario_baja(Usuario array[], int sizeArray);                                      //cambiar usuario
int usuario_bajaValorRepetidoInt(Usuario array[], int sizeArray, int valorBuscado);
int usuario_modificar(Usuario array[], int sizeArray);                                //cambiar usuario
int usuario_ordenarPorDobleCriterio(Usuario array[],int size, int orderFirst, int orderSecond);                                  //cambiar usuario
int usuario_listar(Usuario array[], int size);                      //cambiar usuario

void usuario_mock(Usuario array[], int size,int *contadorId);

