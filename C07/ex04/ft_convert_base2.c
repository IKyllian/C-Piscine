/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:37:04 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/28 10:16:05 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	put_number_positive(char *str, long *nb, int *index)
{
	str[*index] = '-';
	*nb = -*nb;
	*index += 1;
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

int		number_length(int nbr, char *base)
{
	int nbr_length;
	int base_length;

	nbr_length = 0;
	base_length = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		nbr_length++;
	}
	while (base[base_length])
		base_length++;
	while (nbr >= base_length)
	{
		nbr /= base_length;
		nbr_length++;
	}
	return (++nbr_length);
}
