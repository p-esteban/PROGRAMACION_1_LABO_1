#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Autores.h"

#include "Socios.h"
#include "Prestamos.h"
#include "Libros.h"
#include "utn.h"


#define MIN_STR 1
#define MAX_STR 31

static int generarIdLibro(void);

int libro_init(Libro* pLibro,int len)
{
    int i;
    if(pLibro!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pLibro[i].idLibro=-1;
            pLibro[i].isEmpty=-1;
        }
    }
    return 0;
}

int libro_add(Libro* pLibro,Autores* pAutores, int len,int pIndex,char* msgE,int tries)
{
    char bufferTitulo[51];
    int bufferIDAut;
    int retorno=-1;

    if((pLibro!=NULL)&&(len>0)&&(pIndex!=-1))
    {
        bufferIDAut = autores_getID(Autores* pAutores,len,msgE,tries,"\nIngrese ID de Autor: ");
        if((!utn_getName("\nIngrese Titulo: ", msgE, MIN_STR, 51, tries, bufferTitulo))&& (bufferIDAut>=0))
        {
                strncpy(pLibro[pIndex].titulo,bufferTitulo,sizeof(bufferTitulo));
                pLibro[pIndex].idAutor=bufferIDAut;
                pLibro[pIndex].idLibro=generarIdLibro();/////ojo generar id
                pLibro[pIndex].isEmpty=0;
                retorno=0;
        }
    }
    return retorno;
}

int libro_alter(Libro* pLibro,Autores* pAutores, int len,char* msgE,int tries)
{
    int auxID;
    int auxIDAutor;
    int posOfID;
    int opcion=0;
    char bufferTitulo[51];
    int bufferIDAut;
    int retorno=-1;

    if((pLibro!=NULL)&&(len>0))
    {
        auxID=libro_getID(pLibro,len,msgE,tries,"\nIngrese ID Libro: ");//// hacer funcion
        if(auxID>=0)
        {
            posOfID=libro_findLibroById(pLibro,len,auxID);//// hacer funcion
            if(posOfID!=-1)
            {
                while(opcion!=3)
                {
                    printf("\n1- Modificar Titulo\n");
                    printf("2- Modificar ID Autor\n");
                    printf("3- Atras (Menu Principal)\n");
                    utn_getInt("\n   INGRESE OPCION (Menu Modificacion): ", msgE, 1, 3, 2, 1, tries, &opcion);
                    switch(opcion)
                    {
                        case 1:
                        {
                            if(!utn_getName("\nIngrese NUEVO Titulo: ", msgE, MIN_STR, MAX_STR, tries, bufferTitulo))
                            {
                                strncpy(pLibro[posOfID].titulo,bufferTitulo,sizeof(bufferTitulo));
                                retorno=0;
                            }
                            break;
                        }
                        case 2:
                        {
                            auxIDAutor=autores_getID(pAutores,len,msgE,tries,"\nIngrese ID Autor: ");
                            if(auxIDAutor!=-1)
                            {
                                bufferIDAut=autores_findAutorById(pAutores,len,auxIDAutor);
                                if(bufferIDAut!=-1)
                                {
                                    pLibro[posOfID].idAutor=bufferIDAut;
                                    retorno=0;
                                }
                                else
                                {
                                    printf("\nEl ID de Autor no existe");
                                }
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

int libro_remove(Libro* pLibro, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(pLibro!=NULL && len>0)
    {
        auxID=libro_getID(pLibro,len,msgE,tries,"\nIngrese ID Libro: ");
        if(auxID>=0)
        {
            posOfID=libro_findLibroById(pLibro,len,auxID);
            if(posOfID!=-1)
            {
               pLibro[posOfID].isEmpty=-1;
               retorno=0;
            }
        }
     }
    return retorno;
}

int libro_print(Libro* pLibro,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pLibro[i].isEmpty!=-1)
        {
            printf("\nID: %d\nTitulo: %s\nID Autor: %d\nPos i: %d\n-------",
                   pLibro[i].idLibro,pLibro[i].titulo,pLibro[i].idAutor,i);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

int libro_findFree(Libro* pLibro, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pLibro[i].isEmpty==-1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}
/** \brief busca el ID en el array Libro
 *
 * \param puntero al array Libro
 * \param
 * \return devuelve la posicion del array Libro donde esta la coincidencia
 *
 */



int libro_findLibroById(Libro* pLibro, int len, int idFind)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pLibro[i].idLibro==idFind)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int libro_getID (Libro* pLibro,int len,char* msgE,int tries, char* msg)
{
    int retorno=-1;
    int bufferID;

    if(pLibro!=NULL && len>0)
    {
        if(!utn_getInt(msg, msgE,0,999999,7,1,tries,&bufferID))
        {
            retorno=bufferID;
        }
    }
    return retorno;
}

static int generarIdLibro(void)
{
    static int idLibro=0;
    return idLibro++;
}
