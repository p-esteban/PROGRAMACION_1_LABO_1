#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autores.h"
#include "libros.h" //cambiar por nombre entidad




/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array libros Array of libros
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int libros_Inicializar(Libros array[], int size)                                    //cambiar libros
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
* \param array libros Array de libros
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int libros_buscarEmpty(Libros array[], int size, int* posicion)                    //cambiar libros
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
* \param array libros Array de libros
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libros_buscarID(Libros array[], int size, int valorBuscado, int* posicion)                    //cambiar libros
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
* \param array libros Array de libros
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libros_buscarInt(Libros array[], int size, int valorBuscado, int* posicion)                    //cambiar libros
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idAutor==valorBuscado)                                                   //cambiar campo idAutor
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array libros Array de libros
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libros_buscarString(Libros array[], int size, char* valorBuscado, int* indice)                    //cambiar libros
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].titulo,valorBuscado)==0)                                        //cambiar campo titulo
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array libros Array de libros
* \param size int Tama�o del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int libros_alta(Libros array[],Autores arrayAutores[], int size, int sizeAutores, int* contadorID)                          //cambiar libros
{
    int retorno=-1;
    int posicion;
    int auxIdAutor;
    int posicionAutor;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(libros_buscarEmpty(array,size,&posicion)==-1)                          //cambiar libros
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            utn_getNumber ("\nIngrese el ID del autor: \n","\nError",0, size+1,sizeof(int),1,1,&auxIdAutor);
            if(autores_buscarID(arrayAutores,sizeAutores,auxIdAutor,&posicionAutor)==-1)                                   //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
            }
            else
            {
                (*contadorID)++;
                array[posicion].idUnico=*contadorID;                                                       //campo ID
                array[posicion].isEmpty=0;
                array[posicion].idAutor=auxIdAutor;

                //utn_getUnsignedInt("\ngetUnsignedInt: ","\nError",1,sizeof(int),1,10,1,&array[posicion].idAutor);           //mensaje + cambiar campo idAutor
                utn_getName("\ngetName: ","\nError",1,TEXT_SIZE_LIBRO,1,array[posicion].titulo);                      //mensaje + cambiar campo titulo
                printf("\n Posicion: %d\n ID: %d\n idAutor: %d\n titulo: %s\n",
                       posicion, array[posicion].idUnico,array[posicion].idAutor,array[posicion].titulo);
                retorno=0;
            }
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array libros Array de libros
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libros_baja(Libros array[], int sizeArray)                                      //cambiar libros
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a cancelar: ","\nError",1,sizeArray, sizeof(int),1,1,&id);

        //utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(libros_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].idAutor=0;                                                               //cambiar campo idAutor
            strcpy(array[posicion].titulo,"");                                                   //cambiar campo titulo
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array libros Array de libros
* \param size int Tama�o del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libros_bajaValorRepetidoInt(Libros array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
                array[i].idAutor=0;                                                               //cambiar campo idAutor
                strcpy(array[i].titulo,"");                                                   //cambiar campo titulo
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array libros Array de libros
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int libros_modificar(Libros array[], int sizeArray)                                //cambiar libros
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getNumber ("\nID a midoficar: \n","\nError",0, sizeArray,sizeof(int),1,1,&id);
        //utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(libros_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n idAutor: %d\n titulo: %s\n",
                   posicion, array[posicion].idUnico,array[posicion].idAutor,array[posicion].titulo);
                utn_getChar("\nModificar: \nA. Mod. Titulo: \nB. Mod ID Autor\n S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nNUEVO Titulo: ","\nError",1,TEXT_SIZE_LIBRO,1,array[posicion].titulo);           //mensaje + cambiar campo idAutor
                        break;
                    case 'B':
                        utn_getNumber ("\nID Autor NUEVO: \n","\nError",0, sizeArray,sizeof(int),1,1,&array[posicion].idAutor);             //mensaje + cambiar campo varFloat
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
* \param array libros Array de libros
* \param size int Tama�o del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int libros_ordenarPorDobleCriterio(Libros array[],int size, int orderFirst, int orderSecond)                              //cambiar libros
{
    int retorno=-1;
    int i;
    Libros buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].titulo,array[i+1].titulo) < 0) && orderFirst) ||
                    ((strcmp(array[i].titulo,array[i+1].titulo) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].titulo,array[i+1].titulo) == 0)
                {
                    if( ((array[i].idAutor < array[i+1].idAutor) && orderSecond) ||
                        ((array[i].idAutor> array[i+1].idAutor) && !orderSecond) )
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
* \param array libros Array de libros
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int libros_listar(Libros array[], int size)                      //cambiar libros
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
                printf("\n Posicion: %d\n ID: %d\n idAutor: %d\n titulo: %s\n",
                   i, array[i].idUnico,array[i].idAutor,array[i].titulo);
                    //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

void libros_mock(Libros arrayLibros[], int size,int *contadorId)
{
    arrayLibros[0].idUnico=0;
    arrayLibros[0].isEmpty=0;
    arrayLibros[0].idAutor=0;
    strcpy(arrayLibros[0].titulo,"Rayuela");
    contadorId++;

    arrayLibros[1].idUnico=3;
    arrayLibros[1].isEmpty=0;
    arrayLibros[1].idAutor=0;
    strcpy(arrayLibros[1].titulo,"Bestiario");
    contadorId++;

    arrayLibros[2].idUnico=3;
    arrayLibros[2].isEmpty=0;
    arrayLibros[2].idAutor=1;
    strcpy(arrayLibros[2].titulo,"El aleph");
    contadorId++;

    arrayLibros[3].idUnico=3;
    arrayLibros[3].isEmpty=0;
    arrayLibros[3].idAutor=2;
    strcpy(arrayLibros[3].titulo,"La Casa de los espiritus");
    contadorId++;

    arrayLibros[4].idUnico=3;
    arrayLibros[4].isEmpty=0;
    arrayLibros[4].idAutor=1;
    strcpy(arrayLibros[4].titulo,"Ficciones");
    contadorId++;
}


