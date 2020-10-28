/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:01:13 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/21 17:17:57 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int dlength;

	i = 0;
	dlength = 0;
	while (dest[dlength] == '\0')
		dlength++;
	while (i + dlength + 1 < size && src[i] != '\0')
	{
		dest[dlength + i] = src[i];
		i++;
	}
	if (dlength != size)
		dest[dlength + i] = '\0';
	return (dlength + ft_strlen(src));
}
