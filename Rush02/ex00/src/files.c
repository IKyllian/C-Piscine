/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:53:53 by scros             #+#    #+#             */
/*   Updated: 2020/10/25 17:45:23 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "globals.h"

int	ft_open(char *uri)
{
	return (open(uri, O_RDONLY));
}

int	ft_read(int file, char **buf)
{
	char	tmp[BUF_SIZE];
	int		len;

	len = read(file, tmp, BUF_SIZE);
	tmp[len] = 0;
	*buf = tmp;
	return (len);
}

/*
** Open, Read, and Close the file.
** Returns the length of the buffer, -1 if an error occurs.
*/

int	ft_orc(char *uri, char **buf)
{
	int fd;

	if ((fd = ft_open(uri)) == -1)
		return (ERROR);
	ft_read(fd, buf);
	if (close(fd) == -1)
		return (ERROR);
	return (SUCCESS);
}
