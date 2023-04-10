/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:33:11 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/10 01:15:55 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rrotate_ab(t_stack_a **stack)
{
	t_stack_a	*temp;
	t_stack_a	*last;
	t_stack_a	*last1;

	last = *stack;
	while (last && last->next != NULL)
		last = last->next;
	last1 = *stack;
	while (last1 && last1->next && last1->next->next != NULL)
		last1 = last1->next;
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	last1->next = NULL;
}

void	ft_rra(t_stack_a **a)
{
	ft_rrotate_ab(a);
}

void	ft_rrb(t_stack_a **b)
{
	ft_rrotate_ab(b);
}

void	ft_rrr(t_stack_a **a, t_stack_a **b)
{
	ft_rra(a);
	ft_rrb(b);
}
