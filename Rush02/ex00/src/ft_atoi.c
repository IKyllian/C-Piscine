/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:33:25 by scros             #+#    #+#             */
/*   Updated: 2020/10/25 18:06:40 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"

int	ft_atoi(char *str, char *end, t_u128 *result)
{
	int a;

	return (ft_atoi_len(str, end, result, &a));
}

int	ft_atoi_len(char *str, char *end, t_u128 *result, int *len)
{
	t_u128	num;
	int		i;

	num = 0;
	i = 0;
	if (str[i] == '-')
	{
		i++;
		return (ERROR);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	*len = i;
	if (str[i] && (ft_index_of(str[i], end) == -1)
		&& (str[i] < '0' || str[i] > '9'))
		return (ERROR);
	*result = num;
	return (SUCCESS);
}
