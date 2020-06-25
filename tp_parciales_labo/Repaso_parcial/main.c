#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "controller.h"
#include "utn.h"

int main()
{
    LinkedList* listaEntrega=ll_newLinkedList();

        if(!controller_loadFromText("data.csv",listaEntrega))
            printf("\nESTA OK");



        controller_saveAsText("informes.txt",listaEntrega);

    return 0;
}
