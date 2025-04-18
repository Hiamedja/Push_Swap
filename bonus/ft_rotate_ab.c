/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:19:16 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/12 18:18:10 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate_ab(t_stack_a **stack)
{
	t_stack_a	*temp;
	t_stack_a	*last;

	temp = *stack;
	(*stack) = (*stack)->next;
	last = *stack;
	while (last && last->next != NULL)
		last = last->next;
	temp->next = NULL;
	last->next = temp;
}

void	ft_ra(t_stack_a **a)
{
	if (!*a || ft_stack_size(*a) < 2)
		return ;
	ft_rotate_ab(a);
}

void	ft_rb(t_stack_a **b)
{
	if (!*b || ft_stack_size(*b) < 2)
		return ;
	ft_rotate_ab(b);
}

void	ft_rr(t_stack_a **a, t_stack_a **b)
{
	if (!*a || ft_stack_size(*a) < 2 || !*b || ft_stack_size(*b) < 2)
		return ;
	ft_rotate_ab(a);
	ft_rotate_ab(b);
}
