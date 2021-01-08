# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanguy <hanguy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/18 20:15:21 by hanguy            #+#    #+#              #
#    Updated: 2020/10/04 13:05:34 by hanguy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

TEST = test.a

SRCS = 	ft_strlen.s \
		ft_strcpy.s \

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
	rm -rf $(NAME) $(TEST)

re: fclean all

test:
	gcc -Wall -Wextra -Werror main.c -L. libasm.a -o $(TEST)
