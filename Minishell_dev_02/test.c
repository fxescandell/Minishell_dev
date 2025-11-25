// ...existing code...
static void init_terminal(t_shell *shell)
{
    struct termios  term;

    shell->term_saved = 0;
-    if (isatty(STDIN_FILENO))
-        return ;
+    if (!isatty(STDIN_FILENO))
+        return ;
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
    shell->running = 1;
    shell->current_pipeline = NULL;
    shell->current_line = NULL;
    shell->current_segments = NULL;
    init_terminal(shell);

+    /* Evitar que readline instale sus manejadores si quieres manejar señales */
+    /* añadir: #include <readline/readline.h> ya está en el proyecto */
+    rl_catch_signals = 0;
}
