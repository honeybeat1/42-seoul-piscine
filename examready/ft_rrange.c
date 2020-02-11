/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:03:33 by dachung           #+#    #+#             */
/*   Updated: 2020/02/07 16:08:39 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_swap(int *start, int *end)
{
	int temp;

	if (*start > *end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
	}
	else
		return ;
}

int		*ft_rrange(int start, int end)
{
	int	*arr;
	int	i;
	int	scope;
	
	ft_swap(&start, &end);
	scope = (end - start) + 1;
	arr = (int *)malloc(sizeof(int) * scope);
	if (arr == '\0')
		return (0);
	i = 0;
	while (i < scope)
	{
		arr[i] = start;
		i++;
		start++;
	}
	arr[i] = '\0';
	return (arr);
}
