#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Asociado.h"
#include "Llamada.h"
#include "utn.h"
static int generarId(void);

int llam_init(Llamada* pLlamada,int len)
{
    int i;
    if(pLlamada!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pLlamada[i].idLlamada=-1;
            pLlamada[i].estado=-1;
        }
    }
    return 0;
}

int llam_add(Llamada* pLlamada,Asociado* pAsociado,int len,char* msgE,int tries, int pIndex)
{
    int auxID;
    int posOfId;
    int bufferMotivo;
    float bufferHoraEntrada;

    int retorno=-1;
    if((pLlamada!=NULL)&&(len>0))
    {
        auxID=llam_getID(pLlamada,len,msgE,tries,"\nIngrese ID: ");///hacer funcion

/////////////////

        //posOfId=llam_findCallById(pLlamada,len,auxID);///hacer funcion /// buscar posicion libre en llamadas
        if((auxID>=0 )&&(pIndex!=-1))
        {
            if((!utn_getInt("\nIngrese Motivo: ",msgE,0,3,2,1,tries,&bufferMotivo))&&
                (!utn_getFloat("\nIngrese la Hora (HH.MM): ", msgE,0,25,6,5,tries,&bufferHoraEntrada)))
            {
                    pLlamada[pIndex].motivo=bufferMotivo;
                    pLlamada[pIndex].idAsociado=auxID;
                    pLlamada[pIndex].horaEntrada=bufferHoraEntrada;
                    pLlamada[pIndex].idLlamada=generarId();///hacer funcion
                    pLlamada[pIndex].estado=0;
                    retorno=0;
            }
        }
        else
        {
            printf("\n----EL ID no es valido!----\n");
        }
    }

    return retorno;
}

//////////////////////////////////////
int llam_asignar(Llamada* pLlamada, int len,char* msgE,int tries)
{

    int auxID;
    int auxIDAmb;
    int posOfID;
    float bufferHoraSalida;

    int retorno=-1;

    if((pLlamada!=NULL)&&(len>0))
    {
        auxID=llam_getID(pLlamada,len,msgE,tries,"\nIngrese ID LLAMADA: ");//// hacer funcion
        if(auxID>=0)
        {
            posOfID=llam_findCallByIdAndEstado(pLlamada,len,auxID);//// hacer funcion
            auxIDAmb=llam_getID(pLlamada,len,msgE,tries,"\nIngrese ID AMBULANCIA: ");//// hacer funcion
            if((posOfID!=-1)&&(auxIDAmb>=0))
            {
                if(utn_getFloat("\nIngrese la Hora (HH.MM): ", msgE,0,25,6,5,tries,&bufferHoraSalida))
                {
                    pLlamada[posOfID].tiempo=pLlamada[posOfID].horaEntrada-bufferHoraSalida;
                    pLlamada[posOfID].idAmbulancia=auxIDAmb;
                    pLlamada[posOfID].estado=1;
                    retorno=0;

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

int llam_findCallByIdAndEstado(Llamada* pLlamada, int len, int idFind)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if((pLlamada[i].idLlamada==idFind)&&(pLlamada[i].estado==0))
        {
            ret=i;
            break;
        }
    }
    return ret;
}
int llam_findCallById(Llamada* pLlamada, int len, int idFind)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pLlamada[i].idLlamada==idFind)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int llam_getID (Llamada* pLlamada,int len,char* msgE,int tries, char* msg)
{
    int retorno=-1;
    int bufferID;

    if(pLlamada!=NULL && len>0)
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
    int flag=-1;
    static int id=0;
    flag = 1;
    if(flag)
    return id++;
}
int llam_findFree(Llamada* pLlamada, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pLlamada[i].estado==-1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}
int llam_print(Llamada* pLlamada,int len)///muestra solo llamadas pendientes
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pLlamada[i].estado==0)
        {
            printf("\nID LLAMADA: %d\nID Asociado: %d\nMotivo (1-infarto 2-ACV 3-Gripe): %d\nEstado(0-pendiente 1-cumplido): %d\n-------",
                   pLlamada[i].idLlamada,pLlamada[i].idAsociado,pLlamada[i].motivo,pLlamada[i].estado);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}
