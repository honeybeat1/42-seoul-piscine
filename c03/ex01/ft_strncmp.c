/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 00:19:08 by dachung           #+#    #+#             */
/*   Updated: 2020/01/30 00:51:46 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				diff;

	i = 0;
	diff = 0;
	while (i < n)
	{
		while ((s1[i] != 0) || (s2[i] != 0))
		{
			if (s1[i] != s2[i])
			{
				diff = s1[i] - s2[i];
				break ;
			}
		}
		if (diff > 0)
			break ;
		else
			i++;
	}
	return (diff);
}
