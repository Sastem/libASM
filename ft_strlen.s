section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp
	xor rcx, rcx
	mov rax, 0
	jmp loop

loop:
	cmp BYTE[rdi + rcx], 0
	je exit
	inc rcx
	jmp loop

exit:
	mov rax, rcx
	leave
	ret
