/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:47:09 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/05 16:48:07 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_position(t_stack_a *stack_a, int index)
{
	int	i;

	i = 1;
	while (stack_a)
	{
		if (stack_a->index == index)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}
