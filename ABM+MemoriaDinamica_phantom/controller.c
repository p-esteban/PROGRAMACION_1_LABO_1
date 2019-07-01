#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "fantasma.h"
#include "controller.h"

#define SIZE_STRING 51
#define SIZE_ID 10
#define SIZE_VARFLOAT 15
#define SIZE_VARINT 15
#define TRIES 2

/** \brief Carga los datos de  fantasma desde el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero a lista de fantasma
 * \return int returnAux (-1) en caso de error o punteros NULL (0) si carga correctamente
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListFantasma)
{
    int returnAux=-1;
    FILE* pFile = NULL;

    if(path!=NULL && pArrayListFantasma!=NULL)
    {
        ll_clear(pArrayListFantasma);           //revisar!!
        pFile=fopen(path,"r");
        if(pFile!=NULL)
        {
            printf("\n  CARGANDO...\n");
            returnAux=parser_FantasmaFromText(pFile,pArrayListFantasma);
            ll_sort(pArrayListFantasma,fantasma_criterioSortId,1);          //cambiar funcion criterio
            fclose(pFile);
        }
    }
    return returnAux;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* puntero al archivo
 * \param pArrayListFantasma LinkedList* puntero a lista de empleados
 * \return int returnAux (-1) en caso de error o punteros NULL (0) si carga correctamente
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListFantasma)
{

    FILE* pFile;
    int returnAux=-1;

    ll_clear(pArrayListFantasma);   //revisar!!
    pFile=fopen(path,"rb");

    if(pFile != NULL && pArrayListFantasma != NULL && path !=NULL)
    {
        printf("\n  CARGANDO...\n");
        returnAux = parser_FantasmaFromBinary(pFile,pArrayListFantasma);
    }
    fclose(pFile);
    ll_sort(pArrayListFantasma,fantasma_criterioId,1);          //cambiar funcion criterio
    return returnAux;
}



/** \brief Alta de fantasma
 *
 * \param pArrayListFantasma LinkedList* puntero a lista de fantasma
 * \return int returnAux (-1) en caso de error o punteros NULL o valor ingresado incorrecto (0) si agrega correctamente
  *
 */
int controller_addFantasma(LinkedList* pArrayListFantasma)
{
    Fantasma* newFantasma;
    char varChar;
    char varString[SIZE_STRING];
    char varLongString[SIZE_STRING];
    char varIntStr[SIZE_VARINT];
    char varFloatStr[SIZE_VARFLOAT];
    char idStr[SIZE_ID];
    int returnAux=-1;
    int id;

    if (pArrayListFantasma != NULL &&
        !utn_getString("\nIngrese varChar: ","\nError\n",1,2,TRIES,varChar)&&
        !utn_getString("\nIngrese varString: ","\nError\n",3,SIZE_STRING,TRIES,varString)&&
        !utn_getString("\nIngrese varLongString: ","\nError\n",3,SIZE_STRING,TRIES,varLongString)&&
        !utn_getString("\nIngrese varInt: ","\nError\n",1,SIZE_VARINT,TRIES,varIntStr)&&
        !utn_getString("\nIngrese varFloat: ","\nError\n",1,SIZE_VARFLOAT,TRIES,varFloatStr)&&
        !employee_maxId(pArrayListFantasma,&id))
        {
            sprintf(idStr, "%d", id+1);
            newFantasma = fantama_newParametros(idStr,varchar,varString,varLongString,varIntStr,varFloatStr);
            if(!ll_add(pArrayListFantasma,newFantasma))
            {
                printf("\nAlta Exitosa!\n");
                returnAux=0;
            }
            else
            {
                printf("\nNo se realizo Alta!\n");
            }
        }
    return returnAux;
}


/** \brief Modificar datos de fantasma
 *
 * \param pArrayListFantasma LinkedList* puntero a lista de fantasma
 * \return int returnAux (-1) en caso de error o punteros NULL o valor ingresado incorrecto (0) si modifica correctamente
 *
 */
