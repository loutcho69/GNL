/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:30:04 by lobroue           #+#    #+#             */
/*   Updated: 2026/02/01 01:12:26 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_stash(t_list *stash)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
				return (count + 1);
			i++;
			count++;
		}
			stash = stash->next;
	}
	return (count);
}
bool	found_new_line(t_list *stash)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stash;
	if (!tmp)
		return (false);
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->content[i])
	{
		if (tmp->content[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}
t_list	*ft_lstnew(char *buf, int y)
{
	t_list	*res;
	size_t	i;

	i = 0;
	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	while (y < BUFFER_SIZE)
	{
		res->content[i] = buf[y];
		i++;
		y++;
	}
	res->content[i] = '\0';
	res->next = NULL;
	return (res);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

