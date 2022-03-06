/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:35:53 by jperras           #+#    #+#             */
/*   Updated: 2022/03/06 17:12:29 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
int 	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_read(char **c, int *ret, int fd );
char	*ft_strjoin(char *str1, char *str2);
int		ft_strseek(const char *s, int c);
char 	*ft_strcpy(char	*s, int len);
char	*ft_strcpystart(char *s, int start);
#endif
