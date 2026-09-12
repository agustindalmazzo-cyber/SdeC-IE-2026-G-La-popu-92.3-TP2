// SecondLayerC.c
int procesar_gini(float indice_gini) {
    // La conversión de float a entero trunca los decimales automáticamente en C
    int indice_entero = (int)indice_gini;
    
    // Se devuelve el índice sumando uno (+1) como pide la consigna
    return indice_entero + 1;
}