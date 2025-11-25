#ifndef LOOP_H
# define LOOP_H

# include "minishell.h"

void    run_non_tty_loop(t_shell *sh);
void    run_tty_loop(t_shell *sh);

#endif