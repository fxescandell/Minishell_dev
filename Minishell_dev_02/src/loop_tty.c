#include "loop.h"
#include "loop_io.h"
#include "minishell.h"

static char *read_tty_logical(t_shell *sh)
{
    char    *line;

    (void)sh;
    line = read_msx_line();
    if(!line)
    {
        handle_msx_exit();
        return (NULL);
    }
    return(line);
}

void    run_tty_loop(t_shell *sh)
{
    char    *logical;

    while (sh->running)
    {
        logical =  read_tty_logical(sh);
        if(!logical)
            break;
        sh->current_line = logical;
        process_line(logical, sh, 1);
        free(logical);
        sh->current_line = NULL;
    }
    if(sh->current_pipeline)
    {
        sh->current_pipeline = NULL;
    }
}
