/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:41:11 by rdavurov          #+#    #+#             */
/*   Updated: 2024/04/09 11:00:01 by rdavurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *i, int c)
{
	unsigned int	s;
	char			cc;

	cc = (char)c;
	s = 0;
	while (i[s] != '\0')
	{
		if (i[s] == cc && cc != '\0')
			return ((char *)&i[s]);
		s++;
	}
	if (i[s] == cc)
		return ((char *)&i[s]);
	return (NULL);
}
