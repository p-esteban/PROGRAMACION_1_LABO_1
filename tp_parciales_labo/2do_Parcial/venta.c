#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "venta.h"
#include "controller.h"



//falta criterio para map y reduce

///new
Venta* venta_new()
{
    return (Venta*) malloc(sizeof(Venta));
}

///new con paramentros
Venta* venta_newParametros(char* id,char* fecha,char* tipo, char* cuitCliente,char* cantidad, char* precioUnitario)
{
    Venta* returnAux = NULL;
    Venta* pAuxVenta;

    if( id != NULL && tipo != NULL && cuitCliente != NULL && fecha != NULL && cantidad !=NULL && precioUnitario !=NULL)
    {        pAuxVenta = venta_new();
        if(pAuxVenta != NULL)
        {
            if( !venta_setFecha(pAuxVenta,fecha)&&
                !venta_setTipo(pAuxVenta,tipo) &&
                !venta_setCuitCliente(pAuxVenta,cuitCliente) &&
                !venta_setCantidadStr(pAuxVenta,cantidad) &&
                !venta_setPrecioUnitarioStr(pAuxVenta,precioUnitario) &&
                !venta_setIdStr(pAuxVenta,id))
            {
                returnAux = pAuxVenta;
            }
            else
            {
                venta_delete(pAuxVenta);
            }
        }
    }
    return returnAux;
 }

 ///Delete

void venta_delete(Venta* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}



int venta_contarRevelados(void* this)
{
    int returnAux=0;
    int bufferCantidad;
    venta_getCantidad((Venta*)this,&bufferCantidad);
    returnAux=bufferCantidad;
    return returnAux;

}


int venta_criterioMayo150(void* this)
{
    int returnAux=0;
    int bufferCantidad;
    float bufferPrecioUnitario;
    float bufferTotal;

    if(this!=NULL)
    {
        venta_getCantidad((Venta*)this,&bufferCantidad);
        venta_getPrecioUnitario((Venta*)this,&bufferPrecioUnitario);
        bufferTotal=(float)bufferCantidad*bufferPrecioUnitario;
        if(bufferTotal>150)
        {
            returnAux++;
        }
    }
    return returnAux;
}

int venta_criterioMayo300(void* this)
{
    int returnAux=0;
    int bufferCantidad;
    float bufferPrecioUnitario;
    float bufferTotal;

    if(this!=NULL)
    {
        venta_getCantidad((Venta*)this,&bufferCantidad);
        venta_getPrecioUnitario((Venta*)this,&bufferPrecioUnitario);
        bufferTotal=(float)bufferCantidad*bufferPrecioUnitario;
        if(bufferTotal>300)
        {
            returnAux++;
        }
    }
    return returnAux;
}

int venta_criterioTipo(void* this)
{
    int returnAux=0;
    char bufferTipo [SIZE_STRING];

    if(this!=NULL)
    {
        venta_getTipo((Venta*)this,bufferTipo);
        if(!strcmp(bufferTipo,"POLAROID_11x9"))
        {
            returnAux++;
        }
        if(!strcmp(bufferTipo,"POLAROID_10x10"))
        {
            returnAux++;
        }
    }
    return returnAux;
}


/////////////////////////////////////////////////////////////

/// BUSCAR ID

