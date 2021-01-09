/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:09:20 by hanguy            #+#    #+#             */
/*   Updated: 2020/04/30 13:09:20 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libasm.h"

int fd, ret;

void first_check_strlen(char *src)
{
	if (strlen(src) == ft_strlen(src))
		printf("\033[48;2;0;250;154m\033[38;2;0;0;0m[OK]\033[0m   ");
	else
		printf("\033[1m\033[48;2;175;135;255m\033[38;2;255;255;255m[KO]\033[0m   ");
	printf("std: %-4ld, asm: %-4ld\n", strlen(src), ft_strlen(src));
}

void second_check_strlen()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(empty));
	printf("%-20s: %zu\n", "libasm", ft_strlen(empty));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(hello_world));
	printf("%-20s: %zu\n", "libasm", ft_strlen(hello_world));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", alphabet);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(alphabet));
	printf("%-20s: %zu\n", "libasm", ft_strlen(alphabet));
	printf("\n");

	//------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char *", alphabet);
	// printf("%-20s: 0\n", "expected lenght");
	// printf("%-20s: %zu\n", "libc", strlen(NULL));
	// printf("%-20s: %zu\n", "libasm", ft_strlen(NULL));
	// printf("\n");
}

void first_check_strcpy(char *src)
{
	char	s1[BUF];
	char	s2[BUF];
	bzero(s1, BUF);
	bzero(s2, BUF);
	strcpy(s1, src);
	ft_strcpy(s2, src);
	if ((strcmp(s1, s2)) == 0)
		printf("\033[48;2;0;250;154m\033[38;2;0;0;0m[OK]\033[0m   ");
	else
		printf("\033[1m\033[48;2;175;135;255m\033[38;2;255;255;255m[KO]\033[0m   ");
	printf("std: |%s|, asm: |%s|\n", s1, s2);
}

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

void second_check_strcpy()
{
	char buffer[30];

	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

	printf("%-20s: \"%s\"\n", "char []", empty);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, empty));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, empty));
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", hello_world);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, hello_world));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, hello_world));
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", alphabet);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, alphabet));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, alphabet));
	clear_buffer(buffer, 30);
	printf("\n");

	//------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char []", alphabet);
	// printf("%-20s: buffer[50]\n", "copy to");
	// printf("%-20s: \"%s\"\n", "libc", strcpy(NULL, NULL));
	// clear_buffer(buffer, 30);
	// printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(NULL, NULL));
	// clear_buffer(buffer, 30);
	// printf("\n");
}

void first_check_strcmp(char *s1, char *s2)
{
	if ((strcmp(s1, s2) == ft_strcmp(s1, s2)) || (strcmp(s1, s2) < 0 && ft_strcmp(s1, s2) < 0) || (strcmp(s1, s2) > 0 && ft_strcmp(s1, s2) > 0))
		printf("\033[48;2;0;250;154m\033[38;2;0;0;0m[OK]\033[0m   ");
	else
		printf("\033[1m\033[48;2;175;135;255m\033[38;2;255;255;255m[KO]\033[0m   ");
	printf("std: |%d|, asm: |%d|\n", strcmp(s1, s2), ft_strcmp(s1, s2));
}

void second_check_strcmp()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *hello_human = "Hello human !";
	char *hello_world2 = "Hello world !";

	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_human);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world, hello_human));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world, hello_human));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_world2);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world, hello_world2));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world, hello_world2));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world2);
	printf("%-20s: \"%s\"\n", "compared to", empty);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world2, empty));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world2, empty));
	printf("\n");

	// //------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char *", hello_world2);
	// printf("%-20s: %s\n", "compared to", "NULL");
	// //printf("%-20s: \"%d\"\n", "libc", strcmp(NULL, hello_world2));
	// printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(NULL, empty));
	// // printf("\n");
}

void first_check_write()
{
	int fd;
	char *str = "Hello world\n";

	printf("\033[0;32m\n=== ft_write ===\n\033[0m");

	ft_write(1, str, 12);
	write(1, str, 12);

	ft_write(1, &"", 1);
	ft_write(1, &"\n", 1);
	write(1, &"", 1);
	write(1, &"\n", 1);

	fd = open("write2.txt", O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR);
	ft_write(fd, str, 12);
	write(fd, str, 12);
	close(fd);

	errno = 0;
	ft_write(-1, str, 12);
	printf("errno => %d\n", errno);

	errno = 0;
	write(-1, str, 12);
	printf("errno => %d\n", errno);

	fd = open("write.txt", O_WRONLY);
	ft_write(fd, str, 12);
	write(fd, str, 12);
	close(fd);
}

void second_check_write()
{
	char *str = "Test write";
	char *empty = "";
	//char *str1=strdup("test");
	int errno_tmp;

	printf("\n================================\n");
	printf("========== FT_WRITE ============\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", str);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, str, 7));
	// printf("\n");
	printf("%-20s: \"Libasm:%zd\"\n", "libasm", ft_write(1, str, 7));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, empty, 0));
	// printf("\n");
	printf("%-20s: \"Libasm:%zd\"\n", "libasm", ft_write(1, empty, 0));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", str);
	printf("%-20s: \"Libc:%zd\"\n", "libc", write(-7, NULL, 7));
	// printf("\n");
	printf("%-20s: \"Libasm:%zd\"\n", "libasm", ft_write(-7, NULL, 7));

	fd = open("write.txt", O_CREAT | O_APPEND | O_WRONLY, 0755);
	ft_write(fd, str, strlen(str));
	write(fd, str, strlen(str));
	close(fd);

	errno = 0;
	ret = ft_write(-1, str, strlen(str));
	printf("errno = %d\n", (errno_tmp = errno));

	errno = 0;
	ret = write(-1, str, strlen(str));
	printf("errno = %d\n", errno);
	if (errno_tmp != errno)
	printf("not equal");


	printf("\n");
	printf("error: %zd, %s\n", ft_write(211, str, strlen(str)), strerror(errno));
	printf("error: %zd, %s\n", write(211, str, strlen(str)), strerror(errno));

}

int main()
{
	char longstr[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.";

	printf("\n================================\n");
	printf("========== FT_STRLEN ===========\n");
	printf("================================\n\n");
	printf("-----------------------FIRST----------------------\n\n");
	first_check_strlen("");
	first_check_strlen("Hello, world!");
	first_check_strlen(longstr);
	printf("\n-----------------------SECOND----------------------\n\n");
	second_check_strlen();

	printf("\n================================\n");
	printf("========== FT_STRCPY ===========\n");
	printf("================================\n\n");
	printf("-----------------------FIRST----------------------\n\n");
	first_check_strcpy("Hello");
	first_check_strcpy("Hello world; test1; test2; test3; test4; test5");
	first_check_strcpy("");
	first_check_strcpy("lolkek");
	first_check_strcpy(longstr);
	printf("\n-----------------------SECOND----------------------\n\n");
	second_check_strcpy();

	printf("\n================================\n");
	printf("========== FT_STRCMP ===========\n");
	printf("================================\n\n");
	printf("-----------------------FIRST----------------------\n\n");
	first_check_strcmp("Hello", "");
	first_check_strcmp("", "World");
	first_check_strcmp("Hello", "Hel");
	first_check_strcmp("Hel", "Hello");
	first_check_strcmp("", "");
	first_check_strcmp("Hello", "Hello");
	first_check_strcmp(longstr, longstr);
	first_check_strcmp(" ", "");
	first_check_strcmp("Helloo", "Hello");
	first_check_strcmp("", " ");
	first_check_strcmp("Hello", "Helloo");
	printf("\n-----------------------SECOND----------------------\n\n");
	second_check_strcmp();

	printf("\n================================\n");
	printf("========== FT_WRITE ============\n");
	printf("================================\n\n");
	printf("-----------------------FIRST----------------------\n\n");
	first_check_write();
	printf("\n-----------------------SECOND----------------------\n\n");
	second_check_write();
}
