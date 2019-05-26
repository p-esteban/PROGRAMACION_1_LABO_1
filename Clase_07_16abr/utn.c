#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"

#define LARGO_CUIT 11

/** \brief Se muestra un mensaaje y pide al usuario ue ingrese un dato por consola
 *   Luego se llama a la funcion que validara si el dato esta dentro del rango
 *
 * \param resultado: Puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto.
 * \param msg: Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola.
 * \param msgError: Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
 * \param limitMin: Valor mínimo admitido (inclusive)
 * \param limitMax Valor máximo admitido (inclusive)
 * \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
 * \return devuleve 0 si la cadena se toma correctamente o -1 si no se puede tomar el dato.
 *
 */


int utn_getString ( char* msg,
                char* msgError,
                int limitMin,
                int limitMax,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && limitMin < limitMax && reintentos>=0 && resultado != NULL)
    {
            do
            {
                printf("%s",msg);
                if(utn_myGetString(bufferStr, limitMax))
                {
                    if(strlen(bufferStr)>=limitMin && strlen(bufferStr) <limitMax)
                    {
                        strncpy(resultado,bufferStr,limitMax);
                        retorno = 0;
                        break;
                    }
                }
                reintentos--;
                printf("%s",msgError);
            }while(reintentos>=0);
    }
    return retorno;
}

/** \brief toma el dato ingresado por consola, elimina el salto de linea al final de la candena y valida que no supere el tamaño de la cadena
 *
 * \param puntero a bufferS donde se va a gusradar la cadena convertida
 * \param limitMax el largo que no deve superar la cadena
 * \return devuelve true si el proceso sale bien
 *
 */

 int utn_myGetString (char* bufferS,  int limitMax)
{
    char bufferString [4096];
    int retorno = FALSE;
    if (bufferS != NULL && limitMax > 0)
    {
        fgets(bufferString, sizeof(bufferString), stdin);
        fflush(stdin);
        if(bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1] = '\0';
        }
        if (strlen(bufferString)<= limitMax);
        {
        strcpy(bufferS, bufferString);

        retorno = TRUE;
        }
    }
    return retorno;
}

/** \brief Se muestra un mensaaje y pide al usuario ue ingrese un dato por consola
 *   Luego se llama a la funcion que validara si el dato esta dentro del rango
 *
 * \param resultado: Puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto.
 * \param msg: Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola.
 * \param msgError: Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
 * \param limitMin: Valor mínimo admitido (inclusive)
 * \param limitMax Valor máximo admitido (inclusive)
 * \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
 * \return devuleve 0 si la cadena se toma correctamente o -1 si no se puede tomar el dato.
 *
 */

int utn_getName (   char* msg,
                char* msgError,
                int limitMin,
                int limitMax,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && limitMin < limitMax && reintentos>=0 && resultado != NULL)
    {
        if(!utn_getString(msg,msgError,limitMin,limitMax,reintentos,bufferStr))
        {
            if(utn_isValidName(bufferStr))
            {
                strncpy(resultado, bufferStr,limitMax);
                retorno = 0;
            }
        }

    }
    return retorno;
}

/** \brief valida que la cadena esta formada solo por letras
 *
 * \param puntero a cadena
 * \return devuelve True si es cadena de letras o false si no es de letras
 *
 */

