
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov [500h], -5
mov [501h], -4
mov [502h], -3
mov [503h], -2
mov [504h], -1
mov [505h], 11
mov [506h], 12
mov [507h], 13
mov [508h], 14
mov [509h], 15

mov si ,500H
mov bp ,600H 
mov bx ,700H 
mov ax ,10
mov dl, 0
add ax, si

  
CONTROL:
   mov dh,[si]  
   cmp dh,0
   JG ARRPOS
   JL ARRNEG
   inc DL
   next:
   inc si
   CMP SI,AX
   JL CONTROL
   JMP REST 
    
ARRPOS:
    mov [bp],dh
    inc bp
    jmp next
    
ARRNEG:
    mov [bx],dh
    inc bx
    jmp next

    
REST:
    
ret




