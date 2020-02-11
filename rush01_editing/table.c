/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochoi <yochoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:49:06 by yochoi            #+#    #+#             */
/*   Updated: 2020/02/02 15:50:00 by yochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		**fill_array(int **arr, int size);
void	ft_putchar(char x);
int		calc_bfs(int x, int *row);
int		calc_bseen(int x, int *row);
/*
int		check_clue(int *row, char arg, int y)
{
	int argnbr;
	int buildfs;
	int buildseen;

	argnbr = (int)arg - '0';
	buildfs = calc_bfs(y, row);
	buildseen = calc_bseen(y, row);
	if ((buildfs + buildseen) == argnbr)
		return (1);
	return (0);
}
*/
int		check_clue(int *row, char arg, char arg2)
{
	int current;
	int i;

	current = -1;
	i = 0;
	while (row[i] != 0)
	{
		if (current < row[i])
		{
			arg -= 1;
			current = row[i];
		}
		i++;
		if (arg != 0)
			return (0);
	}
	current = -1;
	i = 3;
	while (row[i] != 0)
	{
		if (current < row[i])
		{
			arg2 -= 1;
			current = row[i];
		}
		i--;
		if (arg2 != 0)
			return(0);
	}
	return (1);
}


int		check_row_col(int **table, int x, int y, char *argv)
{
	int i;
	int result;

	result = 1;
	i = 0;
	while (i < 4)
	{
		if (i != y)
			if (table[x][y] == table[x][i])
				return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (i != x)
			if (table[x][y] == table[i][y])
				return (0);
		i++;
	}
	result = check_clue(table[x], argv[x + 8], argv[x + 12]);
	return (result);
}

void	draw_table(int **table, int size)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (i++ < size - 1)
	{
		while (j++ < size - 1)
		{
			ft_putchar(table[i][j] + '0');
			if (j < size - 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		j = -1;
	}
}

int		perform_table(char *argv, int size)
{
	int	x;
	int	y;
	int	**table;

	table = 0;
	table = fill_array(table, size);
	x = 0;
	y = 0;
	while (x < size)
	{
		while (y < size)
		{
			table[x][y] = table[x][y] + 1;
			while (check_row_col(table, x, y, argv) == 0 && table[x][y] < 4)
				table[x][y] = table[x][y] + 1;
			if (check_row_col(table, x, y, argv) == 0)
			{
				table[x][y] = 0;
				y--;
			}
			else
				y++;
			if (y < 0 && x > 0)
				return (0);
		}

		y = 0;
		x++;
	}
	draw_table(table, size);
	return (1);
}
