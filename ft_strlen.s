section .text
	global	_ft_strlen

_ft_strlen:
	mov	rax, 0
	jmp while

while:
	cmp	BYTE [rdi + rax], 0
	je	end					; end if true
	inc	rax					; i++
	jmp	while				; go to while

end:
	ret
