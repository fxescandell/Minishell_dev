#include "minishell.h"

int print_error(const char *cmd; const char *msg)
{
    if (cmd && msg)
    {
        ft_putstr_fd("MSX: ", STDERR_FILENO);
        ft_putstr_fd(cmd, STDERR_FILENO);
        ft_putstr_fd(": ", STDERR_FILENO);
        ft_putstr_fd(msg, STDERR_FILENO);
        ft_putstr_fd("\n", STDERR_FILENO);
    }
    else if (cmd)
    {
        ft_putstr_fd("MSX: ", STDERR_FILENO);
        ft_putstr_fd(cmd, STDERR_FILENO);
        ft_putstr_fd("\n", STDERR_FILENO);
    }
    else if (msg)
    {
        ft_putstr_fd("MSX: ", STDERR_FILENO);
        ft_putstr_fd(cmd, STDERR_FILENO);
        ft_putstr_fd("\n", STDERR_FILENO);
    }
    else
        ft_putstr_fd("MSX: error\n", STDERR_FILENO);
    return (1);
}

int exit_whit_error(const char *msg, it code)
{
    if(msg)
    {
        ft_putstr_fd("MSX: ", STDERR_FILENO);
        ft_putstr_fd(msg, STDERR_FILENO);
        ft_putstr_fd("\n", STDERR_FILENO);
    }
    exit(code);
}
