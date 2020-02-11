/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:09:46 by hwahn             #+#    #+#             */

 /*   Updated: 2020/02/08 15:41:24 by hwahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char *argv[])
{
	int i;
	t_dictionary *dic;

	i = 0;
	if (argc == 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	while (argv[1][i] != 0)
	{
		if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
		{
			ft_putstr("error\n");
			return (0);
		}
		i++;
	}
	if (!(dic = ft_dictionary_setting()))
		return (0);
//	ft_input_dictionary(dic,    );
	ft_find_dictionary(dic, argv[1]);
	ft_print_dic(dic);
	return (0);
}
