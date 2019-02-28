/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:43:48 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/17 21:57:46 by glafond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_save_tab(int *tab, int *soluce)
{
	int		*cpytab;
	int		*cpysoluce;

	cpytab = tab;
	cpysoluce = soluce;
	while (*cpytab != -1)
		*cpysoluce++ = *cpytab++;
}

int		ft_check_soluce(int *tab, int *soluce)
{
	if (!*soluce)
	{
		ft_save_tab(tab, soluce);
		return (1);
	}
	else
		return (0);
}

int		ft_resolve(int *tab, int *tab_index, int *soluce)
{
	int		result[9];
	int		*cpyresult;

	cpyresult = result;
	while (cpyresult < result + 9)
		*cpyresult++ = 0;
	if (*tab_index == -1 && !ft_check_soluce(tab, soluce))
		return (-1);
	if (*tab_index == -1)
		return (0);
	ft_check(tab, result, *tab_index);
	cpyresult = result;
	while (cpyresult < result + 9)
	{
		if (!*cpyresult)
		{
			*(tab + *tab_index) = cpyresult - result + 1;
			if (ft_resolve(tab, tab_index + 1, soluce) == -1)
				return (-1);
		}
		cpyresult++;
	}
	*(tab + *tab_index) = 0;
	return (0);
}
