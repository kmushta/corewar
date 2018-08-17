/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:58:03 by kmushta           #+#    #+#             */
/*   Updated: 2017/11/01 11:58:04 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_delall(t_list **alst)
{
	t_list *curr;
	t_list *prev;

	curr = *alst;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		free(prev);
		prev = 0;
	}
	*alst = 0;
	return (0);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new;
	t_list *curr;
	t_list *beg;

	if (!lst || !f)
		return (0);
	curr = (t_list *)malloc(sizeof(t_list));
	if (!curr)
		return (0);
	curr = (*f)(lst);
	beg = curr;
	tmp = lst->next;
	while (tmp)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
			return (ft_delall(&beg));
		new = (*f)(tmp);
		tmp = tmp->next;
		curr->next = new;
		curr = curr->next;
		new = 0;
	}
	return (beg);
}
