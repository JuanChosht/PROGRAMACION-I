#include <stdio.h>
#include "f.h"


int main (void) {
    int opcion;
    do {
        printf("\n****\tTIENDA\t****\n");
        opcion = opcionmenu();
        procesar(opcion); //switchs del menu
    } while (opcion != 0);
    return 0;   
}

