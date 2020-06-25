#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float operadorA =0;
    float operadorB =0;

    float resultado;

    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A= %f)\n",operadorA);
        printf("2- Ingresar 2do operando (B=%f)\n", operadorB);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                operadorA = getFloat("\nIngresar 1er operando\n");
                break;
            case 2:
                operadorB = getFloat("Ingresar 2do operando\n");
                break;
            case 3:
                printf("\nLa suma de %f + %f es igual a %f", operadorA, operadorB, suma(operadorA , operadorB));
                break;
            case 4:
                printf("\nLa resta de %f - %f es igual a %f", operadorA, operadorB, resta(operadorA , operadorB));
                break;
            case 5:
                if (operadorB == 0)
                {
                    printf( "\nNo se puede realizar la division porque el divisor es 0!!");
                }
                else
                {
                    printf("\nLa division de %f / %f es igual a %f", operadorA, operadorB,division(operadorA , operadorB));
                }
                break;
            case 6:
                printf("\nLa multiplicacion de %f x %f es igual a %f", operadorA, operadorB, multiplicacion(operadorA , operadorB));
                break;
            case 7:
                if (factorial(operadorA ) == -1)
                {
                    printf("\nE resultado del factorial de %f es %f", operadorA, operadorA);
                }
                else
                {
                    printf("\nEl factorial de %f es %f \n", operadorA, factorial(operadorA));

                }
                break;
            case 8:
                printf("\nLa suma de %f + %f es igual a %f", operadorA, operadorB, suma(operadorA , operadorB));
                printf("\nLa resta de %f - %f es igual a %f", operadorA, operadorB, resta(operadorA , operadorB));
                if (operadorB == 0)
                {
                    printf( "\nNo se puede realizar la division porque el divisor es 0!!");
                }
                else
                {
                    printf("\nLa division de %f / %f es igual a %f", operadorA, operadorB,division(operadorA , operadorB));
                }
                printf("\nLa multiplicacion de %f x %f es igual a %f", operadorA, operadorB, multiplicacion(operadorA , operadorB));
                resultado = factorial(operadorA );
                if (resultado == -1)
                {
                    printf("\nE resultado del factorial de %f es %f", operadorA, operadorA);
                }
                else
                {
                    printf("\nEl factorial de %f es %f \n", operadorA, factorial(operadorA));

                }
                break;
            case 9:
                seguir = 'n';
                break;
        }//fin switch
    }//fin while
    return 0;
}//fin main
