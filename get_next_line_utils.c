/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:49:01 by abouassi          #+#    #+#             */
/*   Updated: 2022/11/10 11:49:03 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
char	*ft_strdup(const char *src)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(ft_strlen(src) + 1);
	if (!dst)
	{
		return (NULL);
	}
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
int	ft_strchr( const char *str)
{
	int		i;
	char	*s1;

	i = 0;
	if (!str)
	{
		return 0;
	}
	s1 = (char *)str;
	while (s1[i] != '\n')
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tstr;

	if ( !s2)
		return (NULL);
	if (!s1)
		s1 =ft_strdup("");
	i = 0;
	j = 0;
	tstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!tstr)
		return (NULL);
	while (s1[i] != '\0')
	{
		tstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tstr[i++] = s2[j++];
	}
	tstr[i] = '\0';
	free(s1);
	return (tstr);
}
// int main()
// {
// 	printf("%s",ft_strjoin("fagbfdaady","m\nUGHJMGJH"));
// }