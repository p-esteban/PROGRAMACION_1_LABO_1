#define TRUE 1
#define FALSE 0

int utn_getString ( char* msg,
                char* msgError,
                int limitMin,
                int limitMax,
                int reintentos,
                char* resultado);

int utn_myGetString (char* bufferS,  int limitMax);
//-------------------------------------

//-------NOMBRE --------

int utn_getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);


int utn_isValidName (char* cadena);

//--------APELLIDO ------------

int utn_getSurName (  char* msg,
                    char* msgError,
                    int limitMin,
                    int limitMax,
                    int reintentos,
                    char* resultado);

int utn_isValidSurName (char* cadena);

//-----------NUMERO -----------------
int utn_getNumber (char* msg,
                   char* msgError,
                   int minimo,
                   int maximo,
                   int limitMax,
                   int limitMin,
                   int reintentos,
                   int* resultado);

int utn_isValidNumber (char* cadena);

int utn_isValidRank (char* cadena, int minimo, int maximo);

//-------NUMERO CON COMA ---------

int utn_getFloat ( char* msg,
                   char* msgError,
                   float minimo,
                   float maximo,
                   int limitMax,
                   int limitMin,
                   int reintentos,
                   float* resultado);

int utn_isValidFloat (char* cadena);

int utn_isValidRankFloat (char* cadena, float minimo, float maximo);

//-------NUMERO CON COMA NEGATIVO ---------

int utn_getFloat ( char* msg,
                   char* msgError,
                   float minimo,
                   float maximo,
                   int limitMax,
                   int limitMin,
                   int reintentos,
                   float* resultado);

int utn_isValidFloat (char* cadena);

int utn_isValidRankFloat (char* cadena, float minimo, float maximo);

//----- EDAD ---------
int utn_getEdad   (char* msg,
                   char* msgError,
                   int minimo,
                   int maximo,
                   int limitMax,
                   int limitMin,
                   int reintentos,
                   int* resultado);
int utn_isValidEdad (char* cadena);

//--------TELEFONO-------

int utn_getTelephone ( char* msg,
                       char* msgError,
                       int minimo,
                       int maximo,
                       int limitMax,
                       int limitMin,
                       int reintentos,
                       int* resultado);

int utn_isValidTelephone (char* cadena);

//-------CUIT--------

int utn_getCuit       (char* msg,
                       char* msgError,
                       int limitMax,
                       int limitMin,
                       int reintentos,
                       char* resultado);

int utn_isValidCuit (char* cadena);



