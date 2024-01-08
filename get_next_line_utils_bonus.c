/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:28:01 by adbourji          #+#    #+#             */
/*   Updated: 2024/01/05 14:33:59 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char	*buffer)
{
	char	*temp;
	int		i;
	int		buffer_len;

	i = 0;
	buffer_len = ft_strlen(buffer);
	temp = malloc(sizeof(char) * (buffer_len + 1));
	if (!temp)
		return (NULL);
	while (buffer[i])
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char *remainder, char *buffer)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!remainder)
		return (ft_strdup(buffer));
	res = malloc(ft_strlen(remainder) + ft_strlen(buffer) + 1);
	if (!res)
		return (NULL);
	while (remainder[i])
	{
		res[i] = remainder[i];
		i++;
	}
	while (buffer[j])
		res[i++] = buffer[j++];
	res[i] = '\0';
	return (free(remainder), res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	if (!s)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	if (!(char)c)
		return (str + i);
	return (NULL);
}
