/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:35:04 by adbourji          #+#    #+#             */
/*   Updated: 2024/01/05 15:53:43 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	size_t	len_s1;
	char	*temp;

	i = 0;
	len_s1 = ft_strlen(s1);
	temp = malloc(sizeof(char) * (len_s1 + 1));
	if (!temp)
		return (NULL);
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char	*remainder1, char *buffer1)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!remainder1)
		return (ft_strdup(buffer1));
	res = malloc(ft_strlen(remainder1) + ft_strlen(buffer1) + 1);
	if (!res)
		return (NULL);
	while (remainder1[i])
	{
		res[i] = remainder1[i];
		i++;
	}
	while (buffer1[j])
		res[i++] = buffer1[j++];
	res[i] = '\0';
	free(remainder1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	if ((char)c == 0)
		return (str + i);
	return (NULL);
}
