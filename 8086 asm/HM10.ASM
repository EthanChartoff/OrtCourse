.model small
.STACK 100h
.DATA
; --------------------------
; Your variables here
; -------------------------
	
.CODE

; --------------------------
; Procs here
; --------------------------
Q1 PROC
	push ax
	push bx
	pop ax
	pop bx 	
	
	ret
Q1 ENDP

; when going into the proc, assume ax already has a value
Q2 PROC
	xor cx, cx
	mov bx, 10
put_dec_on_stk:
	xor dx, dx
	div bx
	push dx
	inc cx
	
	or ax, 0
	jnz put_dec_on_stk
	
	mov ah, 2
print_dec:
	pop dx
	add dl, '0'
	int 21h
	loop print_dec
	
	ret
Q2 ENDP

start:
	mov ax, @DATA
	mov ds, ax
; --------------------------
; Your code here
; --------------------------
	mov ax, 34567
	call Q2
	
exit:
	mov ax, 4c00h
	int 21h
END start
