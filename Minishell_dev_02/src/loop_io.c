#include "loop_io.h"
#include "minishell.h"

void process_line(char *line, t_shell *shell, int record_history)
{
    char    **segments;

    if(shell->current_segments)
    {
        free_string_array(shell->current_segments);
        shell->current_segments = NULL;
    }

    if(is_empty_or_space(line))
        return ;

    if(record_history)
        add_history(line);

    segments = split_by_semmicolon(line);
    shell->current_segments = segments;
    process_segment_array(segments, shell);
    free_string_array(shell->current_segments);
    shell->current_segments = NULL;
}

int read_trimmed_line(char **buf, size_t *cap)
{
    ssize_t r;

    r = ft_getline_internal(buf, cap);
    if(r <= 0)
        return (0);
    if(r > 0 && (*buf)[r -1] == '\n')
        (*buf)[r - 1] = '\0';
    return (1);
}