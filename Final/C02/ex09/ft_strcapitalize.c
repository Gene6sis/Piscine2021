/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 23:09:14 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/06 02:49:02 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alphanum(char str)
{
	if (!((str <= 'z' && str >= 'a')
			   || (str <= 'Z' && str >= 'A')
			   || (str <= '9' && str >= '0')))
		return (0);
	return (1);
}

int	ft_is_lowercase(char str)
{
	if (str > 'z' || str < 'a')
		return (0);
	return (1);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	str = ft_strlowcase(str);
	if (ft_is_lowercase(str[0]))
		str[0] -= 32;
	i = 1;
	while (str[i])
	{	
		if (!ft_str_is_alphanum(str[i - 1]))
		{
			if (ft_is_lowercase(str[i]))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
