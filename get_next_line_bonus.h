/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:38:20 by rdemiray          #+#    #+#             */
/*   Updated: 2023/07/30 17:06:18 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_get_line(char *str);
char	*read_the_file(int fd, char *str);
char	*shift_the_line(char *str);

int		ft_strlen(char *str);
int		ft_strlcpy(char	*dst, char *src, int dstsize);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_free(void *str);
int		newline(char *ptr);

#endif