#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#include "autores.h" //cambiar por nombre entidad
#include "libros.h"

#define ID_MAX 999


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array autores Array of autores
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int autores_Inicializar(Autores array[], int size)                                    //cambiar autores
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
* \param array autores Array de autores
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int autores_buscarEmpty(Autores array[], int size, int* posicion)                    //cambiar autores
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
* \param array autores Array de autores
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int autores_buscarID(Autores array[], int size, int valorBuscado, int* posicion)                    //cambiar autores
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

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array autores Array de autores
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int autores_alta(Autores array[], int size, int* contadorID)                          //cambiar autores
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(autores_buscarEmpty(array,size,&posicion)==-1)                          //cambiar autores
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("\nIngrese Nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getSurName("\nIngrese Apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);
            //utn_getTexto("\nIngrese Apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);                 //mensaje + cambiar campo nombre
            printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s",
                   posicion, array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array autores Array de autores
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int autores_baja(Autores array[], int sizeArray)                                      //cambiar autores
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a cancelar: ","\nError",0,ID_MAX,sizeof(int),1,1,&id);
        //utn_getInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id)
        //utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(autores_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].apellido,"");                                               //cambiar campo apellido
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array autores Array de autores
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int autores_bajaValorRepetidoInt(Autores array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array autores Array de autores
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int autores_modificar(Autores array[], int sizeArray)                                //cambiar autores
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a cancelar: ","\nError",0,ID_MAX,sizeof(int),1,1,&id);
        if(autores_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s",
                posicion, array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido);
                utn_getChar("\nModificar:\nA - Nombre\nB - Apellido\nS(salir)\n","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nIngrese NUEVO Nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                        break;
                    case 'B':
                        utn_getTexto("\nIngrese NUEVO Apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);             //mensaje + cambiar campo apellido
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
* \param array autores Array de autores
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int autores_ordenarPorDobleCriterio(Autores array[],int size, int orderFirst, int orderSecond)                              //cambiar autores
{
    int retorno=-1;
    int i;
    Autores buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].apellido,array[i+1].apellido) < 0) && orderFirst) ||
                    ((strcmp(array[i].apellido,array[i+1].apellido) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].apellido,array[i+1].apellido) == 0)
                {
                    if( ((strcmp(array[i].nombre,array[i+1].nombre)< 0) && orderSecond) ||   ///str1 menor a str2
                        ((strcmp(array[i].nombre,array[i+1].nombre)> 0) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array autores Array de autores
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int autores_listar(Autores array[], int size)                      //cambiar autores
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
          printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s",
                i, array[i].idUnico,array[i].nombre,array[i].apellido);
        }
        retorno=0;
    }
    return retorno;
}
void autores_mock(Autores arrayAutores[], int size,int *contadorIdautores)
{
    arrayAutores[0].idUnico=0;
    arrayAutores[0].isEmpty=0;
    strcpy(arrayAutores[0].apellido,"Cortazar");
    strcpy(arrayAutores[0].nombre,"Julio");
    contadorIdautores++;

    arrayAutores[1].idUnico=1;
    arrayAutores[1].isEmpty=0;
    strcpy(arrayAutores[1].apellido,"Borges");
    strcpy(arrayAutores[1].nombre,"Jorge");
    contadorIdautores++;

    arrayAutores[2].idUnico=2;
    arrayAutores[2].isEmpty=0;
    strcpy(arrayAutores[2].apellido,"Allende");
    strcpy(arrayAutores[2].nombre,"Isabel");
    contadorIdautores++;

    arrayAutores[3].idUnico=3;
    arrayAutores[3].isEmpty=0;
    strcpy(arrayAutores[3].apellido,"Borges");
    strcpy(arrayAutores[3].nombre,"Luis");
    contadorIdautores++;
}

