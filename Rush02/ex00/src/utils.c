/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:34:51 by scros             #+#    #+#             */
/*   Updated: 2020/10/25 17:25:27 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "globals.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int				ft_ends_with(char *end, char *str)
{
	unsigned int str_len;
	unsigned int end_len;

	str_len = ft_strlen(str);
	end_len = ft_strlen(end);
	while (str_len > 0 && end_len > 0)
	{
		--str_len;
		--end_len;
		if (str[str_len] != end[end_len])
			return (0);
		if (str_len == 0)
			return (0);
	}
	return (1);
}

char			*ft_strdup(char *src)
{
	char	*pointer;
	size_t	size;
	int		i;

	size = ft_strlen(src) + 1;
	if (!(pointer = malloc(size * sizeof(*src))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		pointer[i] = src[i];
		i++;
	}
	pointer[i] = 0;
	return (pointer);
}

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
