/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:11:59 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/31 17:12:02 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memmove_lstnew(void *dst, const void *src, size_t len)
{
	char		*s1;
	const char	*s2;

	s1 = dst;
	s2 = src;
	if ((size_t)s2 < (size_t)s1)
	{
		s1 += len - 1;
		s2 += len - 1;
		while (len)
		{
			*s1-- = *s2--;
			len--;
		}
	}
	else
		while (len)
		{
			*s1++ = *s2++;
			len--;
		}
	return (dst);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	if (content && content_size)
	{
		lst->content = (void *)malloc(content_size);
		if (!(lst->content))
		{
			free(lst);
			return (0);
		}
		ft_memmove_lstnew(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	else
	{
		lst->content = 0;
		lst->content_size = 0;
	}
	lst->next = 0;
	return (lst);
}
