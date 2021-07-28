
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt


include emu8086.inc
org 100h      

LEA SI, msg 
MOV DX, 100
CALL print_string
CALL get_string
MOV BL, [DI]
printn

CMP [password], BL
JNE endprog  
print 'OK'


endprog: 
hlt
ret

msg db 'Enter the string: ', 0
password db 'somepassword', 0
  
   
DEFINE_GET_STRING   
DEFINE_PRINT_STRING
   
end




