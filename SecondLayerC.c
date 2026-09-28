// SecondLayerC.c
int procesar_gini(float indice_gini) {
    // La conversión de float a entero trunca los decimales automáticamente en C
    int indice_entero = (int)indice_gini;
    
    // Se devuelve el índice sumando uno (+1) como pide la consigna
    return indice_entero + 1;
}

//faltaria remplazar esta funcion por un codigo en assemble q haga la misma suma en el stack, y verlo mediante gdb
//queremos que no vayan en la registor, debriamos pasar 6 o 7 datos para que el proximo dato a pasar se vea en el stack y 
//se pueda mostrar en el gdb