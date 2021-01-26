section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc

_ft_strdup:
	push rdi         		; save rdi
	call _ft_strlen  		; rdi is still == str
	inc  rax          		; len++ for '\0'

	mov  rdi, rax     		; size to malloc
	call _malloc			; rax = (void *)malloc return
	cmp  rax, 0
	je   _err

	pop  rsi          		; original str as src
	mov  rdi, rax     		; allocated as dest
	call _ft_strcpy
	ret
_err:
	pop  rdi
	ret
