/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dict_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 13:21:16 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/25 17:52:15 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"

void	hundred_2(t_u128 *nbr, t_config *config, t_u128 *index)
{
	if ((*index = ft_index_of_dict(100, config->dict)) != -1)
	{
		ft_putstr(config->dict[*index].str);
		if (*nbr / 100 * 100 != *nbr)
			ft_putstr(" ");
	}
	if (*nbr - (*nbr / 100) * 100 > 0)
	{
		if (*(config->liaison))
		{
			ft_putstr(config->liaison);
			ft_putstr(" ");
		}
		next(*nbr - (*nbr / 100) * 100, config);
	}
}

void	hundred(t_u128 *nbr, t_config *config, t_u128 *index)
{
	if ((*index = ft_index_of_dict((*nbr / 100), config->dict)) != -1)
	{
		if (*index == 1)
		{
			if (*(config->first))
			{
				ft_putstr(config->first);
				ft_putstr(" ");
			}
		}
		else
		{
			ft_putstr(config->dict[*index].str);
			ft_putstr(" ");
		}
	}
	hundred_2(nbr, config, index);
}

void	next(t_u128 nbr, t_config *config)
{
	t_u128 index;

	if ((index = ft_index_of_dict(nbr, config->dict)) != -1)
	{
		ft_putstr(config->dict[index].str);
		return ;
	}
	if (nbr < 100)
	{
		if ((index = ft_index_of_dict((nbr / 10) * 10, config->dict)) != -1)
		{
			ft_putstr(config->dict[index].str);
			if (config->dash)
				ft_putstr("-");
			else
				ft_putstr(" ");
		}
		if (nbr - (nbr / 10) * 10 > 0)
			next(nbr - (nbr / 10) * 10, config);
	}
	else
	{
		hundred(&nbr, config, &index);
	}
}

void	print_preset(t_config *config, t_u128 nbr, t_u128 pow, t_u128 index)
{
	if (nbr / pow * pow == nbr)
	{
		if (nbr > 1000 && (*(config->first_after_thousand)))
		{
			ft_putstr(config->first_after_thousand);
			ft_putstr(" ");
		}
		else if (nbr > 99 && (*(config->first)))
		{
			ft_putstr(config->first);
			ft_putstr(" ");
		}
	}
	ft_putstr(config->dict[index].str);
}

void	print_number(t_u128 nbr, t_config *config)
{
	t_u128	j;
	t_u128	cpy;
	t_u128	pow;
	t_u128	index;

	j = 0;
	cpy = nbr;
	while ((cpy /= 1000) > 0)
		j++;
	if ((index = ft_index_of_dict(nbr, config->dict)) != -1)
	{
		print_preset(config, nbr, ft_power(1000, j), index);
		return ;
	}
	while (1)
	{
		pow = ft_power(1000, j);
		print_triple(&nbr, config, &pow, &index);
		if (j == 0)
			break ;
		j--;
	}
}
