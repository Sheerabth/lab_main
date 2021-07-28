
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov [500h], 10
mov [501h], 11
mov [502h], 12
mov [503h], 13
mov [504h], 14

mov ax, 5
mov cx, 0
mov si, 500h
mov di, 700h

same_order:
    mov dl, [si]
    mov [di], dl
    inc si
    inc di
    inc cx
    cmp cx, ax
    jl same_order

ret




