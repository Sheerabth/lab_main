
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV BX, 1200H

MOV AL, 0

Prog:
    CMP AL, [BX]
    JMP Increment
    INC BX
    CMP BX, 1250H
    JLE Prog
    JMP End   

Increment:
    INC DX
    INC BX
    CMP BX, 1250H
    JLE Prog
    
End:    
              
ret