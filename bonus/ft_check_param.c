/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:26:34 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/09 17:30:56 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isnum(char *av)
{
	int	i;
	long long	nb;

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
	nb = ft_atoi(av);
	if (nb > 2147483647 || nb < -2147483648)
		ft_error();
	return (1);
}

int	ft_check_param(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isnum(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
