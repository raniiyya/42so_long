/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:38:30 by rdavurov          #+#    #+#             */
/*   Updated: 2024/04/12 14:10:15 by rdavurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**free_palestine(char **mem, int i)
{
	while (i-- != 0)
		free(mem[i]);
	free(mem);
	return (NULL);
}

static char	**hejka_list(char const *s, char c, char **tmp)
{
	int	i;

	i = 0;
	while (ft_strchr(s, c) != NULL && c)
	{
		tmp[i++] = ft_substr(s, 0, ft_strchr(s, c) - s);
		if (!tmp[i - 1])
			return (free_palestine(tmp, i - 1));
		s = ft_strchr(s, c);
		while (*s == c)
			s++;
	}
	if (*s != c && *s != '\0')
	{
		tmp[i++] = ft_substr(s, 0, ft_strchr(s, '\0') - s);
		if (!tmp[i - 1])
			return (free_palestine(tmp, i - 1));
	}
	tmp[i] = NULL;
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;

	if (!s)
		return (NULL);
	while (*s == c && c)
		s++;
	tmp = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tmp)
		return (NULL);
	tmp = hejka_list(s, c, tmp);
	return (tmp);
}
