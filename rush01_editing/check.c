/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochoi <yochoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:47:33 by yochoi            #+#    #+#             */
/*   Updated: 2020/02/02 11:29:10 by yochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_length(char *str);

int		check4(char *pnt)
{
	int c4;

	c4 = 0;
	while (*pnt != '\0')
	{
		if (*pnt == '4')
			c4++;
		pnt++;
	}
	if (c4 > 2)
		return (0);
	return (1);
}

int		is_valid(char x, char y)
{
	int result;

	result = 1;
	if (x == '4' && y != '1')
		result = 0;
	else if (x == '3' && y != '2' && y != '1')
		result = 0;
	else if (x == '2' && y == '4')
		result = 0;
	else if (x == '1' && y == '1')
		result = 0;
	return (result);
}

void	print_error(int error)
{
	if (error == -2)
		write(1, "Error: Wrong number of parameters.", 34);
	else if (error == -1)
		write(1, "Error: There must be only four '1'.", 35);
	else if (error == 0)
		write(1, "Wrong parameters.", 17);
	else if (error == -3)
		write(1, "Error: At most there can only be two '4'.", 41);
	else if (error == -4)
		write(1, "Error: Not solution found", 25);
}

int		arg_validate(char *pnt)
{
	int i;
	int result;

	i = 0;
	result = 1;
	while (i < ft_length(pnt) - 4)
	{
		if (is_valid(pnt[i], pnt[i + 4]) != 1)
		{
			result = 0;
			break ;
		}
		i++;
		if (i == 4)
			i = 8;
	}
	return (result);
}

int		argv_is_valid(char *pnt)
{
	int result;
	int i;
	int count;

	i = 0;
	count = 0;
	result = 1;
	while (pnt[i] != '\0')
	{
		if (pnt[i] < '1' || pnt[i] > '4')
			return (0);
		if (pnt[i] == '1')
			count++;
		i++;
	}
	if (count != 4)
		return (-1);
	if (i != 16)
		return (-2);
	if (check4(pnt) == 0)
		return (-3);
	result = arg_validate(pnt);
	return (result);
}
