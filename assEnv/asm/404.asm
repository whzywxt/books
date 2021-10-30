assume cs:codesg,ds:DATA_SEG

DATA_SEG SEGMENT
    ; ORG 30H
    ; VAR1 DB  30H,'0',30H,0,30H
    
    
    ; BUF DB  6 DUP(0)

    DA4 DB 0ABH，89H
    DA3 EQU WORD PTR DA4
DATA_SEG ENDS


codesg segment

; start:  mov ax,DATA_SEG
;         mov ds,ax



; start:  mov ax,DATA_SEG
;         mov ds,ax

;         mov al,'Z'   
;         lea bx,BUF
;         mov cx,5
;         lop: mov byte ptr[bx],al
;              dec al
;              inc bx
;              loop lop



start:  mov ax,DATA_SEG
        mov ds,ax

        SHR DA3,1   
        MOV DX,DA3 
        SHL DA4,1
        MOV CX,DA3

        mov ax,4c00h
        int 21h

codesg ends

end start
