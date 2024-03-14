.model small
.STACK 100h
.DATA
; --------------------------
; Your variables here
; -------------------------
A db 'AbcDefG'
B db 7 dup(' $')
N db 7
	
.CODE

; --------------------------
; Procs here
; --------------------------

start:
	mov ax, @DATA
	mov ds, ax
; --------------------------
; Your code here
; --------------------------
	mov es,ax
	cld
	mov cl,N
	xor ch,ch
	mov si,offset A
	mov di,si
	add di,cx
next:
	lodsb
	test al,32
	loopne next
	jnz sof
	push si
sof:

exit:
	mov ax, 4c00h
	int 21h
END start
