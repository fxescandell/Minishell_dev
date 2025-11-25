/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:10:59 by fescande          #+#    #+#             */
/*   Updated: 2025/11/17 19:04:14 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int							type;
	char						*target;
}								t_redir;

typedef struct s_cmd
{
	char						**argv;
	t_redir						*redirs;
	int							redir_count;
}								t_cmd;

typedef struct s_pipeline
{
	t_cmd						*commands;
	int							count;
}								t_pipeline;

typedef struct s_shell
{
	char						**envp;
	int							last_status;
	int							running;
	t_pipeline					*current_pipeline;
	char						*current_line;
	char						**current_segments;
	struct termios				term_orig;
	int							term_saved;
}								t_shell;

typedef struct s_parse_ctx
{
	t_cmd						*cmd;
	int							i;
	int							j;
	int							cap;
	int							quoted;
}								t_parse_ctx;

typedef struct s_tok_ctx
{
	const char					*line;
	int							i;
	int							n;
	int							has_space;
}								t_tok_ctx;

typedef struct s_pipe_ctx
{
	int							i;
	int							fd_in;
	int							pipefd[2];
	pid_t						last_pid;
}								t_pipe_ctx;

void							setup_interactive_signals(void);
void							restore_default_signals(void);
extern volatile sig_atomic_t	g_signal;
void							run_shell_loop(t_shell *shell);
void							cleanup_shell(t_shell *shell);
void							cleanup_child(t_shell *shell);
int								compute_shlvl(const char *value);
void							update_shell_level(char ***envp);
int								parse_sign(const char *s, int *i, int *sign);
int								parse_digits(const char *s, int *i, long *result);
int								ft_atol_strict(const char *s, long *out);
void							exit_directory_error(char *arg);
void							exit_permission_error(char *arg);
void							exit_cmd_not_found_error(char *arg);
void							exit_no_file_error(char *arg);
void							handle_path_exec_error(char *arg);

char							**tokenize_line(const char *line);
int								is_separator(char c);
int								is_end(const char *s, int i);
int								find_closing_quote(const char *s, int start,
									char quote);
char							*prefixed_sub(const char *s, int a, int b,
									char prefix);
char							*extract_operator(const char *s, int *i);
char							*extract_quoted(const char *s, int *i);
char							*extract_word(const char *s, int *i);
void							free_partial_tokens(char **tokens, int count);
int								should_merge_token(char **tokens, int n,
									int has_space);
int								add_merged_token(char **tokens, int *n,
									const char *line, int *i);
int								add_new_token(char **tokens, int *n,
									const char *line, int *i);

t_pipeline						parse_command_line(char *line, t_shell *shell);
int								validate_tokens(char **tokens);
void							free_pipeline(t_pipeline *pipeline);

int								is_pipe(const char *t);
int								is_redir(const char *t);
int								redir_type(const char *t);
int								count_commands(char **toks);
int								count_args_until_pipe(char **toks, int start);
int								needs_expand(const char *tok);
char							*strip_quote_prefix(const char *tok);
int								has_quote_marker(const char *str);
void							init_command(t_cmd *c);
char							**resize_argv(char **argv, int old_cap,
									int new_cap);
void							skip_whitespace(char *core, int *p);
void							add_word_to_argv(char *core, char ***argv,
									int *j, int *cap);
int								split_and_add_words(char *core, char ***argv,
									int *j, int *cap);
int								fill_command_redirs(t_cmd *cmd, char **toks,
									int start, t_shell *sh);
int								fill_command_argv(t_cmd *cmd, char **toks,
									int start, t_shell *sh);

char							*expand_variables(const char *input,
									t_shell *shell);

int								execute_pipeline(t_pipeline *pipeline,
									t_shell *shell);
int								is_parent_builtin(char *cmd);
int								handle_empty_command(t_cmd *cmd,
									t_shell *shell);
int								handle_assignments_only(t_cmd *cmd,
									t_shell *shell);
int								is_assignment_only_cmd(t_cmd *cmd);
int								execute_pipeline_pipes(t_pipeline *pipeline,
									t_shell *shell);
int								execute_builtin_with_redirs(t_cmd *cmd,
									t_shell *shell);
int								exec_external_parent(t_cmd *cmd,
									t_shell *shell);
int								wait_all_children(t_shell *sh, pid_t last_pid);
void							apply_dup2_close(int fd, int stdfd);
void							execute_command(t_cmd *cmd, t_shell *sh);
void							update_pipe_fds(t_pipe_ctx *ctx, int count);

int								prepare_redirections(t_cmd *cmd, int *fd_in,
									int *fd_out);
int								handle_input_redir(t_redir *r, int *fd_in);
int								handle_output_redir(t_redir *r, int *fd_out);
int								build_heredoc(const char *delimiter);
int								open_input_file(const char *file_path);
int								open_output_trunc(const char *file_path);
int								open_output_append(const char *file_path);

char							*resolve_command_path(char *cmd, char **envp);

int								is_empty_or_spaces(const char *s);

int								is_builtin(const char *cmd);
int								run_builtin(char **argv, t_shell *shell);

int								builtin_echo(char **argv);
int								builtin_pwd(char **argv, t_shell *shell);
void							update_oldpwd(t_shell *shell);
void							update_pwd(t_shell *shell);
char							*expand_tilde_path(char *path, t_shell *shell);
int								builtin_cd(char **argv, t_shell *shell);
int								builtin_env(char **argv, t_shell *shell);
//int								env_strcmp(const void *a, const void *b);    ------- ya no se utiliza esta eliminada
char							**create_sorted_copy(char **envp, int count);
void							print_one_export(char *env_line);
void							print_export_error(char *arg);
int								builtin_export(char **argv, t_shell *shell);
int								builtin_unset(char **argv, t_shell *shell);
int								builtin_exit(char **argv, t_shell *shell);
int								builtin_dot(char **argv, t_shell *shell);

char							**duplicate_env(char **envp);
int								builtin_pwd(char **argv, t_shell *shell);
char							*get_env_value(const char *key, char **envp);
int								set_env_value(const char *assign,
									char ***envp_ptr);
int								unset_env_key(const char *key,
									char ***envp_ptr);
void							free_env(char **envp);

char							**split_path_list(const char *path);

void							*safe_malloc(size_t size);
void							free_string_array(char **array);
char							*str_duplicate(const char *s);
char							*str_duplicate_sub(const char *s, int start,
									int end);

int								print_error(const char *cmd, const char *msg);
int								exit_with_error(const char *msg, int code);

# ifndef Q_SINGLE_MARK
#  define Q_SINGLE_MARK '\x01'
# endif
# ifndef Q_DOUBLE_MARK
#  define Q_DOUBLE_MARK '\x02'
# endif
# ifndef MSX_PROMPT
#  define MSX_PROMPT "MSX> "
# endif
# ifndef MSX_CONT_PROMPT
#  define MSX_CONT_PROMPT "> "
# endif

#endif