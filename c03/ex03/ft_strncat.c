/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:16:24 by dachung           #+#    #+#             */
/*   Updated: 2020/01/30 16:40:50 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[j] != 0)
		j++;
	while (i < nb)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int     main(void)
{
    char src[] = "hell";
    char dest[8] = {'a','b','c','\0','\0'};
    char dest_1[8] = {'a','b','c','\0','\0'};
    printf("내꺼: %s\n", ft_strncat(dest, src, 4));
    printf("진짜: %s\n",strncat(dest_1, src, 4)); 
    printf("내꺼: %c\n", ft_strncat(dest, src, 4)[6]);
    printf("진짜: %c\n",strncat(dest_1, src, 4)[6]);
   	return (0);
}

