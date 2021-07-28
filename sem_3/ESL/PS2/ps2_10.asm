
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov [500h], 14
mov [501h], 13
mov [502h], 12
mov [503h], 11
mov [504h], 10

mov dx, 5
mov cx, 0
mov si, 500h
mov ax, 0
mov bx, [504h]

for_loop:
    cmp ax, [si]
    jl change_ax
    cmp bx, [si]
    jg change_bx
    inc si
    cmp si, 505h
    jl for_loop
    jmp end
    
change_ax:
    mov ax, [si]
    inc si
    cmp si, 505h
    jl for_loop
    jmp end
   
change_bx:
    mov bx, [si]
    inc si
    cmp si, 505h
    jl for_loop
    jmp end
           
end:

ret




