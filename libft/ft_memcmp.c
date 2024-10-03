/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:58:06 by rdavurov          #+#    #+#             */
/*   Updated: 2024/04/09 10:39:42 by rdavurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*s;
	unsigned const char	*c;

	if (n == 0)
		return (0);
	i = 0;
	s = (unsigned const char *)s1;
	c = (unsigned const char *)s2;
	while (i < n && s[i] == c[i] && i < (n - 1))
		i++;
	return (s[i] - c[i]);
}
