/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:50:49 by kmushta           #+#    #+#             */
/*   Updated: 2017/10/31 13:50:50 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_words_count_strsplit(char const *s, char c)
{
	unsigned int q;

	if (!s)
		return (0);
	q = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		q++;
		while (*s != c && *s)
			s++;
		if (!*s)
			return (q);
		while (*s == c && *s)
			s++;
	}
	return (q);
}

static void			ft_del_strsplit(char ***arr)
{
	unsigned int	i;

	i = 0;
	while (*((*arr) + i))
	{
		free(*((*arr) + i));
		*((*arr) + i) = 0;
		i++;
	}
	free(*arr);
	*arr = 0;
}

static unsigned int	ft_word_lenght_strsplit(char const *s, char c)
{
	unsigned int q;

	q = 0;
	while (*s != c && *s)
	{
		q++;
		s++;
	}
	return (q);
}

static char			*ft_read_strsplit(char const **s, char c)
{
	char	*arr;
	char	*it;

	while (**s == c)
		(*s)++;
	arr = (char *)malloc(sizeof(char) * (ft_word_lenght_strsplit(*s, c) + 1));
	if (!arr)
		return (0);
	it = arr;
	while (**s != c && **s)
		*it++ = *(*s)++;
	*it = 0;
	return (arr);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**arr;
	unsigned int	len;
	unsigned int	i;

	len = ft_words_count_strsplit(s, c);
	arr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!arr)
		return (0);
	i = -1;
	while ((++i) <= len)
		*(arr + i) = 0;
	i = -1;
	while ((++i) < len)
	{
		*(arr + i) = ft_read_strsplit(&s, c);
		if (!*(arr + i))
			ft_del_strsplit(&arr);
	}
	return (arr);
}
