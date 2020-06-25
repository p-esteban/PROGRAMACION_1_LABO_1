#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"


/**
 * \brief Inicializa el isEmpty en un array de orquesta
 * \param array Es el array en el cual buscar
 * \param size Indica la logitud del array
 * \return return (-1) [Invalid length or NULL pointer] - (0) si inicializa exitosamente
 *
 */
int orquesta_Inicializar(Orquesta array[], int size)
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


/** \brief Busca el primer lugar vacio en un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un string en un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param lugarBuscado char* Puntero al lugar  que se va a buscar en en array
* \param posicion int* Puntero a la posicion del array donde se encuentra el lugar buscado
* \return int Return (-1) si no encuentra el lugar buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el lugar buscado
*
*/
int orquesta_buscarLugar(Orquesta array[], int size, char* lugarBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {

        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].lugar,lugarBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getTexto("\nIngrese Nombre Orquesta: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getTexto("\nIngrese lugar: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar);
            utn_getInt("\nIngrese tipo (1-Sinfonica 2-Filarmonica 3-Camara) : ", "\nError",1,3,sizeof(int),1,1,&array[posicion].tipo);

            printf("\nOK - ID Orquesta: %d",array[posicion].idUnico);
            //printf("\n Posicion: %d\n ID: %d\n tipo: %d\n nombre: %s\n lugar: %s",posicion, array[posicion].idUnico,array[posicion].tipo,array[posicion].nombre,array[posicion].lugar);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a cancelar: ","\nError",0,sizeArray,sizeof(int),1,1,&id);
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].tipo=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].lugar,"");
            retorno=id;
        }
    }
    return retorno;
}



//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta array[], int size)
{
    int retorno=-1;
    int i;
    char auxTipo[TEXT_SIZE];

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
                switch(array[i].tipo)
                {
                case 1:
                    strncpy(auxTipo,"Sinfonica",TEXT_SIZE);
                    break;
                case 2:
                    strncpy(auxTipo,"Filarmonica",TEXT_SIZE);
                    break;
                case 3:
                    strncpy(auxTipo,"De Camara",TEXT_SIZE);
                    break;
                }

                printf("\nID %d - %s\n Lugar: %s\n Tipo: %s\n---------------------------",
                       array[i].idUnico,array[i].nombre,array[i].lugar,auxTipo);
                //printf("\n Posicion: %d\n ID: %d\n tipo: %s\n nombre: %s\n lugar: %s\n",
                //i, array[i].idUnico,auxTipo,array[i].nombre,array[i].lugar);
             }
        retorno=0;
        }

    }
    return retorno;
}


