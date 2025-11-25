#include "minishell.h"

void    show_msx_intro(void)
{
    ft_printf("MSX BASIC version 1.0\n");
    ft_printf("Copyright 1983 by Mocosoft\n");
    ft_printf("32559 Bytes free\n\n");
    ft_printf("Ready\n\n");
}

char *read_msx_line(void)
{
    return (readline(MSX_PROMPT));
}

char *read_msx_continuation(void)
{
    return (readline(MSX_CONT_PROMPT));
}

void    handle_msx_exit(void)
{
    if (isatty(STDOUT_FILENO) && isatty(STDIN_FILENO))
        write(1, "exit\n", 5);
}