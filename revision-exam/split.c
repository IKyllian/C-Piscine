/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:20:47 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/28 15:34:30 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_get_index_of(char c, char *str)
{
	int i;

	i = 0;
	if (!c)
		return (-1);
	while (str[i])
	{
		if(c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int		*ft_get_len_strings(char *str, char *charset, int len, int **starts)
{
	int *len_strings;
	int i;
	int j;

	if(!(len_strings = malloc(sizeof(*len_strings) * len)))
		return (NULL);
	if(!(*starts = malloc(sizeof(**starts) * len)))
		return (NULL);
	i = 0;
	j = ft_get_index_of(str[0], charset) != -1 ? -1 : 0;
	while (str[i])
	{
		len_strings[j] = 0;
		(*starts)[j] = -1;
		while (str[i] && ft_get_index_of(str[i], charset) == -1)
		{
			len_strings += 1;
			(*starts)[j] = (*starts)[j] < 0 ? i + 1 : 0;
			i++;
		}
		j++;
		while (str[i] && ft_get_index_of(str[i], charset) != -1)
			i++;
	}
	return (len_strings);
}

int		ft_get_len_tab(char *str, char *charset)
{
	int i;
	int j;

	i = 0;
	j = ft_get_index_of(str[0], charset) != -1 ? -1 : 0;
	while (str[i])
	{
		while (str[i] && ft_get_index_of(str[i], charset) == -1)
			i++;
		j++;
		while (str[i] && ft_get_index_of(str[i], charset) != -1)
			i++;
	}
	return (j);
}

void	ft_fill_tab(char *str, char **output, int *starts, int *len_strings)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i == *starts)
		{
			if(!(output[j] = malloc(sizeof(**output) * (*len_strings + 1))))
					return ;
			while (i++ - *starts < *len_strings)
				output[j][i - *starts - 1] = str[i - 1];
			output[j][i - *starts - 1] = '\0';
			starts++;
			len_strings++;
			j++;
		}
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
		int len_tab;
		int *starts;
		int *len_strings;
		char **output;

		len_tab = ft_get_len_tab(str, charset) + 1;
		len_strings = ft_get_len_strings(str, charset, len_tab, &starts);
		printf("test");
		if(!(output = malloc(sizeof(*output) * len_tab)))
			return (NULL);
		if (len_tab > 1)
			ft_fill_tab(str, output, starts, len_strings);
		else
			output[0][0] = 0;
		return (output);
}

int		main(void)
{
	char str[] = "Ceci est un test";
	char charset[] = " ";
	char **final_str = ft_split(str, charset);
	int i = 0;
	printf("test");
	while (final_str[i] != 0)
	{
		printf("%s\n", final_str[i]);
		i++;
	}
}
