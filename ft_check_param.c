/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:26:34 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/07 01:16:00 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	ft_isnum(char *av)
{
	int	i;

	i = 0;
	while (av[i] && ((av[i] >= 9 && av[i] <= 13) || (av[i] == ' ')))
		i++;
	if ((av[i] && (av[i] == '-' || av[i] == '+')))
		i++;
	while (av[i])
	{
		if (av[i] < 48 || av[i] > 57)
			ft_error();
		i++;
	}
	return (ft_atoi(av));
}

int	ft_check_param(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_isnum(av[i]))
			return (0);
		i++;
	}
	return (1);
}
