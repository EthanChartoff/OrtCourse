.model small, StdCall
.STACK 500h

.LIST
; -------------------------
; Constants
; -------------------------

.DATA
; --------------------------
; Variables 
; --------------------------
; Series vars
overflow_msg    DB  "number caused overflow", '$'
arrow           DB  "->", '$'

; SeperateWords vars
str1            DB  "GoodLuckInTheTestStudents!"
len1            EQU $-str1
str2            DB  20 DUP('$')

.CODE
; --------------------------
; Procs 
; --------------------------
PrintDecimal PROC n:word
    PUSH    AX
    PUSH    BX
    PUSH    CX
    PUSH    DX

    MOV     AX, n
    MOV     BX, 10
    XOR     CX, CX

push_digits:
    XOR     DX, DX
    INC     CX

    DIV     BX
    PUSH    DX
    OR      AX, AX
    JNZ     push_digits

    MOV     AH, 2
pop_digits:
    POP     DX
    ADD     DL, '0'
    INT     21h
    LOOP    pop_digits

PrintDecimal_exit:
    POP     DX
    POP     CX
    POP     BX
    POP     AX
    RET
PrintDecimal ENDP


Series PROC n:WORD
   ; check if n is 1 
    MOV     AX, n
    CMP     AX, 1
    JZ      print_n

    ; test if n is even or odd, and proceed according to the series rules
    XOR     DX, DX      ; both instances will mul or dec
    TEST    AX, 1
    JZ      is_even

is_odd:
    MOV     BX, 3
    MUL     BX
    OR      DX, DX      ; if dx is not zero that means result is a dword, and series should stop
    JNZ     overflow 
    INC     AX
    JMP     rec_call

is_even:
    MOV     BX, 2
    DIV     BX
    JMP     rec_call

overflow:
    MOV     AH, 9
    LEA     DX, overflow_msg
    INT     21h
    JMP     Series_exit

rec_call:
    PUSH    AX
    CALL    Series

print_n:
    MOV     AX, n
    PUSH    AX
    CALL    PrintDecimal


    MOV     AH, 9
    LEA     DX, arrow
    INT     21h

Series_exit:
    RET
Series ENDP 

SeperateWords PROC strPtr:WORD
    ; init vars
    MOV     DI, strPtr
    INC     DI
    MOV     CX, len1
    DEC     CX
    CLD

scan_string:
    CMP     byte ptr [DI], 'A'
    JB      scan_string_loop    ; char below 'A'
    CMP     byte ptr [DI], 'Z'
    JA      scan_string_loop    ; char above 'Z'

    ; shift string by 1 and add space
    PUSH    DI
    PUSH    CX
    STD

    ADD     DI, CX
    MOV     SI, DI
    DEC     SI
shift_string:
    LODSB
    STOSB

    LOOP shift_string
    MOV     AL, ' '
    STOSB 

    CLD
    POP     CX
    POP     DI
    INC DI                      ; add di shift offset

scan_string_loop:
    INC     DI
    LOOP    scan_string
SeperateWords_exit:
    RET
SeperateWords ENDP

start:
	MOV     AX, @DATA
	MOV     DS, AX
    MOV     ES, AX
; --------------------------
; Code
; --------------------------

exit:
	MOV     AX, 4c00h
	INT     21h
END start
