/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:28:26 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/09 15:53:58 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_count(char const *s, char c)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			j = 1;
			count++;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	t_list	var;

	var.i = 0;
	var.j = 0;
	if (!s)
		return (NULL);
	var.count = ft_count(s, c);
	var.str = (char **)malloc (sizeof(char *) * (var.count + 1));
	if (!var.str)
		return (NULL);
	while (var.i < var.count)
	{
		while (s[var.j] == c)
			var.j++;
		var.x = var.j;
		while (s[var.j])
			if (s[var.j] == c)
				break ;
		else
				var.j++;
		var.str[var.i++] = ft_substr(s, var.x, var.j - var.x);
	}
	var.str[var.i] = 0;
	return (var.str);
}
