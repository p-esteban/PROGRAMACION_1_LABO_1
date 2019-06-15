#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "funciones.h"

void printArrayInt(  int* arrayResultado,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("%d\n",arrayResultado[i]);
    }
}


void sortArrayInt(  int* array,int limite)
{
    int i;
    int flagSwap;
    int auxiliar;
    do
    {
        flagSwap = 0;
        for(i=0;i<limite-1;i++)
        {
            if(array[i] > array[i+1])
            {
                auxiliar = array[i];
                array[i]=array[i+1];
                array[i+1] = auxiliar;
                flagSwap = 1;
            }
        }
    }while(flagSwap);
}






int getArrayInt(    char* mensaje,
                    char* mensajeError,
                    int maximo,
                    int minimo,
                    int reintentos,
                    int* arrayResultado,
                    int limite)
{
    int retorno=-1;
    int i;
    int buffer;

    if( arrayResultado!=NULL &&
        mensaje!=NULL &&
        mensajeError!=NULL &&
        minimo<=maximo &&
        reintentos>=0 &&
        limite>0)
    {

        retorno=0;
        for(i=0;i<limite;i++)
        {
            if(utn_getNumero(&buffer,mensaje,mensajeError,minimo,maximo,reintentos)==0)
            {
                arrayResultado[i]=buffer;
            }
            else
            {
                retorno=-1;
                break;
            }
        }
    }
        //utn_getNumero
    return retorno;
}




/////////------------------///////////////

int buscar_maximo(double valores[], int num_valores)
{
	int maximo_pos = 0;
	for (int i = 1; i < num_valores; i++) {
		if (valores[i] > valores[maximo_pos]) {
			maximo_pos = i;
		}
	}
	return maximo_pos;
}
















int utn_getNumero(int* pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    int num;

    while (reintentos>0)
    {
        printf("%s",mensaje);
        if (getInt(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
                __fpurge(stdin);
                reintentos--;
                printf("%s\n",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}

int getInt(int *pResultado)
{
    char buffer[64];
    scanf("%s",buffer);

    *pResultado = atoi(buffer);
    return 0;
}

int utn_getFloat(float *pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    float num;

    while (reintentos>0)
    {
        printf("%s",mensaje);
        if (getFloat(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
                __fpurge(stdin);
                reintentos--;
                printf("%s\n",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}

int getFloat(float *pResultado)
{
    char buffer[64];
    scanf("%s",buffer);

    *pResultado = atof(buffer);
    return 0;
}

int utn_getChar(char* pResultado,const char *mensaje,const char *mensajeError,const char *minimo,const char *maximo,int reintentos)
{
    int ret = -1;
    char buffer[64];
    int i;

    do{
        printf("%s",mensaje);
        scanf("%s", buffer);
        i=0;
        while (buffer[i]!='\0' && i<2)
        {

            if (buffer[0]>=minimo[0] && buffer[0]<=maximo[0])
            {
                ret=0;
            }
            i++;
        }

        if (ret==0 && i==1)
        {
            pResultado = buffer;
            break;
        }
        reintentos--;
        printf("%s\n",mensajeError);
        ret = -1;
        __fpurge(stdin);

    }while (reintentos>0);
    return ret;
}










