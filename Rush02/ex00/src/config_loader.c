/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:31:25 by scros             #+#    #+#             */
/*   Updated: 2020/10/25 19:29:05 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "globals.h"

int		parse_bool(char *bool)
{
	return (ft_strcmp(bool, "true") == 0);
}

int		parse_line(char *line, t_config *config)
{
	int		current_len;
	char	*key;

	key = ft_split(line, " :", &current_len)[0];
	while (*line != ':' && *line != ' ')
		line++;
	while (*line == ':' || *line == ' ')
		line++;
	if (!ft_strlen(line))
		return (DICT_ERROR);
	if (ft_strcmp(key, "dictionaries") == 0)
		config->dict_uri = line;
	else if (ft_strcmp(key, "dash") == 0)
		config->dash = parse_bool(line);
	else if (ft_strcmp(key, "comma") == 0)
		config->comma = parse_bool(line);
	else if (ft_strcmp(key, "liaison") == 0)
		config->liaison = line;
	else if (ft_strcmp(key, "first_word") == 0)
		config->first = line;
	else if (ft_strcmp(key, "first_word_after_thousand") == 0)
		config->first_after_thousand = line;
	return (SUCCESS);
}

int		parse_config(char *buf, t_config *config)
{
	int		current_len;
	char	**lines;
	int		i;

	i = -1;
	lines = ft_split(buf, "\n", &current_len);
	config->comma = 0;
	config->dash = 0;
	config->first = "";
	config->liaison = "";
	config->first_after_thousand = "";
	while (lines[++i])
	{
		parse_line(lines[i], config);
	}
	return (SUCCESS);
}

char	*str_to_lang(char *str)
{
	char *path[3];

	if (ft_ends_with(".conf", str))
		return (str);
	path[0] = "resources/lang/";
	path[1] = str;
	path[2] = ".conf";
	return (ft_strjoin(3, path, ""));
}

int		load_config(char *uri, t_config **config)
{
	int		error;
	int		override;
	char	*config_uri;
	char	*buf;

	override = 0;
	if (ft_ends_with(".txt", uri) ||
		ft_ends_with(".dict", uri) ||
		ft_ends_with(".dict.txt", uri))
	{
		config_uri = DEFAULT_CONFIG;
		override = 1;
	}
	else
		config_uri = str_to_lang(uri);
	if ((error = ft_orc(config_uri, &buf)) != SUCCESS)
		return (error);
	if (!(*config = malloc(sizeof(**config))))
		return (ERROR);
	parse_config(buf, *config);
	if (override)
		(*config)->dict_uri = uri;
	return (SUCCESS);
}
