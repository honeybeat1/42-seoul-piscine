/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:48:03 by dachung           #+#    #+#             */
/*   Updated: 2020/01/28 19:28:45 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		size_arr(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	unsigned int d_size;
	unsigned int s_size;
	
	d_size = size_arr(dest);
	s_size = size_arr(src);

	i = 0;

	if (d_size + 1 >= n)
	{
		while ( i < n )
			{
				dest[i] = src[i];
				i++;
			}
		if (s_size >= n && n == d_size +1) 
			{
				i = 0;
				while (i < n)
				{
					dest[i] = src[i];
					i++;
				}
				i = 0;
				while (i > 0)
				{
					dest[n] = dest[i];
				}

			}
	}
	return (dest);
}
