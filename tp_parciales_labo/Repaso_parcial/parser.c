#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "entrega.h"

/** \brief Parsea los datos los datos de entrega desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int
 *
 */
int parser_entregaFromText(FILE* pFile , LinkedList* pArrayListEntrega)
{
    int returnAux= 1;
    char bufferId[4096];
    char bufferTipo[4096];
    char bufferCantidad[4096];
    char bufferImporte[4096];
    Entrega *pEntrega;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,bufferTipo,bufferCantidad,bufferImporte);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,bufferTipo,bufferCantidad,bufferImporte);

            pEntrega = entrega_newParametros(bufferId,bufferTipo,bufferCantidad,bufferImporte);

            if(pEntrega != NULL)
            {
                if(!ll_add(pArrayListEntrega,pEntrega))
                    returnAux = 0;
            }
        }
    }
    return returnAux;
}
