/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:30:08 by lobroue           #+#    #+#             */
/*   Updated: 2026/02/02 05:17:26 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*clear_stash(t_list *stash)
{
	t_list	*new_stash;
	t_list	*tmp;
	size_t	i;

	if (!stash)
		return (NULL);
	tmp = stash;
	new_stash = NULL;
	i = 0;
	while (stash->next)
		stash = stash->next;
	while (stash->content[i] != '\n' && stash->content[i])
		i++;
	if (stash->content[i] == '\n')
		i++;
	new_stash = ft_lstnew(stash->content, i);
	ft_lstclear(&tmp);
	return (new_stash);
}

char	*extract_line(t_list *stash, char *line)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen_stash(stash);
	line = malloc(len + 1);
	if (!line)
	{
		ft_lstclear(&stash);
		return (NULL);
	}
	j = 0;
	i = 0;
	while (j < len)
	{
		if (stash->content[i] == '\0')
		{
			stash = stash->next;
			i = 0;
		}
		line[j++] = stash->content[i++];
	}
	line[j++] = '\0';
	return (line);
}

#include <stdio.h>

t_list	*read_and_stash(t_list *stash, int fd)
{
	char	*buf;
	ssize_t	readed;
	t_list	*new_node;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	readed = read(fd, buf, BUFFER_SIZE);
	buf[readed] = '\0';
	if (readed <= 0)
	{
		ft_lstclear(&stash);
		free(buf);
		return (NULL);
	}
	while (readed > 0)
	{
		new_node = ft_lstnew(buf, 0);
		ft_lstadd_back(&stash, new_node);
		if (found_new_line(stash))
			break ;
		readed = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
	}
	free(buf);
	return (stash);
}
char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!found_new_line(stash))
		stash = read_and_stash(stash, fd);
	if (!stash)
	{
		ft_lstclear(&stash);
		return (NULL);
	}
	line = extract_line(stash, line);
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	stash = clear_stash(stash);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	size_t	i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 40)
	{
		line = get_next_line(fd);
		printf("%s", line);
		++i;
		free(line);
	}
	close(fd);
	return (0);
}
