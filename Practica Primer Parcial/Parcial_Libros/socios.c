#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "socios.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array socios Array of socios
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int socios_Inicializar(Socios array[], int size)                                    //cambiar socios
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int socios_buscarEmpty(Socios array[], int size, int* posicion)                    //cambiar socios
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socios_buscarID(Socios array[], int size, int valorBuscado, int* posicion)                    //cambiar socios
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int socios_alta(Socios array[], int size, int* contadorID)                          //cambiar socios
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(socios_buscarEmpty(array,size,&posicion)==-1)                          //cambiar socios
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("\nIngrese Nombre: ","\nError",1,TEXT_SIZE_SOCIO,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
            utn_getTexto("\nIngrese Apellido: ","\nError",1,TEXT_SIZE_SOCIO,1,array[posicion].apellido);
            utn_getChar("\nIngrese Sexo (M - F): ","\nError",'F','M',1,array[posicion].sexo);
            utn_getTelephone("\nIngrese Telefono: ","\nError",16,10,1,array[posicion].telefono);
            utn_getEmail("\nIngrese Email: ","\nError", 5, 31,1,array[posicion].email);
            utn_getInt("\nIngrese Dia: ","\nError",1,31,3,1,1,&array[posicion].dia);
            //utn_getNumber("\nIngrese Dia: ","\nError",1,31,3,1,1,&array[posicion].dia);
            utn_getInt("\nIngrese Mes: ","\nError",1,12,3,1,1,&array[posicion].mes);
            //utn_getNumber("\nIngrese Mes: ","\nError",1,12,3,1,1,&array[posicion].mes);
            utn_getInt("\nIngrese Año: ","\nError",2018,2020,5,4,1,&array[posicion].anio);
            //utn_getNumber("\nIngrese Año: ","\nError",2018,2020,5,4,1,&array[posicion].anio);
            printf("\n Posicion: %d\n ID: %d\n apellido: %s\n nombre: %s\n Sexo: %s\n Telefono: %s\n Email: %s\n Fecha: %d/%d/%d\n",
                   posicion, array[posicion].idUnico,array[posicion].apellido,array[posicion].nombre,array[posicion].sexo,
                   array[posicion].telefono,array[posicion].email,array[posicion].dia,array[posicion].mes,array[posicion].anio);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array socios Array de socios
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socios_baja(Socios array[], int sizeArray)                                      //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a cancelar: ","\nError",sizeof(int),1,1,sizeArray,1,&id);
        //utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(socios_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
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


//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array socios Array de socios
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int socios_modificar(Socios array[], int sizeArray)                                //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getInt("\nID a modificar: ","\nError",1,sizeArray, sizeof(int),1,1,&id);
        //utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(socios_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
            printf("\n Posicion: %d\n ID: %d\n apellido: %s\n nombre: %s\n Sexo: %s\n Telefono: %s\n Email: %s\n Fecha: %d/%d/%d\n",
                   posicion, array[posicion].idUnico,array[posicion].apellido,array[posicion].nombre,array[posicion].sexo,
                   array[posicion].telefono,array[posicion].email,array[posicion].dia,array[posicion].mes,array[posicion].anio);
            utn_getChar("\nModificar: \nA- Apellido: \nB- Nombre: \nC- Sexo: \nD- Telefono: \nE- Email\n S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getTexto("\nIngrese NUEVO Apellido: ","\nError",1,TEXT_SIZE_SOCIO,1,array[posicion].apellido);             //mensaje + cambiar campo apellido
                        break;
                    case 'B':
                        utn_getName("\nIngrese NUEVO Nombre: ","\nError",1,TEXT_SIZE_SOCIO,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                        break;
                    case 'C':
                        utn_getChar("\nIngrese NUEVO Sexo: ","\nError",'F','M',1,array[posicion].sexo);
                        break;
                    case 'D':
                        utn_getTelephone("\nIngrese NUEVO Telefono: ","\nError",17,10,1,array[posicion].telefono);
                        break;
                    case 'E':

                        utn_getEmail("\nIngrese NUEVO Telefono: ","\nError",5,31,1,array[posicion].email);
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int socios_ordenarPorDobleCriterio(Socios array[],int size, int orderFirst, int orderSecond)                              //cambiar socios
{
    int retorno=-1;
    int i;
    Socios buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].apellido) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].apellido) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].nombre,array[i+1].nombre) == 0)
                {
                    if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderSecond) ||
                        ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderSecond) )
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int socios_listar(Socios array[], int size)                      //cambiar socios
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
                printf("\n Posicion: %d\n ID: %d\n apellido: %s\n nombre: %s\n Sexo: %s\n Telefono: %s\n Email: %s\n Fecha: %d/%d/%d\n-------------\n",
                   i, array[i].idUnico,array[i].apellido,array[i].nombre,array[i].sexo,
                   array[i].telefono,array[i].email,array[i].dia,array[i].mes,array[i].anio);    //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}






void socios_mock(Socios arraySocios[], int size,int *contadorId)                      //cambiar socios
{
    //*******************************************************************
    arraySocios[0].idUnico=0;
    arraySocios[0].isEmpty=0;
    arraySocios[0].dia=7;
    arraySocios[0].mes=10;
    arraySocios[0].anio=2018;
    strcpy(arraySocios[0].apellido,"Perez");
    strcpy(arraySocios[0].nombre,"Ana");
    strcpy(arraySocios[0].email,"xxxx@cjakc.com");
    strcpy(arraySocios[0].telefono,"1234567");
    strcpy(arraySocios[0].sexo,"M");
    *contadorId++;

    arraySocios[1].idUnico=1;
    arraySocios[1].isEmpty=0;
    arraySocios[1].dia=5;
    arraySocios[1].mes=8;
    arraySocios[1].anio=2019;
    strcpy(arraySocios[1].apellido,"Gomez");
    strcpy(arraySocios[1].nombre,"Julio");
    strcpy(arraySocios[1].email,"xxxx@cjakc.com");
    strcpy(arraySocios[1].telefono,"1234567");
    strcpy(arraySocios[1].sexo,"M");
    *contadorId++;

    arraySocios[2].idUnico=2;
    arraySocios[2].isEmpty=0;
    arraySocios[2].dia=21;
    arraySocios[2].mes=12;
    arraySocios[2].anio=2019;
    strcpy(arraySocios[2].apellido,"Carrio");
    strcpy(arraySocios[2].nombre,"Elisa");
    strcpy(arraySocios[2].email,"xxxx@cjakc.com");
    strcpy(arraySocios[2].telefono,"1234567");
    strcpy(arraySocios[2].sexo,"M");
    *contadorId++;

    arraySocios[3].idUnico=3;
    arraySocios[3].isEmpty=0;
    arraySocios[3].dia=31;
    arraySocios[3].mes=3;
    arraySocios[3].anio=2018;
    strcpy(arraySocios[3].apellido,"Perez");
    strcpy(arraySocios[3].nombre,"Julia");
    strcpy(arraySocios[3].email,"xxxx@cjakc.com");
    strcpy(arraySocios[3].telefono,"1234567");
    strcpy(arraySocios[3].sexo,"F");
    *contadorId++;
}

