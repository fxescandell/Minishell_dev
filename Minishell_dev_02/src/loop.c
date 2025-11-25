#include "loop.h"
#include "loop_io.h"

void    run_non_tty_loop(t_shell *sh)
{
    (void)sh;
}

void    run_shell_loop(t_shell *shell)
{
    if (!isatty(STDIN_FILENO))
    {
        run_non_tty_loop(shell);
        return ;
    }
    show_msx_intro();
    run_tty_loop(shell);
}