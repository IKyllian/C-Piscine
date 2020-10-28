/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 10:19:54 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/11 10:06:18 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		if (size > 0 && i < size - 1)
		{
			dest[j++] = src[i];
		}
		i++;
	}
	if (size > 0)
	{
		dest[j] = '\0';
	}
	return (i);
}
