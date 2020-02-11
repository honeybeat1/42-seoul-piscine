/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trial.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:53:50 by dachung           #+#    #+#             */
/*   Updated: 2020/02/09 18:01:37 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int bulk;

	typedef struct {
		char *key;
		int value;
	} dictionary;

	dictionary dict[2] = {{ .key = 2, .value = two}, { .key = 40, .value = forty}};

	typedef struct {
		int hund;
		int ten;
		int one;
	} number; 

	number num[100];

	if
		bulk = ft_len(argv[1]) / 3
	else
		bulk = ft_len(argv[1]) / 3 + 1;
	
	num[0].key = 

	

}
