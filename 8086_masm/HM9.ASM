.model small
.STACK 100h
.DATA
; --------------------------
; Your variables here
; -------------------------
arr db 200, 100, -3, -80, 80h, -128
arr_len equ $ - arr
swap_flag db ?

str_dec_instructions db "insert dec number no greater then 65,535 $"
str_dec_size db 6
str_dec db 7 dup(?)

col db 39
row db 10
pyr_hight equ 7

.CODE

; --------------------------
; Procs here
; --------------------------
 
bubble_sort:
	xor cx, cx
bs_for1:
	and swap_flag, 0
	xor bx, bx
bs_for2:
	; comparing vars to see if they need to be swapped
	mov al, arr[bx]
	cmp al, arr[bx+1]
	ja bs_swap
	
	; inner loop condition
	inc bx
	cmp bx, arr_len - 1
	jb bs_for2
	
	; check if anything was swapped, if not that measns the arr is soerted
	test swap_flag, 1
	jz bubble_sort_end
	
	; outer loop condition
	inc cx
	cmp cx, arr_len - 1
	jb bs_for1
	
bubble_sort_end:
	ret
	
bs_swap:
	; swap flags
	mov ah, arr[bx+1]
	mov arr[bx], ah
	mov arr[bx+1], al
	
	; indicate the swapped happened
	mov swap_flag, 1
	
	jmp bs_for2
	

str_to_dec:
	; print instructions
	mov dx, offset str_dec_instructions
	mov ah, 9h
	int 21h
	
	; get user input
	mov dx, offset str_dec_size
	mov ah, 0Ah
	int 21h
	
	xor ax, ax
	xor di, di
	inc di

scan_str:
	; check if char is a digit
	cmp str_dec[di], '0'
	jb str_to_dec_exit
	cmp str_dec[di], '9'
	ja str_to_dec_exit
	
	; mul by 10 and add digit
	shl ax, 1
	mov dx, ax
	shl ax, 1
	shl ax, 1
	add ax, dx
	
	add al, str_dec[di]
	sub al, '0'
	
	inc di
	cmp di, word ptr str_dec_size - 1
	jb scan_str

str_to_dec_exit:
	ret


print_pyramid:
	call cls
	xor cx, cx ; row offset
	
move_cursor:
	xor bx, bx
	mov dh, row
	add dh, cl
	mov dl, col
	sub dl, cl 
	mov ah, 2h
	int 10h
	
print_row:
	shl cx, 1
	inc cx
	
	mov dl, '*'
print_star:
	int 21h
	inc bx
	cmp bx, cx
	jne print_star
	
	dec cx
	shr cx, 1
	
	inc cx
	cmp cx, pyr_hight
	jna move_cursor
	
	ret
	
	
cls:
  push ax
  mov ah, 0
  mov al, 3  ; text mode 80x25 16 colours
  int 10h
  pop ax
  ret
	
	
start:
	mov ax, @DATA
	mov ds, ax
; --------------------------
; Your code here
; --------------------------
	call print_pyramid
	

exit:
	mov ax, 4c00h
	int 21h
END start






