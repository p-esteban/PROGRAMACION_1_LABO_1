#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Employee.h"
#include "Controller.h"

#define SIZE_NOMBRE 128
#define SIZE_ID 10
#define SIZE_SUELDO 15
#define SIZE_HORAS 15
#define TRIES 2


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero a lista de empleados
 * \return int retorno (-1) en caso de error o punteros NULL (0) si carga correctamente
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile = NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        ll_clear(pArrayListEmployee);
        pFile=fopen(path,"r");
        if(pFile!=NULL)
        {
            printf("\n  CARGANDO...\n");
            retorno=parser_EmployeeFromText(pFile,pArrayListEmployee);
            ll_sort(pArrayListEmployee,employee_criterioId,1);
            fclose(pFile);
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero a lista de empleados
 * \return int retorno (-1) en caso de error o punteros NULL (0) si carga correctamente
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

    FILE* pFile;
    int retorno=-1;

    ll_clear(pArrayListEmployee);
    pFile=fopen(path,"rb");

    if(pFile != NULL && pArrayListEmployee != NULL && path !=NULL)
    {
        printf("\n  CARGANDO...\n");
        retorno = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    }
    fclose(pFile);
    ll_sort(pArrayListEmployee,employee_criterioId,1);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a lista de empleados
 * \return int retorno (-1) en caso de error o punteros NULL o valor ingresado incorrecto (0) si agrega correctamente
  *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* newEmployee;
    char nombre[SIZE_NOMBRE];
    char horasTrabajadasStr[SIZE_HORAS];
    char sueldoStr[SIZE_SUELDO];
    char idStr[SIZE_ID];
    int retorno=-1;
    int id;

    if (pArrayListEmployee != NULL &&
        !utn_getString("\nIngrese Nombre del empleado: ","\nError\n",3,SIZE_NOMBRE,TRIES,nombre)&&
        !utn_getString("\nIngrese Horas Trabajadas: ","\nError\n",1,SIZE_HORAS,TRIES,horasTrabajadasStr)&&
        !utn_getString("\nIngrese Sueldo: ","\nError\n",1,SIZE_SUELDO,TRIES,sueldoStr)&&
        !employee_maxId(pArrayListEmployee,&id))
        {
            sprintf(idStr, "%d", id+1);
            newEmployee = employee_newParametros(idStr,nombre,horasTrabajadasStr,sueldoStr);
            retorno=ll_add(pArrayListEmployee,newEmployee);
        }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero a lista de empleados
 * \return int retorno (-1) en caso de error o punteros NULL o valor ingresado incorrecto (0) si modifica correctamente
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* empleado=NULL;
    char idBuscado[SIZE_ID];
    char nombre[SIZE_NOMBRE];
    char horasTrabajadasStr[SIZE_HORAS];
    char sueldoStr[SIZE_SUELDO];
    int opcion;
    int index;

   if( pArrayListEmployee != NULL &&
       !utn_getString("\nIngrese id del empleado a Modificar:","\nError\n",1,SIZE_ID,TRIES,idBuscado) &&
       !employee_searchById(pArrayListEmployee,atoi(idBuscado),&index))
    {
        empleado = ll_get(pArrayListEmployee,index);
        utn_getInt("\n1- Modificar NOMBRE\n2- Modificar HORAS\n3- Modificar SUELDO\n4- Volver al menu principal\nIngrese opcion: ",
                   "\nOpcion invalida",1,4,sizeof(int),1,TRIES,&opcion);
        switch(opcion)
        {
            case 1:
                if(!utn_getString("\nIngrese Nombre del empleado: ","\nError\n",3,SIZE_NOMBRE,TRIES,nombre))
                    retorno=employee_setNombre(empleado,nombre);
                break;
            case 2:
                if(!utn_getString("\nIngrese Horas Trabajadas: ","\nError\n",1,SIZE_HORAS,TRIES,horasTrabajadasStr))
                    retorno=employee_setHorasTrabajadasStr(empleado,horasTrabajadasStr);
                break;
            case 3:
                if(!utn_getString("\nIngrese Sueldo: ","\nError\n",1,SIZE_SUELDO,TRIES,sueldoStr))
                    retorno=employee_setSueldoStr(empleado,sueldoStr);
                break;
            case 4:
                break;
        }
    }
    else
    {
        printf("\nId inexistente\n");
    }
    return retorno;
}


