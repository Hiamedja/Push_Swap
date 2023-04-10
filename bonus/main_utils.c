/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:16:38 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/10 15:14:27 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	ft_check_double(t_stack_a *stack_a)
{
	t_stack_a	*stack_b;
	int			i;
	int			j;
	int			k;

	stack_b = stack_a;
	while (stack_b)
	{
		i = stack_b->count;
		stack_a = stack_b;
		j = 0;
		while (stack_a)
		{
			k = stack_a->count;
			if (i == k)
			{
				j++;
				if (j > 1)
					return (-1);
			}
			stack_a = stack_a->next;
		}
		stack_b = stack_b->next;
	}
	return (0);
}

t_stack_a	*ft_newstack(int content)
{
	t_stack_a	*new_stack;

	new_stack = malloc(sizeof(t_stack_a));
	if (!new_stack)
		return (NULL);
	new_stack->count = content;
	new_stack->next = NULL;
	return (new_stack);
}

int	ft_checksort(t_stack_a *stack)
{
	while (stack && stack->next != NULL)
	{
		if (stack->count > stack->next->count)
			return (0);
		stack = stack->next;
	}
	return (1);
}
