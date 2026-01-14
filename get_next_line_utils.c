/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:30:04 by lobroue           #+#    #+#             */
/*   Updated: 2026/01/14 18:49:17 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int found_newline(t_list *stash)
{
    int i;
    t_list  *current;
    
    if (stash == NULL)
        return (0);
    current = lst_get_last(stash);
    i = 0;
    while (current->content[i])
    {
        if (current->content[i] == '\n')
            return(1);
        ++i;
    }
    return (0);
}


t_list    *lst_get_last(t_list *stash)
{
    t_list  *current;

    current = stash;
    while (current && current->next)
        current = current->next;
    return (current);
}