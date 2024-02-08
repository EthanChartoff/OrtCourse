.model small, StdCall
.STACK 100h

; --------------------------
; Constants
; -------------------------
; Q4
MAX_SENTENCE_LEN equ 100

.DATA
; --------------------------
; Variables 
; --------------------------
;Q1
msg db "esrever ni gnirts"
len dw $-msg

; Q2
first db "Ziggy played guitar, jamming good with Wierd and Gilly"
len_first dw $-first
second db 57 dup(?)  

; Q3
LTD_msg db "LTD Guitars and Basses, el al is a LTD company, LTDLT"
LTD_len dw $-LTD_msg
PLC db "PLC"

; Q4
A db MAX_SENTENCE_LEN, (MAX_SENTENCE_LEN + 1) dup(?)
B db MAX_SENTENCE_LEN dup(?)

.CODE
; --------------------------
; Procs 
; --------------------------
print_reverse PROC src:word, len_src:word
    std                 ; set the direction flag 
    mov cx, len_src     
    mov si, src         
    add si, cx         
    dec si              ; mov si to the end of the string

print_char:
    lodsb               ; load the char 
    mov dx, ax          ; mov the char so program can print it
    mov ah, 2h
    int 21h             ; print char
    loop print_char     ; loop until start of string

exit:
    ret
print_reverse ENDP 

load_reverse PROC src:word, dest:word, len_src:word
    mov cx, len_src     
    mov si, src
    add si, cx
    dec si              ; mov si to the end of the string
    mov di, dest        ; mov di to the dest position

print_char:
    std                 ; set direction flag, so when loading si will dec
    lodsb               ; load char to ax
    cld                 ; clear df, so when storing char di will inc
    stosb               ; store char in dest string
    loop print_char     ; loop until the src is copied to the dest backwards 

exit:
    ret
load_reverse ENDP

replace_LTD_PLC PROC src:word, len_src:word
    mov cx, len_src     
    mov di, src

detect_L:
    cld             ; clear df
    mov al, 'L'     ; mov to al 'L'
    repne scasb     ; rep until found 'L'
    jnz exit        ; exit if at end of string

detect_T:
    mov al, 'T'         
    scasb           ; check if next char is T
    je detect_D     ; if it is, detect next char after this
    
    dec di          ; if its not, dec di to its original point and rep from there 
    jmp detect_L    

detect_D:
    mov al, 'D'     
    scasb           ; check if next next char is D          
    je replace_LTD  ; if it is, replace LTD with PLC
          
    dec di          ; go to prev char
    jmp detect_L   

replace_LTD:
    push cx             ; store cx
    mov cx, 3           ; len of PLC
    dec di              ; go to prec char 
    lea si, PLC + 2     ; get plc 
replace_char:
    std                 ; set df 

    lodsb               ; load PLC
    stosb               ; store PLC
    loop replace_char   ; loop until replaced

    pop cx              ; get original cx back
    inc cx
    jmp detect_L        ; detect if thers more LTD

exit:
    ret
replace_LTD_PLC ENDP


find_max_word PROC
    lea dx, A
	mov ah, 0Ah
	int 21h             ; get sentence

    mov cl, [A+1]       ; get len of sentence
    lea di, A + 2       ; load address of senetenec to di 
    xor bx, bx          ; bx will be used as max
    xor dx, dx          ; dx will be used as curr word len counter
    xor ax, ax
    mov al, ' '

find_word:
    inc dx              ; inc dx to every char
    scasb               ; cmp [di] to ' '
    loopne find_word    ; loop until equal to ' '

    dec dx              ; dec dex bcs space was found
    cmp dx, bx          ; cmp curr word length and max word length
    jna check_cx        ; if not above, find another word

    mov bx, dx          ; mov curr word length to max word length
    mov dx, di          ; mov into dx the space of the max word
    sub dx, bx          ; sub space index by the length of the max word to get the index of the first word
    dec dx
    mov B, dl           ; store the index in B

check_cx:
    xor dx, dx
    or cx, cx           ; check if at end of string
    jz max_word_found   
    jmp find_word

max_word_found:
    mov cx, bx          ; mov max word length to bx
    mov al, B
    mov si, ax          ; mov max word index to si to load 
    lea di, B           ; load address of B into di to store char there

copy_max_word:
    lodsb
    stosb
    loop copy_max_word

exit:
    ret
find_max_word ENDP

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
