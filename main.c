#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

size_t	ft_read(int fd, char *buff, size_t len);
size_t	ft_write(int fd, char *str, size_t len);
size_t	ft_strlen(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);

void	clear_buff(char *buff, int len)
{
	int i = -1;

	while (++i < len )
		buff[i] = 0;
}

int		main(int ac, char **av)
{
	char	buff[300];
	char	cpy1[90];
	char	*str2 = "coucou lala. la tete, les fesses et la moula";
	char	*empty = "";
	char	*str = "coucou";
	char	*str1 = "coucou";
	char	*str3 = "elle a tout elle a tout ca t'fait des chatouilles partout guiliguili";
	char	*dup1;
	char	*dup2;
	size_t	len = ft_strlen(str);
	size_t	ret;
	size_t	ret2;
	size_t	ret3;
	int fd = open("main.c", O_RDONLY);
	int fd2 = open("test.c", O_RDONLY);

	printf("TEST FT_STRLEN\n");
	printf("-----------------\n");
	printf("ft_strlen = %zu\n", len);

	printf("TEST FT_WRITE\n");
	printf("-----------------\n");
	write (1, "ft_write: ", strlen("ft_write: "));
	ft_write(1, str, len);
	ft_write(1, "\n", 1);
	write (1, "write: ", strlen("write: "));
	write(1, str, len);
	write(1, "\n", 1);

	printf("TEST FT_STRCMP\n");
	printf("-----------------\n");
	printf("ft_strcmp: %d\n", ft_strcmp(str, str1));
	printf("strcmp: %d\n", strcmp(str, str1));
	printf("ft_strcmp: %d\n", ft_strcmp(str, str3));
	printf("strcmp: %d\n", strcmp(str, str3));
	printf("ft_strcmp: %d\n", ft_strcmp(str, empty));
	printf("strcmp: %d\n", strcmp(str, empty));
	printf("\n");

	printf("TEST FT_STRCPY\n");
	printf("-----------------\n");
	printf("ft_strcpy: %s\n", ft_strcpy(cpy1, str2));
	printf("ft_strcpy_len = %zu\n", ft_strlen(ft_strcpy(cpy1, str2)));
	clear_buff(cpy1, 90);
	printf("strcpy: %s\n", strcpy(cpy1, str2));
	printf("strcpy_len = %zu\n", ft_strlen(strcpy(cpy1, str2)));
	clear_buff(cpy1, 90);
	printf("ft_strcpy: %s\n", ft_strcpy(cpy1, str3));
	printf("ft_strcpy_len = %zu\n", ft_strlen(ft_strcpy(cpy1, str3)));
	clear_buff(cpy1, 90);
	printf("strcpy: %s\n", strcpy(cpy1, str3));
	printf("strcpy_len = %zu\n", ft_strlen(strcpy(cpy1, str3)));
	clear_buff(cpy1, 90);
	printf("\n");

	printf("TEST FT_STRDUP\n");
	printf("-----------------\n");
	dup1 = ft_strdup(str);
	printf("ft_strdup: %s\n", dup1);
	printf("ft_strdup_len = %zu\n", ft_strlen(dup1));
	free (dup1);
	dup1= NULL;
	dup2 = strdup(str);
	printf("strdup: %s\n", dup2);
	printf("strdup_len = %zu\n", ft_strlen(dup2));
	free (dup2);
	dup2 = NULL;
	printf("\n");

	printf("TEST FT_READ\n");
	printf("-----------------\n");
	ret = ft_read(fd, buff, 299);
	buff[ret] = '\0';
	printf("ft_read: ret = %zu\nbuff = %s\n", ret, buff);
	close (fd);
	clear_buff(buff, 299);
	printf("\n");

	fd = open("main.c", O_RDONLY);
	ret = read(fd, buff, 299);
	buff[ret] = '\0';
	printf("vrai read: ret = %zu\nbuff = %s\n", ret, buff);
	clear_buff(buff, 299);
	printf("\n");
	close (fd);
	ret2 = ft_read(fd2, buff, 299);
	buff[ret] = '\0';
	printf("error ft_read: ret = %zu\nbuff = %s\n", ret2, buff);
	close (fd2);
	clear_buff(buff, 299);
	printf("\n");
	ret3 = read(fd2, buff, 299);
	buff[ret] = '\0';
	printf("error vrai read: ret = %zu\nbuff = %s\n", ret3, buff);
	close (fd2);
	clear_buff(buff, 299);
	printf("\n");
	printf("test stdin \n");
	ret = ft_read(1, buff, 299);
	buff[ret] = '\0';
	printf("ret = %zu\nbuff = %s\n", ret, buff);
	clear_buff(buff, 299);
	return (1);
}
