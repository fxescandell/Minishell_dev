/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:36:52 by fescande          #+#    #+#             */
/*   Updated: 2025/05/06 10:36:55 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*pt;

	i = 0;
	len = ft_strlen(s);
	pt = malloc(sizeof(char) * (len + 1));
	if (pt == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		pt[i] = s[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
