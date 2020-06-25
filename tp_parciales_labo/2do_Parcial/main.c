#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "controller.h"
#include "utn.h"

int main()
{
    LinkedList* listaVentas=ll_newLinkedList();

        if(!controller_loadFromText("data.csv",listaVentas))
            printf("\nESTA OK");



        controller_saveAsText("informes.txt",listaVentas);

    return 0;
}
