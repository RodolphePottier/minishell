/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_calloc_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:59:20 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 21:32:00 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	__ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
	}
}

static void	__free_exit(t_list **lst)
{
	__ft_lstclear(lst);
}

void	*__ft_calloc_env(ssize_t size)
{
	static t_list	*list_malloc;
	t_list			*new;
	void			*content;

	if (size < 0)
	{
		__free_exit(&list_malloc);
		return (NULL);
	}
	content = ft_calloc(1, size);
	if (!content)
		__free_exit(&list_malloc);
	new = ft_lstnew(content);
	if (!new)
	{
		free(content);
		__free_exit(&list_malloc);
	}
	if (!list_malloc)
		list_malloc = new;
	else
		ft_lstadd_back(&list_malloc, new);
	return (content);
}
