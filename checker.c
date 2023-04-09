/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:24:11 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/08 23:35:31 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(t_stack_a **stack_a, t_stack_a **stack_b, char *str)
{
	if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
		ft_sa(stack_a);
	else if (str[0] == 'r' && str[1] == 'a' && str[2] == '\n')
		ft_ra(stack_a);
	else if (str[0] == 'p' && str[1] == 'a' && str[2] == '\n')
		ft_pa(stack_a, stack_b);
	else if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
		ft_sb(stack_b);
	else if (str[0] == 'r' && str[1] == 'b' && str[2] == '\n')
		ft_rb(stack_b);
	else if (str[0] == 'p' && str[1] == 'b' && str[2] == '\n')
		ft_pb(stack_a, stack_b);
	else if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
		ft_ss(stack_a, stack_b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
		ft_rr(stack_a, stack_b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\n')
		ft_rra(stack_a);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\n')
		ft_rrb(stack_b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\n')
		ft_rrr(stack_a, stack_b);
	else
		ft_error();
}

void	ft_checker(t_stack_a **stack_a, t_stack_a **stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		ft_check(stack_a, stack_b, str);
		free(str);
	}
}
