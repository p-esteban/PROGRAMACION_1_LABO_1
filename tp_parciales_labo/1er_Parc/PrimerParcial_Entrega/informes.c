#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"
#include "informes.h"

#define TEXT_SIZE 50
#define SORT_DOWN 0




void informes_menu(Instrumento arrayInstrumento[], Musico arrayMusico[], Orquesta arrayOrquesta[],int sizeInstrumento,int sizeMusico,int sizeOrquesta)
{
    char opcion;

    do
    {
        utn_getChar("\n\n---------MENU INFORMES--------\n A-Listar orquesta segun lugar ingresado\n B-Listar Musicos menora 25 años\n "
                    "C-Listar Orquesa con menos de 6 musicos\n D-Listar instrumentos de orquesta selaccionada\n E-Listar Orquestas completas\n "
                    "F-Listar Orquesta con menos Musicos\n G-Promedio de instrumentos por orquesta\n H-Musicos que NO tocan instrumentos de viento\n"
                    " S- Volver al menu inicial\n","Erro",'A','S',1,&opcion);

        switch(opcion)
        {
            case 'A'://Listar orquesta segun lugar ingresado
                orquesta_listar(arrayOrquesta,sizeOrquesta);
                informes_listarOrquestaPorLugar(arrayOrquesta,sizeOrquesta);
                break;
            case 'B':
                informes_listarMusicosPorCriterioEdad(arrayMusico,arrayOrquesta, arrayInstrumento ,sizeMusico, sizeOrquesta, sizeInstrumento);
                break;
            case 'C':
                informes_listarOrquestaPorCantMusicos(arrayOrquesta, arrayMusico, sizeMusico, sizeOrquesta);
                break;
            case 'D'://Listar instrumentos de orquesta selaccionada
                orquesta_listar(arrayOrquesta,sizeOrquesta);
                informes_listarInstrumentoPorOrquesta(arrayOrquesta, sizeOrquesta,arrayInstrumento,sizeInstrumento,arrayMusico ,sizeMusico);
             break;
            case 'E':
                informes_listarOrquestaCompleta(arrayOrquesta, arrayMusico, arrayInstrumento,sizeOrquesta, sizeMusico, sizeInstrumento);
                break;
            case 'F':
                informes_listarOrquestaConMenosMusicos(arrayOrquesta,arrayMusico, sizeOrquesta, sizeMusico);
                break;
            case 'G':
                informes_listarPromedioInstrumento(arrayOrquesta , arrayMusico, sizeOrquesta,sizeMusico);
                break;
            case 'H':
                informes_listarMusicoCriterioTipoInstrumento(arrayMusico, arrayInstrumento, sizeMusico,sizeInstrumento);
                break;
            case 'S':
                break;
            default:
                printf("\nOpcion no valida");
        }
    }while(opcion!='S');
 }


///LISTAR ORQUESTA POR LUGAR
/** \brief Imprime lista de orquestas segun lugar ingresado
 *
 * \param arrayOrquesta: array de Orquestas en el cual se busca segun campo lugar
 * \param sizeOrquesta: Indica la logitud del array
 * \return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
 *
 */

int informes_listarOrquestaPorLugar(Orquesta arrayOrquesta[], int sizeOrquesta)
{
    int retorno=-1;
    int i;
    int posicionOrquesta;
    char auxLugar[TEXT_SIZE];

    if(arrayOrquesta!=NULL && sizeOrquesta>=0)
    {
        if(!utn_getTexto("\nIngrese lugar: ","\nError",1,TEXT_SIZE,1,auxLugar)&&
            orquesta_buscarLugar(arrayOrquesta, sizeOrquesta, auxLugar, &posicionOrquesta)!=-1)
        {
            for(i=posicionOrquesta;i<sizeOrquesta;i++)
            {
                if(arrayOrquesta[i].isEmpty==1)
                    continue;

                else
                {
                    if(strcmp(arrayOrquesta[i].lugar,auxLugar)==0)
                    {
                        informes_mostrarOrquesta(arrayOrquesta,i);
                        retorno=0;
                    }
                }
            }
        }
        else
        {
            printf("\nEl lugar ingresado no pertenece a una orquesta registrada\n");
        }

    }
    return retorno;
}


