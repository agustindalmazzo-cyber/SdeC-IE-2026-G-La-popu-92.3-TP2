#include <stdio.h>

// Declaramos la función que tienes en calculos.c
extern int procesar_gini(float indice_gini);

int main() {
    int i;
    float valor_prueba = 42.7;

    // Ejecutamos la función millones de veces, simulando el "bucle de cálculo" del TP1
    for(i = 0; i < 10000000; i++) {
        procesar_gini(valor_prueba);
    }

    return 0;
}