int controller_editFantasma(LinkedList* pArrayListFantasma)
{
    int returnAux=-1;
    Fantasma* auxFantasma=NULL;
    char idBuscado[SIZE_ID];
    char varChar;
    char varSting[SIZE_NOMBRE];
    char varLongSting[SIZE_NOMBRE];
    char varIntStr[SIZE_HORAS];
    char varFloatStr[SIZE_SUELDO];
    int option;
    int index;

   if( pArrayListFantasma != NULL &&
       !utn_getString("\nIngrese id a Modificar:","\nError\n",1,SIZE_ID,TRIES,idBuscado) &&
       !fantasma_searchById(pArrayListFantasma,atoi(idBuscado),&index))                         //cambiar funcion
    {
        auxFantasma = ll_get(pArrayListFantasma,index);
        utn_getInt("\n1- Modificar varChar \n2- Modificar varString \n3- Modificar varLongString\n4- Modificar varInt \n"
                   "\n5- Modificar varFLoat \n6- Volver al menu anterior\nIngrese opcion:",
                   "\nError",1,6,sizeof(int),1,TRIES,&option);  //cambiar limite
        switch(option)
        {
            case 1:
                if(!utn_getString("\nIngrese varChar: ","\nError\n",1,2,TRIES,varChar))
                    returnAux=fantasma_setVarChar(auxFantasma,varChar);
                break;
            case 2:
                if(!utn_getString("\nIngrese varString: ","\nError\n",3,SIZE_STRING,TRIES,varString))
                    returnAux=fantasma_setVarString(auxFantasma,varString);
               break;
            case 3:
                 if(!utn_getString("\nIngrese varLongString: ","\nError\n",3,SIZE_STRING,TRIES,varLongString))
                    returnAux=fantasma_setVarLongString(auxFantasma,varLongString);
              break;
            case 4:
                 if(!utn_getString("\nIngrese varInt: ","\nError\n",1,SIZE_VARINT,TRIES,varIntStr))
                    returnAux=fantasma_setVarIntStr(auxFantasma,varIntStr);
            case 5:
                 if(!utn_getString("\nIngrese varFLoat: ","\nError\n",3,SIZE_VARFLOAT,TRIES,varFLoatStr))
                    returnAux=fantasma_setVarFloatStr(auxFantasma,varFloatStr);
                break;
            case 6:
                break;
            default:
                printf("\nOpcion incorrecta!\n");
                break;
        }
        if(!returnAux)
            printf("\nModificacion Exitosa!\n");
        else
            printf("\nNo se realizo Modificacion!\n");
    }
    else
    {
        printf("\nId inexistente\n");
    }
    return returnAux;
}


/** \brief Baja de fantasma
 *
 * \param pArrayListFantasma LinkedList* puntero a lista de fantasma
 * \return int returnAux (-1) en caso de error o punteros NULL o valor ingresado incorrecto
 *         o lista vacia (0) si elimina correctamente
 *
 */
int controller_removeFantasma(LinkedList* pArrayListFantasma)
{
    int returnAux=-1;
    char idBuscado[SIZE_ID];
    int index;

        if(pArrayListFantasma != NULL && ll_len(pArrayListFantasma)>0)
        {
            if( !utn_getString("\nIngrese id:","\nError\n",1,SIZE_ID,TRIES,idBuscado) &&
                !fantasma_searchById(pArrayListFantasma,atoi(idBuscado),&index))            //cambiar funcion
            {
                if(!ll_remove(pArrayListFantasma,index))
                {
                    printf("\nEliminado exitosamente!");
                    returnAux=0;
                }
                else
                {
                    printf("\nNo se pudo eliminar!\n");
                }
            }
            else
            {
                printf("\nNo existe el ID\n");
            }
        }
        else
        {
            printf("\nLa lista esta vacia!\n");
        }
    return returnAux;
}

/** \brief Listar fantams
 *
 * \param pArrayListFantasma LinkedList* puntero a lista de fantasma
 * \return int returnAux (-1) en caso de error o punteros NULL o lista vacia (0) si lista correctamente
 *
 */
int controller_listFantasma(LinkedList* pArrayListFantasma)
{
    int returnAux = -1;
    int i;
    Fantasma* auxFantasma=NULL;
    char VarChar;
    char VarString[SIZE_STRING];
    char VarLongString[SIZE_STRING];
    int id;
    int VarInt;
    float VarSueldo;

    if(pArrayListFantasma != NULL && ll_len(pArrayListFantasma)>0 )
    {
        for (i=0;i<ll_len(pArrayListFantasma);i++)
        {
            auxFantasma=ll_get(pArrayListFantasma,i);           //cambiar
            fantasma_getVarChar(auxFantasma,VarChar);
            fantasma_getVarString(auxFantasma,VarString);
            fantasma_getVarLongString(auxFantasma,VarLongSring);
            fantasma_getId(auxFantasma,&id);
            fantasma_getVarFloat(auxFantasma,&VarFloat);
            fantasma_getVarInt(auxFantasma,&VarInt);
            printf("\nId:%-4d VarChar: %s  VarString: %s VarLongString: %s VarInt: %d VarFLoat: %f"   //cambiar
                    ,id,VarChar,VarString,VarLongString,VarInt,VarFloat);
            returnAux=0;
        }
    }
    else
    {
        printf("\nLa lista esta vacia!\n");
    }
    return returnAux;

}



