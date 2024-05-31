#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "f.h"


int main (void) {
    int opcion;
    do {
        printf("\n****\t1001 AUTOS\t****\n");
        opcion = opcionmenu();
        procesar(opcion); 
    } while (opcion != 0);
    return 0;   
}

