/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:24:36 by scros             #+#    #+#             */
/*   Updated: 2020/10/25 13:39:01 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "globals.h"

int		*ft_init_lens(char *str, char *charset, int len, int **starts)
{
	int *lens;
	int i;
	int j;

	if (!(lens = malloc(len * sizeof(*lens))))
		return (NULL);
	if (!((*starts) = malloc(len * sizeof(**starts))))
		return (NULL);
	i = 0;
	j = ft_index_of(str[0], charset) != -1 ? -1 : 0;
	while (str[i])
	{
		lens[j] = 0;
		(*starts)[j] = -1;
		while (str[i] && ft_index_of(str[i], charset) == -1)
		{
			lens[j] += 1;
			(*starts)[j] += (*starts)[j] < 0 ? i + 1 : 0;
			i++;
		}
		++j;
		while (str[i] && ft_index_of(str[i], charset) != -1)
			i++;
	}
	return (lens);
}

int		ft_init(char *str, char *charset)
{
	int i;
	int j;

	i = 0;
	j = ft_index_of(str[0], charset) != -1 ? -1 : 0;
	while (str[i])
	{
		while (str[i] && ft_index_of(str[i], charset) == -1)
			i++;
		++j;
		while (str[i] && ft_index_of(str[i], charset) != -1)
			i++;
	}
	return (j);
}

void	ft_fill(char *str, char **output, int *lens, int *starts)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i == *starts)
		{
			if (!(output[j] = malloc((*lens + 1) * sizeof(**output))))
				return ;
			while (i++ - *starts < *lens)
				output[j][i - *starts - 1] = str[i - 1];
			output[j][i - *starts - 1] = 0;
			starts++;
			lens++;
			j++;
		}
		else
			i++;
	}
	output[j] = 0;
}

char	**ft_split(char *str, char *charset, int *len)
{
	int		max;
	int		*starts;
	int		*lens;
	char	**output;

	max = ft_init(str, charset) + 1;
	lens = ft_init_lens(str, charset, max, &starts);
	*len = max;
	if (!(output = malloc(max * sizeof(*output))))
		return (NULL);
	if (max > 1)
		ft_fill(str, output, lens, starts);
	else
		output[0] = 0;
	return (output);
}
