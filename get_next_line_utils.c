/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veduardo <veduardo@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:14:53 by veduardo          #+#    #+#             */
/*   Updated: 2021/06/19 20:38:52 by veduardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strlcpy(char *dst, char *src, size_t n);

size_t	ft_strlen(char *s)
{
	size_t			size;

	size = 0;
	if (!s)
		return (0);
	while (s[size])
		size++;
	return (size);
}

char	*ft_strdup(char *str)
{
	size_t	size_str;
	char	*new_str;

	size_str = ft_strlen(str);
	new_str = (char *)ft_calloc(sizeof(char), size_str + 1);
	if (str == NULL || !new_str)
		return (NULL);
	ft_strlcpy(new_str, str, size_str + 1);
	return (new_str);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_strlcpy(char *dst, char *src, size_t n)
{
	size_t	i;

	if (n == 0 || src == NULL)
		return ;
	i = 0;
	while ((src[i] != '\0') && (i < (n - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}

char	*ft_strjoin(char *dest, char *org, int positions)
{
	char	*temp;

	if (!dest && !org)
		return (NULL);
	temp = ft_calloc((ft_strlen(dest) + positions + 1), sizeof(char));
	if (!(temp))
		return (NULL);
	ft_strlcpy(temp, dest, (ft_strlen(dest) + 1));
	ft_strlcpy((temp + ft_strlen(dest)), org, positions + 1);
	if (dest)
		free(dest);
	return (temp);
}
