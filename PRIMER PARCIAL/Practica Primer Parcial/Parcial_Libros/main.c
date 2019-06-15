#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "libros.h"
#include "autores.h"
#include "socios.h"
#include "prestamos.h"
#include "informes.h"
#include "fecha.h"

#define QTY_ARRAY_AUTORES 4
#define QTY_ARRAY_SOCIOS 4
#define QTY_ARRAY_LIBROS 4
#define QTY_ARRAY_PRESTAMOS 4

#define OPTION_MAX 19

#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int contadorIdautores=0;
    int contadorIdsocios=0;
    int contadorId=0;
    int contadorIdprestamos=0;                  //cambiar

    Autores arrayAutores[QTY_ARRAY_AUTORES];                   //cambiar
    autores_Inicializar(arrayAutores,QTY_ARRAY_AUTORES);                   //cambiar

    Socios arraySocios[QTY_ARRAY_SOCIOS];                   //cambiar
    socios_Inicializar(arraySocios,QTY_ARRAY_SOCIOS);

    Libros arrayLibros[QTY_ARRAY_LIBROS];                   //cambiar
    libros_Inicializar(arrayLibros,QTY_ARRAY_LIBROS);


    Prestamos arrayPrestamos[QTY_ARRAY_PRESTAMOS];                   //cambiar
    prestamos_Inicializar(arrayPrestamos,QTY_ARRAY_PRESTAMOS);

    EAux arrayEAux [QTY_ARRAY_PRESTAMOS];
    informes_Inicializar(arrayEAux,QTY_ARRAY_PRESTAMOS);
    //*******************************************************************

    socios_mock(arraySocios,QTY_ARRAY_SOCIOS,&contadorIdsocios);
    autores_mock(arrayAutores,QTY_ARRAY_AUTORES,&contadorIdautores);
    libros_mock(arrayLibros,QTY_ARRAY_LIBROS,&contadorId);
    prestamos_mock(arrayPrestamos,QTY_ARRAY_PRESTAMOS,&contadorIdprestamos);
    //********************************************************************

    do
    {

        utn_getInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Alta Socio\n"
                    "7)Modificar Socio \n8)Baja Socio\n9)Listar \n10)Ordenar por Apellido y Nombre\n"
                    "11) Alta Libro\n12)Modificar Libro \n13)Baja libro\n114)Listar Libros \n15)Ordenar por Titulo Y Id de autor\n16) Salir\n\n",                   //cambiar
                    "\nError",1,OPTION_MAX,sizeof(int),1,1,&opcion);

        //utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Alta Socio\n"
         //                  "7)Modificar Socio \n8)Baja Socio\n9)Listar \n10)Ordenar por Apellido y Nombre\n"
            //               "11) Alta Libro\n12)Modificar Libro \n13)Baja libro\n114)Listar Libros \n15)Ordenar por Titulo Y Id de autor\n16) Salir\n\n",                   //cambiar
            //               "\nError",1,sizeof(int),1,19,1,&opcion);

        switch(opcion)
        {
            case 1: //Alta
               if(!Informes_maxContadorAcumulado(arrayPrestamos,arrayEAux,QTY_ARRAY_PRESTAMOS) )
               {
                    printf("OKK");
               }
               else
               {
                   printf("error en func maxCont");
               }

               informes_listar(arrayEAux,QTY_ARRAY_PRESTAMOS);
                //autores_alta(arrayAutores,QTY_ARRAY_AUTORES,&contadorIdautores);                   //cambiar
                break;

            case 2: //Modificar
                autores_modificar(arrayAutores,QTY_ARRAY_AUTORES);                   //cambiar
                break;

            case 3: //Baja
                autores_baja(arrayAutores,QTY_ARRAY_AUTORES);                   //cambiar
                break;

            case 4://Listar
                autores_listar(arrayAutores,QTY_ARRAY_AUTORES);                   //cambiar
                break;

            case 5://Ordenar
                autores_ordenarPorDobleCriterio(arrayAutores,QTY_ARRAY_AUTORES,SORT_DOWN,SORT_DOWN);
                //autores_listar(arrayAutores,QTY_ARRAY_AUTORES);                  //cambiar
                break;

            case 6: //Alta
                socios_alta(arraySocios,QTY_ARRAY_AUTORES,&contadorIdsocios);                   //cambiar
                break;

            case 7: //Modificar
                socios_modificar(arraySocios,QTY_ARRAY_AUTORES);                   //cambiar
                break;

            case 8: //Baja
                socios_baja(arraySocios,QTY_ARRAY_AUTORES);                   //cambiar
                break;

            case 9://Listar
                socios_listar(arraySocios,QTY_ARRAY_AUTORES);                   //cambiar
                break;

            case 10://Ordenar
                socios_ordenarPorDobleCriterio(arraySocios,QTY_ARRAY_SOCIOS,SORT_DOWN,SORT_DOWN);
                //socios_listar(arraySocios,QTY_ARRAY_AUTORES);                  //cambiar
                break;

            case 11: //Alta Libro
                autores_listar(arrayAutores,QTY_ARRAY_AUTORES);


                libros_alta(arrayLibros,arrayAutores,QTY_ARRAY_LIBROS,QTY_ARRAY_AUTORES,&contadorId);                   //cambiar
                break;

            case 12: //Modificar
                libros_modificar(arrayLibros,QTY_ARRAY_LIBROS);                   //cambiar
                break;

            case 13: //Baja
                libros_baja(arrayLibros,QTY_ARRAY_LIBROS);                   //cambiar
                break;

            case 14://Listar
                libros_listar(arrayLibros,QTY_ARRAY_LIBROS);                   //cambiar
                break;

            case 15://Ordenar
                libros_ordenarPorDobleCriterio(arrayLibros,QTY_ARRAY_LIBROS,SORT_DOWN,SORT_DOWN);
                //prestamos_listar(arrayLibros,QTY_ARRAY_LIBROS);                  //cambiar
                break;
            case 16: //Alta Prestamos


                prestamos_alta(arrayPrestamos,arraySocios,arrayLibros,QTY_ARRAY_PRESTAMOS,
                               QTY_ARRAY_SOCIOS,QTY_ARRAY_LIBROS,&contadorIdprestamos);
                break;

            case 17: //Listar
                prestamos_listar(arrayPrestamos,QTY_ARRAY_PRESTAMOS);                     //cambiar
                break;

            case 18: //Baja
                prestamos_baja(arrayPrestamos,QTY_ARRAY_PRESTAMOS);                   //cambiar
                break;

            case 19://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=19);
    return 0;
}

