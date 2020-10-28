/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:18:44 by scros             #+#    #+#             */
/*   Updated: 2020/10/25 16:52:59 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"

int	validate(t_entry *dict)
{
	t_u128	key;
	int		max;

	key = 0;
	max = 13;
	while (key < 20)
		if (ft_index_of_dict(key++, dict) == -1)
			return (DICT_ERROR);
	while (key < 100)
	{
		if (ft_index_of_dict(key, dict) == -1)
			return (DICT_ERROR);
		key += 10;
	}
	if (ft_index_of_dict(key, dict) == -1)
		return (DICT_ERROR);
	key *= 10;
	while (--max)
	{
		if (ft_index_of_dict(key, dict) == -1)
			return (DICT_ERROR);
		key *= 1000;
	}
	return (SUCCESS);
}
