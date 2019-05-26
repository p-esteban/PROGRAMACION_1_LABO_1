#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Autores.h"
#include "Libros.h"
#include "Socios.h"
#include "Prestamos.h"
#include "utn.h"

#define LEN_LISTA 7
#define INTENTOS 4


int main()
{
    int flag=0;
    int posLibreAut;
    int posLibreLib;
    int posLibreSoc;
    int opcion=0;
    Autores ListaAutores[LEN_LISTA];
    Libro ListaLibros[LEN_LISTA];
    Prestamo ListaPrestamos[LEN_LISTA];
    Socio ListaSocios[LEN_LISTA];




    autores_init(ListaAutores,LEN_LISTA);
    libro_init(ListaLibros,LEN_LISTA);
    prestamo_init(ListaPrestamos,LEN_LISTA);
    socio_init(ListaSocios,LEN_LISTA);
    //llam_init(llamadas,LEN_LISTA);

    while(opcion!=7)
    {
        utn_getInt("\n1)Alta AUTOR\n2)Alta LIBRO\n3)Alta SOCIO\n4)Modificar AUTOR\n5)Modificar LIBRO\n6)Modificar SOCIO\n"
                   "7)Baja AUTOR\n8)Baja LIBRO\n9)Baja SOCIO\n7)PRESTAMO\n8)LISTAR\n\nINGRESE OPCION: ",
                   "ERROR", 1, 8, 2, 1, INTENTOS,&opcion);
        switch(opcion)
        {
            case 1:
            {
                posLibreAut=autores_findFree(ListaAutores,LEN_LISTA);
                if(posLibreAut>=0)
                {
                    printf("POs Lib: %d",posLibreAut);
                    printf("\n----Se encontro lugar----\n");
                    if(!autores_add(ListaAutores,LEN_LISTA,posLibreAut,"DATO NO VALIDO\n",INTENTOS))
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
                /// DEBO MOSTRAR LISTA DE AUTORES Y SU ID
                autores_print(ListaAutores,LEN_LISTA);
                posLibreLib=libro_findFree(ListaLibros,LEN_LISTA);
                if(posLibreLib>=0)
                {
                    printf("POs Lib: %d",posLibreLib);
                    printf("\n----Se encontro lugar----\n");

                    if(!libro_add(ListaLibros,LEN_LISTA,posLibreLib,"DATO NO VALIDO\n",INTENTOS))
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
            case 3:
            {
                posLibreSoc=socio_findFree(ListaSocios,LEN_LISTA);
                if(posLibreSoc>=0)
                {
                    printf("POs Lib: %d",posLibreSoc);
                    printf("\n----Se encontro lugar----\n");
                    if(!socio_add(ListaSocios,LEN_LISTA,posLibreSoc,"DATO NO VALIDO\n",INTENTOS))
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


            /*
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
            */

        }
    }





    return 0;
}
