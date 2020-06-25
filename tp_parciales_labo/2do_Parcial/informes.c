#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "venta.h"
#include "controller.h"


int informes_totalRevelados(LinkedList* pArrayList, int* cantidadTotal)
{
    int returnAux=-1;

    if(pArrayList!=NULL)
    {
        *cantidadTotal=ll_count(pArrayList,venta_contarRevelados);

    }
    return returnAux;
}


int informes_montoMayo150(LinkedList* pArrayList, int* cantMayor150)
{
    int returnAux=-1;

    if(pArrayList!=NULL)
    {
        *cantMayor150=ll_count(pArrayList,venta_criterioMayo150);
        returnAux=0;

    }
    return returnAux;

}

int informes_montoMayo300(LinkedList* pArrayList, int* cantMayor300)
{
    int returnAux=-1;

    if(pArrayList!=NULL)
    {
        *cantMayor300=ll_count(pArrayList,venta_criterioMayo300);
        returnAux=0;

    }
    return returnAux;

}

int informes_cantidadPolaroid(LinkedList* pArrayList, int* cantPolaroid)
{
    int returnAux=-1;

    if(pArrayList!=NULL)
    {
        *cantPolaroid=ll_count(pArrayList,venta_criterioTipo);
        returnAux=0;
    printf("\nPOLAROID: %d",*cantPolaroid);
    }
    return returnAux;

}
