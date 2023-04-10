/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:40:27 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/10 16:35:17 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		if (ft_check_param(str) == 0)
			ft_error();
		while (str[j])
			ft_lstadd_back(&stack, ft_newstack(ft_atoi(str[j++])));
		i++;
		ft_free(str);
	}
	if (ft_check_double(stack) == -1)
		ft_error();
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack_a	*a;
	t_stack_a	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	a = ft_parse_arguments(av, ac);
	ft_checker(&a, &b);
	if (ft_checksort(a) != 0 && ft_stack_size(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	system("leaks checker");
}
