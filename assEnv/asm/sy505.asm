assume cs:code

a segment
    db 1,2,3,4,5,6,7,8
a ends

b segment
    db 1,2,3,4,5,6,7,8
b ends

c segment
    db 0,0,0,0,0,0,0,0
c ends

code segment

start:  mov ax,a
        mov ds,ax

        mov bx,b
        mov es,bx

        mov ax,c
        mov ss,ax

        mov bx,0
        mov ax,0
        mov cx,8
        
s:      add ax,ds:[bx]
        add ax,es:[bx]
        mov ss:[bx],ax
        mov ax,0
        add bx,1
        loop s

        mov ax,4c00h
        int 21h

code ends

end start

; 实验5 编写、调试具有多个段的程序
; 编写 code 段中的代码，将 a 段和 b 段中的数据依次相加，将结果存到 c 段中