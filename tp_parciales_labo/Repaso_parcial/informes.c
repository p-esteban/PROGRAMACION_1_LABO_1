#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "entrega.h"
#include "controller.h"

int informes_calculoContadorAcumulado(LinkedList* pArrayList, int* contadorGold, int* contadorRegular, int* contadorPlus,int* acumuladorCantidad, int* promedioEntrega, float* importePromedio )
{
    int returnAux =-1;
    float acumuladorImporte=0;
    int i;
    int bufferCantidad=0;
    float bufferImporte=0;
    Entrega* pEntrega;

    if(pArrayList!=NULL)
    {

        for(i=0;i<ll_len(pArrayList);i++)
        {
            pEntrega=ll_get(pArrayList,i);

            entrega_getCantidad(pEntrega,&bufferCantidad);
            *acumuladorCantidad=+bufferCantidad;

            entrega_getImporte(pEntrega,&bufferImporte);
            acumuladorImporte=+bufferImporte;

            if(!entrega_criterioFilterTipo(pEntrega,"GOLD"))
                (*contadorGold)++;
            if(!entrega_criterioFilterTipo(pEntrega,"REGULAR"))
                (*contadorRegular)++;
            if(!entrega_criterioFilterTipo(pEntrega,"PLUS"))
                (*contadorPlus)++;
       }
       *promedioEntrega=(*acumuladorCantidad)/ll_len(pArrayList);
       *importePromedio=(float)acumuladorImporte/ll_len(pArrayList);
       returnAux=0;

    }

    return returnAux;
}
