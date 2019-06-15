#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h"

/**
 * \brief Inicializa el isEmpty en un array de instrumento
 * \param array Es el array en el cual buscar
 * \param size Indica la logitud del array
 * \return return (-1) [Invalid length or NULL pointer] - (0) si inicializa exitosamente
 *
 */
int instrumento_Inicializar(Instrumento array[], int size)
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion)
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {

        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                if(array[i].idUnico==valorBuscado)
                {
                retorno=0;
                *posicion=i;
                break;
                }
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getName("\nIngrese Nombre del instrumento: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getInt("\nIngrese tipo (1-cuerdas 2-Vieto madera 3-Viento metal 4-Percusion) : ", "\nError",1,10,sizeof(int),1,1,&array[posicion].tipo);

            printf("\nOK - ID generado: %d",array[posicion].idUnico);
           //printf("\n Posicion: %d\n ID: %d\n tipo: %d\n nombre: %s\n",posicion, array[posicion].idUnico,array[posicion].tipo,array[posicion].nombre);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_baja(Instrumento array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a cancelar: ","\nError",0,sizeArray,sizeof(int),1,1,&id);
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].tipo=0;
            strcpy(array[posicion].nombre,"");
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;
                array[i].tipo=0;
                strcpy(array[i].nombre,"");
            }
        }
        retorno=0;
    }
    return retorno;
}


//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumento_listar(Instrumento array[], int size)
{
    int retorno=-1;
    int i;
    char tipoInstrumento[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;

            else
            {
                instrumento_tipoStr(array,i,tipoInstrumento);
                printf("\n ID:%d - %s\n tipo: %s\n---------------------",array[i].idUnico,array[i].nombre,tipoInstrumento);
            }
        }
        retorno=0;
    }
    return retorno;
}
/** \brief remplaza un numero por una cadena de caracteres
 *
 * \param array Instrumento array de instrumentos
 * \param posicion int posicion del array de instrumentos donde se encuentra el valor a remplazar
 * \param tipoInstrumento *char puntero a tipoStr donde se guardara el equivalente al valor unimerico en tipo cadena de caracteres
 * \return -
 *
 */

void instrumento_tipoStr(Instrumento array[],int posicion, char* tipoInstrumento)
{
    if(array!=NULL && tipoInstrumento!=NULL && posicion>=0)
    {
        switch(array[posicion].tipo)
        {
        case 1:
            strncpy(tipoInstrumento,"Cuerdas",TEXT_SIZE);
            break;
        case 2:
            strncpy(tipoInstrumento,"Viento-Madera",TEXT_SIZE);
            break;
        case 3:
            strncpy(tipoInstrumento,"Viento-Metal",TEXT_SIZE);
            break;
        case 4:
            strncpy(tipoInstrumento,"Percusion",TEXT_SIZE);
            break;
        }
    }
}


