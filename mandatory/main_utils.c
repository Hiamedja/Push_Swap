/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:43:18 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/10 00:44:18 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < len - 1)
	{
		min = i;
		j = i + 1;
		while (j < len)
		{
			if (tab[j] < tab[min])
				min = j;
			j++;
		}
		ft_swap(&tab[i], &tab[min]);
		i++;
	}
}
