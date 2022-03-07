/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:34:26 by jperras           #+#    #+#             */
/*   Updated: 2022/03/07 15:55:08 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	ret;
	static char	*c;
	char		*str;

	if (fd == -1 || BUFFER_SIZE < 1 || read(fd, c, 0) == -1)
		return (NULL);
	str = ft_read(&c, &ret, fd);
	return (str);
}

char	*ft_read(char **c, int *ret, int fd)
{
	char	*str = NULL;
	char	*tmp = NULL;
	int 	flag;
	char	*tampon;
	//char 	*b;
	flag = 0;
	tampon = malloc(sizeof(char) * BUFFER_SIZE + 1);
	tampon[0] = '\0';
	if(*ret == 0)
	{
		*ret = read(fd, tampon, BUFFER_SIZE);
		tampon[*ret] = '\0';
	}
	if(!*c && *ret != 0)
		*c = tampon;
	while (flag == 0 && *ret > 0)
	{
		if (ft_strseek(*c, '\n') != -1)
		{
			str = ft_strcpy(*c, ft_strseek(*c, '\n'));
			*c = ft_strcpystart(*c, ft_strseek(*c, '\n'));
			flag = 1;
		}		
		else 
		{	
			tmp =ft_strcpystart(*c, -1);
			*ret = read(fd, tampon, BUFFER_SIZE);
			tampon[*ret] = '\0';
			if (*ret != 0)
			{
				*c = ft_strjoin(tmp, tampon);
			}
			else
				free(tmp);
		}
		if ( *ret == 0)
		{
			str = ft_strcpy(*c, ft_strlen(*c));
			flag = 1;
		}
	}	
	if (str != NULL && *str == 0)
	{
		free(str);
		str = NULL;
	}
	free(tampon);
	return (str);

}
/*
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
#include <stdio.h>
int main()
{
	int	fd;
	fd = open("fd_Empty Lines",O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
}*/
