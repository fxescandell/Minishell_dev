/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:40:29 by fescande          #+#    #+#             */
/*   Updated: 2025/05/06 10:40:32 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*tstr;

	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && *s1)
		start++;
	if (start > end)
	{
		tstr = malloc(1);
		if (!tstr)
			return (0);
		else
			*tstr = '\0';
		return (tstr);
	}
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	tstr = malloc(end - start + 2);
	if (!tstr)
		return (0);
	ft_strlcpy(tstr, &s1[start], end - start + 2);
	return (tstr);
}
