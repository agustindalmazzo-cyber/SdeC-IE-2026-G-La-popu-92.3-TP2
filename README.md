# Trabajo Práctico N° 2 - Interfaz Multicapa y Procesamiento en Ensamblador

Este repositorio contiene la implementación del **Trabajo Práctico N° 2**, enfocado en la integración de capas de software de alto y bajo nivel. El sistema consume datos desde una API REST en Python, interactúa con un módulo intermedio en C y ejecuta cálculos numéricos optimizados (índice de Gini) implementados en lenguaje Ensamblador respetando las convenciones de llamada estándar.

---

## 🏗️ Arquitectura del Sistema

El proyecto se estructura en 3 capas principales:

1. **Capa Superior (Python - `MainPython.py`):**
   * Realiza las peticiones a la API REST para recuperar los datos de entrada.
   * Procesa la información inicial y se comunica mediante enlaces dinámicos/Ctypes con la capa en C.
   * Presenta los resultados finales procesados.

2. **Capa Intermedia (C - `SecondLayerC.c` / `MainTEST.c`):**
   * Actúa como puente entre Python y la rutina en bajo nivel.
   * Invoca a la rutina en Assembly cargando argumentos a través de la pila/registros según las convenciones de llamada (*Calling Conventions* / CDECL / System V ABI).

3. **Capa de Bajo Nivel (Assembly - `gini.asm`):**
   * Implementa los algoritmos de cálculo numérico y conversión (Índice de Gini) directamente en ensamblador.
   * Maneja el marco de pila (*stack frame*) para la recepción de parámetros y la devolución del resultado.

---

## 📂 Estructura del Repositorio

A partir de la disposición de archivos del proyecto, la estructura se organiza de la siguiente manera:

```text
.
├── CodigosDelLibro/        # Códigos de referencia y material bibliográfico
├── Imagenes/               # Diagramas y capturas de pantalla para documentación
├── MainPython.py           # Capa de nivel superior en Python (Consumo API REST)
├── SecondLayerC.c          # Código fuente en C (Capa intermedia)
├── MainTEST.c              # Pruebas unitarias y profiling de la capa en C
├── gini.asm                # Código fuente en Ensamblador (Cálculos de Gini)
├── libcalculos.so          # Librería compartida compilada para consumo de Python
├── programa_gini           # Ejecutable compilado para pruebas directas en C
├── analysis_gini.txt       # Informe de análisis y resultados de profiling
├── test_profiling          # Script/Binario para la ejecución de pruebas de rendimiento
├── gmon.out                # Archivo generado por gprof para análisis de profiling
└── README.md               # Documentación del proyecto
