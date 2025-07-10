section .text
global ft_strcmp

ft_strcmp:

boucle:
    mov al, [rdi]
    mov bl, [rsi]

    cmp al, bl
    jne differents

    cmp al, 0
    je egaux

    inc rdi
    inc rsi
    jmp boucle

differents:
    movzx rax, al 
    movzx rbx, bl 
    sub rax, rbx  
    ret

egaux:
    mov rax, 0    
    ret