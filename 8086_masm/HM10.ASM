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
lol PROC
	push bp
	mov sp, bp

	mov bl, 1
	mov dl, 10
	mov ax, [bp + 4]
check_mod:
	cmp al, 10
	jb sof
	div dl
	push ah
	call lol

sof:
	cmp al, [bp + 4]
	jb good
	mov bl, 0

good: 
	ret 4

lol ENDP

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
