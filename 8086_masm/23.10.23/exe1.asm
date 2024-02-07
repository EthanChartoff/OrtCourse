; Author: Ethan Raphael Chartoff
; Purpose: homework number 4 

.STACK 100h
.DATA 
; --------------------------
; Your variables here
; --------------------------
    var1 db 5
                            
.CODE

start:
	mov ax, DATA
	mov ds, ax
; --------------------------
; Your code here
; -------------------------- 
    mov al, var1
    mov ax, 10
    mov bx, 1010b
    mov cx, 0Ah         
                                            
exit:
	mov ax, 4c00h
	int 21h
END start






