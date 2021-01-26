section .text
	global _ft_read 	; fildes = rdi, buf = rsi, nbyte = rdx
	extern ___error

_ft_read:
	mov rax, 0x2000003	; read instruction
	syscall 			; syscall's return in rax
	jc _err 			; if err => carry flag = 1, rax = err_num
	ret

_err:
	push rax 			; push err_num in stack
	call ___error 		; return errno
	pop rbx 			; rbx = err_num
	mov [rax], rbx 		; save err_num to errno
	mov rax, -1
	ret
