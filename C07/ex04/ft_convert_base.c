/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:46:39 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/28 10:16:04 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
void	put_number_positive(char *str, long *nb, int *index);
int		check_str(char str, char *base);
int		number_length(int nbr, char *base);

int		check_base(char *base)
{
	int i;
	int y;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == '\t' ||
				base[i] == '\n' || base[i] == '\r' || base[i] == '\v' ||
				base[i] == '\f' || base[i] == ' ')
			return (0);
		y = i + 1;
		while (base[y])
		{
			if (base[y] == base[i])
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

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
	check_whitespaces_signs(str, &i, &sign);
	while (check_str(str[i], base))
	{
		nbr *= size_of_base;
		nbr += check_str(str[i], base);
		i++;
	}
	return (nbr * sign);
}

char	*ft_itoa_base(int nbr, char *base, char *str)
{
	int		final_nbr[100];
	int		i;
	int		y;
	long	nb;

	i = 0;
	y = 0;
	nb = nbr;
	if (nb == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (nb < 0)
		put_number_positive(str, &nb, &y);
	while (nb)
	{
		final_nbr[i++] = nb % ft_strlen(base);
		nb = nb / ft_strlen(base);
	}
	while (--i >= 0)
		str[y++] = base[final_nbr[i]];
	str[y] = '\0';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		nb;
	int		length;

	if (!(check_base(base_from) && check_base(base_to)))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	length = number_length(nb, base_to);
	str = (char *)malloc(sizeof(*str) * (length + 1));
	if (str == NULL)
		return (NULL);
	str = ft_itoa_base(nb, base_to, str);
	return (str);
}

int		main()
{
	char str[] = "	onfQWcdgrgt45";
	printf("%s", ft_convert_base(str, "poneyvif", "0123456789"));

}
