#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#define SIZE_NOMBRE 128
#define SIZE_ID 10

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* retorno = NULL;
    Employee* pAuxEmpleado;

    if( idStr != NULL && nombreStr != NULL &&
        horasTrabajadasStr != NULL && sueldoStr != NULL)
    {        pAuxEmpleado = employee_new();
        if(pAuxEmpleado != NULL)
        {
            if( !employee_setNombre(pAuxEmpleado,nombreStr) &&
                !employee_setHorasTrabajadasStr(pAuxEmpleado,horasTrabajadasStr) &&
                !employee_setSueldoStr(pAuxEmpleado,sueldoStr) &&
                !employee_setIdStr(pAuxEmpleado,idStr))
            {
                retorno = pAuxEmpleado;
            }
            else
            {
                employee_delete(pAuxEmpleado);
            }
        }
    }
    return retorno;
 }



////
void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}


int employee_setIdStr(Employee* this, char* idStr)
{
    int retorno = -1;
    if(this != NULL && idStr != NULL && utn_isValidInt(idStr))
    {
        retorno = employee_setId(this,atoi(idStr));;
    }
    return retorno;
}

int employee_setId(Employee* this, int id)
{
    int retorno = -1;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_getIdStr(Employee* this, char* resultado)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && resultado != NULL)
    {
        employee_getId(this,&bufferInt);
        sprintf(resultado,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}


int employee_getId(Employee* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

///

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && utn_isValidTexto(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
///
int employee_setHorasTrabajadasStr(Employee* this, char* horasTrabajadasStr)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadasStr != NULL && utn_isValidInt(horasTrabajadasStr))
    {
        retorno = employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr));
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadasStr)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadasStr >= 0)
    {
        this->horasTrabajadas = horasTrabajadasStr;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadasStr(Employee* this, char* resultado)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && resultado != NULL)
    {
        employee_getHorasTrabajadas(this,&bufferInt);
        sprintf(resultado,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}


int employee_getHorasTrabajadas(Employee* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
///

int employee_setSueldoStr(Employee* this, char* sueldoStr)
{
    int retorno = -1;
    if(this != NULL && sueldoStr != NULL && utn_isValidInt(sueldoStr))
    {
        retorno = employee_setSueldo(this,atoi(sueldoStr));;
    }
    return retorno;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldoStr(Employee* this, char* resultado)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && resultado != NULL)
    {
        employee_getSueldo(this,&bufferInt);
        sprintf(resultado,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}


int employee_getSueldo(Employee* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->sueldo;
        retorno = 0;
    }
    return retorno;
}
/////////////////////////////////////////////////////////////

int employee_searchById(LinkedList* pArrayListEmployee, int valorBuscado, int* index)
{
    int retorno=-1;
    int i;
    int bufferID;
    Employee* pAuxEpleado=NULL;

    if(pArrayListEmployee!=NULL )
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pAuxEpleado=ll_get(pArrayListEmployee,i);
            employee_getId(pAuxEpleado,&bufferID);

            if(valorBuscado==bufferID)
            {
                *index=i;
                retorno=0;
            }
        }
    }
    return retorno;
}

int employee_maxId(LinkedList* pArrayListEmployee, int* maxID)
{
    int retorno=-1;
    Employee* pAuxEpleado=NULL;
    int i;
    int bufferId;
    int bufferMaxId=0;

    if(pArrayListEmployee!=NULL && maxID!=NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pAuxEpleado=ll_get(pArrayListEmployee,i);
            if(pAuxEpleado!=NULL)
            {
                employee_getId(pAuxEpleado,&bufferId);
                if(bufferId>bufferMaxId)
                    bufferMaxId=bufferId;
            }
        }
        *maxID=bufferMaxId;
        retorno=0;
    }
    return retorno;
}

int employee_criterioName(void* this1, void* this2)
{
    int retorno=-1;

    char bufferI[SIZE_NOMBRE];
    char bufferJ[SIZE_NOMBRE];

    if(this1!=NULL && this2!=NULL)
    {
        employee_getNombre((Employee*)this1,bufferI);
        employee_getNombre((Employee*)this2,bufferJ);
        retorno = strcmp(bufferI,bufferJ);
    }
    return retorno;
}

int employee_criterioId(void* this1, void* this2)
{
    int retorno =-1;
    int bufferI;
    int bufferJ;

    if(this1!=NULL && this2!=NULL)
    {
        employee_getId((Employee*)this1,&bufferI);
        employee_getId((Employee*)this2,&bufferJ);
        if(bufferI>bufferJ)
            retorno=1;
        if(bufferI<bufferJ)
            retorno=-1;
        if(bufferI==bufferJ)
            retorno=0;
    }
    return retorno;
}

int employee_criterioHoras(void* this1, void* this2)
{
    int retorno =-1;
    int bufferI;
    int bufferJ;

    if(this1!=NULL && this2!=NULL)
    {
        employee_getHorasTrabajadas((Employee*)this1,&bufferI);
        employee_getHorasTrabajadas((Employee*)this2,&bufferJ);
        if(bufferI>bufferJ)
            retorno=1;
        if(bufferI<bufferJ)
            retorno=-1;
        if(bufferI==bufferJ)
            retorno=0;
    }
    return retorno;
}

int employee_criterioSueldo(void* this1, void* this2)
{
    int retorno =-1;
    int bufferI;
    int bufferJ;

    if(this1!=NULL && this2!=NULL)
    {
        employee_getSueldo((Employee*)this1,&bufferI);
        employee_getSueldo((Employee*)this2,&bufferJ);
        if(bufferI>bufferJ)
            retorno=1;
        if(bufferI<bufferJ)
            retorno=-1;
        if(bufferI==bufferJ)
            retorno=0;
    }
    return retorno;
}
