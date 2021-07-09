section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc

_ft_strdup:
	call _ft_strlen
	inc rax
	push rdi
	mov rdi, rax
	call _malloc
	pop rdx
	test rax, rax
	jz null_ret
	push rdi
	mov rdi, rax
	mov rsi, rdx
	call _ft_strcpy
	pop rsi
	ret

null_ret:
	leave
	ret