/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero a lista de empleados
 * \return int retorno (-1) en caso de error o punteros NULL o valor ingresado incorrecto
 *         o lista vacia (0) si elimina correctamente
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char idBuscado[SIZE_ID];
    int index;

       if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee)>0)
        {
            if( !utn_getString("\nIngrese id del empleado a Eliminar:","\nError\n",1,SIZE_ID,TRIES,idBuscado) &&
                !employee_searchById(pArrayListEmployee,atoi(idBuscado),&index))
            {
                retorno=ll_remove(pArrayListEmployee,index);
            }
            else
            {
                printf("\nNo existe el ID\n");
            }
        }
        else
        {
            printf("\nNo hay empleado en la nomina\n");
        }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a lista de empleados
 * \return int retorno (-1) en caso de error o punteros NULL o lista vacia (0) si lista correctamente
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* auxPunteroEmpleado;
    char nombre[SIZE_NOMBRE];
    int id;
    int horasTrabajadas;
    int sueldo;

    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee)>0 )
    {
        for (i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxPunteroEmpleado=ll_get(pArrayListEmployee,i);
            employee_getNombre(auxPunteroEmpleado,nombre);
            employee_getId(auxPunteroEmpleado,&id);
            employee_getHorasTrabajadas(auxPunteroEmpleado,&horasTrabajadas);
            employee_getSueldo(auxPunteroEmpleado,&sueldo);
            printf("\nId:%-4d Nombre: %-16s  Horas: %-6d Sueldo: %d" ,id,nombre,horasTrabajadas,sueldo);
            retorno=0;
        }
    }
    else
    {
        printf("\nNo hay empleado en la nomina\n");
    }
    return retorno;

}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a lista de empleados
 * \return int retorno (-1) en caso de error o punteros NULL o criterio ingresado incorrecto
 *         o lista vacia (0) si elimina correctamente
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
   int retorno=-1;
   int opcion;
   int flag = -1;

    if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0&&
       !utn_getInt("\n----SELECCIONAR CRITERIO----\n1-Nombre ascendente\n2-Nombre descendente\n3-Id ascendente\n4-Id descendente\n"
                   "5-Horas Trabajadas ascendente\n6-Horas Trabajadas descendente\n7-Sueldo ascendente\n8-Sueldo descendente\n9-Volver al Menu anterior\n",
                   "\nOpcion incorrecta\n",1,9,sizeof(int),1,TRIES,&opcion))
    {
        if(opcion!=9)
            printf("\n  ORDENANDO...\n");
        switch(opcion)
        {
            case 1:
                flag=ll_sort(pArrayListEmployee, employee_criterioName, 1);//1 a-a 0 z-a
            break;
            case 2:
                flag=ll_sort(pArrayListEmployee,employee_criterioName,0);
            break;
            case 3:
                flag=ll_sort(pArrayListEmployee,employee_criterioId,1);
            break;
            case 4:
                flag=ll_sort(pArrayListEmployee,employee_criterioId,0);
            break;
            case 5:
                flag=ll_sort(pArrayListEmployee,employee_criterioHoras,1);
            break;
            case 6:
                flag=ll_sort(pArrayListEmployee,employee_criterioHoras,0);
            break;
            case 7:
                flag=ll_sort(pArrayListEmployee,employee_criterioSueldo,1);
            break;
            case 8:
                flag=ll_sort(pArrayListEmployee,employee_criterioSueldo,0);
            break;
            case 9:
                retorno=0;
            break;
        }
        if(flag!=-1)
        {
            printf("\n----LISTA ORDENADA----\n");
            retorno =0;
        }
    }
    else
    {
        printf("\n NO hay elementos para ordenar!\n");
    }
    return retorno;
}




/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero a lista de empleados
 * \return int retorno (-1) en caso de error o punteros NULL (0) si guarda en el archivo correctamente
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    char id[1024];
    char sueldo[1024];
    char horasTrabajadas[1024];
    char nombre[1024];
    Employee * pEmpleado=NULL;
    FILE* pFile=NULL;

    if(path != NULL)
    {
        pFile=fopen(path,"w");

        if(pFile!=NULL && pArrayListEmployee !=NULL)
        {
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmpleado=ll_get(pArrayListEmployee,i);
                employee_getIdStr(pEmpleado,id);
                employee_getNombre(pEmpleado,nombre);
                employee_getSueldoStr(pEmpleado,sueldo);
                employee_getHorasTrabajadasStr(pEmpleado,horasTrabajadas);
                fprintf(pFile,"%s,%s,%s,%s\n",id,nombre,horasTrabajadas,sueldo);
                //printf("%s,%s,%s,%s\n",id,nombre,horasTrabajadas,sueldo);
            }
        fclose(pFile);
        retorno=0;
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero a lista de empleados
 * \return int retorno (-1) en caso de error o punteros NULL (0) si guarda en el archivo correctamente
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee *pEmployee=NULL;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmployee =ll_get(pArrayListEmployee,i);
                fwrite(pEmployee,sizeof(Employee),1,pFile);
            }
        }
        retorno =0;
        fclose(pFile);
    }
    return retorno;
}


