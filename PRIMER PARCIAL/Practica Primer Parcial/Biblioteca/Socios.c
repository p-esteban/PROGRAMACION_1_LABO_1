#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Autores.h"
#include "Libros.h"
#include "Prestamos.h"
#include "Socios.h"
#include "utn.h"


#define MIN_STR 1
#define MAX_STR 31

static int generarIdSocio(void);

int socio_init(Socio* pSocio,int len)
{
    int i;
    if(pSocio!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pSocio[i].idSocio=-1;
            pSocio[i].isEmpty=-1;
        }
    }
    return 0;
}

int socio_add(Socio* pSocio,int len,int pIndex,char* msgE,int tries)
{
    char bufferName[MAX_STR];
    char bufferSurName[MAX_STR];
    int bufferDni;
    char bufferSexo[2];
    int bufferTelefono;
    char bufferEmail[MAX_STR];
    int bufferDia;
    int bufferMes;
    int bufferAno;


    int retorno=-1;
    if((pSocio!=NULL)&&(len>0)&&(pIndex!=-1))
    {
        if((!utn_getName("\nIngrese Nombre: ", msgE, MIN_STR, MAX_STR, tries, bufferName))&&
           (!utn_getSurName("\nIngrese Apellido: ", msgE, MIN_STR, MAX_STR, tries, bufferSurName)))
        {
            if((!utn_getInt("\nIngrese DNI: ", msgE, 111111, 999999999, 9, 7, tries, &bufferDni))&&
               (!utn_getString("Ingrese Sexo (M - F): ",msgE,1,2,tries,bufferSexo)))
            {
                if((!utn_getEmail("\nIngrese Email: ", msgE,5,MAX_STR,tries,bufferEmail))&&
                   (!utn_getTelephone("\nIngrese Telefono: ", msgE, 1111, 99999999, 11, 5,tries, &bufferTelefono))&&
                   (!utn_getInt("\nIngrese Dia: ",msgE,1,31,1,3,tries,&bufferDia))&&
                   (!utn_getInt("\nIngrese Mes: ", msgE,1,12,1,3,tries,&bufferMes))&&
                   (!utn_getInt("\nIngrese Año: ",msgE,1100,2019,3,5,tries,&bufferAno)))
                {
                strncpy(pSocio[pIndex].nombre,bufferName,sizeof(bufferName));
                strncpy(pSocio[pIndex].apellido,bufferSurName,sizeof(bufferSurName));
                strncpy(pSocio[pIndex].sexo,bufferSexo,sizeof(bufferSexo));
                strncpy(pSocio[pIndex].email,bufferEmail,sizeof(bufferEmail));
                pSocio[pIndex].telefono=bufferTelefono;
                pSocio[pIndex].dia=bufferDia;
                pSocio[pIndex].mes=bufferMes;
                pSocio[pIndex].ano=bufferAno;
                pSocio[pIndex].idSocio=generarIdSocio();/////ojo generar id
                pSocio[pIndex].isEmpty=0;
                retorno=0;
                }
            }
        }
    }
    return retorno;
}

int socio_alter(Socio* pSocio, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int opcion=0;
    char bufferName[MAX_STR];
    char bufferSurName[MAX_STR];
    char bufferSexo[2];
    int bufferTelefono;
    char bufferEmail[MAX_STR];
    int retorno=-1;

    if((pSocio!=NULL)&&(len>0))
    {
        auxID=socio_getID(pSocio,len,msgE,tries,"\nIngrese ID Socio: ");//// hacer funcion
        if(auxID>=0)
        {
            posOfID=socio_findSocioById(pSocio,len,auxID);//// hacer funcion
            if(posOfID!=-1)
            {
                while(opcion!=6)
                {
                    printf("\n1- Modificar Nombre\n");
                    printf("2- Modificar Apellido\n");
                    printf("3- Modificar Sexo\n");
                    printf("4- Modificar Telefono\n");
                    printf("5- Modificar Email\n");
                    printf("6- Atras (Menu Principal)\n");
                    utn_getInt("\n   INGRESE OPCION (Menu Modificacion): ", msgE, 1, 6, 2, 1, tries, &opcion);
                    switch(opcion)
                    {
                        case 1:
                        {
                            if(!utn_getName("\nIngrese NUEVO Nombre: ", msgE, MIN_STR, MAX_STR, tries, bufferName))
                            {
                                strncpy(pSocio[posOfID].nombre,bufferName,sizeof(bufferName));
                                retorno=0;
                            }
                            break;
                        }
                        case 2:
                        {
                            if(!utn_getSurName("\nIngrese NUEVO Apellido: ", msgE, MIN_STR, MAX_STR, tries, bufferSurName))
                            {
                                strncpy(pSocio[posOfID].apellido,bufferSurName,sizeof(bufferSurName));
                                retorno=0;
                            }
                            break;
                        }
                        case 3:
                        {
                            if(!utn_getString("\nIngrese NUEVO Sexo: ", msgE,5,MAX_STR,tries,bufferSexo))
                            {
                                strncpy(pSocio[posOfID].email,bufferEmail,sizeof(bufferSexo));
                                retorno=0;
                            }
                            break;
                        }
                        case 4:
                        {
                            if(!utn_getInt("\nIngrese NUEVO Telefono: ", msgE, 1111, 99999999, 11, 5, tries,&bufferTelefono))
                            {
                                pSocio[posOfID].telefono=bufferTelefono;
                                retorno=0;
                            }
                            break;
                        }
                        case 5:
                        {
                            if(!utn_getEmail("\nIngrese Email: ", msgE,5,MAX_STR,tries,bufferEmail))
                            {
                                strncpy(pSocio[posOfID].email,bufferEmail,sizeof(bufferEmail));
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

int socio_remove(Socio* pSocio, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(pSocio!=NULL && len>0)
    {
        auxID=socio_getID(pSocio,len,msgE,tries,"\nIngrese ID Socio: ");
         if(auxID>=0)
        {
            posOfID=socio_findSocioById(pSocio,len,auxID);
            if(posOfID!=-1)
            {
               pSocio[posOfID].isEmpty=-1;
               retorno=0;
            }
        }
     }
    return retorno;
}

int socio_print(Socio* pSocio,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pSocio[i].isEmpty!=-1)
        {
            printf("\nID: %d\nApellido: %s\nNombre: %s\nTelefono: %d\nEmail: %s\nFecha: %d/%d/%d\nPos i: %d\n-------",
                   pSocio[i].idSocio,pSocio[i].apellido,pSocio[i].nombre,pSocio[i].telefono,pSocio[i].email,
                   pSocio[i].dia,pSocio[i].mes,pSocio[i].ano,i);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

int socio_findFree(Socio* pSocio, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pSocio[i].isEmpty==-1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}
/** \brief busca el ID en el array Socio
 *
 * \param puntero al array Socio
 * \param
 * \return devuelve la posicion del array Socio donde esta la coincidencia
 *
 */



int socio_findSocioById(Socio* pSocio, int len, int idFind)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pSocio[i].idSocio==idFind)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int socio_getID(Socio* pSocio,int len,char* msgE,int tries, char* msg)
{
    int retorno=-1;
    int bufferID;

    if(pSocio!=NULL && len>0)
    {
        if(!utn_getInt(msg, msgE,0,999999,7,1,tries,&bufferID))
        {
            retorno=bufferID;
        }
    }
    return retorno;
}

static int generarIdSocio(void)
{
    static int idAsoc=0;
    return idAsoc++;
}

