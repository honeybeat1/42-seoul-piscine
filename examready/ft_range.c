/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:10:52 by dachung           #+#    #+#             */
/*   Updated: 2020/02/07 14:36:05 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


unsigned char swap_bits(unsigned char octet)
{
	unsigned char result;

	result = 0;
	result += octet << 4;
	result += octet >> 4;
	return (result);
}

#include <stdio.h>

int		main(void)
{
	printf("%d\n", (int) swap_bits(65)); 
}
