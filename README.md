# libasm

Write the following functions in x64 assembly (in the Intel syntax):

```C
int		ft_strlen(char const *str);
int		ft_strcmp(char const *s1, char const *s2);
char		*ft_strcpy(char *dst, char const *src);
ssize_t		ft_write(int fd, void const *buf, size_t nbyte);
ssize_t		ft_read(int fd, void *buf, size_t nbyte);
char		*ft_strdup(char const *s1);
```

### How to use it

Using ``make`` will create the ``libasm.a`` binary.

If you want to test:

```
make test

./test.a
```

To include the library in your project, clone the repository in your working tree and compile with the following flags :

```
gcc -L. -lasm file.c
```
