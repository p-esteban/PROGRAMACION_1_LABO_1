#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "venta.h"

/** \brief Parsea los datos los datos de venta desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int parser_VentaFromText(FILE* pFile , LinkedList* pArrayListVenta)
{
    int returnAux= 1;
    char bufferId[4096];
    char bufferFecha[4096];
    char bufferTipo[4096];
    char bufferCantidad[4096];
    char bufferPrecioUnitario[4096];
    char bufferCuitCliente[4096];
    Venta *pVenta;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,bufferFecha,bufferTipo,bufferCantidad,bufferPrecioUnitario,bufferCuitCliente);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,bufferFecha,bufferTipo,bufferCantidad,bufferPrecioUnitario,bufferCuitCliente);


            pVenta = venta_newParametros( bufferId,bufferFecha,bufferTipo,bufferCuitCliente,bufferCantidad,bufferPrecioUnitario);

            if(pVenta != NULL)
            {
                if(!ll_add(pArrayListVenta,pVenta))
                    returnAux = 0;
            }
        }
    }
    return returnAux;
}
