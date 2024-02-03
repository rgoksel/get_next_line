/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:37:35 by rdemiray          #+#    #+#             */
/*   Updated: 2023/07/30 17:04:25 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_get_line(char *str)
{
	int		i;
	char	*dest;
	int		check;

	i = 0;
	if (!str[i])
		return (NULL);
	check = newline(str);
	while (str[i] && str[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (i + check + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		dest[i] = str[i];
	if (check)
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

char	*shift_the_line(char *str)
{
	int			i;
	int			j;
	char		*dest;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (ft_free(str));
	dest = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dest)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	free(str);
	return (dest);
}

char	*read_the_file(int fd, char *str)
{
	char	*buffer;
	int		rc;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rc = 1;
	while (!newline(str) && rc != 0)
	{
		rc = read(fd, buffer, BUFFER_SIZE);
		if (rc == -1)
		{
			free(str);
			return (ft_free(buffer));
		}
		buffer[rc] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*str[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = read_the_file(fd, str[fd]);
	if (!str[fd])
		return (0);
	line = ft_get_line(str[fd]);
	str[fd] = shift_the_line(str[fd]);
	return (line);
}
