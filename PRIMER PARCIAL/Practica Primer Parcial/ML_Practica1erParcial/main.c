#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "usuarios.h"
#include "productos.h" //cambiar por nombre entidad


#define QTY_ARRAY_USUARIO 100
#define QTY_ARRAY_PRODUCTOS 1000
#define OPTION_MAX 16

int main()
{
     int opcion;
    int contadorIdfantasma=0;                   //cambiar
    int contadorIdUsuario=0;                   //cambiar

    Usuario arrayUsuario[QTY_ARRAY_USUARIO];                   //cambiar
    usuario_Inicializar(arrayUsuario,QTY_ARRAY_USUARIO);                   //cambiar

    usuario_mock(arrayUsuario,QTY_ARRAY_USUARIO,&contadorIdUsuario);

    Producto arrayProducto[QTY_ARRAY_PRODUCTOS];                   //cambiar
    producto_Inicializar(arrayProducto,QTY_ARRAY_PRODUCTOS);


    do
    {
        utn_getInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Alta Socio\n"
                    "7)Modificar Socio \n8)Baja Socio\n9)Listar \n10)Ordenar por Apellido y Nombre\n"
                    "11) Alta Libro\n12)Modificar Libro \n13)Baja libro\n114)Listar Libros \n15)Ordenar por Titulo Y Id de autor\n16) Salir\n\n",                   //cambiar
                    "\nError",1,sizeof(int),OPTION_MAX,1,1,&opcion);
        //utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                    //  "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                usuario_alta(arrayUsuario,QTY_ARRAY_USUARIO,&contadorIdUsuario);                   //cambiar
                break;

            case 2: //Modificar
                usuario_modificar(arrayUsuario,QTY_ARRAY_USUARIO);                   //cambiar
                break;

            case 3: //Baja
                usuario_baja(arrayUsuario,QTY_ARRAY_USUARIO);                   //cambiar
                break;

            case 4://Listar
                fantasma_listar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                fantasma_ordenarPorDobleCriterio(arrayFantasma,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);


    return 0;
}
