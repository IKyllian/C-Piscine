/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:20:00 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/16 16:35:28 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_base()
{
	int i;
	int z;


	...

}

void	ft_putnbr_base(int nbr, char *base)
{
	int i;
	long nb;
	int final_number[50];
	int size_base;

	i = 0;
	size_base = 0;
	nb = nbr;
	if (check_base(base))
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		while (base[size_base])
			size_base++;
		while (nb)
		{
			final_number[i] = nb % size_base;
			nb = nb / size_base;
			i++
		}
		while (--i < 0)
		{
			ft_putchar(base[final_number[i]]);
			i--;
		}
	}
}

int		main(void)
{
	ft_putnbr_base(42, "0123456789");
	return (0);
}
