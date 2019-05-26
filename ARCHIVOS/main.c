#include <stdio.h>
#include <stdlib.h>
#include "persona.h"


int main()
{
    Persona *pArrayPersona[1000];
    int ultimoElementoArrayPersona = 0;
    int indiceActual;
    int auxInt;
    char auxNom[50];
    int auxEstado;

    indiceActual = ultimoElementoArrayPersona;
    pArrayPersona[indiceActual] =  Pers_new();










    if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        printf("\nOK");
        if(!Pers_setId(pArrayPersona[indiceActual],14))
        {
            Pers_getId(pArrayPersona[indiceActual], &auxInt);
            printf("\n El id es %d",auxInt);

        }

    }


    if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        printf("\nOK");
        if(!Pers_setNombre(pArrayPersona[indiceActual],"Alguien"))
        {
            Pers_getNombre(pArrayPersona[indiceActual], auxNom);
            printf("\n El nombre es %s",auxNom);

        }
    }

    if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        printf("\nOK");
        if(!Pers_setEstado(pArrayPersona[indiceActual],1))
        {
            Pers_getEstado(pArrayPersona[indiceActual], &auxEstado);
            printf("\n El estado es %d",auxEstado);

        }

    }

    return 0;
}
