/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:58:27 by scros             #+#    #+#             */
/*   Updated: 2020/10/25 19:06:54 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	read_input(t_config **config, t_u128 *num)
{
	int		input_len;
	int		error;
	char	*str;
	char	*uri;

	ft_putstr("Entrez un nombre :\n");
	if (!(str = malloc(42 * sizeof(*str))))
		return (ERROR);
	input_len = read(0, str, 41 * sizeof(*str));
	if (input_len - 1 == 0)
		return (ERROR);
	str[input_len - 1] = 0;
	ft_putstr("Entrez la langue ('");
	ft_putstr(DEFAULT_CONFIG);
	ft_putstr("' si vide) :\n");
	if (!(uri = malloc(200 * sizeof(*uri))))
		return (ERROR);
	input_len = read(0, uri, 199 * sizeof(*uri));
	if (input_len - 1 == 0)
		uri = DEFAULT_CONFIG;
	else
		uri[input_len - 1] = 0;
	if ((error = load_config(uri, config)) != SUCCESS)
		return (error);
	return (ft_atoi(str, "", num));
}

int	parse_input(int ac, char **av, t_u128 *num, t_config **config)
{
	char	*str;
	int		error;
	char	*uri;

	if (ac == 0)
	{
		error = read_input(config, num);
		ft_putstr("----------------------\n");
		return (error);
	}
	else if (ac == 1)
	{
		uri = DEFAULT_CONFIG;
		str = av[0];
	}
	else if (ac == 2)
	{
		uri = av[0];
		str = av[1];
	}
	else
		return (ERROR);
	if ((error = load_config(uri, config)) != SUCCESS)
		return (error);
	return (ft_atoi(str, "", num));
}
