global procesar_gini_asm

section .text
procesar_gini_asm:
    push rbp
    mov rbp, rsp

    ; En 64-bit Linux:
    ; RDI, RSI, RDX, RCX, R8, R9 tienen los valores 10, 20, 30, 40, 50, 60
    ; El 7mo parámetro (el índice GINI real) está en la pila en [rbp + 16]

    mov eax, dword [rbp + 16]   ; Trae el índice GINI desde el Stack a EAX
    add eax, 1                  ; Suma 1

    pop rbp
    ret                         ; Retorna a C (el resultado ya está en EAX)
