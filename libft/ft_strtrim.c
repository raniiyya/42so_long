/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:00:15 by rdavurov          #+#    #+#             */
/*   Updated: 2024/04/10 16:22:28 by rdavurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hejka(char to_find, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*tmp;

	start = 0;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	end = ft_strlen(s1) - 1;
	while (s1[start] && hejka(s1[start], set))
		start++;
	while (s1[end] && hejka(s1[end], set) && end >= start)
		end--;
	tmp = (char *)malloc(sizeof(char) * (&s1[end] - &s1[start] + 1) + 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, &s1[start], &s1[end] - &s1[start] + 1 + 1);
	return (tmp);
}