///LISTAR MUSICOS MENORES A 25 AÑOS
/** \brief Imprime por pantalla lista de Musicos que cumplen con edad<25. Muestra nombre apellido edad de Musico instrumento y orquesta
 *
 * \param arrayMusico : array de musicos en el cual buscar
 * \param arrayOrquesta : arraya de orquestas donde se busca el id y nombre de orquesta. se pasa por parametro a otra funcion
 * \param arrayInstrumento : array de instrumento donde se busca el id y nombre de instrumento. se pasa por parametro a otra funcion
 * \param sizeMusico : Indica la logitud del array de musicos
 * \param sizeOrquesta : Indica la logitud del array orquesta
 * \param sizeIntrumento : Indica la logitud del array de instrumentos
 * \return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
 *
 */

int informes_listarMusicosPorCriterioEdad(Musico arrayMusico[],Orquesta arrayOrquesta[], Instrumento arrayInstrumento[], int sizeMusico, int sizeOrquesta, int sizeIntrumento)
{
    int retorno=-1;
    int i;
    int posInstrumento;
    int posOrquesta;

    if(arrayMusico!=NULL && sizeMusico>=0 && arrayOrquesta!=NULL && sizeOrquesta>=0 && arrayInstrumento!=NULL && sizeIntrumento>=0)
    {
        for(i=0;i<sizeMusico;i++)
        {
            if(arrayMusico[i].isEmpty==1)
                continue;

            else
            {
                if( arrayMusico[i].edad<25 && !instrumento_buscarID(arrayInstrumento,sizeIntrumento,arrayMusico[i].idInstrumento,&posInstrumento)&&
                    !orquesta_buscarID(arrayOrquesta,sizeOrquesta,arrayMusico[i].idOrquesta,&posOrquesta))
                {
                        printf(" ID: %d\n Nombre: %s\n Apellido: %s\n Edad: %d\n Instrumento: %s\n Orquesta: %s\n-----------------\n",
                        arrayMusico[i].idUnico,arrayMusico[i].nombre,arrayMusico[i].apellido,arrayMusico[i].edad,arrayInstrumento[posInstrumento].nombre,arrayOrquesta[posOrquesta].nombre);
                        retorno=0;
                }
            }
        }
    }
    return retorno;
}
///LISTAR ORQUESTA CON MENOS DE 6 MUSICOS
/** \brief imprime lista de orquestas filtrada por criterio menso de 6 musicos
 *
 * \param arrayOrquesta : array de orquestas
 * \param arrayMusico : array de musico donde busca coincidencia con id orquesta
 * \param sizeMusico : Indica la logitud del array
 * \param sizeOrquesta : Indica la logitud del array
 * \return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
 *
 */

int informes_listarOrquestaPorCantMusicos(Orquesta arrayOrquesta[], Musico arrayMusico[], int sizeOrquesta, int sizeMusico)
{
    int retorno=-1;
    int i;
    int k;
    int contador;
    int posicion;

    if(arrayOrquesta!=NULL && sizeOrquesta>=0 && arrayMusico!=NULL && sizeMusico>=0)
    {
        for(i=0;i<sizeOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty==1 )
                continue;

            else
            {
                for(k=0, contador=0;k<sizeMusico;k++)
                {
                    if(arrayMusico[k].isEmpty!=1 && arrayOrquesta[i].idUnico==arrayMusico[k].idOrquesta)
                        contador++;

                }
                if(contador<6 && arrayMusico[i].isEmpty!=1)
                {
                    orquesta_buscarID(arrayOrquesta,sizeOrquesta,arrayOrquesta[i].idUnico,&posicion);
                    informes_mostrarOrquesta(arrayOrquesta,posicion);
                }
            }
            retorno=0;
        }
    }
    return retorno;
}
/** \brief Imprime todos los campos de la estructura Orquesta de una posicion recibida como parametro.Remplaza valor numerico tipo por cadena
 *
 * \param array : array de orquesta
 * \param posicion : posicion del array de orquesta  recibida como parametro
 * \return (-1) si Error [largo no valido o NULL pointer] - (0) si se imprimio exitosamente
 *
 */

