/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:25:48 by dachung           #+#    #+#             */
/*   Updated: 2020/02/09 23:39:39 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void ft_putstr(char *dict);
int	ft_find_dict(char *conv, int size);
char *dict[101];
char *value[100];

int		ft_convert(char *num, int len)
{
	char *conv;
	int size;
	int i;
	int j;
	int result;
	
	size = (((len - 1) / 3) + 1) * 3;
	conv = (char *)malloc(sizeof(char) * (size + 1));
	if (conv == 0)
		return (0);
	i = 0;
	j = 0;
	while (i < size - len)
		conv[i++] = '0';
	while (i < size)
		conv[i++] = num[j++];
	conv[i] = '\0';
	result = ft_find_dict(conv, size);
	free(conv); 
	return (result);
}

int		ft_find_dict(char *conv, int size)
{
	int i;
	int j;
	int c;
	int control;

	i = 0;
	j = 1;
	c = 1;
	if (size / 3 > 12)
		return (0);
	while (conv[i] != 0)
		conv[i++] -= 48;
	i = 0;
	control = size;
	while (control > 0)
	{
		if (conv[i] != '\0' && i % 3 == 0)
		{
			ft_putstr(dict[(int)conv[i]]);
			ft_putstr(dict[100]);
		}
		if (conv[i] != '\0' && i % 3 == 1)
		{
			if (conv[i] != 1)
			{
				ft_putstr(dict[conv[i] * 10]);
			}
			else
				ft_putstr(dict[conv[i + 1] + 10]);
				i++;
		}
		if (conv[i] != '\0' && i  % 3 == 2)
			ft_putstr(dict[(int)conv[i]]);
		if (i % 3 == 2 && size > 3 && i > 1 && ((size / 3) > c))
		{
			ft_putstr(value[(size / 3) - c]);
			c++;
		}
		i++;
		control--;
	}
	return (1);
}

void	ft_putstr(char *dict)
{
	int i;

	i = 0;
	while (dict[i] != 0)
	{
		write(1, &dict[i], 1);
		i++;
	}
	write(1, " ", 1);
}

int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	dict[0] = "zero";
	dict[1] = "one";
	dict[2] = "two";
	dict[3] = "three";
	dict[4] = "four";
	dict[5] = "five";
	dict[6] = "six";
	dict[7] = "seven";
	dict[8] = "eight";
	dict[9] = "nine";
	dict[10] = "ten";
	dict[11] = "eleven";
	dict[12] = "twelve";
	dict[13] = "thirteen";
	dict[14] = "fourteen";
	dict[15] = "fifteen";
	dict[16] = "sixteen";
	dict[17] = "seventeen";
	dict[18] = "eighteen";
	dict[19] = "nineteen";
	dict[20] = "twenty";
	dict[30] = "thirty";
	dict[40] = "fourty";
	dict[50] = "fifty";
	dict[60] = "sixty";
	dict[70] = "seventy";
	dict[80] = "eighty";
	dict[90] = "ninety";
	dict[100] = "hundred";
	value[1] = "thousand";
	value[2] = "million";
	value[3] = "billion";
	value[4] = "trillion";
	value[5] = "quadrillion";
	value[6] = "quintillion";
	value[7] = "sextillion";
	value[8] = "septillion";
	value[9] = "octillion";
	value[10] = "nonillion";
	value[11] = "decillion";
	value[12] = "undecillion";
	
	int len_argv;
	int i;

	i = 0;	
	if (argc != 2)
		return (0);
	while (argv[1][i] != 0)
	{
		if (!('0' <= argv[1][i] && argv[1][i] <= '9'))
			return (0);
		i++;
	}
	len_argv = ft_len(argv[1]);
	ft_convert(argv[1], len_argv);
}
