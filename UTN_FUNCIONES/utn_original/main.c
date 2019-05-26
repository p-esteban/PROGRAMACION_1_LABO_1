#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#define LARGO_CUIT 11


int main()
{


int num;
int aux;
//int ret =
if(!utn_getNumber("ingrese \n", "error\n", 1, 5, 3 , 1, 5, &num))
    {
        aux = num;
        printf("\n OK: %d \n", aux);
        //printf("%d",strlen(num));
    }
    else
    {
        printf("ER: %d",aux);
    }



/*


    char auxEmail[1000];
    if(!utn_getEmail("ingrese email: \n", "error \n",  2, 255, 5, auxEmail ))
    {
        printf("\n OK: %s \n", auxEmail);
        printf("%d",strlen(auxEmail));
    }
    else
    {
        printf("ER: %s",auxEmail);
    }

*/

    /*
    //strncpy(auxName, "20-35937856-5", 14);

    //if(!utn_eliminarCarcter(auxName,'-',14 ))
    if(!utn_getCuit("numero de cuit \n", "error \n",  14, 11, 5, auxName ))
    {
        printf("\n OK: %s \n", auxName);
        printf("%d",strlen(auxName));
    }
    else
    {
        printf("ER: %s",auxName);
    }

    */



    return 0;
}




void printArrayInt(  int* arrayResultado,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("%d\n",arrayResultado[i]);
    }
}