int informes_mostrarOrquesta(Orquesta arrayOrquesta[], int posicion)
{
    int retorno=-1;
    char tipoStr[TEXT_SIZE];

    if(arrayOrquesta!=NULL && posicion>=0 && arrayOrquesta[posicion].isEmpty==1);
    {
        switch(arrayOrquesta[posicion].tipo)
        {
        case 1:
            strncpy(tipoStr,"Sinfonica",TEXT_SIZE);
            break;
        case 2:
            strncpy(tipoStr,"Filarmonica",TEXT_SIZE);
            break;
        case 3:
            strncpy(tipoStr,"De Camara",TEXT_SIZE);
            break;
        }
        printf("\n\n ID: %d - %s\n Tipo: %s\n Lugar: %s",
                arrayOrquesta[posicion].idUnico,arrayOrquesta[posicion].nombre,tipoStr,arrayOrquesta[posicion].lugar);
        retorno=0;
    }
    return retorno;
}





/// LISTAR INSTRUMENTO DE UNA ORQUESTA
/** \brief imprime lista de instrumentos segun id orquesta seleccionada por el usuario
 *
 * \param arrayOrquesta : array de Orquesta donde se busca si id ingresado existe
 * \param arrayInstrumento : array de Instrumentos se pasa como parametro a una funcion que devulve la pocision de ocurrencias con el array de musico
 * \param arrayMusico : array de musico en el cual se busca en el campo idOrquesta el valor ingresado
 * \param sizeInstrumento : Indica la logitud del array de instrumentos
 * \param sizeMusico : Indica la logitud del array de musicos
 * \param sizeOrquesta : Indica la logitud del array de orquestas
 * \param idOrquesta : id de orquesta ingresado por usuario, criterio de busqueda de musico
 * \return (-1) si Error [largo no valido o NULL pointer] - (0) si se imprime exitosamente
 *
 */


int informes_listarInstrumentoPorOrquesta(Orquesta arrayOrquesta[], int sizeOrquesta,Instrumento arrayInstrumento[],int sizeInstrumento, Musico arrayMusico[],int sizeMusico)
{
    int retorno=-1;
    int i;
    char tipoStr[TEXT_SIZE];
    int posicionInstrumento;
    int posOrquesta;
    int idOrquesta;

    if(arrayOrquesta!=NULL && sizeOrquesta>=0 && arrayInstrumento!=NULL && sizeInstrumento>=0 && arrayMusico !=NULL && sizeMusico >=0)
    {
        if(!utn_getInt("\nIngrese ID de Orquesta: \n","\nError\n",0,sizeOrquesta,sizeof(int),1,1,&idOrquesta)&&
           !orquesta_buscarID(arrayOrquesta,sizeOrquesta,idOrquesta,&posOrquesta))
        {
            for(i=0;i<sizeMusico;i++)
            {
                if(arrayMusico[i].isEmpty==1)
                    continue;

                else
                {
                    if(arrayMusico[i].idOrquesta==idOrquesta && !instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusico[i].idInstrumento,&posicionInstrumento) )
                    {
                        instrumento_tipoStr(arrayInstrumento,posicionInstrumento,tipoStr);
                        printf("\nInstrumento: %s\nTipo: %s\nMusico: %s %s\n--------------",
                                arrayInstrumento[posicionInstrumento].nombre,tipoStr,arrayMusico[i].nombre,arrayMusico[i].apellido);
                        retorno=0;
                    }
                }
            }
        }
        else
        {
            printf("\nError - ID invalido\n");
        }
    }
    return retorno;
}


