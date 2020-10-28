/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:50:41 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/07 18:56:33 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int first;
	int second;
	int third;

	first = '0' - 1;
	while (++first <= '7')
	{
		second = first;
		while (++second <= '8')
		{
			third = second;
			while (++third <= '9')
			{
				write(1, &first, 1);
				write(1, &second, 1);
				write(1, &third, 1);
				if (first != '7' || second != '8' || third != '9')
				{
					write(1, ",", 1);
					write(1, " ", 1);
				}
			}
		}
	}
}
