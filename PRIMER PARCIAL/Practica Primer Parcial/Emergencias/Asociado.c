#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Asociado.h"
#include "Llamada.h"
#include "utn.h"

#define MIN_STR_NAME 1
#define MAX_STR_NAME 50

static int generarId(void);

int asoc_initAsociado(Asociado* pAsociado,int len)
{
    int i;
    if(pAsociado!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pAsociado[i].idAsociado=-1;
            pAsociado[i].estado=-1;
        }
    }
    return 0;
}

int asoc_add(Asociado* pAsociado,int len,int pIndex,char* msgE,int tries)
{
    char bufferName[50];
    char bufferSurName[50];
    int bufferDni;
    int bufferEdad;


    int retorno=-1;
    if((pAsociado!=NULL)&&(len>0)&&(pIndex!=-1))
    {
        if((!utn_getName("\nIngrese Nombre: ", msgE, MIN_STR_NAME, MAX_STR_NAME, tries, bufferName))&&
            (!utn_getSurName("\nIngrese Apellido: ", msgE, MIN_STR_NAME, MAX_STR_NAME, tries, bufferSurName)))
        {
            if((!utn_getInt("\nIngrese Edad: ", msgE, 0, 99, 3, 1, tries, &bufferEdad))
                &&(!utn_getInt("\nIngrese DNI: ", msgE, 111111, 999999999, 9, 7, tries, &bufferDni)))
            {

                strncpy(pAsociado[pIndex].nombre,bufferName,sizeof(bufferName));
                strncpy(pAsociado[pIndex].apellido,bufferSurName,sizeof(bufferSurName));
                pAsociado[pIndex].edad=bufferEdad;
                pAsociado[pIndex].dni=bufferDni;
                pAsociado[pIndex].idAsociado=generarId();/////ojo generar id
                pAsociado[pIndex].estado=1;
                retorno=0;
            }
        }
    }
    return retorno;
}

int asoc_alter(Asociado* pAsociado, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int opcion=0;
    char bufferName[50];
    char bufferSurName[50];
    int bufferEdad;
    int bufferDni;
    int auxEstado;
    int retorno=-1;

    if((pAsociado!=NULL)&&(len>0))
    {
        auxID=asoc_getID(pAsociado,len,msgE,tries,"\nIngrese ID: ");//// hacer funcion
        if(auxID>=0)
        {
            posOfID=asoc_findAsocById(pAsociado,len,auxID);//// hacer funcion
            if(posOfID!=-1)
            {
                while(opcion!=6)
                {
                    printf("\n1- Modificar Nombre\n");
                    printf("2- Modificar Apellido\n");
                    printf("3- Modificar Edad\n");
                    printf("4- Modificar Dni\n");
                    printf("5- Modificar Estado\n");
                    printf("6- Atras (Menu Principal)\n");
                    utn_getInt("\n   INGRESE OPCION (Menu Modificacion): ", msgE, 1, 6, 2, 1, tries, &opcion);
                    switch(opcion)
                    {
                        case 1:
                        {
                            if(!utn_getName("\nIngrese NUEVO Nombre: ", msgE, MIN_STR_NAME, MAX_STR_NAME, tries, bufferName))
                            {
                                strncpy(pAsociado[posOfID].nombre,bufferName,sizeof(bufferName));
                                retorno=0;
                            }
                            break;
                        }
                        case 2:
                        {
                            if(!utn_getSurName("\nIngrese NUEVO Apellido: ", msgE, MIN_STR_NAME, MAX_STR_NAME, tries, bufferSurName))
                            {
                                strncpy(pAsociado[posOfID].apellido,bufferSurName,sizeof(bufferSurName));
                                retorno=0;
                            }
                            break;
                        }
                        case 3:
                        {
                            if(!utn_getInt("\nIngrese NUEVA Edad: ", msgE, 0, 99, 3, 1, tries, &bufferEdad))
                            {

                                pAsociado[posOfID].edad=bufferEdad;
                                retorno=0;
                            }
                            break;
                        }
                        case 4:
                        {
                            if(!utn_getInt("\nIngrese NUEVO DNI: ", msgE, 1111111, 99999999, 11, 9, tries, &bufferDni))
                            {

                                pAsociado[posOfID].dni=bufferDni;
                                retorno=0;
                            }
                            break;
                        }
                        case 5:
                        {
                            if(!utn_getInt("\nIngrese NUEVO Estado (1 - Habilitado / 0 - Inhabilitado): ", msgE, 1, 2, 2, 1, tries, &auxEstado))
                            {

                                pAsociado[posOfID].estado=auxEstado;
                                retorno=0;
                            }
                            break;
                        }
                    }
                }
            }
            else
            {
                printf("\n----No se encontro el ID!-----\n");
            }
        }
    }
    return retorno;
}

int asoc_remove(Asociado* pAsociado, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(pAsociado!=NULL && len>0)
    {
        auxID=asoc_getID(pAsociado,len,msgE,tries,"\nIngrese ID: ");
         if(auxID>=0)
        {
            posOfID=asoc_findAsocById(pAsociado,len,auxID);
            if(posOfID!=-1)
            {
               pAsociado[posOfID].estado=-1;
               retorno=0;
            }
        }
     }
    return retorno;
}

int asoc_print(Asociado* pAsociado,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pAsociado[i].estado!=-1)
        {
            printf("\nID: %d\nApellido: %s\nNombre: %s\nEdad: %d\nDNI: %d\nEstado (1-Habilitado / 0-Inhabilitado): %d\nPos i: %d\n-------",
                   pAsociado[i].idAsociado,pAsociado[i].apellido,pAsociado[i].nombre,
                   pAsociado[i].edad,pAsociado[i].dni,pAsociado[i].estado,i);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

int asoc_findFree(Asociado* pAsociado, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pAsociado[i].estado==-1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}
/** \brief busca el ID en el array Asociado
 *
 * \param puntero al array asociado
 * \param
 * \return devuelve la posicion del array Asociado donde esta la coincidencia
 *
 */



int asoc_findAsocById(Asociado* pAsociado, int len, int idFind)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pAsociado[i].idAsociado==idFind)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int asoc_getID (Asociado* pAsociado,int len,char* msgE,int tries, char* msg)
{
    int retorno=-1;
    int bufferID;

    if(pAsociado!=NULL && len>0)
    {
        if(!utn_getInt(msg, msgE,0,999999,7,1,tries,&bufferID))
        {
            retorno=bufferID;
        }
    }
    return retorno;
}

static int generarId(void)
{
    static int idAsoc=0;
    return idAsoc++;
}
