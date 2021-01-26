/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:09:20 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/26 13:09:20 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define BUF	512

size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
ssize_t			ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t			ft_read(int fildes, void *buf, size_t nbyte);
char			*ft_strdup(const char *src);

#endif
