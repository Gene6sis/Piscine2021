#include <stdlib.h>

int	ft_is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_len(char *str, char *charset)
{
	unsigned int	i;
	unsigned int	compt;

	i = 0;
	compt = 0;
	while (ft_is_in_charset(str[i], charset) == 0)
		i++;
	while (ft_is_in_charset(str[i], charset) != 0 && str[i])
	{
		i++;
		compt++;
	}
	return (compt);
}

int	ft_elements(char *str, char *charset)
{
	unsigned int	i;
	unsigned int	compt;

	i = 0;
	compt = 0;
	while (str[i])
	{
		while (ft_is_in_charset(str[i], charset) == 0)
			i++;
		if (ft_is_in_charset(str[i], charset) != 0 && str[i])
			compt++;
		while (ft_is_in_charset(str[i], charset) != 0 && str[i])
			i++;
	}
	return (compt);
}

char	**ft_split(char *str, char *charset)
{
	char			**result;
	int				i;
	unsigned int	j;
	unsigned int	x;

	result = malloc(sizeof(char *) * (ft_elements(str, charset) + 1));
	if (!str || !result)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_elements(str, charset))
	{
		x = 0;
		result[i] = malloc(ft_len(&str[j], charset) + 1);
		while (ft_is_in_charset(str[j], charset) == 0)
			j++;
		while (ft_is_in_charset(str[j], charset) != 0 && str[j] != '\0')
			result[i][x++] = str[j++];
		result[i][x] = '\0';
		i++;
	}
	result[i] = 0;
	return (result);
}
