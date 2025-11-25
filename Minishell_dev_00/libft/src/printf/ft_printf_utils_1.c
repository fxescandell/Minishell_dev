/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:05:49 by fescande          #+#    #+#             */
/*   Updated: 2025/06/28 22:23:38 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;
	int	index;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	index = 0;
	while (str[index])
	{
		count = count + print_char(str[index]);
		index = index + 1;
	}
	return (count);
}

int	print_nbr(int n)
{
	long	number;
	int		count;

	number = (long)n;
	count = 0;
	if (number < 0)
	{
		count = count + print_char('-');
		number = -number;
	}
	if (number >= 10)
	{
		count = count + print_nbr((int)(number / 10));
	}
	count = count + print_char((char)((number % 10) + '0'));
	return (count);
}

int	print_unsigned_nbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count = count + print_unsigned_nbr(n / 10);
	}
	count = count + print_char((char)((n % 10) + '0'));
	return (count);
}
