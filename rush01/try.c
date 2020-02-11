/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 00:57:52 by dachung           #+#    #+#             */
/*   Updated: 2020/02/02 13:58:51 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	insert_vlaue(int **arr, int x, int y, int *clue, int i)
{
	if (x == 0 || x == 5)
	{
		while (y < 5)
		{
			arr[x][y] = clue[i];
			y++;
			i++;
		}
	}
	if (y == 0 || y == 5)
	{
		while (x < 5)
		{
			arr[x][y] = clue[i];
			x++;
			i++;
		}
	}
}

int		**insert_clue(int **arr, int *clue)
{
	insert_value(arr, 0, 1, clue, 0);
	insert_value(arr, 5, 1, clue, 4);
	insert_value(arr, 1, 0, clue, 8);
	insert_value(arr, 1, 5, clue, 12);
	return (arr);
}

int 	**insert_four(int **arr)
{
	while (x < 5 && y < 5)
	{
		if (arr[x][y] == 1)
	}
}


int	perform_table(int *clue)
{
	int x;
	int y;
	int **table;

	table = 0;
	table = fill_array(table, 5);//0으로 채우는 5x5만들기
	x = 0;
	y = 0;

	table = insert_clue(table, clue);
	table = insert_four(table);


}

