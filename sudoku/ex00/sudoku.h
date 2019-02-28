/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:33:20 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/17 22:06:10 by glafond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

void	ft_check_square(int *tab, int *result, int index);
void	ft_check_column(int *tab, int *result, int index);
void	ft_check_line(int *tab, int *result, int index);
void	ft_check(int *tab, int *result, int index);
int		ft_resolve(int *tab, int *tab_index, int *soluce);
void	ft_putchar(char c);
void	ft_print_tab(int *tab);
int		ft_error(void);
int		ft_add_to_tab(int *tab, char *str);
int		ft_check_result(int *tab, int *result, int condition, int index);
int		ft_tab(int *tab, int ac, char **av);
void	ft_sort_index(int *tab_index, int *tab_temp);
int		ft_find_nbrs(int *tab, int index);
int		ft_check_full(int *tab);
int		ft_strlen(char *str);

#endif
