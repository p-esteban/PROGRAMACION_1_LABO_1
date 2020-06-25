#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Employee.h"

#define QTY_EMPLOYEE 15
#define TRIES 1

int main()
{
    int option;
    int contadorId=0;
    int auxId;



    Employee listEmployee[QTY_EMPLOYEE];
    initEmployees(listEmployee,QTY_EMPLOYEE);
    mock(listEmployee,&contadorId);
    do
    {
        utn_getInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Informar \n5) Salir\n\n",
                    "\nError",1,5,sizeof(int),1,TRIES,&option);
        switch(option)
        {
            case 1: //Alta
                addEmployee(listEmployee,QTY_EMPLOYEE,&contadorId);
                break;
            case 2: //Modificar
                editEmployee(listEmployee,QTY_EMPLOYEE);
                break;
            case 3: //Baja
                if(isEmpty(listEmployee,QTY_EMPLOYEE))
                    printf("\nNo hay Empleados en la lista!\n");

                else
                {
                    utn_getInt("\nIngrese ID: ","\nError\n",0,QTY_EMPLOYEE,sizeof(int),0,TRIES,&auxId);
                    removeEmployee(listEmployee,QTY_EMPLOYEE,auxId);
                }
                break;
            case 4://Listar
                reportEmployee(listEmployee,QTY_EMPLOYEE);
                break;
            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(option!=6);
    return 0;
}
