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

static int generarIdPrestamo(void);

int prestamo_init(Prestamo* pPrestamo,int len)
{
    int i;
    if(pPrestamo!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pPrestamo[i].idPrestamo=-1;
            pPrestamo[i].isEmpty=-1;
        }
    }
    return 0;
}

int prestamo_add(Prestamo* pPrestamo,Libro* pLibro,Socio* pSocio, int len,int pIndex,char* msgE,int tries)
{
    int bufferDia;
    int bufferMes;
    int bufferAno;
    int auxIDLibro;
    int auxIDSocio;
    int retorno=-1;

    if((pPrestamo!=NULL)&&(len>0)&&(pIndex!=-1))
    {
        auxIDLibro=libro_getID(pLibro,len,msgE,tries,"\nIngrese ID Libro: ");//// hacer funcion
        auxIDSocio=socio_getID(pSocio,len,msgE,tries,"\nIngrese ID Socio: ");
        if(auxIDLibro>=0 && auxIDSocio>=0 )
        {
            if((libro_findLibroById(pLibro,len,auxIDLibro)!=-1)&&(socio_findSocioById(pSocio,len,auxIDSocio)!=-1))
            {
                if((!utn_getInt("\nIngrese Dia: ",msgE,1,31,3,1,tries,&bufferDia))&&
                   (!utn_getInt("\nIngrese Mes: ",msgE,1,12,3,1,tries,&bufferMes))&&
                   (!utn_getInt("\nIngrese Año: ",msgE,2018,2020,5,4,tries,&bufferAno)))
                   {
                        pPrestamo[pIndex].idPrestamo=generarIdPrestamo();
                        pPrestamo[pIndex].idLibro=auxIDLibro;
                        pPrestamo[pIndex].idSocio=auxIDSocio;
                        pPrestamo[pIndex].dia=bufferDia;
                        pPrestamo[pIndex].mes=bufferMes;
                        pPrestamo[pIndex].ano=bufferAno;
                        pPrestamo[pIndex].isEmpty=0;
                        retorno=0;

                   }
                   else
                   {
                        printf("\nFecha Incorrecta");
                   }
            }
            else
            {
                printf("\nEl ID no existe");
            }
        }

    }
    return retorno;
}
/*
int prestamo_print(Prestamo* pPrestamo,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pPrestamo[i].isEmpty!=-1)
        {
            printf("\nID Prestamo: %d\Titulo: %s\ID Autor: %s\nPos i: %d\n-------",
                   pPrestamo[i].idPrestamo,pPrestamo[i].titulo,pPrestamo[i].idAutor,i);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}
*/
int prestamo_findFree(Prestamo* pPrestamo, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pPrestamo[i].isEmpty==-1)
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



int socio_findAsocById(Socio* pSocio, int len, int idFind)
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

int prestamo_getID (Prestamo* pPrestamo,int len,char* msgE,int tries, char* msg)
{
    int retorno=-1;
    int bufferID;

    if(pPrestamo!=NULL && len>0)
    {
        if(!utn_getInt(msg, msgE,0,999999,7,1,tries,&bufferID))
        {
            retorno=bufferID;
        }
    }
    return retorno;
}

static int generarIdPrestamo(void)
{
    static int idPrestamo=0;
    return idPrestamo++;
}


