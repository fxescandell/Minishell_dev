#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include <limits.h>

/* readline */
# include <readline/history.h>
# include <readline/readline.h>

/* libft */
# include <libft.h>

typedef struct s_redir
{
    int        type;
    char       *target;
}   t_redir;

typedef struct s_cmd
{
    char        **argv;
    t_redir     *redirs;
    int         redir_count;    
}   t_cmd;

typedef struct s_pipeline
{
    t_cmd   *command;
    int     count;
}   t_pipeline;

typedef struct s_shell
{
    char            **envp;
    int             last_status;
    int             running;
    t_pipeline      *current_pipeline;
    char            *current_line;
    char            **current_segments;
    struct termios  term_orig;
    int             term_saved;
}   t_shell;

/* contextos auxiliares utilizados mas adelante */
typedef struct s_parse_ctx
{
    t_cmd   *cmd;
    int     i;
    int     j;
    int     cap;
    int     quoted;
}   t_parse_ctx;

typedef struct s_tok_ctx
{
    const char      *line;
    int             i;
    int             n;
    int             has_space;
}   t_tok_ctx;

typedef struct s_pipe_ctx
{
    int     i;
    int     fd_in;
    int     pipefd[2];
    pid_t   last_pid;
}   t_pipe_ctx;

/* loop.c */
void    run_shell_loop(t_shell *shell);

/* clean_shell.c */
void    clean_shell(t_shell *shell);
void    clean_child(t_shell *shell);

/* error_utils.c */
int exit_whit_error(const char *msg, int code);
int print_error(const char *cmd, const char *msg);

/* memory_utils.c */
void  *safe_malloc(size_t size);
void  free_string_array(char **array);

/* msx_ui.c*/
void    handle_msx_exit(void);
char *read_msx_continuation(void);
char *read_msx_line(void);
void    show_msx_intro(void);


#ifndef MSX_PROMPT
# define MSX_PROMPT "MSX> "
#endif
#ifndef MSX_CONT_PROMPT
# define MSX_CONT_PROMPT "> "
#endif


#endif