int venta_searchById(LinkedList* pArrayListVenta, int valorBuscado, int* index)
{
    int returnAux=-1;
    int i;
    int bufferID;
    Venta* pAuxVenta=NULL;

    if(pArrayListVenta!=NULL )
    {
        for(i=0;i<ll_len(pArrayListVenta);i++)
        {
            pAuxVenta=ll_get(pArrayListVenta,i);
            venta_getId(pAuxVenta,&bufferID);

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
int venta_maxId(LinkedList* pArrayListVenta, int* maxID)
{
    int returnAux=-1;
    Venta* pAuxVenta=NULL;
    int i;
    int bufferId;
    int bufferMaxId=0;

    if(pArrayListVenta!=NULL && maxID!=NULL)
    {
        for(i=0;i<ll_len(pArrayListVenta);i++)
        {
            pAuxVenta=ll_get(pArrayListVenta,i);
            if(pAuxVenta!=NULL)
            {
                venta_getId(pAuxVenta,&bufferId);
                if(bufferId>bufferMaxId)
                    bufferMaxId=bufferId;
            }
        }
        *maxID=bufferMaxId;
        returnAux=0;
    }
    return returnAux;
}

/// BUSCAR INT
int venta_searchByCantidad(LinkedList* pArrayListVenta, int valorBuscado, int* index)
{
    int returnAux=-1;
    int i;
    int bufferCantidad;
    Venta* pAuxEpleado=NULL;

    if(pArrayListVenta!=NULL )
    {
        for(i=0;i<ll_len(pArrayListVenta);i++)
        {
            pAuxEpleado=ll_get(pArrayListVenta,i);
            venta_getCantidad(pAuxEpleado,&bufferCantidad); //cambiar funcion

            if(valorBuscado==bufferCantidad)
            {
                *index=i;
                returnAux=0;
            }
        }
    }
    return returnAux;
}

/// BUSCRA STRING
int venta_searchByTipo(LinkedList* pArrayListVenta, char* valorBuscado, int* index)
{
    int returnAux=-1;
    int i;
    char bufferTipo[SIZE_STRING];
    Venta* pAuxVenta=NULL;

    if(pArrayListVenta!=NULL )
    {
        for(i=0;i<ll_len(pArrayListVenta);i++)
        {
            pAuxVenta=ll_get(pArrayListVenta,i);
            venta_getTipo(pAuxVenta,bufferTipo); //cambiar funcion

            if(!strcmp(bufferTipo,valorBuscado))
            {
                *index=i;
                returnAux=0;
            }
        }
    }
    return returnAux;
}


int venta_criterioSortId(void* this1, void* this2)
{
    int returnAux =-1;
    int bufferI;
    int bufferJ;

    if(this1!=NULL && this2!=NULL)
    {
        venta_getId((Venta*)this1,&bufferI);
        venta_getId((Venta*)this2,&bufferJ);
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

int venta_setIdStr(Venta* this, char* id)
{
    int returnAux = -1;
    if(this != NULL && id != NULL && utn_isValidInt(id))
    {
        returnAux = venta_setId(this,atoi(id));;
    }
    return returnAux;
}

int venta_setId(Venta* this, int id)
{
    int returnAux = -1;
    if(this != NULL && id > 0)
    {
        this->id = id;
        returnAux = 0;
    }
    return returnAux;
}
int venta_getIdStr(Venta* this, char* result)
{
    int returnAux = -1;
    int bufferInt;
    if(this != NULL && result != NULL)
    {
        venta_getId(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        returnAux = 0;
    }
    return returnAux;
}

int venta_getId(Venta* this, int* result)
{
    int returnAux = -1;
    if(this != NULL && result != NULL)
    {
        *result = this->id;
        returnAux = 0;
    }
    return returnAux;
}

/// fecha

int venta_setFecha(Venta* this, char* fecha)
{
    int returnAux = -1;
    if(this != NULL && utn_isValidTexto(fecha))
    {
        strncpy(this->fecha,fecha,sizeof(this->fecha));
        returnAux = 0;
    }
    return returnAux;
}

int venta_getFecha(Venta* this, char* result)
{
    int returnAux = -1;
    if(this != NULL)
    {
        strncpy(result,this->fecha,sizeof(this->fecha));
        returnAux = 0;
    }
    return returnAux;
}


/// tipo

int venta_setTipo(Venta* this, char* tipo)
{
    int returnAux = -1;
    if(this != NULL && utn_isValidTexto(tipo)) //se puede usar isValidName
    {
        strncpy(this->tipo,tipo,sizeof(this->tipo));
        returnAux = 0;
    }
    return returnAux;
}

int venta_getTipo(Venta* this, char* result)
{
    int returnAux = -1;
    if(this != NULL)
    {
        strncpy(result,this->tipo,sizeof(this->tipo));
        returnAux = 0;
    }
    return returnAux;
}

/// cuitCliente


int venta_setCuitCliente(Venta* this, char* cuitCliente)
{
    int returnAux = -1;
    if(this != NULL && utn_isValidCuit(cuitCliente))
    {
        strncpy(this->cuitCliente,cuitCliente,sizeof(this->cuitCliente));
        returnAux = 0;
    }
    return returnAux;
}

int venta_getCuitCliente(Venta* this, char* result)
{
    int returnAux = -1;
    if(this != NULL)
    {
        strncpy(result,this->cuitCliente,sizeof(this->cuitCliente));
        returnAux = 0;
    }
    return returnAux;
}



/// cantidad

int venta_setCantidadStr(Venta* this, char* cantidad)
{
    int returnAux = -1;
    if(this != NULL && cantidad != NULL && utn_isValidInt(cantidad))
    {
        returnAux = venta_setCantidad(this,atoi(cantidad));
    }
    return returnAux;
}

int venta_setCantidad(Venta* this, int cantidad)
{
    int returnAux = -1;
    if(this != NULL && cantidad >= 0)
    {
        this->cantidad = cantidad;
        returnAux = 0;
    }
    return returnAux;
}

int venta_getCantidadStr(Venta* this, char* result)
{
    int returnAux = -1;
    int bufferInt;
    if(this != NULL && result != NULL)
    {
        venta_getCantidad(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        returnAux = 0;
    }
    return returnAux;
}


int venta_getCantidad(Venta* this, int* result)
{
    int returnAux = -1;
    if(this != NULL && result != NULL)
    {
        *result = this->cantidad;
        returnAux = 0;
    }
    return returnAux;
}
/// precioUnitario

int venta_setPrecioUnitarioStr(Venta* this, char* precioUnitario)
{
    int returnAux = -1;
    if(this != NULL && precioUnitario != NULL && utn_isValidFloat(precioUnitario))
    {
        returnAux = venta_setPrecioUnitario(this,atoi(precioUnitario));;
    }
    return returnAux;
}

int venta_setPrecioUnitario(Venta* this, float precioUnitario)
{
    int returnAux = -1;
    if(this != NULL && precioUnitario >= 0)
    {
        this->precioUnitario = precioUnitario;
        returnAux = 0;
    }
    return returnAux;
}

int venta_getPrecioUnitarioStr(Venta* this, char* result)
{
    int returnAux = -1;
    float bufferFloat;
    if(this != NULL && result != NULL)
    {
        venta_getPrecioUnitario(this,&bufferFloat);
        sprintf(result,"%f",bufferFloat);
        returnAux = 0;
    }
    return returnAux;
}


int venta_getPrecioUnitario(Venta* this, float* result)
{
    int returnAux = -1;
    if(this != NULL && result != NULL)
    {
        *result = this->precioUnitario;
        returnAux = 0;
    }
    return returnAux;
}
