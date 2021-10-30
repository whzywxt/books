assume cs:codesg

codesg segment

        mov al,9ah
        mov bh,0c2h
        add al,bh

        mov ax,4c00h
        int 21h

codesg ends

end