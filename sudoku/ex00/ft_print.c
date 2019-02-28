/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 10:49:39 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/17 15:20:54 by glafond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(int *tab)
{
	int		*cpytab;

	cpytab = tab;
	while (cpytab < tab + 81)
	{
		if (!*cpytab)
			ft_putchar('.');
		else
			ft_putchar(*cpytab + '0');
		cpytab++;
		if (!((cpytab - tab) % 9))
			ft_putchar('\n');
		else
			ft_putchar(' ');
	}
}

int		ft_error(void)
{
	write(1, "Error\n", 6);
	return (-1);
}
