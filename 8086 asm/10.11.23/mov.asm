
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
    
    ; Q3      
    mov al, [40h]             
    mov bl, [30h]
    mov [30h], al 
    mov [40h], bl                
    
    ; Q4
    mov al, [4h]
    mov [12h], al
    mov [13h], al
    
    ;Q5
    mov [10h], 1
    mov al, [10h]
    mov cl, al
    mov ch, al
    mov dl, al
    mov dh, al
    
    
exit:
	mov ax, 4c00h
	int 21h
END start






