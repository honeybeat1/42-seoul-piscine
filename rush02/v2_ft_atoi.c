/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 21:09:24 by dachung           #+#    #+#             */
/*   Updated: 2020/02/09 12:10:53 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;
	int r;
	int sign;

	i = 0;
	sign = 1;
	r = 0;
	while (str[i] != 0)
	{
		while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
			i++;
		if (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				sign *= -1;
		while ('0' <= str[i] && str[i] <= '9')
		{
			r = r * 10 + str[i++] - '0';
			if (!('0' <= str[i] && str[i] <= '9'))
				return (sign * r);
		}
		return (0);
	}
	return (0);
}
