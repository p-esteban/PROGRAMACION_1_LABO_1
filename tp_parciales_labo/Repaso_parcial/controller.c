#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "entrega.h"
#include "controller.h"
#include "informes.h"

#define SIZE_STRING 51
#define SIZE_ID 10
#define SIZE_VARFLOAT 15
#define SIZE_VARINT 15
#define TRIES 2

/** \brief Carga los datos de  entrega desde el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero a lista de entrega
 * \return int returnAux (-1) en caso de error o punteros NULL (0) si carga correctamente
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEntrega)
{
    int returnAux=-1;
    FILE* pFile = NULL;

    if(path!=NULL && pArrayListEntrega!=NULL)
    {
        ll_clear(pArrayListEntrega);           //revisar!!
        pFile=fopen(path,"r");
        if(pFile!=NULL)
        {
            printf("\n  CARGANDO...\n");
            returnAux=parser_entregaFromText(pFile,pArrayListEntrega);
            fclose(pFile);
        }
    }
    return returnAux;
}





/** \brief Guarda los datos de los entrega en el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo
 * \param pArrayListEntrega LinkedList* puntero a lista de entrega
 * \return int returnAux (-1) en caso de error o punteros NULL (0) si guarda en el archivo correctamente
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEntrega)
{
    int returnAux=-1;
    int cantidadGold=0;
    int cantidadRegular=0;
    int cantidadPlus=0;
    int totalBulos=0;
    int promedioEntregas;
    float importePromedio;

    FILE* pFile=NULL;

    printf("\nEntre\n");

    if(path != NULL)
    {
        pFile=fopen(path,"w");

        printf("\nEntre1\n");
        if(pFile!=NULL && pArrayListEntrega !=NULL )
        {
            printf("\nEntre2\n");
            if(!informes_calculoContadorAcumulado(pArrayListEntrega,&cantidadGold,&cantidadRegular,&cantidadPlus,&totalBulos,&promedioEntregas,&importePromedio))
            {
                printf("\nEntreInformes\n");
                fprintf(pFile,"*****************\n");
                fprintf(pFile,"Informe ventas\n");
                fprintf(pFile,"*****************\n");
                fprintf(pFile,"Cantidad total de entregas %d\n",ll_len(pArrayListEntrega));
                fprintf(pFile,"- Cantidad total de entregas: %d  (GOLD)- %d (REGUAR) - %d (PLUS)\n",cantidadGold,cantidadRegular,cantidadPlus);
                fprintf(pFile,"- Cantidad total de bultos entregados: %d\n",totalBulos);
                fprintf(pFile,"- Promedio de bultos por entrega: %d\n",promedioEntregas);
                fprintf(pFile,"- Importe promedio por entrega: %f\n",importePromedio);
            }
        fclose(pFile);
        returnAux=0;
        }
    }
    return returnAux;
}
