
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt


include 'emu8086.inc'
org 100h

num1 DW 0;
num2 DW 0;
 
  
LEA    SI, msg1       
CALL   print_string  
CALL   scan_num 
MOV AX, CX
PRINTN

LEA    SI, msg2       
CALL   print_string   
CALL   scan_num 
MOV BX, CX 
PRINTN
            
CMP AX, 3 
JL if
CMP BX, 2
JL if
JMP else     



if:
    MOV CX, 1
    JMP endif
   
else:    
    MOV CX, 0
    JMP endif
    
endif:
    MOV AX, CX  
    CALL pthis
    DB 'The number in CX: ', 0
    CALL print_num
    PRINTN 
    
ret

msg1 DB 'Enter the first number: ', 0
msg2 DB 'Enter the second number: ', 0 

DEFINE_SCAN_NUM
DEFINE_PRINT_STRING
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS  
DEFINE_PTHIS
                      
end