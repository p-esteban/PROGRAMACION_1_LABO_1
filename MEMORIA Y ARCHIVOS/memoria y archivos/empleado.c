#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

Empleado* Emp_new(void)
{
    return (Empleado*) malloc(sizeof(Empleado));
}

Empleado* Emp_newStr(   char* id,
                        char* nombre,
                        char* apellido,
                        char* estado)
{
    Empleado* retorno = NULL;
    Empleado* pAuxEmpleado;

    if( id != NULL && nombre != NULL &&
        apellido != NULL && estado != NULL)
    {        pAuxEmpleado = Emp_new();
        if(pAuxEmpleado != NULL)
        {
            if( !Emp_setNombre(pAuxEmpleado,nombre) &&
                !Emp_setApellido(pAuxEmpleado,apellido) &&
                !Emp_setIdStr(pAuxEmpleado,id) &&
                !Emp_setEstadoStr(pAuxEmpleado,estado))
            {
                retorno = pAuxEmpleado;
            }
            else
            {
                Emp_delete(pAuxEmpleado);
            }
        }
    }
}








int Emp_delete(Empleado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Emp_setId(Empleado* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}


int Emp_setIdStr(Empleado* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL && !isValidNumber(id))
    {
        retorno = Emp_setId(this,atoi(id));;
    }
    return retorno;
}




int Emp_getId(Empleado* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}


int Emp_getIdStr(Empleado* this, char* resultado)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && resultado != NULL)
    {
        Emp_getId(this,&bufferInt);
        sprintf(resultado,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}



int Emp_setPeso(Empleado* this, float peso);
int Emp_getPeso(Empleado* this, float* resultado);
int Emp_setNombre(Empleado* this, char* nombre);
int Emp_getNombre(Empleado* this, char* resultado);
int Emp_setEstado(Empleado* this, int estado);
int Emp_getEstado(Empleado* this, int* resultado);






