#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "fantasma.h"
#include "controller.h"



//falta criterio para map y reduce

///new
Fantasma* fantasma_new()
{
    return (Fantasma*) malloc(sizeof(Fantasma));
}

///new con paramentros
Fantasma* fantasma_newParametros(char* varId,char* varChar,char* varString, char* varLongString,char* varInt, char* varFloat)
{
    Fantasma* returnAux = NULL;
    Fantasma* pAuxFantasma;

    if( varId != NULL && varString != NULL && varLongString != NULL && varChar != NULL && varInt !=NULL && varFloat !=NULL)
    {        pAuxFantasma = fantasma_new();
        if(pAuxFantasma != NULL)
        {
            if( !fantasma_setVarChar(pAuxFantasma,varChar)&&
                !fantasma_setVarString(pAuxFantasma,varString) &&
                !fantasma_setVarLongString(pAuxFantasma,varLongString) &&
                !fantasma_setVarIntStr(pAuxFantasma,varInt) &&
                !fantasma_setvarFloatStr(pAuxFantasma,varFloat) &&
                !fantasma_setIdStr(pAuxFantasma,varId))
            {
                returnAux = pAuxFantasma;
            }
            else
            {
                fantasma_delete(pAuxFantasma);
            }
        }
    }
    return returnAux;
 }

 ///Delete

