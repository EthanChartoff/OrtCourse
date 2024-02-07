.STACK 100h
.DATA 
; --------------------------
; Your variables here
; --------------------------
;Q1 vars
arr1 db 17 DUP(?)
len1 equ 17
        
;Q2 vars
arr21 db 10, 8, 4, 5      
arr22 db 80h, 0A2h, 94h, 0C8h
sum dw 0
isum dw 0                      
                      
;Q3 vars
arr3 db 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 

;Q4 vars
arr4 dw 7999h, 8000h, 8001h, 8002h
quotient db 4 DUP(?)
remainder db 4 DUP(?)
tenw dw 10 

.CODE         

;   Q1
Q1:       
    mov cx, len1    
loop1:
    mov di, cx
    mov arr1[di], cl
    loop loop1
    
    ret  
    
;   Q2
Q2:
    mov cx, 4
    mov di, 4
    xor ax, ax
loop2:
    ; mov index into di    
    dec di     
    ; mul arrs and add them to sum
    mov al, arr21[di]
    mul arr22[di]
    add sum, ax   
    ; init ax
    xor ax, ax
    ; imul arrs and add them to isum
    mov al, arr21[di]
    imul arr22[di]
    add isum, ax
    ; loop until muled all elements
    loop loop2
    
    ret

;   Q3   
Q3:
    xor ax, ax
    xor bx, bx
    xor cx, cx
start_loop3:
    ; test if index is odd/even
    test bx, 1
    jz sum_even
; if index is odd, go here
    add cl, arr3[bx]            
    jmp end_loop3         
; if index is even, go here    
sum_even:
    add al, arr3[bx]
    
; loop back until at end of arr3
end_loop3:    
    inc bx
    cmp bx, 10
    jne start_loop3
          
    ret   
    
;   Q4
Q4:
    mov cx, 4
    mov di, 0
    xor bx, bx
loop4:
    neg arr4[di]
    mov ax, arr4[di]
    div tenw     
    
    ; cant put all of ax and dx into arrs because they are bytes and not words
    mov quotient[bx], al
    mov remainder[bx], dl
    
    inc bx   
    inc di
    inc di
    loop loop4

    ret
      
start:
	mov ax, DATA
	mov ds, ax
; --------------------------
; Your code here
; -------------------------- 
    call Q4         
    
exit:
	mov ax, 4c00h
	int 21h
END start




