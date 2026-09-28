#include <stdio.h>

// Método 1: Bucle simple eliminando el bit menos significativo
int count_bits_1(unsigned int data) {
    int cnt = 0;
    while(data != 0) {
        data = data & (data - 1);
        cnt++;
    }
    return cnt;
}

// Método 2: Tabla de búsqueda (Lookup table)
static unsigned char byte_bit_count[256]; 

void initialize_count_bits() {
    int cnt, i, data;
    for(i = 0; i < 256; i++) {
        cnt = 0;
        data = i;
        while(data != 0) { 
            data = data & (data - 1);
            cnt++;
        }
        byte_bit_count[i] = cnt;
    }
}

int count_bits_2(unsigned int data) {
    const unsigned char * byte = (unsigned char *) &data;
    return byte_bit_count[byte[0]] + byte_bit_count[byte[1]] +
           byte_bit_count[byte[2]] + byte_bit_count[byte[3]];
}

// Método 3: Conteo en paralelo usando máscaras de bits
int count_bits_3(unsigned int x) {
    static unsigned int mask[] = { 0x55555555,
                                   0x33333333,
                                   0x0F0F0F0F,
                                   0x00FF00FF,
                                   0x0000FFFF };
    int i;
    int shift; 
    for(i = 0, shift = 1; i < 5; i++, shift *= 2) {
        x = (x & mask[i]) + ((x >> shift) & mask[i]);
    }
    return x;
}

int main() {
    // Inicializamos la tabla requerida por el Método 2
    initialize_count_bits();
    
    // Probamos con el número 43 (En binario: 101011, que tiene 4 bits en '1')
    unsigned int numero_prueba = 43;
    
    printf("Evaluando el número: %u\n\n", numero_prueba);
    
    printf("Resultado Método 1: %d bits\n", count_bits_1(numero_prueba));
    printf("Resultado Método 2: %d bits\n", count_bits_2(numero_prueba));
    printf("Resultado Método 3: %d bits\n", count_bits_3(numero_prueba));
    
    return 0;
}
