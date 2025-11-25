/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:20:56 by fescande          #+#    #+#             */
/*   Updated: 2025/06/02 13:06:24 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif

// Prototipo de la función principal
char	*get_next_line(int fd);

// el resto de funciones como son static,
// no es necesario incluirlas en el header
// ya que solo se utilizarán dentro de este archivo
// y no serán accesibles desde otros archivos.

/* Prototipos de funciones auxiliares internas */

// Prototipo de la función para calcular la longitud de una cadena
size_t	string_len(const char *s);

// Prototipo de la función para buscar un carácter en una cadena
char	*char_search(const char *s, int c);

// Prototipo de la función para duplicar una cadena
char	*string_duplicated(const char *s);

// Prototipo de la función para unir dos cadenas
char	*string_joined(char *s1, const char *s2);

#endif