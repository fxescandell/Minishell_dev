/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:34:04 by fescande          #+#    #+#             */
/*   Updated: 2025/05/06 10:34:06 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pointblock;
	size_t			i;

	i = 0;
	pointblock = (unsigned char *)s;
	while (i < n)
	{
		pointblock[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
