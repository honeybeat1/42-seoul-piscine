/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:41:04 by dachung           #+#    #+#             */
/*   Updated: 2020/02/07 15:02:58 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*ft_strrev(char *str)
{
	int len;
	int i;

	len = 0;
	while (str[len] != 0)
		len++;
	i = 0;
	while (i < len / 2)
	{
		ft_swap(&str[i], &str[len - 1 - i]);
		i++;	
	}
	return (str);
}
#include <stdio.h>
int		main(void)
{
	char str[] = "abcde";
	printf("%s", ft_strrev(str));
}
