
.STACK 100h
.DATA 
; --------------------------
; Your variables here
; --------------------------
    msg db 13,10,'Hello, World !',13,10,24h       
    Mem1 	db 8 DUP (0AAh)
    Mem2	db 8 DUP (0BBh)
    Mem3 	db 8 DUP (0CCh)


.CODE

start:
	mov ax, DATA
	mov ds, ax
	nop
; --------------------------
; Your code here
; -------------------------- 
    mov ah, 9
    mov dx, offset msg
    int 21h
    
exit:
	mov ax, 4c00h
	int 21h
END start






