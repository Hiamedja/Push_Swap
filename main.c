/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:40:27 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/08 18:02:10 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_stack_size(t_stack_a *stack)
// {
// 	int	i;

// 	i = 0;
// 	if (!stack)
// 		return (0);
// 	while (stack)
// 	{
// 		(stack) = (stack)->next;
// 		i++;
// 	}
// 	return (i);
// }

int	ft_check_double(t_stack_a *stack_a)
{
	t_stack_a *stack_b;
	int i, j, k;

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


void	indexing(t_stack_a **stack2, int *tab ,int size)
{
	int				i;
	t_stack_a *stack;

	stack = *stack2;
	i = 0;
	while (stack)
	{
		while(i < size)
		{
			if (stack->count == tab[i])
			{
				//printf("hello\n");
				stack->index = i;
				break;
			}
			i++;
		}
		stack = stack->next;
		i = 0;
	}
}


int	main(int ac, char **av)
{
	int		i,j;
	t_stack_a	*a;
	t_stack_a	*b;
	char	**str;
	int		*tab;
	int		sizeofstack;

	a = NULL;
	if (ac < 2)
		return (0);
	i = 1;
	while (av[i])
	{
		j = 0;
		str = ft_split(av[i], ' ');
		if (ft_check_param(str) == 0)
			ft_error();
		while (str[j])
			ft_lstadd_back(&a, ft_newstack(ft_atoi(str[j++])));
		i++;
	}
	if (ft_check_double(a) == -1)
		ft_error();
	if (ft_checksort(a) != 0)
		ft_error();
	sizeofstack = ft_stack_size(a);
	tab = ft_fillingtab(a, sizeofstack);
	indexing(&a, tab, sizeofstack);
	ft_sort(&a, &b, tab);
	// while (b)
	// {
	// 	printf("%d---", (b)->count);
	// 	printf("%d\n",(b)->index);
	// 	b = (b)->next;
	// }
	//printf("%d\n", ft_checksort(a));
}
