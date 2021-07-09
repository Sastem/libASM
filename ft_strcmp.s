section .text
	global _ft_strcmp

_ft_strcmp:
	push rbp
	mov rbp, rsp
	xor rcx, rcx
	jmp loop

loop:
	mov al, BYTE [rdi + rcx]
	cmp al, BYTE[rsi + rcx]
	je char_eq
	jmp return

char_eq:
	cmp al, 0
	je str_eq
	inc rcx
	jmp loop

return:
	mov bl, al
	sub bl, BYTE[rsi + rcx]
	movsx rax, bl
	ret

str_eq:
	mov rax, 0
	ret
