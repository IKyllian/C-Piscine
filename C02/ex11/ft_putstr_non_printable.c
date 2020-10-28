/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:27:36 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/13 18:35:49 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_printable(char str)
{
	if (str >= 32 && str <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned int	a;
	unsigned char	c;
	char			*base;

	i = 0;
	base = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
		{
			write(1, &str[i], 1);
		}
		else
		{
			c = str[i];
			write(1, "\\", 1);
			a = c / 16;
			write(1, &base[a], 1);
			a = c % 16;
			write(1, &base[a], 1);
		}
		i++;
	}
}
