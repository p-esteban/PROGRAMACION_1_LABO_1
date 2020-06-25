#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "entrega.h"
#include "controller.h"



//falta criterio para map y reduce

///new
Entrega* entrega_new()
{
    return (Entrega*) malloc(sizeof(Entrega));
}

///new con paramentros
Entrega* entrega_newParametros(char* id,char* tipo,char* cantidad,char* importe)
{
    Entrega* returnAux = NULL;
    Entrega* pAuxEntrega;

    if( id != NULL && tipo != NULL && importe !=NULL && cantidad !=NULL)
    {        pAuxEntrega = entrega_new();
        if(pAuxEntrega != NULL)
        {
            if( !entrega_setTipo(pAuxEntrega,tipo) &&
                !entrega_setCantidadStr(pAuxEntrega,cantidad) &&
                !entrega_setImporteStr(pAuxEntrega,importe)&&
                !entrega_setIdStr(pAuxEntrega,id))
            {
                returnAux = pAuxEntrega;
            }
            else
            {
                entrega_delete(pAuxEntrega);
            }
        }
    }
    return returnAux;
 }

 ///Delete

void entrega_delete(Entrega* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}



int entrega_criterioFilterTipo(void* this,char* criterio)
{
    int returnAux=-1;
    char bufferTipo[SIZE_STRING];

    if(this!=NULL)
    {
        entrega_getTipo(this,bufferTipo);
        if(!strcmp(bufferTipo,criterio)  )          //remplazar entrega + campo
        {
            returnAux=0;
        }
    }
    return returnAux;
}



/////////////////////////////////////////////////////////////

/// BUSCAR ID

int entrega_searchById(LinkedList* pArrayListEntrega, int valorBuscado, int* index)
{
    int returnAux=-1;
    int i;
    int bufferID;
    Entrega* pAuxEntrega=NULL;

    if(pArrayListEntrega!=NULL )
    {
        for(i=0;i<ll_len(pArrayListEntrega);i++)
        {
            pAuxEntrega=ll_get(pArrayListEntrega,i);
            entrega_getId(pAuxEntrega,&bufferID);

            if(valorBuscado==bufferID)
            {
                *index=i;
                returnAux=0;
            }
        }
    }
    return returnAux;
}
/// BUSCAR ID MAX
int entrega_maxId(LinkedList* pArrayListEntrega, int* maxID)
{
    int returnAux=-1;
    Entrega* pAuxEntrega=NULL;
    int i;
    int bufferId;
    int bufferMaxId=0;

    if(pArrayListEntrega!=NULL && maxID!=NULL)
    {
        for(i=0;i<ll_len(pArrayListEntrega);i++)
        {
            pAuxEntrega=ll_get(pArrayListEntrega,i);
            if(pAuxEntrega!=NULL)
            {
                entrega_getId(pAuxEntrega,&bufferId);
                if(bufferId>bufferMaxId)
                    bufferMaxId=bufferId;
            }
        }
        *maxID=bufferMaxId;
        returnAux=0;
    }
    return returnAux;
}


/// CRITERIOS PARA ORDENAR

int entrega_criterioSortTipo(void* this1, void* this2)
{
    int returnAux=-1;

    char bufferI[SIZE_STRING];
    char bufferJ[SIZE_STRING];

    if(this1!=NULL && this2!=NULL)
    {
        entrega_getTipo((Entrega*)this1,bufferI);
        entrega_getTipo((Entrega*)this2,bufferJ);
        returnAux = strcmp(bufferI,bufferJ);
    }
    return returnAux;
}

int entrega_criterioSortId(void* this1, void* this2)
{
    int returnAux =-1;
    int bufferI;
    int bufferJ;

    if(this1!=NULL && this2!=NULL)
    {
        entrega_getId((Entrega*)this1,&bufferI);
        entrega_getId((Entrega*)this2,&bufferJ);
        if(bufferI>bufferJ)
            returnAux=1;
        if(bufferI<bufferJ)
            returnAux=-1;
        if(bufferI==bufferJ)
            returnAux=0;
    }
    return returnAux;
}



/// setters y getters

/// id

int entrega_setIdStr(Entrega* this, char* id)
{
    int returnAux = -1;
    if(this != NULL && id != NULL && utn_isValidInt(id))
    {
        returnAux = entrega_setId(this,atoi(id));;
    }
    return returnAux;
}

int entrega_setId(Entrega* this, int id)
{
    int returnAux = -1;
    if(this != NULL && id > 0)
    {
        this->id = id;
        returnAux = 0;
    }
    return returnAux;
}
int entrega_getIdStr(Entrega* this, char* result)
{
    int returnAux = -1;
    int bufferInt;
    if(this != NULL && result != NULL)
    {
        entrega_getId(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        returnAux = 0;
    }
    return returnAux;
}

int entrega_getId(Entrega* this, int* result)
{
    int returnAux = -1;
    if(this != NULL && result != NULL)
    {
        *result = this->id;
        returnAux = 0;
    }
    return returnAux;
}




/// tipo

int entrega_setTipo(Entrega* this, char* tipo)
{
    int returnAux = -1;
    if(this != NULL && utn_isValidTexto(tipo)) //se puede usar isValidName
    {
        strncpy(this->tipo,tipo,sizeof(this->tipo));
        returnAux = 0;
    }
    return returnAux;
}

int entrega_getTipo(Entrega* this, char* result)
{
    int returnAux = -1;
    if(this != NULL)
    {
        strncpy(result,this->tipo,sizeof(this->tipo));
        returnAux = 0;
    }
    return returnAux;
}


/// cantidad

int entrega_setCantidadStr(Entrega* this, char* cantidad)
{
    int returnAux = -1;
    if(this != NULL && cantidad != NULL && utn_isValidInt(cantidad))
    {
        returnAux = entrega_setCantidad(this,atoi(cantidad));
    }
    return returnAux;
}

int entrega_setCantidad(Entrega* this, int cantidad)
{
    int returnAux = -1;
    if(this != NULL && cantidad >= 0)
    {
        this->cantidad = cantidad;
        returnAux = 0;
    }
    return returnAux;
}

int entrega_getCantidadStr(Entrega* this, char* result)
{
    int returnAux = -1;
    int bufferInt;
    if(this != NULL && result != NULL)
    {
        entrega_getCantidad(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        returnAux = 0;
    }
    return returnAux;
}


int entrega_getCantidad(Entrega* this, int* result)
{
    int returnAux = -1;
    if(this != NULL && result != NULL)
    {
        *result = this->cantidad;
        returnAux = 0;
    }
    return returnAux;
}


/// importe

int entrega_setImporteStr(Entrega* this, char* importe)
{
    int returnAux = -1;
    if(this != NULL && importe != NULL && utn_isValidFloat(importe))
    {
        returnAux = entrega_setImporte(this,atoi(importe));;
    }
    return returnAux;
}

int entrega_setImporte(Entrega* this, float importe)
{
    int returnAux = -1;
    if(this != NULL && importe >= 0)
    {
        this->importe = importe;
        returnAux = 0;
    }
    return returnAux;
}

int entrega_getImporteStr(Entrega* this, char* result)
{
    int returnAux = -1;
    float bufferFloat;
    if(this != NULL && result != NULL)
    {
        entrega_getImporte(this,&bufferFloat);
        sprintf(result,"%f",bufferFloat);
        returnAux = 0;
    }
    return returnAux;
}


int entrega_getImporte(Entrega* this, float* result)
{
    int returnAux = -1;
    if(this != NULL && result != NULL)
    {
        *result = this->importe;
        returnAux = 0;
    }
    return returnAux;
}