int utn_isValidName (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a')  )
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

int utn_getSurName (char* msg,
                    char* msgError,
                    int limitMin,
                    int limitMax,
                    int reintentos,
                    char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && limitMin < limitMax && reintentos>=0 && resultado != NULL)
    {
        if(!utn_getString(msg,msgError,limitMin,limitMax,reintentos,bufferStr))
        {
            if(utn_isValidName(bufferStr))
            {
                strncpy(resultado, bufferStr,limitMax);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int utn_isValidSurName (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a') &&
           (cadena [i] != toascii(39) || cadena [i] != ' ')  ) /// buscar apostrofe en ascii y remplazar por xxx
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;

}

//--------NUMERO ENTERO POSITIVO -------- puede ser edad

int utn_getEdad   (char* msg,
                   char* msgError,
                   int minimo,
                   int maximo,
                   int limitMax,
                   int limitMin,
                   int reintentos,
                   int* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    int buffer;
    if(msg != NULL && msgError != NULL && limitMin < limitMax && reintentos>=0 && resultado != NULL && minimo < maximo)
    {
        if(!utn_getString(msg,msgError,limitMin,limitMax,reintentos,bufferStr))
        {
            if(utn_isValidNumber(bufferStr) && utn_isValidRank(bufferStr, minimo, maximo))
            {
                buffer = atoi(bufferStr);
                *resultado = buffer;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int utn_isValidEdad (char* cadena)
{

    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if(cadena[i] > '9' || cadena[i] < '0')
        {
            retorno = FALSE;
            break;
        }
    }


    return retorno;
}

////----------ENTERO CON SIGNO ---------
int utn_getNumber (char* msg,
                   char* msgError,
                   int minimo,
                   int maximo,
                   int limitMax,
                   int limitMin,
                   int reintentos,
                   int* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    int buffer;
    if(msg != NULL && msgError != NULL && limitMin < limitMax && reintentos>=0 && resultado != NULL && minimo < maximo)
    {
        if(!utn_getString(msg,msgError,limitMin,limitMax,reintentos,bufferStr))
        {
            if(utn_isValidNumber(bufferStr) && utn_isValidRank(bufferStr, minimo, maximo))
            {
                buffer = atoi(bufferStr);
                *resultado = buffer;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int utn_isValidRank (char* cadena, int minimo, int maximo)
{
    int buffer;
    int retorno = FALSE;

    buffer = atoi(cadena);
    if (buffer >= minimo && buffer <= maximo)
    {
        retorno = TRUE;
    }
    return retorno;
}

int utn_isValidNumber (char* cadena)
{

    int retorno = TRUE;
    int i;
    int contadorMenos = 0;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if(cadena[i] != '-')
        {
            if(cadena[i] > '9' || cadena[i] < '0')
            {
                retorno = FALSE;
                break;
            }
        }
        else
        {
            contadorMenos++;
            if(cadena[0]!='-' || contadorMenos > 1)
            {
                retorno=FALSE;
                break;
            }
        }
    }
    return retorno;
}





//-----NUMERO CON COMA  Y SIGNO ----------

int utn_getFloat ( char* msg,
                   char* msgError,
                   float minimo,
                   float maximo,
                   int limitMax,
                   int limitMin,
                   int reintentos,
                   float* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    float buffer;
    if(msg != NULL && msgError != NULL && limitMin < limitMax && reintentos>=0 && resultado != NULL && minimo < maximo)
    {
        if(!utn_getString(msg,msgError,limitMin,limitMax,reintentos,bufferStr))
        {
            if(utn_isValidFloat(bufferStr) && utn_isValidRankFloat(bufferStr,minimo,maximo))
            {
                buffer = atof(bufferStr);
                *resultado = buffer;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int utn_isValidRankFloat (char* cadena, float minimo, float maximo)
{

    float buffer;
    int retorno = FALSE;

    buffer = atof(cadena);
    if (buffer >= minimo && buffer <= maximo)
    {
        retorno = TRUE;
    }

    return retorno;
}

int utn_isValidFloat (char* cadena)
{
    int retorno = TRUE;

    int i;
    int contadorPunto = 0;
    int contadorMenos = 0;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if (cadena [i]!='.'&& cadena [i] != '-')
        {
            if(cadena[i] > '9' || cadena[i] < '0' )
            {
                retorno = FALSE;
                break;
            }
        }
        else
        {
            if(cadena[i]=='.')
            {
                contadorPunto++;
            }
            if(cadena[i]=='-')
            {
                contadorMenos++;
                if(cadena[0]!='-' || contadorMenos > 1)
                {
                    retorno=FALSE;
                    break;
                }
            }
        }
    }
    if (contadorPunto > 1)
    {
        retorno = FALSE;
    }

    return retorno;
}

//------ TELEFONO ---------

int utn_getTelephone ( char* msg,
                       char* msgError,
                       int minimo,
                       int maximo,
                       int limitMax,
                       int limitMin,
                       int reintentos,
                       int* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    int buffer;
    if(msg != NULL && msgError != NULL && limitMin < limitMax && reintentos>=0 && resultado != NULL && minimo < maximo)
    {
        if(!utn_getString(msg,msgError,limitMin,limitMax,reintentos,bufferStr))
        {
            if(utn_isValidTelephone(bufferStr) && utn_isValidRank(bufferStr, minimo, maximo))
            {
                buffer = atoi(bufferStr);
                *resultado = buffer;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int utn_isValidTelephone (char* cadena)
{

    int retorno = TRUE;
    int i;
    int contador = 0;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if(cadena[i] != '-' && cadena[i] != ' ')
        {
            if(cadena[i] > '9' || cadena[i] < '0')
            {
                retorno = FALSE;
                break;
            }
        }
        else
        {
            contador++;
            if( contador > 2)
            {
                retorno=FALSE;
                break;
            }
        }
    }
    return retorno;
}

//---------- CUIT----------

int utn_getCuit      ( char* msg,
                       char* msgError,
                       int limitMax,
                       int limitMin,
                       int reintentos,
                       char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];

    if(msg != NULL && msgError != NULL && limitMin < limitMax && reintentos>=0 && resultado != NULL )
    {
        if(!utn_getString(msg,msgError,limitMin,limitMax,reintentos,bufferStr))
        {
            if(utn_isValidCuit(bufferStr))
            {
                strncpy(resultado, bufferStr, limitMax);
                //buffer = atoi(bufferStr);
                //*resultado = buffer;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int utn_isValidCuit (char* cadena)
{
    //char cadena[] = {2,0,3,5,9,3,7,8,5,6,5};

    int retorno = TRUE;
    int i;

    for( i=0 ; cadena[i] != '\0'  ; i++)
    {

            if(cadena[i] > '9' || cadena[i] < '0' )
            {
                retorno = FALSE;
                break;
            }
    }
    if (!utn_isValidDigitoVerificador(cadena))
    {
        retorno = FALSE;
    }

    return retorno;
}

int utn_isValidDigitoVerificador (char* cadena)
{
    //char cadena[] = {2,0,3,5,9,3,7,8,5,6,5};

    int retorno = TRUE;
    int i;
    char vec[] = {5, 4, 3, 2, 7, 6, 5, 4, 3, 2} ;
    int acumulador = 0;
    int digitoVerificador;
    for( i=0 ; i< strlen(vec) /* vec[i] != '\0' */ ; i++)
    {
        acumulador +=vec[i] * cadena[i];
    }
    digitoVerificador = LARGO_CUIT - (acumulador % LARGO_CUIT);
    printf("%d",digitoVerificador);
    /*if(digitoVerificador != cadena[11])
    {
        retorno = FALSE;
    }
*/
    printf("%d",strlen(cadena));
    return retorno;
}


