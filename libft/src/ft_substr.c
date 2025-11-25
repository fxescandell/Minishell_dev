/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:40:56 by fescande          #+#    #+#             */
/*   Updated: 2025/05/06 10:41:02 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pt_substr;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = 0;
	if (s == NULL)
		return (NULL);
	s_len = (ft_strlen((char *)s));
	if (s_len < start)
		return (ft_strdup(""));
	if (len >= s_len - start)
		len = s_len - start;
	pt_substr = (char *)malloc(sizeof(char) * (len + 1));
	if (pt_substr == NULL)
		return (NULL);
	while (i < len)
	{
		pt_substr[i] = s[start + i];
		i++;
	}
	pt_substr[i] = '\0';
	return (pt_substr);
}
