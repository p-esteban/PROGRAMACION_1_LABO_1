#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "empleado.h"

Empleado* Emp_new(void)
{
    return (Empleado*) malloc(sizeof(Empleado));
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



int Emp_setPeso(Empleado* this, float peso)
{
    int retorno = -1;

    if(this != NULL && peso >=0)
    {
        this->peso = peso;
        retorno = 0;
    }
    return retorno;

}
int Emp_getPeso(Empleado* this, float* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->peso;
        retorno = 0;
    }
    return retorno;
}



int Emp_setNombre(Empleado* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && utn_isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        //this->nombre = nombre;
        retorno = 0;
    }
    return retorno;

}
int Emp_getNombre(Empleado* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->nombre);
        //*resultado = this->nombre;
        retorno = 0;
    }
    return retorno;
}

int Emp_setEstado(Empleado* this, int estado)
{
    int retorno = -1;

    if(this != NULL && estado >=0)
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;

}
int Emp_getEstado(Empleado* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->estado;
        retorno = 0;
    }
    return retorno;
}






