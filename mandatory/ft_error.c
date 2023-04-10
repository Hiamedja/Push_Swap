/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:02:47 by hiamedja          #+#    #+#             */
/*   Updated: 2023/03/13 15:14:52 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freestack(t_stack_a **stack)
{
	t_stack_a	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	stack = NULL;
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
