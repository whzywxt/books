assume cs:code,ds:data,ss:stack

code segment

start:  mov ax,stack
        mov ss,ax
        mov sp,16
        
        mov ax,data
        mov ds,ax

        push ds:[0]
        push ds:[2]
        pop  ds:[2]
        pop  quitds:[0]

        mov ax,4c00h
        int 21h

code ends

data segment
    dw 0135h,0258h
data ends

stack segment
    dw 0,0
stack ends

end start

; 实验5 编写、调试具有多个段的程序
; 将程序编译、连接，用Debug加载、跟踪
; 1,cpu执行程序，程序返回前，data段数据为
; data段数据为 0123h,0456h
; ---
; 2,cpu执行程序，程序返回前，cs=076E，ss=076B，ds=075C 
; debug sy502.exe 使用 r 查看 cs、ss、ds 的值
; ---
; 3,设程序加载后，code段的段地址为 X，则data段的段地址为：X-2，stack段的地址为：X-1
; 4,对于如下定义字段：
;name segment
;...
;name ends
;如果段中的数据占N个字节，则程序加载后，该段实际占有的空间为：N%16==0 ？ N : (N/16 + 1) * 16