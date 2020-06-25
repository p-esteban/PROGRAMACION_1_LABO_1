#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h"
#include "orquesta.h"
#include "musico.h"
#include "informes.h"

#define QTY_ARRAY_INSTRUMENTO 20
#define QTY_ARRAY_ORQUESTA 50
#define QTY_ARRAY_MUSICO 100

#define SORT_UP 1
#define SORT_DOWN 0
#define OPTION_MAX 11

int main()
{
    int opcion;
    int contadorIdInstrumento=0;
    int contadorIdOrquesta=0;
    int contadorIdMusico=0;
    int idOrquesta;

    Instrumento arrayInstrumento[QTY_ARRAY_INSTRUMENTO];
    instrumento_Inicializar(arrayInstrumento,QTY_ARRAY_INSTRUMENTO);

    Orquesta arrayOrquesta[QTY_ARRAY_ORQUESTA];
    orquesta_Inicializar(arrayOrquesta,QTY_ARRAY_ORQUESTA);

    Musico arrayMusico[QTY_ARRAY_MUSICO];
    musico_Inicializar(arrayMusico,QTY_ARRAY_MUSICO);

    //////////////
    instrumento_mock(arrayInstrumento,QTY_ARRAY_INSTRUMENTO);
    orquesta_mock(arrayOrquesta,QTY_ARRAY_ORQUESTA);
    musico_mock(arrayMusico,QTY_ARRAY_MUSICO);

    do
    {
        utn_getInt("\n\n---------MENU---------\n1) Alta ORQUESTA \n2) Eliminar ORQUESTA\n3) Imprimir ORQUESTA \n4) Agregar MUSICO\n5) Modificar MUSICO\n6) Eliminar MUSICO\n"
                    "7) Imprimir MUSICO \n8) Agregar INSTRUMENTO\n9) Imprimir INSTRUMENTO\n10) INFORMES\n11) Salir\n\nIngrese Opcion: ","\nError",1,OPTION_MAX,sizeof(int),1,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta orquesta
                if(orquesta_alta(arrayOrquesta,QTY_ARRAY_ORQUESTA,&contadorIdOrquesta))
                {
                    printf("\nNO SE REALIZO EL ALTA");
                }
                break;
            case 2: //baja orquesta
                if(!orquesta_listar(arrayOrquesta,QTY_ARRAY_ORQUESTA))
                {
                    idOrquesta = orquesta_baja(arrayOrquesta,QTY_ARRAY_ORQUESTA);
                    if(idOrquesta>=0)
                    {
                        musico_bajaByIdOrquesta(arrayMusico,QTY_ARRAY_MUSICO,idOrquesta);
                    }
                }
                else
                {
                    printf("\n---NO HAY ELEMENTOS PARA ELIMINAR---\n");
                }
                break;
            case 3: //LISTAR orquesta
                if(orquesta_listar(arrayOrquesta,QTY_ARRAY_ORQUESTA))
                {
                    printf("\nNO HAY ORQUESTAS EN LA LISTA\n");
                }
                break;
            case 4: //Alta musico
                if(musico_alta(arrayMusico,QTY_ARRAY_MUSICO,arrayOrquesta,QTY_ARRAY_ORQUESTA,
                               arrayInstrumento,QTY_ARRAY_INSTRUMENTO,&contadorIdMusico))
                {
                    printf("\nNO SE REALIZO EL ALTA");
                }
                break;
            case 5: //modificar musico
                if(!musico_listar(arrayMusico,QTY_ARRAY_MUSICO))
                {
                    musico_modificar(arrayMusico,QTY_ARRAY_MUSICO);
                }
                else
                {
                    printf("\nNO HAY MUSICOS EN LA LISTA\n");
                }
                break;
            case 6: //eliminar musico
                if(!musico_listar(arrayMusico,QTY_ARRAY_MUSICO))
                {
                    if(!musico_baja(arrayMusico,QTY_ARRAY_MUSICO))
                        printf("\nBaja exitosa\n");
                }
                else
                {
                    printf("\nNO HAY MUSICOS EN LA LISTA\n");
                }
                break;
            case 7: //imprimir MUSICO
                if(musico_listarConInstrumento(arrayMusico,QTY_ARRAY_MUSICO,arrayInstrumento,QTY_ARRAY_INSTRUMENTO))
                {
                    printf("\nNO HAY MUSICOS EN LA LISTA\n");
                }
                break;
            case 8: //agregar instrumento
                if(instrumento_alta(arrayInstrumento,QTY_ARRAY_INSTRUMENTO,&contadorIdInstrumento))
                {
                    printf("\nNO SE REALIZO EL ALTA");
                }
                break;
            case 9: //listar instrumento
                if(instrumento_listar(arrayInstrumento,QTY_ARRAY_INSTRUMENTO))
                {
                    printf("\nNO HAY MUSICOS EN LA LISTA\n");
                }
            case 10://Informes
                informes_menu(arrayInstrumento,arrayMusico,arrayOrquesta,QTY_ARRAY_INSTRUMENTO,QTY_ARRAY_MUSICO,QTY_ARRAY_ORQUESTA);
                break;
            case 11://salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=11);



    return 0;
}
