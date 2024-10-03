/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:31:25 by rdavurov          #+#    #+#             */
/*   Updated: 2024/04/09 10:40:43 by rdavurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	b;
	unsigned int	l;

	b = 0;
	l = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[b] != '\0' && b < len)
	{
		while (big[b + l] == little[l] && len > b + l)
		{
			l++;
			if (little[l] == '\0')
				return ((char *)big + b);
		}
		b++;
		l = 0;
	}
	return (NULL);
}
