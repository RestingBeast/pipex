/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 05:24:37 by kkhant-z          #+#    #+#             */
/*   Updated: 2025/12/01 05:24:38 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*res;

	prev = NULL;
	res = NULL;
	while (lst)
	{
		tmp = malloc(sizeof(t_list));
		if (!tmp)
			return (ft_lstclear(&res, del), NULL);
		tmp->content = f(lst->content);
		tmp->next = NULL;
		if (!res)
			res = tmp;
		if (prev)
			prev->next = tmp;
		prev = tmp;
		lst = lst->next;
	}
	return (res);
}
