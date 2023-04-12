/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:03:01 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/11 21:38:18 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	lst_addfront(t_stack_a **stack_a, t_stack_a *new)
{
	if (*stack_a)
	{
		new->next = *stack_a;
		*stack_a = new;
	}
	else
	{
		*stack_a = new;
		new->next = NULL;
	}
}

void	ft_pb(t_stack_a **a, t_stack_a **b)
{
	t_stack_a	*temp;

	if (!*a || ft_stack_size(*a) < 1)
		return ;
	else
	{
		temp = (*a);
		(*a) = (*a)->next;
		temp->next = NULL;
		lst_addfront(b, temp);
	}
}

void	ft_pa(t_stack_a **a, t_stack_a **b)
{
	t_stack_a	*temp;

	if (!*b || ft_stack_size(*b) < 1)
		return ;
	else
	{
		temp = (*b);
		(*b) = (*b)->next;
		temp->next = NULL;
		lst_addfront(a, temp);
	}
}
