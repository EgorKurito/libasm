/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.s                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:09:20 by hanguy            #+#    #+#             */
/*   Updated: 2020/04/30 13:09:20 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
