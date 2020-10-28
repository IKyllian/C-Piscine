/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:27:40 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/11 19:07:37 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	build_wall(int x, int y)
{
	int i;
	int j;

	i = 1;
	while (++i <= y - 1)
	{
		j = 0;
		while (++j <= x)
		{
			if (j == 1 || j == x)
			{
				ft_putchar('B');
			}
			else
			{
				ft_putchar(' ');
			}
		}
		ft_putchar('\n');
	}
}

void	build_top(int x)
{
	int i;

	i = 0;
	while (++i <= x)
	{
		if (i == 1)
		{
			ft_putchar('A');
		}
		else if (i == x)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
	}
	ft_putchar('\n');
}

void	build_bottom(int x)
{
	int i;

	i = 0;
	while (++i <= x)
	{
		if (i == 1)
		{
			ft_putchar('C');
		}
		else if (i == x)
		{
			ft_putchar('A');
		}
		else
		{
			ft_putchar('B');
		}
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (!(x <= 0 || y <= 0))
	{
		build_top(x);
		build_wall(x, y);
		if (y > 1)
		{
			build_bottom(x);
		}
	}
}
