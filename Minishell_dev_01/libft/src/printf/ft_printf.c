/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:59:54 by fescande          #+#    #+#             */
/*   Updated: 2025/06/28 22:23:38 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	format_conversor(char spec, va_list *args)
{
	if (spec == 'c')
		return (print_char((char)va_arg(*args, int)));
	else if (spec == 's')
		return (print_str(va_arg(*args, char *)));
	else if (spec == 'p')
		return (print_ptr(va_arg(*args, void *)));
	else if (spec == 'd' || spec == 'i')
		return (print_nbr(va_arg(*args, int)));
	else if (spec == 'u')
		return (print_unsigned_nbr(va_arg(*args, unsigned int)));
	else if (spec == 'x' || spec == 'X')
		return (print_hex(va_arg(*args, unsigned int), spec));
	else if (spec == '%')
		return (print_char('%'));
	else
		return (0);
}

static int	handle_format(const char *str, va_list *args)
{
	int	i;
	int	byte_count;

	i = 0;
	byte_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i = i + 1;
			byte_count = byte_count + format_conversor(str[i], args);
		}
		else
		{
			byte_count = byte_count + print_char(str[i]);
		}
		i = i + 1;
	}
	return (byte_count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		byte_count;

	va_start(args, str);
	byte_count = handle_format(str, &args);
	va_end(args);
	return (byte_count);
}
