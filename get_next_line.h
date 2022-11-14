/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:49:46 by abouassi          #+#    #+#             */
/*   Updated: 2022/11/10 11:49:48 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 10
#endif

char *get_next_line(int fd);
int	ft_strchr( const char *str);
char	*ft_strjoin(char  *s1, char *s2);
size_t	ft_strlen(const char *str);
#endif