void fantasma_delete(Fantasma* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

/// Criterio para FILTER tiene que ser de un solo criterio
int fantasma_criterioFilterVarInt(Fantasma* fantasma)
{
    int returnAux=-1;

    if(fantasma!=NULL)
    {
        if(fantasma->varInt==condicion)             //remplazar fantasma + campo
        {
            returnAux=0;
        }
    }
    return returnAux;
}
int fantasma_criterioFilterVarFloat(Fantasma* fantasma)
{
    int returnAux=-1;

    if(fantasma!=NULL)
    {
        if(fantasma->varFloat==condicion)             //remplazar fantasma + campo
        {
            returnAux=0;
        }
    }
    return returnAux;
}
int fantasma_criterioFilterVarString(Fantasma* fantasma)
{
    int returnAux=-1;

    if(fantasma!=NULL)
    {
        if(!strcmp(fantasma->varInt,condicion)             //remplazar fantasma + campo
        {
            returnAux=0;
        }
    }
    return returnAux;
}

int fantasma_print(Fantasma* fantasma)
{
    int returnAux = -1;
    int i;
    char VarChar;
    char VarString[SIZE_STRING];
    char VarLongString[SIZE_STRING];
    int id;
    int VarInt;
    float VarSueldo;

    if(fantasma!=NULL)
    {
        fantasma_getVarChar(fantasma,VarChar);
        fantasma_getVarString(fantasma,VarString);
        fantasma_getVarLongString(fantasma,VarLongSring);
        fantasma_getId(fantasma,&id);
        fantasma_getVarFloat(fantasma,&VarFloat);
        fantasma_getVarInt(fantasma,&VarInt);
        printf("\nId:%-4d VarChar: %s  VarString: %s VarLongString: %s VarInt: %d VarFLoat: %f"   //cambiar
                ,id,VarChar,VarString,VarLongString,VarInt,VarFloat);
        returnAux=0;
    }


}

/////////////////////////////////////////////////////////////

/// BUSCAR ID

int fantasma_searchById(LinkedList* pArrayListFantasma, int valorBuscado, int* index)
{
    int returnAux=-1;
    int i;
    int bufferID;
    Fantasma* pAuxFantasma=NULL;

    if(pArrayListFantasma!=NULL )
    {
        for(i=0;i<ll_len(pArrayListFantasma);i++)
        {
            pAuxFantasma=ll_get(pArrayListFantasma,i);
            fantasma_getId(pAuxFantasma,&bufferID);

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
int fantasma_maxId(LinkedList* pArrayListFantasma, int* maxID)
{
    int returnAux=-1;
    Fantasma* pAuxFantasma=NULL;
    int i;
    int bufferId;
    int bufferMaxId=0;

    if(pArrayListFantasma!=NULL && maxID!=NULL)
    {
        for(i=0;i<ll_len(pArrayListFantasma);i++)
        {
            pAuxFantasma=ll_get(pArrayListFantasma,i);
            if(pAuxFantasma!=NULL)
            {
                fantasma_getId(pAuxFantasma,&bufferId);
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
int fantasma_searchByVarInt(LinkedList* pArrayListFantasma, int valorBuscado, int* index)
{
    int returnAux=-1;
    int i;
    int bufferVarInt;
    Fantasma* pAuxEpleado=NULL;

    if(pArrayListFantasma!=NULL )
    {
        for(i=0;i<ll_len(pArrayListFantasma);i++)
        {
            pAuxEpleado=ll_get(pArrayListFantasma,i);
            fantasma_getVarInt(pAuxEpleado,&bufferVarInt); //cambiar funcion

            if(valorBuscado==bufferVarInt)
            {
                *index=i;
                returnAux=0;
            }
        }
    }
    return returnAux;
}

/// BUSCRA STRING
int fantasma_searchByVarString(LinkedList* pArrayListFantasma, char* valorBuscado, int* index)
{
    int returnAux=-1;
    int i;
    char bufferVarString[SIZE_STRING];
    Fantasma* pAuxFantasma=NULL;

    if(pArrayListFantasma!=NULL )
    {
        for(i=0;i<ll_len(pArrayListFantasma);i++)
        {
            pAuxFantasma=ll_get(pArrayListFantasma,i);
            fantasma_getVarString(pAuxFantasma,bufferVarString); //cambiar funcion

            if(!strcmp(bufferVarString,valorBuscado))
            {
                *index=i;
                returnAux=0;
            }
        }
    }
    return returnAux;
}
/// BUSCAR VAR FLOAT

int fantasma_searchByVarFloat(LinkedList* pArrayListFantasma, float valorBuscado, int* index)
{
    int returnAux=-1;
    int i;
    float bufferVarInt;
    Fantasma* pAuxFantasma=NULL;

    if(pArrayListFantasma!=NULL )
    {
        for(i=0;i<ll_len(pArrayListFantasma);i++)
        {
            pAuxFantasma=ll_get(pArrayListFantasma,i);
            fantasma_getVarFloat(pAuxFantasma,&bufferVarFloat); //cambiar funcion

            if(valorBuscado==bufferVarFloat)
            {
                *index=i;
                returnAux=0;
            }
        }
    }
    return returnAux;
}
/// CRITERIOS PARA ORDENAR

int fantasma_criterioSortVarString(void* this1, void* this2)
{
    int returnAux=-1;

    char bufferI[SIZE_STRING];
    char bufferJ[SIZE_STRING];

    if(this1!=NULL && this2!=NULL)
    {
        fantasma_getVarString((Fantasma*)this1,bufferI);
        fantasma_getVarString((Fantasma*)this2,bufferJ);
        returnAux = strcmp(bufferI,bufferJ);
    }
    return returnAux;
}

int fantasma_criterioSortId(void* this1, void* this2)
{
    int returnAux =-1;
    int bufferI;
    int bufferJ;

    if(this1!=NULL && this2!=NULL)
    {
        fantasma_getId((Fantasma*)this1,&bufferI);
        fantasma_getId((Fantasma*)this2,&bufferJ);
        if(bufferI>bufferJ)
            returnAux=1;
        if(bufferI<bufferJ)
            returnAux=-1;
        if(bufferI==bufferJ)
            returnAux=0;
    }
    return returnAux;
}

int fantasma_criterioSortVarFLoat(void* this1, void* this2)
{
    int returnAux =-1;
    float bufferI;
    float bufferJ;

    if(this1!=NULL && this2!=NULL)
    {
        fantasma_getVarFloat((Fantasma*)this1,&bufferI);
        fantasma_getVarFloat((Fantasma*)this2,&bufferJ);
        if(bufferI>bufferJ)
            returnAux=1;
        if(bufferI<bufferJ)
            returnAux=-1;
        if(bufferI==bufferJ)
            returnAux=0;
    }
    return returnAux;
}

int fantasma_criterioSortVarInt(void* this1, void* this2)
{
    int returnAux =-1;
    int bufferI;
    int bufferJ;

    if(this1!=NULL && this2!=NULL)
    {
        fantasma_getVarInt((Fantasma*)this1,&bufferI);
        fantasma_getVarInt((Fantasma*)this2,&bufferJ);
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

int fantasma_setIdStr(Fantasma* this, char* varId)
{
    int returnAux = -1;
    if(this != NULL && varId != NULL && utn_isValidInt(varId))
    {
        returnAux = fantasma_setId(this,atoi(varId));;
    }
    return returnAux;
}

int fantasma_setId(Employee* this, int varId)
{
    int returnAux = -1;
    if(this != NULL && varId > 0)
    {
        this->varId = varId;
        returnAux = 0;
    }
    return returnAux;
}
int fantasma_getIdStr(Fantasma* this, char* result)
{
    int returnAux = -1;
    int bufferInt;
    if(this != NULL && result != NULL)
    {
        fantasma_getId(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        returnAux = 0;
    }
    return returnAux;
}

int fantasma_getId(Fantasma* this, int* result)
{
    int returnAux = -1;
    if(this != NULL && result != NULL)
    {
        *result = this->id;
        returnAux = 0;
    }
    return returnAux;
}

/// varChar

int fantasma_setVarChar(Fantasma* this, char* varChar)
{
    int returnAux = -1;
    if(this != NULL && isValidChar(varChar,1,sizeof(char)))
    {
        strncpy(this->varChar,varChar,sizeof(this->varChar));
        returnAux = 0;
    }
    return returnAux;
}

int fantasma_getVarChar(Fantasma* this, char* result)
{
    int returnAux = -1;
    if(this != NULL)
    {
        strncpy(result,this->varChar,sizeof(this->varChar));
        returnAux = 0;
    }
    return returnAux;
}


/// varString

int fantasma_setVarString(Fantasma* this, char* varString)
{
    int returnAux = -1;
    if(this != NULL && utn_isValidTexto(varString)) //se puede usar isValidName
    {
        strncpy(this->varString,varString,sizeof(this->varString));
        returnAux = 0;
    }
    return returnAux;
}

int fantasma_getVarString(Fantasma* this, char* result)
{
    int returnAux = -1;
    if(this != NULL)
    {
        strncpy(result,this->varString,sizeof(this->varString));
        returnAux = 0;
    }
    return returnAux;
}

/// varLongString


int fantasma_setVarLongString(Fantasma* this, char* varLongString)
{
    int returnAux = -1;
    if(this != NULL && utn_isValidTexto(varLongString))
    {
        strncpy(this->varLongString,varLongString,sizeof(this->varLongString));
        returnAux = 0;
    }
    return returnAux;
}

int fantasma_getVarLongString(Fantasma* this, char* result)
{
    int returnAux = -1;
    if(this != NULL)
    {
        strncpy(result,this->varLongString,sizeof(this->varLongString));
        returnAux = 0;
    }
    return returnAux;
}



/// varInt

int fantasma_setVarIntStr(Fantasma* this, char* varInt)
{
    int returnAux = -1;
    if(this != NULL && varInt != NULL && utn_isValidInt(varInt))
    {
        returnAux = fantasma_setVarInt(this,atoi(varInt));
    }
    return returnAux;
}

int fantasma_setVarInt(Fantasma* this, int varInt)
{
    int returnAux = -1;
    if(this != NULL && varInt >= 0)
    {
        this->varInt = varInt;
        returnAux = 0;
    }
    return returnAux;
}

int fantasma_getVarIntStr(Fantasma* this, char* result)
{
    int returnAux = -1;
    int bufferInt;
    if(this != NULL && result != NULL)
    {
        fantasma_getVarInt(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        returnAux = 0;
    }
    return returnAux;
}


int fantasma_getVarInt(Fantasma* this, int* result)
{
    int returnAux = -1;
    if(this != NULL && result != NULL)
    {
        *result = this->varInt;
        returnAux = 0;
    }
    return returnAux;
}
/// varFloat

int fantasma_setVarFloatStr(Fantasma* this, char* varFloat)
{
    int returnAux = -1;
    if(this != NULL && varFloat != NULL && utn_isValidFloat(varFloat))
    {
        returnAux = fantasma_setVarFloat(this,atoi(varFloat));;
    }
    return returnAux;
}

int fantasma_setVarFloat(Fantasma* this, float varFloat)
{
    int returnAux = -1;
    if(this != NULL && varFloat >= 0)
    {
        this->varFloat = varFloat;
        returnAux = 0;
    }
    return returnAux;
}

int fantasma_getVarFloatStr(Fantasma* this, char* result)
{
    int returnAux = -1;
    float bufferFloat;
    if(this != NULL && result != NULL)
    {
        fantasma_getVarFloat(this,&bufferFloat);
        sprintf(result,"%f",bufferFloat);
        returnAux = 0;
    }
    return returnAux;
}


int fantasma_getVarFloat(Fantasma* this, float* result)
{
    int returnAux = -1;
    if(this != NULL && result != NULL)
    {
        *result = this->varFloat;
        returnAux = 0;
    }
    return returnAux;
}
