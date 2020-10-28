/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:48:59 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/21 14:50:17 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		base_is_ok(char *base)
{
	int i;
	int z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[z] != '\0')
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		size_of_base;
	int		final_nbr[100];
	int		i;
	long	nb;

	i = 0;
	size_of_base = ft_strlen(base);
	nb = nbr;
	if (!base_is_ok(base))
		return ;
	if (nb == 0)
		ft_putchar(base[0]);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (nb)
	{
		final_nbr[i++] = nb % size_of_base;
		nb = nb / size_of_base;
	}
	while (--i >= 0)
		ft_putchar(base[final_nbr[i]]);
}

int main()
{
	ft_putnbr_base(42, "0123456789abcdef");

}
