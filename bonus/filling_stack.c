/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:50:40 by hiamedja          #+#    #+#             */
/*   Updated: 2023/03/16 16:54:32 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstadd_back(t_stack_a **lst, t_stack_a *new)
{
	t_stack_a	*tmp;

	tmp = *lst;
	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

// t_push	*filling_stack(int ac, char **av)
// {
// 	t_push	*stack_a;
// 	long	nb;
// 	int		i;

// 	stack_a = NULL;
// 	i = 1;
// 	while (i < ac)
// 	{
// 		nb = ft_atoi(av[i]);
// 		if (nb > 2147483647 || nb < -2147483647 -1)
// 			ft_error(&stack_a, NULL);
// 		if (i == 1)
// 			stack_a = ft_newstack((int)nb);
// 		else
// 			ft_lstadd_back(&stack_a, ft_newstack((int)nb));
// 		i++;
// 	}
// 	return (stack_a);
// }

// char	**filling_stack(int ac, char **av)
// {
// 	char	**str;

// 	if (ac == 2)
// 	{
// 		str = ft_split(av[1], ' ');
// 		return (str);
// 	}
// 	else
// 		return (av + 1);
// }

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	i++;
// 	return (i);
// }
