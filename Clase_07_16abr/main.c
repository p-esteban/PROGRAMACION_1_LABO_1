#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mostrarArray(char array[][50], int limit );
int initArray(char arrayStr[][50], int limit, int len);
int freeArray (char array[][50] , int limit );
int buscarArray ( char array [][50], int limit, char* comparar);

int main()
{
    char arrayName[500][50];

    initArray(arrayName, 5, 50);

    strncpy(arrayName[0],"HOLA \n",50);
    strncpy(arrayName[2],"QUE\n",50);
    strncpy(arrayName[3],"TAL\n",50);

char nombre[50][50];
    mostrarArray(arrayName, 5);
    strncpy(nombre[0],"\0",40);
    buscarArray(arrayName, 50, nombre );
    //strncpy(nombre[0],"QUE\n",50);
    //buscarArray(arrayName, 5, nombre);
    freeArray(arrayName, 5);
    int i;
    for(i = 0; i < 500 ; i++)
    {
        printf("%s", arrayName[i]);
    }

    //printf("Hello world!\n");
    return 0;
}

int mostrarArray(char array[][50], int limit )
    {
        int i;
        for(i = 0; i < limit; i++ )
        {
            printf("%s \n", array[i]);
        }
        return 0;
    }

int initArray(char arrayStr[][50], int limit, int len)
{
    int i;
    for(i = 0; i<limit ; i++)
    {
        strncpy(arrayStr[i], "\0", len);
    }
    return 0;
}

int freeArray (char array[][50] , int limit )
{
    int i;
    int retorno = -1;

    for(i = 0 ; i < limit ; i++ )
    {
        printf(" Que tiene cargado array %s, posicion %d \n",array[i],i);
        if(strcmp(array[i],"\0")==0)
        {
            retorno = i;
            printf(" posicion %d  \n", retorno);
            break;

        }
    }
    return retorno;
}

int buscarArray ( char array [][50], int limit, char* comparar)
{
    int i;
    int retorno = -1;


    for (i = 0; i < limit ; i++)
    {
        if(strcmp(array[i],comparar)==0)
        {
            retorno = i;
            printf(" posicion %d  \n", retorno);
            break;
        }
    }
    return retorno;
}

/*
int menu()
{

}

biblioteca controler

/// ALTA
verifica si hay lugar pa guardar luego get name
verificar que el nombre no exista
conservar valor de lugar vacio y dar de alta
/// modificar
verificar si hay elementos
pedir nombre a modificar
buscar el nombre en el array
pediro el nombre que quiere modificar
//imprinmi
//ordenar alfabetic

*/
