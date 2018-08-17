/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:04:51 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/31 19:04:55 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *curr;

	if (!alst || !*alst || !del)
		return ;
	curr = *alst;
	while (curr)
	{
		next = curr->next;
		(*del)(curr->content, curr->content_size);
		free(curr);
		curr = next;
	}
	*alst = 0;
}
