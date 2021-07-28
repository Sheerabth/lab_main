
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV BX, 7000

MOV AX, 0

Prog:
    MOV DX, [BX]
    SHR DX, 1
    JNC Increment
    INC BX
    CMP BX, 8000
    JLE Prog
    JMP End   

Increment:
    INC AX
    INC BX
    CMP BX, 8000
    JLE Prog
    
End:    

ret




