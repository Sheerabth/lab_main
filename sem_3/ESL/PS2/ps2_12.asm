
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
 
mov ax, 6000h 
mov ds, ax

mov [0000h], 1000h
mov [0200h], 2000h

mov si, 0000h
mov di, 0200h
mov ax, 0

for_loop:
    mov bx, [si]
    add ax, bx
    add si, 2
    cmp si, di
    jle for_loop

ret




