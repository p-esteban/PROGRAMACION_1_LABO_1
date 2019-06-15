#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "socios.h"
#include "libros.h"

#include "prestamos.h" //cambiar por nombre entidad
#include "informes.h" //cambiar por nombre entidad

int informes_Inicializar(EAux array[], int size)                                    //cambiar informes
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int informes_buscarEmpty(EAux array[], int size, int* posicion)                    //cambiar informes
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                printf("Estoy en emty: %d",i);
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
int informes_listar(EAux array[], int size)                      //cambiar prestamos
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n Posicion: %d\n dia : %d\n mes: %d\n anio: %d\n libros prestados: %d\n",
                       i, array[i].dia,array[i].mes,array[i].anio,array[i].contadorDias);
        }
        retorno=0;
    }
    return retorno;
}

int Informes_maxContadorAcumulado(Prestamos arrayPrestamos[], EAux arrayEAux[], int sizeI)
{
    int retorno=-1;
    int i;
    //int j;

    int auxPosicion;
    /*
    int maxAcumulado=0;
    int maxContador=0;
    int acumulador=0;
    */
    int contador=0;
    //int contadorIgual=1;
    int flag=1;
    //int iMaxAcumulado [sizeI];
    //int iMaxContador [sizeI];

    if(arrayPrestamos!=NULL && sizeI>=0 && arrayEAux!=NULL )
    {


        for(i=0;i<sizeI;i++)
        {
            if(arrayPrestamos[i].isEmpty==1 )//si empty es 1 esta vacio
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                if(flag)
                {
                    arrayEAux[i].isEmpty=0;
                    arrayEAux[i].dia=arrayPrestamos[i].dia;
                    arrayEAux[i].mes=arrayPrestamos[i].mes;
                    arrayEAux[i].anio=arrayPrestamos[i].anio;
                    arrayEAux[i].contadorDias=contador++;
                    flag=0;
                    printf("Primer IF %d\n",arrayEAux[i].contadorDias);
                }
                else
                {
                    printf("contador %d   pos i %d\n",arrayEAux[i].contadorDias,i);
                    printf("valor que voy a buscar %d",arrayPrestamos[i].dia);
                    if(!informes_buscarAnio(arrayEAux,i,arrayPrestamos[i].dia,&auxPosicion))                  //cambiar nombreFuncion y campo
                    {
                        arrayEAux[auxPosicion].isEmpty=0;
                        arrayEAux[auxPosicion].dia=arrayPrestamos[i].dia;
                        arrayEAux[auxPosicion].mes=arrayPrestamos[i].mes;
                        arrayEAux[auxPosicion].anio=arrayPrestamos[i].anio;
                        arrayEAux[auxPosicion].contadorDias=arrayEAux[auxPosicion].contadorDias+1;
                      //  printf("\n Posicion: %d\n dia : %d\n mes: %d\n anio: %d\n libros prestados: %d\n",
                        //    auxPosicion, arrayEAux[auxPosicion].dia,arrayEAux[auxPosicion].mes,arrayEAux[auxPosicion].anio,arrayEAux[auxPosicion].contadorDias);

                        printf("Salio bien buscar int");
                    }
                    else{
                        printf("sali mal buscar int");
                        if(!informes_buscarEmpty(arrayEAux,i,&auxPosicion))
                        {
                            arrayEAux[auxPosicion].isEmpty=0;
                            arrayEAux[auxPosicion].dia=arrayPrestamos[i].dia;
                            arrayEAux[auxPosicion].mes=arrayPrestamos[i].mes;
                            arrayEAux[auxPosicion].anio=arrayPrestamos[i].anio;
                            arrayEAux[auxPosicion].contadorDias=arrayEAux[auxPosicion].contadorDias+1;
                    // printf("\n Posicion: %d\n dia : %d\n mes: %d\n anio: %d\n libros prestados: %d\n",
                        //    auxPosicion, arrayEAux[auxPosicion].dia,arrayEAux[auxPosicion].mes,arrayEAux[auxPosicion].anio,arrayEAux[auxPosicion].contadorDias);
                        }
                    }

                    //prestamos_buscarInt(arrayEAux,i,arrayPrestamos[i].mes,&auxPosicion);                  //cambiar nombreFuncion y campo
                   // prestamos_buscarInt(arrayEAux,i,arrayPrestamos[i].anio,&auxPosicion);

                    printf("Hatas aca llegue POS: %d\n",auxPosicion);


                }
           }
        }
        retorno=0;
    }
                /*
                //Guardo los max acumulado y contador
                if(acumulador>maxAcumulado)
                {
                    maxAcumulado=acumulador;
                    iMaxAcumulado[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxAcumulado[i]=i;
                }
                else if(acumulador==maxAcumulado)
                    iMaxAcumulado[i]=i;
                else
                    iMaxAcumulado[i]=-2;                         //Para marcar los lugares vacios

                acumulador=0;

                if(contador>maxContador)
                {
                    maxContador=contador;
                    iMaxContador[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxContador[i]=i;
                }
                else if(contador==maxContador)
                    iMaxContador[i]=i;
                else
                    iMaxContador[i]=-2;                         //Para marcar los lugares vacios

                contador=0;
                */

           //printf("\nDia: %d Mes: %d: Año: %d Total Presatamos: %d",
             //  arrayEAux[i].dia,arrayEAux[i].mes,arrayEAux[i].anio,arrayEAux[i].contadorDias);


        /*
        printf("\nMayor acumulado: %d \nMayor contador: %d \nI: ",maxAcumulado,maxContador);
        for(;iMaxAcumulado[i]!=-1;i--)                                                      //Uno o el otro, sino agregar otro contador que no sea el i
        {
            if(iMaxAcumulado[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxAcumulado[i]].varString);
            }
        }
        for(;iMaxContador[i]!=-1;i--)
        {
            if(iMaxContador[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxContador[i]].varString);
            }
        }

        retorno=0;
        */

    return retorno;
}
int informes_buscarAnio(EAux array[], int size, int valorBuscado, int* posicion)                    //cambiar prestamos
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        //printf("\nestoy en buscar. BUsco %d",valorBuscado);
        for(i=0;i<size;i++)
        {
            //printf("\nestoy en arrayEaux en la posicion %d\n.. contenido %d\n empty: %d",i,array[i].dia,array[i].isEmpty);
            //printf("\nEmpty en pos siguiente %d",array[i+1].isEmpty);
            if(array[i].isEmpty==1)
            {
                //printf("\nesta lleno en la pos %d",i);
                continue;
            }

            else
            {
                //printf("\nentre al eslssss");
                if(array[i].dia==valorBuscado)                                                   //cambiar campo idSocio
                {
                    //printf("\nestoy en elseIF");
                    retorno=0;
                    *posicion=i;
                    //printf("\nMuestro retorno %d",retorno);
                    break;
                }
            }
        }
    }
    return retorno;
}
