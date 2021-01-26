section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc

_ft_strdup:
	push rdi         		; save rdi (*s1)
	call _ft_strlen  		; rdi is still == str
	inc  rax          		; += 1 for '\0'

	mov  rdi, rax     		; malloc get num of bytes in rdi
	call _malloc			; rax = (void *)malloc return
	cmp  rax, 0
	je   _err

	pop  rsi          		; original str as src
	mov  rdi, rax     		; allocated as dest
	call _ft_strcpy			; it will copy rsi to rdi and mov rdi to rax
	ret
_err:
	pop  rdi
	ret
