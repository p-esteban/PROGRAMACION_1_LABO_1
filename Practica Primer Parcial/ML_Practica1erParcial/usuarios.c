#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "usuarios.h"
#include "productos.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array usuario Array of usuario
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int usuario_Inicializar(Usuario array[], int size)                                    //cambiar usuario
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array usuario Array de usuario
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int usuario_buscarEmpty(Usuario array[], int size, int* posicion)                    //cambiar usuario
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array usuario Array de usuario
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int usuario_buscarID(Usuario array[], int size, int valorBuscado, int* posicion)                    //cambiar usuario
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array usuario Array de usuario
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int usuario_buscarInt(Usuario array[], int size, int valorBuscado, int* posicion)                    //cambiar usuario
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].calificacion==valorBuscado)                                                   //cambiar campo calificacion
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array usuario Array de usuario
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int usuario_alta(Usuario array[], int size, int* contadorID)                          //cambiar usuario
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(usuario_buscarEmpty(array,size,&posicion)==-1)                          //cambiar usuario
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;

            utn_getName("\nIngrese Nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getTexto("\nIngrese Password: ","\nError",1,TEXT_SIZE,1,array[posicion].password);
            //utn_getSurName("\nIngrese Password: ","\nError",1,TEXT_SIZE,1,array[posicion].password);
            //utn_getInt("\n : ", "\nError",1,10,sizeof(int),1,1,&array[posicion].calificacion);

            printf("\n Posicion: %d\n ID: %d\n calificacion: %d\n nombre: %s\n password: %s",
                   posicion, array[posicion].idUnico,array[posicion].calificacion,array[posicion].nombre,array[posicion].password);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array usuario Array de usuario
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int usuario_baja(Usuario array[], int sizeArray)                                      //cambiar usuario
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        usuario_listar(array,sizeArray);
        utn_getInt("\nID a cancelar: ","\nError",0,sizeArray,sizeof(int),1,1,&id);
        //utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(usuario_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].calificacion=0;                                                               //cambiar campo calificacion
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].password,"");                                               //cambiar campo password
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array usuario Array de usuario
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int usuario_bajaValorRepetidoInt(Usuario array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].calificacion=0;                                                               //cambiar campo calificacion
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].password,"");                                               //cambiar campo password
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array usuario Array de usuario
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int usuario_modificar(Usuario array[], int sizeArray)                                //cambiar usuario
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        usuario_listar(array,sizeArray);
        utn_getInt("\nID a modificar: ","\nError",0,sizeArray,sizeof(int),1,1,&id);
        //utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(usuario_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
               printf("\n Posicion: %d\n ID: %d\n calificacion: %d\n nombre: %s\n password: %s",
                   posicion, array[posicion].idUnico,array[posicion].calificacion,array[posicion].nombre,array[posicion].password);
              utn_getChar("\nModificar:\n A- Modificar Nombre\n B- Modificar Pass\n  S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nIngrese NUEVO nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;
                    case 'B':
                        utn_getTexto("\nIngrese NUEVO PASS: ","\nError",1,TEXT_SIZE,1,array[posicion].password);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array usuario Array de usuario
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int usuario_ordenarPorDobleCriterio(Usuario array[],int size, int orderFirst, int orderSecond)                              //cambiar usuario
{
    int retorno=-1;
    int i;
    Usuario buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                /*
                else if(strcmp(array[i].nombre,array[i+1].nombre) == 0)
                {
                    if( ((array[i].varFloat < array[i+1].varFloat) && orderSecond) ||
                        ((array[i].varFloat > array[i+1].varFloat) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }
                */
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array usuario Array de usuario
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int usuario_listar(Usuario array[], int size)                      //cambiar usuario
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n Posicion: %d\n ID: %d\n calificacion: %d\n nombre: %s\n password: %s",
                   i, array[i].idUnico,array[i].calificacion,array[i].nombre,array[i].password);
        }
        retorno=0;
    }
    return retorno;
}

////////////////////

void usuario_mock(Usuario array[], int size,int *contadorId)                      //cambiar autor
{

    array[0].idUnico=0;
    array[0].isEmpty=0;
    strcpy(array[0].password,"CCCCC");
    strcpy(array[0].nombre,"CCCCC");
    array[0].calificacion=0;
    *contadorId++;

    array[1].idUnico=1;
    array[1].isEmpty=0;
    strcpy(array[1].password,"AAAAA");
    strcpy(array[1].nombre,"AAAAA");
    array[1].calificacion=0;
    *contadorId++;

    array[2].idUnico=2;
    array[2].isEmpty=0;
    strcpy(array[2].password,"BBBBB");
    strcpy(array[2].nombre,"BBBBBB");
    array[2].calificacion=0;
    *contadorId++;

    array[3].idUnico=3;
    array[3].isEmpty=0;
    strcpy(array[3].password,"BBBBB");
    strcpy(array[3].nombre,"BBBBBB");
    array[3].calificacion=0;
    *contadorId++;


}
