/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:43:42 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/27 16:57:19 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_index_of(char c, char *str)
{
	int i;

	i = -1;
	if (!c)
		return (-1);
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

int		*ft_init_lens(char *str, char *charset, int len, int **starts)
{
	int *lens;
	int i;
	int j;

	if (!(lens = malloc(len * sizeof(*lens))))
		return (NULL);
	if (!(*starts = malloc(len * sizeof(**starts))))
		return (NULL);
	i = 0;
	j = ft_index_of(str[0], charset) != -1 ? -1 : 0;
	while (str[i])
	{
		lens[j] = 0;
		(*starts)[j] = -1; //sert a pour modifier que 1 fois starts dans la boucle
		printf("my i = %i\n", i);
		while (str[i] && ft_index_of(str[i], charset) == -1)
		{
			lens[j] += 1;
			(*starts)[j] += (*starts)[j] < 0 ? i + 1 : 0;
			i++;
		}
		printf("(*starts)[j] = %i\n", (*starts)[j]);
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
	j = ft_index_of(str[0], charset) != -1 ? -1 : 0; // -1 si la chaine commence par un separateur
	while (str[i])
	{
		while (str[i] && ft_index_of(str[i], charset) == -1)
			i++;
		++j;
		while (str[i] && ft_index_of(str[i], charset) != -1)
			i++;
	}
	printf("j = %i\n", j);
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

char	**ft_split(char *str, char *charset)
{
	int		max; //Taile du tableau
	int		*starts; //Contient l'index du debut de chaque mot
	int		*lens; //Contient la taille de chaque mot
	char	**output;

	max = ft_init(str, charset) + 1;
	lens = ft_init_lens(str, charset, max, &starts);
	if (!(output = malloc(max * sizeof(*output))))
		return (NULL);
	if (max > 1)
		ft_fill(str, output, lens, starts);
	else
		output[0] = 0;
	return (output);
}


int main()
{
	char str[] = "Ceci est un test";
	char charset[] = " ";
	char **final_str = ft_split(str, charset);

	int i = 0;
	while (final_str[i] != 0)
	{
		printf("%s\n", final_str[i]);
		i++;
	}

}
