#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno= 1;
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];
    Employee *pEmpleado;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

            pEmpleado = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

            if(pEmpleado != NULL)
            {
                if(!ll_add(pArrayListEmployee,pEmpleado))
                    retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int estado=1;
    Employee* pEmpleado;

    do
    {
        pEmpleado = employee_new();
        if(fread(pEmpleado,sizeof(Employee),1, pFile)!=0) //porque cuento con 1
        {
            ll_add(pArrayListEmployee,pEmpleado);
            estado=0;
        }
        else
        {
            employee_delete(pEmpleado);
        }

    }while( !feof(pFile));

    return estado;

/*
    int retorno=-1;
    Employee auxEmpleado;
    Employee* pEmpleado;
    int contador=0;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
          pEmpleado=employee_new();

        while( fread(&auxEmpleado,sizeof(Employee),1,pFile)!=0)
        {
            printf("\nLEYENDO EN EL BIN %d",contador++);
                printf("\n%s", auxEmpleado.nombre);

            if(pEmpleado!=NULL)
            {
                ll_add(pArrayListEmployee,pEmpleado);


                retorno=0;
            }
            else
            {
                employee_delete(pEmpleado);

            }
        }
    }

    return retorno;
    */
}
