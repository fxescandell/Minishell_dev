/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:28:29 by fescande          #+#    #+#             */
/*   Updated: 2025/05/06 10:28:33 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*pt;

	pt = malloc(num * size);
	if (pt == NULL)
		return (NULL);
	ft_bzero(pt, num * size);
	return (pt);
}
