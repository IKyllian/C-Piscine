/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:34:09 by scros             #+#    #+#             */
/*   Updated: 2020/10/25 17:49:34 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"

int		ft_index_of_dict(t_u128 c, t_entry *dict)
{
	int i;

	i = -1;
	while (dict[++i].str)
	{
		if (c == dict[i].value)
			return (i);
	}
	return (-1);
}

int		load_dict(char *uri, t_entry **dict)
{
	char	**lines;
	t_entry	entry;
	char	*buf;
	int		len;
	int		i;

	if (ft_orc(uri, &buf) != SUCCESS)
		return (ERROR);
	lines = ft_split(buf, "\n", &len);
	if (!(*dict = malloc((len + 1) * sizeof(**dict))))
		return (ERROR);
	i = -1;
	while (lines[++i])
	{
		if (ft_get_entry(lines[i], &entry) != SUCCESS)
			return (DICT_ERROR);
		(*dict)[i] = entry;
	}
	return (validate(*dict));
}

void	errors(int error)
{
	if (error == ERROR)
		ft_putstr(ERROR_MSG);
	else if (error == CONFIG_ERROR)
		ft_putstr(CONFIG_ERROR_MSG);
	else if (error == DICT_ERROR)
		ft_putstr(DICT_ERROR_MSG);
}

void	free_all(t_config *config)
{
	int i;

	i = -1;
	while (config->dict[++i].str)
	{
		free(config->dict[i].str);
	}
	free(config->dict);
	free(config);
}

int		main(int ac, char **av)
{
	t_entry		*dict;
	int			error;
	t_config	*config;
	t_u128		num;

	if ((error = parse_input(ac - 1, av + 1, &num, &config)) == SUCCESS)
	{
		if ((error = load_dict(config->dict_uri, &dict)) == SUCCESS)
		{
			config->dict = dict;
			print_number(num, config);
			ft_putstr("\n");
			free_all(config);
			return (0);
		}
	}
	errors(error);
	return (0);
}
