.model small, StdCall
.STACK 100h

; --------------------------
; Macros
; -------------------------
print MACRO msg
	push ax
	push dx

	mov ah, 09h
	lea dx, msg
	int 21h

	pop dx
	pop ax
ENDM


printchar MACRO char
	push ax
	push dx

	mov ah, 2h
	mov dl, char
	int 21h

	pop dx
	pop ax
ENDM

println MACRO msg
	push ax
	push dx

	print msg
	printchar 13
	printchar 10

	pop dx
	pop ax
ENDM

.CONST
; --------------------------
; Constants
; -------------------------
; Q1
WORD_INPUT_COUNT equ 8 				; num of numbers to get
MAX_WORD equ 65535					; max val of number (2^16 - 1)
MAX_WORD_LEN equ 5					; max length of number
PRINT_BASE equ 10				

.DATA
; --------------------------
; Variables 
; -------------------------
;Q1
START_MSG db 'This is a program that gets dwords as numbers $'	; start msg		
GET_NUM_MSG db 'Num dword num $' 								; get number msg 
CARRY_MSG db 'Number is too big $'
input_num_arr dw WORD_INPUT_COUNT dup(?)
input_num db MAX_WORD_LEN + 1, (MAX_WORD_LEN + 1) dup(?) 
swap_flag db ?

.CODE
; --------------------------
; Procs 
; --------------------------
get_dw_arr PROC count:word, arr_p:word 
	println START_MSG

	xor di, di
	mov cx, count
	mov si, arr_p
get_numbers:
	print GET_NUM_MSG

	; input string of number and new line
	mov dx, offset input_num
	mov ah, 0ah
	int 21h
	printchar 10

	; convert string to number
	push cx

	lea di, input_num 		; max len
	inc di					; buffer count
	inc di					; first char of buffer
	mov cx, 10          
	xor ax, ax
	xor bx, bx
convert_number:
    mul cx
	jc num_carry
	mov bl, byte ptr [di]
	sub bx, 30h
	add ax, bx
	jc num_carry           
	inc di
	cmp byte ptr [di], 0Dh
	jne convert_number

	pop cx

	; mov converted number to array
	mov [si], ax
	inc si
	inc si
	loop get_numbers

    ret
	
num_carry:
	println CARRY_MSG
	pop cx
	jmp get_numbers

get_dw_arr ENDP

; bubble sort
bubble_sort PROC count:word, arr_p:word 
	mov cx, count
	
bs_for1:
	and swap_flag, 0
	mov si, arr_p
	push cx

bs_for2:
	; comparing vars to see if they need to be swapped
	mov ax, [si]
	cmp ax, [si + 2]
	ja bs_swap
	
	inc si
	inc si

	; inner loop condition
	loop bs_for2
	pop cx
	
	; check if anything was swapped, if not that measns the arr is soerted
	test swap_flag, 1
	jz bubble_sort_end
	
	; outer loop condition
	loop bs_for1
	
bubble_sort_end:
	ret
	
bs_swap:
	; swap flags
	mov dx, [si + 2]
	mov [si], dx
	mov [si + 2], ax
	
	; indicate the swapped happened
	mov swap_flag, 1
	
	jmp bs_for2
bubble_sort ENDP


; print arr
printDecimal PROC count:word, arr_p:word
	mov cx, count
	mov si, arr_p
	mov bx, PRINT_BASE

print_nums:
	push cx
	xor cx, cx
	mov ax, [si]

div_num:
	xor dx, dx
	div bx
	push dx

	inc cx
	or ax, ax
	jnz div_num

print_num:
	pop ax
	add al, '0'
	printchar al
	loop print_num


	printchar ' '
	inc si
	inc si
	pop cx
	loop print_nums


	ret
printDecimal ENDP

fib PROC 
	push bp
	mov bp, sp

	mov cx, [bp + 4]	; get index
	cmp cx, 2			; if fib(<2)
	ja body
	mov ax, 1			; else fib(>=2)
	jmp done

body:
	push bx
	push cx

	sub cx, 2			; handled fib(<2) already
	mov bx, 1			; fib(n-2)
	mov ax, 1			; fib(n-1)

lop:
	xchg ax, bx
	add ax, bx
	loop lop

	pop cx
	pop bx
done:
	pop bp
	ret 2 
fib ENDP


start:
	mov ax, @DATA
	mov ds, ax
; --------------------------
; Code
; --------------------------
	; Q1
		; mov ax, offset input_num_arr
		; push ax
		; mov ax, WORD_INPUT_COUNT
		; push ax

		; call get_dw_arr


		; mov ax, offset input_num_arr
		; push ax
		; mov ax, WORD_INPUT_COUNT
		; push ax

		; call bubble_sort


		; mov ax, offset input_num_arr
		; push ax
		; mov ax, WORD_INPUT_COUNT
		; push ax

		; call printDecimal

		; mov dx, offset input_num
		; mov ah, 0ah
		; int 21h

	mov ax, 9
	push ax
	call fib

exit:
	mov ax, 4c00h
	int 21h
END start
