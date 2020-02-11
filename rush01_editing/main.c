/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochoi <yochoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 10:54:49 by yochoi            #+#    #+#             */
/*   Updated: 2020/02/02 14:57:37 by yochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		argv_is_valid(char *pnt);
int		perform_table(char *argv, int size);
void	print_error(int error);
int		ft_length(char *str);

int		main(int argc, char *argv[])
{
	int		i;
	char	*pnt;

	argc = 0;
	pnt = malloc((ft_length(argv[1]) / 2) * sizeof(char));
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] != ' ')
		{
			pnt[argc] = argv[1][i];
			argc++;
		}
		i++;
	}
	if (argv_is_valid(pnt) <= 0)
		print_error(argv_is_valid(pnt));
	else
	{
		if (perform_table(pnt, 4) == 0)
			print_error(-4);
	}
	free(pnt);
	return (0);
}
