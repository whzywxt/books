assume cs:codesg,ds:DATA_SEG

DATA_SEG SEGMENT
    DA1 DB 34H,12H,45H,23H
    DA2 DW 2211H,'YX'
    BUF DB 2 DUP(66H,55H), 3 DUP(78H)
DATA_SEG ENDS


codesg segment

start:  mov ax,DATA_SEG
        mov ds,ax

        mov ax,4c00h
        int 21h

codesg ends

end start
