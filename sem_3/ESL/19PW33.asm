
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
LEA SI, STR1          ;LOADING STRINGS
LEA DI, STR2         
MOV DX, LEN1          ;STORING LENGT
MOV CX, LEN2         
DEC DX;
DEC CX;
CMP CX, DX;         
JA ENDPROG;            
JE SAMELENGTH       
JB FINDSTRING                              

SAMELENGTH:
        CLD                
        REPE CMPSB     ;directly compare the strings    
        JNE NOTFOUND
        JMP FOUNDSTRING

FINDSTRING:        
        MOV AL, [SI]   ;storing ascii value of charachter of superstring 
        MOV AH, [DI]    
        CMP AL,AH      ;check if charachter is same or not 
        JE CHECK       ;jmp if they are equal 
        JNE ENDIF

ENDIF:
        INC SI          
        DEC DX          
        CMP DX, 0000H  ;dx is the counter  
        JE NOTFOUND    ;checking if charachters are left 
        JMP FINDSTRING 

CHECK:
        MOV CX, LEN2;    
        MOV SP, SI;    
        INC SP
        CLD
        REPE CMPSB
        JNE NEXT
        JMP FOUNDSTRING

NEXT:             
        MOV SI,SP       
        DEC DX
        LEA DI, STR2    
        JMP FINDSTRING                 

FOUNDSTRING:  
        MOV AL, 1H   ;substring found
        JMP ENDPROG


NOTFOUND:    
        MOV AL, 0H   ;substring not found
        JMP ENDPROG

ENDPROG:         

HLT    
RET

STR1 DB 'super strin',0
LEN1 DW ($-STR1)    ;storing the length of STR1
STR2 DB 'string',0
LEN2 DW ($-STR2)    ;stroing the length of STR2
    
END