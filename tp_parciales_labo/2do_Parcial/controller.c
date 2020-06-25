#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "venta.h"
#include "controller.h"
#include "informes.h"

#define SIZE_STRING 51
#define SIZE_ID 10
#define SIZE_VARFLOAT 15
#define SIZE_VARINT 15
#define TRIES 2

/** \brief Carga los datos de  venta desde el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero a lista de venta
 * \return int returnAux (-1) en caso de error o punteros NULL (0) si carga correctamente
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListVenta)
{
    int returnAux=-1;
    FILE* pFile = NULL;

    if(path!=NULL && pArrayListVenta!=NULL)
    {
        printf("\nEstoy aca");
        ll_clear(pArrayListVenta);           //revisar!!
        pFile=fopen(path,"r");
        if(pFile!=NULL)
        {
            printf("\n  CARGANDO...\n");
            returnAux=parser_VentaFromText(pFile,pArrayListVenta);
            ll_sort(pArrayListVenta,venta_criterioSortId,1);          //cambiar funcion criterio
            fclose(pFile);
        }
    }
    return returnAux;
}


/** \brief Guarda los datos de los venta en el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo
 * \param pArrayListVenta LinkedList* puntero a lista de venta
 * \return int returnAux (-1) en caso de error o punteros NULL (0) si guarda en el archivo correctamente
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListVenta)
{
    int returnAux=-1;
    FILE* pFile=NULL;
    int cantidadTotal=0;
    int cantidadMayor150=0;
    int cantidadMayor300=0;
    int cantidadPolariod=0;

    if(path != NULL)
    {
        pFile=fopen(path,"w");

        if(pFile!=NULL && pArrayListVenta !=NULL)
        {


            informes_totalRevelados(pArrayListVenta,&cantidadTotal);
            informes_montoMayo150(pArrayListVenta,&cantidadMayor150);
            informes_montoMayo300(pArrayListVenta,&cantidadMayor300);
            informes_cantidadPolaroid(pArrayListVenta,&cantidadPolariod);


            printf("\nEntre en guardar");

            fprintf(pFile,"*****************\n");
            fprintf(pFile,"Informe ventas\n");
            fprintf(pFile,"*****************\n");
            fprintf(pFile,"- Cantidad de fotos reveladas %d\n",cantidadTotal);
            fprintf(pFile,"- Cantidad de ventas por un monto mayor 150: %d\n",cantidadMayor150);
            fprintf(pFile,"- Cantidad de ventas por un monto mayor 300: %d\n",cantidadMayor300);
            fprintf(pFile,"- Cantidad de fotos Polaroid reveladas: %d\n",cantidadPolariod);



        }
        fclose(pFile);
        returnAux=0;

    }
    return returnAux;
}

/** \brief Guarda los datos de venta en el archivo data.csv (modo binario).
 *
 * \param path char* puntero al archivo
 * \param pArrayListVenta LinkedList* puntero a lista de venta
 * \return int returnAux (-1) en caso de error o punteros NULL (0) si guarda en el archivo correctamente
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListVenta)
{
    int returnAux = -1;
    int i;
    Venta *pVenta=NULL;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListVenta != NULL)
    {
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            for(i=0;i<ll_len(pArrayListVenta);i++)
            {
                pVenta =ll_get(pArrayListVenta,i);
                fwrite(pVenta,sizeof(Venta),1,pFile);
            }
        }
        returnAux =0;
        fclose(pFile);
    }
    return returnAux;
}





