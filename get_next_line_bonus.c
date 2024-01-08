/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:27:16 by adbourji          #+#    #+#             */
/*   Updated: 2024/01/05 16:50:28 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_unitl_nl(int fd, char *remainder)
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
			return (free(remainder), free(buffer), NULL);
		buffer[ret] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
			return (free(buffer), remainder);
	}
	return (free(buffer), remainder);
}

char	*one_line(char	*remainder)
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
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		line[j++] = remainder[i++];
	if (remainder[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*get_new_remainder(char	*remainder)
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
		return (free(remainder), NULL);
	new_remainder = malloc(ft_strlen(remainder) - i + 1);
	if (!new_remainder)
		return (NULL);
	if (remainder[i] == '\n')
		i++;
	while (remainder[i] != '\0')
		new_remainder[j++] = remainder[i++];
	new_remainder[j] = '\0';
	return (free(remainder), new_remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder[OPEN_MAX];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	remainder[fd] = read_unitl_nl(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	next_line = one_line(remainder[fd]);
	remainder[fd] = get_new_remainder(remainder[fd]);
	return (next_line);
}

/*
int main()
{
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);

	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
}
*/
