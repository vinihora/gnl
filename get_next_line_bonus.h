/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veduardo <veduardo@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 08:55:29 by veduardo          #+#    #+#             */
/*   Updated: 2021/06/19 20:30:12 by veduardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/param.h>
# include <sys/resource.h>
# include <fcntl.h>
# include <sys/stat.h>

char	*ft_strdup(char *str);
int		ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *dest, char *org, int positions);
int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t nb, size_t size);

#endif