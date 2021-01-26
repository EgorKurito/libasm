section .text
	global	_ft_strcpy 				; dst = rdi, src = rsi

_ft_strcpy:
	mov	rcx, 0
	mov rbx, 0

while:
	mov bl, byte [rsi + rcx] 		; bl = rsi[rcx]
	mov byte [rdi + rcx], bl 		; rdi[rcx] = bl
	inc rcx
	cmp bl, 0
	je	end
	jmp while

end:
	mov rax, rdi
	ret
