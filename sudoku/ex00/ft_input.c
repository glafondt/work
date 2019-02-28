/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 20:00:27 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/17 22:08:33 by glafond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		ft_add_to_tab(int *tab, char *str)
{
	int		*cpytab;
	char	*cpystr;

	cpytab = tab;
	cpystr = str;
	if (ft_strlen(str) != 9)
		return (0);
	while (*cpytab != -1)
		cpytab++;
	while (*cpystr)
	{
		if (*cpystr == '.')
			*cpytab = 0;
		else
			*cpytab = *cpystr - '0';
		cpystr++;
		cpytab++;
	}
	*cpytab = -1;
	return (1);
}

int		ft_check_input(int *tab)
{
	int		result[9];
	int		*cpyresult;
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 9)
		{
			cpyresult = result;
			while (cpyresult < result + 9)
				*cpyresult++ = 0;
			if (!ft_check_result(tab, result, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_check_result(int *tab, int *result, int condition, int index)
{
	int		*cpyresult;

	if (!condition)
		ft_check_column(tab, result, index);
	if (!(condition - 1))
		ft_check_line(tab, result, index * 9);
	if (!(condition - 2))
	{
		index = (index / 3) * 9 * 3 + (index % 3) * 3;
		ft_check_square(tab, result, index);
	}
	cpyresult = result;
	while (cpyresult < result + 9)
	{
		if (*cpyresult > 1)
			return (0);
		cpyresult++;
	}
	return (1);
}

int		ft_tab(int *tab, int ac, char **av)
{
	int		counter;
	int		*cpytab;

	counter = 1;
	if (ac != 10)
		return (0);
	while (counter < ac)
	{
		if (!ft_add_to_tab(tab, av[counter]))
			return (0);
		counter++;
	}
	cpytab = tab;
	while (*cpytab != -1)
	{
		if (*cpytab < 0 || *cpytab > 9)
			return (0);
		cpytab++;
	}
	return (ft_check_input(tab));
}

int		ft_strlen(char *str)
{
	char	*cpystr;

	cpystr = str;
	while (*cpystr)
		cpystr++;
	return (cpystr - str);
}
