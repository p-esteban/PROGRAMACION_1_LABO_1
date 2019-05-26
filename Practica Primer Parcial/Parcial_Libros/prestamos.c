#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "socios.h"
#include "libros.h"
#include "fecha.h"

#include "prestamos.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array prestamos Array of prestamos
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int prestamos_Inicializar(Prestamos array[], int size)                                    //cambiar prestamos
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
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int prestamos_buscarEmpty(Prestamos array[], int size, int* posicion)                    //cambiar prestamos
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
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prestamos_buscarID(Prestamos array[], int size, int valorBuscado, int* posicion)                    //cambiar prestamos
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
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/

int prestamos_buscarInt(Prestamos array[], int size, int valorBuscado, int* posicion)                    //cambiar prestamos
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idSocio==valorBuscado)                                                   //cambiar campo idSocio
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
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int prestamos_alta(Prestamos array[],Socios arraySocios[],Libros arrayLibros[], int size,int sizeSocios, int sizeLibros, int* contadorID)                          //cambiar prestamos
{
    int retorno=-1;
    int posicion;
    int auxIdSocio;
    int auxIdLibro;

    int posicionLibro;
    int posicionSocio;

    int auxDia;
    int auxMes;
    int auxAnio;

    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(prestamos_buscarEmpty(array,size,&posicion)==-1)                          //cambiar prestamos
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            printf("Posicion Buscar emty: %d",posicion);
            printf("\n----LISTADO DE SOCIOS----");
            socios_listar(arraySocios,sizeSocios);
            utn_getNumber ("\nIngrese el ID del socio: \n","\nError",0, size+1,sizeof(int),1,1,&auxIdSocio);
            printf("\n----LISTADO DE LIBROS------");
            libros_listar(arrayLibros,sizeLibros);

            utn_getNumber ("\nIngrese el ID del Libro: \n","\nError",0, size+1,sizeof(int),1,1,&auxIdLibro);

            if((socios_buscarID(arraySocios,sizeSocios,auxIdSocio,&posicionSocio)==-1)&&
               (libros_buscarID(arrayLibros,sizeLibros,auxIdLibro,&posicionLibro))==-1)                                   //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
            }
            else
            {
                if(!utn_getInt("\nIngrese Dia: ","\nError",1,31,3,1,1,&auxDia)&&!utn_getInt("\nIngrese Mes: ","\nError",1,12,3,1,1,&auxMes)
                   &&!utn_getInt("\nIngrese Año: ","\nError",2018,2020,5,4,1,&auxAnio)&&isValidFecha(auxDia,auxMes,auxAnio))
                {
                    (*contadorID)++;
                    array[posicion].idUnico=*contadorID;                                                       //campo ID
                    array[posicion].isEmpty=0;
                    array[posicion].idSocio=auxIdSocio;
                    array[posicion].idLibro=auxIdLibro;
                    array[posicion].dia=auxDia;
                    array[posicion].mes=auxMes;
                    array[posicion].anio=auxAnio;
                    printf("\nOK");
                }
                else
                {
                    printf("\nFECHA INCORRECTA");

                }

                //printf("\n Posicion: %d\n ID : %d\n idSocio: %d\n idLibro: %d\n",
                  //     posicion, array[posicion].idUnico,array[posicion].idSocio,array[posicion].idLibro);
                retorno=0;
            }
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int prestamos_baja(Prestamos array[], int sizeArray)                                      //cambiar prestamos
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a cancelar: ","\nError",1,sizeArray, sizeof(int),1,1,&id);
        //utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(prestamos_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int prestamos_bajaValorRepetidoInt(Prestamos array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
                array[i].idSocio=0;                                                               //cambiar campo idSocio
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int prestamos_listar(Prestamos array[], int size)                      //cambiar prestamos
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
                printf("\n Posicion: %d\n ID : %d\n idSocio: %d\n idLibro: %d\n",
                       i, array[i].idUnico,array[i].idSocio,array[i].idLibro);
        }
        retorno=0;
    }
    return retorno;
}

void prestamos_mock(Prestamos arrayPrestamos[], int size,int *contadorId)                      //cambiar socios
{
    //*******************************************************************
    arrayPrestamos[0].idUnico=0;
    arrayPrestamos[0].isEmpty=0;
    arrayPrestamos[0].dia=2;
    arrayPrestamos[0].mes=12;
    arrayPrestamos[0].anio=2018;
    arrayPrestamos[0].idSocio=0;
    arrayPrestamos[0].idLibro=1;
    *contadorId++;

    arrayPrestamos[1].idUnico=1;
    arrayPrestamos[1].isEmpty=0;
    arrayPrestamos[1].dia=20;
    arrayPrestamos[1].mes=03;
    arrayPrestamos[1].anio=2018;
    arrayPrestamos[1].idSocio=0;
    arrayPrestamos[1].idLibro=0;
    *contadorId++;

    arrayPrestamos[2].idUnico=2;
    arrayPrestamos[2].isEmpty=0;
    arrayPrestamos[2].dia=20;
    arrayPrestamos[2].mes=03;
    arrayPrestamos[2].anio=2018;
    arrayPrestamos[2].idSocio=1;
    arrayPrestamos[2].idLibro=1;
    *contadorId++;

    arrayPrestamos[3].idUnico=3;
    arrayPrestamos[3].isEmpty=0;
    arrayPrestamos[3].dia=14;
    arrayPrestamos[3].mes=2;
    arrayPrestamos[3].anio=2018;
    arrayPrestamos[3].idSocio=2;
    arrayPrestamos[3].idLibro=3;
    *contadorId++;


}


