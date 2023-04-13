/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:17:14 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/13 14:44:11 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_stack_a **a)
{
	int	temp;

	if (!*a || ft_stack_size(*a) < 2)
		return ;
	temp = (*a)->count;
	(*a)->count = ((*a)->next)->count;
	((*a)->next)->count = temp;
}

void	ft_sb(t_stack_a **b)
{
	int	temp;

	if (!*b || ft_stack_size(*b) < 2)
		return ;
	temp = (*b)->count;
	(*b)->count = (*b)->next->count;
	(*b)->next->count = temp;
}

void	ft_ss(t_stack_a **a, t_stack_a **b)
{
	int	temp;

	if (!*a || !*b || ft_stack_size(*a) < 2 || ft_stack_size(*b) < 2)
		return ;
	temp = (*b)->count;
	(*b)->count = ((*b)->next)->count;
	((*b)->next)->count = temp;
	temp = (*a)->count;
	(*a)->count = ((*a)->next)->count;
	((*a)->next)->count = temp;
}
