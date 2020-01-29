/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:29:39 by dachung           #+#    #+#             */
/*   Updated: 2020/01/29 19:10:41 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[0] == 0)
		return (1);
	while (str[i] != '\0')
	{
		if ((96 < str[i] && str[i] < 123) | (64 < str[i] && str[i] < 91))
			i++;
		else
			return (0);
	}
	return (1);
}
