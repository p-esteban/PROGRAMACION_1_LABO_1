#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"

#define LONG_CUIT 11


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

 int utn_myGetString (char* bufferS,  int limitMax)
{
    char bufferString [4096];
    int retorno = FALSE;
    if (bufferS != NULL && limitMax > 0)
    {
        fgets(bufferString, sizeof(bufferString), stdin);
        fflush(stdin);
        //_fpurge(stdin)
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

int utn_isValidName (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a') && (cadena[i]!=' ')  )
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
           (cadena [i] != toascii(39) || cadena [i] != ' ')  )
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;

}

int utn_getInt    (char* msg,
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
            if(utn_isValidInt(bufferStr) && utn_isValidRank(bufferStr, minimo, maximo))
            {
                buffer = atoi(bufferStr);
                *resultado = buffer;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int utn_isValidInt (char* cadena)
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
    int retorno = -4;
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
            else
            {
                retorno = -1;
            }
        }
        else
        {
            retorno = -2;
        }
    }
    else
    {
        retorno = -3;
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

int utn_getFloatSigne ( char* msg,
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
                       int limitMax,
                       int limitMin,
                       int reintentos,
                       char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    //int buffer;
    if(msg != NULL && msgError != NULL && limitMin < limitMax && reintentos>=0 && resultado != NULL )
    {
        if(!utn_getString(msg,msgError,limitMin,limitMax,reintentos,bufferStr))
        {
            if(utn_isValidTelephone(bufferStr))
            {
                strncpy(resultado,bufferStr,strlen(resultado));
                //*resultado = buffer;
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
                utn_eliminarCarcter(bufferStr, '-', limitMax);
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
    int retorno = TRUE;
    int contador = 0;
    int i;
    int flag = 1;

    if( cadena != NULL)
    {
        for( i=0 ; cadena[i] != '\0'  ; i++)
        {

                if(cadena[i] > '9' || cadena[i] < '0' )
                {
                    if(cadena[i] != '-')
                    {
                        retorno = FALSE;
                        break;
                    }
                }
                if(cadena [i] == '-')
                {
                    contador++;
                    if (cadena [2] != '-' || cadena [11] != '-')
                    {
                        retorno = FALSE;
                        break;
                    }
                    if (contador > 2)
                    {
                        retorno = FALSE;
                        break;
                    }

                }
                if (flag)
                {
                    if(cadena [i] != '2' && cadena[i] != '3')
                    {
                        retorno = FALSE;
                        break;
                    }
                    flag = 0;
                }
        }
    }
    /*
    if (!utn_isValidDigitoVerificador(cadena))
    {
        retorno = FALSE;
    }
    */
    return retorno;
}



int utn_isValidDigitoVerificador (char* cadena )
{
    //char cadena[] = {2,0,3,5,9,3,7,8,5,6,5};

    int retorno = TRUE;
    int i;
    int mult [10] = {2,3,4,5,6,7,2,3,4,5};//= "5432765432";//{'5', '4', '3', '2', '7', '6', '5', '4', '3', '2', '\0'} ;//revisar


    int total = 0;
    int verificador;

    for( i=0 ;  i < strlen(cadena-1); i++)
    {
        total += mult[i] * cadena[i];
        //printf(" pos i %d valor mult: %d valor cadena: %s  total: %d\n", i, mult, cadena, total);
    }
    //printf(" pos i %d \n", total);
    verificador = LONG_CUIT - (total % LONG_CUIT);
    //printf("digito %d \n",verificador);
    if(verificador != cadena[11])////revisar
    {
        retorno = FALSE;
    }

    //printf("%d",strlen(cadena));
    return retorno;
}






int utn_eliminarCarcter (char* cadena, char chart, int limitMax)
{
    int i;
    int j = 0;
    char str[80];
    char tmpCad[80];
    int retorno = -1;

    if (cadena != NULL &&  limitMax >=0)
    {
        strncpy(str,cadena,limitMax);

        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] != chart)
            {
                tmpCad[j] = str[i];
                j++;
            }
        }
        //strncpy(tmpCad[j], '\0', limitMax );
        //tmpCad[j] = '\0';
        strncpy(cadena, tmpCad,limitMax );
        retorno = 0;
    }

    return retorno;

}
///////////DNI///////////////

int utn_getDni (char* pStr, char* msg, char* msgE,int tries)
{
    char bufferStr[10];
    int ret=1;
    while(ret==1 && tries>0)
    {
        if((!utn_getString(msg,msgE,6,9,tries,bufferStr))&&(pStr != NULL)&&(!utn_isValidDni(bufferStr)))
        {
            strncpy(pStr,bufferStr,10);
            ret=0;
        }
        else
        {
            ret=1;
        }
    }
    return ret;
}

int utn_isValidDni (char* pStr)
{
    int i=0;
    int ret=-1;
    while(pStr[i]!='\0')
    {
        if(utn_isValidInt(pStr))///devuvle true si es valido
        {
            ret=0;
        }
        if(strlen(pStr)<7 || strlen(pStr)>8)
        {
            ret=-1;
        }
        i++;
    }
    return ret;
}


/////////EMAIL////////////

int utn_getEmail (  char* msg,
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
            if(utn_isValidEmail(bufferStr))
            {
                strncpy(resultado, bufferStr,limitMax);
                retorno = 0;
            }
        }
    }
    return retorno;
}

