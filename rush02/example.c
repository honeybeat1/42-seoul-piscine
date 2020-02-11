/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:53:31 by jbeen             #+#    #+#             */
/*   Updated: 2020/02/09 19:27:51 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int		g_idx = 0;
int		g_count = 0;
int		g_max_unit = 12;
char	*g_num_table[101] = {0, };
char	**g_unit_table;

typedef struct		s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}					t_dict;

int     ft_strlen(char *str)
{
    int     i;
    i = 0;
    while (str[i])
        i++;
    return (i + 1);
}
// ft_putnum 반복출력을 위한 putchar 함수
void	ft_putchar(int index)
{
	write(1, g_num_table[index], ft_strlen(g_num_table[index]));
}
// 변환된 숫자 해쉬테이블에서 찾아 출력하기
int    ft_putnum(char *conv, int size)
{
    int     i;
    char    putnum;
	int		temp;
//  max_unit 보다 큰경우 error (return (0)) 0 반환
	if (size / 3 > g_max_unit)
		return (0);
    i = 0;
	while (conv[i])
		conv[i++] -= '0';
	i = 0;
    while (size >= 0)
    {	
        if (i % 3 == 0)
        {
			ft_putchar(conv[i]);
            if (conv[i])
			{
            	write(1, " ", 1);
				ft_putchar(100);
			}
			i++;
        }
        if (i % 3 == 1)
        {
            if (conv[i] && conv[i - 1])
             write(1, " ", 1);
            if (conv[i] == 1)
            {
				i++;
				ft_putchar(conv[i] + 10);
                i++;
            }
            else
			{
				ft_putchar(conv[i] * 10);
				i++;
			}
        }
        if (i % 3 == 2)
        {
            if (conv[i] && conv[i - 1])
                write(1, " ", 1);
			 ft_putchar(conv[i]);
            i++;
        }
		if (size > 3)
		{
			write(1, " ", 1);
    	    write (1, g_unit_table[(size - 1) / 3], ft_strlen(g_unit_table[(size - 1) / 3]));
			temp = i;
			while (conv[i])
			{
				if (!(conv[i++]))
					break ;
				else
				{
					write(1, " ", 1);
					break;
				}
			}
			i = temp;
		}
        size -= 3;
		if (!(conv[i]))
			return (1);
    }
	return (1);
}
// split된 num과 그 길이를 인자로 받아, 3의 배수의 size를 갖는 배열을 만들고 conv[i]로 convert
// 이후 출력단계인 putnum으로 이동
int		ft_convert_num(char *num, int len)
{
	char	*conv;
	int		size;
	int		i;
    int     j;
	int		result;
	i = 0;
    j = 0;
	size = ((((len - 1) / 3) + 1) * 3);
	if(!(conv = (char *)malloc(sizeof(char) * (size + 1)))) // 밑에서 free
		return (0);
	while (i < size - len)
		conv[i++] = '0';
	while (i < size)
		conv[i++] = num[j++];
	conv[i] = 0;
    result = ft_putnum(conv, size);
	free(conv);
    return (result);
}


void	ft_move_space(char *buf)
{
	while (buf[g_idx] == ' ' || buf[g_idx] == 9
	|| (11 <= buf[g_idx] && buf[g_idx] <= 13))
		g_idx++;
}

int		ft_move_num(char *buf)
{
	int		len;

	len = 0;
	while ('0' <= buf[g_idx] && buf[g_idx] <= '9')
	{
		g_idx++;
		len++;
	}
	return (len);
}



int		ft_move_char(char *buf)
{
	int		len;

	len = 0;
	while (32 <= buf[g_idx] && buf[g_idx] <= 126)
	{
		g_idx++;
		len++;
	}
	return (len);
}

char	*ft_strndup(char *src, int len)
{
	int     i;
	char	*temp;

	i = 0;
	g_idx -= len;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		temp[i] = src[g_idx];
		g_idx++;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr != NULL)
	{
		while (i < len)
		{
			ptr[i] = src[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}

void	ft_initialize_num_table(char *key, char *value, int key_len)
{
	int		i;
	int		idx;

	i = 0;
	idx = 0;
	if (key_len == 1 || (key_len == 2 && (key[0] == '1' || key[1] == '0'))
	 	|| (key_len == 3 && (key[0] == '1' && key[1] == '0' && key[2] == '0')))
	{
		while (i < key_len)
		{
			idx = (idx * 10) + (key[i] - '0');
			i++;
		}
		g_num_table[idx] = ft_strdup(value);
	}
	return ;
}

void	ft_remalloc_unit_table(int idx)
{
	int		i;
	char	**temp;

	i = 1;
	temp = (char **)malloc(sizeof(char *) * (idx + 1));
	while (i < 13)
	{
		temp[i] = ft_strdup(g_unit_table[i]);
		free(g_unit_table[i]);
		i++;
	}
	free(g_unit_table);
	i = 1;
	g_unit_table = (char **)malloc(sizeof(char *) * (idx + 1));
	while (i < 13)
	{
		g_unit_table[i] = ft_strdup(temp[i]);
		free(temp[i]);
		i++;
	}
	free(temp);
}

void		ft_initialize_unit_table(char *key, char *value, int key_len)
{
	int		idx;

	//key가 유효한지 확인하기
	//4, 7, 10 ... 이므로 3으로 나눴을 때 나머지가 1이어야 하고('1'은 제외), key[0]이 '1'이어야 함
	if (key_len != 1 && key_len % 3 == 1 && key[0] == '1')
	{
		//기본 key면 바로 넣기
		idx = key_len / 3;
		if (idx < 13)
		{
			g_unit_table[idx] = ft_strdup(value);
		}
		//새로운 key면 새로 malloc해주고, 복사 후, 기존 malloc free하기
		else
		{
			ft_remalloc_unit_table(idx);
			g_unit_table[idx] = ft_strdup(value);
			if (g_max_unit < idx)
				g_max_unit = idx;
		}
	}

	//parsing이 끝난 후 unit이 유효한지 검증하기 -> 유효하지 않으면 dict Error?

	return ;
}

int		ft_dict_parsing(char *buf)
{
	int		key_len;
	int		value_len;
	char	*key;
	char	*value;
	
	//g_idx 0으로 초기화는 main에서 dict_parsing호출하기 전에 실행
	while (buf[g_idx] != '\0')
	{
		//숫자인지 확인하면서 이동 후 길이 구함
		key_len = ft_move_num(buf);

		//시작이 숫자가 아니라서 len이 0이면 dict Error (생략 가능?)
		if (key_len == 0)
			return (0); 

		//숫자를 temp_key에 복제
		key = ft_strndup(buf, key_len);
		
		//스페이스 이동, :이동, 스페이스 이동
		ft_move_space(buf);
		if (buf[g_idx++] != ':')
			return (0);
		ft_move_space(buf);

		value_len = ft_move_char(buf);
		// value_len이 0인 경우는 에러?
		value = ft_strndup(buf, value_len);

		ft_initialize_num_table(key, value, key_len); //if문으로 num일 때만 보낼 수 있지만 줄수제한 때문에 무조건 보냄
		ft_initialize_unit_table(key, value, key_len); //if문으로 unit일 때만 보낼 수 있지만 줄수제한 때문에 무조건 보냄

		//key, value는 while문 돌 때 마다 새로 생기니까 바로바로 free해야하는 게 맞는지 확인해보기
		free(key);
		free(value);

		ft_move_space(buf);

		//printf("[%d]", g_count++);
		if (buf[g_idx] == '\0')
			break;
		if (buf[g_idx] != '\n')
		 	return (0);
		while (buf[g_idx] == '\n')
			g_idx++;
	}
	return (1);
}

int		ft_is_integer(char *str)
{
	int		len;
	int		idx;
	int		count;

	len = 0;
	idx = 0;
	

	//idx = 0
	//스페이스만큼 idx이동시키기
	while (str[idx] == ' ')
		idx++;
	//idx = 3

	//+,-개수 세면서 idx이동시키기
	count = 0;
	while (str[idx] == '+' || str[idx] == '-')
	{
		if(str[idx] == '-')
			count++;
		idx++;			
	}
	if (count % 2 == 1)
		return (0);
	//idx = 7

	//0만큼 idx 이동시키기
	while (str[idx] == '0')
		idx++;
	//idx = 9

	//숫자인지 확인하면서, len을 증가시킨다
	while (str[idx] != 0 && str[idx] >= '0' && str[idx] <= '9')
	{
		len++;
		idx++;
	}

	//숫자 이후에 \0까지 진행하면서 공백 이외의 문자가 나오면 0 리턴, 공백만 나오면 len리턴
	while (str[idx] != 0)
	{
		if (str[idx] == ' ')
			idx++;
		else
			return (0);	
	}
	return (len);

}

int		main(int argc, char **argv)
{
	int		fd;
	int		readn;
	int		len;
	//int		q;
	//char	*number;
	int		i;
	// char	buf[691];
	char	buf[1024] = {1, };

	printf("[%s]\n", argv[0]);
	if (!(argc == 2 || argc == 3))
		write(1, "Error\n", 6);
	else if (argc == 2)
	{
		len = ft_is_integer(argv[1]);


		//dict parsing, nonblock의미 없으므로 삭제
		if ((fd = open("numbers.dict", O_RDONLY)) == -1)
			write(2, "Error\n", 6);
		else
		{
			// readn = read(fd, buf, 690);
			// buf[690] = 0;
			readn = read(fd, buf, 1024);
			//buf[1023] = 0; 생략 가능?
			
			// printf("%d!!\n", readn);
			// printf("<%s>", buf);

			//global 변수들 초기화하기 ->  g_num_table을 malloc으로 초기화시키는 과정 추가
			g_idx = 0;
			g_unit_table = (char **)malloc(sizeof(char *) * 13);
			if (!ft_dict_parsing(buf))
			{
				//write(2, "Error1\n", 7);
				printf("Error1");
			}
			else
			{
				//num parsing 성공 테스트
				// i = 0;
				// while (i < 101)
				// {
				// 	printf("[index(key) : %d, value : %s]\n", i, g_num_table[i]);
				// 	i++;
				// }

				//unit parsing 성공 테스트
				// i = 1;
				// while (i < 14)
				// {
				// 	printf("[index(key) : %d, value : %s]\n", i, g_unit_table[i]);
				// 	i++;
				// }
				ft_convert_num(argv[1], 9);
			}
			close (fd);
		}
	}
	else if (argc == 3)
	{

	}
	return (0);
}
