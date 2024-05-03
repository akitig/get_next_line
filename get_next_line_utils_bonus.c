/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:12:56 by akunimot          #+#    #+#             */
/*   Updated: 2024/05/03 19:50:57 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

// ft_memset(s, 0, n);
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ans;

	i = 0;
	ans = (unsigned char *)s;
	while (i < n)
	{
		ans[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (size > 0 && (SIZE_MAX / size < count))
	{
		errno = ENOMEM;
		return (NULL);
	}
	size *= count;
	ptr = (unsigned char *)malloc(size);
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	ft_bzero(ptr, size);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (NULL);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char *str;
	size_t i;
	size_t j;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}