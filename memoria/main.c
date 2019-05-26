#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main()
{
    Empleado *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    int auxInt;
    float auxFloat;
    char auxNom[50];
    int auxEstado;

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Emp_new();


    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("\nOK");
        if(!Emp_setId(pArrayEmpleado[indiceActual],14))
        {
            Emp_getId(pArrayEmpleado[indiceActual], &auxInt);
            printf("\n El id es %d",auxInt);

        }

    }

    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("\nOK");
        if(!Emp_setPeso(pArrayEmpleado[indiceActual],60.5))
        {
            Emp_getPeso(pArrayEmpleado[indiceActual], &auxFloat);
            printf("\n El peso es %f",auxFloat);

        }

    }

    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("\nOK");
        if(!Emp_setNombre(pArrayEmpleado[indiceActual],"Alguien"))
        {
            Emp_getNombre(pArrayEmpleado[indiceActual], auxNom);
            printf("\n El nombre es %s",auxNom);

        }
    }

    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("\nOK");
        if(!Emp_setEstado(pArrayEmpleado[indiceActual],1))
        {
            Emp_getEstado(pArrayEmpleado[indiceActual], &auxEstado);
            printf("\n El estado es %d",auxEstado);

        }

    }

    return 0;
}
