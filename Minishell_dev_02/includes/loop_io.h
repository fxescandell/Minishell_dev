// ...existing code...
#ifndef LOOP_IO_H
# define LOOP_IO_H

# include <stddef.h>
# include <sys/types.h>

/* Necesitamos los typedefs t_shell y t_pipeline */
# include "minishell.h"

/* msx_ui.c */
void    show_msx_intro(void);
char    *read_msx_line(void);
char    *read_msx_continuation(void);
void    handle_msx_exit(void);

/* loop_io_utils.c */
int     is_empty_or_space(const char *s);
void    process_segment_array(char **segments, t_shell *shell);
void    process_segment(char *segment, t_shell *shell);

/* funciones de parsing/ejecución (stubs/impl) */
t_pipeline  parse_command_line(const char *segment, t_shell *shell);
void        execute_pipeline(t_pipeline *pl, t_shell *shell);
void        free_pipeline(t_pipeline *pl);

/* loop_io.c u loop_io_split.c */
int     read_trimmed_line(char **buf, size_t *cap);
char    **split_by_semmicolon(const char *line);
void    process_line(char *line, t_shell *shell, int in_history);

/* loop_io_getline.c */
ssize_t ft_getline_internal(char **buf, size_t *cap);

#endif
// ...existing code...