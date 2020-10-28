/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:42:35 by pgoudet           #+#    #+#             */
/*   Updated: 2020/10/18 16:11:16 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

typedef struct coordonnee_point
{
	int x;
	int y;
}				coordonnee_point;

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_atoi_itoa(char *str)
{
	int i;
	char *c;
	int j;

	i = 0;
	j = 0;
	c = malloc(16);
	while (str[i])
	{
		if(str[i] >= '1' && str[i] <= '4')
			c[j++] = str[i];
		i++;
	}
	c[j] = 0;
	return (c);
}

int	is_correct(char *c)
{
	if(ft_strlen(c) != 15)
		return (0);
	return (1);
}

int ***contour_tab(char *c)
{
	int i;
	int tab[4][4][4];
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while(j < 4)
		{
			tab[i][j] = c[k] - 48;
			k++;
			j++;
		}
		i++;
	}
	return (tab);
}

int	verif_contour(int ***tab)
{
	int i;
	int j;


	i = 0;
	j = 3;
	while (i < 4 && j >= 0)
	{
		if(verif_combinaison(tab[0][i], tab[2][j]) &&
			   	verif_combinaison(tab[1][i], tab[3][j]))
		{
			j--;
			i++;
		}
		else
			return (0);
	}
	return (1);
}


int	verif_combinaison(int a, int b)
{
	if ((a == 4 && b == 1) || (b == 4 && a == 1))
		return (1);
	else if ((a == 2 && b == 2))
		return (1);
	else if ((a == 3 && b == 2) || (b == 3 && a == 2))
		return (1);
	else if ((a == 1 && b == 2) || (b == 1 && a == 2))
		return (1);
	else if ((a == 3 && b == 1) || (a == 1 && b == 3))
		return (1);
	else
		return (0);
}int	search_opp(int k)
{
	return (3 - k);
}


coordonnee_point	*cherche_les_chats(char *c)
{
	int i;
	coordonnee_point *tab;
	int j;

	j = count_cat(c);
	tab = malloc(j);
	i = -1;
	while (++i < 15)
	{
		if (c[i] == '4')
		{
			tab[i].x= i / 4;
			tab[i].y= i % 4;
		}
	}
	return (tab);
}

int		count_cat(char *c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 15)
	{
		if (c[i] == '4')
		j++;
		i++;
	}
	return (j);
}

void	display(int ***tab)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			if (j == 4)
				ft_putchar('\n');
			else
				ft_putchar(tab[1][i][j]);
		}
		i++;
	}
}


void	remplir_tableau_serie(char *c, int ***tab)
{
	coordonnee_point *t;
	int j;
	int i;
	int k;

	j = count_cat(c);
	t = malloc(j);
	t = cherche_les_chats(c);
	i = 1;
	while (i < j)
	{
		k = 1;
		while (k < 5)
		{
			tab[t[i].x][t[i].y][k] = k;
			tab[t[i].x + 2][3 - t[i].y][3 - k] = k;
			tab[t[i].x + 1][k - 1][k] = k;
			tab[t[i].x +3][3 - k - 1][3 - k] = k;
			k++;
		}
	}
}

int	count_int(int nb, int ***tab)
{
	int i;
	int j;
	int compt;

	i = 0;
	j = 0;
	compt = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[0][i][j] == nb)
				compt++;
			j++;
		}
		j = 0;
		i++;
	}
	return (compt);
}

coordonnee_point *cherche_nb(int ***tab, int nb)
{
	int i;
	int j;
	coordonnee_point *t;
	int k;

	
	i = -1;
	j = 0;
	k = 0;
	t = malloc(count_int(nb), tab);
	while (++i < 4)
	{
		while (j < 4)
		{
			if (tab[0][i][j] == nb)
			{
				t[k].x = i;
				t[k].y = j;
				k++;
			}
			j++;
		}
		j = 0;
	}
	return (t);
}

int	check_args(char *str)
{
	char *contour;
	int ***tab;

	contour = ft_atoi_itoa(str);
	tab = contour_tab(contour);
	if (verif_contour(tab) || is_correct(contour))
		return (1);
	else
		return (0);
}



int	main(int argc, int **argv)
{
	int ***tab;

	tab = contour_tab(argv[1]);
	if(argc != 2)
	{
		ft_putstr("error too many arg\n");
		return (0);
	}
	if (!check_args(argv[1]))
	{
		ft_putstr("error\n");
		return (0);
	}
	remplir_tableau_serie(argv[1], tab);
	//
	////
	//
	//
	display(tab);
	return (0);
}