int utn_isValidEmail (char* cadena)
{
    int retorno = TRUE;
    int i;
    int contadorAt = 0;
    int flag = 1;
    int contadorNom = 0;
    int contadorDom = 0;

    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a') && (cadena[i] > '9' || cadena[i] < '0')
            &&(toascii(cadena[i]) != 64) && (cadena[i] != '.') && (cadena[i] != '_') && (cadena[i] != '-') )
        {
            retorno = FALSE;
            break;
        }
        if(toascii(cadena[i]) == 64)
        {
            contadorAt++;
            flag = 0;
            if( contadorAt > 1)
            {
                retorno= FALSE;
                break;
            }
        }

        if(flag)
        {
            contadorNom++;

        }
        else
        {
            contadorDom++;

        }

        if((cadena[0] == '.') || (cadena[i] <= '9' && cadena[i] >= '0'))
        {
            retorno = FALSE;
            break;
        }
    }//fin for

    if(contadorNom > 65 || contadorNom < 2)
    {
        retorno = FALSE;
    }
    if (contadorDom < 3 || contadorDom > 255)
    {
        retorno = FALSE;
    }
    return retorno;
}

////////////// ARRAY //////////

void printArrayInt(  int* arrayResultado,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("%d\n",arrayResultado[i]);
    }
}


void sortArrayInt(  int* array,int limite)
{
    int i;
    int flagSwap;
    int auxiliar;
    do
    {
        flagSwap = 0;
        for(i=0;i<limite-1;i++)
        {
            if(array[i] > array[i+1])
            {
                auxiliar = array[i];
                array[i]=array[i+1];
                array[i+1] = auxiliar;
                flagSwap = 1;
            }
        }
    }while(flagSwap);
}






int getArrayInt(    char* msg,
                    char* msgError,
                    int max,
                    int min,
                    int limitMin,
                    int limitMax,
                    int reintentos,
                    int* arrayResultado,
                    int limite)
{
    int retorno=-1;
    int i;
    int buffer;

    if( arrayResultado!=NULL &&
        msg!=NULL &&
        msgError!=NULL &&
        min<=max &&
        reintentos>=0 &&
        limitMax>limitMin)
    {

        retorno=0;
        for(i=0;i<limite;i++)
        {
            if(!utn_getNumber(msg, msgError, min, max,limitMax, limitMin, reintentos, &buffer))///// revisarrrrrr
            {
                arrayResultado[i]=buffer;
            }
            else
            {
                retorno=-1;
                break;
            }
        }
    }

    return retorno;
}

////////////get char////////////////

int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferChar[256];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {

            if(!utn_getString(msg,msgError,1,3,reintentos,bufferChar)) //==0
            {
                if(isValidChar(bufferChar, min, max))
                {
                    printf("OK");
                    *resultado=bufferChar[0];
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_isValidChar(char* charRecibido, int min, int max)
{
    int i;
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    for( i=0 ; charRecibido[i] != '\0'  ; i++)
    {
        if(charRecibido[i]<'A' || (charRecibido[i]>'Z' && charRecibido[i]<'a') || charRecibido[i]>'z')
        {
            if(charRecibido[i]>=min && charRecibido[i] <= max)//valida rango
            retorno=0;
        }
    }
    return retorno;
}
////////////

int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {

            if(!utn_getString(msg,msgError,minSize,maxSize,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(utn_isValidTexto(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_isValidTexto(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<' ' || stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//*************************************************************
int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minSize,maxSize,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidAlphanumeric(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_isValidAlphanumeric(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || (stringRecibido[i]>'9' && stringRecibido[i]<'A') || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z' )
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}



/////////------------------///////////////

int utn_buscar_maximo(double valores[], int num_valores)
{
	int maximo_pos = 0;
	for (int i = 1; i < num_valores; i++) {
		if (valores[i] > valores[maximo_pos]) {
			maximo_pos = i;
		}
	}
	return maximo_pos;
}

