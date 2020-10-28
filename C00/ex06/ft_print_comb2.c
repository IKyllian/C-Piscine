/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:17:43 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/07 19:27:02 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int n)
{
	int		n1;
	int		n2;
	char	print_n1;
	char	print_n2;

	n1 = n / 10;
	n2 = n % 10;
	print_n1 = 48 + n1;
	print_n2 = 48 + n2;
	write(1, &print_n1, 1);
	write(1, &print_n2, 1);
}

void	ft_print_comb2(void)
{
	int numbers[2];

	numbers[0] = 0;
	while (numbers[0] <= 98)
	{
		numbers[1] = numbers[0] + 1;
		while (numbers[1] <= 99)
		{
			print_number(numbers[0]);
			write(1, " ", 1);
			print_number(numbers[1]);
			if (numbers[0] != 98 || numbers[1] != 99)
			{
				write(1, ",", 1);
				write(1, " ", 1);
			}
			numbers[1]++;
		}
		numbers[0]++;
	}
}
