/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:19:20 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/11 17:19:43 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack_a *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		(stack) = (stack)->next;
		i++;
	}
	return (i);
}

void	ft_sort2(t_stack_a *stack)
{
	ft_sa(&stack);
	while (stack)
	{
		stack = stack->next;
	}
}

void	ft_sort3(t_stack_a **a)
{
	if ((*a)->count > (*a)->next->count
		&& (*a)->next->count < (*a)->next->next->count
		&& (*a)->count < (*a)->next->next->count)
		ft_sa(a);
	else if ((*a)->count < (*a)->next->count
		&& (*a)->next->count > (*a)->next->next->count
		&& (*a)->count > (*a)->next->next->count)
		ft_rra(a);
	else if ((*a)->count > (*a)->next->count
		&& (*a)->next->count < (*a)->next->next->count
		&& (*a)->count > (*a)->next->next->count)
		ft_ra(a);
	else if ((*a)->count > (*a)->next->count
		&& (*a)->next->count > (*a)->next->next->count)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if ((*a)->count < (*a)->next->count
		&& (*a)->next->count > (*a)->next->next->count
		&& (*a)->count < (*a)->next->next->count)
	{
		ft_sa(a);
		ft_ra(a);
	}
}

int	find_low_numb(t_stack_a *a)
{
	int	i;

	i = a->count;
	while (a)
	{
		if (a->count < i)
			i = a->count;
		a = a->next;
	}
	return (i);
}
