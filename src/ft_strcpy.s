global _ft_strcpy

_ft_strcpy:
	xor rcx, rcx
	xor rax, rax
	xor rbx, rbx

loop:
	mov rbx, [rsi + rcx]
	mov [rdi + rcx], rbx
	cmp rbx, 0
	je end
	inc rcx

end:
	mov rax, rdi
	ret