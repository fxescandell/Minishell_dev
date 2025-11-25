/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:29:25 by fescande          #+#    #+#             */
/*   Updated: 2025/05/06 10:29:52 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <ctype.h>

int	ft_isalnum(int c)
{
	if ((ft_isdigit(c)) || (ft_isalpha(c)))
		return (1);
	return (0);
}
