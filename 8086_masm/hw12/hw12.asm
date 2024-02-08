.model small, StdCall
.STACK 100h

.DATA
; --------------------------
; Variables 
; --------------------------
num dw 12343
decimal dw 10
hex dw 10h

.CODE
; --------------------------
; Procs 
; --------------------------
is_sorted PROC n:word
    mov ax, n       ; mov number to ax to div
    cmp ax, decimal ; check if divided last digit
    jb sorted

    xor dx, dx
    div decimal     ; divide by decimal to get digit
    mov cx, ax      ; save ax
    mov bx, dx      ; mov digit to another reg
    xor dx, dx
    div decimal        ; divide again to get digit
    cmp bx, dx      ; check if first digit is smaller then the second
    jb not_sorted   ; if not sorted 
    push cx         ; mov prev ax
    call is_sorted  ; rec call
    jmp exit        ; when rec calls are done exit

sorted:
    mov bx, 1
    jmp exit

not_sorted:
    xor bx, bx

exit:
    ret
is_sorted ENDP

print_signed_number PROC n:word
    mov ax, n
    test ax, 80h        ; test if number is negative
    jnz print_unsigned  ; if number is negative 
    push ax
    call print_number
    jmp exit

print_unsigned:
    push ax

    mov ah, 2h
	mov dl, '-'
	int 21h             ; print minus 

    pop ax
    neg ax              ; get 2's compliment   
    push ax             
    call print_number

exit:
    ret
print_signed_number ENDP

print_number PROC n:word
    mov ax, n
    cmp ax, decimal
    jb print_digit

    xor dx, dx
    div decimal         ; divide by the decimal to get digit
    push ax             ; push whats left of the number
    call print_number   ; rec call

print_digit:
    mov ax, n
    xor dx, dx
    div decimal

    mov ah, 2h
    add dl, '0'
	int 21h             ; print char 

exit:
    ret 
print_number ENDP

print_hex PROC n:word
    mov ax, n
    cmp ax, hex
    jb print_hex_digit

    xor dx, dx
    div hex
    push ax
    call print_hex

print_hex_digit:
    mov ax, n
    xor dx, dx
    div hex

    cmp dx, decimal
    jb is_decimal_digit
    add dl, 55
    jmp actually_print_hex_digit
is_decimal_digit:
    add dl, '0'

actually_print_hex_digit:
    mov ah, 2h
    int 21h

exit:
    ret
print_hex ENDP

start:
	mov ax, @DATA
	mov ds, ax
    mov es, ax
; --------------------------
; Code
; --------------------------

exit:
	mov ax, 4c00h
	int 21h
END start
