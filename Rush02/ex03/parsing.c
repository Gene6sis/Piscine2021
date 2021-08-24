/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 00:49:18 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/22 15:59:51 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ck_dict.h"
#include <stdlib.h>
#include <unistd.h>


char	**ft_split(char *str, char *charset);

char	**str_to_strs(char *file)
{
	char	*dict_str;
	char	**dict_line;

	if ((dict_str = dict_to_str(file)) == NULL)
		return (NULL);
	if ((dict_line = ft_split(dict_str, "\n")) == NULL)
	{
		free(dict_str);
		return (NULL);
	}
	free(dict_str);
	return (dict_line);
}}

int		nb_start_at(char *str)
{
	int i;
	int seen_number;
	int zero_before;

	zero_before = 0;
	seen_number = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] != '0')
			seen_number = 1;
		if (seen_number == 0 && str[i] == '0' && str[i + 1] != ' '
				&& str[i + 1] != ':')
			zero_before++;
		i++;
	}
	return (zero_before);
}

int		is_line_valid(char *str)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != ':')
		return (0);
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= ' ' && str[i] <= '~')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int		key_start_pos(char *str)
{
	int i;

	i = 0;
	while (str[i] != ':')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	return (i);
}

int		key_len(char *str, int start)
{
	int prev_space;
	int len;

	len = 0;
	prev_space = 0;
	while (str[start] >= ' ' && str[start] <= '~')
	{
		if (str[start] == ' ' && prev_space == 0)
		{
			prev_space = 1;
			len += 1;
		}
		else if (str[start] != ' ')
		{
			prev_space = 0;
			len += 1;
		}
		start++;
	}
	return (len);
}

char	*parse_key(char *str)
{
	int		i;
	int		j;
	char	*ret;
	int		prev_space;

	i = key_start_pos(str);
	if (!(ret = malloc((key_len(str, i) + 1) * sizeof(char))))
		return (NULL);
	j = 0;
	prev_space = 0;
	while (str[++i - 1] >= ' ' && str[i - 1] <= '~')
	{
		if (str[i - 1] == ' ' && prev_space == 0)
		{
			prev_space = 1;
			ret[j++] = ' ';
		}
		else if (str[i - 1] != ' ')
		{
			prev_space = 0;
			ret[j++] = str[i - 1];
		}
	}
	ret[j] = '\0';
	return (ret);
}

int		check_if_followed_zero(char *str, int len_trip)
{
	int i;

	i = -1;
	while (str[++i] >= '0' && str[i] <= '9')
	{
		if (i >= len_trip && str[i] != '0')
			return (0);
	}
	return (1);
}


void	parse_number(t_key *dict, char *str)
{
	char	*ret;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	while (!(str[i] >= '0' && str[i] <= '9')
		|| (str[i] == '0' && str[i+1] != '0'))
		i++;
	while (str[i++] >= '0' && str[i] <= '9')
		j++;
	ret = malloc(sizeof(char) * (j + 1));
	if (ret == 0)
		return (NULL);
	i -= j;
	while (str[i] >= '0' && str[i] <= '9')
		ret[k++] = str[i++];
	ret[k] = '\0';
	dict->nb = ret;
}


int		parse_line(t_key *key, char *str, int *pos)
{
	if (is_line_valid(str))
	{
		parse_number(key, str);
		if (!(key->str = parse_key(str)))
		{
			write(2, "Malloc Error\n", 13);
			key->str = NULL;
			return (0);
		}
		*pos += 1;
		return (1);
	}
	return (1);
}

t_key	*dict_allocation(char **strs)
{
	int		len;
	t_key	*ret;

	if (strs == NULL)
		return (NULL);
	if ((len = dict_nb_key(strs)) == 0 || valid_table(strs) == 0)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	if (!(ret = malloc((len + 1) * sizeof(t_key))))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (ret);
}

t_key	*parse_dict_strs(char **strs)
{
	int		i;
	t_key	*ret;
	int		pos;

	if (!(ret = dict_allocation(strs)))
		return (NULL);
	i = -1;
	pos = 0;
	while (strs[++i] != NULL)
	{
		if (parse_line(&ret[pos], strs[i], &pos) == 0)
		{
			ft_free_strs(strs);
			ft_free_tab_key(ret);
			return (NULL);
		}
	}
	ft_free_strs(strs);
	ret[pos].str = NULL;
	return (ret);
}
