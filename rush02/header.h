/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:40:26 by hwahn             #+#    #+#             */
/*   Updated: 2020/02/09 15:24:10 by hwahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_dictionary
{
	struct s_node *cur_node;
	struct s_node *head_node;
	struct s_node *tail_node;
} 				t_dictionary;

typedef struct	s_node
{
	char *key;
	char *value;
	struct s_node *node_next;
}				t_node;

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_create_node(t_dictionary *dic, char *t_key, char *t_value);
void	ft_find_dictionary(t_dictionary *dic, char *t_key);
void	ft_presetting_dic(t_dictionary *dic);
t_dictionary	*ft_dictionary_setting(void);
char	**ft_split(char *str);
char	*ft_sep_by_one_line(char *str, char	*a_line);
char	*ft_reduce_address(char *buffer);
char	*ft_rm_space_value(char *str);
char	*ft_rm_space_key(char *str);
void	ft_input_a_line(t_dictionary *dic, char *buffer);
int		ft_dic_size();
void	ft_print_dic(t_dictionary *dic);

#endif
