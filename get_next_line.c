/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:46:14 by adbourji          #+#    #+#             */
/*   Updated: 2024/01/05 16:49:26 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_until_nl(int fd, char *remainder)
{
	char	*buffer;
	int		ret;

	ret = 1;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ret != 0 && !ft_strchr(remainder, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(remainder);
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (remainder == NULL)
		{
			free(buffer);
			return (remainder);
		}
	}
	return (free(buffer), remainder);
}

char	*one_line(char *remainder)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (remainder[0] == '\0')
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = malloc (i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		line[j++] = remainder[i++];
	if (remainder[i] == '\n')
	{
		line[j++] = '\n';
	}
	line[j] = '\0';
	return (line);
}

char	*get_remaining(char	*remainder)
{
	char	*new_remainder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!remainder)
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\0')
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = malloc(ft_strlen(remainder) - i + 1);
	if (!new_remainder)
		return (NULL);
	if (remainder[i] == '\n')
		i++;
	while (remainder[i] != '\0')
		new_remainder[j++] = remainder[i++];
	new_remainder[j] = '\0';
	free(remainder);
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = ft_read_until_nl(fd, remainder);
	if (!remainder)
		return (NULL);
	next_line = one_line(remainder);
	remainder = get_remaining(remainder);
	return (next_line);
}
