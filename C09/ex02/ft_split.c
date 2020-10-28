/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:45:56 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/28 13:33:22 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_index_of(char c, char *charset)
{
	int i;

	i = 0;
	if (!c)
		return (-1);
	while (charset[i])
	{
		if (c == charset[i])
			return (i);
		i++;
	}
	return (-1);
}

int		*ft_init_len_string(char *str, char *charset, int len, int **starts)
{
	int *len_string;
	int i;
	int j;

	if (!(len_string = malloc(sizeof(*len_string) * len)))
		return (NULL);
	if (!(*starts = malloc(sizeof(**starts) * len)))
		return (NULL);
	i = 0;
	j = ft_index_of(str[0], charset) != -1 ? -1 : 0;
	while (str[i])
	{
		len_string[j] = 0;
		(*starts)[j] = -1;
		while (str[i] && ft_index_of(str[i], charset) == -1)
		{
			len_string[j] += 1;
			(*starts)[j] += (*starts)[j] < 0 ? i + 1 : 0;
			i++;
		}
		j++;
		while (str[i] && ft_index_of(str[i], charset) != -1)
			i++;
	}
	return (len_string);
}

void	ft_remplir_tab(char *str, char **output, int *len_string, int *starts)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i == *starts)
		{
			if (!(output[j] = malloc(sizeof(**output) * (*len_string + 1))))
				return ;
			while (i++ - *starts < *len_string)
				output[j][i - *starts - 1] = str[i - 1];
			output[j][i - *starts - 1] = '\0';
			starts++;
			len_string++;
			j++;
		}
		else
			i++;
	}
	output[j] = 0;
}

int		ft_init_length(char *str, char *charset)
{
	int i;
	int j;

	i = 0;
	j = ft_index_of(str[0], charset) != -1 ? -1 : 0;
	while (str[i])
	{
		while (str[i] && ft_index_of(str[i], charset) == -1)
			i++;
		j++;
		while (str[i] && ft_index_of(str[i], charset) != -1)
			i++;
	}
	return (j);
}

char	**ft_split(char *str, char *charset)
{
	int		len_tab;
	int		*starts;
	int		*len_string;
	char	**output;

	len_tab = ft_init_length(str, charset) + 1;
	len_string = ft_init_len_string(str, charset, len_tab, &starts);
	if (!(output = malloc(sizeof(*output) * len_tab)))
		return (NULL);
	if (len_tab > 1)
		ft_remplir_tab(str, output, len_string, starts);
	else
		output[0] = 0;
	return (output);
}
