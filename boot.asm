	BITS 16

	mov ax, 0x7c0
	mov ds, ax
	mov ax, 0xb87c
	mov es, ax

	xor ax, ax
	int 0x16 
	mov cl, al 

	xor bx, bx
	mov si, msg

xoor:
	xor [si], cx
	cmp byte [si], 0x0a
	je next
	inc si
	jmp xoor 

next:
	xor cx, cx 
	mov [si], cx 
	mov ax, 3
	int 0x10 

	xor di, di
	mov si, msg
	mov ah, 0x5f

write:
	lodsb			;copy 1 byte from DS:SI to AL, SI++ 
	test al, al			;set ZF to 1 if cl == 0
	jz end				;jump end if ZF == 1 
	stosw			;save AX at address ES:DI (to 0xb800)
	jmp write 		

end: 
	jmp $

msg:
	dd 0xFFFF 
	times 510-($-$$) db 0
	dw 0xaa55
