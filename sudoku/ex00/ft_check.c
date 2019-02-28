/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:30:23 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/17 17:58:08 by glafond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_check(int *tab, int *result, int index)
{
	ft_check_line(tab, result, index);
	ft_check_column(tab, result, index);
	ft_check_square(tab, result, index);
}

void	ft_check_line(int *tab, int *result, int index)
{
	int		line_i;
	int		*tab_start;
	int		*tab_end;

	line_i = (index / 9) * 9;
	tab_start = tab + line_i;
	tab_end = tab_start;
	while (tab_end < tab_start + 9)
	{
		if (*tab_end)
			*(result + *tab_end - 1) += 1;
		tab_end++;
	}
}

void	ft_check_column(int *tab, int *result, int index)
{
	int		column_i;
	int		*tab_start;
	int		*tab_end;

	column_i = (index % 9);
	tab_start = tab + column_i;
	tab_end = tab_start;
	while (tab_end < tab_start + 9 * 9)
	{
		if (*tab_end)
			*(result + *tab_end - 1) += 1;
		tab_end += 9;
	}
}

void	ft_check_square(int *tab, int *result, int index)
{
	int		square_i;
	int		*tab_start;
	int		*tab_end;

	square_i = (index / 9) / 3 * 3 * 9 + (index % 9) / 3 * 3;
	tab_start = tab + square_i;
	tab_end = tab_start;
	while (tab_end < tab_start + 2 * 9 + 3)
	{
		while ((tab_end - tab_start) % 9 <= 2)
		{
			if (*tab_end)
				*(result + *tab_end - 1) += 1;
			tab_end++;
		}
		tab_end = tab_end - 3 + 9;
	}
}
