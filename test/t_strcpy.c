#include <stdio.h>
#include <string.h>

void	t_strcpy(char *dest, char *src)
{
	while ((*(src++) = *(dest++)))
		;
}

int	main(void)
{
	char src[] = "hello";
	char dest[13];
	char dest_1[13];
	t_strcpy(dest, src);
	printf("%s\n", dest);
	printf("%s\n", strcpy(dest_1, src));
	return (0);
}
