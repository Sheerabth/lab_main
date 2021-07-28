
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov DX, 10101;
mov CX ,0;

JMP Start;

Increment:
    INC CX;

Start:
    SHR DX, 1;
    JC Increment;
    CMP DX, 0;
    JG Start;

ret




