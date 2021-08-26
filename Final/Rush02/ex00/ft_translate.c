
#include <stdlib.h>
#include <stdio.h>

char *create_str(char *file);

int	ft_findico(char *str, char *nb)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (nb[j] == str[i + j])
		{
			if (nb[j + 1] == '\0' && (str[i - 1] < '0' || str[i - 1] > '9')
					&& (str[i + j + 1] < '0' || str[i + j + 1] > '9'))
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int		key_start_pos(char *str, int nb)
{
	int i;

	i = nb;
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

char	*ft_translate(char *str, char *nb)
{
	int		i;
	int		j;
	char	*ret;
	int		prev_space;

	i = key_start_pos(str, ft_findico(str, nb));
	ret = malloc((key_len(str, i) + 1) * sizeof(char));
	if (!ret)
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
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	char *str;

	str = create_str(argv[1]);
	printf("OKKKKKKKKKKK\n");
	printf("%s\n", ft_translate(str, argv[2]));
}
*/
