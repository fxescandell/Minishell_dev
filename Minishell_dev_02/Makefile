NAME		:= minishell
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
INCLUDES	:= -Iincludes

SRC_DIR		:= src
OBJ_DIR		:= obj

# --- colores ---
GREEN		:= \033[0;92m
CYAN		:= \033[0;96m
DEF_COLOR	:= \033[0;39m

# --- deteccion readline Macos / Linux ---
UNAME_S		:= $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	READLINE_LIB := -lreadline
else
	READLINE_INC := -I$(shell brew --prefix readline)/include
	READLINE_LIB := -L$(shell brew --prefix readline)/lib -lreadline
endif

# --- Libft ---
LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a
LIBFT_INC	:= -I$(LIBFT_DIR)/include

# --- Archivos fuente ---
SRC	:=	$(SRC_DIR)/main.c \
        $(SRC_DIR)/msx_ui.c \
        $(SRC_DIR)/clean_shell.c \
        $(SRC_DIR)/utils/memory_utils.c \
        $(SRC_DIR)/utils/error_utils.c \
		$(SRC_DIR)/loop_io.c \
		$(SRC_DIR)/loop_io_split.c \
		$(SRC_DIR)/loop_io_utils.c \
		$(SRC_DIR)/loop_tty.c \
		$(SRC_DIR)/loop.c \
		$(SRC_DIR)/loop_io_getline.c

# --- Transformacion de rutas de .c -> .o ---
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# --- Reglas ---
all: $(NAME)

# --- Crear el ejecutable ---
$(NAME): $(LIBFT) $(OBJ)
	@printf "\n"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(READLINE_LIB) -o $(NAME)
	@echo "$(GREEN)Minishell compiled successfully!$(DEF_COLOR)"

# --- Compilar la libreria LIBFT ---
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(dir $@)
	@printf "$(CYAN)Compiling: $<$(DEF_COLOR)\r"
	@$(CC) $(CFLAGS) $(INCLUDES) $(READLINE_INC) $(LIBFT_INC) -c $< -o $@

# --- Limpieza ---
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Minishell build directory removed"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re