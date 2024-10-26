#include <stdio.h>

int			ft_strlen(char *str);
char		*ft_strcpy(char *dst, char *src);
int			ft_strcmp(char *s1, char *s2);
ssize_t		ft_write(unsigned int fd, const char *str, size_t len);
//ssize_t		ft_read(int fd, void *buf, size_t nbyte);
//char		*ft_strdup(const char *s);

int main(void){
	printf("Len is: %i\n", ft_strlen("testing"));
	ft_write(1, "test\n", 5);
	return 0;
}
