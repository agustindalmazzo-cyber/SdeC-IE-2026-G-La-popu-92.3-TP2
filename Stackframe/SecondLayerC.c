// SecondLayerC.c

// Declaramos la función en ensamblador
extern int procesar_gini_asm(int p1, int p2, int p3, int p4, int p5, int p6, int indice_entero);

// Esta es la función que Python llama vía ctypes
int procesar_gini(float indice_gini) {
    // Trunca los decimales
    int indice_entero = (int)indice_gini;
    
    // Pasa 6 valores basura (10 al 60) a los registros.
    int resultado = procesar_gini_asm(10, 20, 30, 40, 50, 60, indice_entero);
    resultado = resultado +9;
    return resultado;
}