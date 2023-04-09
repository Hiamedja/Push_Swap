/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:03:01 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/08 23:25:55 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stack_a *temp;

	if (!*a)
		return ;
	else
	{
		temp = (*a);
		(*a) = (*a)->next;
		temp->next = NULL;
		lst_addfront(b, temp);
	}
	write(1, "pb\n", 3);
}

void	ft_pa(t_stack_a **a, t_stack_a **b)
{
	t_stack_a	*temp;

	if (!*b)
		return ;
	else
	{
		temp = (*b);
		(*b) = (*b)->next;
		temp->next = NULL;
		lst_addfront(a, temp);
	}
	write(1, "pa\n", 3);
}
