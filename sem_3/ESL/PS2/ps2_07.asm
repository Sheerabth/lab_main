org 100h


MOV AX,1
MOV BX,2
MOV CX,3
MOV DX,4
MOV SI,5
MOV DI,6

JMP START
AX_BX:
    MOV BP, AX
    MOV AX, BX
    MOV BX, BP 
    JMP START
              
BX_CX:
    MOV BP, BX
    MOV BX, CX
    MOV CX, BP
    JMP START
              
CX_DX:
    MOV BP, CX
    MOV CX, DX
    MOV DX, BP
    JMP START
             
DX_SI:
    MOV BP, DX
    MOV DX, SI
    MOV SI, BP
    JMP START
             
SI_DI:
    MOV BP, SI
    MOV SI, DI
    MOV DI, BP
    JMP START
    
START:
    CMP AX,BX
    JL AX_BX
    CMP BX,CX
    JL BX_CX
    CMP CX,DX
    JL CX_DX
    CMP DX,SI
    JL DX_SI
    CMP SI,DI
    JL SI_DI

ret    