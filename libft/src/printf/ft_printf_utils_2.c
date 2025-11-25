/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:41:22 by fescande          #+#    #+#             */
/*   Updated: 2025/06/28 22:23:38 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdio.h>

int	print_hex(unsigned int n, char format)
{
	char	*base;
	int		count;

	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	else
		return (0);
	count = 0;
	if (n >= 16)
		count = count + print_hex(n / 16, format);
	count = count + print_char(base[n % 16]);
	return (count);
}

static int	print_hex_ul(unsigned long n)
{
	int			count;
	const char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16UL)
	{
		count = count + print_hex_ul(n / 16UL);
	}
	count = count + print_char(base[n % 16UL]);
	return (count);
}

int	print_ptr(void *ptr)
{
	unsigned long	address;
	int				count;

	address = (unsigned long)ptr;
	count = 0;
	count = count + write(1, "0x", 2);
	if (address == 0UL)
	{
		count = count + print_char('0');
		return (count);
	}
	count = count + print_hex_ul(address);
	return (count);
}
