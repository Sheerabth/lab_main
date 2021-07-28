
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov [1100H], 10;
mov BX, DS:[1100H];
mov CX, DS:[1100H];
mov [1300H], CX;

ret




