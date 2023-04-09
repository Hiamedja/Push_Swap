/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:08:41 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/08 00:39:55 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	m;
	char	*str;

	i = 0;
	m = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		m = ft_strlen(s) - start;
	if (m > len)
		m = len;
	str = malloc(sizeof(char) * (m + 1));
	if (!str)
		return (NULL);
	while (i < m && s[start] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
