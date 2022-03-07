/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:54:04 by jperras           #+#    #+#             */
/*   Updated: 2022/03/07 12:52:50 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		len;
	char	*str3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	str3 = malloc(sizeof(char) * (len + 1));
	if (str3 == NULL)
		return (NULL);
	while (str1[i] != '\0')
	{
		str3[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		str3[i] = str2[j];
		i++;
		j++;
	}
	str3[i] = '\0';	
	return (str3);
}

int	ft_strseek(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_strcpy(char *s, int len)
{
	char	*str;
	int		i;

	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strcpystart(char *s, int start)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(&s[start + 1]) + 1));
	if (str == NULL)
		return(NULL);
	while (s[start + 1+ i] != '\0')
	{
		str[i] = s[i + start + 1];
		i++;
	}
	str[i] = '\0';
	return (str);
}
