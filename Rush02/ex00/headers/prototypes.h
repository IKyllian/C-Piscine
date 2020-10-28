/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:29:35 by kdelport          #+#    #+#             */
/*   Updated: 2020/10/25 19:13:17 by scros            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

int				ft_index_of_dict(t_u128 c, t_entry *dict);
void			print_triple_2(t_u128 *a, t_config *b, t_u128 *c, t_u128 *d);
void			print_triple(t_u128 *a, t_config *b, t_u128 *c, t_u128 *d);
void			print_number(t_u128 nbr, t_config *config);
int				ft_ends_with(char *end, char *str);
int				ft_get_entry(char *line, t_entry *entry);
int				ft_atoi_len(char *str, char *end, t_u128 *result, int *len);
int				parse_input(int ac, char **av, t_u128 *num, t_config **config);
int				ft_index_of(char c, char *str);
int				load_config(char *uri, t_config **config);
char			*ft_strjoin(int size, char **strs, char *sep);
char			**ft_split(char *str, char *charset, int *len);
char			*ft_strdup(char *src);
void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);
unsigned int	ft_strlen(char *str);
int				validate(t_entry *dict);
t_u128			ft_power(t_u128 nb, t_u128 power);
int				ft_atoi(char *str, char *end, t_u128 *result);
int				ft_orc(char *uri, char **buf);
void			next(t_u128 nbr, t_config *config);

#endif
