.model small, StdCall
.STACK 100h

; --------------------------
; Macros
; -------------------------

; --------------------------
; Constants
; -------------------------

.DATA
; --------------------------
; Variables 
; --------------------------
;Q1
msg db "esrever ni gnirts"

.CODE
; --------------------------
; Procs 
; --------------------------
print_reverse PROC
print_reverse ENDP

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
