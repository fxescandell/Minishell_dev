/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:18:17 by fescande          #+#    #+#             */
/*   Updated: 2025/06/28 22:23:38 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* ************************************************************************* */
size_t	string_len(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/* ************************************************************************* */
char	*char_search(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/* ************************************************************************* */
char	*string_duplicated(const char *s)
{
	size_t	len;
	char	*copy;
	size_t	i;

	len = string_len(s);
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}

/* ************************************************************************* */
char	*string_joined(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;
	size_t	i;

	len1 = string_len(s1);
	len2 = string_len(s2);
	join = malloc(len1 + len2 + 1);
	if (join == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		join[len1 + i] = s2[i];
		i++;
	}
	join[len1 + len2] = '\0';
	return (join);
}
