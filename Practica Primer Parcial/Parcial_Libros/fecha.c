#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "fecha.h"

int isValidFecha(int dia,int mes,int anio)
{
    int ret=0;


    if (mes >= 1&& mes <= 12)
    {
        switch ( mes )
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if ( dia >= 1 && dia <= 31 )
            {
                ret=1;
            }
            else
            {
                printf("Dia incorrecto\n\n");
                system("pause");
                ret=0;

            }
            break;

        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( dia >= 1 && dia<= 30 )
            {
                ret=1;
            }
            else
            {

                printf("Dia incorrecto\n\n");
                system("pause");
                ret=0;
            }

            break;

        case  2 :
            if ( ((anio % 4 == 0) && (anio % 100 != 0)) || (anio % 400 == 0 ))
            {
                if ( dia >= 1 && dia <= 29 )
                {
                    ret=1;
                }
                else
                {
                    printf("Dia incorrecto\n\n");
                    system("pause");
                    ret=0;
                }

            }
            else if ( dia >= 1 && dia <= 28 )
            {
                ret=1;
            }
            else
            {
                printf("Dia incorrecto\n\n");
                system("pause");
                ret=0;
            }

            break;



        }

    }
    else
    {
        printf("Mes Ingresado es incorrecto\n\n");
        system("pause");
    }

    return ret;
}
