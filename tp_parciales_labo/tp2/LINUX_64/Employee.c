#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Employee.h"

#define TRIES 1


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int returnAux (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
    int returnAux=-1;
    if(list!= NULL && len>0)
    {
        for(;len>0;len--)
        {
            list[len-1].isEmpty=1;
        }
        returnAux=0;
    }
    return returnAux;
}

/** \brief Find the first empty place in an array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param index int* Pointer to the position of the array where the searched value is
* \return int returnAux (-1) if there is no empty placeo Error [Invalid length or NULL pointer] - (0) if it finds an empty position
*
*/
int findEmpty(Employee* list, int len, int* index)
{
    int returnAux=-1;
    int i;
    if(list!= NULL && len>=0 && index!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==1)
            {
                returnAux=0;
                *index=i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee* Pointer to array of employees
 * \param len int Array length
 * \return int returnAux (-1) if Error [Invalid length or NULL pointer or without
    free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int* contadorID)
{
    int returnAux=-1;
    int index;
    if(list!=NULL && len>0 && contadorID!=NULL)
    {
        if(findEmpty(list,len,&index))
            printf("\nNo hay lugares vacios");

        else
        {
            (*contadorID)++;
            list[index].id=*contadorID;
            list[index].isEmpty=0;
            utn_getName("\nIngrese nombre:","\nError\n",2,TEXT_SIZE,TRIES,list[index].name);
            utn_getSurName("\nIngrese apellido:","\nError\n",2,TEXT_SIZE,TRIES,list[index].lastName);
            utn_getFloatSigne("\nIngrese salario: ","\nError\n",0,1000000,10,0,TRIES,&list[index].salary);
            utn_getInt("\nIngrese sector: ","\nError\n",0,100,sizeof(int),0,TRIES,&list[index].sector);
            printf("\nAlta exitosa!");
            //printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s\n salario: %f\n sector: %d",
                 //  index, list[index].id,list[index].name,list[index].lastName,list[index].salary,list[index].sector);
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int sought value
 * \return returnAux employee index position or (-1) if [Invalid length or NULL
    pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
    int returnAux=-1;
    int i;
    if(list!= NULL && len>=0 && id>=0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty)
                continue;

            if(list[i].id==id)
            {
                 returnAux=i;
                  break;
            }
        }
    }
    return returnAux;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int sought value
 * \return int returnAux (-1) if Error [Invalid length or NULL pointer or if can't
    find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
    int returnAux=-1;
    int index;

    if(list!=NULL && len>0)
    {
        index = findEmployeeById(list,len,id);
        if(id<1 && id >len)
            printf("\nNo existe este ID");

        else
        {
            list[index].isEmpty=1;
            list[index].id=0;
            list[index].salary=0;
            list[index].sector=0;
            strcpy(list[index].name,"");
            strcpy(list[index].lastName,"");
            printf("\nBaja exitosa\n");
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Sort the elements in the array of employees, the argument order
    indicate UP or DOWN order
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [0] indicate UP - [1] indicate DOWN
 * \return int returnAux (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
    int returnAux=-1;
    int i;
    Employee buffer;
    int flagSwap;

    if(list!=NULL && len>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 0; i < len-1; i++)
            {
                if( ((strcmp(list[i].lastName,list[i+1].lastName) < 0) && order) ||  //1 descendente
                    ((strcmp(list[i].lastName,list[i+1].lastName) > 0) && !order) )  //0ascendente
                {
                    flagSwap=1;
                    buffer = list[i];
                    list[i] = list[i+1];
                    list[i+1] = buffer;
                }
                else if(strcmp(list[i].lastName,list[i+1].lastName) == 0)
                {
                    if( ((list[i].sector < list[i+1].sector) && order) ||
                        ((list[i].sector > list[i+1].sector) && !order) )
                    {
                        flagSwap=1;
                        buffer = list[i];
                        list[i] = list[i+1];
                        list[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        returnAux=0;
    }
    return returnAux;
}

/** \brief print the content of employees array
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int returnAux (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee* list, int length)
{
    int returAux=-1;
    int i;
    if(list!=NULL && length>=0)
    {
        for(i=0;i<length;i++)
        {
            if(list[i].isEmpty)
                continue;
            else
                printf(" ID: %d\n nombre: %s\n apellido: %s\n salario: %.2f\n sector: %d\n--------------------\n",
                       list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
        returAux=0;
    }
    return returAux;
}
/** \brief Search for an item by ID and modify its fields
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int returnAux (-1) if Error [Invalid length or NULL pointer or can not find elements with the desired value] - (0) if Ok
 *
 */

int editEmployee(Employee* list, int len)
{
    int returnAux=-1;
    int index;
    int auxId;
    char option;
    if(list!=NULL && len>0)
    {
        if(isEmpty(list,len))
            printf("\nNo hay Empleados en la lista!\n");

        else
        {
            utn_getInt("\nIngrese ID: ","\nError\n",1,len,sizeof(int),0,TRIES,&auxId);
            index=findEmployeeById(list,len,auxId);
        }
        if(auxId<1 && auxId >len && index<0 )
            printf("\nNo existe este ID");

        else
        {
            do
            {
                utn_getChar("\n\n------MODIFICAR-----\nA. Nombre\nB. Apellido\nC. Salario\nD. Sector\n S. Volver al Menu Anterior\n",
                            "\nError\n",1,sizeof(char),TRIES,&option);
                switch(option)
                {
                    case 'A':
                        returnAux=utn_getName("\nIngrese nombre:","\nError\n",2,TEXT_SIZE,TRIES,list[index].name);
                        break;
                    case 'B':
                        returnAux=utn_getSurName("\nIngrese apellido:","\nError\n",2,TEXT_SIZE,TRIES,list[index].lastName);
                        break;
                    case 'C':
                        returnAux=utn_getFloatSigne("\nIngrese salario: ","\nError\n",0,1000000,10,0,TRIES,&list[index].salary);
                        break;
                    case 'D':
                        returnAux=utn_getInt("\nIngrese sector: ","\nError\n",0,100,sizeof(int),0,TRIES,&list[index].sector);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
                if(!returnAux)
                    printf("\nModificacion exitos!\n");
            }while(option!='S');
        }
    }
    return returnAux;
}
/** \brief Employee report ordered and average list
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int returnAux (-1)  Error [lInvalid length or NULL pointer] - (0) is OK
 */

int reportEmployee(Employee* list, int len)
{
    int returnAux =-1;
    char option;
    int auxOrder;

    if(list!=NULL && len >0)
    {
        if(isEmpty(list,len))
             printf("\nNo hay Empleados en la lista!\n");

        else
        {
            do
            {
                utn_getChar("\n---------INFORMAR---------\nA. Listado Ordenado por Apellido y Salario\nB. Total y Promedio de salarios"
                            "\n S.Menu anterior\n","\nError\n",1,sizeof(char),TRIES,&option);
                switch(option)
                {
                case 'A':
                    if(!utn_getInt("\n------ORDENAR-----\n0.Ascendente\n1.Descendente\n","\nError\n",0,1,sizeof(int),1,TRIES,&auxOrder))
                    {
                        sortEmployees(list,len,auxOrder);
                        printEmployees(list,len);
                    }
                    break;
                case 'B':
                    reportSalary(list,len);
                    break;
                case 'S':
                    break;
                }
            }while(option!='S');
        }
    }
    return returnAux;
}
/** \brief Report total and average salaries, and how many employees exceed the average salary.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int returnAux (-1)  Error [lInvalid length or NULL pointer] - (0) is OK
 */
int reportSalary(Employee* list, int len)
{
    int returnAux=-1;
    int i;
    int k;
    int employeeQty=0;
    float totalSalary=0;
    int lowerThanAverage=0;
    float average;

    if(list!=NULL && len >0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==1)
                continue;

            else
            {
                employeeQty++;
                totalSalary+=list[i].salary;
            }
        }
        average= (float)totalSalary/employeeQty;
        for(k=0;k<len;k++)
        {
            if(list[k].isEmpty==1)
                continue;

            else if(list[k].salary==average)
            {
                lowerThanAverage++;
            }
        }
        printf("\nTotal de salarios %.2f Promedio: %.2f\n %d Empleados no superan el promedio\n",totalSalary,average,lowerThanAverage);
        returnAux=0;
    }
    return returnAux;
}
/** \brief Find a busy place in an array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int returnAux (-1) if there is  empty array Error [Invalid length or NULL pointer] - (0) if it finds a busy position
 *
 */
int isEmpty(Employee* list, int len)
{
    int returnAux=-1;
    int i;
    if(list!=NULL && len >0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty)
                continue;

            returnAux=0;
        }
    }
    return returnAux;
}

void mock(Employee* list, int* contadorID)
{

    list[0].id=1;
    list[0].isEmpty=0;
    list[0].sector=2;
    list[0].salary=10250;
    strcpy(list[0].name,"Lou");
    strcpy(list[0].lastName,"Czhe");
    (*contadorID)++;

    list[1].id=2;
    list[1].isEmpty=0;
    list[1].sector=2;
    list[1].salary=10523;
    strcpy(list[1].name,"Perez");
    strcpy(list[1].lastName,"Ana");
    (*contadorID)++;

    list[2].id=3;
    list[2].isEmpty=0;
    list[2].sector=4;
    list[2].salary=10000;
    strcpy(list[2].name,"Daniel");
    strcpy(list[2].lastName,"ALguien");
    (*contadorID)++;

    list[3].id=4;
    list[3].isEmpty=0;
    list[3].sector=2;
    list[3].salary=14000;
    strcpy(list[3].name,"Esteban");
    strcpy(list[3].lastName,"Otro");
    (*contadorID)++;

    list[4].id=5;
    list[4].isEmpty=0;
    list[4].sector=1;
    list[4].salary=15000;
    strcpy(list[4].name,"Juan");
    strcpy(list[4].lastName,"Pepe");
    (*contadorID)++;

    list[5].id=6;
    list[5].isEmpty=0;
    list[5].sector=4;
    list[5].salary=15800;
    strcpy(list[5].name,"Fede");
    strcpy(list[5].lastName,"Ahce");
    (*contadorID)++;

    list[6].id=7;
    list[6].isEmpty=0;
    list[6].sector=4;
    list[6].salary=17000;
    strcpy(list[6].name,"Pedro");
    strcpy(list[6].lastName,"Almodovar");
    (*contadorID)++;

    list[7].id=8;
    list[7].isEmpty=0;
    list[7].sector=3;
    list[7].salary=17257;
    strcpy(list[7].name,"Virginia");
    strcpy(list[7].lastName,"Woolf");
    (*contadorID)++;

    list[8].id=9;
    list[8].isEmpty=0;
    list[8].sector=1;
    list[8].salary=18258;
    strcpy(list[8].name,"Salome");
    strcpy(list[8].lastName,"Vorfas");
    (*contadorID)++;

    list[9].id=10;
    list[9].isEmpty=0;
    list[9].sector=2;
    list[9].salary=19259;
    strcpy(list[9].name,"Anibal");
    strcpy(list[9].lastName,"Fernandez");
    (*contadorID)++;

    list[10].id=11;
    list[10].isEmpty=0;
    list[10].sector=2;
    list[10].salary=110210;
    strcpy(list[10].name,"Pepe");
    strcpy(list[10].lastName,"Mujica");
    (*contadorID)++;

    list[11].id=12;
    list[11].isEmpty=0;
    list[11].sector=3;
    list[11].salary=112511;
    strcpy(list[11].name,"Juan");
    strcpy(list[11].lastName,"Peron");
    (*contadorID)++;

    list[12].id=13;
    list[12].isEmpty=0;
    list[12].sector=4;
    list[12].salary=122512;
    strcpy(list[12].name,"Jorge");
    strcpy(list[12].lastName,"Rial");
    (*contadorID)++;

    list[13].id=14;
    list[13].isEmpty=0;
    list[13].sector=2;
    list[13].salary=112513;
    strcpy(list[13].name,"Papa");
    strcpy(list[13].lastName,"Francisco");
    (*contadorID)++;

}

