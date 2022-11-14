/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:48:32 by abouassi          #+#    #+#             */
/*   Updated: 2022/11/10 11:48:37 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h> 

char *htafdlia(char * str)
{
	int i;
	int j;
	char *buff;
	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
			i++;
	if (!str[i])
	{
		free(str);
		return(NULL);
	}
	buff = malloc(ft_strlen(str) - i + 1);
	if (!buff)
		return (NULL);
	i++;
	while (str[i])
	{
		buff[j] = str[i];
		i++;
		j++;
	}
	buff[j] = '\0';
	free(str);
	return (buff);   
}
char *get_clean(char *str )
{
	char *buff1;
	int i;
	i = 0;
	if(!str[0])
		return NULL;
	while (str[i] != '\n' && str[i])
		i++;
	buff1 = malloc(i + 2);
	if (!buff1)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n' )
	{
		buff1[i] = str[i]; 
		i++;
	} 
	if(str[i] == '\n')
		buff1[i++] = '\n';
	buff1[i] = '\0';
	return (buff1);
}
char *read_line(int fd,char *str)
{
	char *buff;
	int ret;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ret = 1;

	while (!ft_strchr(str) && ret != 0)
	{
		ret = read(fd,buff,BUFFER_SIZE);
		if (ret == -1 )
		{
			free(buff);
			free(str);
			return NULL;
		}
		buff[ret] = '\0';
		str = ft_strjoin(str,buff);
	
	}
	free(buff);
	return (str);

}

char *get_next_line(int fd)
{
	static char *ptr;
	char *buff = NULL;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}

	ptr  = read_line(fd,ptr);
	
	if (!ptr)
	{
		return (NULL);
	}
	buff = get_clean(ptr);
	ptr = htafdlia(ptr);
	return (buff);
}
// int main()
// {
// 	int fd;

// 	fd = open("42", O_RDONLY);
 


// 	 printf("%s",  get_next_line(fd));
// 	  printf("%s",  get_next_line(fd));
// 	   printf("%s",  get_next_line(fd));


// }