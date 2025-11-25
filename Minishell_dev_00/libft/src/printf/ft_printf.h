/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:59:46 by fescande          #+#    #+#             */
/*   Updated: 2025/06/02 23:21:31 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*
** Prototipos de las funciones básicas de impresión
*/
int	print_char(char c);
int	print_str(char *s);
int	print_nbr(int n);
int	print_unsigned_nbr(unsigned int n);
int	print_hex(unsigned int n, char format);
int	print_ptr(void *ptr);

/*
** Función principal obligatoria
*/
int	ft_printf(const char *str, ...);

#endif