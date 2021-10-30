assume cs:codesg,ds:DATA_SEG

DATA_SEG SEGMENT
    A     DB  5
    BUF   DB 20 DUP(0)
    VAR  DW 5612H, 0A78H
    MSG  DB 'yes'
DATA_SEG ENDS


codesg segment

start:  mov ax,DATA_SEG
        mov ds,ax

        mov ax,4c00h
        int 21h

codesg ends

end start
