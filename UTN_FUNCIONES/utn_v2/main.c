#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char cuit[180];

    utn_getCuit("\nIngrese: ", "\Error",18,11,3,cuit);
    //utn_getString("\nIngrese: ", "\Error",11,18,3,cuit);
    printf("\nCuit Obtenido!!! %s\n",cuit);
    return 0;
}
