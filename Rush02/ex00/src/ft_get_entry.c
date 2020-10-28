/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:51:14 by scros             #+#    #+#             */
/*   Updated: 2020/10/25 10:31:28 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"

int	ft_get_entry(char *line, t_entry *entry)
{
	int		i;
	int		len;
	t_u128	value;

	i = -1;
	if (ft_atoi_len(line, " :", &value, &len) == ERROR)
		return (DICT_ERROR);
	line += len;
	while (*line == ':' || *line == ' ')
		line++;
	if (!ft_strlen(line))
		return (DICT_ERROR);
	entry->value = value;
	entry->str = ft_strdup(line);
	return (SUCCESS);
}
