/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_triple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:45:47 by scros             #+#    #+#             */
/*   Updated: 2020/10/25 17:46:36 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"

void	print_triple_2(t_u128 *nbr, t_config *config, t_u128 *pow, t_u128 *i)
{
	int div;

	div = *nbr / *pow;
	if (div)
	{
		*nbr -= div * *pow;
		if ((div != 1 || *(config->first)) && *nbr > 0)
			ft_putstr(" ");
		if (*pow != 1 && (*i = ft_index_of_dict(*pow, config->dict)) != -1)
		{
			if (*nbr == 0)
				ft_putstr(" ");
			ft_putstr(config->dict[*i].str);
			if (*nbr > 0)
			{
				if (config->comma)
					ft_putstr(",");
				ft_putstr(" ");
			}
		}
	}
}

void	print_triple(t_u128 *nbr, t_config *config, t_u128 *pow, t_u128 *index)
{
	int div;

	div = *nbr / *pow;
	if (div)
	{
		if (*nbr < 100 || div != 1)
			next(div, config);
		else
		{
			if (*nbr / 1000 * 1000 > 1000 && (*(config->first_after_thousand)))
			{
				ft_putstr(config->first_after_thousand);
				ft_putstr(" ");
			}
			else if ((*(config->first)))
			{
				ft_putstr(config->first);
				ft_putstr(" ");
			}
		}
		print_triple_2(nbr, config, pow, index);
	}
}
