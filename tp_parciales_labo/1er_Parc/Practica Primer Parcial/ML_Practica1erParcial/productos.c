#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "usuarios.h"
#include "productos.h" //cambiar por nombre entidad


#define PRICE_MAX 9999


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array producto Array of producto
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int producto_Inicializar(Producto array[], int size)                                    //cambiar producto
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
* \param array producto Array de producto
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int producto_buscarEmpty(Producto array[], int size, int* posicion)                    //cambiar producto
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
* \param array producto Array de producto
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int producto_buscarID(Producto array[], int size, int valorBuscado, int* posicion)                    //cambiar producto
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
* \param array producto Array de producto
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int producto_alta(Producto array[],Usuario arrayUsuario[], int size, int sizeUsuario, int* contadorID)                          //cambiar producto
{
    int retorno=-1;
    int posicion;
    int auxIdUsuario;
    int posicionUsuario;

    if(array!=NULL && size>0 && contadorID!=NULL)
    {

        if(producto_buscarEmpty(array,size,&posicion)==-1)                          //cambiar producto
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            printf("\n----LISTADO DE SOCIOS----");
            usuario_listar(arrayUsuario,sizeUsuario);
            utn_getNumber ("\nIngrese el ID del socio: \n","\nError",0, size+1,sizeof(int),1,1,&auxIdUsuario);
            if(usuario_buscarID(arrayUsuario,sizeUsuario,auxIdUsuario,&posicionUsuario)==-1)
            {
                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
            }
            else
            {
               (*contadorID)++;
                array[posicion].idUnico=*contadorID;                                                       //campo ID
                array[posicion].isEmpty=0;

                utn_getName("\nIngrese Nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);
                utn_getInt("\n Ingerse Stock: ", "\nError",1,10,sizeof(int),1,1,&array[posicion].varInt);
                utn_getFloatSigne("\nIngrese Precio: ","\nError",1,PRICE_MAX,sizeof(float),1,1,&array[posicion].varFloat);

                //utn_getUnsignedInt("\ngetUnsignedInt: ","\nError",1,sizeof(int),1,10,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
                //utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                //utn_getName("\ngetName: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
                //utn_getTexto("\ngetTexto: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);                 //mensaje + cambiar campo varLongString
                printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s",
                       posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString);
                retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array producto Array de producto
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int producto_baja(Producto array[], int sizeArray)                                      //cambiar producto
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a cancelar: ","\nError",0,sizeArray,sizeof(int),1,1,&id);
        //utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(producto_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].varInt=0;                                                               //cambiar campo varInt
            array[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].varString,"");                                                   //cambiar campo varString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array producto Array de producto
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int producto_bajaValorRepetidoInt(Producto array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
                array[i].varInt=0;                                                               //cambiar campo varInt
                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].varString,"");                                                   //cambiar campo varString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array producto Array de producto
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int producto_modificar(Producto array[], int sizeArray)                                //cambiar producto
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        producto_listar(array,sizeArray);
        utn_getInt("\nID a modificar: ","\nError",0,sizeArray,sizeof(int),1,1,&id);
        //utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(producto_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s",
                       posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString);
                           utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getInt("\n : ","\nError",0,sizeArray,sizeof(int),1,1,&id);
                        //utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        //utn_getFloat("\ngetFloat: ","\nError",1,10,sizeof(float),1,1,&array[posicion].varFloat);
                        utn_getFloatSigne("\ngetFloat: ","\nError",1,10,sizeof(float),1,1,&array[posicion].varFloat);
                        //utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);
                        //utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
                        break;
                    case 'D':
                        utn_getTexto("\ngetTexto: ","\nError",1,TEXT_SIZE,1,array[posicion].varText);             //mensaje + cambiar campo varLongString
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


int producto_comprar(Producto array[],Usuario arrayUsuario[],int sizeUsuario, int sizeArray)                                //cambiar producto
{
    int retorno=-1;
    int posicion;
    int id;
    int calificacion;                                                                                         //cambiar si no se busca por ID
    char opcion;
    int contador=0;

    if(array!=NULL && sizeArray>0)
    {
        producto_listar(array,sizeArray);
        utn_getInt("\nID del producto para comprar: ","\nError",0,sizeArray,sizeof(int),1,1,&id);
        //utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(producto_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
               //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s",
                       posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString);

                if(array[posicion].varInt > 0)
                {
                    printf("\nCOMPRA EXITOSA!!\n");
                    array[posicion].varInt-=1;
                    array[posicion].cantVendidos=contador++;


                    if(!utn_getInt("\nIngrese calificacion al venddedor : ","\nError",0,sizeArray,sizeof(int),1,1,&calificacion)
                       &&!usuario_buscarID(arrayUsuario,sizeUsuario,array[posicion].idUsuario,&posicion))
                    {
                        arrayUsuario[posicion].calificacion=calificacion;
                    }
                }
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array producto Array de producto
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int producto_ordenarPorDobleCriterio(Producto array[],int size, int orderFirst, int orderSecond)                              //cambiar producto
{
    int retorno=-1;
    int i;
    Producto buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].varString,array[i+1].varString) < 0) && orderFirst) ||
                    ((strcmp(array[i].varString,array[i+1].varString) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].varString,array[i+1].varString) == 0)
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
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array producto Array de producto
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int producto_listar(Producto array[], int size)                      //cambiar producto
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                 continue;

            }
            else
            {
                printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s",
                       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString);      //cambiar todos

            }

        }
        retorno=0;
    }
    return retorno;
}


