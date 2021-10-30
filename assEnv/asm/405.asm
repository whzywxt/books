assume cs:codesg

codesg segment

    ; MOV   AX,7452H
    ; ADD   AL,AH
    ; DAA
    ; XCHG  AH,AL
    ; SUB   AL,AH
    ; DAS

    ;;题
    ; mov dx,0A476H
    ; mov cx,0302H
    ; OR   DX,DX
    ; RCR  DX,CL
    ; XCHG CH,CL
    ; RCL  DX,CL

    ;;题
    ; mov ax,10
    ; shl ax,1
    ; shl ax,1
    ; mov bx,ax
    ; mov cl,2
    ; shl ax,cl
    ; add ax,bx

    ;;题
    MOV  AX,0FF60H
    MOV  DX,96
    XOR  DH,0FFH
    SBB  AX,DX

    mov ax,4c00h
    int 21h

codesg ends

end
