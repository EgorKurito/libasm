# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanguy <hanguy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/18 20:15:21 by hanguy            #+#    #+#              #
#    Updated: 2021/01/26 13:05:34 by hanguy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

S_SRCS = ft_strlen.s			\
		ft_strcpy.s			\
		ft_strcmp.s			\
		ft_write.s			\
		ft_read.s			\
		ft_strdup.s

SRCS = $(addprefix src/, $(S_SRCS))

OBJS = $(SRCS:.s=.o)

%.o : %.s
	nasm -f macho64 $<

all : $(NAME)

$(NAME)	: $(OBJS)
	ar rcs $(NAME) $(OBJS)

.PHONY: all clean fclean re test./a

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) test.a write.txt write2.txt

re: fclean all

test:
	gcc -Wall -Wextra -Werror main.c -L. libasm.a -o test.a
