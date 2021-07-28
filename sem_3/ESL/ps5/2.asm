
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

list DW 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16

mov si, list
mov cx, 15

for:
    mov ax, [si + 2]      
    mov [si], ax
    add si, 2
    loop for
        
ret



