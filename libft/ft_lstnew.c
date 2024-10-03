/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:44:54 by rdavurov          #+#    #+#             */
/*   Updated: 2024/04/09 11:03:59 by rdavurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*sklad;

	sklad = (t_list *)malloc(sizeof(t_list));
	if (sklad == NULL)
		return (NULL);
	sklad->content = content;
	sklad->next = NULL;
	return (sklad);
}
