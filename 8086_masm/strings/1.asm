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

.DATA
; --------------------------
; Variables 
; --------------------------
strbla1 db "blablabla1$"
lenbla1 db $ - strbla1

strbla2 db "blabala2$"
lenbla2 db $ - strbla2

strbla3 db "blablabla2$"
lenbla3 db $ - strbla3

result db ?

tbl db "zxcvbnmasdfghjklqwertyuiop"
txt db "sfctvzuxyf"

.CODE
; --------------------------
; Procs 
; --------------------------
cmpstr PROC str1:word, len1:word, str2:word, len2:word
    xor dx, dx
    mov cx, len1    ; get length of first num
    cmp cx, len2    ; cmp length
    jne done

    mov si, str1    ; get first string
    mov di, str2    ; get sec string 
    repe cmpsb      ; cmp [si] and [di] until cx=0 or not equal 
    jne done      ; zf=0 means not equal
    inc dx          ; set dx to true
    jmp done        ; done

done:
    ret
cmpstr ENDP  

strchr PROC src:word, len:word, chr:byte
    mov result, 0
    mov al, chr
    mov cx, len
    mov di, src

cmp_chr:
    repne scasb
    jnz exit
    inc result
    jmp cmp_chr

exit:
    ret
strchr ENDP 

xlatstr PROC
    mov bx, offset tbl
       
xlatstr ENDP

start:
	mov ax, @DATA
	mov ds, ax
    mov es, ax
; --------------------------
; Code
; --------------------------
    mov ax, 'a'
    push ax

    xor ax, ax
    mov al, lenbla1 
    push ax
    
    mov ax, offset strbla1 
	push ax
    call strchr

exit:
	mov ax, 4c00h
	int 21h
END start
