.model small
.STACK 100h
.DATA
; --------------------------
; Your variables here
; -------------------------

; Q2
num dw 0C0FEh
base dw 10

; Q3
avg dw 0
iavg dw 0
nums db 0FEh, 127, 100,64h, 25, 0ACh, 105, 0E0h
len equ $-num

.CODE

Q1:
	; 70 > [3h] > 10
	mov byte ptr ds:[3], 4
	
	cmp byte ptr ds:[3], 10
	jbe exit
	cmp byte ptr ds:[3], 70
	jae exit
	
	mov al, ds:[3]
	mov byte ptr ds:[5h], al
	
	ret

Q2:
	mov ax, num
div_base:
	xor dx, dx
	div base
	push dx
	or ax, ax
	jnz div_base
	
; number is stack
	ret

Q3:
	mov di, len
	xor bx, bx
	xor dx, dx
	xor ax, ax
sum_nums:
	; adc to bx, unsigned
	add bl, nums[di-1]
	adc bh, 0
	; cbw to dx, signed
	mov al, nums[di-1]
	cbw
	add dx, ax
	dec di
	jnz sum_nums
	
	; calc avgs
	mov ax, dx
	xor dx, dx
	idiv bx
	mov iavg, ax
	
	mov ax, bx
	xor dx, dx
	mov bx, 10h
	div bx
	mov avg, ax
	
	ret
	
start:
	mov ax, @DATA
	mov ds, ax
	nop
; --------------------------
; Your code here
; --------------------------
	call Q3
	
exit:
	mov ax, 4ch
	int 21h
END start






