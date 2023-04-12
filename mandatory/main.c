/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:40:27 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/12 18:09:40 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_free(char **str)
{
	int	i ;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
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
		if (str[j] == '\0')
			ft_error();
		if (ft_check_param(str) == 0)
			ft_error();
		while (str[j])
			ft_lstadd_back(&stack, ft_newstack(ft_atoi(str[j++])));
		i++;
		ft_free(str);
	}
	if (ft_check_double(stack) == -1)
		ft_error();
	if (ft_checksort(stack) != 0)
		exit(EXIT_SUCCESS);
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
	free(tab);
	system("leaks push_swap");
}
