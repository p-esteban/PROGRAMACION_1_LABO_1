#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"

/**
 * \brief Inicializa el isEmpty en un array de musico
 * \param array Es el array en el cual buscar
 * \param size Indica la logitud del array
 * \return return (-1) [Invalid length or NULL pointer] - (0) si inicializa exitosamente
 *
 */
int musico_Inicializar(Musico array[], int size)
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param valorBuscado int id a buscar en el array de muscico
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)
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
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array musico Array de musico
* \param size int Tamaño del array
* \param idOrquestaBuscado int valor a buscar en array de musico
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarByIdOrquesta(Musico array[], int size, int idOrquestaBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idOrquesta==idOrquestaBuscado)
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param arrayOrquesta Array de orquesta donde se busca existencia de idOrquesta ingresado
* \param sizeOrquesta int Tamaño del array
* \param arrayInstrumento Array de instrumento donde se busca existencia de idInstrumento ingresado
* \param sizeInstrumento int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[], int size, Orquesta arrayOrquesta[],int sizeOrquesta, Instrumento arrayInstrumento[],int sizeInstrumento, int* contadorID)                          //cambiar musico
{
    int retorno=-1;
    int posicion;
    int auxIdOrquesta;
    int posicionOrquesta;
    int auxIdInstrumento;
    int posicionInstrumento;

    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getTexto("\nIngrese Nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getTexto("\nIngrese Apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);
            utn_getInt("\nIngrese Edad: ", "\nError",1,99,sizeof(int),1,1,&array[posicion].edad);
            utn_getInt("\nIngrese ID Orquesta: ", "\nError",1,10,sizeof(int),1,1,&auxIdOrquesta);
            utn_getInt("\nIngrese ID Instrumento: ", "\nError",1,10,sizeof(int),1,1,&auxIdInstrumento);

            if((orquesta_buscarID(arrayOrquesta,sizeOrquesta,auxIdOrquesta,&posicionOrquesta))&&
               (instrumento_buscarID(arrayInstrumento,sizeInstrumento,auxIdInstrumento,&posicionInstrumento)))
            {
                printf("\nNo existe este ID");
            }
            else
            {
                array[posicion].idOrquesta=auxIdOrquesta;
                array[posicion].idInstrumento=auxIdInstrumento;
                printf("\n OK ID: %d",array[posicion].idUnico);
                //printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n IdOrquesta: %d\n IdIntrumento: %d",
                        //posicion, array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido,array[posicion].edad,array[posicion].idOrquesta,array[posicion]idInstrumento);
                retorno=0;
            }
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[],int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a cancelar: ","\nError",0,sizeArray,sizeof(int),1,1,&id);
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].edad=0;
            array[posicion].idOrquesta=0;
            array[posicion].idInstrumento=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].apellido,"");
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musico Array de musico
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaByIdOrquesta(Musico array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idOrquesta==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;
                array[i].edad=0;
                strcpy(array[i].nombre,"");
                strcpy(array[i].apellido,"");
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a modificar: ","\nError",0,sizeArray,sizeof(int),1,1,&id);
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                utn_getChar("\n-----MENU MODIFICAR----\n A-ID Orquesta\n B-Edad\nS(salir)\n","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getInt("\nNUEVO ID: ","\nError",0,sizeArray,sizeof(int),1,1,&array[posicion].idOrquesta);
                        break;
                    case 'B':
                        utn_getInt("\nNUEVA EDAD: ","\nError",0,99,sizeof(int),1,1,&array[posicion].edad);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida\n");
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musico_ordenarPorApellido(Musico array[],int size, int orderFirst)
{
    int retorno=-1;
    int i;
    Musico buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 0; i < size-1; i++)
            {
                if( ((strcmp(array[i].apellido,array[i+1].apellido) < 0) && orderFirst) ||
                    ((strcmp(array[i].apellido,array[i+1].apellido) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}


int musico_ordenar(Musico array[],int size)
{
    int retorno=-1;
    int i;
    int j;
    Musico buffer;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            buffer = array[i];

            j = i - 1;
            while((j>=0)&&(strcmp(array[i].apellido,array[j].apellido) < 0))
            {
                array[j+1]=array[j];
                j--;
            }
            array[j+1]=buffer;
        }
        retorno=0;
    }
    return retorno;
}





//*****************************************
//Listar
/** \brief Lista los elementos de un array con el nombre de su intrumento
* \param array musico Array de musico
* \param array instrumento Array de instrumentos
* \param size int Tamaño del array de musico
* \param sizeInstrumento int Tamaño del array de instrumento
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listarConInstrumento(Musico array[], int size, Instrumento arrayInstrumento[], int sizeInstrumento)
{
    int retorno=-1;
    int i;
    int posicion;
    char tipoStr[TEXT_SIZE];

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
                if(!instrumento_buscarID(arrayInstrumento,sizeInstrumento,array[i].idInstrumento,&posicion))
                {
                    instrumento_tipoStr(arrayInstrumento,posicion,tipoStr);
                    printf("\nID: %d\nNombre: %s\nApellido: %s\nInstrumento: %s\nTipo: %s\n---------------",
                       array[i].idUnico,array[i].nombre,array[i].apellido,arrayInstrumento[posicion].nombre,tipoStr);
                       retorno=0;
                }
            }
        }
    }
    return retorno;
}


/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int size)
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
                printf(" ID: %d\n Nombre: %s\n Apellido: %s\n-----------------\n",
                       array[i].idUnico,array[i].nombre,array[i].apellido);
                retorno=0;
            }
        }

    }
    return retorno;
}


void musico_mock(Musico arrayMusico[], int size)
{

    arrayMusico[0].idUnico=1;
    arrayMusico[0].isEmpty=0;
    arrayMusico[0].edad=30;
    arrayMusico[0].idOrquesta=1;
    arrayMusico[0].idInstrumento=2;
    strcpy(arrayMusico[0].apellido,"AMus1");
    strcpy(arrayMusico[0].nombre,"Mus1");


    arrayMusico[1].idUnico=2;
    arrayMusico[1].isEmpty=0;
    arrayMusico[1].edad=20;
    arrayMusico[1].idOrquesta=2;
    arrayMusico[1].idInstrumento=5;
    strcpy(arrayMusico[1].apellido,"AMus2");
    strcpy(arrayMusico[1].nombre,"Mus2");


    arrayMusico[2].idUnico=3;
    arrayMusico[2].isEmpty=0;
    arrayMusico[2].edad=25;
    arrayMusico[2].idOrquesta=4;
    arrayMusico[2].idInstrumento=2;
    strcpy(arrayMusico[2].apellido,"AMus3");
    strcpy(arrayMusico[2].nombre,"Mus3");


    arrayMusico[3].idUnico=4;
    arrayMusico[3].isEmpty=0;
    arrayMusico[3].edad=27;
    arrayMusico[3].idOrquesta=4;
    arrayMusico[3].idInstrumento=1;
    strcpy(arrayMusico[3].apellido,"AMus4");
    strcpy(arrayMusico[3].nombre,"Mus4");


    arrayMusico[4].idUnico=5;
    arrayMusico[4].isEmpty=0;
    arrayMusico[4].edad=22;
    arrayMusico[4].idOrquesta=1;
    arrayMusico[4].idInstrumento=3;
    strcpy(arrayMusico[4].apellido,"AMus5");
    strcpy(arrayMusico[4].nombre,"Mus5");


    arrayMusico[5].idUnico=6;
    arrayMusico[5].isEmpty=0;
    arrayMusico[5].edad=35;
    arrayMusico[5].idOrquesta=3;
    arrayMusico[5].idInstrumento=4;
    strcpy(arrayMusico[5].apellido,"AMus6");
    strcpy(arrayMusico[5].nombre,"Mus6");

    /*
    arrayMusico[0].idUnico=0;
    arrayMusico[0].isEmpty=0;
    arrayMusico[0].edad=20;
    arrayMusico[0].idOrquesta=0;
    arrayMusico[0].idInstrumento=0;
    strcpy(arrayMusico[0].apellido,"Gologorsky");
    strcpy(arrayMusico[0].nombre,"Arkadi");


    arrayMusico[1].idUnico=1;
    arrayMusico[1].isEmpty=0;
    arrayMusico[1].edad=18;
    arrayMusico[1].idOrquesta=0;
    arrayMusico[1].idInstrumento=0;
    strcpy(arrayMusico[1].apellido,"Argerich");
    strcpy(arrayMusico[1].nombre,"Marta");


    arrayMusico[2].idUnico=2;
    arrayMusico[2].isEmpty=0;
    arrayMusico[2].edad=20;
    arrayMusico[2].idOrquesta=0;
    arrayMusico[2].idInstrumento=0;
    strcpy(arrayMusico[2].apellido,"Bolena");
    strcpy(arrayMusico[2].nombre,"Ana");


    arrayMusico[3].idUnico=3;
    arrayMusico[3].isEmpty=0;
    arrayMusico[3].edad=20;
    arrayMusico[3].idOrquesta=0;
    arrayMusico[3].idInstrumento=2;
    strcpy(arrayMusico[3].apellido,"Perez");
    strcpy(arrayMusico[3].nombre,"Julio");


    arrayMusico[4].idUnico=4;
    arrayMusico[4].isEmpty=0;
    arrayMusico[4].edad=38;
    arrayMusico[4].idOrquesta=0;
    arrayMusico[4].idInstrumento=4;
    strcpy(arrayMusico[4].apellido,"Rodrigues");
    strcpy(arrayMusico[4].nombre,"Luis");


    arrayMusico[5].idUnico=5;
    arrayMusico[5].isEmpty=0;
    arrayMusico[5].edad=40;
    arrayMusico[5].idOrquesta=0;
    arrayMusico[5].idInstrumento=5;
    strcpy(arrayMusico[5].apellido,"Ginastera");
    strcpy(arrayMusico[5].nombre,"Alberto");


    arrayMusico[6].idUnico=6;
    arrayMusico[6].isEmpty=0;
    arrayMusico[6].edad=80;
    arrayMusico[6].idOrquesta=0;
    arrayMusico[6].idInstrumento=2;
    strcpy(arrayMusico[6].apellido,"Guelber");
    strcpy(arrayMusico[6].nombre,"Bruno");


    arrayMusico[7].idUnico=7;
    arrayMusico[7].isEmpty=0;
    arrayMusico[7].edad=90;
    arrayMusico[7].idOrquesta=0;
    arrayMusico[7].idInstrumento=0;
    strcpy(arrayMusico[7].apellido,"Villazon");
    strcpy(arrayMusico[7].nombre,"Rolando");


    arrayMusico[8].idUnico=8;
    arrayMusico[8].isEmpty=0;
    arrayMusico[8].edad=19;
    arrayMusico[8].idOrquesta=0;
    arrayMusico[8].idInstrumento=8;
    strcpy(arrayMusico[8].apellido,"Netrebko");
    strcpy(arrayMusico[8].nombre,"Ana");


    arrayMusico[9].idUnico=9;
    arrayMusico[9].isEmpty=0;
    arrayMusico[9].edad=24;
    arrayMusico[9].idOrquesta=17;
    arrayMusico[9].idInstrumento=9;
    strcpy(arrayMusico[9].apellido,"Bartoli");
    strcpy(arrayMusico[9].nombre,"Cecilia");


    arrayMusico[10].idUnico=10;
    arrayMusico[10].isEmpty=0;
    arrayMusico[10].edad=48;
    arrayMusico[10].idOrquesta=17;
    arrayMusico[10].idInstrumento=1;
    strcpy(arrayMusico[10].apellido,"Lavandera");
    strcpy(arrayMusico[10].nombre,"Horacio");


    arrayMusico[11].idUnico=11;
    arrayMusico[11].isEmpty=0;
    arrayMusico[11].edad=71;
    arrayMusico[11].idOrquesta=17;
    arrayMusico[11].idInstrumento=2;
    strcpy(arrayMusico[11].apellido,"Villalobos");
    strcpy(arrayMusico[11].nombre,"Hector");


    arrayMusico[12].idUnico=12;
    arrayMusico[12].isEmpty=0;
    arrayMusico[12].edad=8;
    arrayMusico[12].idOrquesta=2;
    arrayMusico[12].idInstrumento=2;
    strcpy(arrayMusico[12].apellido,"Goto");
    strcpy(arrayMusico[12].nombre,"Midori");


    arrayMusico[13].idUnico=13;
    arrayMusico[13].isEmpty=0;
    arrayMusico[13].edad=89;
    arrayMusico[13].idOrquesta=2;
    arrayMusico[13].idInstrumento=3;
    strcpy(arrayMusico[13].apellido,"Savater");
    strcpy(arrayMusico[13].nombre,"Fernando");


    arrayMusico[14].idUnico=14;
    arrayMusico[14].isEmpty=0;
    arrayMusico[14].edad=36;
    arrayMusico[14].idOrquesta=2;
    arrayMusico[14].idInstrumento=4;
    strcpy(arrayMusico[14].apellido,"Odonellel");
    strcpy(arrayMusico[14].nombre,"Maria");


    arrayMusico[15].idUnico=15;
    arrayMusico[15].isEmpty=0;
    arrayMusico[15].edad=58;
    arrayMusico[15].idOrquesta=2;
    arrayMusico[15].idInstrumento=5;
    strcpy(arrayMusico[15].apellido,"Villa");
    strcpy(arrayMusico[15].nombre,"Pancho");


    arrayMusico[16].idUnico=16;
    arrayMusico[16].isEmpty=0;
    arrayMusico[16].edad=78;
    arrayMusico[16].idOrquesta=3;
    arrayMusico[16].idInstrumento=6;
    strcpy(arrayMusico[16].apellido,"Fernandez");
    strcpy(arrayMusico[16].nombre,"Anibal");


    arrayMusico[17].idUnico=17;
    arrayMusico[17].isEmpty=0;
    arrayMusico[17].edad=66;
    arrayMusico[17].idOrquesta=3;
    arrayMusico[17].idInstrumento=7;
    strcpy(arrayMusico[17].apellido,"Lemebel");
    strcpy(arrayMusico[17].nombre,"Pedro");


    arrayMusico[18].idUnico=18;
    arrayMusico[18].isEmpty=0;
    arrayMusico[18].edad=22;
    arrayMusico[18].idOrquesta=3;
    arrayMusico[18].idInstrumento=8;
    strcpy(arrayMusico[18].apellido,"Modarelli");
    strcpy(arrayMusico[18].nombre,"Alejandro");


    arrayMusico[19].idUnico=19;
    arrayMusico[19].isEmpty=0;
    arrayMusico[19].edad=28;
    arrayMusico[19].idOrquesta=4;
    arrayMusico[19].idInstrumento=9;
    strcpy(arrayMusico[19].apellido,"Sola");
    strcpy(arrayMusico[19].nombre,"Juan");


    arrayMusico[20].idUnico=20;
    arrayMusico[20].isEmpty=0;
    arrayMusico[20].edad=27;
    arrayMusico[20].idOrquesta=4;
    arrayMusico[20].idInstrumento=2;
    strcpy(arrayMusico[20].apellido,"Bolano");
    strcpy(arrayMusico[20].nombre,"Roberto");
    */

}


