assume cs:codesg

codesg segment

        mov ax,0123H
        mov bx,0456H
        add ax,bx
        add ax,ax

        mov ax,4c00H
        int 21H

codesg ends

end


#primary .main-content ul:not(.numbat-slider) li:not(.rotate45), 
#primary .main-content ul li:not(.rotate45),
#primary .main-content ul li:not(.rev_slider li) {
    margin-left: 0;
}

.woo-variation-swatches.wvs-show-label .variations td {
    text-align: left;
}


