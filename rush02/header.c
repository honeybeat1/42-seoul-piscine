/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:07:30 by hwahn             #+#    #+#             */
/*   Updated: 2020/02/09 15:59:15 by hwahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int		ft_strcmp(char *s1,char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_create_node(t_dictionary *dic, char *t_key, char *t_value)
{
	t_node *newNode = (t_node *)malloc(sizeof(t_node));
	newNode->key = t_key;
	newNode->value = t_value;
	newNode->node_next = NULL;
	if (dic->head_node == NULL && dic->tail_node == NULL)
		dic->head_node = dic->tail_node = newNode;
	else
	{
		dic->tail_node->node_next = newNode;
		dic->tail_node = newNode;
	}
	printf("create : %s %s\n", t_key, t_value);
	dic->cur_node = newNode;
}

void	ft_find_dictionary(t_dictionary *dic, char *t_key)
{
	t_node *curr = dic->head_node;
	while (curr != NULL)
	{
		if (!(ft_strcmp(curr->key, t_key)))
			printf("%s\n", curr->value);
		curr = curr->node_next;
	}
}

void	ft_print_dic(t_dictionary *dic)
{
	t_node *curr = dic->head_node;
	while (curr != NULL)
	{
		printf("print dic : %s %s\n", curr->key, curr->value);
		curr = curr->node_next;
	}
}

char	**ft_split(char *str)
{
	int		key_length;
	int		val_length;
	char	**values;
	int		i;

	i = 0;
	values = malloc(sizeof(char *) * 2);
	key_length = 0;
	val_length = 0;
	while (str[key_length] != ':')
	{
		if ((str[key_length] >= 9 && str[key_length] <= 13) || str[key_length] == 32)
			break ;
		key_length++;
	}
	str[key_length] = 0;
	values[0] = str;
	str += key_length + 1;
	values[1] = str;
	return (values);
}
char	*ft_sep_by_one_line(char *str, char	*a_line)
{
	int		i;
	i = 0;
	while (*str != '\n')
	{
		a_line[i] = *str;
		i++;
		str++;
	}
	a_line[i] = '\0';
	return (a_line);
}

char	*ft_reduce_address(char *buffer)
{
	while (*buffer != '\n')
		buffer++;
	buffer++;
	return (buffer);
}

char	*ft_rm_space_value(char *str)
{
	int		i;
	i = 0;
	while (str[i] == 0)
		str++;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == ':' || str[i] == 0)
			str++;
		i++;
	}
	return (str);
}

char	*ft_rm_space_key(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			str[i] = 0;
		i++;
	}
	return (str);
}

void	ft_input_a_line(t_dictionary *dic, char *buffer)
{
	char	*a_line;
	char	**key_and_value;
	int		i;

	a_line = malloc(sizeof(char) * 10000);
	i = 0;
	while(i < 5)
	{
		key_and_value = malloc(sizeof(char *) * 2);
		a_line = ft_sep_by_one_line(buffer, a_line);
		buffer = ft_reduce_address(buffer);
		key_and_value = ft_split(a_line);
		printf("%s %s\n", key_and_value[0], key_and_value[1]);
		key_and_value[0] = ft_rm_space_key(key_and_value[0]);
		key_and_value[1] = ft_rm_space_value(key_and_value[1]);
		printf("after:%s %s\n", key_and_value[0], key_and_value[1]);
		ft_create_node(dic, key_and_value[0], key_and_value[1]);
		i++;
	}
}

int		ft_dic_size(   )
{
	return (0);	
}

void	ft_presetting_dic(t_dictionary *dic)
{
	char	*buffer;
	int		fd;

	buffer = malloc(sizeof(char) * 10000);
	fd = open("numbers.dict", O_RDONLY);
	read(fd, buffer, 10000);
	ft_input_a_line(dic, buffer);
}

t_dictionary	*ft_dictionary_setting(void)
{
      t_dictionary *dic = (t_dictionary*)malloc(sizeof(t_dictionary));
     if (dic == NULL)
		 return (0);
	  dic->head_node = NULL;
      dic->cur_node = NULL;
      dic->tail_node = NULL;
	  ft_presetting_dic(dic);
	  return (dic);
}
