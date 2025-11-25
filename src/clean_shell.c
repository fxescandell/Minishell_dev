#include "minishell.h"

static void clean_runtime_state(t_shell *shell)
{
    if(shell->current_segments)
    {
        free_string_array(shell->current_segments);
        shell->current_segments=NULL;
    }
}

static void clean_enviroment(t_shell *shell)
{
    (void)shell;
}

void    clean_child(t_shell *shell)
{
    if(!shell)
        return ;
    clean_runtime_state(shell);
    clean_enviroment(shell);
}

void    clean_shell(t_shell *shell)
{
    if (!shell)
        return ;
    clean_runtime_state(shell);
    clean_enviroment(shell);
    rl_clear_history();
}