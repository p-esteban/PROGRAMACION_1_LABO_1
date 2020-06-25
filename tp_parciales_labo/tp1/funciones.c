

/**
 * \brief Solicita un número entero al usuario y devuelve el resultado
 * \param  es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param  Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/** \brief suma dos operadores
 * \param recibe dos numeros
 * \return el resultado de la suma
 *
 */
float suma (float operadorA, float operadorB)
{
    float resultado;
    resultado = operadorA + operadorB;
    return resultado;

}


/** \brief realiza la resta entre dos numero
 * \param recibe dos numeros
 * \return devulve el resultado de la resta
 *
 */
float resta(float operadorA, float operadorB)
{
    float resultado;
    resultado = operadorA - operadorB;
    return resultado;
}


/** \brief divide dos numeros
 * \param recibe dos numeros
 * \return resultado de la division
 *
 */
 float division (float operadorA, float operadorB)
 {
     float resultado;

     resultado = operadorA / operadorB;
     return resultado;

 }

 /** \brief multiplica dos numeros
  * \param dos numeros
  * \return devuelve el resultado
  *
  */

float multiplicacion (float operadorA, float operadorB)
{
    float resultado;
    resultado = operadorA * operadorB;
    return resultado;
}

/** \brief calcula el factorial de un numero
 * \param numero
 * \return muestra el factorial
 *
 */
float factorial (float operadorA)
{
    float auxiliar = 1;
    float i;
    int retorno;

    if(operadorA <= 0)
    {
        retorno = -1;
        return retorno;
    }else
    {
        for( i = operadorA; i >= 1 ; i--)
        {
        auxiliar = auxiliar * i;

        }

        return auxiliar;
    }

}
