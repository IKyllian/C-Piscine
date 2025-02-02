/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:17:43 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/18 16:33:27 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;
	int max;

	i = 1;
	max = nb / 2 + 1;
	if (nb < 0)
		return (0);
	if (max > 46340)
		max = 46340;
	while (i <= max)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
