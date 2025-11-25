#include "loop_io.h"
#include "minishell.h"

int is_empty_or_space(const char *s)
{
    if (!s)
        return (1);
    while (*s)
    {
        if (!(*s == ' ' || *s == '\t' || *s == '\n' ||
              *s == '\r' || *s == '\v' || *s == '\f'))
            return (0);
        s++;
    }
    return (1);
}


void process_segment_array(char **segments, t_shell *shell)
{
    int i;

    if (!segments || !*segments)
        return ;
    i = 0;
    while (segments[i])
    {
        if (!is_empty_or_space(segments[i]))
        {
            t_pipeline pl = parse_command_line(segments[i], shell);
            if (pl.count > 0 || pl.command != NULL)
            {
                t_pipeline *pl_ptr = safe_malloc(sizeof(*pl_ptr));
                *pl_ptr = pl;
                execute_pipeline(pl_ptr, shell);
                free_pipeline(pl_ptr);
                free(pl_ptr);
            }
        }
        i++;
    }
}

/* Stubs temporales: devolver estructuras vacías y no hacer nada.
   Reemplazar por la lógica real más adelante. */

t_pipeline parse_command_line(const char *segment, t_shell *shell)
{
    t_pipeline result;

    (void)segment;
    (void)shell;
    result.command = NULL;
    result.count = 0;
    return (result);
}

void free_pipeline(t_pipeline *pl)
{
    (void)pl;
    /* liberar contenido cuando haya implementación real */
}

void execute_pipeline(t_pipeline *pl, t_shell *shell)
{
    (void)pl;
    (void)shell;
    /* ejecutar pipeline real cuando esté implementado */
}