/** \brief Ordenar fantasma
 *
 * \param pArrayListFantasma LinkedList* puntero a lista de fantasma
 * \return int returnAux (-1) en caso de error o punteros NULL o criterio ingresado incorrecto
 *         o lista vacia (0) si elimina correctamente
 *
 */
int controller_sortFantasma(LinkedList* pArrayListFantasma)
{
   int returnAux=-1;
   int option;
   int flag = -1;

    if(pArrayListFantasma!=NULL && ll_len(pArrayListFantasma)>0&&
       !utn_getInt("\n----SELECCIONAR CRITERIO----\n1- varString ascendente\n2- varString descendente\n3-Id ascendente\n4-Id descendente\n"
                   "5- varInt asecendente \n6- varInt descendente\n7- varFloat ascendente\n8- varFloat descendente\n9- Volver al menu anterior\n",
                   "\nError\n",1,9,sizeof(int),1,TRIES,&option))
    {
        if(option!=9)
            printf("\n  ORDENANDO...\n");
        switch(option)
        {
            case 1:
                flag=ll_sort(pArrayListFantasma, fantasma_criterioSortVarString, 1);//1 a-a 0 z-a
            break;
            case 2:
                flag=ll_sort(pArrayListFantasma,fantasma_criterioSortVarString,0);
            break;
            case 3:
                flag=ll_sort(pArrayListFantasma,fantasma_criterioSortId,1);
            break;
            case 4:
                flag=ll_sort(pArrayListFantasma,fantasma_criterioSortId,0);
            break;
            case 5:
                flag=ll_sort(pArrayListFantasma,fantasma_criterioSortVarInt,1);
            break;
            case 6:
                flag=ll_sort(pArrayListFantasma,fantasma_criterioSortVarInt,0);
            break;
            case 7:
                flag=ll_sort(pArrayListFantasma,fantasma_criterioSortVarFloat,1);
            break;
            case 8:
                flag=ll_sort(pArrayListFantasma,fantasma_criterioSortVarFloat,0);
            break;
            case 9:
                returnAux=0;
            break;
        }
        if(flag!=-1)
        {
            printf("\n----LISTA ORDENADA----\n");
            returnAux =0;
        }
    }
    else
    {
        printf("\n NO hay elementos para ordenar!\n");
    }
    return returnAux;
}



/** \brief Guarda los datos de los fantasma en el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo
 * \param pArrayListFantasma LinkedList* puntero a lista de fantasma
 * \return int returnAux (-1) en caso de error o punteros NULL (0) si guarda en el archivo correctamente
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListFantasma)
{
    int returnAux=-1;
    int i;
    char id[1024];
    char varChar[1024];
    char varString[1024];
    char varLongString[1024];
    char varInt[1024];
    char varFlaot[1024];
    Fantasma * pFantasma=NULL;
    FILE* pFile=NULL;

    if(path != NULL)
    {
        pFile=fopen(path,"w");

        if(pFile!=NULL && pArrayListFantasma !=NULL)
        {
            fprintf(pFile,"id,varChar,varString,varLongString,varInt,varFloat\n");  //ANTENCIO!!! CAMBIAR
            for(i=0;i<ll_len(pArrayListFantasma);i++)
            {
                pFantasma=ll_get(pArrayListFantasma,i);

                fantasma_getVarChar(pFantasma,varChar);                 //cambiar
                fantasma_getVarString(pFantasma,varString);
                fantasma_getVarLongString(pFantasma,varLongSring);
                fantasma_getIdStr(pFantasma,id);
                fantasma_getVarFloatStr(pFantasma,varFloat);
                fantasma_getVarIntStr(pFantasma,varInt);

                fprintf(pFile,"%s,%s,%s,%s,%s,%s\n",id,varChar,varString,varLongString,varInt,varFloat);
                //printf("%s,%s,%s,%s,%s,%s\n",id,varChar,varString,varLongString,varInt,varFloat);
            }
        fclose(pFile);
        returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Guarda los datos de fantasma en el archivo data.csv (modo binario).
 *
 * \param path char* puntero al archivo
 * \param pArrayListFantasma LinkedList* puntero a lista de fantasma
 * \return int returnAux (-1) en caso de error o punteros NULL (0) si guarda en el archivo correctamente
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListFantasma)
{
    int returnAux = -1;
    int i;
    Fantasma *pFantasma=NULL;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListFantasma != NULL)
    {
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            for(i=0;i<ll_len(pArrayListFantasma);i++)
            {
                pFantasma =ll_get(pArrayListFantasma,i);
                fwrite(pFantasma,sizeof(Fantasma),1,pFile);
            }
        }
        returnAux =0;
        fclose(pFile);
    }
    return returnAux;
}





