global _ft_strcmp

_ft_strcmp:
	xor rcx, rcx
	xor rbx, rbx
	xor rax, rax

loop:
	movzx rax, BYTE[rdi + rcx]
	movzx rbx, BYTE[rsi + rcx]
	cmp rax, 0
	cmp rbx, 0
	jz end
	cmp rax, rbx
	jne end
	inc rcx
	jmp loop

end:
	sub rax, rbx
	ret