#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Autores.h"
#include "Libros.h"
#include "Socios.h"
#include "Prestamos.h"
#include "utn.h"


#define MIN_STR 1
#define MAX_STR 31

static int generarIdAutores(void);

int autores_init(Autores* pAutores,int len)
{
    int i;
    if(pAutores!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pAutores[i].idAutores=-1;
            pAutores[i].isEmpty=-1;
        }
    }
    return 0;
}

int autores_add(Autores* pAutores,int len,int pIndex,char* msgE,int tries)
{
    char bufferName[50];
    char bufferSurName[50];
    int retorno=-1;

    if((pAutores!=NULL)&&(len>0)&&(pIndex!=-1))
    {
        if((!utn_getName("\nIngrese Nombre: ", msgE, MIN_STR, MAX_STR, tries, bufferName))&&
            (!utn_getSurName("\nIngrese Apellido: ", msgE, MIN_STR, MAX_STR, tries, bufferSurName)))
        {
                strncpy(pAutores[pIndex].nombre,bufferName,sizeof(bufferName));
                strncpy(pAutores[pIndex].apellido,bufferSurName,sizeof(bufferSurName));
                pAutores[pIndex].idAutores=generarIdAutores();/////ojo generar id
                pAutores[pIndex].isEmpty=0;
                retorno=0;
        }
    }
    return retorno;
}

int autores_alter(Autores* pAutores, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int opcion=0;
    char bufferName[50];
    char bufferSurName[50];
    int retorno=-1;

    if((pAutores!=NULL)&&(len>0))
    {
        auxID=autores_getID(pAutores,len,msgE,tries,"\nIngrese ID: ");//// hacer funcion
        if(auxID>=0)
        {
            posOfID=autores_findAutorById(pAutores,len,auxID);//// hacer funcion
            if(posOfID!=-1)
            {
                while(opcion!=3)
                {
                    printf("\n1- Modificar Nombre\n");
                    printf("2- Modificar Apellido\n");
                    printf("3- Atras (Menu Principal)\n");
                    utn_getInt("\n   INGRESE OPCION (Menu Modificacion): ", msgE, 1, 3, 2, 1, tries, &opcion);
                    switch(opcion)
                    {
                        case 1:
                        {
                            if(!utn_getName("\nIngrese NUEVO Nombre: ", msgE, MIN_STR, MAX_STR, tries, bufferName))
                            {
                                strncpy(pAutores[posOfID].nombre,bufferName,sizeof(bufferName));
                                retorno=0;
                            }
                            break;
                        }
                        case 2:
                        {
                            if(!utn_getSurName("\nIngrese NUEVO Apellido: ", msgE, MIN_STR, MAX_STR, tries, bufferSurName))
                            {
                                strncpy(pAutores[posOfID].apellido,bufferSurName,sizeof(bufferSurName));
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

int autores_remove(Autores* pAutores, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(pAutores!=NULL && len>0)
    {
        auxID=autores_getID(pAutores,len,msgE,tries,"\nIngrese ID Autor: ");
         if(auxID>=0)
        {
            posOfID=autores_findAutorById(pAutores,len,auxID);
            if(posOfID!=-1)
            {
               pAutores[posOfID].isEmpty=-1;
               retorno=0;
            }
        }
     }
    return retorno;
}

int autores_print(Autores* pAutores,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pAutores[i].isEmpty!=-1)
        {
            printf("\nID: %d\nApellido: %s\nNombre: %s\nPos i: %d\n-------",
                   pAutores[i].idAutores,pAutores[i].apellido,pAutores[i].nombre,i);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

int autores_findFree(Autores* pAutores, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pAutores[i].isEmpty==-1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}
/** \brief busca el ID en el array Autores
 *
 * \param puntero al array Autores
 * \param
 * \return devuelve la posicion del array Autores donde esta la coincidencia
 *
 */



int autores_findAutorById(Autores* pAutores, int len, int idFind)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pAutores[i].idAutores==idFind)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int autores_getID (Autores* pAutores,int len,char* msgE,int tries, char* msg)
{
    int retorno=-1;
    int bufferID;

    if(pAutores!=NULL && len>0)
    {
        if(!utn_getInt(msg, msgE,0,999999,7,1,tries,&bufferID))
        {
            retorno=bufferID;
        }
    }
    return retorno;
}

static int generarIdAutores(void)
{
    static int idAsoc=0;
    return idAsoc++;
}
