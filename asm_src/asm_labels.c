/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_labels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:18:42 by vveselov          #+#    #+#             */
/*   Updated: 2018/06/14 19:41:45 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_check.h"

t_label		*new_label(char *s, int *i)
{
	int		j;
	int		k;
	t_label	*new;

	new = (t_label *)malloc(sizeof(t_label));
	new->next = NULL;
	j = *i;
	k = 0;
	while (s[*i] != ':')
		(*i)++;
	(*i)++;
	new->label = (char *)malloc(sizeof(char) * ((*i - j) + 1));
	while (j < *i)
		new->label[k++] = s[j++];
	new->label[k] = '\0';
	return (new);
}

void		del_labels(t_label *list)
{
	t_label		*tmp;

	if (list)
		while (list)
		{
			tmp = list->next;
			free(list->label);
			free(list);
			list = tmp;
		}
}

void		add_label(t_label **list, char *s, int *i)
{
	t_label	*tmp;

	if (!(*list))
		*list = new_label(s, i);
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_label(s, i);
	}
}

t_label		*lab_er(char *s, t_label *list, int i, int tmp[2])
{
	del_labels(list);
	i = 0;
	list = NULL;
	error_menager(&s[i], tmp, -1);
	add_label(&list, "?:", &i);
	return (list);
}

t_label		*collect_labels(char *s, int i, int pos[2])
{
	int			w;
	t_label		*list;
	int			tmp[2];

	tmp[0] = pos[0];
	tmp[1] = pos[1];
	list = NULL;
	while (s[i])
	{
		if (!asm_skip_space(s, &i, tmp, 2) &&
		((w = asm_word_type(&s[i], tmp)) == 11 || w == 10 || w == 8 || w == 7 ||
		(w <= 3 && w >= 1)))
		{
			s[i] = '\0';
			return (list);
		}
		if (w == 6)
			add_label(&list, s, &i);
		else if (w == -1 || w == -32 || w == 32)
			return (lab_er(s, list, i, tmp));
		while (s[i] && s[i] != '\n')
			i++;
	}
	return (list);
}
