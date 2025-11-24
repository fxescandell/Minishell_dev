#include "minishell.h"

static void init_terminal(t_shell *shell)
{
    struct termios  term;

    shell->term_saved = 0;
    if (isatty(STDIN_FILENO))
        return ;
    if (tcgetattr(STDIN_FILENO, &term) == -1)
        return ;
    shell->term_orig = term;
    shell->term_saved = 1;
}

static void init_shell(t_shell *shell, char **envp)
{
    if (!shell)
        return ;
    (void)envp;
    shell->envp = NULL;
    shell->last_status = 0;
    shell->runtime = 1;
    init_terminal(shell);
}

int main (int argc, char **argv, char **envp)
{
    t_shell shell;

    (void)argc;
    (void)argv;
    signal(SIGPIPE, SIG_IGN);
    init_shell(&shell, envp);
    clean_shell(&shell);
    return (shell.last_status);
}