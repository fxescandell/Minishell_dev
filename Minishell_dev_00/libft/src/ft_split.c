/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:28:51 by fescande          #+#    #+#             */
/*   Updated: 2025/05/06 10:28:54 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (*s != '\0')
	{
		if (*s != c && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (count);
}

static char	*next_word(const char **s, char c)
{
	const char	*start;
	size_t		len;
	char		*word;

	while (**s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = *s - start;
	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

static void	free_all(char **arr, size_t used)
{
	size_t	i;

	i = 0;
	while (i < used)
		free(arr[i++]);
	free(arr);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	words;
	size_t	i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		res[i] = next_word(&s, c);
		if (!res[i])
		{
			free_all(res, i);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
