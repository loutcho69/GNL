/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:30:08 by lobroue           #+#    #+#             */
/*   Updated: 2026/01/11 14:56:25 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static  t_list  *stash;
    char    *line;
    int     readed;

    stash = NULL;
    if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &line, 0) < 0)
        return (NULL);
    readed = 1;
    line = NULL;
    read_and_stash(fd, &stash, &readed);
    if (stash == NULL)
        return (NULL);
    
    


    return (line);
}
void    read_and_stash(int fd, t_list **stash, int  *readed_ptr)
{
    char    *buf;
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buf == NULL)
        return;
    while (!found_newline(*stash) && *readed_ptr != 0)
    {
        *readed_ptr = read(fd, buf, BUFFER_SIZE);
        buf[*readed_ptr] = '\0';
        if((*stash == NULL && *readed_ptr == 0) || *readed_ptr != 0)

    }
}

void    add_to_stash()
{
    
}
void    extract_line()
{
    
}

int     main()
{
    int fd;
    char    *line;

    fd = open("test", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("%s, line");
        free (line);
    }
    return (0);
}