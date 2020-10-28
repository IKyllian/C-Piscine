/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:27:53 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/28 10:15:54 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	check_whitespaces_signs(char *str, int *i, int *sign)
{
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\r' ||
		str[*i] == '\v' || str[*i] == '\f' || str[*i] == ' ')
	{
		*i = *i + 1;
	}
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign *= -1;
		*i = *i + 1;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
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
		if (base[i] == '+' || base[i] == '-' || base[i] == '\t' ||
			base[i] == '\n' || base[i] == '\r' || base[i] == '\v' ||
			base[i] == '\f' || base[i] == ' ')
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

int		check_str(char str, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int nbr;
	int sign;
	int size_of_base;

	i = 0;
	sign = 1;
	nbr = 0;
	size_of_base = ft_strlen(base);
	if (!base_is_ok(base))
		return (0);
	check_whitespaces_signs(str, &i, &sign);
	while (check_str(str[i], base))
	{
		nbr *= size_of_base;
		nbr += check_str(str[i], base);
		i++;
	}
	return (nbr * sign);
}
