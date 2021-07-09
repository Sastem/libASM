section .text
	global _ft_strcpy

_ft_strcpy:
	push rbp
	mov rbp, rsp
	xor rcx, rcx
	jmp loop

loop:
	cmp BYTE[rsi + rcx], 0
	je exit
	mov al, BYTE[rsi + rcx]
	mov BYTE[rdi + rcx], al
	inc rcx
	jmp loop

exit:
	mov BYTE[rdi + rcx], 0
	mov rax, rdi
	leave
	ret
