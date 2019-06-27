
#define TRUE 1
#define FALSE 0

/**
* \brief Solicita una CADENA DE CARACTERES
* \param msg Es el mensaje a ser mostrado
* \param msgError Es el mensaje a ser mostrado en caso de error
* \param limitMin Longitud mínima de la cadena
* \param limitMax Longitud máxima de la cadena
* \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \param resultado Se carga el string ingresado
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int utn_getString ( char* msg,
                    char* msgError,
                    int limitMin,
                    int limitMax,
                    int reintentos,
                    char* resultado);


/** \brief Elimina el salto de linea y finaliza la cadena con [\0]
 *
 * \param bufferS: cadena que recorre y donde guarda el resultado
 * \param limitMax: Longitud máxima de la cadena
 * \return [TRUE] cuando la cadena se guarda correctamente, si no [FALSE]
 *
 */
int utn_myGetString (char* bufferS,  int limitMax);


/**
* \brief Solicita una cadena de caracteres de SOLO LETRAS y la valida
* \param msg Es el mensaje a ser mostrado
* \param msgError Es el mensaje a ser mostrado en caso de error
* \param minimo Longitud mínima de la cadena
* \param maximo Longitud máxima de la cadena
* \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \param resultado Se carga el string ingresado
* \return Si obtuvo la cadena [0] si no [-1]
*
*/


int utn_getName (   char* msg,
                    char* msgError,
                    int minimo,
                    int maximo,
                    int reintentos,
                    char* resultado);


int utn_isValidName (char* cadena);

/**
* \brief Solicita una cadena de caracteres de SOLO LETRAS y la valida
* \param msg Es el mensaje a ser mostrado
* \param msgError Es el mensaje a ser mostrado en caso de error
* \param limitMin Longitud mínima de la cadena
* \param limitMax Longitud máxima de la cadena
* \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \param resultado Se carga el string ingresado
* \return Si obtuvo la cadena [0] si no [-1]
*
*/


int utn_getSurName (  char* msg,
                      char* msgError,
                      int limitMin,
                      int limitMax,
                      int reintentos,
                      char* resultado);

int utn_isValidSurName (char* cadena);

/**
* \brief Solicita un numero ENTERO CON SIGNO y lo valida
* \param msg Es el mensaje a ser mostrado
* \param msgError Es el mensaje a ser mostrado en caso de error
* \param minimo:  Valor minimo admitido (inclusive)
* \param maximo:  Valor maximo admitido (inclusive)
* \param limitMin Longitud mínima de la cadena
* \param limitMax Longitud máxima de la cadena
* \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \param resultado Se carga el string ingresado
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
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


/**
* \brief Solicita un NUMERO CON COMA y lo valida
* \param msg Es el mensaje a ser mostrado
* \param msgError Es el mensaje a ser mostrado en caso de error
* \param minimo:  Valor minimo admitido (inclusive)
* \param maximo:  Valor maximo admitido (inclusive)
* \param limitMin Longitud mínima de la cadena
* \param limitMax Longitud máxima de la cadena
* \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \param resultado Se carga el string ingresado
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
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

/**
* \brief Solicita un NUMERO CON COMA Y SIGNO y lo valida
* \param msg Es el mensaje a ser mostrado
* \param msgError Es el mensaje a ser mostrado en caso de error
* \param minimo:  Valor minimo admitido (inclusive)
* \param maximo:  Valor maximo admitido (inclusive)
* \param limitMin Longitud mínima de la cadena
* \param limitMax Longitud máxima de la cadena
* \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \param resultado Se carga el string ingresado
* \return Si obtuvo la cadena [0] si no [-1]
*
*/

int utn_getFloatSigne (char* msg,
                       char* msgError,
                       float minimo,
                       float maximo,
                       int limitMax,
                       int limitMin,
                       int reintentos,
                       float* resultado);

int utn_isValidFloat (char* cadena);

int utn_isValidRankFloat (char* cadena, float minimo, float maximo);


