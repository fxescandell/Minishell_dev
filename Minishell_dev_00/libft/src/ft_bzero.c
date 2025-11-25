/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:27:49 by fescande          #+#    #+#             */
/*   Updated: 2025/05/06 10:27:56 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*pointblock;
	size_t			i;

	i = 0;
	pointblock = (unsigned char *)s;
	while (i < n)
	{
		pointblock[i] = '\0';
		i++;
	}
}
