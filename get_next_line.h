/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:30:10 by lobroue           #+#    #+#             */
/*   Updated: 2026/01/15 17:45:58 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE.H
#define GET_NEXT_LINE.H 

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

typedef struct  s_list
{
    char    *content;
    struct s_list   *next;
}               t_list;




char    *get_next_line(int fd);




#endif
