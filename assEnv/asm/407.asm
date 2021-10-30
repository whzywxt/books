ASSUME DS:DATA, CS:CODE

DATA SEGMENT
    BUF1 DW -56,24,54,-1,89,-8,-10,-9,9,45 
    BUF2 DW 45,-23,124,345,-265,-985,90,34,222,10 
    SUM DW 10 DUP(0) 
DATA ENDS

CODE SEGMENT

START: MOV AX, DATA
       MOV DS, AX
       MOV SI, 0
       MOV CX, 10
LOP:   MOV AX, BUF1[SI]
       CMP AX, 0
       JGE N1
       NEG AX
N1:    MOV BX, BUF2[SI]
       CMP BX, 0
       JGE N2
       NEG BX
N2:    ADD AX, BX
       MOV SUM[SI], AX
       INC SI
       LOOP LOP
        
       MOV AH, 0
       INT 21H
CODE  ENDS
END  START