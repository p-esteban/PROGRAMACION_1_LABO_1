#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Asociado.h"
#include "Llamada.h"
#include "utn.h"

#define REINTENTOS 3
#define LEN_LISTA 5


int main()
{
    int flag=0;
    int posLibre;
    int opcion=0;
    Asociado asociados[LEN_LISTA];
    Llamada llamadas[LEN_LISTA];



    asoc_initAsociado(asociados,LEN_LISTA);
    llam_init(llamadas,LEN_LISTA);


    ///////////////PRUEBA////////////
    /*
    strcpy(asociados[0].apellido,"Perez");
    asociados[0].estado=1;
    strcpy(asociados[0].nombre,"Juan");
    asociados[0].edad= 20;
    asociados[0].dni=35937856;
    asociados[0].idAsociado=0;


    flag = 1;

    strcpy(asociados[1].apellido,"Perez");
    asociados[1].estado=1;
    strcpy(asociados[1].nombre,"Ana");
    asociados[1].edad= 85;
    asociados[1].dni=35937856;
    asociados[1].idAsociado=1;

    strcpy(asociados[2].apellido,"Abc");
    asociados[2].estado=0;
    strcpy(asociados[2].nombre,"Def");
    asociados[2].edad= 15;
    asociados[2].dni=35937856;
    asociados[2].idAsociado=2;

    llamadas[0].idLlamada=0;
    llamadas[0].estado=0;
    llamadas[0].horaEntrada=14.20;
    llamadas[0].motivo=3;
    llamadas[0].idAsociado=1;
    llamadas[0].horaSalida=15.50;
    llamadas[0].idAmbulancia=1;
    llamadas[0].tiempo=30;

    llamadas[1].idLlamada=1;
    llamadas[1].estado=0;
    llamadas[1].horaEntrada=12.20;
    llamadas[1].motivo=1;
    llamadas[1].idAsociado=0;
    llamadas[1].horaSalida=15.50;
    llamadas[1].idAmbulancia=55;
    llamadas[1].tiempo=30;
    */
    /*
 int idLlamada;
    int idAsociado;
    int idAmbulancia;
    int tiempo;
    int motivo;/// 0-ninguno 1-infarto 2-ACV 3-Gripe
    int estado;/// 0-pendiente 1-cumplido (-1)-Vacio
    float horaEntrada;
    float horaSalida;
*/
    while(opcion!=7)
    {
        utn_getInt("\n1)Alta de pantalla\n2)Modificar datos de pantalla\n3)Baja de pantalla\n"
                   "4)Nueva Llamada\n5)Listar\n6)Asignar Ambulancia\n7)Salir\n\n    INGRESE OPCION: ",
                   "ERROR", 1, 7, 2, 1, REINTENTOS,&opcion);
        switch(opcion)
        {
            case 1:
            {
                posLibre=asoc_findFree(asociados,LEN_LISTA);
                if(posLibre>=0)
                {
                    printf("POs Lib: %d",posLibre);
                    printf("\n----Se encontro lugar----\n");
                    if(!asoc_add(asociados,LEN_LISTA,posLibre,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        flag=1;
                        printf("\n----Se dio de ALTA exitosamente!----\n");
                        break;
                    }
                    else
                    {
                        printf("\n----No se realizo el ALTA!----\n");
                    }
                }
                else
                {
                    printf("\n----No se encontro lugar libre!----\n");
                }
                break;
            }
            case 2:
            {
                if(flag)
                {
                    if(asoc_alter(asociados,LEN_LISTA,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----Se modifico exitosamente----\n");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS en la NOMINA!----\n");
                }
                break;
            }
            case 3:
            {
                if(flag)
                {
                    if(asoc_remove(asociados,LEN_LISTA,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----La BAJA se realizo con exito!----\n");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS en la NOMINA!----\n");
                }
                break;
            }

            case 4:
            {
                if(flag)
                {

                    //asoc_print(llamadas,LEN_LISTA);
                    posLibre=llam_findFree(llamadas,LEN_LISTA);
                    //asoc_print(asociados,LEN_LISTA;
                    if(!llam_add(llamadas,asociados,LEN_LISTA,"\nDATO NO VALIDO\n",REINTENTOS, posLibre))
                    {
                        printf("\n----La LLAMADA se registró con exito!----\n");
                    }
                    else
                    {
                        printf("\n----No se pudo REGISTRAR la llamada!----\n");
                    }
                }
                else
                {
                    printf("\n----No hay ASOCIADOS en la NOMINA!----\n");
                }
                break;
            }

            case 5:
            {
                if(flag)
                {
                    asoc_print(asociados,LEN_LISTA);
                }
                break;
            }


            case 6:
            {
                if(flag)
                {
                    llam_print(llamadas,LEN_LISTA);

                    llam_asignar(llamadas,LEN_LISTA,"\nERROR",REINTENTOS);


                }
                break;
            }

        }
    }


    return 0;
}