void instrumento_mock(Instrumento arrayInstrumento[], int size)
{
    //*******************************************************************

    arrayInstrumento[0].idUnico=1;
    arrayInstrumento[0].isEmpty=0;
    arrayInstrumento[0].tipo=1;
    strcpy(arrayInstrumento[0].nombre,"Inst1");


    arrayInstrumento[1].idUnico=2;
    arrayInstrumento[1].isEmpty=0;
    arrayInstrumento[1].tipo=2;
    strcpy(arrayInstrumento[1].nombre,"Inst2");


    arrayInstrumento[2].idUnico=3;
    arrayInstrumento[2].isEmpty=0;
    arrayInstrumento[2].tipo=2;
    strcpy(arrayInstrumento[2].nombre,"Inst3");


    arrayInstrumento[3].idUnico=4;
    arrayInstrumento[3].isEmpty=0;
    arrayInstrumento[3].tipo=3;
    strcpy(arrayInstrumento[3].nombre,"Inst4");


    arrayInstrumento[4].idUnico=5;
    arrayInstrumento[4].isEmpty=0;
    arrayInstrumento[4].tipo=4;
    strcpy(arrayInstrumento[4].nombre,"Inst5");




 /*
    arrayInstrumento[0].idUnico=0;
    arrayInstrumento[0].isEmpty=0;
    arrayInstrumento[0].tipo=1;
    strcpy(arrayInstrumento[0].nombre,"Violin");


    arrayInstrumento[1].idUnico=1;
    arrayInstrumento[1].isEmpty=0;
    arrayInstrumento[1].tipo=2;
    strcpy(arrayInstrumento[1].nombre,"Fagot");


    arrayInstrumento[2].idUnico=2;
    arrayInstrumento[2].isEmpty=0;
    arrayInstrumento[2].tipo=2;
    strcpy(arrayInstrumento[2].nombre,"Oboe");


    arrayInstrumento[3].idUnico=3;
    arrayInstrumento[3].isEmpty=0;
    arrayInstrumento[3].tipo=4;
    strcpy(arrayInstrumento[3].nombre,"Timbales");


    arrayInstrumento[4].idUnico=4;
    arrayInstrumento[4].isEmpty=0;
    arrayInstrumento[4].tipo=4;
    strcpy(arrayInstrumento[4].nombre,"Platillos");


    arrayInstrumento[5].idUnico=5;
    arrayInstrumento[5].isEmpty=0;
    arrayInstrumento[5].tipo=2;
    strcpy(arrayInstrumento[5].nombre,"Picolo");


    arrayInstrumento[6].idUnico=6;
    arrayInstrumento[6].isEmpty=0;
    arrayInstrumento[6].tipo=1;
    strcpy(arrayInstrumento[6].nombre,"Contra Bajo");


    arrayInstrumento[7].idUnico=7;
    arrayInstrumento[7].isEmpty=0;
    arrayInstrumento[7].tipo=4;
    strcpy(arrayInstrumento[7].nombre,"Timbales");


    arrayInstrumento[8].idUnico=8;
    arrayInstrumento[8].isEmpty=0;
    arrayInstrumento[8].tipo=3;
    strcpy(arrayInstrumento[8].nombre,"Trompeta");


    arrayInstrumento[9].idUnico=9;
    arrayInstrumento[9].isEmpty=0;
    arrayInstrumento[9].tipo=1;
    strcpy(arrayInstrumento[9].nombre,"Arpa");


    arrayInstrumento[10].idUnico=10;
    arrayInstrumento[10].isEmpty=0;
    arrayInstrumento[10].tipo=3;
    strcpy(arrayInstrumento[10].nombre,"Tuba");


    arrayInstrumento[11].idUnico=11;
    arrayInstrumento[11].isEmpty=0;
    arrayInstrumento[11].tipo=3;
    strcpy(arrayInstrumento[11].nombre,"Corno");


    arrayInstrumento[12].idUnico=12;
    arrayInstrumento[12].isEmpty=0;
    arrayInstrumento[12].tipo=1;
    strcpy(arrayInstrumento[12].nombre,"Viola");


    arrayInstrumento[13].idUnico=13;
    arrayInstrumento[13].isEmpty=0;
    arrayInstrumento[13].tipo=1;
    strcpy(arrayInstrumento[13].nombre,"Violoncelo");


    arrayInstrumento[14].idUnico=14;
    arrayInstrumento[14].isEmpty=0;
    arrayInstrumento[14].tipo=3;
    strcpy(arrayInstrumento[14].nombre,"Saxofon");


    arrayInstrumento[15].idUnico=15;
    arrayInstrumento[15].isEmpty=0;
    arrayInstrumento[15].tipo=3;
    strcpy(arrayInstrumento[15].nombre,"Trombon");


    arrayInstrumento[16].idUnico=16;
    arrayInstrumento[16].isEmpty=0;
    arrayInstrumento[16].tipo=4;
    strcpy(arrayInstrumento[16].nombre,"Timbales");


    arrayInstrumento[17].idUnico=17;
    arrayInstrumento[17].isEmpty=0;
    arrayInstrumento[17].tipo=2;
    strcpy(arrayInstrumento[17].nombre,"Flautin");


    arrayInstrumento[18].idUnico=18;
    arrayInstrumento[18].isEmpty=0;
    arrayInstrumento[18].tipo=4;
    strcpy(arrayInstrumento[18].nombre,"Triangulo");
*/


}

