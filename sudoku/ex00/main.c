/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 10:53:46 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/17 21:49:18 by glafond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "sudoku.h"

void	ft_init(int *tab, int *tab_index)
{
	int		*cpytab;
	int		*cpytab_index;
	int		temp[82];
	int		*cpytemp;

	cpytab = tab;
	cpytab_index = tab_index;
	cpytemp = temp;
	while (cpytemp < temp + 82)
		*cpytemp++ = 0;
	cpytemp = temp;
	while (*cpytab != -1)
	{
		if (*cpytab == 0)
		{
			*cpytemp = ft_find_nbrs(tab, cpytab - tab);
		}
		cpytemp++;
		cpytab++;
	}
	ft_sort_index(tab_index, temp);
}

int		ft_find_nbrs(int *tab, int index)
{
	int		result[9];
	int		*cpyresult;
	int		nbrs;

	cpyresult = result;
	nbrs = 0;
	while (cpyresult < result + 9)
		*cpyresult++ = 0;
	ft_check(tab, result, index);
	cpyresult = result;
	while (cpyresult < result + 9)
	{
		if (!*cpyresult)
			nbrs++;
		cpyresult++;
	}
	return (nbrs);
}

void	ft_sort_index(int *tab_index, int *tab_temp)
{
	int		*cpytab_index;
	int		*cpytab_temp;
	int		nbr_soluce;

	cpytab_index = tab_index;
	nbr_soluce = 1;
	while (nbr_soluce <= 9)
	{
		cpytab_temp = tab_temp;
		while (cpytab_temp < tab_temp + 81)
		{
			if (*cpytab_temp == nbr_soluce)
			{
				*cpytab_index = cpytab_temp - tab_temp;
				cpytab_index++;
				*cpytab_index = -1;
			}
			cpytab_temp++;
		}
		nbr_soluce++;
	}
	*cpytab_index = -1;
}

int		main(int ac, char **av)
{
	int		tab[82];
	int		soluce[82];
	int		tab_index[82];
	int		*cpytab;

	cpytab = tab;
	*cpytab = -1;
	if (!ft_tab(tab, ac, av))
		return (ft_error());
	if (!ft_check_full(tab))
	{
		ft_print_tab(tab);
		return (0);
	}
	ft_init(tab, tab_index);
	if (ft_resolve(tab, tab_index, soluce) == -1)
		return (ft_error());
	else
		ft_print_tab(soluce);
	return (0);
}

int		ft_check_full(int *tab)
{
	int		*cpytab;

	cpytab = tab;
	while (cpytab - tab < 82)
	{
		if (!*cpytab)
			return (1);
		cpytab++;
	}
	return (0);
}
