default rel ; adresse absolue -> relative : programme peux etre charger n importe ou pas fixe
section .text
global ft_write
extern __errno_location

ft_write:
    mov rax, 1
    syscall

    cmp rax, 0
    jl .error
    ret

.error:
    neg rax
    push rax
    call __errno_location wrt ..plt ; wrt ..plt specifie l utilisation de plt (sinon on trouve pas errno..)
    pop rdx
    mov [rax], rdx
    mov rax, -1
    ret