void orquesta_mock(Orquesta arrayOrquesta[], int size)
{


    arrayOrquesta[0].idUnico=1;
    arrayOrquesta[0].isEmpty=0;
    arrayOrquesta[0].tipo=1;
    strcpy(arrayOrquesta[0].lugar,"Lugar1");
    strcpy(arrayOrquesta[0].nombre,"Orquesta1");


    arrayOrquesta[1].idUnico=2;
    arrayOrquesta[1].isEmpty=0;
    arrayOrquesta[1].tipo=2;
    strcpy(arrayOrquesta[1].lugar,"Lugar1");
    strcpy(arrayOrquesta[1].nombre,"Orquesta2");


    arrayOrquesta[2].idUnico=3;
    arrayOrquesta[2].isEmpty=0;
    arrayOrquesta[2].tipo=3;
    strcpy(arrayOrquesta[2].lugar,"Lugar2");
    strcpy(arrayOrquesta[2].nombre,"Orquesta3");


    arrayOrquesta[3].idUnico=4;
    arrayOrquesta[3].isEmpty=0;
    arrayOrquesta[3].tipo=2;
    strcpy(arrayOrquesta[3].lugar,"Lugar3");
    strcpy(arrayOrquesta[3].nombre,"Orquesta4");

    /*
    arrayOrquesta[0].idUnico=0;
    arrayOrquesta[0].isEmpty=0;
    arrayOrquesta[0].tipo=1;
    strcpy(arrayOrquesta[0].lugar,"Buenos Aires");
    strcpy(arrayOrquesta[0].nombre,"ORQUESTA SINFONICA NACIONAL");


    arrayOrquesta[1].idUnico=1;
    arrayOrquesta[1].isEmpty=0;
    arrayOrquesta[1].tipo=1;
    strcpy(arrayOrquesta[1].lugar,"Viena");
    strcpy(arrayOrquesta[1].nombre,"SINFONICA DE VIENA");


    arrayOrquesta[2].idUnico=2;
    arrayOrquesta[2].isEmpty=0;
    arrayOrquesta[2].tipo=2;
    strcpy(arrayOrquesta[2].lugar,"Amsterdam");
    strcpy(arrayOrquesta[2].nombre,"REAL ORQUESTA DEL CONCERTGEBOUW DE AMSTERDAM");


    arrayOrquesta[3].idUnico=3;
    arrayOrquesta[3].isEmpty=0;
    arrayOrquesta[3].tipo=1;
    strcpy(arrayOrquesta[3].lugar,"Londres");
    strcpy(arrayOrquesta[3].nombre,"ORQUESTA SINFÓNICA DE LONDRES");


    arrayOrquesta[4].idUnico=4;
    arrayOrquesta[4].isEmpty=0;
    arrayOrquesta[4].tipo=1;
    strcpy(arrayOrquesta[4].lugar,"Alemania");
    strcpy(arrayOrquesta[4].nombre,"ORQUESTA SAJONA DE LA STAATSKAPELLE DE DRESDE");


    arrayOrquesta[5].idUnico=5;
    arrayOrquesta[5].isEmpty=0;
    arrayOrquesta[5].tipo=2;
    strcpy(arrayOrquesta[5].lugar,"Rusia");
    strcpy(arrayOrquesta[5].nombre,"ORQUESTA FILARMÓNICA DE SAN PETERSBURGO");


    arrayOrquesta[6].idUnico=6;
    arrayOrquesta[6].isEmpty=0;
    arrayOrquesta[6].tipo=2;
    strcpy(arrayOrquesta[6].lugar,"Alemania");
    strcpy(arrayOrquesta[6].nombre,"ORQUESTA FILARMÓNICA DE BERLÍN");


    arrayOrquesta[7].idUnico=7;
    arrayOrquesta[7].isEmpty=0;
    arrayOrquesta[7].tipo=1;
    strcpy(arrayOrquesta[7].lugar,"EE UU");
    strcpy(arrayOrquesta[7].nombre,"ORQUESTA SINFÓNICA DE CHICAGO");


    arrayOrquesta[8].idUnico=8;
    arrayOrquesta[8].isEmpty=0;
    arrayOrquesta[8].tipo=1;
    strcpy(arrayOrquesta[8].lugar,"Venezuela");
    strcpy(arrayOrquesta[8].nombre,"ORQUESTA SINFÓNICA SIMÓN BOLÍVAR ");


    arrayOrquesta[9].idUnico=9;
    arrayOrquesta[9].isEmpty=0;
    arrayOrquesta[9].tipo=3;
    strcpy(arrayOrquesta[9].lugar,"Chile");
    strcpy(arrayOrquesta[9].nombre,"SYNTAGMA MUSICUM");



    arrayOrquesta[10].idUnico=10;
    arrayOrquesta[10].isEmpty=0;
    arrayOrquesta[10].tipo=3;
    strcpy(arrayOrquesta[10].lugar,"Argentina");
    strcpy(arrayOrquesta[10].nombre,"CAMERATA BARILOCHE");


    arrayOrquesta[11].idUnico=11;
    arrayOrquesta[11].isEmpty=0;
    arrayOrquesta[11].tipo=3;
    strcpy(arrayOrquesta[11].lugar,"Argentina");
    strcpy(arrayOrquesta[11].nombre,"VIOLETA CLUB");


    arrayOrquesta[12].idUnico=12;
    arrayOrquesta[12].isEmpty=0;
    arrayOrquesta[12].tipo=2;
    strcpy(arrayOrquesta[12].lugar,"Rusia");
    strcpy(arrayOrquesta[12].nombre,"PHILARMONIA");


    arrayOrquesta[13].idUnico=13;
    arrayOrquesta[13].isEmpty=0;
    arrayOrquesta[13].tipo=3;
    strcpy(arrayOrquesta[13].lugar,"Francia");
    strcpy(arrayOrquesta[13].nombre,"ENSEMBLE MATHEUS");


    arrayOrquesta[14].idUnico=14;
    arrayOrquesta[14].isEmpty=0;
    arrayOrquesta[14].tipo=2;
    strcpy(arrayOrquesta[14].lugar,"EE UU");
    strcpy(arrayOrquesta[14].nombre,"ROYAL PHILARMONIC");


    arrayOrquesta[15].idUnico=15;
    arrayOrquesta[15].isEmpty=0;
    arrayOrquesta[15].tipo=2;
    strcpy(arrayOrquesta[15].lugar,"EE UU");
    strcpy(arrayOrquesta[15].nombre,"ROYAL OPERA HOUSE COVENT");


    arrayOrquesta[16].idUnico=16;
    arrayOrquesta[16].isEmpty=0;
    arrayOrquesta[16].tipo=2;
    strcpy(arrayOrquesta[16].lugar,"Republica Checa");
    strcpy(arrayOrquesta[16].nombre,"CZECH PHILHARMONIC");


    arrayOrquesta[17].idUnico=17;
    arrayOrquesta[17].isEmpty=0;
    arrayOrquesta[17].tipo=1;
    strcpy(arrayOrquesta[17].lugar,"Tokyo");
    strcpy(arrayOrquesta[17].nombre,"SAITO KINEN SYMPHONY ORCHESTRA");
*/

}

