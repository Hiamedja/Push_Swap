/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:40:27 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/10 00:54:14 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_check_double(t_stack_a *stack_a)
// {
// 	t_stack_a	*stack_b;
// 	int			i;
// 	int			j;
// 	int			k;

// 	stack_b = stack_a;
// 	while (stack_b)
// 	{
// 		i = stack_b->count;
// 		stack_a = stack_b;
// 		j = 0;
// 		while (stack_a)
// 		{
// 			k = stack_a->count;
// 			if (i == k)
// 			{
// 				j++;
// 				if (j > 1)
// 					return (-1);
// 			}
// 			stack_a = stack_a->next;
// 		}
// 		stack_b = stack_b->next;
// 	}
// 	return (0);
// }

// t_stack_a	*ft_newstack(int content)
// {
// 	t_stack_a	*new_stack;

// 	new_stack = malloc(sizeof(t_stack_a));
// 	if (!new_stack)
// 		return (NULL);
// 	new_stack->count = content;
// 	new_stack->next = NULL;
// 	return (new_stack);
// }

// int	ft_checksort(t_stack_a *stack)
// {
// 	while (stack && stack->next != NULL)
// 	{
// 		if (stack->count > stack->next->count)
// 			return (0);
// 		stack = stack->next;
// 	}
// 	return (1);
// }

// void	ft_swap(int *a, int *b)
// {
// 	int	tmp;

// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

// void	sort_tab(int *tab, int len)
// {
// 	int	i;
// 	int	j;
// 	int	min;

// 	i = 0;
// 	while (i < len - 1)
// 	{
// 		min = i;
// 		j = i + 1;
// 		while (j < len)
// 		{
// 			if (tab[j] < tab[min])
// 				min = j;
// 			j++;
// 		}
// 		ft_swap(&tab[i], &tab[min]);
// 		i++;
// 	}
// }

int	*ft_fillingtab(t_stack_a *stack, int size)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	while (stack)
	{
		tab[i] = stack->count;
		stack = stack->next;
		i++;
	}
	sort_tab(tab, size);
	return (tab);
}

void	indexing(t_stack_a **stack2, int *tab, int size)
{
	int			i;
	t_stack_a	*stack;

	stack = *stack2;
	i = 0;
	while (stack)
	{
		while (i < size)
		{
			if (stack->count == tab[i])
			{
				stack->index = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
		i = 0;
	}
}

t_stack_a	*ft_parse_arguments(char **av, int ac)
{
	int			i;
	int			j;
	t_stack_a	*stack;
	char		**str;

	i = 1;
	stack = NULL;
	while (i < ac)
	{
		j = 0;
		str = ft_split(av[i], ' ');
		if (ft_check_param(str) == 0)
			ft_error();
		while (str[j])
			ft_lstadd_back(&stack, ft_newstack(ft_atoi(str[j++])));
		i++;
	}
	if (ft_check_double(stack) == -1)
		ft_error();
	if (ft_checksort(stack) != 0)
		return (0);
	return (stack);
}

int	main(int ac, char **av)
{
	int			*tab;
	t_stack_a	*a;
	t_stack_a	*b;
	int			sizeofstack;

	a = NULL;
	if (ac < 2)
		return (0);
	a = ft_parse_arguments(av, ac);
	sizeofstack = ft_stack_size(a);
	tab = ft_fillingtab(a, sizeofstack);
	indexing(&a, tab, sizeofstack);
	ft_sort(&a, &b, tab);
}
/////////////////////////////.while (1);
// while (b)
// {
// 	printf("%d---", (b)->count);
// 	printf("%d\n",(b)->index);
// 	b = (b)->next;
// }
//printf("%d\n", ft_checksort(a));