/** \brief calcula promedio de instrumentos por orquesta activa. imprime el resultado
 *
 * \param arrayOrquesta : array de Orquesta recorre y busca coincidencias con el array de musico
 * \param arrayMusico : array de musico
 * \param sizeOrquesta : Indica la logitud del array de orquesta
 * \param sizeMusico : Indica la logitud del array de musicos
 * \return (-1) si Error [largo no valido o NULL pointer] - (0) si se imprime exitosamente
 *
 */

int informes_listarPromedioInstrumento(Orquesta arrayOrquesta[], Musico arrayMusico[], int sizeOrquesta, int sizeMusico)
{
    int retorno=-1;
    int i;
    int k;
    int musicosPorOrquesta;
    int orquestasActivas;

    if(arrayOrquesta!=NULL && sizeOrquesta>=0 && arrayMusico!=NULL && sizeMusico>=0)
    {
        for(k=0,orquestasActivas=0;k<sizeOrquesta;k++)
        {
            if(arrayOrquesta[k].isEmpty!=1)
                orquestasActivas++;
        }
        for(i=0;i<sizeOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty==1)
                continue;
            else
            {
                for(k=0,musicosPorOrquesta=0;k<sizeMusico;k++)
                {
                    if(arrayMusico[k].isEmpty!=1 && arrayOrquesta[i].idUnico==arrayMusico[k].idOrquesta)
                         musicosPorOrquesta++;
                }
                printf("\nID %d - %s\n Promedio de instrumentos: %f\n",arrayOrquesta[i].idUnico,
                       arrayOrquesta[i].nombre,(float) musicosPorOrquesta/orquestasActivas);
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Cuenta tipo de intrumentos por orquesta y la imprime cuando cumple con la condicion de orquesta completa
 *
 * \param arrayOrquesta: array de orquesta que recorre
 * \param arrayMusico arra de musico en el que buscar coincidencia con id del arrayOrquesta
 * \param arrayInstrumento se pasa por paramtro a otra funcion que devulve la posicion cuando encuentra coincidencia con idInstrumento del array de musico
 * \param sizeOrquesta Indica la logitud del array
 * \param sizeMusico Indica la logitud del array
 * \param sizeInstrmento Indica la logitud del array
 * \return (-1) si Error [largo no valido o NULL pointer] - (0) si se imprime exitosamente
 *
 */

int informes_listarOrquestaCompleta(Orquesta arrayOrquesta[], Musico arrayMusico[],Instrumento arrayInstrumento[], int sizeOrquesta, int sizeMusico, int sizeInstrumento)
{
    int retorno=-1;
    int i,j,k;
    int cuerdas;
    int vientos;
    int percusion;
    int orquestaCompleta=0;

    if(arrayOrquesta!=NULL && sizeOrquesta>=0 && arrayMusico!=NULL && sizeMusico>=0 && arrayInstrumento!=NULL && sizeInstrumento>=0)
    {
        for(i=0;i<sizeOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty==1)
                continue;
            else
            {
                for(k=0,cuerdas=0,vientos=0,percusion=0;k<sizeMusico;k++)
                {
                    if(arrayMusico[k].isEmpty!=1 && arrayOrquesta[i].idUnico==arrayMusico[k].idOrquesta &&
                       !instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusico[k].idInstrumento,&j))
                    {
                        if(arrayInstrumento[j].tipo==1)
                            cuerdas++;
                        if(arrayInstrumento[j].tipo==2 || arrayInstrumento[j].tipo==3)
                            vientos++;
                        if(arrayInstrumento[j].tipo==4)
                            percusion++;
                    }
                }
                if(cuerdas>=4 && vientos >=4 && percusion>=1)
                {
                    informes_mostrarOrquesta(arrayOrquesta,i);
                    orquestaCompleta++;
                }
            }
            retorno=0;
        }
        if(!orquestaCompleta)
            printf("\nNo hay orquestas completas\n");
    }
    return retorno;
}


/** \brief lista orquestas con menos musicos
 *
 * \param arrayOrquesta : array de Orquesta
 * \param arrayMusico : array de musico el cual recorre y busca ocurrencia con el campo id del array orquesta
 * \param sizeOrquesta : Indica la logitud del array de orquesta
 * \param sizeMusico : Indica la logitud del array de musicos
 * \return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
 *
 */

int informes_listarOrquestaConMenosMusicos(Orquesta arrayOrquesta[], Musico arrayMusico[], int sizeOrquesta, int sizeMusico)
{
    int retorno=-1;
    int i;
    int k;
    int musicoPorOrquesta=0;
    int minimo;
    int flag =1;

    if(arrayOrquesta!=NULL && sizeOrquesta>=0 && arrayMusico!=NULL && sizeMusico>=0)
    {
        for(i=0;i<sizeOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty==1)
                continue;

            else
            {
                for(k=0,musicoPorOrquesta =0;k<sizeMusico;k++)
                {
                    if(arrayMusico[k].isEmpty!=1 && arrayOrquesta[i].idUnico==arrayMusico[k].idOrquesta)
                        musicoPorOrquesta++;
                }
                if(flag)
                {
                    minimo = musicoPorOrquesta;
                    flag =0;
                }
                else
                {
                    if(musicoPorOrquesta<minimo)
                        minimo=musicoPorOrquesta;
                }
            }
        }
        for(i=0;i<sizeOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty==1)
                continue;

            else
            {
                for(k=0,musicoPorOrquesta=0;k<sizeMusico;k++)
                {
                    if(arrayMusico[k].isEmpty!=1 && arrayOrquesta[i].idUnico==arrayMusico[k].idOrquesta)
                        musicoPorOrquesta++;
                }
                if(musicoPorOrquesta<=minimo)
                {
                    informes_mostrarOrquesta(arrayOrquesta,i);
                    printf("\n Cantidad de Musicos: %d",musicoPorOrquesta);
                    minimo = musicoPorOrquesta;
                    musicoPorOrquesta=0;
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}
/** \brief lista musicos segun criterio tipo de instrumento
 *
 * \param arrayMusico : array de musico
 * \param arrayInstrumento : array de instrumento el cual recorre y busca coincidencias de campo idInstrumento en en arrayInstrumento
 * \param sizeMusico : Indica la logitud del array de musico
 * \param sizeInstrumento : Indica la logitud del array de intrumento
 * \return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
 *
 */


int informes_listarMusicoCriterioTipoInstrumento(Musico arrayMusico[], Instrumento arrayInstrumento[], int sizeMusico, int sizeInstrumento)
{
    int retorno=-1;
    int i;
    int posInstrumento;
    char tipoStr[TEXT_SIZE];

    if(arrayMusico!=NULL && sizeMusico>=0 && arrayInstrumento!=NULL && sizeInstrumento>=0)
    {
        musico_ordenarPorApellido(arrayMusico,sizeMusico,SORT_DOWN);
        for(i=0;i<sizeMusico;i++)
        {
            if(arrayMusico[i].isEmpty==1)
                continue;
            else
            {
                instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusico[i].idInstrumento,&posInstrumento);
                if(posInstrumento >=0 &&( arrayInstrumento[posInstrumento].tipo == 1 || arrayInstrumento[posInstrumento].tipo == 4))
                {
                    instrumento_tipoStr(arrayInstrumento,posInstrumento,tipoStr);
                    printf("\nInstrumento: %s\nTipo: %s\nMusico: %s %s\n--------------",
                            arrayInstrumento[posInstrumento].nombre,tipoStr,arrayMusico[i].nombre,arrayMusico[i].apellido);
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}




