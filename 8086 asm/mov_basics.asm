; Addressing Modes:   
;
; Immidiate Addresing [fastest]
;   mov [register], [8/16 bit constant value]
;
;   The value is part of the instruction:
;   mov al, 10h     B010
;   cx, 0FFh        B1091
;
; Register Addresing [fast]
;   mov ax, bx
;        
; Direct Addresing 
;   mov ax, [ds:100]
;
;   mov ax, [ds:0004]   A10400    
;   mov ax, var         A10100    
;
; Register indirect Addressing [slow]
;   mov ax, [si] 
;
; Register relative indirect addressing [slow]
;   mov al, vars[di]                   
;
; Register offset indirect Addressing [slow]
;   mov vars[si+bx], cx       
;
; it is recommended that you access memory only with BP, BX, DI and SI.
; also, its recommended that you wont mov data into address registers.
;
; ptr operator can define a size.                         
                       
.STACK 100h
.DATA 
; --------------------------
; Your variables here
; --------------------------

.CODE

start:
	mov ax, DATA
	mov ds, ax       
; --------------------------
; Your code here
; -------------------------- 
    mov ax, 0AABBh
    mov [1], ax              
                  
exit:
	mov ax, 4c00h
	int 21h
END start  
