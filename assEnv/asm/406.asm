assume cs:code,ds:data,ss:stack

data segment
    DA4 DB 0ABH,89H
data ends

stack segment
    DA3 EQU WORD PTR DA4
stack ends

code segment

start:  mov ax,stack
        mov ss,ax
        mov sp,16
        
        mov ax,data
        mov ds,ax

        SHR DA3,1    
        MOV DX,DA3    
        SHL DA4,1    
        MOV CX,DA3

        mov ax,4c00h
        int 21h

code ends

end start
