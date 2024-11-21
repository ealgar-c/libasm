global _ft_strcmp

_ft_strcmp:
	xor rcx, rcx
	xor r8, r8
	xor rax, rax

loop:
	movzx rax, BYTE[rdi + rcx]
	movzx r8, BYTE[rsi + rcx]
	cmp rax, 0
	cmp r8, 0
	jz end
	cmp rax, r8
	jne end
	inc rcx
	jmp loop

end:
	sub rax, r8
	ret