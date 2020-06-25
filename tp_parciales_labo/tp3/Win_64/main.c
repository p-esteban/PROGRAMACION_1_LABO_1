#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        utn_getInt( "\n\n------------MENU PRINCIPAL------------"
                    "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)"
                    "\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)"
                    "\n3. Alta de empleado"
                    "\n4. Modificar datos de empleado"
                    "\n5. Baja de empleado"
                    "\n6. Listar empleados"
                    "\n7. Ordenar empleados"
                    "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)"
                    "\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)"
                    "\n10. Salir\nIngrese Opcion:","\nOpcion invalida",0,10,sizeof(int),1,1,&option);
        switch(option)
        {
            case 1:
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("\nCarga exitosa! %d\n", ll_len(listaEmpleados));
                }
                else
                {
                    printf("\nNo se realizo la carga");
                }
                break;
            case 2:
                if(!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("\nCarga exitosa! %d\n", ll_len(listaEmpleados));
                }
                else
                {
                    printf("\nNo se realizo la carga");
                }
                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados))
                {
                    printf("\nAlta exitosa!\n");
                }
                else
                {
                    printf("\nNo se realizo el Alta");
                }
                break;
            case 4:
                if(!controller_editEmployee(listaEmpleados))
                {
                    printf("\nModificado exitosamente!\n");
                }
                else
                {
                    printf("\nNo se realizo Modificacion");
                }
                break;
            case 5:
                if(!controller_removeEmployee(listaEmpleados))
                {
                    printf("\nEliminado!\n");
                }
                else
                {
                    printf("\nNo se pudo Eliminar");
                }
                break;
            case 6:
                if(controller_ListEmployee(listaEmpleados))
                    printf("\nERROR!");
             break;
            case 7:
                if(controller_sortEmployee(listaEmpleados)==-1)
                    printf("\nERROR!");;
                break;
            case 8:
                if(!controller_saveAsText("data.bkp",listaEmpleados))
                {
                    printf("\nGUARDADO!\n");
                }
                else
                {
                    printf("\nNo se pudo guardar");
                }
                break;
            case 9:
                if(!controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf("\nGUARDADO!\n");
                }
                else
                {
                    printf("\nNo se pudo guardar");
                }
                break;
            case 10:

                break;
        }
    }while(option != 10);
    return 0;
}
