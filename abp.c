#include <stdio.h>
#include <stdbool.h>

bool esNumeroValido(int *numero) {
    char buffer[50];
    return fgets(buffer, sizeof(buffer), stdin) != NULL && sscanf(buffer, "%d", numero) == 1;
}

int solicitarMonto(const char *mensaje, int min, int max) {
    int monto;
    while (true) {
        printf("%s (%d-%d): ", mensaje, min, max);
        if (esNumeroValido(&monto) && monto >= min && monto <= max) {
            break;
        }
        printf("El monto debe ser un número entre %d y %d.\n", min, max);
    }
    return monto;
}

void calcularCambio(int cambio) {
    int denominaciones[] = {10, 5, 2, 1};
    int cantidad[4] = {0};
    int total_monedas = 0;

    for (int i = 0; i < 4; i++) {
        cantidad[i] = cambio / denominaciones[i];
        cambio %= denominaciones[i];
        total_monedas += cantidad[i];
    }

    printf("Cambio a devolver:\n");
    printf("Monedas de 10: %d\n", cantidad[0]);
    printf("Monedas de 5: %d\n", cantidad[1]);
    printf("Monedas de 2: %d\n", cantidad[2]);
    printf("Monedas de 1: %d\n", cantidad[3]);
    printf("Total de monedas: %d\n", total_monedas);
}

int main() {
    int total_cobrar, monto_pagado, cambio;

   
    total_cobrar = solicitarMonto("Ingrese el monto total a cobrar", 1, 100);

    monto_pagado = solicitarMonto("Ingrese el monto pagado por el cliente", total_cobrar, 100);

    cambio = monto_pagado - total_cobrar;

    if (cambio == 0) {
        printf("No hay cambio a devolver.\n");
    } else {
        
        calcularCambio(cambio);
    }

    return 0;
}
