global _ft_read
extern ___error					; macOS error handler
extern errno_location			; Linux error handler

%macro set_read_syscall 0
	%ifdef __APPLE__
		mov rax, 0x02000003 	; Syscall number for read on macOS
	%elif __linux__
		mov rax, 0				; Syscall number for read on Linux
	%else
		mov rax, -1				; Invalid syscall
	%endif
%endmacro

%macro handle_error 0
	mov r8, rax
	%ifdef __APPLE__
		call ___error			; Call macOS error handler
	%elif __linux__
		call errno_location		; Call Linux error handler
	%endif
	mov [rax], r8
	mov rax, -1
	ret
%endmacro

_ft_read:
	set_read_syscall
	mov rdi, rdi				; fd
	mov rsi, rsi				; buff
	mov rdx, rdx				; len
	syscall						; Make the syscall
	jc error
	ret

error:
	handle_error
