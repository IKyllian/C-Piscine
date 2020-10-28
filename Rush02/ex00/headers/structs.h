/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:33:18 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/25 15:41:31 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef __uint128_t	t_u128;
typedef	struct		s_entry
{
	t_u128			value;
	char			*str;
}					t_entry;
typedef	struct		s_config
{
	int				dash;
	int				comma;
	char			*first;
	char			*liaison;
	char			*first_after_thousand;
	char			*dict_uri;
	t_entry			*dict;
}					t_config;
#endif
