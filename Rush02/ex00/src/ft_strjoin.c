/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:14:42 by scros             #+#    #+#             */
/*   Updated: 2020/10/25 19:16:09 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "globals.h"

void	ft_next(char **final_str, int len, char *str)
{
	int		j;

	j = -1;
	while (++j < len)
		*((*final_str)++) = str[j];
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*final_str;
	int		i;
	int		len;
	int		lens[size];
	int		sep_len;

	i = -1;
	sep_len = ft_strlen(sep);
	len = (size - 1) * sep_len + 1;
	len = len < 1 ? 1 : len;
	while (++i < size)
		len += (lens[i] = ft_strlen(strs[i]));
	if (!(final_str = malloc(len * sizeof(final_str))))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		ft_next(&final_str, lens[i], strs[i]);
		if (i < size - 1)
			ft_next(&final_str, sep_len, sep);
	}
	*final_str = 0;
	return (final_str - (len - 1));
}
