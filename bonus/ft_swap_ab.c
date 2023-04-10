/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:17:14 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/10 01:16:12 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_stack_a **a)
{
	int	temp;

	temp = (*a)->count;
	(*a)->count = ((*a)->next)->count;
	((*a)->next)->count = temp;
}

void	ft_sb(t_stack_a **b)
{
	int	temp;

	temp = (*b)->count;
	(*b)->count = (*b)->next->count;
	(*b)->next->count = temp;
}

void	ft_ss(t_stack_a **a, t_stack_a **b)
{
	if (((*a)->count < 2) && ((*b)->count < 2))
		return ;
	ft_sa(&(*a)->next);
	ft_sb(&(*b)->next);
}
