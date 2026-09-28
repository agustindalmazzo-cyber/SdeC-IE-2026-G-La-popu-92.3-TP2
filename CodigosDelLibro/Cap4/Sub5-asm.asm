%include "asm_io.inc"

segment .text
global calc_sum

calc_sum:
    enter 4,0 ; hace espacio para sum en la pila
    push ebx ; IMPORTANTE!

    mov dword [ebp-4], 0 ; sum = 0
    dump_stack 1, 2, 4 ; imprime la pila desde ebp-8 hasta ebp+16
    
    mov ecx, 1 ; ecx es i en el pseudocodigo
for_loop:
    cmp ecx, [ebp+8] ; cmp i y n
    jnle end_for ; si no i <= n, sale

    add [ebp-4], ecx ; sum += i
    inc ecx
    jmp short for_loop

end_for:
    mov ebx, [ebp+12] ; ebx = sump
    mov eax, [ebp-4] ; eax = sum
    mov [ebx], eax

    pop ebx ; restaura ebx
    leave
    ret
