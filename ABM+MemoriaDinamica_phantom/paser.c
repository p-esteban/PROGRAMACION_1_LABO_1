#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Fantasma.h"

/** \brief Parsea los datos los datos de fantasma desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int parser_FantasmaFromText(FILE* pFile , LinkedList* pArrayListFantasma)
{
    int returnAux= 1;
    char bufferId[4096];
    char bufferVarChar[4096];
    char bufferVarString[4096];
    char bufferVarLongString[4096];
    char bufferVarInt[4096];
    char bufferVarFloat[4096];
    Fantasma *pFantasma;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,bufferVarChar,bufferVarString,bufferVarLongString,bufferVarInt,bufferVarFloat);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId,bufferVarChar,bufferVarString,bufferVarLongString,bufferVarInt,bufferVarFloat);

            pFantasma = fantasma_newParametros(bufferId,bufferVarChar,bufferVarString,bufferVarLongString,bufferVarInt,bufferVarFloat);

            if(pFantasma != NULL)
            {
                if(!ll_add(pArrayListFantasma,pFantasma))
                    returnAux = 0;
            }
        }
    }
    return returnAux;
}

/** \brief Parsea los datos los datos de fantasma desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int parser_FantasmaFromBinary(FILE* pFile , LinkedList* pArrayListFantasma)
{

    int returnAux=1;
    Fantasma* pFantasma;

    do
    {
        pFantasma = fantasma_new();
        if(fread(pFantasma,sizeof(Fantasma),1, pFile)!=0) //porque cuento con 1
        {
            ll_add(pArrayListFantasma,pFantasma);
            returnAux=0;
        }
        else
        {
            fantasma_delete(pFantasma);
        }

    }while( !feof(pFile));

    return returnAux;
}
