#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDAD_ALUMNOS 5

int main()
{
    int aEdades[CANTIDAD_ALUMNOS] = {2,51,1,8,0};
    //getArrayInt("Ingrese edad","Edad invalida",120,0,5,aEdades,CANTIDAD_ALUMNOS);
    printArrayInt(aEdades,CANTIDAD_ALUMNOS);
    sortArrayInt(aEdades,CANTIDAD_ALUMNOS);
    printf("\n\nORDENADO\n");
    printArrayInt(aEdades,CANTIDAD_ALUMNOS);
}
