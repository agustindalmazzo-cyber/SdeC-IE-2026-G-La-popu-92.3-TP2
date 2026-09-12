import requests
import json
import ctypes

# 1. Cargamos la librería compilada de C
libcalculos = ctypes.CDLL('./libcalculos.so')

# 2. Definimos los tipos de datos (Python manda un float y C devuelve un entero)
libcalculos.procesar_gini.argtypes = (ctypes.c_float,)
libcalculos.procesar_gini.restype = ctypes.c_int

# 3. Definimos el objetivo
url_objetivo = "https://api.worldbank.org/v2/en/country/AR/indicator/SI.POV.GINI?format=json&date=2011:2020&per_page=32500&page=1"

def conectar_api():
    print("Iniciando conexión con la base de datos objetivo...")
    
    try:
        respuesta = requests.get(url_objetivo)
        
        if respuesta.status_code == 200:
            print("Conexión establecida con éxito (Estado: 200 OK)\n")
            
            datos = respuesta.json()
            
            # La información del Banco Mundial viene en una lista. 
            # En la posición 0 hay metadatos, y en la posición 1 están los registros reales.
            registros = datos[1]
            
            print("--- Índice GINI de Argentina (2011-2020) ---")
            
            # AQUÍ ESTÁ EL FOR: Recorremos cada elemento de la lista de registros
            for registro in registros:
                anio = registro['date']
                valor = registro['value']
                
                # Algunos años pueden no tener datos (viene como None), los filtramos
                if valor is not None:
                    # Llamamos a nuestro programa en C pasándole el valor flotante
                    resultado_c = libcalculos.procesar_gini(valor)
                    
                    print(f"Año: {anio} | GINI Original: {valor} | GINI Procesado en C (+1): {resultado_c}")
            
            return datos
        else:
            print(f"Fallo en la misión. Código de error: {respuesta.status_code}")
            return None
            
    except requests.exceptions.RequestException as e:
        print(f"Error crítico de red: {e}")
        return None

# Ejecución
if __name__ == "__main__":
    datos_crudos = conectar_api()