/**
* \brief Solicita un número al usuario y lo valida
* \param msg: mensaje a ser mostrado
* \param msgError: Es el mensaje a ser mostrado en caso de error
* \param minimo:  Valor minimo admitido (inclusive)
* \param maximo:  Valor maximo admitido (inclusive)
* \param limitMin: Valor mínimo de caracteres admitidos
* \param limitMax Valor máximo de caracteres admitidos
* \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \param resultado: Se carga el numero ingresado
* \return devuleve 0 si el numero se toma correctamente o -1 si no se puede tomar.
*
*/
//----- ENTERO ---------
int utn_getInt    (char* msg,
                   char* msgError,
                   int minimo,
                   int maximo,
                   int limitMax,
                   int limitMin,
                   int reintentos,
                   int* resultado);

int utn_isValidInt (char* cadena);


/**
* \brief Solicita un numero TELEFONO y lo valida
* \param msg Es el mensaje a ser mostrado
* \param msgError Es el mensaje a ser mostrado en caso de error
* \param minimo:  Valor minimo admitido (inclusive)
* \param maximo:  Valor maximo admitido (inclusive)
* \param limitMin Longitud mínima de la cadena
* \param limitMax Longitud máxima de la cadena
* \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \param resultado Se carga el string ingresado
* \return Si obtuvo la cadena [0] si no [-1]
*
*/

int utn_getTelephone ( char* msg,
                       char* msgError,
                       int limitMax,
                       int limitMin,
                       int reintentos,
                       char* resultado);

int utn_isValidTelephone (char* cadena);

/**
* \brief Solicita un numero CUIT y lo valida
* \param msg Es el mensaje a ser mostrado
* \param msgError Es el mensaje a ser mostrado en caso de error
* \param limitMin Longitud mínima de la cadena
* \param limitMax Longitud máxima de la cadena
* \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \param resultado Se carga el string ingresado
* \return Si obtuvo la cadena [0] si no [-1]
*
*/

int utn_getCuit       (char* msg,
                       char* msgError,
                       int limitMax,
                       int limitMin,
                       int reintentos,
                       char* resultado);

int utn_isValidCuit (char* cadena);

int utn_isValidDigitoVerificador (char* cadena);


/**
* \brief Solicita un EMAIL al usuario y lo valida
* \param msg Es el mensaje a ser mostrado
* \param msgError Es el mensaje a ser mostrado en caso de error
* \param limitMin Longitud mínima de la cadena
* \param limitMax Longitud máxima de la cadena
* \param reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \param resultado Se carga el string ingresado
* \return Si obtuvo la cadena [0] si no [-1]
*
*/

int utn_getEmail      (char* msg,
                       char* msgError,
                       int limitMax,
                       int limitMin,
                       int reintentos,
                       char* resultado);

int utn_isValidEmail (char* cadena);

/** \brief recibe una cadena de caracteres y se elimina un caracter que se pssa como parametro
 *
 * \param cadena: puntero donde se guarda el resultado
 * \param chart: caracter que se quiere eliminar
 * \param limitMax: limite maximo de caracteres admitidos para guardar en cadena
 * \return [-1] si falla [0] si es correcto
 *
 */
int utn_eliminarCarcter (char* cadena, char chart, int limitMax);

/**
* \brief Solicita un DNI al usuario y valida si son numeros y tiene un largo minimo de 7 y maximo de 8
* \param pStr: Se carga el string ingresado
* \param msg Es el mensaje a ser mostrado
* \param msgError Es el mensaje a ser mostrado en caso de error
* \param tries: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \return Si obtuvo la cadena [0] si no [1]
*
*/
int utn_getDni (char* pStr, char* msg, char* msgE,int tries);
int utn_isValidDni (char* pStr);



/////////
int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int utn_isValidChar(char* charRecibido, int min, int max);

int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int utn_isValidTexto(char* stringRecibido);

int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int utn_isValidAlphanumeric(char* stringRecibido);

