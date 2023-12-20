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
    mov al, 3
	shl al, 2
                  
exit:
	mov ax, 4c00h
	int 21h
END start  
