section .text

global _ft_strcmp				; str1 = rdi, str2 = rsi

_ft_strcmp:
	mov rax, 0
	mov rbx, 0
	mov rcx, 0
	jmp compare

compare:
	mov al, byte [rdi + rcx]	; al: low 8 bits in rax
	mov bl, byte [rsi + rcx]	; bl: low 8 bits in rbx
	cmp al, bl
	jne dif
	je	equal

dif:
	sub rax, rbx				; rax - rbx (rdi's char - rsi's char)
	ret

equal:
	cmp al, 0 					; if '\0'
	je 	end						; if not null
	inc rcx
	jmp compare

end:
	mov rax, 0
	ret
